//
// Created by Jamie Briggs on 04/12/2024.
//

#include "Day04.h"

#include "WordSearchGrid.h"
std::string solutions::Day04::solvePartOne(const helper::SolutionInput *input) {

  int totalXmas = 0;
  auto* grid = new WordSearchGrid(input->getTestInput());

  totalXmas += grid->findTotalHorizontalInstances("XMAS");
  totalXmas += grid->findTotalVerticalInstances("XMAS");
  totalXmas += grid->findTotalDiagonalInstances("XMAS");

  return std::to_string(totalXmas);
}
std::string solutions::Day04::solvePartTwo(const helper::SolutionInput *input) {
  return "Haven't solved yet!";
}