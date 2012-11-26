#include "word_template.h"

WordTemplate::WordTemplate(std::string type) {
  this->type = type;
  this->wordType = splitString(type)[0];
  this->wordCategory = splitString(type)[1];
}

bool WordTemplate::matches(std::string otherType) {
  std::string otherWordType = splitString(otherType)[0];
  std::string otherWordCategory = splitString(otherType)[1];
  return (wordType == "*") ||
         (wordType == otherWordType && otherWordCategory == "*") ||
         (wordType == otherWordType && wordCategory == otherWordCategory);
}

std::vector<std::string> WordTemplate::splitString(std::string input) {
  std::vector<std::string> result;
  result.push_back("");
  for(unsigned i = 0; i < input.size(); i++) {
    if(input[i] != ':')
      result.back() += input[i];
    else
      result.push_back("");
  }
  if(result.size() == 1) result.push_back("*");
  return result;
}
