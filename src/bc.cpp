#include "base.hpp"
#include "rw/file.hpp"

constexpr const char* BC_HELP_MSG =
R"(    bc - simple c/c++ build system
    |- <no args>        -> run build.toml config in debug mode
    |- -[d|r]           -> run build.toml in selected mode

    -   build.toml description
    |- [sources.src] - project code files to be included in
    |- [] -
)";

int main(int argc, char** argv) {
    if (argc > 1 && strcmp(argv[1], "help") == 0) {
        std::cout << BC_HELP_MSG << '\n';
        return 0;
    }

    auto opts = bc::read_buildfile("build.toml");
    std::cout << "main bc::read_buildfile output_dir = " << opts.output_path << '\n';
}
