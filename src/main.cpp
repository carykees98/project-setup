#include <filesystem>
#include <iostream>
#include <string>

#include "generator.h"
#include "help.h"
#include "project.h"

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		std::cerr << "Too few arguments" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (argv[1] == std::string("--help") || argv[1] == std::string("-h"))
	{
		pjs::printUsage();
		exit(EXIT_FAILURE);
	}

	pjs::Project projectInfo;
	projectInfo.name = argv[1];

	std::filesystem::path path;
	if (argc > 2)
	{
		if (argv[2][0] == '/')
			path = std::filesystem::absolute(std::string(argv[2]) + "/" + argv[1]);
		else
			path = std::filesystem::relative(std::string(argv[2]) + "/" + argv[1], std::filesystem::current_path());
		std::filesystem::create_directory(path);
		projectInfo.path = path;
	}
	else
	{
		path = std::filesystem::absolute("./" + projectInfo.name);
		std::filesystem::create_directory(path);
		projectInfo.path = path;
	}

	pjs::createProject(projectInfo);

	exit(EXIT_SUCCESS);
}
