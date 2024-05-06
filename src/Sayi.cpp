
#include "../include/Sayi.hpp"
#include <stddef.h>

Sayi::Sayi(int j)
{
	this->i = j;
	this->ilk = nullptr;

	while (i > 0)
	{
		Basamak *new_Basamak;
		Basamak *tmp;
		
		new_Basamak = new Basamak(i % 10);
		tmp = ilk;
		ilk = new_Basamak;
		ilk->next = tmp;
		i = i / 10;
	}
};

Sayi::~Sayi()
{
	Basamak *tmp = ilk;
	Basamak *tmp2;

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