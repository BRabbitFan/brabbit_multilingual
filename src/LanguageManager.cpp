/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:23:45
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 14:15:02
 * @FilePath     : /brabbit_multilingual/src/LanguageManager.cpp
 * @Description  : 
 */

#include "LanguageManager.hpp"

namespace br {

  LanguageManager& LanguageManager::instance() {
    static LanguageManager instance;
    return instance;
  }

  LanguageManager::LanguageManager() {}

  LanguageManager::~LanguageManager() {}

  void LanguageManager::objectCreated(LanguageObject* object) {
    std::cout << "objectCreated" << std::endl;
    if (object == nullptr) {
      return;
    }
    objectToState_[object] = ObjectState::Unregister;
  }

  void LanguageManager::objectDestoryed(LanguageObject* object) {
    std::cout << "objectDestoryed" << std::endl;
    if (object == nullptr) {
      return;
    }
    objectToState_.erase(object);
    objectToTag_.erase(object);
    objectToSetter_.erase(object);
  }

  bool LanguageManager::registerObject(LanguageObject* object, Tag tag, LanguageSetter setter) {
    if (object == nullptr) {
      return false;
    }
    objectToState_[object] = ObjectState::Register;
    objectToTag_[object] = tag;
    objectToSetter_[object] = setter;
    updateObjectLanguage(object);
    return true;
  }

  bool LanguageManager::unregisterObject(LanguageObject* object) {
    if (object == nullptr) {
      return false;
    }
    
    auto itor = objectToState_.find(object);
    if (itor == objectToState_.end() || itor->second == ObjectState::Unregister) {
      return false;
    }
    
    objectToTag_.erase(object);
    objectToSetter_.erase(object);
    return true;
  }

  bool LanguageManager::chkRegistered(LanguageObject* object) {
    if (object == nullptr) {
      return false;
    }
    auto itor = objectToState_.find(object);
    if (itor == objectToState_.end()) {
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
    for (auto pair : objectToState_) {
      if (pair.second == ObjectState::Register) {
        updateObjectLanguage(pair.first);
      }
    }
  }

  void LanguageManager::updateObjectLanguage(LanguageObject* object) {
    if (object == nullptr || translator_ == nullptr) {
      return;
    }

    auto tagItor = objectToTag_.find(object);
    auto setterItor = objectToSetter_.find(object);
    if (setterItor == objectToSetter_.end() || tagItor == objectToTag_.end()) {
      return;
    }

    auto string = translator_->translate(tagItor->second);
    auto setter = setterItor->second;
    setter(string);
  }

};  // namespace br