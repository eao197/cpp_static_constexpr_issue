#include "qvalue.hpp"

void a(unsigned int & dest)
{
	dest = qvalue_t{ qvalue_t::maximum }.as_uint();
}

