#include "move_strategy.h"

bool Basic_Move::is_wall(const Tile& tile) const {
  return tile.has_wall() || tile.has_mob();
}

bool Climbing_Move::is_wall(const Tile& tile) const {
  return tile.has_mob();
}

