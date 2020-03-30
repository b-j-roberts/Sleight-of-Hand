#include "translate.h"

Translate::Translate(float bx, float by, float ex, float ey):
  time_(0),
  begin_x(bx),
  begin_y(by),
  end_x(ex),
  end_y(ey) { }

void Translate::tick() {
  if(direction == Direction::forward) {
    if(time_ >= 1.f) direction = Direction::stop;
    else time_ += tick_;
  } else if(direction == Direction::backward) {
    if(time_ <= 0.f) direction = Direction::stop;
    else time_ -= tick_;
  }
}

float Translate::move_x() { return pos_x() - begin_x; }
float Translate::move_y() { return pos_y() - begin_y; }

float Translate::pos_x() { return ( 1.f - time_) * begin_x + time_ * end_x; } 
float Translate::pos_y() { return ( 1.f - time_) * begin_y + time_ * end_y; }

void Translate::set(Direction dir) { direction = dir; }
