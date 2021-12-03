/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:23:37
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 11:31:10
 * @FilePath     : /brabbit_multilingual/src/LanguageManager.hpp
 * @Description  : 
 */

#ifndef BR_LANGUAGE_MANAGER
#define BR_LANGUAGE_MANAGER

#include <string>
#include <memory>
#include <set>
#include <map>

#include "LanguageGlobal.hpp"
#include "LanguageObject.hpp"
#include "LanguageTranslator.hpp"

namespace br {

  class LanguageManager {
    public:
      static LanguageManager& instance();

    private:
      LanguageManager();
      ~LanguageManager();
      LanguageManager(const LanguageManager&) = delete;
      LanguageManager& operator=(const LanguageManager&) = delete;

    public:
      enum class ObjectState {
        Unregister = 0,
        Register
      };

    public:
      void objectCreated(LanguageObject* object);
      void objectDestoryed(LanguageObject* object);
      
      bool registerObject(LanguageObject* object, Tag tag, LanguageSetter setter);
      bool unregisterObject(LanguageObject* object);
      bool chkRegistered(LanguageObject* object);

      bool setLanguage(Language language);
      Language getLanguage() const;
      void installTranslator(std::shared_ptr<LanguageTranslator> translator);

    private:
      void updateAllObjectLanguage();
      void updateObjectLanguage(LanguageObject* object);

    private:
      std::map<LanguageObject*, ObjectState> objectToState_;
      std::map<LanguageObject*, Tag> objectToTag_;
      std::map<LanguageObject*, LanguageSetter> objectToSetter_;

      std::shared_ptr<LanguageTranslator> translator_;

  };  // class LanguageManager

};  // namespace br

#endif // BR_LANGUAGE_MANAGER