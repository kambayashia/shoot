#ifndef __OBJ_ENEMY_H_
#define __OBJ_ENEMY_H_

#include "Unit.h"

class Enemy : public Unit
{
public:
  Enemy();
  virtual ~Enemy();

  virtual void update(float delta);
  virtual void render();

  void initialize();
private:
};

#endif // __OBJ_ENEMY_H_

