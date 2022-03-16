// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
struct SNAPSHOTDEMO_API FFraction
{
	uint32 Integer;
	uint32 Numerator;
	uint32 Denominator;

	bool bIsPositiveOrZero;

	FFraction();
	FFraction(const int32 Integer);
	FFraction(const int32 Numerator, const int32 Denominator);
	FFraction(const int32 Integer, const int32 Numerator, const int32 Denominator);

	FFraction operator+ (const int32 p);
	FFraction operator+ (const FFraction& fract);
	FFraction operator+=(const int32 p);
	FFraction operator+=(const FFraction& fract);

	FFraction operator- (const int32 p);
	FFraction operator- (const FFraction& fract);
	FFraction operator-=(const int32 p);
	FFraction operator-=(const FFraction& fract);

	FFraction operator* (const int32 p);
	FFraction operator* (const FFraction& fract);
	FFraction operator*=(const int32 p);
	FFraction operator*=(const FFraction& fract);

	FFraction operator/ (const int32 p);
	FFraction operator/ (const FFraction& fract);
	FFraction operator/=(const int32 p);
	FFraction operator/=(const FFraction& fract);

	FFraction operator= (const int32 p);
	FFraction operator= (const FFraction& fract);

	FFraction operator- ();

	FFraction operator< (const int32 p);
	FFraction operator< (const FFraction& fract);

	FFraction operator<=(const int32 p);
	FFraction operator<=(const FFraction& fract);

	FFraction operator> (const int32 p);
	FFraction operator> (const FFraction& fract);

	FFraction operator>=(const int32 p);
	FFraction operator>=(const FFraction& fract);

	FFraction operator==(const int32 p);
	FFraction operator==(const FFraction& fract);


	~FFraction();
};

