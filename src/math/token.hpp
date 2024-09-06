#ifndef MP_TOKEN_HPP
#define MP_TOKEN_HPP

#include "tokenType.hpp"
#include <string>

namespace mathParser{
    struct Token
    {
        mathParser::TokenType type;
        std::string value;
    };
    
}

#endif