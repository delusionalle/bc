#include "driver.hpp"

void bc::Driver::build_line() {
    m_line += compilerSelectionToString();
}

void bc::Driver::call() {
    // TODO: write
    // std::system(m_line.c_str());
    std::cout << "Driver::call()" << '\n';
}

std::string bc::Driver::compilerSelectionToString() const {
    switch (call_opts.compiler) {
        case CompilerSelection::CLANG: return "clang++ ";
        case CompilerSelection::GCC: return "g++ ";
        default: return "echo hi; ";
    }
}
