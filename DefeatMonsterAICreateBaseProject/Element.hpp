#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

enum class ElementInfo : size_t { Normal = 0, Fire = 1, Ice = 2, Thunder = 3, Earth = 4, Wind = 5, Shine = 6, Dark = 7 };

class AdvantageInfo {
private:
	std::vector<ElementInfo> WeakElement;
	std::vector<ElementInfo> BeautyElement;
public:
	AdvantageInfo(const ElementInfo Element) {
		switch (Element) {
			case ElementInfo::Normal:
				break;
			case ElementInfo::Fire:
				this->WeakElement = { ElementInfo::Ice, ElementInfo::Earth };
				this->BeautyElement = { ElementInfo::Fire, ElementInfo::Thunder, ElementInfo::Wind };
				break;
			case ElementInfo::Ice:
				this->WeakElement = { ElementInfo::Thunder, ElementInfo::Wind };
				this->BeautyElement = { ElementInfo::Fire, ElementInfo::Ice, ElementInfo::Earth };
				break;
			case ElementInfo::Thunder:
				this->WeakElement = { ElementInfo::Fire, ElementInfo::Earth };
				this->BeautyElement = { ElementInfo::Ice, ElementInfo::Thunder, ElementInfo::Wind };
				break;
			case ElementInfo::Earth:
				this->WeakElement = { ElementInfo::Ice, ElementInfo::Wind };
				this->BeautyElement = { ElementInfo::Fire, ElementInfo::Thunder, ElementInfo::Earth };
				break;
			case ElementInfo::Wind:
				this->WeakElement = { ElementInfo::Fire, ElementInfo::Thunder };
				this->BeautyElement = { ElementInfo::Ice, ElementInfo::Earth, ElementInfo::Wind };
				break;
			case ElementInfo::Shine:
				this->WeakElement = { ElementInfo::Dark };
				this->BeautyElement = { ElementInfo::Shine };
				break;
			case ElementInfo::Dark:
				this->WeakElement = { ElementInfo::Shine };
				this->BeautyElement = { ElementInfo::Dark };
				break;
			default:
				throw std::runtime_error("入力された属性はこのクラスでは相性判定できません。");
		 }
	}
	// 引数：攻撃属性
	// 戻り値　：ダメージ倍率
	float GetAdvantage(const ElementInfo AttackElement) const {
		return this->IsWeakElement(AttackElement) ? 2.0f : (this->IsBeautyElement(AttackElement) ? 0.5f : 1.0f);
	}
	// 引数：攻撃属性
	bool IsWeakElement(const ElementInfo AttackElement) const {
		if (this->WeakElement.empty()) return false;
		return std::any_of(this->WeakElement.begin(), this->WeakElement.end(), [AttackElement](const ElementInfo Elem) { return AttackElement == Elem; });
	}
	// 引数：攻撃属性
	bool IsBeautyElement(const ElementInfo AttackElement) const {
		if (this->BeautyElement.empty()) return false;
		return std::any_of(this->BeautyElement.begin(), this->BeautyElement.end(), [AttackElement](const ElementInfo Elem) { return AttackElement == Elem; });
	}
};

class Element {
public:
	static ElementInfo ElementCast(const std::string Element) noexcept {
		// ユーザーが属性を自由に追加できるようにstd::vectorクラスにしてあるだけ
		static const std::vector<std::string> ElementList = { "normal", "fire", "ice", "thunder", "earth", "wind", "shine", "dark" };
		for (size_t i = 0; i < ElementList.size(); i++) if (Element == ElementList[i]) return static_cast<ElementInfo>(i);
		return ElementInfo::Normal;
	}
	static ElementInfo ElementCast(const std::wstring Element) noexcept {
		static const std::vector<std::wstring> ElementList = { L"normal", L"ice", L"thunder", L"earth", L"wind", L"shine", L"dark" };
		for (size_t i = 0; i < ElementList.size(); i++) if (Element == ElementList[i]) return static_cast<ElementInfo>(i);
		return ElementInfo::Normal;
	}
	Element() : Element(ElementInfo::Normal) {}
	Element(const ElementInfo Elem) : Elem(Elem) {}
	Element(const std::string Elem) : Element(ElementCast(Elem)) {}
	Element(const std::wstring Elem) : Element(ElementCast(Elem)) {}
	ElementInfo Elem;
	float Advantage(const ElementInfo AttackElement) const {
		return (this->Elem == ElementInfo::Normal || AttackElement == ElementInfo::Normal)
			? 1.0f : AdvantageInfo(this->Elem).GetAdvantage(AttackElement);
	}
};
