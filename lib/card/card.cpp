#include "card.h"

Card::Card(const std::string& name, const std::string& img_url,
           const std::string& desc, unsigned int cost):
  cost_(cost),
  visual_(name, img_url, desc, cost) { }

void Card::setup() {
  visual_.setup();
}

void Card::draw(sf::RenderWindow& window) const {
  visual_.draw(window);
}
