#include "LittleRed.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

/*  Set the name of the protagonist. */
void LittleRed::setName() {

	name = "Little Red";

}

/*  Set a random age for the protagonist (from 
	6 to 17). */
void LittleRed::setAge() {

	srand(time(NULL));

	age = rand() % 12 + 6;

}

/*  Set the place of residence for the protagnist. */
void LittleRed::setPlaceOfResidence() {

	srand(time(NULL));

	std::ifstream places_file;
	places_file.open("RedPlacesOfResidence.txt");

	if (places_file.fail()) {

		std::cout << "ERROR: The file could not be read." << std::endl;

		places_file.close();

		return;

	}

	std::vector<std::string> places_vector;
	std::string place;

	while (std::getline(places_file, place)) {

		places_vector.push_back(place);

	}

	places_file.close();

	int random_index = rand() % places_vector.size();
	place_of_residence = places_vector[random_index];

	places_vector.clear();

}

/*  Set the Boolean value for her parents to "true." */
void LittleRed::setParents() {

	parents = true;

}

/*  Add certain words from a file to a vector. */
void LittleRed::addElementsToVector(std::vector<std::string> &vect, std::string filename) {

	srand(time(NULL));

	std::ifstream elements_file;
	elements_file.open(filename);

	if (elements_file.fail()) {

		std::cout << "ERROR: The file could not be read." << std::endl;

		elements_file.close();

		return;

	}

	std::vector<std::string> tmp_vector;
	std::string element;

	while (std::getline(elements_file, element)) {

		tmp_vector.push_back(element);

	}

	elements_file.close();

	int random_index_1 = rand() % tmp_vector.size();
	int random_index_2 = rand() % tmp_vector.size();
	int random_index_3 = rand() % tmp_vector.size();

	while ((random_index_2 == random_index_1) || (random_index_3 == random_index_2) || (random_index_3 == random_index_1)) {

		random_index_2 = rand() % tmp_vector.size();
		random_index_3 = rand() % tmp_vector.size();

	}

	vect.push_back(tmp_vector[random_index_1]);
	vect.push_back(tmp_vector[random_index_2]);
	vect.push_back(tmp_vector[random_index_3]);

	tmp_vector.clear();

}

/*  Set the adjectives for Little Red using the previously 
	examined method. */
void LittleRed::setCharacterDescriptions() {

	std::string descriptions_filename = "RedCharacterDescriptions.txt";

	addElementsToVector(character_descriptions, descriptions_filename);

}

/*  Set the objects Little Red likes using the addElementsToVector
	method. */
void LittleRed::setLikes() {

	std::string likes_filename = "RedLikes.txt";

	addElementsToVector(likes, likes_filename);

}

/*  Select the decisions Little Red makes by drawing them
	from the appropriate file. */
void LittleRed::setDecisions() {

	std::ifstream decisions_file;
	decisions_file.open("RedDecisions.txt");

	if (decisions_file.fail()) {

		std::cout << "ERROR: The file could not be read." << std::endl;

		decisions_file.close();

		return;

	}

	std::string search_phrase = "her grandmother";
	bool voluntary_decision = false;

	for (std::string s : likes) {

		if (s == search_phrase) {

			voluntary_decision = true;

		}

	}

	std::vector<std::string> tmp_vector;
	std::string element;

	while (std::getline(decisions_file, element)) {

		tmp_vector.push_back(element);

	}

	decisions_file.close();

	for (int i = 0; i < tmp_vector.size(); i++) {

		if (voluntary_decision && (tmp_vector.at(i).find("decided") != -1)) {

			decisions.push_back(tmp_vector.at(i));

		}

		if (!voluntary_decision && (tmp_vector.at(i).find("asked") != -1)) {

			decisions.push_back(tmp_vector.at(i));

		}

	}

	decisions.push_back(tmp_vector.back());

}

/*  Display Little Red's data in a record-like format. */
void LittleRed::displayCharacterData() {

	std::cout << "\n#####################################################" << std::endl;
	std::cout << "\nCURRENT DATA FOR \"" << name << "\"" << std::endl;
	std::cout << "\nAge: " << age << std::endl;
	std::cout << "\nPlace of Residence: " << place_of_residence << std::endl;
	std::cout << "\nParents: ";

	if (parents == true) {

		std::cout << "Yes" << std::endl;

	}
	else {

		std::cout << "No" << std::endl;

	}

	std::cout << "\nCharacter Descriptions:" << std::endl;

	for (std::string c_d : character_descriptions) {

		std::cout << "\t" << c_d << std::endl;

	}

	std::cout << "\nLikes:" << std::endl;

	for (std::string l : likes) {

		std::cout << "\t" << l << std::endl;

	}

	std::cout << "\nDecisions:" << std::endl;

	for (std::string d : decisions) {

		std::cout << "\t" << d << std::endl;

	}

	std::cout << "\n#####################################################" << std::endl;

}