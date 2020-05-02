#include "mob.h"

#include <iostream>

Mob::Mob():
  pos_(0, 0),
  base_stats_{10, 2.f, 3.f},
  curr_modifiers_{0, 1.f, 1.f} { }

void Mob::turn(const Board& board) {
  return do_attack(do_move(movement_astar(board, this*)));
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

float Mob::do_move(std::vector<Direction> path) {
  // TO DO : Stop if enemy within distance of attack
  float movement = stats_->speed_; // TO DO
  while(movement > 0.f) {
    float dist = movement > 1.f ? 1.f : movement;
    if(!path.empty()) { // TO DO : Remove the last block?
   //if(path.length() > weapon.range()) {
      switch(path.top()) {
        case Direction::North:
          pos.y -= dist;
          break;
        case Direction::South:
          pos.y += dist;
          break;
        case Direction::East:
          pos.x += dist;
          break;
        case Direction::West:
          pos.x -= dist;
          break;
        default:
          break;
      }
      movement -= dist;
      path.pop();
    } else {
      return movement / stats_->speed_;
    }
  }
  return movement / stats_->speed_;
}

float Mob::do_attack(float percent) {
  float attack_speed = percent * weapon_->atk_speed * stats_->atk_speed;
  return weapon_->damage * attack_speed;
}
