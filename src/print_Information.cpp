
#include "../include/SayilarListesi.hpp"
#include <stddef.h>
#include<sstream>
#include <iostream>

using namespace std;

void	lastThree(Basamak *b)
{
	string address;
	ostringstream get_the_adress;

	get_the_adress << b;
	address = get_the_adress.str();
	cout << address.substr(address.size() - 3);
}

void	print_Dugum(Dugum *d)
{
	Basamak *b = d->sayi->ilk;
	int	count = 0;
	for (int i=13; i>0; i--)
		cout << "#";
	cout << "   ";
	for (int n = d->__SAYI__; n > 0; n = n /10)
	{
		count++;
		for (int i=7; i>0; i--)
			cout << "*";
		cout << " ";
	}
	cout << "\n#" << d << "#   ";
	while (b != nullptr)
	{
		cout << "* ";
		lastThree(b);
		cout << " * ";
		b = b->next;
	}
	cout << "\n#";
	for (int i=11; i>0; i--)
		cout << "-";
	cout << "#   ";
	for (int n = d->__SAYI__; n > 0; n = n /10)
	{
		for (int i=7; i>0; i--)
			cout << "*";
		cout << " ";
	}
	b = d->sayi->ilk;
	cout << "\n#";
	for (int i= 11-count; i>0; i--)
		cout << " ";
	cout << d->__SAYI__ << "#   ";
	while (count > 0)
	{
		cout << "*   ";
		cout << b->number;
		cout << " * ";
		b = b->next;
		count--;
	}
	cout << endl;
	for (int i=13; i>0; i--)
		cout << "#";
	cout << "   ";
	for (int n = d->__SAYI__; n > 0; n = n /10)
	{
		for (int i=7; i>0; i--)
			cout << "*";
		cout << " ";
	}
	cout << "\n\n";
}

void	SayilarListesi::print_Information()
{
	Dugum *d = ilk;
	while (d != nullptr)
	{
		print_Dugum(d);
		d = d->next;
	}
	cout << "1. Tek basamaklari Basa Al\n";
	cout << "2. Basamaklari Tersle\n";
	cout << "3. En Buyuk Cikar\n";
	cout << "4. cikis\n";
}