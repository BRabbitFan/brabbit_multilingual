/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:27:25
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 11:03:16
 * @FilePath     : /brabbit_multilingual/src/LanguageTag.hpp
 * @Description  : 
 */

#ifndef BR_LANGUAGE_TAG
#define BR_LANGUAGE_TAG

namespace br {
  
  using Tag = const char*;

  struct LanguageTag {
    static constexpr Tag Empty = "Empty";
    static constexpr Tag One = "One";
    static constexpr Tag Year = "Year";
  };

};

#endif // BR_LANGUAGE_TAG