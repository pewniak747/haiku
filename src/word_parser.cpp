#include <cstdio>
#include <xercesc/dom/DOM.hpp>

#include "word_parser.h"

WordParser::WordParser(std::string fileName) {
  this->xmlFileName = fileName;
}

void WordParser::parse() {
  DOMImplementation* dom_xml = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode(""));
  DOMLSParser* dom_file = dom_xml->createLSParser(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
  DOMDocument* dom_doc  = dom_file->parseURI(xmlFileName.c_str());
  DOMElement*  dom_root = dom_doc->getDocumentElement();

  for (DOMNode* dom_child=dom_root->getFirstChild(); dom_child != 0; dom_child=dom_child->getNextSibling()) {
    if (dom_child->getNodeType() == DOMNode::ELEMENT_NODE && strcmp(XMLString::transcode(dom_child->getNodeName()), "word") == 0) {
      std::string kanjiString, kanaString, romajiString, englishString, typeString;

      DOMNamedNodeMap *dom_attrs = dom_child->getAttributes();
      int num= dom_attrs->getLength();
      for(int i=0; i < num; i++) {
        DOMAttr* dom_attr = (DOMAttr*) dom_attrs->item(i);
        char* name = XMLString::transcode(dom_attr->getName());
        if(strcmp(name, "type") == 0) {
          typeString = XMLString::transcode(dom_attr->getValue());
        }
      }

      for(DOMNode* nestedChild=dom_child->getFirstChild(); nestedChild != 0; nestedChild = nestedChild->getNextSibling()) {
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

      parsedElements.push_back(new Word(kanjiString, kanaString, romajiString, englishString, typeString));
    }
  }
}

void WordParser::loadToRepository(WordRepository *repository) {
  for(unsigned i = 0; i < parsedElements.size(); i++) {
    repository->add(parsedElements[i]);
  }
}
