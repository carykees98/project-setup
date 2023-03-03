#include "logging.h"

#include <iostream>
#include <string>

namespace pjs
{
	void logDirectoryCreation(const std::string directoryName)
	{
		std::cerr << "Creating directory: " << directoryName << std::endl;
	}

	void logFileGeneration(const std::string fileName)
	{
		std::cerr << "Generating file: " << fileName << std::endl;
	}
} // namespace pjs
