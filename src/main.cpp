#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/binding/OptionsLayer.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
public:
    void customSetup() {
        PauseLayer::customSetup();

        auto button = CCMenuItemSpriteExtra::create(
	    CCSprite::createWithSpriteFrameName("GJ_infoBtn_001.png"),
	    this,
	    menu_selector(MyPauseLayer::onSettingsButton)
        );
	auto menu = this->getChildByID("center-button-menu");
	button->setID("settings-button"_spr);
	menu->addChild(button);

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
