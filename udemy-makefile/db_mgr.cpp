#include "db_mgr.h"
#include "employee.h"
#include "db_reader.h"

DB_Mgr::DB_Mgr() {

	Employee obj1("EID:1", "Ashruti", "Embedded Engineer");

	emp.list.emplace_back(obj1);

	emp_list.emplace_back("EID:2", "hcnd", "sr. Embedded Engineer");
	emp_list.emplace_back("EID:3", "hcnd", "sr. Embedded Engineer");
	emp_list.emplace_back("EID:4", "hcnd", "sr. Embedded Engineer");
	emp_list.emplace_back("EID:5", "Ashruti", "Embedded Engineer");

}

Employee DB_Mgr::get_emp_details(const std::string& emp_id) {

	Employee emp;
	DB_Reader dbrObj;
	dbrObj.read_emp_data(emp_list, emp_id, emp);
	return emp;
}

std::list<Employee> DB_Mgr::getEmp_list() const
{
	return emp_list;
}

