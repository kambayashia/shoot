#ifndef __SCENE_MYLAYER_H_
#define __SCENE_MYLAYER_H_

#include "cocos2d.h"

#define LAYER_DEFAULT_FONT_SIZE 24

class MyLayer : public cocos2d::Layer
{
public:

protected:
  cocos2d::LabelTTF *createLabel(const std::string &string, int font_size = LAYER_DEFAULT_FONT_SIZE);
};

#endif // __SCENE_MYLAYER_H_

