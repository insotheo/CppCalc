#ifndef MP_TOKEN_TYPE_HPP
#define MP_TOKEN_TYPE_HPP

namespace mathParser{
    enum class TokenType{
        Number,
        Plus,
        Minus,
        Multiply,
        Divide,
        Power,
        LeftParen,
        RightParen,
        Function,
        PI,
        E,
        End,
        Invalid
    };
}

#endif