#ifndef MOB_H
#define MOB_H

#include <SFML/Graphics.hpp>

#include <memory>

struct stat_block {
  int hp_;
  float speed_;
  float damage_;
};

class Mob {
  sf::Vector2f pos_;
  const stat_block base_stats_;
  stat_block curr_modifiers_;
  mutable std::shared_ptr<sf::Sprite> visual_;
public:
  Mob(); // TO DO
  void turn();
  void draw(sf::RenderWindow&) const;
};

#endif
