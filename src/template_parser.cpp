#include <cstdio>
#include <xercesc/dom/DOM.hpp>

#include "template_parser.h"

TemplateParser::TemplateParser(std::string fileName) {
  this->xmlFileName = fileName;
}

void TemplateParser::parse() {
  DOMImplementation* dom_xml = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode(""));
  DOMLSParser* dom_file = dom_xml->createLSParser(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
  DOMDocument* dom_doc  = dom_file->parseURI(xmlFileName.c_str());
  DOMElement*  dom_root = dom_doc->getDocumentElement();

  for (DOMNode* dom_child=dom_root->getFirstChild(); dom_child != 0; dom_child=dom_child->getNextSibling()) {
    if (dom_child->getNodeType() == DOMNode::ELEMENT_NODE && strcmp(XMLString::transcode(dom_child->getNodeName()), "template") == 0) {
      std::vector<LineTemplate*> lines;

      for(DOMNode* nestedChild=dom_child->getFirstChild(); nestedChild != 0; nestedChild = nestedChild->getNextSibling()) {
        char *name = XMLString::transcode(nestedChild->getNodeName());
        if(strcmp(name, "line") == 0) {
          std::string japaneseString, romajiString, englishString;
          std::vector<WordTemplate*> words;
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
          }
          lines.push_back(new LineTemplate(words, japaneseString, romajiString, englishString));
        }
      }
      parsedElements.push_back(new PoemTemplate(lines));
    }
  }
}

void TemplateParser::loadToRepository(PoemTemplateRepository *repository) {
  for(unsigned i = 0; i < parsedElements.size(); i++) {
    repository->add(parsedElements[i]);
  }
}
