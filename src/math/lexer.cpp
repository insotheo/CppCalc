#include "lexer.hpp"

namespace mathParser {

    mathParser::Token Lexer::nextToken() {
        while (pos < text.size()) {
            char currentChar = text[pos];

            // Skip whitespace
            if (std::isspace(currentChar)) {
                pos++;
                continue;
            }

            // Handle numbers and unary plus/minus
            if (std::isdigit(currentChar) || currentChar == '.' || 
                (currentChar == '-' && (pos == 0 || text[pos - 1] == '(' || text[pos - 1] == '+' || text[pos - 1] == '-')) ||
                (currentChar == '+' && (pos == 0 || text[pos - 1] == '('))){
                
                std::string number;
                bool hasDecimal = false;

                if (currentChar == '-' || currentChar == '+') {
                    number += currentChar;
                    pos++;
                    currentChar = text[pos];
                }

                while (pos < text.size() && (std::isdigit(text[pos]) || currentChar == '.')) {
                    if (text[pos] == '.') {
                        if (hasDecimal) {
                            throw std::runtime_error("Invalid number format!");
                        }
                        hasDecimal = true;
                    }
                    number += currentChar;
                    pos++;
                    if (pos < text.size()) {
                        currentChar = text[pos];
                    }
                }
                return {TokenType::Number, number};
            }

            // Handle functions or constants
            if (std::isalpha(currentChar)) {
                std::string func;
                while (pos < text.size() && std::isalpha(text[pos])) {
                    func += text[pos++];
                }

                // Functions
                if (func == "sqrt" 
                || func == "sin" 
                || func == "cos" 
                || func == "tg"
                || func == "tan" 
                || func == "ctg"
                || func == "ctan" 
                || func == "arcsin" 
                || func == "arccos" 
                || func == "arctg"
                || func == "arcctg" 
                || func == "exp" 
                || func == "arctan" 
                || func == "arcctan"
                || func == "abs"
                || func == "floor"
                || func == "ceil") {
                    return {TokenType::Function, func};
                }

                // Constants
                if (func == "pi") {
                    return {TokenType::PI, "pi"};
                }
                if (func == "e") {
                    return {TokenType::E, "e"};
                }

                return {TokenType::Invalid, func};
            }

            // Handle operators
            switch (currentChar) {
                case '+': pos++; return {TokenType::Plus, "+"};
                case '-': pos++; return {TokenType::Minus, "-"};
                case '*': pos++; return {TokenType::Multiply, "*"};
                case '/': pos++; return {TokenType::Divide, "/"};
                case '^': pos++; return {TokenType::Power, "^"};
                case '(': pos++; return {TokenType::LeftParen, "("};
                case ')': pos++; return {TokenType::RightParen, ")"};

            }
            return {TokenType::Invalid, ""};
        }

        return {TokenType::End, ""};
    }
}
