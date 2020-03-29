#include "card.h"

Card::Card(size_t idx):
  idx_(idx),
  draw_strat_(std::make_shared<Hand_Drawer>()) { }

void Card::setup(sf::RenderWindow& window) {
  visual_.setup();
  draw_strat_->setup(window, idx_, visual_);
}

void Card::draw(sf::RenderWindow& window) const {
  visual_.draw(window);
}
