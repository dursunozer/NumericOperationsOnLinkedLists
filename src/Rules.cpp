
#include "../include/SayilarListesi.hpp"
#include <stddef.h>
#include <iostream>

int get_count(Basamak *ilk)
{
	Basamak *tmp = ilk;
	int i = 0;

	while (tmp != nullptr)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

Basamak	*tersle(Basamak *d, int len)
{
	Basamak *b;
	int	i;

	if (len == 1)
	{
		d->next = nullptr;
		return (d);
	}
	b = d;
	i = len;
	while (i > 1)
	{
		b = b->next;
		i--;
	}
	b->next = tersle(d, len-1);
	return (b);
}

void	add_basamak(Basamak **b, Basamak *tmp, int i)
{
	Basamak *tmp_b;

	if (i == 1)
	{
		(*b) = tmp;
		return ;
	}
	if (i == 2)
	{
		(*b)->next = tmp;
		return ;
	}
	while (i > 2)
	{
		i--;
		tmp_b = (*b)->next;
	}
	tmp_b->next = tmp;
}

int		control_func1(int number)
{
	int odd = 0;
	int even = 0;
	while (number > 0)
	{
		if (number % 2 == 0)
			odd++;
		if (number % 2 == 1)
			even++;
		number /= 10;
	}
	if (!odd || !even)
		return (0);
	return (1);
}

void	function1(Dugum *d)
{
	int	i = 0, j = 0;
	Basamak *tmp;
	Basamak *tmp_odd;
	Basamak *tmp_even;

	tmp = d->sayi->ilk;
	tmp_odd = nullptr;
	tmp_even = nullptr;
	while (tmp != nullptr)
	{
		if (tmp->number % 2 == 0)
		{
			i++;
			add_basamak(&tmp_even, tmp, i);
		}
		else if (tmp->number % 2 == 1)
		{
			j++;
			add_basamak(&tmp_odd, tmp, j);
		}
		tmp = tmp->next;
	}
	d->sayi->ilk = tmp_odd;
	while (j--, j > 0)
		tmp_odd = tmp_odd->next;
	tmp_odd->next = tmp_even;
	while (i--, i > 0)
		tmp_even = tmp_even->next;
	tmp_even->next = nullptr;
}

void	function2(Dugum *ilk)
{
	Dugum *d;

	d = ilk;
	while (d != nullptr)
	{
		d->sayi->ilk = tersle(d->sayi->ilk, get_count(d->sayi->ilk));
		d = d->next;
	}
}

void	function3(Dugum **ilk, int __EnBuyuk__)
{
	Dugum *tmp_delete;
	if ((*ilk)->__SAYI__ == __EnBuyuk__)
	{
		tmp_delete = (*ilk);
		(*ilk) = (*ilk)->next;
		delete tmp_delete;
		return ;
	}
	Dugum *tmp = (*ilk);
	while (tmp->next->__SAYI__ != __EnBuyuk__)
		tmp = tmp->next;
	tmp_delete = tmp->next;
	tmp->next = tmp_delete->next;
	delete tmp_delete;
}

void	SayilarListesi::Rules(int i)
{
	if (i == 1)
	{
		Dugum *d = this->ilk;
		while (d != nullptr)
		{
			if (control_func1(d->__SAYI__))
				function1(d);
			d = d->next;
		}
		update_numbers();
	}
	else if (i == 2)
	{
		function2(this->ilk);
		update_numbers();
	}
	else if (i == 3)
	{
		if (ilk == nullptr)
			return ;
		function3(&this->ilk, this->__BIGGEST__);
		update_numbers();
	}
}