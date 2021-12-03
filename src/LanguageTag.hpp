/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:27:25
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 14:45:57
 * @FilePath     : /brabbit_multilingual/src/LanguageTag.hpp
 * @Description  : LanguageTag 语言标签, 没有对应的 .cpp 文件.
 *                 每个标签可在 LanguageTranslator 中映射到一个译文.
 *                 直接使用同名字符串也是可以的, 但不建议这么做.
 */

#ifndef BR_LANGUAGE_TAG
#define BR_LANGUAGE_TAG

namespace br {
  
  using Tag = const char*;

  struct LanguageTag {
    static constexpr Tag Empty = "Empty";
    static constexpr Tag One = "One";
    static constexpr Tag Year = "Year";
  };  // struct LanguageTag

};  // namespace br

#endif // BR_LANGUAGE_TAG