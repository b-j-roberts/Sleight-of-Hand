#ifndef TRANSLATE_H
#define TRANSLATE_H

enum class Direction { forward, backward, stop };

// TO DO : Generalize ( rn is only linear )
// TO DO : Bessier
class Translate {

  Direction direction = Direction::stop;

  const float tick_ = 1.f / 60.f; // TO DO

  float time_; // in seconds
  
  // TO DO : sf::Vector2f?
  const float begin_x, begin_y;
  const float end_x, end_y;

public:
  // params : begin x, begin y, end x, end y
  Translate(float, float, float, float);
  void tick();

  // Return amount to move from begin
  float move_x();
  float move_y();

  // Return x & y pos
  float pos_x();
  float pos_y();

  void set(Direction);
};

#endif
