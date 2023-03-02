#pragma once

#include <string>

#include "project.h"

namespace pjs
{

	void createProject(Project &projectInfo);

	void generateMain(Project &projectInfo);

	void generateMakefile(Project &projectInfo);

} // namespace pjs