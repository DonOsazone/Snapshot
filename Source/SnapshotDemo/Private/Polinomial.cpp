// Fill out your copyright notice in the Description page of Project Settings.


#include "Polinomial.h"

Polinomial::Polinomial()
{
}

Polinomial::~Polinomial()
{
}

Polinomial operator+ (const Polinomial& p1, const Polinomial& p2) {
	int p1length = p1.content.size();
	int p2length = p2.content.size();
	for (int i = 0; 
		i<(p1length>p2length?p1length:p2length);
		i++) {
			
	}
}