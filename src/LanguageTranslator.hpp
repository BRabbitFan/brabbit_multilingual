/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:30:41
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 14:14:12
 * @FilePath     : /brabbit_multilingual/src/LanguageTranslator.hpp
 * @Description  : 
 */

#ifndef BR_LANGUAGE_TRANSLATOR
#define BR_LANGUAGE_TRANSLATOR

#include <string>
#include <map>

#include "LanguageGlobal.hpp"
#include "LanguageTag.hpp"

namespace br {
  
  class LanguageTranslator {
    public:
      LanguageTranslator();
      LanguageTranslator(std::string filepath);

    public:
      bool load(std::string filepath);
      bool chkLoadSuccess() const;
      Language getLanguage() const;
      std::string translate(Tag tag);

    protected:
      bool isLoadSuccess_;
      Language language_;
      std::map<Tag, std::string, TagComparer> tagToStringMap_;
  };

};

#endif // BR_LANGUAGE_TRANSLATOR