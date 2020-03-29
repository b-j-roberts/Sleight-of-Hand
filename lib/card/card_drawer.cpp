#include "card_drawer.h"
#include "card_visual.h"

void Hand_Drawer::setup(sf::RenderWindow& window, size_t idx, Card_Visual& card_visual) {
  // TO DO : Think about moving out const's
  const auto window_height = window.getSize().y;
  const sf::Vector2f card_size(300, 500); // TO DO : Move somewhere else
  const float margin = 50.f;
  const float gap = 30.f;
  const sf::Vector2f offset(static_cast<float>(idx) * (card_size.x + gap) + margin,
                            window_height - card_size.y - margin); 
  const float scale = 1.f;

  card_visual.frame_->setScale(scale, scale);
  card_visual.frame_->move(offset);

  // Image TO DO
  /*sf::RectangleShape img(sf::Vector2f(227, 227));
  img.setFillColor(sf::Color::Red);
  const sf::Vector2f img_offset(37 * scale, 102 * scale);
  img.setPosition(img_offset + offset);
  img.setScale(scale, scale);
  window.draw(img);*/
  
  card_visual.name_.setScale(scale, scale);
  card_visual.name_.setPosition(card_visual.name_.getPosition() * scale + offset);

  card_visual.cost_display_.setScale(scale, scale);
  card_visual.cost_display_.setPosition(card_visual.cost_display_.getPosition() * scale + offset);

  card_visual.description_.setScale(scale, scale);
  card_visual.description_.setPosition(card_visual.description_.getPosition() * scale + offset);
}
