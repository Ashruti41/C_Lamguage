#pragma once

#include<string>
#include "employee.h"
#include "list"

class DB_Mgr{

	public:
		DB_Mgr();
		Employee get_emp_details(const std::string& emp_id);

		std::list<Employee> getEmp_list() const;
		void setEmp_list(const std::list<Employee> &value);

	private:
		std::list<Employee> emp_list;
};


