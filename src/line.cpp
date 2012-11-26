#include <sstream>

#include "line.h"

Line::Line(std::vector<Word*> words, LineTemplate *lineTemplate) {
  this->words = words;
  this->lineTemplate = lineTemplate;
}

std::string Line::toString() {
  std::string resultString = this->lineTemplate->getJapaneseTemplate();
  for(unsigned i = 0; i < this->words.size(); i++) {
    std::string replacementString = this->words[i]->getJapanese();
    std::ostringstream replacedString;
    replacedString << "$" << (i+1);
    int findPosition = resultString.find(replacedString.str());
    if(findPosition >= 0)
      resultString.replace(findPosition, 2, replacementString);
  }
  return resultString;
}
