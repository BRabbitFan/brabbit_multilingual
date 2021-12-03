/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:23:37
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 15:57:57
 * @FilePath     : /brabbit_multilingual/src/LanguageManager.hpp
 * @Description  : LanguageManager 语言管理器, 负责实现动态语言文本翻译.
 *                 LanguageObject 可在此注册/注销, 注册过后即可在语言切换时自动更新文本.
 *                 当 LanguageObject 析构时自动注销, 通常情况下无需手动注销.
 */

#ifndef BR_LANGUAGE_MANAGER
#define BR_LANGUAGE_MANAGER

#include <string>
#include <memory>
#include <set>
#include <map>

#include "LanguageTranslator.hpp"
#include "LanguageGlobal.hpp"
#include "LanguageObject.hpp"

namespace br {

  class LanguageManager {
    public:
      static LanguageManager& instance();

    private:
      LanguageManager() = default;
      ~LanguageManager() = default;
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
      std::map<LanguageObject*, ObjectState>    object2stateMap_;
      std::map<LanguageObject*, Tag>            object2tagMap_;
      std::map<LanguageObject*, LanguageSetter> object2setterMap_;

      std::shared_ptr<LanguageTranslator>       translator_;

  };  // class LanguageManager

};  // namespace br

#endif // BR_LANGUAGE_MANAGER