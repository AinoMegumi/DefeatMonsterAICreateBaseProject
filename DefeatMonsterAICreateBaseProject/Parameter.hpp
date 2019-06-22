#pragma once 
#include "BodyParameterManager.hpp"
#include "UseDamageCalculationStatus.hpp"
#include "SpeedManager.hpp"
#include "DamageManager.hpp"
#include "LevelManager.hpp"
#include "Skill.hpp"

class Parameter {
public:
	Parameter() = default;
	Parameter(const BodyParameter<int>& HP, const BodyParameter<int>& MP, 
		const UseDamageCalculationStatus<int>& PhysicalParam, const UseDamageCalculationStatus<int>& MagicParam,
		const UseDamageCalculationParameter<int>& MCUR, const SpeedManager<int>& SPD, 
		const UseDamageCalculationParameter<int>& CLV, const DamageManager& Dmg)
		: HP(HP), MP(MP), Physical(PhysicalParam), Magic(MagicParam),
		MagicCure(MCUR), Speed(SPD), Cleverness(CLV), Damage(Dmg), AbleToUseAttackMagic(),
		AbleToUseSingleCureMagic(), AbleToUseRangeCureMagic() {}
	BodyParameterManager<int> HP;
	BodyParameterManager<int> MP;
	UseDamageCalculationStatus<int> Physical;
	UseDamageCalculationStatus<int> Magic;
	UseDamageCalculationParameter<int> MagicCure;
	SpeedManager<int> Speed;
	UseDamageCalculationParameter<int> Cleverness;
protected:
	DamageManager Damage;
public:
	std::vector<SkillA> AbleToUseAttackMagic;
	std::vector<SkillA> AbleToUseSingleCureMagic;
	std::vector<SkillA> AbleToUseRangeCureMagic;
};
