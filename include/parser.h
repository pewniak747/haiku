#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <xercesc/dom/DOM.hpp>

#include "repository.h"

using namespace xercesc;

template<typename T>
class Parser {
  public:
    Parser(std::string fileName);
    virtual void parse() = 0;
    void loadToRepository(Repository<T> *repository);
  protected:
    DOMElement *getXMLRoot();
    std::string xmlFileName;
    void pushElement(T *element);
    std::vector<T*> parsedElements;
};

class WordParser : public Parser<Word> {
  public:
    WordParser(std::string fileName) : Parser(fileName) {};
    void parse();
};

class TemplateParser : public Parser<PoemTemplate> {
  public:
    TemplateParser(std::string fileName) : Parser(fileName) {};
    void parse();
};

template<typename T>
Parser<T>::Parser(std::string fileName) {
  this->xmlFileName = fileName;
}

template<typename T>
void Parser<T>::pushElement(T *element) {
  parsedElements.push_back(element);
}

template<typename T>
DOMElement* Parser<T>::getXMLRoot() {
  DOMImplementation* dom_xml = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode(""));
  DOMLSParser* dom_file = dom_xml->createLSParser(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
  DOMDocument* dom_doc  = dom_file->parseURI(xmlFileName.c_str());
  return dom_doc->getDocumentElement();
}

template<typename T>
void Parser<T>::loadToRepository(Repository<T> *repository) {
  for(unsigned i = 0; i < parsedElements.size(); i++) {
    repository->add(parsedElements[i]);
  }
}

void WordParser::parse() {
  DOMElement *domRoot = getXMLRoot();
  for (DOMNode* domChild=domRoot->getFirstChild(); domChild != 0; domChild=domChild->getNextSibling()) {
    if (domChild->getNodeType() == DOMNode::ELEMENT_NODE && strcmp(XMLString::transcode(domChild->getNodeName()), "word") == 0) {
      std::string kanjiString, kanaString, romajiString, englishString, typeString;
      unsigned syllabesNum;

      DOMNamedNodeMap *domAttrs = domChild->getAttributes();
      int num= domAttrs->getLength();
      for(int i=0; i < num; i++) {
        DOMAttr* domAttr = (DOMAttr*) domAttrs->item(i);
        char* name = XMLString::transcode(domAttr->getName());
        char* value = XMLString::transcode(domAttr->getValue());
        if(strcmp(name, "type") == 0) {
          typeString = value;
        }
        else if(strcmp(name, "syllabes") == 0) {
          syllabesNum = atoi(value);
        }
      }

      for(DOMNode* nestedChild=domChild->getFirstChild(); nestedChild != 0; nestedChild = nestedChild->getNextSibling()) {
        char *name = XMLString::transcode(nestedChild->getNodeName());
        char *value = XMLString::transcode(nestedChild->getTextContent());
        if(strcmp(name, "kanji") == 0) {
          kanjiString = value;
        }
        else if(strcmp(name, "kana") == 0) {
          kanaString = value;
        }
        else if(strcmp(name, "romaji") == 0) {
          romajiString = value;
        }
        else if(strcmp(name, "english") == 0) {
          englishString = value;
        }
      }

      pushElement(new Word(kanjiString, kanaString, romajiString, englishString, typeString, syllabesNum));
    }
  }
}

void TemplateParser::parse() {
  DOMElement *domRoot = getXMLRoot();
  for (DOMNode* domChild=domRoot->getFirstChild(); domChild != 0; domChild=domChild->getNextSibling()) {
    if (domChild->getNodeType() == DOMNode::ELEMENT_NODE && strcmp(XMLString::transcode(domChild->getNodeName()), "template") == 0) {
      std::vector<LineTemplate*> lines;

      for(DOMNode* nestedChild=domChild->getFirstChild(); nestedChild != 0; nestedChild = nestedChild->getNextSibling()) {
        char *name = XMLString::transcode(nestedChild->getNodeName());
        if(strcmp(name, "line") == 0) {
          std::string japaneseString, romajiString, englishString;
          std::vector<WordTemplate*> words;
          unsigned syllabesNum;
          for(DOMNode* nestedNestedChild=nestedChild->getFirstChild(); nestedNestedChild != 0; nestedNestedChild = nestedNestedChild->getNextSibling()) {
            char *name = XMLString::transcode(nestedNestedChild->getNodeName());
            char *value = XMLString::transcode(nestedNestedChild->getTextContent());
            if(strcmp(name, "japanese") == 0) {
              japaneseString = value;
            }
            else if(strcmp(name, "romaji") == 0) {
              romajiString = value;
            }
            else if(strcmp(name, "english") == 0) {
              englishString = value;
            }
            else if(strcmp(name, "word") == 0) {
              words.push_back(new WordTemplate(value));
            }
            else if(strcmp(name, "syllabes") == 0) {
              syllabesNum = atoi(value);
            }
          }
          lines.push_back(new LineTemplate(words, japaneseString, romajiString, englishString, syllabesNum));
        }
      }
      pushElement(new PoemTemplate(lines));
    }
  }
}
#endif // PARSER_H
