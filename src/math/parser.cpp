#include "parser.hpp"

namespace mathParser {

    void Parser::eat(TokenType type) {
        if (currentToken.type == type) {
            currentToken = lexer.nextToken();
        } else {
            throw std::runtime_error("Invalid syntax");
        }
    }

    double Parser::expression() {
        double result = term();
        while (currentToken.type == TokenType::Plus || currentToken.type == TokenType::Minus) {
            if (currentToken.type == TokenType::Plus) {
                eat(TokenType::Plus);
                result += term();
            } else {
                eat(TokenType::Minus);
                result -= term();
            }
        }
        return result;
    }

    double Parser::term() {
        double result = power();
        while (currentToken.type == TokenType::Multiply || currentToken.type == TokenType::Divide) {
            if (currentToken.type == TokenType::Multiply) {
                eat(TokenType::Multiply);
                result *= power();
            } else {
                eat(TokenType::Divide);
                result /= power();
            }
        }
        return result;
    }

    double Parser::factor() {
        if (currentToken.type == TokenType::Number) {
            double value = std::stod(currentToken.value);
            eat(TokenType::Number);
            return value;
        }

        if (currentToken.type == TokenType::Plus || currentToken.type == TokenType::Minus) {
            std::string sign = currentToken.value;
            eat(currentToken.type);
            double value = factor();
            return (sign == "-") ? -value : value;
        }

        if (currentToken.type == TokenType::PI) {
            eat(TokenType::PI);
            return 3.1415926535;
        }

        if (currentToken.type == TokenType::E) {
            eat(TokenType::E);
            return 2.718281828459045;
        }

        if (currentToken.type == TokenType::Function) {
            std::string funcName = currentToken.value;
            eat(TokenType::Function);
            eat(TokenType::LeftParen);
            double arg = expression();
            eat(TokenType::RightParen);
            // Function handling
            if (funcName == "sqrt") return std::sqrt(arg);
            if (funcName == "sin") return std::sin(arg);
            if (funcName == "cos") return std::cos(arg);
            if (funcName == "tg" || funcName == "tan") return std::tan(arg);
            if (funcName == "ctg" || funcName == "ctan") return 1 / std::tan(arg);
            if (funcName == "arcsin") return std::asin(arg);
            if (funcName == "arccos") return std::acos(arg);
            if (funcName == "arctg" || funcName == "arctan") return std::atan(arg);
            if (funcName == "arcctg" || funcName == "arcctan") return (3.1415926535 / 2) - std::atan(arg);
            if (funcName == "exp") return std::exp(arg);
            if (funcName == "abs") return std::abs(arg);
            if (funcName == "floor") return std::floor(arg);
            if (funcName == "ceil") return std::ceil(arg);

            throw std::runtime_error("Unknown function!");
        }

        if (currentToken.type == TokenType::LeftParen) {
            eat(TokenType::LeftParen);
            double result = expression();
            eat(TokenType::RightParen);
            return result;
        }

        throw std::runtime_error("Invalid syntax!");
    }

    double Parser::power() {
        double result = factor();
        while (currentToken.type == TokenType::Power) {
            eat(TokenType::Power);
            double exponent = factor();
            result = std::pow(result, exponent);
        }
        return result;
    }
}
