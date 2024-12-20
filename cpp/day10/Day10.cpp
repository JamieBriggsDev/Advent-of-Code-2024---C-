//
// Created by Jamie Briggs on 10/12/2024.
//

#include "Day10.h"

#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>

#include "../algorithms/pathfinding/IncrementalPathFinder.h"
#include "../algorithms/pathfinding/PathFinder.h"
#include "TopographicMap.h"

namespace solutions {
  std::string Day10::solvePartOne(const helper::SolutionInput *input) {
    core::TopographicMap map = core::TopographicMap(input->getTestInput());
    // Get all starting positions
    auto nodes = map.getStartingPositions();
    // Get all paths from positions
    vector<queue<pathfinding::Node *>> allPaths;

    pathfinding::IncrementalPathFinder pathFinder;

    std::map<pathfinding::Node *, int> trailHeadPoints;

    for (auto node: nodes) {
      // First add node to trailHeadPoints
      trailHeadPoints[node] = 0;
      // Next start map of found finishing nodes
      std::unordered_set<pathfinding::Node *> finishingNodes;
      // Next find all possible paths with starting node
      auto paths = pathFinder.findAllPaths(node);
      // Loop through each path, and find ones which end on a peak (i.e size of 10)
      for (auto path: paths) {
        if (path.size() == 10) {
          pathfinding::Node *destination = path.back();
          if (!finishingNodes.contains(destination)) {
            finishingNodes.insert(destination);
            trailHeadPoints[node]++;
          }
        }
      }
    }

    // Find sum of all values in trailHeadPoints
    int sum = 0;
    for (const auto &pair: trailHeadPoints) {
      sum += pair.second;
    }

    return std::to_string(sum);
  }
  std::string Day10::solvePartTwo(const helper::SolutionInput *input) {
    core::TopographicMap map = core::TopographicMap(input->getTestInput());
    // Get all starting positions
    auto nodes = map.getStartingPositions();
    // Get all paths from positions
    vector<queue<pathfinding::Node *>> allPaths;

    pathfinding::IncrementalPathFinder pathFinder;

    std::map<pathfinding::Node *, int> trailHeadPoints;

    for (auto node: nodes) {
      // First add node to trailHeadPoints
      trailHeadPoints[node] = 0;
      // Next find all possible paths with starting node
      auto paths = pathFinder.findAllPaths(node);
      // Loop through each path, and find ones which end on a peak (i.e size of 10)
      for (auto path: paths) {
        if (path.size() == 10) {
          trailHeadPoints[node]++;
        }
      }
    }

    // Find sum of all values in trailHeadPoints
    int sum = 0;
    for (const auto &pair: trailHeadPoints) {
      sum += pair.second;
    }

    return std::to_string(sum);
  }
} // namespace solutions
