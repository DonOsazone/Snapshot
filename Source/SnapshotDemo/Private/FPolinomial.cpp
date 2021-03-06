// Fill out your copyright notice in the Description page of Project Settings.


#include "FPolinomial.h"

void HighZeroRemove(TArray<FFraction>& PolinomialContent)
{
	for (int32 i = PolinomialContent.Num() - 1; i > 0; i++)
	{
		if (PolinomialContent[i] == 0)
		{
			PolinomialContent.RemoveAt(i);
		}
		else
		{
			return;
		}
	}
}


FPolinomial::FPolinomial()
{
	this->PositiveContent = TArray<FFraction>({FFraction(0)});
	this->NegativeContent = TArray<FFraction>({FFraction(0)});
}

FPolinomial::FPolinomial(const TArray<FFraction>& Content)
{
	this->PositiveContent = Content;
	this->NegativeContent = TArray<FFraction>({FFraction(0)});
}

FPolinomial::FPolinomial(const TArray<FFraction>& NegativeContent, const TArray<FFraction>& PositiveContent)
{
	this->PositiveContent = PositiveContent;
	this->NegativeContent = NegativeContent;
}

FPolinomial::~FPolinomial()
{
}

inline int32 FPolinomial::PositiveLimit() const
{
	return this->PositiveContent.Num() - 1;
}

inline int32 FPolinomial::NegativeLimit() const
{
	return 1 - this->NegativeContent.Num();
}

FPolinomial FPolinomial::operator+(const FPolinomial& Polinomial) const
{
	const int32 SelfPositiveLength = this->PositiveContent.Num();
	const int32 OtherPositiveLength = Polinomial.PositiveContent.Num();
	const int32 MaxPositiveLength = SelfPositiveLength > OtherPositiveLength ? SelfPositiveLength : OtherPositiveLength;

	const int32 SelfNegativeLength = this->NegativeContent.Num();
	const int32 OtherNegativeLength = Polinomial.NegativeContent.Num();
	const int32 MaxNegativeLength = SelfNegativeLength > OtherNegativeLength ? SelfNegativeLength : OtherNegativeLength;

	TArray<FFraction> TempPositiveResult, TempNegativeResult;
	for (int32 i = 0; i != MaxPositiveLength; i++)
	{
		TempPositiveResult.Add(
			(i >= SelfPositiveLength ? 0 : this->PositiveContent[i])
			+
			(i >= OtherPositiveLength ? 0 : Polinomial.PositiveContent[i])
		);
	}
	for (int32 i = 1; i != MaxNegativeLength; i++)
	{
		TempNegativeResult.Add(
			(i >= SelfNegativeLength ? 0 : this->NegativeContent[i])
			+
			(i >= OtherNegativeLength ? 0 : Polinomial.NegativeContent[i])
		);
	}

	return FPolinomial(TempNegativeResult, TempPositiveResult);
}

FPolinomial FPolinomial::operator+(const FFraction& Fraction) const
{
	// ?????????????????????????????????????????????TArray???????????????????????????????????????TArray?????????Polinomial???????????????
	TArray<FFraction> TempPositiveResult = this->PositiveContent;
	TArray<FFraction> TempNegativeResult = this->NegativeContent;

	TempPositiveResult[0] += Fraction;

	return FPolinomial(TempNegativeResult, TempPositiveResult);
}

FPolinomial FPolinomial::operator+(const int32 Integer) const
{
	TArray<FFraction> TempPositiveResult = this->PositiveContent;
	TArray<FFraction> TempNegativeResult = this->NegativeContent;

	TempPositiveResult[0] += Integer;

	return FPolinomial(TempNegativeResult, TempPositiveResult);
}

