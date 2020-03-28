#include "card_visual.h"

Card_Visual::Card_Visual() {
  t_.loadFromFile("rsc/Card_Template_original.jpg");
  frame_ = std::make_shared<sf::Sprite>(t_);
  frame_->setPosition(0, 0);
}
