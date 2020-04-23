#ifndef TILE_H
#define TILE_H

#include <memory>

class Tile {
  std::unique_ptr<Mob> mob_;
  std::unique_ptr<Wall> wall_;
  std::unique_ptr<Trap> trap_;
public:

  bool has_mob() const { return mob_; }
  bool has_wall() const { return wall_; }
  bool has_trap() const { return trap_; }

  void update();
  void draw(sf::RenderWindow&, float, float) const;
};

#endif
