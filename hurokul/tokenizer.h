#ifndef HUROKUL_TOKENIZER_H
#define HUROKUL_TOKENIZER_H

#include "./includes.h"

typedef enum TokenType {
    TOKEN_NAME = 0,         //
    TOKEN_VALUE,            //
    TOKEN_ASSIGN,           // =
    TOKEN_ADD,              // +
    TOKEN_SUBTRACT,         // -
    TOKEN_MULTIPLY,         // *
    TOKEN_DIV,              // /
    TOKEN_MOD,              // %
    TOKEN_GREATER_THAN,     // >
    TOKEN_LESS_THAN,        // <
    TOKEN_PARENTHESS_OPEN,  // (
    TOKEN_PARENTHESS_CLOSE, // )
    TOKEN_CURLY_OPEN,       // {
    TOKEN_CURLY_CLOSE,      // }
    TOKEN_SQUARE_OPEN,      // [
    TOKEN_SQUARE_CLOSE,     // ]
    TOKEN_SEMICOLON,        // ;
    TOKEN_COLON,            // :
    TOKEN_OPERATOR_AND,     // &
    TOKEN_AND,              // &&
    TOKEN_OPERATOR_OR,      // |
    TOKEN_OR,               // ||
    TOKEN_OPERATOR_NOT,     // !
    TOKEN_EQUALS,           // ==
    TOKEN_NOT_EQUALS,       // !=
    TOKEN_DOLAR,            // $
} TokenType;

typedef struct Token {
    TokenType type;
    std::string_view value;

    size_t line;
} Token;

static inline const char *getTokenTypeName(TokenType type) {
    switch ( type ) {
        case TOKEN_NAME: return "TOKEN_NAME";
        case TOKEN_VALUE: return "TOKEN_VALUE";
        case TOKEN_ASSIGN: return "TOKEN_ASSIGN";
        case TOKEN_ADD: return "TOKEN_ADD";
        case TOKEN_SUBTRACT: return "TOKEN_SUBSTRACT";
        case TOKEN_MULTIPLY: return "TOKEN_MULTIPLY";
        case TOKEN_DIV: return "TOKEN_DIV";
        case TOKEN_MOD: return "TOKEN_MOD";
        case TOKEN_GREATER_THAN: return "TOKEN_GREATER_THAN";
        case TOKEN_LESS_THAN: return "TOKEN_LESS_THAN";
        case TOKEN_PARENTHESS_OPEN: return "TOKEN_PARENTHESS_OPEN";
        case TOKEN_PARENTHESS_CLOSE: return "TOKEN_PARENTHESS_CLOSE";
        case TOKEN_CURLY_OPEN: return "TOKEN_CURLY_OPEN";
        case TOKEN_CURLY_CLOSE: return "TOKEN_CURLY_CLOSE";
        case TOKEN_SQUARE_OPEN: return "TOKEN_SQUARE_OPEN";
        case TOKEN_SQUARE_CLOSE: return "TOKEN_SQUARE_CLOSE";
        case TOKEN_SEMICOLON: return "TOKEN_SEMICOLON";
        case TOKEN_COLON: return "TOKEN_COLON";
        case TOKEN_OPERATOR_AND: return "TOKEN_OPERATOR_AND";
        case TOKEN_AND: return "TOKEN_AND";
        case TOKEN_OPERATOR_OR: return "TOKEN_OPERATOR_OR";
        case TOKEN_OR: return "TOKEN_OR";
        case TOKEN_OPERATOR_NOT: return "TOKEN_OPERATOR_NOT";
        case TOKEN_EQUALS: return "TOKEN_EQUALS";
        case TOKEN_NOT_EQUALS: return "TOKEN_NOT_EQUALS";
        case TOKEN_DOLAR: return "TOKEN_DOLAR";
        default: return "Unknown Token!";
    }
}


class Tokenizer {
public:
    Tokenizer(std::string &input, size_t line);
    std::optional<Token> next();

private:
    std::string &t_input;
    size_t line {0};
    size_t t_index {0};
};


#endif
