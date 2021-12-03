/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:23:45
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 15:52:21
 * @FilePath     : /brabbit_multilingual/src/LanguageManager.cpp
 * @Description  : LanguageManager 语言管理器实现
 */

#include "LanguageManager.hpp"

namespace br {

  LanguageManager& LanguageManager::instance() {
    static LanguageManager instance;
    return instance;
  }

  void LanguageManager::objectCreated(LanguageObject* object) {
    if (object == nullptr) {
      return;
    }
    object2stateMap_[object] = ObjectState::Unregister;
  }

  void LanguageManager::objectDestoryed(LanguageObject* object) {
    if (object == nullptr) {
      return;
    }
    object2stateMap_.erase(object);
    object2tagMap_.erase(object);
    object2setterMap_.erase(object);
  }

  bool LanguageManager::registerObject(LanguageObject* object, Tag tag, LanguageSetter setter) {
    if (object == nullptr) {
      return false;
    }
    object2stateMap_[object] = ObjectState::Register;
    object2tagMap_[object] = tag;
    object2setterMap_[object] = setter;
    updateObjectLanguage(object);
    return true;
  }

  bool LanguageManager::unregisterObject(LanguageObject* object) {
    if (object == nullptr) {
      return false;
    }
    
    auto itor = object2stateMap_.find(object);
    if (itor == object2stateMap_.end() || itor->second == ObjectState::Unregister) {
      return false;
    }
    
    object2tagMap_.erase(object);
    object2setterMap_.erase(object);
    return true;
  }

  bool LanguageManager::chkRegistered(LanguageObject* object) {
    if (object == nullptr) {
      return false;
    }
    auto itor = object2stateMap_.find(object);
    if (itor == object2stateMap_.end()) {
      return false;
    }
    return itor->second == ObjectState::Register;
  }

  bool LanguageManager::setLanguage(Language language) {
    if (getLanguage() == language) {
      return false;
    }

    auto filepath = doLanguageToFilepath(language);
    auto translator = std::make_shared<LanguageTranslator>(filepath);
    if (!translator->chkLoadSuccess()) {
      return false;
    }

    installTranslator(translator);
    return true;
  }

  Language LanguageManager::getLanguage() const {
    if (translator_ == nullptr) {
      return Language::Unknow;
    }
    return translator_->getLanguage();
  }

  void LanguageManager::installTranslator(std::shared_ptr<LanguageTranslator> translator) {
    if (translator->chkLoadSuccess() == false) {
      return;
    }
    translator_ = translator;
    updateAllObjectLanguage();
  }

  void LanguageManager::updateAllObjectLanguage() {
    if (translator_ == nullptr) {
      return;
    }
    for (auto pair : object2stateMap_) {
      if (pair.second == ObjectState::Register) {
        updateObjectLanguage(pair.first);
      }
    }
  }

  void LanguageManager::updateObjectLanguage(LanguageObject* object) {
    if (object == nullptr || translator_ == nullptr) {
      return;
    }

    auto tagItor = object2tagMap_.find(object);
    auto setterItor = object2setterMap_.find(object);
    if (setterItor == object2setterMap_.end() || tagItor == object2tagMap_.end()) {
      return;
    }

    auto string = translator_->translate(tagItor->second);
    auto setter = setterItor->second;
    setter(string);
  }

};  // namespace br