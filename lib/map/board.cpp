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

std::pair<std::shared_ptr<Map_Node>, std::shared_ptr<Map_Node>>
    Board::create_node_map(std::vector<std::vector<std::shared_ptr<Map_Node>>>& node_map,
                           const Mob& mob) {
  node_map = std::vector<std::vector<std::shared_ptr<Map_Node>>>(tiles_.size());
  std::pair<std::shared_ptr<Map_Node>, std::shared_ptr<Map_Node>> source_target_pair;
  size_t id = 0;
  for(size_t i = 0; const auto& row : tiles_) {
    size_t j = 0;
    std::transform(row.begin(), row.end(), std::back_inserter(node_map[i]), [&](const auto& tile){
      auto ret = std::make_shared<Map_Node>();
      ret->is_wall = mob.is_wall(tile);
      ret->id = id++;
      ret->posx = j++;
      ret->posy = i;
      ret->neighbors = /* TO DO */
      if(/* tile has player */) source_target_pair.first = ret;
      // default super high value for costs?
      return ret;
    });
    ++i;
  }
  source_target_pair.second = node_map[mob.x()][mob.y()];
  return source_target_pair;
}
