#pragma once
#include "tokens.hpp"
#include <vector>
#include <cstdlib>

struct lexer{
    std::string source;
    int position = 0;
    std::vector<Tokens> Token;
    lexer(std::string s){
        source = s;
    }
};
int line_num{};
std::vector<Tokens> Tokenize(std::string s){
    lexer lex(s);
    while(lex.position < lex.source.length()){
        char c =lex.source[lex.position];
        // for strings
        if(c == '"' || c == '\''){
            char str_entering_quote = c;
            lex.position++;
            std::string otp{};
            while(lex.position < lex.source.length() && lex.source[lex.position] != str_entering_quote){
                otp += lex.source[lex.position];
                lex.position++;
            }
            if(lex.position == lex.source.length()){
                std::cerr << "Error at line " << line_num << "string not terminated, started with " << str_entering_quote << "\n";
                exit(1);
            }
            (lex.Token).push_back(Tokens{Token_type::STRING , otp});
            continue;
        }
        //for empty spaces/newlines
        if(c == '\n' || c == ' ' || c == '\t' || c == '\r'){
            if(c == '\n'){
                line_num++;
            }
            lex.position++;   
            continue;
        }
        // for single instance chars
        if(c =='[' || c == ']' || c == '{' || c == '}' || c == '(' || c == ')' || c == ',' || c == ';' || c =='?'|| c == '.' || c == '%'){
            switch(c){
                case '[':
                    lex.Token.push_back(Tokens{Token_type::OPEN_SQUARE, "["});
                    break;
                case ']':
                    lex.Token.push_back(Tokens{Token_type::CLOSE_SQUARE, "]"});
                    break;
                case '{':
                    lex.Token.push_back(Tokens{Token_type::OPEN_CURLY, "{"});
                    break;
                case '}':
                    lex.Token.push_back(Tokens{Token_type::CLOSE_CURLY, "}"});
                    break;
                case '(':
                    lex.Token.push_back(Tokens{Token_type::OPEN_ROUND, "("});
                    break;
                case ')':
                    lex.Token.push_back(Tokens{Token_type::CLOSE_ROUND, ")"});
                    break;
                case ',':
                    lex.Token.push_back(Tokens{Token_type::COMMA, ","});
                    break;
                case ';':
                    lex.Token.push_back(Tokens{Token_type::SEMI_COLON, ";"});
                    break;
                case '?':
                    lex.Token.push_back(Tokens{Token_type::QUESTION_MARK, "?"});
                    break;
                case '.':
                    lex.Token.push_back(Tokens{Token_type::DOT, "."});
                    break;
                case '%':
                    lex.Token.push_back(Tokens{Token_type::PERCENT, "%"});
                    break;
            }
            lex.position++;
        }
        //for multiple char possiblility chars
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>' || c == ':' || c == '!' || c == '|' || c == '&'){
            char next_char = lex.source[lex.position + 1];
            switch(c){
                case '+':
                    if(lex.position + 1 < lex.source.length()  && next_char == '+'){
                        lex.Token.push_back(Tokens{Token_type::PLUS_PLUS , "++"});
                        lex.position++;
                        break;
                    }
                    else if(lex.position + 1 < lex.source.length() && next_char == '='){
                        lex.Token.push_back(Tokens{Token_type::PLUS_EQUALS ,"+="});
                        lex.position++;
                        break;
                    }
                    else{
                        lex.Token.push_back(Tokens{Token_type::PLUS , "+"});
                        break;
                    }
                case '-':
                    if(lex.position + 1 < lex.source.length()  && next_char == '-'){
                        lex.Token.push_back(Tokens{Token_type::MINUS_MINUS , "--"});
                        lex.position++;
                        break;
                    }
                    else if(lex.position + 1 < lex.source.length() && next_char == '='){
                        lex.Token.push_back(Tokens{Token_type::MINUS_EQUALS ,"-="});
                        lex.position++;
                        break;
                    }
                    else{
                        lex.Token.push_back(Tokens{Token_type::MINUS , "-"});
                        break;
                    }
                case '*':
                    if(lex.position + 1 < lex.source.length() && next_char == '='){
                        lex.Token.push_back(Tokens{Token_type::STAR_EQUALS ,"*="});
                        lex.position++;
                        break;
                    }
                    else{
                        lex.Token.push_back(Tokens{Token_type::STAR , "*"});
                        break;
                    }
                case '/':
                    if(lex.position + 1 < lex.source.length() && next_char == '='){
                        lex.Token.push_back(Tokens{Token_type::SLASH_EQUALS ,"/="});
                        lex.position++;
                        break;
                    }
                    else{
                        lex.Token.push_back(Tokens{Token_type::SLASH, "/"});
                        break;
                    }
                case '=':
                    if(lex.position + 1 < lex.source.length() && next_char == '='){
                        lex.Token.push_back(Tokens{Token_type::EQUALS,"=="});
                        lex.position++;
                        break;
                    }
                    else{
                        lex.Token.push_back(Tokens{Token_type::ASSIGNMENT, "="});
                        break;
                    }
                case '<':
                    if(lex.position + 1 < lex.source.length() && next_char == '='){
                        lex.Token.push_back(Tokens{Token_type::LESS_EQUAL ,"<="});
                        lex.position++;
                        break;
                    }
                    else{
                        lex.Token.push_back(Tokens{Token_type::LESS, "<"});
                        break;
                    }
                case '>':
                    if(lex.position + 1 < lex.source.length() && next_char == '='){
                        lex.Token.push_back(Tokens{Token_type::GREATER_EQUAL ,">="});
                        lex.position++;
                        break;
                    }
                    else{
                        lex.Token.push_back(Tokens{Token_type::GREATER, ">"});
                        break;
                    }
                case '!':
                    if(lex.position + 1 < lex.source.length() && next_char == '='){
                        lex.Token.push_back(Tokens{Token_type::NOT_EQUALS ,"!="});
                        lex.position++;
                        break;
                    }
                    else{
                        lex.Token.push_back(Tokens{Token_type::NOT, "!"});
                        break;
                    }
                case ':':
                    if(lex.position + 1 < lex.source.length() && next_char == ':'){
                        lex.Token.push_back(Tokens{Token_type::DOUBLE_COLON ,"::"});
                        lex.position++;
                        break;
                    }
                    else{
                        lex.Token.push_back(Tokens{Token_type::COLON, ":"});
                        break;
                    }
                case '|':
                    if(lex.position + 1 < lex.source.length() && next_char == '|'){
                        lex.Token.push_back(Tokens{Token_type::OR ,"||"});
                        lex.position++;
                        break;
                    }
                    else{
                        std::cerr << "Expected another '|' at line number" << line_num << "\n";
                        exit(1);
                    }
                case '&':
                    if(lex.position + 1 < lex.source.length() && next_char == '&'){
                        lex.Token.push_back(Tokens{Token_type::AND ,"&&"});
                        lex.position++;
                        break;
                    }
                    else{
                        lex.Token.push_back(Tokens{Token_type::AMPERSAND, "&"});
                        break;
                    }
            }
            lex.position++;
            continue;
        }
        if(isdigit((int)c)){
            
        }
    }
    return lex.Token;
}
