// Fill out your copyright notice in the Description page of Project Settings.


#include "FPolinomial.h"

FPolinomial::FPolinomial()
{
	this->Content = TArray<double>({0});
}

FPolinomial::FPolinomial(TArray<double>& Content)
{
	this->Content = Content;
}

FPolinomial::~FPolinomial()
{
}


FPolinomial FPolinomial::operator+ (const FPolinomial& p) {
	int32 SelfLength = this->Content.Num();
	int32 OtherLength = p.Content.Num();
	int32 MaxLength = (SelfLength > OtherLength? SelfLength:OtherLength);

	TArray<double> TempResult;
	for (int32 i = 0; i != MaxLength; i++) {
		TempResult.Add(
			(i >= SelfLength ? 0 : this->Content[i])
			+
			(i >= OtherLength ? 0 : p.Content[i])
		);
	}

	return FPolinomial(TempResult);
}

FPolinomial FPolinomial::operator+(const double p)
{
	TArray<double> TempResult = this->Content;
	TempResult[0] += p;
	return FPolinomial(TempResult);
}
