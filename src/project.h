#pragma once

#include <filesystem>
#include <string>

namespace pjs
{
	struct Project
	{
	public:
		std::string name;
		std::filesystem::path path = std::filesystem::relative(".");
	};
} // namespace pjs