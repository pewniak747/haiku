#include <sstream>

#include "line.h"

Line::Line(std::vector<Word*> words, LineTemplate *lineTemplate) {
  this->words = words;
  this->lineTemplate = lineTemplate;
}

std::string Line::toString(std::string (*wordToString)(Word *word)) {
  std::string resultString = lineTemplate->getJapaneseTemplate();
  for(unsigned i = 0; i < words.size(); i++) {
    std::string replacementString = wordToString(words[i]);
    std::ostringstream replacedString;
    replacedString << "$" << (i+1);
    int findPosition = resultString.find(replacedString.str());
    if(findPosition >= 0)
      resultString.replace(findPosition, 2, replacementString);
  }
  return resultString;
}
