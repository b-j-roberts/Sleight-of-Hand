#include "card/card_pool.h"
#include "card/card_inventory.h"

#include "map/board.h"
#include "mobs/mob.h"

int main() {

  sf::VideoMode desktop = sf::VideoMode().getDesktopMode(); // TO DO : Full SCreen
  sf::RenderWindow window(desktop, "Sleight of Hand");
  window.setFramerateLimit(60);

  Board board;

  Card_Pool card_pool("rsc/cfg/Cards.cfg");
  Card_Inventory hand(window, "rsc/cfg/Hand.cfg", card_pool);

  Mob monster;

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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      hand.forward();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      hand.backward();
    }
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::ESC)) {
    //  window.close();
    //}

    // UPDATE
    monster.turn();


    // DRAW
    window.clear();

    board.draw(window);
    monster.draw(window);

    hand.display(window);
    
    window.display();

  } // end game loop

  return 0;
}