FPolinomial& FPolinomial::operator+=(const FPolinomial& Polinomial)
{
	const int32 SelfPositiveLength = this->PositiveContent.Num();
	const int32 OtherPositiveLength = Polinomial.PositiveContent.Num();
	const int32 MaxPositiveLength = SelfPositiveLength > OtherPositiveLength ? SelfPositiveLength : OtherPositiveLength;

	const int32 SelfNegativeLength = this->NegativeContent.Num();
	const int32 OtherNegativeLength = Polinomial.NegativeContent.Num();
	const int32 MaxNegativeLength = SelfNegativeLength > OtherNegativeLength ? SelfNegativeLength : OtherNegativeLength;

	for (int32 i = 0; i != MaxPositiveLength; i++)
	{
		if (i >= SelfPositiveLength)
		{
			this->PositiveContent.Add(FFraction(0));
		}
		this->PositiveContent[i] += i > OtherPositiveLength ? 0 : Polinomial.PositiveContent[i];
	}
	for (int32 i = 1; i != MaxNegativeLength; i++)
	{
		if (i >= SelfNegativeLength)
		{
			this->NegativeContent.Add(FFraction(0));
		}
		this->NegativeContent[i] += i > OtherNegativeLength ? 0 : Polinomial.NegativeContent[i];
	}

	return *this;
}

FPolinomial& FPolinomial::operator+=(const FFraction& Fraction)
{
	this->PositiveContent[0] += Fraction;
	return *this;
}

FPolinomial& FPolinomial::operator+=(const int32 Integer)
{
	this->PositiveContent[0] += Integer;
	return *this;
}

FPolinomial FPolinomial::operator-(const FPolinomial& Polinomial) const
{
	const int32 SelfPositiveLength = this->PositiveContent.Num();
	const int32 OtherPositiveLength = Polinomial.PositiveContent.Num();
	const int32 MaxPositiveLength = SelfPositiveLength > OtherPositiveLength ? SelfPositiveLength : OtherPositiveLength;

	const int32 SelfNegativeLength = this->NegativeContent.Num();
	const int32 OtherNegativeLength = Polinomial.NegativeContent.Num();
	const int32 MaxNegativeLength = SelfNegativeLength > OtherNegativeLength ? SelfNegativeLength : OtherNegativeLength;

	TArray<FFraction> TempPositiveResult, TempNegativeResult;
	for (int32 i = 0; i != MaxPositiveLength; i++)
	{
		TempPositiveResult.Add(
			(i >= SelfPositiveLength ? 0 : this->PositiveContent[i])
			-
			(i >= OtherPositiveLength ? 0 : Polinomial.PositiveContent[i])
		);
	}
	for (int32 i = 1; i != MaxNegativeLength; i++)
	{
		TempNegativeResult.Add(
			(i >= SelfNegativeLength ? 0 : this->NegativeContent[i])
			-
			(i >= OtherNegativeLength ? 0 : Polinomial.NegativeContent[i])
		);
	}

	return FPolinomial(TempNegativeResult, TempPositiveResult);
}

FPolinomial FPolinomial::operator-(const FFraction& Fraction) const
{
	TArray<FFraction> TempPositiveResult = this->PositiveContent;
	TArray<FFraction> TempNegativeResult = this->NegativeContent;

	TempPositiveResult[0] -= Fraction;

	return FPolinomial(TempNegativeResult, TempPositiveResult);
}

FPolinomial FPolinomial::operator-(const int32 Integer) const
{
	TArray<FFraction> TempPositiveResult = this->PositiveContent;
	TArray<FFraction> TempNegativeResult = this->NegativeContent;

	TempPositiveResult[0] -= Integer;

	return FPolinomial(TempNegativeResult, TempPositiveResult);
}

FPolinomial& FPolinomial::operator-=(const FPolinomial& Polinomial)
{
	const int32 SelfPositiveLength = this->PositiveContent.Num();
	const int32 OtherPositiveLength = Polinomial.PositiveContent.Num();
	const int32 MaxPositiveLength = SelfPositiveLength > OtherPositiveLength ? SelfPositiveLength : OtherPositiveLength;

	const int32 SelfNegativeLength = this->NegativeContent.Num();
	const int32 OtherNegativeLength = Polinomial.NegativeContent.Num();
	const int32 MaxNegativeLength = SelfNegativeLength > OtherNegativeLength ? SelfNegativeLength : OtherNegativeLength;

	for (int32 i = 0; i != MaxPositiveLength; i++)
	{
		if (i >= SelfPositiveLength)
		{
			this->PositiveContent.Add(FFraction(0));
		}
		this->PositiveContent[i] -= i > OtherPositiveLength ? 0 : Polinomial.PositiveContent[i];
	}
	for (int32 i = 1; i != MaxNegativeLength; i++)
	{
		if (i >= SelfNegativeLength)
		{
			this->NegativeContent.Add(FFraction(0));
		}
		this->NegativeContent[i] -= i > OtherNegativeLength ? 0 : Polinomial.NegativeContent[i];
	}

	return *this;
}

