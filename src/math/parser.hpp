#ifndef MP_PARSER_HPP
#define MP_PARSER_HPP

#include "lexer.hpp"

#include <cmath>
#include <stdexcept>

namespace mathParser {

    class Parser {
    public:
        Parser(Lexer &lexer) : lexer(lexer) {
            currentToken = lexer.nextToken();
        }

        inline double parse() { return expression(); };

    private:
        Lexer& lexer;
        Token currentToken;

        void eat(TokenType type);

        double expression();
        double term();
        double factor();
        double power();
    };

}

#endif