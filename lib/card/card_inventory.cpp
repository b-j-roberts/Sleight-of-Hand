#include "card_inventory.h"

#include "Harmony/config_reader/config_reader.h"

Card_Inventory::Card_Inventory(sf::RenderWindow& window, const std::string& filename,
                               const Card_Pool& pool):
  draw_strat_(std::make_unique<Hand_Drawer>()) {
  Config_Reader cfg(filename);
  const auto window_height = window.getSize().y;
  const sf::Vector2f card_size(300, 500); // TO DO : Move somewhere else
  const float margin = 25.f;
  const float gap = 5.f;

  for(size_t idx = 0; const auto& name : cfg["inventory"].as_vector()) {
    const sf::Vector2f offset(static_cast<float>(idx) * (card_size.x + gap) + margin,
                              window_height - card_size.y - margin);
    cards_.push_back(pool.get_card(name.as_string()));
    translates_.emplace_back(-300, offset.y, offset.x, offset.y); // TO DO : based on inventory
    ++idx;
  }
}

void Card_Inventory::display(sf::RenderWindow& window) {
  for(size_t idx = 0; auto& card : cards_) {
    card->setup();
    draw_strat_->setup(window, idx, card->visual_, translates_[idx]);
    card->draw(window);
    ++idx;
  }
}

//std::shared_ptr<Card> pop_rand();
//std::shared_ptr<Card> pop_idx(size_t idx);
