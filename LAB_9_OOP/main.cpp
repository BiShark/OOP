#include <string>
#include <iostream>

#include "Rhomb.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "TBinaryTree.h"
#include <memory>
#include <algorithm>

#include <future>
#include <functional>
#include <random>
#include <thread>
#include <ctime>


int main(int argc, char** argv)
{   
    typedef std::function<void (void) > command;

    std::shared_ptr<TBinaryTree<Figure> > tree = std::shared_ptr<TBinaryTree<Figure> >(new TBinaryTree<Figure>());
    std::string action;

    TStack<std::shared_ptr<command> > stack_cmd;
    TStack<size_t> stack_remove;
    std::default_random_engine generator(time(0));

    command cmd_insert = [&]() {
        std::cout << "Command: Insert figure" << std::endl;
        std::uniform_int_distribution<size_t> distribution(1, 1000);

        for (int i = 0; i < 10; i++) {
            int figure_num = distribution(generator);
            if (figure_num <= 333) {
                size_t side_a = distribution(generator);
                size_t angle = distribution(generator);
                tree->insert(std::shared_ptr<Figure>(new Rhomb(side_a, angle)));
            } else if (figure_num <= 666) {
                size_t side_a = distribution(generator);
                tree->insert(std::shared_ptr<Figure>(new Hexagon(side_a)));
            } else if (figure_num <= 999) {
                size_t side_a = distribution(generator);
                tree->insert(std::shared_ptr<Figure>(new Pentagon(side_a)));
            } else {
                i--;
                continue;
            }
        }
    };
    
    command cmd_print = [&]() {
        std::cout << "Command: Print tree" << std::endl;
        std::cout << *tree << std::endl;
    };

    command cmd_remove = [&]() {
        if (stack_remove.Size() > 0) {
            size_t rem_square = stack_remove.Get();
            std::cout << "Command: Remove figure(S = " << rem_square << ")." << std::endl;
            bool is_remove = true;
            while (is_remove) {
                is_remove = false;
                for (auto i : *tree) {
                    size_t sq = i->GetFigure()->Square();
                    if (sq < rem_square) {
                        tree->remove(sq);
                        is_remove = true;
                        break;
                    }
                }
            }
        }
        
    };

    std::cout << "Введите 'h' или 'help' для получения справки." << std::endl;
    while (!std::cin.eof()) {
        std::cin.clear();
        std::cin.sync();
        std::cin >> action;

        if (action == "q" || action == "quit") {
            break;
        }
        else if (action == "insertR" || action == "ins_r") {
            size_t side_a, angle;
            if (!(std::cin >> side_a >> angle)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            if (side_a <= 0) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->insert(std::shared_ptr<Figure>(new Rhomb(side_a, angle)));
        }
        else if (action == "insertP" || action == "ins_p") {
            size_t side_a;
            if (!(std::cin >> side_a)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            if (side_a <= 0) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->insert(std::shared_ptr<Figure>(new Pentagon(side_a)));
        }
        else if (action == "insertH" || action == "ins_h") {
            size_t side_b;
            if (!(std::cin >> side_b)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            if (side_b <= 0) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->insert(std::shared_ptr<Figure>(new Hexagon(side_b)));
        }
        else if (action == "remove" || action == "r") {
            size_t square;
            if (!(std::cin >> square)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->remove(square);
        }
        else if (action == "find" || action == "f") {
            if (tree->empty()) {
                std::cout << "Дерево пустое." << std::endl;
                continue;
            }
            size_t square;
            if (!(std::cin >> square)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            std::shared_ptr<TBinaryTreeItem<Figure> > rect = tree->find(square);
            if (rect != nullptr) {
                rect->GetFigure()->Print();
            } else {
                std::cout << "Фигура не найдена." << std::endl;
            }
        }
        else if (action == "destroy" || action == "d") {
            tree = std::shared_ptr<TBinaryTree<Figure> >(new TBinaryTree<Figure>());
            std::cout << "Дерево удалено." << std::endl;
        }
        else if (action == "print" || action == "p") {
            if (!tree->empty()) {
                std::cout << *tree << std::endl;
            } else {
                std::cout << "Дерево пустое." << std::endl;
            }
        }
        else if (action == "iter" || action == "it") {
            if (!tree->empty()) {
                for (auto i : *tree) {
                    i->GetFigure()->Print();
                }
            } else {
                std::cout << "Дерево пустое." << std::endl;
            }
        }
        else if (action == "sort" || action == "s") {
            if (tree->empty()) {
                std::cout << "Дерево пустое." << std::endl;
                continue;
            }
            tree->Sort();
        }
        else if (action == "sort_p" || action == "sp") {
            if (tree->empty()) {
                std::cout << "Дерево пустое." << std::endl;
                continue;
            }
            tree->SortP();
        }
        else if (action == "cmd_ins" || action == "cmd_insert") {
            stack_cmd.Set(std::shared_ptr<command> (&cmd_insert, [](command*) {}));
            std::cout << "Команда добавлена" << std::endl;
        }
        else if (action == "cmd_p" || action == "cmd_print") {
            stack_cmd.Set(std::shared_ptr<command> (&cmd_print, [](command*) {}));
            std::cout << "Команда добавлена" << std::endl;
        }
        else if (action == "cmd_r" || action == "cmd_remove") {
            size_t rem_sq;
            if (std::cin >> rem_sq) {
                stack_remove.Set(rem_sq);
                stack_cmd.Set(std::shared_ptr<command> (&cmd_remove, [](command*) {}));
                std::cout << "Команда добавлена" << std::endl;
            }
        }
        else if (action == "get" || action == "get_command") {
            if (!stack_cmd.Empty()) {
                std::shared_ptr<command> cmd = stack_cmd.Get();
                std::future<void> ft = std::async(*cmd);
                ft.get();
            } else {
                std::cout << "Стек команд пуст." << std::endl;
            }
            //std::thread(*cmd).detach();
        }
        else if (action == "help" || action == "h") {
            std::cout << "'q'        или 'quit'           - выйти из программы."                 << std::endl;
            std::cout << "'r'        или 'remove'         - удалить фигуру."                     << std::endl;
            std::cout << "'f'        или 'find'           - найти фигуру."                       << std::endl;
            std::cout << "'d'        или 'destroy'        - удалить дерево."                     << std::endl;
            std::cout << "'p'        или 'print'          - вывести дерево."                     << std::endl;
            std::cout << "'ins_r'    или 'insertR'        - вставить ромб в дерево."             << std::endl;
            std::cout << "'ins_q'    или 'insertQ'        - вставить пятиугольник в дерево."     << std::endl;
            std::cout << "'ins_t'    или 'insertT'        - вставить шестиугольник в дерево."    << std::endl;
            std::cout << "'iter'     или 'it'             - выполнить итерацию по дереву"        << std::endl;
            std::cout << "'sort'     или 's'              - отсортировать дерево"                << std::endl;
            std::cout << "'sort_p'   или 'sp'             - параллельно отсортировать дерево"    << std::endl;
            std::cout << "'cmd_ins'  или 'cmd_insert'     - добавить команду вставки"            << std::endl;
            std::cout << "'cmd_p'    или 'cmd_print'      - добавить команду печати"             << std::endl;
            std::cout << "'cmd_r'    или 'cmd_remove      - добавить команду удаления"           << std::endl;
            std::cout << "'get'      или 'get_command'    - извлечь команду"                     << std::endl;
            std::cout << "'h'        или 'help'           - вывести справку."                    << std::endl;
        }
        action = " ";
    }

    return 0;
}