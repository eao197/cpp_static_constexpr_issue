#include "qvalue.hpp"

void b(unsigned int & dest)
{
	dest = qvalue_t{ qvalue_t::maximum }.as_uint();
}

