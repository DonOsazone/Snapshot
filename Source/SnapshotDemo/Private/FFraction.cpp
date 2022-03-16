// Fill out your copyright notice in the Description page of Project Settings.


#include "FFraction.h"


// 辗转相除法求最大公约数
uint32 gcd(uint32 n, uint32 m)
{
	return m == 0 ? n : gcd(m, n % m);
}


FFraction::FFraction()
{
	this->Integer = 0;
	this->Numerator = 0;
	this->Denominator = 1;
	this->bIsPositiveOrZero = true;
}

FFraction::FFraction(const int32 Integer)
{
	this->Integer = Integer;
	this->Numerator = 0;
	this->Denominator = 1;
	this->bIsPositiveOrZero = true;
}

FFraction::FFraction(const int32 Numerator, const int32 Denominator)
{
	if (Denominator == 0) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("错误：分母为0"));
		// --TODO!
		// 错误处理部分的其他代码完成后，此处接入那里

		this->Integer = 0;
		this->Numerator = 0;
		this->Denominator = 1;
		this->bIsPositiveOrZero = true;
	}
	else {
		uint32 _n = (uint32)(Numerator>=0?Numerator:-Numerator);
		uint32 _d = (uint32)(Denominator >= 0 ? Denominator : -Denominator);

		this->Integer = _n / _d;
		
		uint32 _gcd = gcd((_n % _d), _d);

		this->Numerator = _n / _gcd;
		this->Denominator = _d / _gcd;

		this->bIsPositiveOrZero = (Numerator >= 0) == (Denominator >= 0);
	}
}

FFraction::FFraction(const int32 Integer, const int32 Numerator, const int32 Denominator)
{
	if (Denominator == 0) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("错误：分母为0"));
		// --TODO!
		// 错误处理部分的其他代码完成后，此处接入那里

		this->Integer = 0;
		this->Numerator = 0;
		this->Denominator = 1;
		this->bIsPositiveOrZero = true;
	}
	else {
		uint32 _n = (uint32)(Numerator >= 0 ? Numerator : -Numerator);
		uint32 _d = (uint32)(Denominator >= 0 ? Denominator : -Denominator);
		uint32 _i = (uint32)(Integer >= 0 ? Integer : -Integer);

		this->Integer = _i + _n / _d;

		uint32 _gcd = gcd((_n % _d), _d);

		this->Numerator = _n / _gcd;
		this->Denominator = _d / _gcd;

		this->bIsPositiveOrZero = (Integer >= 0) == (Numerator >= 0) == (Denominator >= 0);
	}
}

FFraction FFraction::operator+(const int32 p)
{
	int32 n = ((int32)(this->Integer * this->Denominator + this->Numerator)) * (this->bIsPositiveOrZero ? 1 : -1) + p;
	return FFraction(n, this->Denominator);
}

FFraction FFraction::operator+(const FFraction& fract)
{
	// 首先，将二者强制转换为假分数
	int32 n1 = ((int32)(this->Integer * this->Denominator + this->Numerator)) * (this->bIsPositiveOrZero ? 1 : -1);
	int32 n2 = ((int32)(fract.Integer * fract.Denominator + fract.Numerator)) * (fract.bIsPositiveOrZero ? 1 : -1);

	int32 n = n1 * fract.Denominator + n2 * this->Denominator;	

	return FFraction(n, this->Denominator * fract.Denominator);
}

FFraction FFraction::operator+=(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator+=(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator-(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator-(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator-=(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator-=(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator*(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator*(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator*=(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator*=(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator/(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator/(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator/=(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator/=(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator=(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator=(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator-()
{
	return FFraction();
}

FFraction FFraction::operator<(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator<(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator<=(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator<=(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator>(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator>(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator>=(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator>=(const FFraction& fract)
{
	return FFraction();
}

FFraction FFraction::operator==(const int32 p)
{
	return FFraction();
}

FFraction FFraction::operator==(const FFraction& fract)
{
	return FFraction();
}


FFraction::~FFraction()
{
}
