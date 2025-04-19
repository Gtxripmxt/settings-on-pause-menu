#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/utils/file.hpp>
#include <Geode/utils/cocos.hpp>
#include <Geode/binding/GJGameLevel.hpp>
#include <Geode/binding/GJGarageLayer.hpp>
#include <Geode/binding/LevelBrowserLayer.hpp>
#include <Geode/binding/GJLocalLevelScore.hpp>

using namespace geode::prelude;

class $modify(LevelBrowserLayerExport, LevelBrowserLayer) {
    bool init(GJSearchObject* search) {
        if (!LevelBrowserLayer::init(search)) return false;

        // Add export button
        auto exportBtn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"),
            this,
            menu_selector(LevelBrowserLayerExport::onExportClicked)
        );

        exportBtn->setPosition({ this->getContentSize().width - 50.f, this->getContentSize().height - 50.f });

        auto menu = this->getChildByIDRecursive<CCMenu>("level-browser-menu");
        if (menu) {
            menu->addChild(exportBtn);
        }

        return true;
    }

    void onExportClicked(CCObject*) {
        if (!m_list) return;

        // Get selected level
        auto cell = static_cast<CustomListView*>(m_list)->getSelectedCell();
        if (!cell) {
            FLAlertLayer::create("Export Error", "No level selected.", "OK")->show();
            return;
        }

        auto level = static_cast<GJGameLevel*>(cell->m_entry);
        if (!level) {
            FLAlertLayer::create("Export Error", "Failed to get level data.", "OK")->show();
            return;
        }

        std::string gmdData = level->m_levelString;
        std::string savePath = Mod::get()->getSaveDir() + "/" + std::to_string(level->m_levelID.value()) + "_" + level->m_levelName + ".gmd";

        if (file::writeStringToFile(gmdData, savePath)) {
            FLAlertLayer::create("Export Successful", "Level exported to mod's save files.", "OK")->show();
        } else {
            FLAlertLayer::create("Export Failed", "Could not write to file.", "OK")->show();
        }
    }
};
