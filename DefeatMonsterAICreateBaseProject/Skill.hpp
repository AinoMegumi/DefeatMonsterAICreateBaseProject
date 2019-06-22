#pragma once
#include "Element.hpp"

struct SkillA {
	SkillA() = default;
	SkillA(const std::string Name, const std::string Tag, int UseMP, const int BasePower, const std::string Description, const ElementInfo SkillElement, 
		const std::string EffectGraphPath, const std::string EffectSoundPath, const bool Range, const bool ResurrectionEffect, const int SkillType, const int LessMP, const int AddBlendLevel)
		: Name(Name), Tag(Tag), UseMP(UseMP), BasePower(BasePower), Description(Description), SkillElement(SkillElement), EffectGraphPath(EffectGraphPath), 
		EffectSoundPath(EffectSoundPath), Range(Range), ResurrectionEffect(ResurrectionEffect), SkillType(SkillType), LessMP(LessMP), AddBlendLevel(AddBlendLevel) {}
	std::string Name;			// 名前
	std::string Tag;			// 識別タグ
	int UseMP;					// 消費MP
	int BasePower;				// 基本攻撃力
	std::string Description;	// 説明
	ElementInfo SkillElement;	// 属性(enum class値)
	std::string EffectGraphPath;// エフェクト画像のパス
	std::string EffectSoundPath;// エフェクトのサウンドパス
	bool Range;					// 範囲効果フラグ
	bool ResurrectionEffect;	// 復活効果の有無
	int SkillType;				// スキル種別(0:攻撃　1:回復　2:範囲回復)
	int LessMP;					// 最低限必要なMP
	int AddBlendLevel;			// 加算ブレンドのレベル
	bool operator == (const SkillA s) const {
		return this->Name == s.Name && this->UseMP == s.UseMP && this->BasePower == s.BasePower && this->Description == s.Description && this->SkillElement == s.SkillElement;
	}
	bool operator != (const SkillA s) const { return !this->operator==(s); }
};

struct SkillW {
	SkillW() = default;
	SkillW(const std::wstring Name, const std::wstring Tag, int UseMP, const int BasePower, const std::wstring Description, const ElementInfo SkillElement,
		const std::wstring EffectGraphPath, const std::wstring EffectSoundPath, const bool Range, const bool ResurrectionEffect, const int SkillType, const int LessMP, const int AddBlendLevel)
		: Name(Name), Tag(Tag), UseMP(UseMP), BasePower(BasePower), Description(Description), SkillElement(SkillElement), EffectGraphPath(EffectGraphPath),
		EffectSoundPath(EffectSoundPath), Range(Range), ResurrectionEffect(ResurrectionEffect), SkillType(SkillType), LessMP(LessMP), AddBlendLevel(AddBlendLevel) {}
	std::wstring Name;			 // 名前
	std::wstring Tag;			 // 識別タグ
	int UseMP;					 // 消費MP
	int BasePower;				 // 基本攻撃力
	std::wstring Description;	 // 説明
	ElementInfo SkillElement;	 // 属性(enum class値)
	std::wstring EffectGraphPath;// エフェクト画像のパス
	std::wstring EffectSoundPath;// エフェクトのサウンドパス
	bool Range;					 // 範囲効果フラグ
	bool ResurrectionEffect;	 // 復活効果の有無
	int SkillType;				 // スキル種別(0:攻撃　1:回復　2:範囲回復)
	int LessMP;					 // 最低限必要なMP
	int AddBlendLevel;			 // 加算ブレンドのレベル
	bool operator == (const SkillW s) const {
		return this->Name == s.Name && this->UseMP == s.UseMP && this->BasePower == s.BasePower && this->Description == s.Description && this->SkillElement == s.SkillElement;
	}
};

#if defined(UNICODE)
typedef SkillW Skill;
#else
typedef SkillA Skill;
#endif
