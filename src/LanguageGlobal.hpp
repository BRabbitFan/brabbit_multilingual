/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 15:47:48
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 13:57:15
 * @FilePath     : /brabbit_multilingual/src/LanguageGlobal.hpp
 * @Description  : 
 */

#ifndef BR_LANGUAGE_GLOBAL
#define BR_LANGUAGE_GLOBAL

#include <functional>
#include <string>
#include <cstring>

#include "LanguageTag.hpp"

namespace br {

  enum class Language {
    Unknow = -1,
    System = 0,
    zh_CN  = 1,
    zh_TW  = 2,
    en_US  = 3,
    en_UK  = 4,
  };  // enum class Language

  using LanguageSetter = std::function<void(std::string)>;

  struct TagComparer {
    bool operator()(Tag tagA, Tag tagB) {  
      return std::strcmp(tagA, tagB) < 0;
    }
  };

  static constexpr auto LanguageFilenameStart = "brabbit_language_";
  static constexpr auto LanguageFilenamePath = "./language_file/";

  std::string doLanguageToString(Language language);
  Language doStringToLanguage(std::string string);

  std::string doLanguageToFilename(Language language);
  Language doFilenameToLanguage(std::string filename);

  std::string doLanguageToFilepath(Language language);
  Language doFilepathToLanguage(std::string filepath);

  Tag doStringToTag(std::string string);
  std::string doTagToString(Tag tag);

};  // namespace br

#endif // BR_LANGUAGE_GLOBAL