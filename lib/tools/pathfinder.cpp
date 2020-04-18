#include "pathfinder.h"

Path::Path() { }

void Path::find(const std::vector<std::vector<Tile>>& tile_map) {
  const sf::Vector2i start(0, 0);
}

struct Direction { north = 0, south, east, west };

void the_function(const Board& board, const Mob& mob) {
  std::vector<std::vector<std::shared_ptr<Map_Node>>> node_map;
  auto source_target_pair = board.create_node_map(node_map, mob); // TO DO: these func
  std::set<std::shared_ptr<Map_Node>, Map_Node_Cmp> open_nodes; // to be evaluated
  std::set<std::shared_ptr<Map_Node, Map_Node_Cmp>> closed_nodes; // evaluated
  open_nodes.insert(source_target_pair.first);
  while(/* there still is ground to explore -- !open_nodes.empty()*/) {
    std::shared_ptr<Map_Node> current = /* lowest f_cost node in open_nodes*/;
    open_nodes.remove(current);
    closed_nodes.insert(current);

    if(current->id == source_target_pair.second->id) break;

    for(auto& [key, node] : current.neighbors) {
      if(node->is_wall || closed_nodes.count(node)) continue;
      if(/* new f_cost for node is lower */ || open_nodes.count(node) == 0) {
        // node->f_cost = new f_cost;
        node->parent = current;
        if(open_nodes.count(node) == 0) open_nodes.insert(node);
      }
    }
  }

  // traceback parents from target

}

// Update
