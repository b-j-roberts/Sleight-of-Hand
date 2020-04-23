#include "pathfinder.h"

#include <cstdlib>

Path::Path() { }

void Path::find(const std::vector<std::vector<Tile>>& tile_map) {
  const sf::Vector2i start(0, 0);
}

struct Direction { north = 0, south, east, west };

int compute_f_cost(int h_cost_current, int posx, int posy, int desx, int desy) {
  return h_cost_current + 1 + std::abs(desx - posx) + std::abs(desy - posy);
}

void the_function(const Board& board, const Mob& mob) {
  std::vector<std::vector<std::shared_ptr<Map_Node>>> node_map;
  auto source_target_pair = board.create_node_map(node_map, mob); // TO DO: these func
  source_target_pair.first->h_cost = 0;
  source_target_pair.first->f_cost = 0;
  
  std::set<std::shared_ptr<Map_Node>, Map_Node_Cmp> open_nodes; // to be evaluated
  std::set<std::shared_ptr<Map_Node, Map_Node_Cmp>> closed_nodes; // evaluated
  open_nodes.insert(source_target_pair.first);
  std::shared_ptr<Map_Node> current;
  while(!open_nodes.empty()) {
    
    int min_f_cost = 100000;
    for(const auto& node : open_nodes) { 
      if(node->f_cost < min_f_cost) {
        min_f_cost = node->f_cost;
        current = node;
      }
    }

    open_nodes.remove(current);
    closed_nodes.insert(current);

    if(current->id == source_target_pair.second->id) break;

    for(auto& [key, node] : current->neighbors) {
      if(node->is_wall || closed_nodes.count(node)) continue;
      
      int new_f_cost = compute_f_cost(current->h_cost, node->posx, node->posy, mob.x(), mob.y());
      if(new_f_cost < node->f_cost || open_nodes.count(node) == 0) {
        node->f_cost = new_f_cost;
        node->h_cost = current->h_cost + 1;
        node->parent = current;
        if(open_nodes.count(node) == 0) open_nodes.insert(node);
      }
    }
  }

  // traceback parents from target
  if(current->id == source_target_pair.second->id) {

  } else {
    // there is no path
  }

}

// Update
