#ifndef CARD_POOL_H
#define CARD_POOL_H

#include "card.h"

#include <map>
#include <string>

class Card_Pool {
  std::map<std::string, std::shared_ptr<Card>> pool_;
  // TO DO : Default card?
public:
  // Create a Card_Pool from a cfg file ( using harmony's config_reader.h )
  Card_Pool(const std::string& filename);
  // Get card with cooresponding name 
  // TO DO : Change to some other form of ID
  std::shared_ptr<Card> get_card(const std::string& name) const;
};

#endif
