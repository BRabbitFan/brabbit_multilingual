/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:30:50
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 14:14:56
 * @FilePath     : /brabbit_multilingual/src/LanguageTranslator.cpp
 * @Description  : 

 */
#include "LanguageTranslator.hpp"

#include <fstream>

namespace br {
  
  LanguageTranslator::LanguageTranslator()
    : isLoadSuccess_(false)
    , language_(Language::Unknow) {}

  LanguageTranslator::LanguageTranslator(std::string filepath) : LanguageTranslator() {
    load(filepath);
  }

  bool LanguageTranslator::load(std::string filepath) {
    if (isLoadSuccess_) {
      return isLoadSuccess_;
    }

    std::ifstream file{filepath, std::ios::in | std::ios::binary};
    bool isGood = file.good();

    while (isGood) {
      std::string original;
      if (!std::getline(file, original)) {
        isLoadSuccess_ = true;
        break;
      }
      
      std::string translation;
      if (!std::getline(file, translation)) {
        // isLoadSuccess_ = false;
        break;
      }

      Tag originalTag = doStringToTag(original);
      tagToStringMap_.insert(std::make_pair(originalTag, translation));

      std::string blank;
      if (!std::getline(file, blank)) {
        isLoadSuccess_ = true;
        break;
      }
    }

    return isLoadSuccess_;
  }

  bool LanguageTranslator::chkLoadSuccess() const {
    return isLoadSuccess_;
  }

  Language LanguageTranslator::getLanguage() const {
    return language_;
  }

  std::string LanguageTranslator::translate(Tag tag) {
    auto itor = tagToStringMap_.find(tag);
    if (itor == tagToStringMap_.end()) {
      return std::string(tag);
    }
    return itor->second;
  }

};