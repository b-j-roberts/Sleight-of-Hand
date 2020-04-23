#ifndef MOVE_STRATEGY_H
#define MOVE_STRATEGY_H

class Move_Strategy {
public:
  // Return whether tile is a 'wall', ie cant be walked on
  virtual bool is_wall(const Tile&) const = 0;
};

class Basic_Move : public Move_Strategy {
public:
  bool is_wall(const Tile&) const override;
};

class Climbing_Move : public Move_Strategy {
public:
  bool is_wall(const Tile&) const override;
};

#endif
