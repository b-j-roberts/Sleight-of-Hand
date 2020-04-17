#ifndef MOVE_STRATEGY_H
#define MOVE_STRATEGY_H

class Move_Strategy {
public:
  virtual void do_turn(const Stats&) const = 0;
};

class Basic_Move : public Move_Strategy {
public:
  void do_turn(const Stats&) const override;
};

class Climbing_Move : public Move_Strategy {
public:
  void do_turn(const Stats&) const override;
};

#endif
