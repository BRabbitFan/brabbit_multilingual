/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:59:26
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 14:34:01
 * @FilePath     : /brabbit_multilingual/src/LanguageObject.cpp
 * @Description  : LanguageObject 多语言对象基类实现.
 */

#include "LanguageObject.hpp"

#include "LanguageManager.hpp"

namespace br {

LanguageObject::LanguageObject() {
  LanguageManager::instance().objectCreated(this);
}

LanguageObject::~LanguageObject() {
  LanguageManager::instance().objectDestoryed(this);
}

};  // namespace br