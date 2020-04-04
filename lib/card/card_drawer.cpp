#include "card_drawer.h"
#include "card_visual.h"

void Hand_Drawer::setup(sf::RenderWindow& window, size_t idx, 
                        Card_Visual& card_visual, Translate& translate) {
  // TO DO : Think about moving out const's
 /* const auto window_height = window.getSize().y;
  const sf::Vector2f card_size(300, 500); // TO DO : Move somewhere else
  const float margin = 50.f;
  const float gap = 30.f;
  const sf::Vector2f offset(static_cast<float>(idx) * (card_size.x + gap) + margin,
                            window_height - card_size.y - margin); 
 */
  const float scale = 1.f;
  sf::Vector2f transform(translate.pos_x(), translate.pos_y());

  card_visual.frame_->setScale(scale, scale);
  card_visual.frame_->move(transform);

  card_visual.name_.setScale(scale, scale);
  card_visual.name_.setPosition(card_visual.name_.getPosition() * scale + transform);

  card_visual.img_->setScale(scale, scale);
  card_visual.img_->move(transform);

  card_visual.cost_display_.setScale(scale, scale);
  card_visual.cost_display_.setPosition(card_visual.cost_display_.getPosition() * scale + transform);

  card_visual.description_.setScale(scale, scale);
  card_visual.description_.setPosition(card_visual.description_.getPosition() * scale + transform);

  translate.tick();
}
