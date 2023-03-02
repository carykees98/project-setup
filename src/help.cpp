#include <iostream>
#include <iomanip>

#include "help.h"

namespace pjs
{
	void printUsage()
	{
		int width = 8;

		std::cout << std::left << "Arguments: " << std::endl
				  << std::setw(width) << "--help" << std::endl
				  << std::setw(width) << "-h"
				  << "Displays this menu" << std::endl
				  << std::endl
				  << std::setw(width) << "[project name]" << std::endl
				  << std::setw(width) << ""
				  << "Ex: aurelia" << std::endl
				  << std::endl
				  << std::endl
				  << "Examples: " << std::endl
				  << std::setw(width) << "project-setup --help" << std::endl
				  << std::setw(width) << "\tproject-setup aurelia" << std::endl;
	}
} // namespace pjs