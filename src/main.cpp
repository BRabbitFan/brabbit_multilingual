/*
 * @Author       : BRabbitFan
 * @Date         : 2021-12-02 14:22:47
 * @LastEditer   : BRabbitFan
 * @LastEditTime : 2021-12-03 15:56:21
 * @FilePath     : /brabbit_multilingual/src/main.cpp
 * @Description  : 多语言机制测试程序.
 */

#include <iostream>
#include <memory>

#include "LanguageManager.hpp"
#include "LanguageObject.hpp"
#include "LanguageTag.hpp"

class BRabbitUIWidget {};  // class BRabbitUIWidget

class BRabbitUILabel : public BRabbitUIWidget, public br::LanguageObject {
  public:
    std::string labelText_;
};  // class BRabbitUILabel

int main(int argc, char* argv[]) {
  auto& manager = br::LanguageManager::instance();
  
  auto* labelA = new BRabbitUILabel;
  auto* labelB = new BRabbitUILabel;
  br::LanguageSetter labelASetter = [labelA](std::string text) { labelA->labelText_ = text; };
  br::LanguageSetter labelBSetter = [labelB](std::string text) { labelB->labelText_ = text; };
  manager.registerObject(labelA, br::LanguageTag::Year, labelASetter);
  manager.registerObject(labelB, br::LanguageTag::One, labelBSetter);

  manager.setLanguage(br::Language::zh_CN);

  std::cout << labelA->labelText_ << std::endl;
  std::cout << labelB->labelText_ << std::endl;

  manager.setLanguage(br::Language::en_US);

  delete labelA;
  std::cout << labelB->labelText_ << std::endl;

  return 0;
}