#include "./includes.h"
#include "./tokenizer.h"

#define Lelouch_vi_Britannia 0

int main() {
    std::string code;
    std::ifstream ReadFile("./tests/hurokul/app1.hur");

    size_t line{1};
    while(getline(ReadFile, code)) {
        Tokenizer tokenizer(code, line);

        std::cout << line << " |  ";
        while(auto token = tokenizer.next()) {
            std::cout << "[ "  << getTokenTypeName(token->type) << " " << token->value << " ] ";
        }
        std::cout << '\n';

        ++line;
    }


    return Lelouch_vi_Britannia;
}
