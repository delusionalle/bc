#include "base.hpp"

constexpr const char* BC_HELP_MSG =
 R"(    bc - simple c/c++ build system
    |- <no args>        -> run build.toml config in debug mode
    |- -[d|r]           -> run build.toml in selected mode

    -   build.toml description
    |- [sources.src] - project code files to be included in
    |- [] -
)";

int main(int argc, char** argv) {
    if (argc == 1) std::cout << BC_HELP_MSG << '\n';
}
