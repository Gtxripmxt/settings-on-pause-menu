#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/utils/cocos.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
    void onEnter() {
        PauseLayer::onEnter(); // call base method first

        // Create the button
        auto btn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Options", 0, false, "goldFont.fnt", "GJ_button_01.png", 40.0f, 1.0f),
            this,
            menu_selector(MyPauseLayer::onOptionsButton)
        );

        // Position it on the right side of the screen
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        btn->setPosition({winSize.width - 60.0f, winSize.height / 2});

        // Add it to a new menu
        auto menu = CCMenu::create();
        menu->addChild(btn);
        menu->setPosition(CCPointZero);
        this->addChild(menu);
    }

    void onOptionsButton(CCObject*) {
        auto optionsLayer = OptionsLayer::create();
        CCDirector::sharedDirector()->getRunningScene()->addChild(optionsLayer, 1000);
    }
};
