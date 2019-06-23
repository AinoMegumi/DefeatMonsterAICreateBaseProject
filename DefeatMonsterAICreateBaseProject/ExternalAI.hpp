#pragma once
#include "Parameter.hpp"
#include <array>

#ifdef MAKE_PARTNER_AI
enum class AIBattleStyle : unsigned int { AttackMain = 0, Balance = 1, CureMain = 2 };
#endif

namespace Offline {
#ifdef MAKE_PARTNER_AI
	class ExternalPartnerAI {
	public:
		virtual SkillA command(const std::array<Parameter, 4>& CurrentParameter, std::mt19937& RandEngine) noexcept = 0;
		virtual size_t GetCureTarget(std::mt19937& RandEngine) noexcept = 0;
		size_t GetTarget(std::mt19937& RandEngine) noexcept { return this->GetCureTarget(RandEngine); }
	};
#else
	class ExternalEnemyAI {
	public:
		virtual SkillA command(const std::array<Parameter, 4>& CurrentParameter, std::mt19937& RandEngine) noexcept = 0;
		virtual size_t GetAttackTarget(std::mt19937& RandEngine) noexcept = 0;
		size_t GetTarget(std::mt19937& RandEngine) noexcept { return this->GetAttackTarget(RandEngine); }
	};
#endif
}

namespace Online {
#ifdef MAKE_PARTNER_AI
	class ExternalPartnerAI {
		virtual SkillA command(const std::array<Parameter, 5>& CurrentParameter, std::mt19937& RandEngine) noexcept = 0;
		virtual size_t GetCureTarget(std::mt19937& RandEngine) noexcept = 0;
		size_t GetTarget(std::mt19937& RandEngine) noexcept { return this->GetCureTarget(RandEngine); }
	};
#else
	class ExternalEnemyAI {
	public:
		virtual SkillA command(const std::array<Parameter, 5>& CurrentParameter, std::mt19937& RandEngine) noexcept = 0;
		virtual size_t GetAttackTarget(std::mt19937& RandEngine) noexcept = 0;
		size_t GetTarget(std::mt19937& RandEngine) noexcept { return this->GetAttackTarget(RandEngine); }
	};
#endif
}
