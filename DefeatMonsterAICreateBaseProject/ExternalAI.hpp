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
		virtual SkillA command(const std::array<Parameter, 4>& CurrentParameter) noexcept = 0;
		virtual size_t GetCureTarget() noexcept = 0;
		size_t GetTarget() noexcept { return this->GetCureTarget(); }
	};
#else
	class ExternalEnemyAI {
	public:
		virtual SkillA command(const std::array<Parameter, 4>& CurrentParameter) noexcept = 0;
		virtual size_t GetAttackTarget() noexcept = 0;
		size_t GetTarget() noexcept { return this->GetAttackTarget(); }
	};
#endif
}

namespace Online {
#ifdef MAKE_PARTNER_AI
	class ExternalPartnerAI {
		virtual SkillA command(const std::array<Parameter, 5>& CurrentParameter) noexcept = 0;
		virtual size_t GetCureTarget() noexcept = 0;
		size_t GetTarget() noexcept { return this->GetCureTarget(); }
	};
#else
	class ExternalEnemyAI {
	public:
		virtual SkillA command(const std::array<Parameter, 5>& CurrentParameter) noexcept = 0;
		virtual size_t GetAttackTarget() noexcept = 0;
		size_t GetTarget() noexcept { return this->GetAttackTarget(); }
	};
#endif
}
