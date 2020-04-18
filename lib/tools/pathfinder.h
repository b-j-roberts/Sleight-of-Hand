#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <vector>
#include <memory>

#include "../map/board.h"

struct Map_Node {
  bool is_wall;
  const size_t id;

  int f_cost;
  std::map<Direction, std::shared_ptr<Map_Node>> neighbors;
  std::shared_ptr<Map_Node> parent;
};

struct Map_Node_Cmp {
  bool operator()(std::shared_ptr<Map_Node> lhs, std::shared_ptr<Map_Node> rhs) const { 
    return lhs->id < rhs->id;
  }
}

class Path {

  // The path

public:

  Path(); // TO DO
  void find(const std::vector<std::vector<Tile>>& /* , TO DO : player pos */ );
  // Update : update pos of creature based on path
};

#endif
