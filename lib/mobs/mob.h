#ifndef MOB_H
#define MOB_H

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>

class Mob {
  // sf::Vector2f pos_; ?
  std::unique_ptr<Stats> stats_; // TO DO : modifiers ?
  std::vector<Weapon> weapons_; // only one?
  // turn strategy for attack and move?
  mutable std::shared_ptr<sf::Sprite> visual_;
public:
  Mob(); // TO DO
  void turn();
  void draw(sf::RenderWindow&) const;
};

#endif
