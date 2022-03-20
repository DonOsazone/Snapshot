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
	FPolinomial(TArray<FFraction> &Content);
	~FPolinomial();
	
	TArray<FFraction> Content;
	
	FPolinomial		operator+(const FPolinomial& Polinomial) const;
	FPolinomial		operator+(const FFraction& Fraction) const;
	FPolinomial		operator+(const int32 Integer) const;
	FPolinomial&	operator+=(const FPolinomial& Polinomial);
	FPolinomial&	operator+=(const FFraction& Fraction);
	FPolinomial&	operator+=(const int32 Integer);

	FPolinomial		operator-(const FPolinomial& Polinomial) const;
	FPolinomial		operator-(const FFraction& Fraction) const;
	FPolinomial		operator-(const int32 Integer) const;
	FPolinomial&	operator-=(const FPolinomial& Polinomial);
	FPolinomial&	operator-=(const FFraction& Fraction);
	FPolinomial&	operator-=(const int32 Integer);

	FPolinomial		operator*(const FPolinomial& Polinomial) const;
	FPolinomial		operator*(const FFraction& Fraction) const;
	FPolinomial		operator*(const int32 Integer) const;
	FPolinomial&	operator*=(const FPolinomial& Polinomial);
	FPolinomial&	operator*=(const FFraction& Fraction);
	FPolinomial&	operator*=(const int32 Integer);

	FPolinomial		operator/(const FPolinomial& Polinomial) const;
	FPolinomial		operator/(const FFraction& Fraction) const;
	FPolinomial		operator/(const int32 Integer) const;
	FPolinomial&	operator/=(const FPolinomial& Polinomial);
	FPolinomial&	operator/=(const FFraction& Fraction);
	FPolinomial&	operator/=(const int32 Integer);

	bool			operator == (const FPolinomial& Polinomial) const;
	bool			operator == (const FFraction& Fraction) const;
	bool			operator == (const int32 Integer)const;

	
};



