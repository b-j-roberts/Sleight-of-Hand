#include "card_inventory.h"

#include "Harmony/config_reader/config_reader.h"

Card_Inventory::Card_Inventory(const std::string& filename, const Card_Pool& pool):
  draw_strat_(std::make_unique<Hand_Drawer>()) {
  Config_Reader cfg(filename);
  for(const auto& name : cfg["inventory"].as_vector()) {
    cards_.push_back(pool.get_card(name.as_string()));
  }
}

void Card_Inventory::display(sf::RenderWindow& window) {
  for(size_t idx = 0; auto& card : cards_) {
    card->setup();
    draw_strat_->setup(window, idx++, card->visual_);
    card->draw(window);
  }
}

//std::shared_ptr<Card> pop_rand();
//std::shared_ptr<Card> pop_idx(size_t idx);
