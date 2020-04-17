#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "tile.h"

class Board {
  std::vector<std::vector<Tile>> tiles_;
public:
  void update();
  void draw(sf::RenderWindow&) const;
};

#endif
