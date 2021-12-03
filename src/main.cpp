/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:22:47
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 11:46:01
 * @FilePath     : /brabbit_multilingual/src/main.cpp
 * @Description  : main
 */

#include <iostream>
#include <memory>

#include "LanguageTranslator.hpp"
#include "LanguageManager.hpp"
#include "LanguageObject.hpp"
#include "LanguageTag.hpp"

class BRabbitUIWidget {};

class BRabbitUILabel : public BRabbitUIWidget, public br::LanguageObject {
  public:
    std::string labelText_;
};

int main(int argc, char* argv[]) {
  auto& manager = br::LanguageManager::instance();
  auto* label = new BRabbitUILabel;
  auto translator = std::make_shared<br::LanguageTranslator>;

  br::LanguageSetter labelSetter = [label](std::string text) {
    label->labelText_ = text;
  };
  manager.registerObject(dynamic_cast<br::LanguageObject*>(label), br::LanguageTag::Year, labelSetter);

  translator->load(argv[1]);
  br::LanguageManager::instance().installTranslator(translator);
  return 0;  
}