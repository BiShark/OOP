#include <string>
#include <iostream>

#include "Rhomb.h"
#include "TBinaryTree.h"
#include <memory>


int main(int argc, char** argv)
{   

    std::shared_ptr<TBinaryTree> tree = std::shared_ptr<TBinaryTree>(new TBinaryTree());
    std::string action;

    std::cout << "Введите 'h' или 'help' для получения справки." << std::endl;
    while (!std::cin.eof()) {
        std::cin.clear();
        std::cin.sync();
        std::cin >> action;

        if (action == "q" or action == "quit") {
            break;
        }
        else if (action == "insertR" or action == "ins_r") {
            size_t side, angle;
            if (!(std::cin >> side >> angle)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->insert(std::shared_ptr<Figure>(new Rhomb(side, angle)));
        }
        else if (action == "remove" or action == "r") {
            size_t square;
            if (!(std::cin >> square)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->remove(square);
        }
        else if (action == "find" or action == "f") {
            if (tree->empty()) {
                std::cout << "Дерево пустое." << std::endl;
                continue;
            }
            size_t square;
            if (!(std::cin >> square)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            std::shared_ptr<TBinaryTreeItem> rect = tree->find(square);
            if (rect != nullptr) {
                rect->GetFigure()->Print();
            } else {
                std::cout << "Фигура не найдена." << std::endl;
            }
            
        }
        else if (action == "destroy" or action == "d") {
            tree = std::shared_ptr<TBinaryTree>(new TBinaryTree());
            std::cout << "Дерево удалено." << std::endl;
        }
        else if (action == "print" or action == "p") {
            if (!tree->empty()) {
                std::cout << *tree << std::endl;
            } else {
                std::cout << "Дерево пустое." << std::endl;
            }
        }
        else if (action == "help" or action == "h") {
            std::cout << "'q'     или 'quit'            - выйти из программы."                 << std::endl;
            std::cout << "'r'     или 'remove'          - удалить фигуру."                     << std::endl;
            std::cout << "'f'     или 'find'            - найти фигуру."                       << std::endl;
            std::cout << "'d'     или 'destroy'         - удалить дерево."                     << std::endl;
            std::cout << "'p'     или 'print'           - вывести дерево."                     << std::endl;
            std::cout << "'ins_r' или 'insertR a b'     - вставить ромб в дерево."             << std::endl;
            std::cout << "'h'     или 'help'            - вывести справку."                    << std::endl;
        }
        action = " ";
    }

    return 0;
}
