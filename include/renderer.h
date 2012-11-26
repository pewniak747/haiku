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

class JapaneseKanjiRenderer : public Renderer {
  public:
    JapaneseKanjiRenderer(Poem *poem) : Renderer(poem) {};
    std::string toString();
};

class JapaneseKanaRenderer : public Renderer {
  public:
    JapaneseKanaRenderer(Poem *poem) : Renderer(poem) {};
    std::string toString();
};

class JapaneseRomajiRenderer : public Renderer {
  public:
    JapaneseRomajiRenderer(Poem *poem) : Renderer(poem) {};
    std::string toString();
};

class EnglishRenderer : public Renderer {
  public:
    EnglishRenderer(Poem *poem) : Renderer(poem) {};
    std::string toString();
};

#endif // RENDERER_H
