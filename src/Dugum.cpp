
#include "../include/Dugum.hpp"
#include <stddef.h>

Dugum::Dugum(int i)
{
	sayi = new Sayi(i);
	next = nullptr;
	__SAYI__ = i;
}

Dugum::~Dugum()
{
	delete sayi;
}