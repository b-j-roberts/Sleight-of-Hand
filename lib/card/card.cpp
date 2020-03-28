#include "card.h"

Card::Card(size_t idx):
  idx_(idx),
  draw_strat_(std::make_shared<Hand_Drawer>()) { }

void Card::draw(sf::RenderWindow& window) {
  draw_strat_->draw(window, idx_, visual_);
}
