#include "board.h"

Board::Board() {
  // TO DO
}

void Board::update() {
  for(auto& row : tiles_) {
    for(auto& tile : row) {
      tile.update();
    }
  }
}

void Board::draw(sf::RenderWindow& window) const {
  const float tilesize = 100; // TO DO
  const auto window_size = window.getSize();
  const sf::Vector2f offset((window_size.x - tiles_[0].size() * tilesize) / 2,
                            (window_size.y - tiles_.size() * tilesize) / 2);
  for(int posy = offset.y; const auto& row : tiles_) {
    for(int posx = offset.x; const auto& tile : row) {
      tile.draw(window, posx, posy);
      posx += tilesize;
    }
    posy += tilesize;
  }
}
