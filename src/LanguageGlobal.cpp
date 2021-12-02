/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 15:49:13
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-02 18:04:33
 * @FilePath     : /brabbit_multilingual/src/LanguageGlobal.cpp
 * @Description  : 
 */

#include "LanguageGlobal.hpp"

#include <map>
#include <sstream>

namespace br {

  static const std::map<Language, std::string> LanguageToStringMap = {
    {Language::Unknow, "Unknow"},
    {Language::System, "System"},
    {Language::zh_CN,  "zh_CN"},
    {Language::zh_TW,  "zh_TW"},
    {Language::en_US,  "en_US"},
    {Language::en_UK,  "en_UK"},
  };

  std::string doLanguageToString(Language language) {
    return LanguageToStringMap.at(language);
  }

  Language doStringToLanguage(std::string string) {
    Language language = Language::Unknow;
    for (auto pair : LanguageToStringMap) {
      if (pair.second == string) {
        language = pair.first;
        break;
      }
    }
    return language;
  }

  std::string doLanguageToFilename(Language language) {
    std::string filename = LanguageFilenameStart;
    auto languageString = doLanguageToString(language);
    return filename.append(languageString);
  }

  Language doFilenameToLanguage(std::string filename) {
    std::string filenameStart = LanguageFilenameStart;
    auto languageString = filename.substr(filenameStart.size());
    return doStringToLanguage(languageString);
  }

};  // namespace br