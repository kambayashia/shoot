#include "MyLayer.h"

USING_NS_CC;

LabelTTF *MyLayer::createLabel(const std::string &string, int font_size)
{
  return LabelTTF::create(string, "Arial", font_size);
}

