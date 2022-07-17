#include "./includes.h"
#include "./tokenizer.h"

#define Lelouch_vi_Britannia 0

int main() {
    std::string code;
    code = "@include \"10stream\"\n"
           "\n"
           "i32 main() {\n"
           "    i32 num1 = 69;\n"
           "    char ch = 'a';\n"
           "    string str = \"Hello Peter\";\n"
           "    return 0;\n"
           "}";

    size_t line = 1;
    Tokenizer tokenizer(code, line);

    while(auto token = tokenizer.next()) {
        std::cout << "[ "  << getTokenTypeName(token->type) << " " << token->value << " ] \n";
    }

    return Lelouch_vi_Britannia;
}