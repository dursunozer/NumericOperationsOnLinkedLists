
#include "../include/SayilarListesi.hpp"
#include <stddef.h>
#include <iostream>

int	get_number(Basamak *b)
{
	Basamak *tmp = b;
	int i;

	i = 0;
	while (tmp != nullptr)
	{
		i = (i * 10) + tmp->number;
		tmp = tmp->next;
	}
	return (i);
}

void	SayilarListesi::update_numbers()
{
	Dugum *d = this->ilk;
	int biggest = 0;

	while (d != nullptr)
	{
		d->__SAYI__ = get_number(d->sayi->ilk);
		if (d->__SAYI__ > biggest)
			biggest = d->__SAYI__;
		d = d->next;
	}
	this->__BIGGEST__ = biggest;
}

void	SayilarListesi::add(int i)
{
	Dugum	*tmp;
	Dugum	*new_dugum;

	tmp = ilk;
	if (ilk == nullptr)
		ilk = new Dugum(i);
	else
	{
		while (tmp != nullptr && tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = new Dugum(i);
	}
}

SayilarListesi::SayilarListesi()
{
	this->ilk = nullptr;
}

SayilarListesi::~SayilarListesi()
{
	Dugum *tmp = ilk;
	Dugum *tmp2;

	while (tmp != nullptr)
	{
		if (tmp->next != nullptr)
		{
			tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}
		else
		{
			delete tmp;
			tmp = tmp->next;
		}
	}
}