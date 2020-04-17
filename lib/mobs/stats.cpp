#include "stats.h"

int Stat_Block::get_hp() { return hp_; }
float Stat_Block::get_speed() { return speed_; }
float Stat_Block::get_atk_speed() { return atk_speed_; }

int Stat_Adder::get_hp() const { return inner_->get_hp() + hp_; }
float Stat_Adder::get_speed() const { return inner->get_speed() + speed_; }
float Stat_Adder::get_atk_speed() const { return inner->get_atk_speed() + atk_speed_; }

int Stat_Adder::get_hp() const { return inner_->get_hp() * hp_; }
float Stat_Adder::get_speed() const { return inner->get_speed() * speed_; }
float Stat_Adder::get_atk_speed() const { return inner->get_atk_speed() * atk_speed_; }
