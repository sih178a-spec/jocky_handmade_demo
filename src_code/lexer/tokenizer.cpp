#pragma once
#include "tokens.hpp"
#include <vector>

class lexer{
    std::string source;
    int position = 0;

    public:
        std::vector<Tokens> Token;
    lexer(std::string s){
        source = s;
    }
};

std::vector<Tokens> Tokenize(std::string s){
    lexer lex(s);
    
    return lex.Token;
}

