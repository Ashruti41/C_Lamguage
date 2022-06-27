#include <iostream>
#include "test1.h"

void test1::operator()() {
			std::clog << "I am functor test1...-------Hopefully u know me\n";
}

test1::test1() {
	std::clog << __PRETTY_FUNCTION__ << std::endl;
}
