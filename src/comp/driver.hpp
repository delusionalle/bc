#pragma once
#include <base.hpp>
#include <utility>

namespace bc {
    // simple bools that add `arg` to the call line if `enabled` is true
    struct Flag {
        std::string arg;
        bool enabled;

        explicit Flag(std::string _arg) :
            arg(std::move(_arg)), enabled(false) {}
    };

    enum CompilerSelection {
        DEFAULT,
        CLANG,
        GCC,
    };

    // passes compiler opts to driver, wrapping the cmdline
    struct Opts {
        CompilerSelection compiler;

        // bool flags
        Flag is_release{"-O2"};

        // pass options not managed by bc to compiler
        std::string custom_cl_args;

        std::filesystem::path output_path = "build/";
        std::filesystem::path temp_path = "build/temp/";
    };

    // handles calling compilers
    // there is no persistence after fail so we just make a new driver every time
    // this isnt an actual driver its just a cmdline builder and clang++ wrapper lol
    class Driver {
        std::string m_line;

    public:
        explicit Driver(Opts opts):
            call_opts(std::move(opts)) {}

        // if it fails it fails idc
        void build_line();
        void call();

        Opts call_opts;

    private:
        [[nodiscard]] std::string compilerSelectionToString() const;
    };
}
