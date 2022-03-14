// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include<vector>

/**
 * 
 */
class SNAPSHOTDEMO_API Polinomial
{
public:
	Polinomial();
	~Polinomial();

	Polinomial operator+(const Polinomial& p);

	std::vector<int> content;
};

