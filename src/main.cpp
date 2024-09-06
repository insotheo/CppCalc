#include <iostream>
#include <string>

#include "math/math-parser.hpp"

int main(){
    std::string input;
    std::cout << "Enter a mathematical expression:\n";
    std::getline(std::cin, input);
    mathParser::Lexer lexer(input);
    mathParser::Parser parser(lexer);
    for(int i = 0; i <= 15; ++i){
        std::cout << "-";
    }
    std::cout << "\n";
    try{
        double result = parser.parse();
        std::cout << "Result: " << result << "\n";
    }catch(const std::runtime_error& err){
        std::cerr << "Error: " << err.what() << "\n";
    }
    for(int i = 0; i <= 15; ++i){
        std::cout << "-";
    }
    std::cout << "\n";
    std::cout << "Press [Enter] to close the programme!\n";
    std::getchar();
    return 0;
}