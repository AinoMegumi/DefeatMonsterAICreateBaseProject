#pragma once
#include "Element.hpp"
#include <array>

class DamageManager {
private:
	std::array<float, 8> AllElementAdvantageInfo;
	std::pair<ElementInfo, ElementInfo> CharacterElement;
public:
	DamageManager() = default;
	DamageManager(const std::pair<ElementInfo, ElementInfo> ElementData) : CharacterElement(ElementData) {
		const AdvantageInfo FirstElement(ElementData.first), SecondElement(ElementData.second);
		this->AllElementAdvantageInfo.front() = 1.0f;
		for (size_t i = 1; i < 8; i++) this->AllElementAdvantageInfo[i] = FirstElement.GetAdvantage(static_cast<ElementInfo>(i)) * SecondElement.GetAdvantage(static_cast<ElementInfo>(i));
	}
	float GetCrashAdvantage(const ElementInfo AttackElement) const { return this->AllElementAdvantageInfo[static_cast<size_t>(AttackElement)]; }
	float GetAttackAdvantage(const ElementInfo AttackElement) const { return (this->CharacterElement.first == AttackElement || this->CharacterElement.second == AttackElement) ? 1.3f : 1.0f; }
};
