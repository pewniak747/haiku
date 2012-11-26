#include "renderer.h"

Renderer::Renderer(Poem *poem) {
  this->poem = poem;
}

std::string JapaneseRenderer::toString() {
  return poem->toString();
}
