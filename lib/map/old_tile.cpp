#include "tile.h"

void active() const {
  active_effect_.effect();
}

void passive() const {
  passive_effect_.effect(/* TO DO : Take mob map? */);
}

void draw(sf::RenderWindow&) const {
  // TO DO : Setup visual
  window.draw(visual_);
}
