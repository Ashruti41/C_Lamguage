hello
#include<iostream>
//eurjnwiejfnwifn

#include "ui_controller.h"

UI_Controller::UI_Controller() {
	std::clog << "UI_CONTROLLER CONSTRUCTOT\n";
}

void UI_Controller::get_emp_id_and_show_details()
{
	std::string id;
		DB_Mgr dbMgrObj;
	do {

		id.erase();
		std::clog << "\nEnter employee ID: ";
		std::getline(std::cin, id);
		auto emp = dbMgrObj.get_emp_details(id);
		std::clog << "ID: " << emp.getId() << "\nName: " << emp.getName() << "\nDesig: " << emp.designation();
	}while(id!= "0");
}


void UI_Controller::show() {
	std::clog << _PRETTY_FUNCTION_ <<"\n";
	get_emp_id_and_show_details();
}
