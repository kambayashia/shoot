#ifndef __OBJ_BULLET_H_
#define __OBJ_BULLET_H_

#include "Unit.h"

class BulletList;
class Bullet : public Unit
{
public:
  Bullet();
  virtual ~Bullet();

  virtual void update(float delta);
  virtual void render();

  void initialize();
  bool isActive(){
    return mActive;
  }
  void use(){
    mActive = true;
  }
private:
  bool mActive;
  BulletList *mHolder;
  
private:
  void setHolder(BulletList *holder){
    mHolder = holder;
  }
};

#include <vector>
#include <deque>

class BulletList{
public:
  BulletList(int size);
  virtual ~BulletList();
  
  void initialize();
  Bullet *getUnsedBullet();
  
private:
  Bullet *mBullets;
  int mCount;
  std::deque<Bullet *> mUnused;
};
#endif // __OBJ_BULLET_H_

