#ifndef CARD_INVENTORY_H
#define CARD_INVENTORY_H

#include "card.h"

#include <vector>

// TO DO : Somekind of enum and factory for creating Hand, Graveyard, ...
// TO DO : Somekind of mechanism for moving cards between inventories

class Card_Inventory {
protected:
  std::vector<std::shared_ptr<Card>> cards_; // TO DO : array?
  std::unique_ptr<Card_Draw_Strategy> draw_strat_;
public:
  Card_Inventory(); // TO DO
  virtual ~Card_Inventory() = default;
  void display(sf::RenderWindow&); // Setup & draw
}

#endif
