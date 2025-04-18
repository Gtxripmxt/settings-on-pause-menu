#include <Geode/Geode.hpp>
#include <Geode/modify/EditorPauseLayer.hpp>
#include <Geode/modify/EndLevelLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/utils/cocos.hpp>

using namespace geode::prelude;

class $modify(PauseWithImageButton, PauseLayer) {
public:
    void customSetup() override;
    void onSettingsButton(cocos2d::CCObject*);
};

void PauseWithImageButton::customSetup() {
    PauseLayer::customSetup();

    auto btnSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn02_001.png");

    auto button = CCMenuItemSpriteExtra::create(
        sprite,
        sprite,
        this,
        menu_selector(PauseWithImageButton::onSettingsButton) // whowza
    );

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    button->setPosition({ winSize.width - 40.f, winSize.height / 2 });

    auto menu = cocos2d::CCMenu::create();
    menu->addChild(button);
    menu->setPosition({0, 0});
    this->addChild(menu);
}

void PauseWithImageButton::onSettingsButton(cocos2d::CCObject*) {
        auto options = OptionsLayer::create();
        options->show();
}
