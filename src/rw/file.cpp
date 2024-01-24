#include "file.hpp"
#include "sup/toml.hpp"

bc::Opts bc::read_buildfile(std::string_view filename = "build.toml") {
    Opts opts{};

    try {
        toml::table config = toml::parse_file(filename);

        opts.output_path = config["src"]["output_dir"].value_or("");
    } catch (const toml::parse_error& err) {
        std::cerr << "ERR @bc::read_buildfile -> [toml::parse_error] " << err << '\n';
    }

    return opts;
}
