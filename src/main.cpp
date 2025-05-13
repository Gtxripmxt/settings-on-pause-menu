#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/binding/OptionsLayer.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
public:
    void customSetup() {
        PauseLayer::customSetup();

        auto button = CCMenuItemSpriteExtra::create(
	    CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"),
	    this,
	    menu_selector(MyPauseLayer::onSettingsButton)
        );
	auto menu = this->getChildByID("center-button-menu");
	button->setID("settings-button"_spr);
	menu->addChild(button);

	auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
        button->setPosition({ winSize.width - 40.f, winSize.height / 2 });

	menu->updateLayout();
    }
    void onSettingsButton(cocos2d::CCObject*) {
        auto options = OptionsLayer::create();
        if (!options) return;
        auto scene = cocos2d::CCDirector::sharedDirector()->getRunningScene();
        if (!scene) return;
        int zOrder = 1000;
        scene->addChild(options, zOrder);
        options->showLayer(false);	
    }
};
