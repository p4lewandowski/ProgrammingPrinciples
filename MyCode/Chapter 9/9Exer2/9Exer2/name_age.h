#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

namespace Nampai {

	class Name_pairs {

	private:
		std::vector<std::string> names;
		std::vector<int> ages;

	public:
		void read_names();
		void read_ages();
		void sort_data();
		void update(std::vector<std::string> nam, std::vector<int> ag);
		const std::vector<std::string>& get_names() const;
		const std::vector<int>& get_ages() const;
	};

	std::ostream& operator<<(std::ostream& os, Name_pairs& np);
	bool operator==(const Name_pairs& np1, const Name_pairs& np2);

}