#include "name_age.h"

using namespace std;

int main()
{
	Nampai::Name_pairs np;
	np.read_names();
	np.read_ages();
	std::cout << np << endl;
	np.sort_data();
	std::cout << np << endl;


	Nampai::Name_pairs na;
	na.read_names();
	na.read_ages();
	na.sort_data();
	std::cout << (np == na) ? "1" : "0";


}