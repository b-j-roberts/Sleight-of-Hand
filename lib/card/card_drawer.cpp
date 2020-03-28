#include "card_drawer.h"
#include "card_visual.h"

void Hand_Drawer::draw(sf::RenderWindow& window, size_t idx, Card_Visual& card_visual) const {
  
  // TO DO : Think about moving out const's
  const auto window_height = window.getSize().y;
  const sf::Vector2f card_size(300, 500); // TO DO : Move somewhere else
  const float margin = 50.f;
  const float gap = 30.f;
  const sf::Vector2f offset(static_cast<float>(idx) * (card_size.x + gap) + margin,
                            window_height - card_size.y - margin);

  // Frame
  card_visual.frame_->setPosition(offset);
  window.draw(*(card_visual.frame_));
  
  // Image
  sf::RectangleShape img(sf::Vector2f(227, 227));
  img.setFillColor(sf::Color::Red);
  const sf::Vector2f img_offset(37, 102); // TO DO : Move somewhere else
  img.setPosition(img_offset + offset);
  window.draw(img);

  // Name
  sf::RectangleShape title(sf::Vector2f(232,44));
  title.setFillColor(sf::Color(200, 0, 0, 90));
  const sf::Vector2f title_offset(34, 45);
  title.setPosition(title_offset + offset);
  window.draw(title);

  // Cost
  sf::RectangleShape cost_rect(sf::Vector2f(33,36));
  cost_rect.setFillColor(sf::Color(200, 0, 0, 90));
  const sf::Vector2f cost_rect_offset(15, 450);
  cost_rect.setPosition(cost_rect_offset + offset);
  window.draw(cost_rect);

  // Desc
  sf::RectangleShape desc(sf::Vector2f(227,80));
  desc.setFillColor(sf::Color(200, 0, 0, 90));
  const sf::Vector2f desc_offset(37, 350);
  desc.setPosition(desc_offset + offset);
  window.draw(desc);

}
