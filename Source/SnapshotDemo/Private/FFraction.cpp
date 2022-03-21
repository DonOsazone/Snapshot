// Fill out your copyright notice in the Description page of Project Settings.


#include "FFraction.h"


// 辗转相除法求最大公约数
int32 GCD(int32 n, int32 m)
{
	return m == 0 ? n : GCD(m, n % m);
}

inline int32 Abs(int32 n)
{
	return (n >= 0 ? n : -n);
}

FFraction::FFraction()
{
	this->Numerator = 0;
	this->Denominator = 1;
}

FFraction::FFraction(const int32 Integer)
{
	this->Numerator = Integer;
	this->Denominator = 1;
}

FFraction::FFraction(const int32 Numerator, const int32 Denominator)
{
	if (Denominator == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("错误：分母为0"));
		// --TODO!
		// 错误处理部分的其他代码完成后，此处接入那里

		this->Numerator = 0;
		this->Denominator = 1;
	}
	else
	{
		const int32 gcd = GCD(Abs(Numerator), Abs(Denominator));
		if (Denominator > 0)
		{
			this->Numerator = Numerator / gcd;
			this->Denominator = Denominator / gcd;
		}
		else
		{
			this->Numerator = -Numerator / gcd;
			this->Denominator = -Denominator / gcd;
		}
	}
}

FFraction::FFraction(const FFraction& Fract)
{
	this->Numerator = Fract.Numerator;
	this->Denominator = Fract.Denominator;
}

FFraction FFraction::operator+(const int32 Integer) const
{
	return FFraction(
		this->Numerator + Integer * this->Denominator,
		this->Denominator
	);
}

FFraction FFraction::operator+(const FFraction& Fract) const
{
	return FFraction(
		this->Numerator * Fract.Denominator + Fract.Numerator * this->Denominator,
		this->Denominator * Fract.Denominator
	);
}

FFraction& FFraction::operator+=(const int32 Integer)
{
	this->Numerator += Integer * this->Denominator;
	return *this;
}

FFraction& FFraction::operator+=(const FFraction& Fract)
{
	const int32 n = this->Numerator * Fract.Denominator + Fract.Numerator * this->Denominator;
	const int32 d = this->Denominator * Fract.Denominator;
	const int32 gcd = GCD(Abs(n), Abs(d));
	this->Numerator = n / gcd;
	this->Denominator = d / gcd;
	return *this;
}

FFraction FFraction::operator-(const int32 Integer) const
{
	return FFraction(
		this->Numerator - Integer * this->Denominator,
		this->Denominator
	);
}

FFraction FFraction::operator-(const FFraction& Fract) const
{
	return FFraction(
		this->Numerator * Fract.Denominator - Fract.Numerator * this->Denominator,
		this->Denominator * Fract.Denominator
	);
}

FFraction& FFraction::operator-=(const int32 Integer)
{
	this->Numerator += Integer * this->Denominator;
	return *this;
}

FFraction& FFraction::operator-=(const FFraction& Fract)
{
	const int32 n = this->Numerator * Fract.Denominator - Fract.Numerator * this->Denominator;
	const int32 d = this->Denominator * Fract.Denominator;
	const int32 gcd = GCD(Abs(n), Abs(d));
	this->Numerator = n / gcd;
	this->Denominator = d / gcd;
	return *this;
}

FFraction FFraction::operator*(const int32 Integer) const
{
	return FFraction(
		this->Numerator * Integer,
		this->Denominator
	);
}

FFraction FFraction::operator*(const FFraction& Fract) const
{
	return FFraction(
		this->Numerator * Fract.Numerator,
		this->Denominator * Fract.Denominator
	);
}

FFraction& FFraction::operator*=(const int32 Integer)
{
	const int32 gcd = GCD(this->Denominator, Abs(Integer));
	this->Denominator /= gcd;
	this->Numerator *= (Integer / gcd);
	return *this;
}

FFraction& FFraction::operator*=(const FFraction& Fract)
{
	const int32 gcd1 = GCD(this->Denominator, Abs(Fract.Numerator));
	const int32 gcd2 = GCD(Fract.Denominator, Abs(this->Numerator));
	this->Denominator = this->Denominator * Fract.Denominator / (gcd1 * gcd2);
	this->Numerator = this->Numerator * Fract.Numerator / (gcd1 * gcd2);
	return *this;
}

