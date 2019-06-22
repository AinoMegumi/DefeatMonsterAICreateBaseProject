#pragma once
#include "BodyParameter.hpp"

template<typename T, std::enable_if_t<std::is_integral<T>::value && std::is_signed<T>::value, std::nullptr_t> = nullptr>
class BodyParameterManager : public BodyParameter<T> {
private:
	T NotApplyDamageToGraph;
	T ApplySpeed;
public:
	BodyParameterManager() = default;
	//BodyParameterManager(const PossibleChangeStatusArrange<T> StartParam) : BodyParameterManager(StartParam, StartParam) {}
	BodyParameterManager(const PossibleChangeStatusArrange<T> Real, const PossibleChangeStatusArrange<T> Graph)
		: BodyParameter<T>(Real, Graph), NotApplyDamageToGraph(*Graph - *Real), ApplySpeed(0) {}
	BodyParameterManager(const BodyParameter<T>& Param)
		: BodyParameterManager(Param.RealParameter, Param.GraphParameter) {}
	bool IsMin() const noexcept { return this->RealParameter.IsMin(); }
	bool IsMax() const noexcept { return this->RealParameter.IsMax(); }
	BodyParameterManager& operator += (const T AddPoint) {
		this->RealParameter += AddPoint;
		return *this;
	}
	BodyParameterManager& operator -= (const T SubtractPoint) {
		this->RealParameter -= SubtractPoint;
		return *this;
	}
	void ApplyDamage() {
		this->NotApplyDamageToGraph = this->GraphParameter.Get() - this->RealParameter.Get();
		if (this->NotApplyDamageToGraph == 0) return;
		else if (this->NotApplyDamageToGraph > 0) this->ApplySpeed = std::max(std::max(1, this->NotApplyDamageToGraph / 20), this->ApplySpeed);
		else this->ApplySpeed = std::min(std::min(-1, this->NotApplyDamageToGraph / 20), this->ApplySpeed);
		this->GraphParameter -= this->ApplySpeed;
		this->NotApplyDamageToGraph -= this->ApplySpeed;
		this->ApplySpeed = 0;
	}
	void SpeedApply() {
		this->GraphParameter = this->RealParameter;
		this->NotApplyDamageToGraph = 0;
	}
	void Refresh() {
		this->RealParameter += this->RealParameter.GetMax() - this->RealParameter.Get();
		this->GraphParameter -= this->GraphParameter.Get() - this->GraphParameter.GetMin();
	}
};
