/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 15:47:48
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-02 17:36:43
 * @FilePath     : /brabbit_multilingual/src/LanguageGlobal.hpp
 * @Description  : 
 */

#ifndef BR_LANGUAGE_GLOBAL
#define BR_LANGUAGE_GLOBAL

#include <functional>
#include <string>

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

  static constexpr auto LanguageFilenameStart = "brabbit_language_";

  std::string doLanguageToString(Language language);
  Language doStringToLanguage(std::string string);

  std::string doLanguageToFilename(Language language);
  Language doFilenameToLanguage(std::string filename);

};  // namespace br

#endif // BR_LANGUAGE_GLOBAL