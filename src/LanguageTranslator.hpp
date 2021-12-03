/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:30:41
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 14:45:39
 * @FilePath     : /brabbit_multilingual/src/LanguageTranslator.hpp
 * @Description  : LanguageTranslator 语言翻译器, 一个翻译器维护一个语言的译文.
 *                 加载语言文件后, 可通过语言标签获得某个文本的译文.
 *                 该类只支持解析简单的自定义文本语言文件 (@see ../language_file/brabbit_language_en_US)
 *                 通常情况下无需直接操作它, LanguageManager 可以构造合适的翻译器.
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
      std::map<Tag, std::string, TagComparer> tag2stringMap_;
      
  };  // class LanguageTranslator

};  // namepace br

#endif // BR_LANGUAGE_TRANSLATOR