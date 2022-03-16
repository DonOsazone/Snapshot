// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SNAPSHOTDEMO_API FPolinomial
{
public:
	FPolinomial();
	FPolinomial(TArray<double> &Content);
	~FPolinomial();

	FPolinomial operator+(const FPolinomial& p);
	FPolinomial operator+(const double p);

	TArray<double> Content;
};

