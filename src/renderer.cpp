#include "renderer.h"

std::string wordToJapaneseConverter(Word *word) {
  return word->getJapanese();
};

Renderer::Renderer(Poem *poem) {
  this->poem = poem;
}

std::string JapaneseRenderer::toString() {
  return poem->toString(&wordToJapaneseConverter);
}
