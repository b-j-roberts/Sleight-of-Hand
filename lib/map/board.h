#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utility>

#include "tile.h"
#include "../tools/pathfinder.h"
#include "../mob/mob.h"

struct Map_Node; // Forward Declaration

class Board {
  std::vector<std::vector<Tile>> tiles_;
public:
  Board();
  std::pair<std::shared_ptr<Map_Node>, std::shared_ptr<Map_Node>> 
      create_node_map(std::vector<std::vector<std::shared_ptr<Map_Node>>>&, const Mob&); 
  void update();
  void draw(sf::RenderWindow&) const;
};

#endif
