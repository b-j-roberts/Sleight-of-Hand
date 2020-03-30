#ifndef CARD_VISUAL_H
#define CARD_VISUAL_H

#include "card_drawer.h"

#include <memory> // shared_ptr
#include <string>

class Card_Frame_Strategy; // forward declaration

struct Card_Visual {

  sf::Texture t_; // TO DO
  sf::Font f_; // TO DO

  std::shared_ptr<sf::Sprite> frame_;
  std::shared_ptr<Card_Frame_Strategy> frame_strat_;

  std::shared_ptr<sf::Sprite> img_;
  sf::Text name_;
  sf::Text description_;
  sf::Text cost_display_;


  // params: name, image url/location, description, cost
  Card_Visual(const std::string&, const std::string&, const std::string&, unsigned int);
  void setup();
  void draw(sf::RenderWindow&) const;
};

class Card_Frame_Strategy {
public:
  virtual ~Card_Frame_Strategy() = default;
  virtual void setup(Card_Visual&) const = 0;
};

class Original_Frame : public Card_Frame_Strategy {
public:
  ~Original_Frame() override = default;
  void setup(Card_Visual&) const override;
};

#endif
