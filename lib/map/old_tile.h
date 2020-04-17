#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <memory>

class Tile { // TO DO : Make base class into null object ?
  mutable std::shared_ptr<sf::Sprite> visual_;

  bool is_wall_ = false;
  std::shared_ptr<Effect_Strategy> active_effect_;
  std::shared_ptr<Effect_Strategy> passive_effect_;
public:
  Tile();
  bool is_wall() const { return is_wall_; }
  void active() const; // Called when activated ( stepped on, cast, ... )
  void passive() const; // Called every turn
  void draw(sf::RenderWindow&) const; // TO DO : virtual for different animation effects?
};

#endif
