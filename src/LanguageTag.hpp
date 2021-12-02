/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:27:25
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-02 17:36:31
 * @FilePath     : /brabbit_multilingual/src/LanguageTag.hpp
 * @Description  : 
 */

#ifndef BR_LANGUAGE_TAG
#define BR_LANGUAGE_TAG

namespace br {
  
  using Tag = const char*;

  struct LanguageTag {
    static constexpr Tag Empty = "";
  };

};

#endif // BR_LANGUAGE_TAG