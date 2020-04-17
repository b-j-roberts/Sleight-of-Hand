#ifndef TILE_H
#define TILE_H

#include <memory>

class Tile {
  std::unique_ptr<Mob> mob_;
  std::unique_ptr<Wall> wall_;
  std::unique_ptr<Trap> trap_;
public:
  void update();
  void draw(sf::RenderWindow&) const;
};

#endif
