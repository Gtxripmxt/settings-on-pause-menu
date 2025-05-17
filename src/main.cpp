#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
public:
    void customSetup() {
        PauseLayer::customSetup();
	
        auto winSize = CCDirector::sharedDirector()->getWinSize();
	
        auto button = CCMenuItemSpriteExtra::create(
	    CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"),
	    this,
	    menu_selector(MyPauseLayer::onSettingsButton)
        );
        auto menu = cocos2d::CCMenu::create();
        menu->addChild(button);
        menu->setPosition({ 0, 0 });

    }
    void onSettingsButton(cocos2d::CCObject*) {
        auto options = OptionsLayer::create();
        if (!options) return;
        auto scene = cocos2d::CCDirector::sharedDirector()->getRunningScene();
        scene->addChild(options, 1000);
        options->showLayer(false);	
    }
};
