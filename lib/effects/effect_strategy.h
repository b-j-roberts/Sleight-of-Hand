#ifndef EFFECT_STRATEGY_H
#define EFFECT_STRATEGY_H

class Effect_Strategy {
public:
  virtual ~Effect_Strategy() = default;
  virtual void effect() const = 0;
};

class Null_Effect : public Effect_Strategy {
public:
  ~Null_Effect() override = default;
  void effect() const override;
};

#endif
