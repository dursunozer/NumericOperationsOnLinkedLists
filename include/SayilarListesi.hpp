
#include "Dugum.hpp"

class SayilarListesi
{
public:
	Dugum	*ilk;
	int		__BIGGEST__;
	SayilarListesi();
	~SayilarListesi();
	void add(int i);
	void Rules(int i);
	void print_Information();
	void update_numbers();
};