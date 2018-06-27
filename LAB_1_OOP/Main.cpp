#include <cstdlib>
#include <string>
#include "Rhomb.h" 
#include "Pentagon.h" 
#include "Hexagon.h"

void print_help() {
    std::cout << "'q'                or 'quit'  - Exit the program"  << std::endl;
    std::cout << "'create_rhomb'     or 'cr_rh' - Create rhomb"      << std::endl;
    std::cout << "'create_pentagon'  or 'cr_pt' - Create pentagon"   << std::endl;
    std::cout << "'create_hexagon'   or 'cr_hx' - Create hexagon"    << std::endl;
    std::cout << "'print'            or 'pr'    - Output parameters" << std::endl;
    std::cout << "'square'           or 'sq'    - Output square"     << std::endl;
    std::cout << "'help'             or 'h'     - Get help"          << std::endl;
}


int main(int argc, char** argv)
{   
    print_help();

    Figure* figure = nullptr;
    std::string action_figure = "q";

    while (true) {
        if (std::cin.eof())
            break;
        std::cin.clear();
        std::cin.sync();
        std::cout << std::endl << "Select an action" << std::endl;
        std::cin >> action_figure;
        if (std::cin.eof())
            break;

        if (action_figure == "quit" || action_figure == "q") {
            break;
        }
        else if (action_figure == "create_rhomb" || action_figure == "cr_rh") {
            if (figure != nullptr)
                delete figure;
            std::cout << "Enter the side and angle of the rhomb" << std::endl;
            figure = new Rhomb(std::cin);
        }
        else if (action_figure == "create_pentagon" || action_figure == "cr_pt") {
            if (figure != nullptr)
                delete figure;
            std::cout << "Enter the side of the pentagon" << std::endl;
            figure = new Pentagon(std::cin);
        }
        else if (action_figure == "create_hexagon" || action_figure == "cr_hx") {
            if (figure != nullptr)
                delete figure;
            std::cout << "Enter the side ot the hexagon" << std::endl;
            figure = new Hexagon(std::cin);
        }
        else if (action_figure == "print" || action_figure == "pr") {
            if (figure == nullptr) {
                std::cout << "Figure not created";
            }
            else {
                figure->Print();
            }
        }
        else if (action_figure == "square" || action_figure == "sq") {
            if (figure == nullptr) {
                std::cout << "Figure not created";
            }
            else {
                std::cout << "S = " << figure->Square() << std::endl;
            }
        }
        else if (action_figure == "help" || action_figure == "h") {
            print_help();
        }
        else {
            // std::cout << "Action not found, enter 'h' for help" << std::endl;
        }
    }
    if (figure != nullptr) {
        delete figure;
    }
    return 0;
}