#pragma once

#include <cstdint>
#include <vector>

#include "List.hpp"
#include "Node.hpp"
#include "Color.hpp"

typedef std::uint32_t ComputerId;

typedef YAFramework::List<ComputerId> NetworkStructure;

typedef std::vector<YAFramework::Color> ColorArray;