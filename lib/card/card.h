#ifndef CARD_H
#define CARD_H

#include "card_visual.h"

class Card {

  unsigned int cost_ = 0; // TO DO
  size_t idx_; // TO DO
  
  Card_Visual visual_;
  std::shared_ptr<Card_Draw_Strategy> draw_strat_;

public:
  explicit Card(size_t idx);
  void draw(sf::RenderWindow&);
};

#endif
