
#include <iostream>

#include "test1.h"
#include "test2.h"

int main() {

	std::cout << "Inside testi-main\n";
	test1 t1obj;
	t1obj();
	test2 t2obj;
	t2obj(); // test2 class
	return 0;
}
