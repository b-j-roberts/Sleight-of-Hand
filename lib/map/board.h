#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "../mobs/mob.h"

#include <SFML/Graphics.hpp>
#include <vector>

class Board {

  sf::Texture tile_t_;
  mutable sf::Sprite tile_;

  std::vector<std::vector<Mob>> mob_map_;
  std::vector<std::vector<Tile>> tile_map_;

public:

  Board();

  void draw(sf::RenderWindow&) const;
};

#endif
