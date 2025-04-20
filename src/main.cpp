#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/utils/cocos.hpp>
#include <Geode/binding/OptionsLayer.hpp>
#include <Geode/ext/cocos/CCMenuItemSpriteExtra.hpp>

using namespace geode::prelude;

class $modify(PauseWithImageButton, PauseLayer) {
public:
    void customSetup() override;
    void onSettingsButton(cocos2d::CCObject*);
};

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
}

void PauseWithImageButton::onSettingsButton(cocos2d::CCObject*) {
    if (auto* options = OptionsLayer::create()) {
        auto scene = utils::get<cocos2d::CCScene>();
        if (!scene) return;
        auto zOrder = scene->getHighestChildZ();
        scene->addChild(options, zOrder + 1);
        options->showLayer(false);
    }
}
