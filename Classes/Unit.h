#ifndef __OBJ_UNIT_H_
#define __OBJ_UNIT_H_

#include "cocos2d.h"
#include "box2d/common/b2math.h"

#include "Types.h"

class Unit
{
public:
  Unit();
  virtual ~Unit();

  virtual void update(float delta) = 0;
  virtual void render() = 0;
  virtual void collision(Unit &unit);
  
private:
  cocos2d::Point mPosition;
  cocos2d::Rect mSize;
  eDrawState mDrawState;
  
public:
  void addPosition(const cocos2d::Point &point){
    this->setPosition(mPosition + point);
  }
  void setPosition(const cocos2d::Point &point){
    mPosition = point;
  }
  cocos2d::Point getPosition(){
    return mPosition;
  }
  void setSize(const cocos2d::Rect &size){
    mSize = size;
  }
  cocos2d::Rect getSize(){
    return mSize;
  }
  void enableDraw(){
    mDrawState = eDRAW_STATE_ENABLE;
  }
  void disableDraw(){
    mDrawState = eDRAW_STATE_DISABLE;
  }
  

};

#endif // __OBJ_UNIT_H_

