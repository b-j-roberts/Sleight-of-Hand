#ifndef CARD_INVENTORY_H
#define CARD_INVENTORY_H

#include "card.h"
#include "card_drawer.h"
#include "card_pool.h"

// Deck, Hand, Graveyard

class Card_Inventory {
  std::vector<std::shared_ptr<Card>> cards_;
  std::vector<Translate> translates_;
  std::unique_ptr<Card_Draw_Strategy> draw_strat_;  
public:
  Card_Inventory(sf::RenderWindow&, const std::string& filename, const Card_Pool& pool);
  
//  std::shared_ptr<Card> pop_rand(); // TO DO : Replace with shuffle
  //std::shared_ptr<Card> pop_idx(size_t idx);

  void display(sf::RenderWindow& window); // setup & draw

  void forward() { for(auto& translate : translates_) { translate.set(Direction::forward); }}
  void backward() { for(auto& translate : translates_) { translate.set(Direction::backward); }}
};

#endif
