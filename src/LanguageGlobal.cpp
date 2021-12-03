/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 15:49:13
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 14:34:16
 * @FilePath     : /brabbit_multilingual/src/LanguageGlobal.cpp
 * @Description  : 多语言机制全局变量/方法实现.
 */

#include "LanguageGlobal.hpp"

#include <map>
#include <sstream>

namespace br {

  static const std::map<Language, std::string> Language2StringMap = {
    {Language::Unknow, "Unknow"},
    {Language::System, "System"},
    {Language::zh_CN,  "zh_CN"},
    {Language::zh_TW,  "zh_TW"},
    {Language::en_US,  "en_US"},
    {Language::en_UK,  "en_UK"},
  };

  std::string doLanguageToString(Language language) {
    return Language2StringMap.at(language);
  }

  Language doStringToLanguage(std::string string) {
    Language language = Language::Unknow;
    for (auto pair : Language2StringMap) {
      if (pair.second == string) {
        language = pair.first;
        break;
      }
    }
    return language;
  }

  std::string doLanguageToFilename(Language language) {
    std::string filename = LanguageFilenameStart;
    std::string languageString = doLanguageToString(language);
    return filename.append(languageString);
  }

  Language doFilenameToLanguage(std::string filename) {
    std::string filenameStart = LanguageFilenameStart;
    std::string languageString = filename.substr(filenameStart.size());
    return doStringToLanguage(languageString);
  }

  std::string doLanguageToFilepath(Language language) {
    std::string filepath = LanguageFilepathStart;
    std::string filename = doLanguageToFilename(language);
    return filepath.append(filename);
  }

  Language doFilepathToLanguage(std::string filepath) {
    std::string filepathStart = LanguageFilepathStart;
    std::string filename = filepath.substr(filepathStart.size());
    return doFilenameToLanguage(filename);
  }

  Tag doStringToTag(std::string string) {
    auto tagSize = string.size() + 1;
    auto tagCstr = string.c_str();
    return strcpy(static_cast<char*>(malloc(tagSize)), tagCstr);
  }

  std::string doTagToString(Tag tag) {
    return std::string(tag);
  }

};  // namespace br