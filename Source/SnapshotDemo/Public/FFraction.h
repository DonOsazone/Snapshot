// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


/**
 * @brief 分数结构
 * 提供基本的分数运算，以分数形式存储
 */
struct SNAPSHOTDEMO_API FFraction
{
	/**
	 * @brief 分数分子
	 */
	int32 Numerator;
	/**
	 * @brief 分数分母
	 */
	uint32 Denominator;

	FFraction();
	FFraction(const int32 Integer);
	FFraction(const int32 Numerator, const int32 Denominator);
	FFraction(const FFraction& Fract);

	FFraction	operator+	(const int32 Integer) const;
	FFraction	operator+	(const FFraction& Fract) const;
	FFraction&	operator+=	(const int32 Integer);
	FFraction&	operator+=	(const FFraction& Fract);

	FFraction	operator-	(const int32 Integer) const;
	FFraction	operator-	(const FFraction& Fract) const;
	FFraction&	operator-=	(const int32 Integer);
	FFraction&	operator-=	(const FFraction& Fract);

	FFraction	operator*	(const int32 Integer) const;
	FFraction	operator*	(const FFraction& Fract) const;
	FFraction&	operator*=	(const int32 Integer);
	FFraction&	operator*=	(const FFraction& Fract);

	FFraction	operator/	(const int32 Integer) const;
	FFraction	operator/	(const FFraction& Fract) const;
	FFraction&	operator/=	(const int32 Integer);
	FFraction&	operator/=	(const FFraction& Fract);

	FFraction&	operator=	(const int32 Integer);
	FFraction&	operator=	(const FFraction& Fract);

	FFraction	operator-	() const;

	bool		operator<	(const int32 Integer) const;
	bool		operator<	(const FFraction& Fract) const;

	bool		operator<=	(const int32 Integer) const;
	bool		operator<=	(const FFraction& Fract) const;

	bool		operator>	(const int32 Integer) const;
	bool		operator>	(const FFraction& Fract) const;
	
	bool		operator>=	(const int32 Integer) const;
	bool		operator>=	(const FFraction& Fract) const;
	
	bool		operator==	(const int32 Integer) const;
	bool		operator==	(const FFraction& Fract) const;


	~FFraction();
};

