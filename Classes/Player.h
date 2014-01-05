#ifndef __OBJ_PLAYER_H_
#define __OBJ_PLAYER_H_

#include "Unit.h"
#include "Bullet.h"

class Player : public Unit
{
  const static float DEFAULT_SPEED;
  const static cocos2d::Rect DEFAULT_SIZE;
  const static float START_POSITION;
  const static int MAX_BULLETS;
public:
  Player();
  virtual ~Player();

  virtual void update(float delta);
  virtual void render();
  virtual void collision(Unit &unit);
  
  void initialize();
  void setVelocity(const cocos2d::Point &p);
  void clearVelocity();
private:
  float mSpeed;
  cocos2d::Point mVelocity;
  BulletList mBulletList;
  
private:
  void shoot();
};

#endif // __OBJ_PLAYER_H_

