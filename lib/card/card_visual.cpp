#include "card_visual.h"

Card_Visual::Card_Visual(const std::string& name, const std::string& img_loc,
                         const std::string& desc, unsigned int cost) {
  t_.loadFromFile("rsc/frames/original_frame.png");
  frame_ = std::make_shared<sf::Sprite>(t_);
  frame_strat_ = std::make_shared<Original_Frame>();
  f_.loadFromFile("rsc/fonts/FreeMonoBold.ttf");
  name_.setFont(f_);
  name_.setFillColor(sf::Color::Black);
  name_.setCharacterSize(16);
  name_.setString(name);
  cost_display_.setFont(f_);
  cost_display_.setFillColor(sf::Color::Black);
  cost_display_.setCharacterSize(36);
  cost_display_.setString(std::to_string(cost));
  description_.setFont(f_);
  description_.setFillColor(sf::Color::Black);
  description_.setString(desc);
  description_.setCharacterSize(12);
  //description_.setLineSpacing(1.2); // TO DO : 2.5.1
  t2_.loadFromFile(img_loc);
  img_ = std::make_shared<sf::Sprite>(t2_);
}

void Card_Visual::setup() {
  frame_strat_->setup(*this);
}

void Card_Visual::draw(sf::RenderWindow& window) const {
  window.draw(*(frame_));
  window.draw(name_);
  window.draw(*(img_));
  window.draw(cost_display_);
  window.draw(description_);
}

void center_Text(sf::Text& text, const sf::Vector2f& rect_size) {
  sf::FloatRect text_bound = text.getGlobalBounds();
  text.setPosition((rect_size.x - text_bound.width) / 2, (rect_size.y - text_bound.height) / 2);
  // Move based on text bounds
  text_bound = text.getGlobalBounds();
  text.move(text.getPosition() - sf::Vector2f(text_bound.left, text_bound.top));
}

void Original_Frame::setup(Card_Visual& card) const {
  card.frame_->setPosition(0, 0); 
  center_Text(card.name_, sf::Vector2f(232, 44));
  card.name_.move(34, 45);
  card.img_->setPosition(37, 102);
  center_Text(card.cost_display_, sf::Vector2f(33, 36));
  card.cost_display_.move(15, 450);
  card.description_.setPosition(37, 350);
}
