#include "file.hpp"
#include "sup/toml.hpp"

bc::Opts bc::read_buildfile(std::string_view filename = "build.toml") {
    auto buildfile = toml::parse(filename);
    Opts opts{};

    opts.output_path = buildfile["src"]["output_dir"].value_or("");
}
