//
// Created by Jamie Briggs on 02/12/2024.
//

#ifndef DAY_02_H
#define DAY_02_H

#include <string>

#include "../Day.h"
#include "../helper/SolutionInput.h"

using namespace helper;

namespace solutions {
    class Day02 final : public Day {
    public:
        std::string solvePartOne(const helper::SolutionInput* input) override;
        std::string solvePartTwo(const helper::SolutionInput* input) override;
    };
} // solutions

#endif //DAY_02_H
