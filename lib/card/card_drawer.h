#ifndef CARD_DRAWER_H
#define CARD_DRAWER_H

#include <SFML/Graphics.hpp>

struct Card_Visual; // Forward Declaration

class Card_Draw_Strategy {
public:
  virtual ~Card_Draw_Strategy() = default;
  virtual void draw(sf::RenderWindow&, size_t idx, Card_Visual&) const = 0;
};

class Hand_Drawer : public Card_Draw_Strategy {
public:
  ~Hand_Drawer() override = default;
  void draw(sf::RenderWindow&, size_t idx, Card_Visual&) const override;
};

/*
class Graveyard_Drawer : public Card_Draw_Strategy {
public:
  void draw(sf::RenderWindow&, const Card&) const override;
};

class Selected_Drawer : public Card_Draw_Strategy {
public:
  void draw(sf::RenderWindow&, const Card&) const override;
};

class Deckbuild_Drawer : public Card_Draw_Strategy {
public:
  void draw(sf::RenderWindow&, const Card&) const override;
};
*/

#endif
