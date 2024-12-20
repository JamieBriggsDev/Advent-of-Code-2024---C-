//
// Created by Jamie Briggs on 10/12/2024.
//

#ifndef PATH_H
#define PATH_H
#include "../../core/Pair.h"

#include <vector>

#include "../../core/Orientation.h"

namespace pathfinding {

class Node : public core::Pair {
  int weight;
  bool isWalkable = false;
  // Pointer to all neighbour nodes
  std::vector<Node *> neighbourNodes;
  core::Orientation orientation;
  Node* parent = nullptr;
  long g = 0L;
  double h = 0L;
public:
  virtual ~Node() = default;
  Node(int weight, int x, int y, bool isWalkable) : Pair(x, y), weight(weight), isWalkable(isWalkable) {}
  Node* copy() const {
    return new Node(*this);
  }
  int getWeight() const {
    return this->weight;
  }
  void addNeighbour(Node* neighbour) {
    if (std::find(this->neighbourNodes.begin(), this->neighbourNodes.end(), neighbour) == this->neighbourNodes.end()) {
      this->neighbourNodes.push_back(neighbour);
    }
  }
  void removeNeighbour(Node* path) {
    this->neighbourNodes.erase(std::remove(this->neighbourNodes.begin(), this->neighbourNodes.end(), path), this->neighbourNodes.end());
  }
  void setParent(Node* parent) {
    this->parent = parent;
  }
  Node* getParent() const {
    return this->parent;
  }
  void setOrientation(core::Orientation orientation) { this->orientation = orientation; }
  core::Orientation getOrientation() const {
    return this->orientation;
  }
  void setG(long g) {
    this->g = g;
  }
  [[nodiscard]] long getG() const {
    return this->g;
  }
  void setH(double h) {
    this->h = h;
  }
  [[nodiscard]] long getH() const {
    return this->h;
  }
  [[nodiscard]] double getF() const {
    return this->g + this->h;
  }
  [[nodiscard]] Pair getPosition() const {
    return static_cast<Pair>(*this);
  }
  [[nodiscard]] std::vector<Node *> getNeighbourNodes() const {
    std::vector<Node *> walkableNodes;
    for (const auto &node: this->neighbourNodes) {
      if (node->getIsWalkable()) {
        walkableNodes.push_back(node);
      }
    }
    return walkableNodes;
  }
  [[nodiscard]] std::vector<Node *> createCopiesOfNeighbours() const {
    std::vector<Node *> copy;
    for (auto &node : this->neighbourNodes) {
      copy.push_back(new Node(*node));
    }
    return copy;
  }
  [[nodiscard]] bool getIsWalkable() const { return isWalkable; }
  void setIsWalkable(bool isWalkable) { this->isWalkable = isWalkable; }

  friend bool operator==(const Node &lhs, const Node &rhs) {
    return static_cast<const Pair &>(lhs) == static_cast<const Pair &>(rhs) && lhs.weight == rhs.weight &&
           lhs.neighbourNodes == rhs.neighbourNodes;
  }
  friend bool operator!=(const Node &lhs, const Node &rhs) { return !(lhs == rhs); }
};

} // day10

#endif //PATH_H
