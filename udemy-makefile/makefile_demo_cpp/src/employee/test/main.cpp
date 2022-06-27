#include <iostream>

#include "employee.h"

int main() {

	Employee eOBJ{"ID01", "Subrat","SWE"};
	std::clog << eOBJ.getName() << std::endl;
    return 0;
}
