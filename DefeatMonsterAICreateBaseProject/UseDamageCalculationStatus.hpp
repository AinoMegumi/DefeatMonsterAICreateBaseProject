#pragma once
#include "UseDamageCalculationParameter.hpp"

template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
struct UseDamageCalculationStatus {
	UseDamageCalculationStatus() = default;
	UseDamageCalculationStatus(const T Attack, const T Defence)
		: AttackParam({ Attack, Attack * 3, std::max(Attack - 200, 0) }), DefenceParam({ Defence, Defence + 200, std::max(Defence - 200, 0) }) {}
	UseDamageCalculationParameter<T> AttackParam, DefenceParam;
	T AttackPowerUp(const T AddNum) { return this->AttackParam.PowerUp(AddNum); }
	T AttackPowerDown(const T SubtractNum) { return this->AttackParam.PowerDown(SubtractNum); }
	T DefencePowerUp(const T AddNum) { return this->DefenceParam.PowerUp(AddNum); }
	T DefencePowerDown(const T SubtractNum) { return this->DefenceParam.PowerDown(SubtractNum); }
	void AttackReset() { this->AttackParam.Reset(); }
	void DefenceReset() { this->DefenceParam.Reset(); }
	void LevelUp(const T AttackAddPoint, const T DefenceAddPoint) {
		this->AttackParam.AddToMax(AttackAddPoint);
		this->AttackParam += AttackAddPoint;
		this->AttackParam.AddToMin(AttackAddPoint);
		this->DefenceParam.AddToMax(DefenceAddPoint);
		this->DefenceParam += DefenceAddPoint;
		this->DefenceParam.AddToMin(DefenceAddPoint);
	}
};
