//
// Created by perso on 10/12/2024.
//

#ifndef PATHFINDER_H
#define PATHFINDER_H


#include <queue>
#include <stack>

#include "Node.h"


namespace core {
  struct FinalPath {
    std::stack<Node *> path;
    long cost;
    [[nodiscard]] bool pathFound() const {
      return path.size() > 1;
    }
  };
  class PathFinder {
  public:
    virtual ~PathFinder() = default;
    virtual std::vector<std::queue<Node *>> findAllPaths(Node *start) = 0;
    virtual FinalPath findPath(Node *start, Node *finish, bool rotationAddsCost = false) = 0;

  };
}

#endif //PATHFINDER_H
