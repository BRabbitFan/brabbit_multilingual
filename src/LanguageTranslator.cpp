/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:30:50
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-02 17:36:29
 * @FilePath     : /brabbit_multilingual/src/LanguageTranslator.cpp
 * @Description  : 
 */

#include "LanguageTranslator.hpp"

namespace br {
  
  LanguageTranslator::LanguageTranslator()
    : isLoadSuccess_(false)
    , language_(Language::Unknow) {}

  LanguageTranslator::LanguageTranslator(std::string filename) : LanguageTranslator() {
    load(filename);
  }

  bool LanguageTranslator::load(std::string filename) {
    // TODO : 加载文件, 填充 tagToStringMap_
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