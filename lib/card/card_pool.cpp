#include "card_pool.h"

#include "Harmony/config_reader/config_reader.h"

#include <sstream> // istringstream

Card_Pool::Card_Pool(const std::string& filename) {
  Config_Reader cfg(filename);
  for(const auto& [name, config] : cfg.configs()) {
    // Parse description
    std::string description;
    std::istringstream ss(config["desc"].as_string());
    size_t acc = 0;
    for(std::string curr; ss >> curr; ) { // split on words
      if(curr.length() + acc > 28) { // TO DO : size
        description += '\n' + curr + ' ';
        acc = curr.length() + 1;
      } else {
        description += curr + ' ';
        acc += curr.length() + 1;
      }
    }

    // Add to pool
    pool_.emplace(name, std::make_shared<Card>(name, config["img_loc"].as_string(), 
                                               description, config["cost"].as_int()));
  }
}

std::shared_ptr<Card> Card_Pool::get_card(const std::string& name) const {
  return pool_.at(name); // TO DO : Default card for no name?
}
