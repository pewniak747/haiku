#include <cstdio>

#include "template_parser.h"

TemplateParser::TemplateParser(std::string fileName) {
  this->xmlFileName = fileName;
}

void TemplateParser::parse() {
  std::vector<WordTemplate*> firstLineWords;
  firstLineWords.push_back(new WordTemplate("noun:place"));
  std::vector<WordTemplate*> secondLineWords;
  secondLineWords.push_back(new WordTemplate("noun:animal"));
  secondLineWords.push_back(new WordTemplate("verb:*"));
  std::vector<WordTemplate*> thirdLineWords;
  thirdLineWords.push_back(new WordTemplate("noun:element"));
  thirdLineWords.push_back(new WordTemplate("noun:element"));
  LineTemplate *firstLine = new LineTemplate(firstLineWords, "$1や", "$1 ya", "at a $1");
  LineTemplate *secondLine = new LineTemplate(secondLineWords, "$1$2", "$1 $2", "a $1 $2");
  LineTemplate *thirdLine = new LineTemplate(thirdLineWords, "$1の$2", "$1 no $2", "$1 of $2");
  std::vector<LineTemplate*> threeLines;
  threeLines.push_back(firstLine);
  threeLines.push_back(secondLine);
  threeLines.push_back(thirdLine);
  parsedElements.push_back(new PoemTemplate(threeLines));
  printf("[ DEBUG ] loaded template repository\n");
}

void TemplateParser::loadToRepository(PoemTemplateRepository *repository) {
  for(unsigned i = 0; i < parsedElements.size(); i++) {
    repository->add(parsedElements[i]);
  }
  printf("[ DEBUG ] loaded word repository\n");
}
