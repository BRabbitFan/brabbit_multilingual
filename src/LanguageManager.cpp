/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:23:45
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-02 18:10:09
 * @FilePath     : /brabbit_multilingual/src/LanguageManager.cpp
 * @Description  : 
 */

#include "LanguageManager.hpp"

namespace br {

  LanguageManager& LanguageManager::instance() {
    static LanguageManager instance;
    return instance;
  }

  LanguageManager::LanguageManager() {

  }

  LanguageManager::~LanguageManager() {

  }

  void LanguageManager::objectCreated(LanguageObject* object) {
    if (object == nullptr) { return; }
    objectToState_.insert(std::make_pair(object, ObjectState::Unregister));
  }

  void LanguageManager::objectDestoryed(LanguageObject* object) {
    if (object == nullptr) { return; }
    objectToState_.erase(object);
    objectToTag_.erase(object);
    objectToSetter_.erase(object);
  }

  bool LanguageManager::registerObject(LanguageObject* object, Tag tag, LanguageSetter setter) {
    if (object == nullptr) { return false; }
     
    return true;
  }

  bool LanguageManager::unregisterObject(LanguageObject* object) {
    if (object == nullptr) { return false; }
    auto itor = objectToState_.find(object);
    if (itor == objectToState_.end()) { return false; }
    if (itor->second == ObjectState::Unregister) { return false; }
    objectToTag_.erase(object);
    objectToSetter_.erase(object);
    return true;
  }

  bool LanguageManager::chkRegistered(LanguageObject* object) {
    if (object == nullptr) { return false; }
    auto itor = objectToState_.find(object);
    if (itor == objectToState_.end()) { return false; }
    return itor->second == ObjectState::Register;
  }

};  // namespace br