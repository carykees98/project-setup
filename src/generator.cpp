#include "generator.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "project.h"
#include "logging.h"

namespace pjs
{
	void createProject(const Project &projectInfo)
	{
		std::cerr << "Project Name: " << projectInfo.name << std::endl;

		generateMain(projectInfo);
		generateMakefile(projectInfo);

		// Generate build folder
		logDirectoryCreation("build");
		std::filesystem::create_directory(projectInfo.path / "build");

		// Generate gitignore
		logFileGeneration(".gitignore");
		std::ofstream(projectInfo.path / ".gitignore") << "/build" << std::endl;

		// Generate license
		logFileGeneration("license");
		std::ofstream(projectInfo.path / "license");

		// Generate readme.md
		logFileGeneration("readme.md");
		std::ofstream(projectInfo.path / "readme.md") << "# " << projectInfo.name << std::endl;

		std::cerr << "All done!" << std::endl;
	}

	void generateMain(const Project &projectInfo)
	{
		logDirectoryCreation("src");
		std::filesystem::create_directory(projectInfo.path / "src");

		logFileGeneration("main.cpp");
		std::ofstream main(projectInfo.path / "src" / "main.cpp");

		main << "#include <iostream>" << std::endl
			 << std::endl
			 << "int main(int argc, char const *argv[])" << std::endl
			 << "{" << std::endl
			 << "\tstd::cout << \"Hello world!\" << std::endl;" << std::endl
			 << std::endl
			 << "\treturn 0;" << std::endl
			 << "}" << std::endl;
		main.close();
	}

	void generateMakefile(const Project &projectInfo)
	{
		logFileGeneration("makefile");
		std::ofstream makefile(projectInfo.path / "makefile");

		makefile << "projectName = " << projectInfo.name << std::endl
				 << "cppStandard = c++17" << std::endl
				 << std::endl
				 << "sourceFolder = src/" << std::endl
				 << "output = build/$(projectName)" << std::endl
				 << std::endl
				 << "objects = " << std::endl
				 << "main = $(sourceFolder)main.cpp" << std::endl
				 << std::endl
				 << "all: $(project-name)-main clean" << std::endl
				 << std::endl
				 << "$(project-name)-main: $(main) $(objects)" << std::endl
				 << "\tg++ -std=$(cppStandard) $(main) $(objects) -o $(output)" << std::endl
				 << std::endl
				 << "clean: " << std::endl
				 << "\trm *.o" << std::endl;

		makefile.close();
	}
} // namespace pjs