#ifndef ATTACK_STRATEGY_H
#define ATTACK_STRATEGY_H

class Attack_Strategy {
public:
  virtual void do_turn(const Weapon&) const = 0;
};

class Basic_Attack : public Attack_Strategy {
public:
  void do_turn(const Weapon&) const override;
};

#endif
