#ifndef MOB_H
#define MOB_H

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>

class Mob {
  // sf::Vector2f pos_; ?
  std::unique_ptr<Stats> stats_; // TO DO : modifiers ?
  std::vector<Weapon> weapons_; // only one?

  mutable std::shared_ptr<sf::Sprite> visual_;

  std::shared_ptr<Move_strategy> mv_strat_;

  // Returns percentage of movement used to get in range of attack
  float do_move() const;
  float do_attack(float percent);

public:
  Mob(); // TO DO
  float turn();
  void draw(sf::RenderWindow&) const;
};

#endif
