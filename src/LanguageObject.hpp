/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:53:07
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 14:37:35
 * @FilePath     : /brabbit_multilingual/src/LanguageObject.hpp
 * @Description  : LanguageObject 多语言对象基类, 需要使用多语言机制的类请继承该类.
 *                 该类的作用仅仅是构造/析构时通知 LanguageManager 做一些初始化/资源释放等工作,
 *                 因此通常情况下不必担心多重继承所带来的问题.
 */

#ifndef BR_LANGUAGE_OBJECT
#define BR_LANGUAGE_OBJECT

namespace br {

class LanguageObject {
  public:
    LanguageObject();
    ~LanguageObject();

};  // class LanguageObject

};  // namespace br

#endif // BR_LANGUAGE_OBJECT