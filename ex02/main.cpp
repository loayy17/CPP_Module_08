#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <list>
#include <deque>

// Helper function to print stack contents
template <typename T, typename Container>
void printStack(MutantStack<T, Container>& stack) {
    if (stack.empty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }

    std::cout << "Stack contents (bottom to top): ";
    for (typename MutantStack<T, Container>::iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
// Display available commands
void showHelp() {
    std::cout << std::endl;
    std::cout << "Available commands:" << std::endl;
    std::cout << "  push <number> - Add element to stack" << std::endl;
    std::cout << "  pop           - Remove top element" << std::endl;
    std::cout << "  top           - Show top element" << std::endl;
    std::cout << "  size          - Show stack size" << std::endl;
    std::cout << "  print         - Display all elements" << std::endl;
    std::cout << "  help          - Show this help message" << std::endl;
    std::cout << "  exit          - Quit program" << std::endl;
}

// Template function to run the program logic
template <typename Container>
void runProgram(MutantStack<int, Container>& mstack) {
    std::string command;
    int         value;

    while (true) {
        std::cout << "> ";
        if (!(std::cin >> command)) {
            // Handle Ctrl+D (EOF)
            std::cout << "\nInput stream closed (Ctrl+D detected). Exiting..." << std::endl;
            break;
        }

        if (command == "push") {
            if (std::cin >> value) {
                mstack.push(value);
                std::cout << value << " pushed onto stack." << std::endl;
            } else {
                if (std::cin.eof()) {
                    std::cout << "\nInput stream closed (Ctrl+D detected). Exiting..." << std::endl;
                    break;
                }
                std::cout << "Invalid input. Please enter a valid integer." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } else if (command == "pop") {
            if (mstack.empty()) {
                std::cout << "Stack is empty. Cannot pop." << std::endl;
            } else {
                std::cout << "Popped: " << mstack.top() << std::endl;
                mstack.pop();
            }
        } else if (command == "top") {
            if (mstack.empty()) {
                std::cout << "Stack is empty." << std::endl;
            } else {
                std::cout << "Top element: " << mstack.top() << std::endl;
            }
        } else if (command == "size") {
            std::cout << "Stack size: " << mstack.size() << std::endl;
        } else if (command == "print") {
            printStack(mstack);
        } else if (command == "help") {
            showHelp();
        } else if (command == "exit") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Unknown command. Type 'help' for available commands." << std::endl;
        }
    }
}


int main() {
    std::cout << "Welcome to MutantStack Interactive CLI!" << std::endl;
    std::cout << "Choose container type: vector, list, or deque (default: deque)" << std::endl;
    std::cout << "> ";

    std::string containerType;
    if (!(std::cin >> containerType)) {
        std::cout << "\nInput stream closed (Ctrl+D detected). Exiting..." << std::endl;
        return 0;
    }

    if (containerType == "vector") {
        MutantStack<int, std::vector<int> > mstack;
        std::cout << "Using vector-based MutantStack" << std::endl;
        showHelp();
        runProgram(mstack);
    } else if (containerType == "list") {
        MutantStack<int, std::list<int> > mstack;
        std::cout << "Using list-based MutantStack" << std::endl;
        showHelp();
        runProgram(mstack);
    } else {
        if (containerType != "deque")
            std::cout << "Unknown container type '" << containerType << "'. Using default deque container." << std::endl;
        else
            std::cout << "Using deque-based MutantStack" << std::endl;
        MutantStack<int, std::deque<int> > mstack;
        showHelp();
        runProgram(mstack);
    }

    return 0;
}