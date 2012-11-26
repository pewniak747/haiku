#include "renderer.h"

std::string wordToJapaneseKanjiConverter(Word *word) {
  return word->getJapaneseKanji();
};

Renderer::Renderer(Poem *poem) {
  this->poem = poem;
}

std::string JapaneseKanjiRenderer::toString() {
  return poem->toString(&wordToJapaneseKanjiConverter);
}
