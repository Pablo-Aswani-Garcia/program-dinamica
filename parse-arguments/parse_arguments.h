#ifndef PARSE_ARGUMENTS_H
#define PARSE_ARGUMENTS_H

#include <string>

class ParseArguments {
public:
    static std::string parse(int argc, char* argv[]);
};

#endif