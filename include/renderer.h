#ifndef RENDERER_H
#define RENDERER_H

#include <string>

#include "poem.h"

class Renderer {
  public:
    Renderer(Poem *poem);
    virtual std::string toString() = 0;
  protected:
    Poem *poem;
};

class JapaneseRenderer : public Renderer {
  public:
    std::string toString();
};

#endif // RENDERER_H
