#ifndef MP_LEXER_HPP
#define MP_LEXER_HPP

#include "token.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>

namespace mathParser{
    class Lexer{
    public:
        Lexer(const std::string& expr): text(expr), pos(0){}

        mathParser::Token nextToken();

    private:
        std::string text;
        size_t pos;
    };
}

#endif