#ifndef CARD_VISUAL_H
#define CARD_VISUAL_H

#include "card_drawer.h"

#include <memory> // shared_ptr

struct Card_Visual {

  sf::Texture t_; // TO DO
  std::shared_ptr<sf::Sprite> frame_;
  std::shared_ptr<sf::Sprite> img_;
  sf::Text name_;
  sf::Text description_;
  sf::Text cost_display_;


  explicit Card_Visual(); // TO DO
};

#endif
