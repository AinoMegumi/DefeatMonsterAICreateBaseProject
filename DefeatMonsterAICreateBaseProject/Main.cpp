//#define SAMPLE_BUILD
//#define MAKE_PARTNER_AI
#include "ExternalAI.hpp"

#ifdef SAMPLE_BUILD
#ifdef MAKE_PARTNER_AI
class OfflinePartnerAI : public Offline::ExternalPartnerAI {
private:
	size_t ID;
	AIBattleStyle Style;
public:
	OfflinePartnerAI(const size_t SelfID, const AIBattleStyle& BattleStyle)
		: ID(SelfID), Style(BattleStyle) {}
	SkillA command(const std::array<Parameter, 4>&) noexcept override {
		SkillA attack{};
		attack.Tag = "amnormal";
		return attack;
	}
	size_t GetCureTarget() noexcept override {
		return 0;
	}
};

class OnlinePartnerAI : public Online::ExternalPartnerAI {
private:
	size_t ID;
	AIBattleStyle Style;
public:
	OnlinePartnerAI(const size_t SelfID, const AIBattleStyle& BattleStyle)
		: ID(SelfID), Style(BattleStyle) {}
	SkillA command(const std::array<Parameter, 5>&) override {
		SkillA attack{};
		attack.Tag = "amnormal";
		return attack;
	}
	size_t GetCureTarget() noexcept override {
		return 0;
	}
};
#else
class OfflineEnemyAI : public Offline::ExternalEnemyAI {
public:
	SkillA command(const std::array<Parameter, 4>&) noexcept override {
		SkillA attack{};
		attack.Tag = "amnormal";
		return attack;
	}
	size_t GetAttackTarget() noexcept override {
		return 0;
	}
};


class OnlineEnemyAI : public Online::ExternalEnemyAI {
public:
	SkillA command(const std::array<Parameter, 5>&) noexcept override {
		SkillA attack{};
		attack.Tag = "amnormal";
		return attack;
	}
	size_t GetAttackTarget() noexcept override {
		return 0;
	}
};
#endif
#endif

#ifdef SAMPLE_BUILD
#ifdef MAKE_PARTNER_AI
__declspec(dllexport) Offline::ExternalPartnerAI* GetOfflineExternalAI(const size_t SelfID, const AIBattleStyle& BattleStyle) {
	return new OfflinePartnerAI(SelfID, BattleStyle);
}

__declspec(dllexport) Online::ExternalPartnerAI* GetOnlineExternalAI(const size_t SelfID, const AIBattleStyle& BattleStyle) {
	return new OnlinePartnerAI(SelfID, BattleStyle);
}
#else
__declspec(dllexport) Offline::ExternalEnemyAI* GetOfflineExternalAI() {
	return new OfflineEnemyAI();
}

__declspec(dllexport) Online::ExternalEnemyAI* GetOnlineExternalAI() {
	return new OnlineEnemyAI();
}
#endif
#else
#ifdef MAKE_PARTNER_AI
__declspec(dllexport) Offline::ExternalPartnerAI* GetOfflineExternalAI(const size_t SelfID, const AIBattleStyle& BattleStyle) {
	
}

__declspec(dllexport) Online::ExternalPartnerAI* GetOnlineExternalAI(const size_t SelfID, const AIBattleStyle& BattleStyle) {
	
}
#else
__declspec(dllexport) Offline::ExternalEnemyAI* GetOfflineExternalAI() {
	
}

__declspec(dllexport) Online::ExternalEnemyAI* GetOnlineExternalAI() {
	
}
#endif
#endif
