#include "Util.h"
#include <cocos2d.h>

USING_NS_CC;

Size Util::getDisplaySize(){
  return Director::getInstance()->getVisibleSize();
}
Point Util::getCenterPosition(){
  auto display_size = getDisplaySize();
  Point p = Point(display_size.width / 2, display_size.height / 2);
  
  return p;
}