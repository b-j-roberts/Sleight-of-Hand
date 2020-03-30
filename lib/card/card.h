#ifndef CARD_H
#define CARD_H

#include "card_visual.h"

class Card {

  //size_t idx_ = 0; // TO DO
  //std::shared_ptr<Card_Draw_Strategy> draw_strat_;
  
  unsigned int cost_;
  Card_Visual visual_;

public:
  // params : name, image url / location, description, cost
  Card(const std::string&, const std::string&, const std::string&, unsigned int);
  void setup();
  void draw(sf::RenderWindow&) const;
  friend class Card_Inventory;
};

#endif
