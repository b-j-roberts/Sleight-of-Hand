#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <vector>
#include "../map/tile.h"

class Path {

  // The path

public:

  Path(); // TO DO
  void find(const std::vector<std::vector<Tile>>& /* , TO DO : player pos */ );
  // Update : update pos of creature based on path
};

#endif
