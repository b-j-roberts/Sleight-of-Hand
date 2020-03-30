#include "card/card_pool.h"
#include "card/card_inventory.h"

int main() {

  sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
  sf::RenderWindow window(desktop, "Sleight of Hand");
  window.setFramerateLimit(60);

  Card_Pool card_pool("rsc/Cards.cfg");
  Card_Inventory hand("rsc/Hand.cfg", card_pool);

  // Game Loop
  sf::Event event;
  while(window.isOpen()) {

    // INPUT
    while(window.pollEvent(event)) {
      switch(event.type) {
        case sf::Event::Closed:
          window.close();
          break;

        default: break;
      }
    }

    // UPDATE


    // DRAW
    window.clear();

    hand.display(window);
    
    window.display();

  } // end game loop

  return 0;
}
