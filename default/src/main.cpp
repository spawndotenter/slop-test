#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(GrapeMenu, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto spr = CCSprite::create("grape.png"_spr);
        if (!spr) return true;
        spr->setScale(45.f / spr->getContentHeight());

        auto btn = CCMenuItemSpriteExtra::create(
            spr, this, menu_selector(GrapeMenu::onGrape)
        );
        btn->setID("grape-button"_spr);

        if (auto menu = this->getChildByID("bottom-menu")) {
            menu->addChild(btn);
            menu->updateLayout();
        }
        return true;
    }

    void onGrape(CCObject*) {
        FMODAudioEngine::sharedEngine()->playEffect("chestOpen01.ogg", 1.f, 1.f, 1.f);
    }
};
