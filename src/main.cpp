#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/utils/cocos.hpp>
#include <Geode/binding/OptionsLayer.hpp>

using namespace geode::prelude;

class $modify(PauseWithImageButton, PauseLayer) {
public:
    void customSetup() override;
    void onSettingsButton(cocos2d::CCObject*);

void PauseWithImageButton::customSetup() {
    PauseLayer::customSetup();

    auto sprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
    if (!sprite) return;

    auto button = CCMenuItemSpriteExtra::create(
        sprite,
        sprite,
        this,
        menu_selector(PauseWithImageButton::onSettingsButton)
    );

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    button->setPosition({ winSize.width - 40.f, winSize.height / 2 });

    auto menu = cocos2d::CCMenu::create();
    menu->addChild(button);
    menu->setPosition({ 0, 0 });

    this->addChild(menu);
};

void PauseWithImageButton::onSettingsButton(cocos2d::CCObject*) {
       auto options = OptionsLayer::create();
    if (!options) return;
    auto scene = cocos2d::CCDirector::sharedDirector()->getRunningScene();
    if (!scene) return;
    int zOrder = 1000;
    scene->addChild(options, zOrder);
    options->showLayer(false);
    }
};

