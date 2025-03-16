#ifndef PARSE_ARGUMENTS_H
#define PARSE_ARGUMENTS_H

#include <string>

/*
 * Clase que permite pasar los argumentos a un formato entendible para
 * el programa.
 */
class ParseArguments {
public:
    static std::string parse(int argc, char* argv[]);
};

#endif