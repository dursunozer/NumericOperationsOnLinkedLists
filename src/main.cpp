
#include "../include/SayilarListesi.hpp"
#include <fstream>
#include <iostream>
#include <stddef.h>

using namespace std;

void	add_Numbers(SayilarListesi *__LIST__, string fileName)
{
	ifstream okumaDosyasi(fileName);
	okumaDosyasi.seekg(0);
	int	number;
	int x;

	while (!okumaDosyasi.eof())
	{
		string line;
		getline(okumaDosyasi, line);
		while (line != "")
		{	
			number = 0;
			x = line.find_first_of(' ');
			if(x < 0)
				number = stoi(line);
			else
				number = stoi(line.substr(0,x));
			if(x < 0)
				line = "";
			else
				line = line.substr(x+1);
			__LIST__->add(number);
		}
	}
	__LIST__->update_numbers();
}

int main()
{
	SayilarListesi __SayilarListesi__;
	int i;

	add_Numbers(&__SayilarListesi__, "sayilar.txt");
	while (1)
	{

		(__SayilarListesi__).print_Information();
		cin >> i;
		if (i == 1)
			__SayilarListesi__.Rules(1);
		else if (i == 2)
			__SayilarListesi__.Rules(2);
		else if (i == 3)
			__SayilarListesi__.Rules(3);
		else if (i == 4)
			return (0);
	}
}