FFraction FFraction::operator/(const int32 Integer) const
{
	if (Integer == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("错误：除以零"));
		// --TODO!
		// 错误处理部分的其他代码完成后，此处接入那里
	}
	else
	{
		if (Integer < 0)
		{
			return FFraction(
				-this->Numerator,
				this->Denominator * (-Integer)
			);
		}
		return FFraction(
			this->Numerator,
			this->Denominator * Integer
		);
	}
	return FFraction(0);
}

FFraction FFraction::operator/(const FFraction& Fract) const
{
	if (Fract.Numerator == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("错误：除以零"));
		// --TODO!
		// 错误处理部分的其他代码完成后，此处接入那里
	}
	else
	{
		if (Fract.Numerator < 0)
		{
			return FFraction(
				this->Numerator * (-Fract.Denominator),
				this->Denominator * (-Fract.Numerator)
			);
		}
		return FFraction(
			this->Numerator * Fract.Denominator,
			this->Denominator * Fract.Numerator
		);
	}
	return FFraction(0);
}

FFraction& FFraction::operator/=(const int32 Integer)
{
	if (Integer == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("错误：除以零"));
		// --TODO!
		// 错误处理部分的其他代码完成后，此处接入那里
	}
	else
	{
		const int32 gcd = GCD(Abs(this->Numerator), Abs(Integer));
		if (Integer < 0)
		{
			this->Numerator /= -gcd;
			this->Denominator *= -(Integer / gcd);
			return *this;
		}
		this->Numerator /= gcd;
		this->Denominator *= Integer / gcd;
		return *this;
	}
	this->Numerator = 0;
	this->Denominator = 1;
	return *this;
}

FFraction& FFraction::operator/=(const FFraction& Fract)
{
	if (Fract.Numerator == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("错误：除以零"));
		// --TODO!
		// 错误处理部分的其他代码完成后，此处接入那里
	}
	else
	{
		const int32 gcd1 = GCD(Abs(this->Numerator), Abs(Fract.Numerator));
		const int32 gcd2 = GCD(this->Denominator, Fract.Denominator);
		if (Fract.Numerator < 0)
		{
			this->Numerator *= -Fract.Denominator / gcd1;
			this->Denominator *= -Fract.Numerator / gcd2;
			return *this;
		}
		this->Numerator *= Fract.Denominator / gcd1;
		this->Denominator *= Fract.Numerator / gcd2;
		return *this;
	}
	this->Numerator = 0;
	this->Denominator = 1;
	return *this;
}

FFraction& FFraction::operator=(const int32 Integer)
{
	this->Denominator = 1;
	this->Numerator = Integer;
	return *this;
}

FFraction& FFraction::operator=(const FFraction& Fract)
{
	this->Denominator = Fract.Denominator;
	this->Numerator = Fract.Numerator;
	return *this;
}

FFraction FFraction::operator-() const
{
	return FFraction(-(this->Numerator), this->Denominator);
}

bool FFraction::operator<(const int32 Integer) const
{
	return (this->Numerator < Integer * this->Denominator);
}

bool FFraction::operator<(const FFraction& Fract) const
{
	return (this->Numerator * Fract.Denominator < Fract.Numerator * this->Denominator);
}

bool FFraction::operator<=(const int32 Integer) const
{
	return (this->Numerator <= Integer * this->Denominator);
}

bool FFraction::operator<=(const FFraction& Fract) const
{
	return (this->Numerator * Fract.Denominator <= Fract.Numerator * this->Denominator);
}

bool FFraction::operator>(const int32 Integer) const
{
	return (this->Numerator > Integer * this->Denominator);
}

bool FFraction::operator>(const FFraction& Fract) const
{
	return (this->Numerator * Fract.Denominator > Fract.Numerator * this->Denominator);
}

bool FFraction::operator>=(const int32 Integer) const
{
	return (this->Numerator >= Integer * this->Denominator);
}

bool FFraction::operator>=(const FFraction& Fract) const
{
	return (this->Numerator * Fract.Denominator >= Fract.Numerator * this->Denominator);
}

bool FFraction::operator==(const int32 Integer) const
{
	return (this->Numerator == Integer * this->Denominator);
}

bool FFraction::operator==(const FFraction& Fract) const
{
	return (this->Numerator == Fract.Numerator && this->Denominator == Fract.Denominator);
}

bool FFraction::operator!=(const int32 Integer) const
{
	return (this->Numerator != Integer * this->Denominator);
}

bool FFraction::operator!=(const FFraction& Fract) const
{
	return (this->Numerator != Fract.Numerator || this->Denominator != Fract.Denominator);
}


FFraction::~FFraction()
{
}
