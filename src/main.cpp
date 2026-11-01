using namespace geode::prelude;

#include <Geode/modify/DailyLevelPage.hpp>
class $modify(CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init()) return false;

		GameManager::get()->m_dailyID = 0;
		GameManager::get()->m_weeklyID = 0;
		GameManager::get()->m_eventID = 0;

        return true;
    }

    void onEnter() {
        CreatorLayer::onEnter();
    }
};

#include <Geode/modify/DailyLevelPage.hpp>
class $modify(DailyLevelPage) {
    struct Fields {
        float m_refreshTimer = 0.f;
    };

    bool init(GJTimedLevelType type) {
        if (!DailyLevelPage::init(type)) return false;

        this->tryGetDailyStatus();
        m_fields->m_refreshTimer = 0.f;

        return true;
    }

    void updateTimers(float dt) {
        DailyLevelPage::updateTimers(dt);

        m_fields->m_refreshTimer += dt;
        if (m_fields->m_refreshTimer >= 30.f) {
            m_fields->m_refreshTimer = 0.f;
            this->tryGetDailyStatus();
        }
    }
};