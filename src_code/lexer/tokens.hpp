//file for the data type of token
#include <string>
#include <iostream>
// enumerator for the types of token we gonna have
enum class Token_type{
    EOF_TOK,
    
    // datas and names of fncns/ vars
    NUMBER,
    STRING,
    IDENTIFIIERS,

    // barckets
    OPEN_ROUND,
    CLOSE_ROUND,
    OPEN_CURLY,
    CLOSE_CURLY,
    OPEN_SQUARE,
    CLOSE_SQUARE,
    // everything related to COMPARISON

    ASSIGNMENT,
    EQUALS,
    NOT_EQUALS,
    LESS,
    LESS_EQUAL,
    GREATER,
    GREATER_EQUAL,

    // LOGICAL OPERATORS
    AND,
    OR,
    NOT,

    //SYMBOLS
    COLON,
    DOUBLE_COLON,
    SEMI_COLON,
    QUESTION_MARK,
    AMPERSAND,
    COMMA,
    DOT,

    //OPERATORS
    PLUS,
    MINUS,
    STAR,
    SLASH,
    PLUS_PLUS,
    MINUS_MINUS,
    PLUS_EQUALS,
    MINUS_EQUALS,
    STAR_EQUALS,
    SLASH_EQUALS,
    PERCENT,

    //KEYWORDS
    LET,
    CONST,
    NULL_TOK,
    IF,
    ELSE,
    ELIF,
    FOR,
    WHILE,
    ARRAY,
    FN, // to declare functions
    TRUE,
    FALSE,
    RETURN,
    IMPORT,
};

// the token structure
struct Tokens{
    Token_type type;
    std::string data;

    template <typename... Args>
    bool token_is_one_of(Args... args){
        return ((this-> type == args) || ...);
    }
    void token_test();
};

inline std::string Token_to_string(Token_type type){
    switch(type){
        case Token_type::EOF_TOK:
            return "eof";
            break;

        // datas and names of fncns/ vars
        case Token_type::NUMBER:
            return "number";
            break;
        case Token_type::STRING:
            return "string";
            break;
        case Token_type::IDENTIFIIERS:
            return "identifier";
            break;

        // brackets
        case Token_type::OPEN_ROUND:
            return "(";
            break;
        case Token_type::CLOSE_ROUND:
            return ")";
            break;
        case Token_type::OPEN_CURLY:
            return "{";
            break;
        case Token_type::CLOSE_CURLY:
            return "}";
            break;
        case Token_type::OPEN_SQUARE:
            return "[";
            break;
        case Token_type::CLOSE_SQUARE:
            return "]";
            break;

        // comparison
        case Token_type::ASSIGNMENT:
            return "=";
            break;
        case Token_type::EQUALS:
            return "==";
            break;
        case Token_type::NOT_EQUALS:
            return "!=";
            break;
        case Token_type::LESS:
            return "<";
            break;
        case Token_type::LESS_EQUAL:
            return "<=";
            break;
        case Token_type::GREATER:
            return ">";
            break;
        case Token_type::GREATER_EQUAL:
            return ">=";
            break;

        // logical operators
        case Token_type::AND:
            return "and";
            break;
        case Token_type::OR:
            return "or";
            break;
        case Token_type::NOT:
            return "not";
            break;

        // symbols
        case Token_type::COLON:
            return ":";
            break;
        case Token_type::DOUBLE_COLON:
            return "::";
            break;
        case Token_type::SEMI_COLON:
            return ";";
            break;
        case Token_type::QUESTION_MARK:
            return "?";
            break;
        case Token_type::AMPERSAND:
            return "&";
            break;
        case Token_type::COMMA:
            return ",";
            break;
        case Token_type::DOT:
            return ".";
            break;

        // operators
        case Token_type::PLUS:
            return "+";
            break;
        case Token_type::MINUS:
            return "-";
            break;
        case Token_type::STAR:
            return "*";
            break;
        case Token_type::SLASH:
            return "/";
            break;
        case Token_type::PLUS_PLUS:
            return "++";
            break;
        case Token_type::MINUS_MINUS:
            return "--";
            break;
        case Token_type::PLUS_EQUALS:
            return "+=";
            break;
        case Token_type::MINUS_EQUALS:
            return "-=";
            break;
        case Token_type::STAR_EQUALS:
            return "*=";
            break;
        case Token_type::SLASH_EQUALS:
            return "/=";
            break;
        case Token_type::PERCENT:
            return "%";
            break;

        // keywords
        case Token_type::LET:
            return "let";
            break;
        case Token_type::CONST:
            return "const";
            break;
        case Token_type::NULL_TOK:
            return "null";
            break;
        case Token_type::IF:
            return "if";
            break;
        case Token_type::ELSE:
            return "else";
            break;
        case Token_type::ELIF:
            return "elif";
            break;
        case Token_type::FOR:
            return "for";
            break;
        case Token_type::WHILE:
            return "while";
            break;
        case Token_type::ARRAY:
            return "array";
            break;
        case Token_type::FN:
            return "fn";
            break;
        case Token_type::TRUE:
            return "true";
            break;
        case Token_type::FALSE:
            return "false";
            break;
        case Token_type::RETURN:
            return "return";
            break;
        case Token_type::IMPORT:
            return "import";
            break;

        default:
            return "unknown";
            break;
    }
}

inline void Tokens::token_test(){
    if(this->token_is_one_of(Token_type::NUMBER, Token_type::IDENTIFIIERS, Token_type::STRING)){
        std::cout << Token_to_string(this->type) << " ("<<this->data << ")\n"; 
    }
    else{
        std::cout << Token_to_string(this->type) <<"()\n";
    }
}
