#include <cstdio>
#include <xercesc/dom/DOM.hpp>

#include "poem_generator.h"
#include "parser.h"
#include "renderer.h"

using namespace xercesc;

int main() {
  // initialize Xerces
  try { XMLPlatformUtils::Initialize(); }
  catch (const XMLException& toCatch) { return 1; }

  WordParser *wordParser = new WordParser("data/words.xml");
  wordParser->parse();
  WordRepository *wordRepository = new WordRepository();
  wordParser->loadToRepository(wordRepository);

  TemplateParser *templateParser = new TemplateParser("data/templates.xml");
  templateParser->parse();
  PoemTemplateRepository *templateRepository = new PoemTemplateRepository();
  templateParser->loadToRepository(templateRepository);

  PoemGenerator *poemGenerator = new PoemGenerator(wordRepository, templateRepository);
  Poem *poem = poemGenerator->getPoem();
  std::string generatedKanjiPoem, generatedKanaPoem, generatedRomajiPoem, generatedEnglishPoem;
  generatedKanjiPoem = (new JapaneseKanjiRenderer(poem))->toString();
  generatedKanaPoem = (new JapaneseKanaRenderer(poem))->toString();
  generatedRomajiPoem = (new JapaneseRomajiRenderer(poem))->toString();
  generatedEnglishPoem = (new EnglishRenderer(poem))->toString();

  printf("KANJI:\n");
  printf("%s", generatedKanjiPoem.c_str());
  printf("\n");
  printf("KANA:\n");
  printf("%s", generatedKanaPoem.c_str());
  printf("\n");
  printf("ROMAJI:\n");
  printf("%s", generatedRomajiPoem.c_str());
  printf("\n");
  printf("ENGLISH:\n");
  printf("%s", generatedEnglishPoem.c_str());

  // shutdown Xerces
  XMLPlatformUtils::Terminate();
}
