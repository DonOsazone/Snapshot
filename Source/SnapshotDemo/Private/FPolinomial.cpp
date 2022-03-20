// Fill out your copyright notice in the Description page of Project Settings.


#include "FPolinomial.h"

void HighZeroRemove(TArray<FFraction>& PolinomialContent)
{
	for (int32 i = PolinomialContent.Num();i>0;i++)
	{
		if(PolinomialContent[i] == 0)
		{
			PolinomialContent.RemoveAt(i);
		}else
		{
			return;
		}
	}
}


FPolinomial::FPolinomial()
{
	this->Content = TArray<FFraction>({FFraction(0)});
}

FPolinomial::FPolinomial(TArray<FFraction>& Content)
{
	this->Content = Content;
}

FPolinomial::~FPolinomial()
{
}


FPolinomial FPolinomial::operator+(const FPolinomial& Polinomial) const
{
	const int32 SelfLength = this->Content.Num();
	const int32 OtherLength = Polinomial.Content.Num();
	const int32 MaxLength = (SelfLength > OtherLength ? SelfLength : OtherLength);

	TArray<FFraction> TempResult;
	for (int32 i = 0; i != MaxLength; i++)
	{
		TempResult.Add(
			(i >= SelfLength ? 0 : this->Content[i])
			+
			(i >= OtherLength ? 0 : Polinomial.Content[i])
		);
	}

	return FPolinomial(TempResult);
}

FPolinomial FPolinomial::operator+(const FFraction& Fraction) const
{
	TArray<FFraction> TempResult = this->Content;
	TempResult[0] += Fraction;

	return FPolinomial(TempResult);
}

FPolinomial FPolinomial::operator+(const int32 Integer) const
{
	TArray<FFraction> TempResult = this->Content;
	TempResult[0] += Integer;

	return FPolinomial(TempResult);
}

FPolinomial& FPolinomial::operator+=(const FPolinomial& Polinomial)
{
	const int32 SelfLength = this->Content.Num();
	const int32 OtherLength = Polinomial.Content.Num();
	const int32 MaxLength = (SelfLength > OtherLength ? SelfLength : OtherLength);

	for (int32 i = 0; i != MaxLength; i++)
	{
		this->Content[i] += i >= OtherLength ? 0 : Polinomial.Content[i];
	}
	return *this;
}

FPolinomial& FPolinomial::operator+=(const FFraction& Fraction)
{
	this->Content[0] += Fraction;
	return *this;
}

FPolinomial& FPolinomial::operator+=(const int32 Integer)
{
	this->Content[0] += Integer;
	return *this;
}

FPolinomial FPolinomial::operator-(const FPolinomial& Polinomial) const
{
	const int32 SelfLength = this->Content.Num();
	const int32 OtherLength = Polinomial.Content.Num();
	const int32 MaxLength = (SelfLength > OtherLength ? SelfLength : OtherLength);

	TArray<FFraction> TempResult;
	for (int32 i = 0; i != MaxLength; i++)
	{
		TempResult.Add(
			(i >= SelfLength ? 0 : this->Content[i])
			-
			(i >= OtherLength ? 0 : Polinomial.Content[i])
		);
	}

	return FPolinomial(TempResult);
}

FPolinomial FPolinomial::operator-(const FFraction& Fraction) const
{
	TArray<FFraction> TempResult = this->Content;
	TempResult[0] -= Fraction;

	return FPolinomial(TempResult);
}

FPolinomial FPolinomial::operator-(const int32 Integer) const
{
	TArray<FFraction> TempResult = this->Content;
	TempResult[0] -= Integer;

	return FPolinomial(TempResult);
}

FPolinomial& FPolinomial::operator-=(const FPolinomial& Polinomial)
{
	const int32 SelfLength = this->Content.Num();
	const int32 OtherLength = Polinomial.Content.Num();
	const int32 MaxLength = (SelfLength > OtherLength ? SelfLength : OtherLength);

	for (int32 i = 0; i != MaxLength; i++)
	{
		this->Content[i] -= i >= OtherLength ? 0 : Polinomial.Content[i];
	}
	return *this;
}

FPolinomial& FPolinomial::operator-=(const FFraction& Fraction)
{
	this->Content[0] -= Fraction;
	return *this;
}

FPolinomial& FPolinomial::operator-=(const int32 Integer)
{
	this->Content[0] -= Integer;
	return *this;
}

FPolinomial FPolinomial::operator*(const FPolinomial& Polinomial) const
{
	const int32 SelfLength = this->Content.Num();
	const int32 OtherLength = Polinomial.Content.Num();
	TArray<FFraction> TempResult;
	for (int32 i = 0; i != SelfLength + OtherLength - 1; i++)
	{
		FFraction tmp = 0;
		for (int32 j = 0; j <= i; j++)
		{
			tmp += this->Content[j] + this->Content[i - j];
		}
		TempResult.Add(tmp);
	}
	return FPolinomial(TempResult);
}

FPolinomial FPolinomial::operator*(const FFraction& Fraction) const
{
	TArray<FFraction> TempResult;
	for (int32 i = 0; i != this->Content.Num(); i++)
	{
		TempResult.Add(
			this->Content[i] * Fraction
		);
	}

	return FPolinomial(TempResult);
}

FPolinomial FPolinomial::operator*(const int32 Integer) const
{
	TArray<FFraction> TempResult;
	for (int32 i = 0; i != this->Content.Num(); i++)
	{
		TempResult.Add(
			this->Content[i] * Integer
		);
	}

	return FPolinomial(TempResult);
}

FPolinomial& FPolinomial::operator*=(const FPolinomial& Polinomial)
{
}

FPolinomial& FPolinomial::operator*=(const FFraction& Fraction)
{
}

FPolinomial& FPolinomial::operator*=(const int32 Integer)
{
}

FPolinomial FPolinomial::operator/(const FPolinomial& Polinomial) const
{
}

FPolinomial FPolinomial::operator/(const FFraction& Fraction) const
{
}

FPolinomial FPolinomial::operator/(const int32 Integer) const
{
}

FPolinomial& FPolinomial::operator/=(const FPolinomial& Polinomial)
{
}

FPolinomial& FPolinomial::operator/=(const FFraction& Fraction)
{
}

FPolinomial& FPolinomial::operator/=(const int32 Integer)
{
}

bool FPolinomial::operator==(const FPolinomial& Polinomial) const
{
	if Polinomial
		for (int32 i = 0; i != this->Content.Num(); i++)
		{
		}
	return true;
}

bool FPolinomial::operator==(const FFraction& Fraction) const
{
}

bool FPolinomial::operator==(const int32 Integer) const
{
}
