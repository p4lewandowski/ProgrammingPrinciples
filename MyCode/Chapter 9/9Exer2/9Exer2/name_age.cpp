#include "name_age.h"

namespace Nampai {

	void Name_pairs::read_names() {
		std::cout << "Please provide a list of names - end sequence with ;" << std::endl;
		std::string name;
		while (std::cin >> name) {
			if (name == ";")
				break;
			names.push_back(name);
		}
	}
	void Name_pairs::read_ages() {
		std::cout << "Please provide a list of ages for each name entered." << std::endl;

		int input;
		for (auto &iter : names)
		{
			std::cin >> input;
			ages.push_back(input);
		}
		std::cout << "Ages added." << std::endl;
	}

	const std::vector<std::string>& Name_pairs::get_names() const {
		return names;
	}

	const std::vector<int>& Name_pairs::get_ages() const {
		return ages;
	}

	void Name_pairs::update(std::vector<std::string> nam, std::vector<int> ag) {
		names = nam;
		ages = ag;
	}

	void Name_pairs::sort_data() {
		std::vector<std::string> presort = get_names();
		std::vector<int> age_presort = get_ages();

		std::vector<std::string> names = get_names();
		std::vector<int> ages = get_ages();


		std::sort(names.begin(), names.end());
		for (int i = 0; i < names.size(); i++) {
			for (int j = 0; j < presort.size(); j++) {
				if (presort[j] == names[i])
					ages[i] = age_presort[j];
			}
		}
		update(names, ages);

	}

	std::ostream& operator<<(std::ostream& os, Name_pairs& np)
	{
		std::map<std::string, int> comb;
		for (size_t i = 0; i < np.get_names().size(); i++)
			comb[np.get_names()[i]] = np.get_ages()[i];

		for (auto &pair : comb)
			os << pair.first << ' ' << pair.second << std::endl;

		return os;
	}

	bool operator==(const Name_pairs& a, const Name_pairs& b)
	{
		if (a.get_names().size() != b.get_names().size() || a.get_ages().size() != b.get_ages().size())
			return false;
		for (int i = 0; i < a.get_ages().size(); i++) {
			if (a.get_ages()[i] != b.get_ages()[i])
				return false;
		}
		for (int i = 0; i < a.get_names().size(); i++) {
			if (a.get_names()[i] != b.get_names()[i])
				return false;
		}

		return true;
	}
}