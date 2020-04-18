#include "tile.h"

// TO DO : Constructor, placing and moving wall, mob & traps

void Tile::update() {
  mob_->update();
  wall_->update();
  trap_->update();
}

void Tile::draw(sf::RenderWindow& window, float posx, float posy) const {
  // TO DO : Draw Tile
  trap_->draw(window, posx, posy);
  wall_->draw(window, posx, posy);
  mob_->draw(window, posx, posy);
}
