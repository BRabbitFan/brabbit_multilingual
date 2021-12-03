/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:59:26
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 13:43:50
 * @FilePath     : /brabbit_multilingual/src/LanguageObject.cpp
 * @Description  : 
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