FPolinomial& FPolinomial::operator-=(const FFraction& Fraction)
{
	this->PositiveContent[0] -= Fraction;
	return *this;
}

FPolinomial& FPolinomial::operator-=(const int32 Integer)
{
	this->PositiveContent[0] -= Integer;
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
	TArray<FFraction> TempPositiveResult = TArray<FFraction>();
	for (int32 i = 0; i != this->PositiveContent.Num(); i++)
	{
		TempPositiveResult.Add(
			this->PositiveContent[i] * Fraction
		);
	}

	TArray<FFraction> TempNegativeResult = TArray<FFraction>({FFraction()});
	for (int32 i = 1; i != this->NegativeContent.Num(); i++)
	{
		TempNegativeResult.Add(
			this->NegativeContent[i] * Fraction
		);
	}

	return FPolinomial(TempPositiveResult);
}

FPolinomial FPolinomial::operator*(const int32 Integer) const
{
	TArray<FFraction> TempPositiveResult = TArray<FFraction>();
	for (int32 i = 0; i != this->PositiveContent.Num(); i++)
	{
		TempPositiveResult.Add(
			this->PositiveContent[i] * Integer
		);
	}

	TArray<FFraction> TempNegativeResult = TArray<FFraction>({FFraction()});
	for (int32 i = 1; i != this->NegativeContent.Num(); i++)
	{
		TempNegativeResult.Add(
			this->NegativeContent[i] * Integer
		);
	}

	return FPolinomial(TempPositiveResult);
}

FPolinomial& FPolinomial::operator*=(const FPolinomial& Polinomial)
{
}

FPolinomial& FPolinomial::operator*=(const FFraction& Fraction)
{
	for (int32 i = 0; i != this->PositiveContent.Num(); i++)
	{
		this->PositiveContent[i] *= Fraction;
	}
	HighZeroRemove(this->PositiveContent);
	return *this;
}

FPolinomial& FPolinomial::operator*=(const int32 Integer)
{
	for (int32 i = 0; i != this->PositiveContent.Num(); i++)
	{
		this->PositiveContent[i] *= Integer;
	}
	HighZeroRemove(this->PositiveContent);
	for (int32 i = 0; i != this->NegativeContent.Num(); i++)
	{
		this->NegativeContent[i] *= Integer;
	}
	HighZeroRemove(this->NegativeContent);
	return *this;
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

FFraction& FPolinomial::operator[](const int32 Index)
{
	if (Index >= -(this->NegativeContent.Num() - 1) && Index <= this->PositiveContent.Num() - 1)
	{
		if (Index >= 0)
		{
			return this->PositiveContent[Index];
		}
		return this->NegativeContent[-Index];
	}
	// --TODO
	// ????????????
	return this->NegativeContent[0];
}

const FFraction& FPolinomial::operator[](const int32 Index) const
{
	if (Index >= -(this->NegativeContent.Num() - 1) && Index <= this->PositiveContent.Num() - 1)
	{
		if (Index >= 0)
		{
			return this->PositiveContent[Index];
		}
		return this->NegativeContent[-Index];
	}
	// --TODO
	// ????????????
	return this->NegativeContent[0];
}

bool FPolinomial::operator==(const FPolinomial& Polinomial) const
{
	if (Polinomial.NegativeLimit() != this->NegativeLimit() ||
		Polinomial.PositiveLimit() != this->PositiveLimit())
	{
		return false;
	}
	for (int32 i = this->NegativeLimit(); i != this->PositiveLimit(); i++)
	{
		if ((*this)[i] != Polinomial[i])
		{
			return false;
		}
	}
	return true;
}

bool FPolinomial::operator==(const FFraction& Fraction) const
{
	return (
		this->NegativeContent.Num() <= 1 &&
		this->PositiveContent.Num() == 1 &&
		this->PositiveContent[0] == Fraction
	);
}

bool FPolinomial::operator==(const int32 Integer) const
{
	return (
		this->NegativeContent.Num() <= 1 &&
		this->PositiveContent.Num() == 1 &&
		this->PositiveContent[0] == Integer
	);
}
