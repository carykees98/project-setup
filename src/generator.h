#pragma once

#include <string>

#include "project.h"

namespace pjs
{
	void createProject(const Project &projectInfo);

	void generateMain(const Project &projectInfo);

	void generateMakefile(const Project &projectInfo);
} // namespace pjs