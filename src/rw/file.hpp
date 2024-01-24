#pragma once
#include <base.hpp>

#include "comp/driver.hpp"

namespace bc {
    Opts read_buildfile(std::string_view filename /* = "build.toml" */);
}
