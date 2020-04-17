#ifndef STATS_H
#define STATS_H

#include <memory>

// TO DO : Virtual destructors

class Stats {
  int hp_;
  float speed_;
  float atk_speed_;
public:
  virtual int get_hp() const = 0;
  virtual float get_speed() const = 0;
  virtual float get_atk_speed() const = 0;
};

class Stat_Block : public Stats {
public:
  int get_hp() const override;
  float get_speed() const override;
  float get_atk_speed() const override;
};

class Stat_Decorator : public Stats {
  // TO DO : Number of turns
  std::unique_ptr<Stats> inner_;
public:
};

class Stat_Adder : public Stat_Decorator {
public:
  int get_hp() const override;
  float get_speed() const override;
  float get_atk_speed() const override;
};

class Stat_Multiplier : public Stat_Decorator {
public:
  int get_hp() const override;
  float get_speed() const override;
  float get_atk_speed() const override;
};

#endif
