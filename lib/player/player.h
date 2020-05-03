#ifndef PLAYER_H
#define PLAYER_H

class Player {
  std::shared_ptr<Stat_Block> stats_;
  // visual
public:
  Player(); // TO DO
  void take_damage(float);
  void turn();
  void draw(sf::RenderWindow&) const;
};

#endif
