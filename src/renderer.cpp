#include "renderer.h"

std::string wordToJapaneseKanjiConverter(Word *word) {
  return word->getJapaneseKanji();
};

std::string wordToEnglishConverter(Word *word) {
  return word->getEnglish();
};

Renderer::Renderer(Poem *poem) {
  this->poem = poem;
}

std::string JapaneseKanjiRenderer::toString() {
  return poem->toString(&wordToJapaneseKanjiConverter);
}

std::string EnglishRenderer::toString() {
  return poem->toString(&wordToEnglishConverter);
}
