#ifndef __UTIL_RENDERER_H_
#define __UTIL_RENDERER_H_

class Renderer{
public:
  void makeTriangle(const float size, const bool fill = false);
  void makeQuad(const float width, const float height, const bool fill = false);
  
private:
  void makePrimitive(const float * vertices);
};

#endif // __UTIL_RENDERER_H_

