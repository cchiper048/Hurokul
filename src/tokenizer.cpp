#include "./tokenizer.h"

Tokenizer::Tokenizer(std::string &input, size_t line):  t_input(input), line(line) {}

std::optional<Token> Tokenizer::next() {
    auto view = std::string_view(t_input);
    Token token;
    token.line = line;

    while(t_index < t_input.size()) {
        char c = t_input[t_index];

        switch(c) {
            case ' ':
            case '\t':
            case '\n':
                break;

            case '=':
                if(t_input[t_index + 1] != '=') token.type = TOKEN_ASSIGN;
                else { // ==
                    token.type = TOKEN_EQUALS;
                    ++ t_index;
                }
                ++ t_index;
                return token;
            case '+':
                token.type = TOKEN_ADD;
                ++ t_index;
                return token;
            case '-':
                token.type = TOKEN_SUBTRACT;
                ++ t_index;
                return token;
            case '*':
                token.type = TOKEN_MULTIPLY;
                ++ t_index;
                return token;
            case '%':
                token.type = TOKEN_MOD;
                ++ t_index;
                return token;
            case '>':
                token.type = TOKEN_GREATER_THAN;
                ++ t_index;
                return token;
            case '<':
                token.type = TOKEN_LESS_THAN;
                ++ t_index;
                return token;
            case '(':
                token.type = TOKEN_PARENTHESS_OPEN;
                ++ t_index;
                return token;
            case ')':
                token.type = TOKEN_PARENTHESS_CLOSE;
                ++ t_index;
                return token;
            case '{':
                token.type = TOKEN_CURLY_OPEN;
                ++ t_index;
                return token;
            case '}':
                token.type = TOKEN_CURLY_CLOSE;
                ++ t_index;
                return token;
            case '[':
                token.type = TOKEN_SQUARE_OPEN;
                ++ t_index;
                return token;
            case ']':
                token.type = TOKEN_SQUARE_CLOSE;
                ++ t_index;
                return token;
            case ';':
                token.type = TOKEN_SEMICOLON;
                ++ t_index;
                return token;
            case ':':
                token.type = TOKEN_COLON;
                ++ t_index;
                return token;
            case '&':
                if(t_input[t_index + 1] != '&') token.type = TOKEN_OPERATOR_AND;
                else { // &&
                    token.type = TOKEN_AND;
                    ++ t_index;
                } 
                ++ t_index;
                return token;
            case '|':
                if(t_input[t_index + 1] != '|') token.type = TOKEN_OPERATOR_OR;
                else { // ||
                    token.type = TOKEN_OR;
                    ++ t_index;
                } 
                ++ t_index;
                return token;
            case '!':
                if(t_input[t_index + 1] != '=') token.type = TOKEN_OPERATOR_NOT;
                else { // !=
                    token.type = TOKEN_NOT_EQUALS;
                    ++ t_index;
                } 
                ++ t_index;
                return token;
            case '$':
                token.type = TOKEN_DOLAR;
                ++ t_index;
                return token;
            case '"': {
                ++ t_index;
                size_t start = t_index;
                while(t_index < t_input.size()) {
                    c = t_input[t_index];
                    if(c == '"') break;
                    ++ t_index;
                }
                std::string_view parsedToken = view.substr(start, t_index-start);
                token.type = TOKEN_VALUE;
                token.value = parsedToken;
                ++ t_index;
                return token;
            }
            case '\'': {
                ++ t_index;
                size_t start = t_index;
                while(t_index < t_input.size()) {
                    c = t_input[t_index];
                    if(c == '\'') break;
                    ++ t_index;
                }
                std::string_view parsedToken = view.substr(start, t_index-start);
                token.type = TOKEN_VALUE;
                token.value = parsedToken;
                ++ t_index;
                return token;
            }
            default: {
                size_t start = t_index;
                bool done = false;
                while(!done && t_index < t_input.size()) {
                    c = t_input[t_index];

                    switch(c) {
                        case ' ' :
                        case '\t':
                        case '\n':
                        case '=' :
                        case '+' :
                        case '-' :
                        case '*' :
                        case '/' :
                        case '%' :
                        case '>' :
                        case '<' :
                        case '(' :
                        case ')' :
                        case '{' :
                        case '}' :
                        case '[' :
                        case ']' :
                        case ';' :
                        case ':' :
                        case '&' :
                        case '|' :
                        case '!' :
                        case '$' :
                        case '\'':
                        // case '"' :
                            done = true;
                            break;
                        default:
                            ++ t_index;
                    }
                }
                std::string_view parsedToken = view.substr(start, t_index-start);
                token.type = TOKEN_NAME;
                token.value = parsedToken;
                return token;
            }
        }
        ++ t_index;
    }

    return {};
}

