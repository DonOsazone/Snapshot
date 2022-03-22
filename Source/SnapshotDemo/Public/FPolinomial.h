// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FFraction.h"
#include "CoreMinimal.h"

/**
 * 
 */
class SNAPSHOTDEMO_API FPolinomial
{
public:
	FPolinomial();
	FPolinomial(const TArray<FFraction> &Content);
	FPolinomial(const TArray<FFraction>& NegativeContent, const TArray<FFraction>& PositiveContent);
	~FPolinomial();
	
	/**
	 * @brief 多项式（正数域和零）
	 */
	TArray<FFraction> PositiveContent;
	/**
	 * @brief 多项式（负数域）
	 */
	TArray<FFraction> NegativeContent;


	inline int32 PositiveLimit() const;
	inline int32 NegativeLimit() const;

	FPolinomial			operator+ (const FFraction& Fraction) const;
	FPolinomial			operator+ (const FPolinomial& Polinomial) const;
	FPolinomial			operator+ (const int32 Integer) const;
	FPolinomial&		operator+=(const FPolinomial& Polinomial);
	FPolinomial&		operator+=(const FFraction& Fraction);
	FPolinomial&		operator+=(const int32 Integer);
	
	FPolinomial			operator- (const FPolinomial& Polinomial) const;
	FPolinomial			operator- (const FFraction& Fraction) const;
	FPolinomial			operator- (const int32 Integer) const;
	FPolinomial&		operator-=(const FPolinomial& Polinomial);
	FPolinomial&		operator-=(const FFraction& Fraction);
	FPolinomial&		operator-=(const int32 Integer);
	
	FPolinomial			operator* (const FPolinomial& Polinomial) const;
	FPolinomial			operator* (const FFraction& Fraction) const;
	FPolinomial			operator* (const int32 Integer) const;
	FPolinomial&		operator*=(const FPolinomial& Polinomial);
	FPolinomial&		operator*=(const FFraction& Fraction);
	FPolinomial&		operator*=(const int32 Integer);
	
	FPolinomial			operator/ (const FPolinomial& Polinomial) const;
	FPolinomial			operator/ (const FFraction& Fraction) const;
	FPolinomial			operator/ (const int32 Integer) const;
	FPolinomial&		operator/=(const FPolinomial& Polinomial);
	FPolinomial&		operator/=(const FFraction& Fraction);
	FPolinomial&		operator/=(const int32 Integer);
	
	FFraction&			operator[](const int32 Index);
	const FFraction&	operator[](const int32 Index) const;
	
	bool				operator==(const FPolinomial& Polinomial) const;
	bool				operator==(const FFraction& Fraction) const;
	bool				operator==(const int32 Integer)const;
	
	
};



