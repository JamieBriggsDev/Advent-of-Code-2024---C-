//
// Created by perso on 16/12/2024.
//

#ifndef MAZETILE_H
#define MAZETILE_H
#include "../algorithms/pathfinding/Node.h"

namespace solutions {

class MazeTile : public core::Node {
  public:
    // Weight is 1 as every node has equal distance to each other in a Maze!
    MazeTile(int x, int y) : Node(1, x, y) {}
  };

} // solutions

#endif //MAZETILE_H
