#include "card/card.h"

int main() {

  sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
  sf::RenderWindow window(desktop, "Sleight of Hand");
  window.setFramerateLimit(60);

  Card card1(0);
  Card card2(1);
  Card card3(2);
  Card card4(3);
  Card card5(4);

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

    card1.setup(window);
    card1.draw(window);
    card2.setup(window);
    card2.draw(window);
    card3.setup(window);
    card3.draw(window);
    card4.setup(window);
    card4.draw(window);
    card5.setup(window);
    card5.draw(window);

    window.display();

  } // end game loop

  return 0;
}
