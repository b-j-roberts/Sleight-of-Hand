#include "board.h"

Board::Board() {
  tile_t_.loadFromFile("rsc/tiles/Tile.png");
  tile_ = sf::Sprite(tile_t_);
}

void Board::draw(sf::RenderWindow& window) const {
  const float tilesize = 100; // TO DO
  // TO DO
  const auto window_size = window.getSize();
  sf::Vector2f offset((window_size.x - 10 * tilesize) / 2, (window_size.y - 10 * tilesize) / 2);
  for(float i = 0; i < 10; ++i) {
    for(float j = 0; j < 10; ++j) {
      tile_.setPosition(j * tilesize + offset.x, i * tilesize + offset.y);
      window.draw(tile_);
    }
  }
}
