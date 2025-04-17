#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/utils/cocos.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
    bool init(bool idk) {
        if (!PauseLayer::init(idk)) return false;

        // Create the button
        auto btn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Options", 0, false, "goldFont.fnt", "GJ_button_01.png", 40.0f, 1.0f),
            this,
            menu_selector(MyPauseLayer::onOptionsButton)
        );

        // Position on the right side
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        btn->setPosition({winSize.width - 50.0f, winSize.height / 2});

        auto menu = CCMenu::create();
        menu->addChild(btn);
        menu->setPosition(CCPointZero);
        this->addChild(menu);

        return true;
    }

    void onOptionsButton(CCObject*) {
        auto optionsLayer = OptionsLayer::create();
        CCDirector::sharedDirector()->getRunningScene()->addChild(optionsLayer, 1000);
    }
};
