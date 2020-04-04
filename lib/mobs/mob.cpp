#include "mob.h"

#include <iostream>

Mob::Mob():
  pos_(0, 0),
  base_stats_{10, 2.f, 3.f},
  curr_modifiers_{0, 1.f, 1.f} { }

void Mob::turn() { 
  //std::cout << "HP: " << base_stats_.hp_ << " , SPEED: " << base_stats_.speed_ << " , DMG: " << base_stats_.damage_ << '\n';
}

void Mob::draw(sf::RenderWindow& window) const {
  int size = 30;
  sf::CircleShape vis(size);
  vis.setOrigin(size, size);
  const float tilesize = 100; // TO DO
  // TO DO
  const auto window_size = window.getSize();
  sf::Vector2f offset((window_size.x - 10 * tilesize) / 2, (window_size.y - 10 * tilesize) / 2);
  vis.setFillColor(sf::Color::Red);
  vis.setPosition(offset + pos_);
  vis.move(tilesize / 2, tilesize / 2);
  window.draw(vis);
}
