#include <iostream>

void a(unsigned int &);
void b(unsigned int &);

int main()
{
	unsigned int v = 0;

	a(v);
	std::cout << "value from a(): " << v << std::endl;

	b(v);
	std::cout << "value from b(): " << v << std::endl;

	return 0;
}

