#include "MainFunctions.h"
#include "IntroductionLinkedList.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>

/*  Add the original sentences from its respective file to a temporary vector. 
	Randomly shuffle those sentences so the overall ordering is different
	during each generation of the story. Finally, store those shuffled sentences
	into the linked list. */
void addOriginalSentencesToIntroductionLinkedList(IntroductionLinkedList &intro_scene) {

	srand(time(NULL));

	std::ifstream introduction_file;
	introduction_file.open("RedIntroductorySentences.txt");

	if (introduction_file.fail()) {

		std::cout << "ERROR: The file could not be read." << std::endl;

		introduction_file.close();

		return;

	}

	std::vector<std::string> intro_vector;
	std::string intro_sentence;

	while (std::getline(introduction_file, intro_sentence)) {

		intro_vector.push_back(intro_sentence);

	}

	introduction_file.close();

	std::vector<std::string> tmp_vector;
	tmp_vector = intro_vector;

	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::shuffle((tmp_vector.begin() + 1), tmp_vector.end(), std::default_random_engine(seed));

	for (std::string tmp_s : tmp_vector) {

		for (int i = 0; i < intro_vector.size(); i++) {

			if (intro_vector[i] == tmp_s) {

				intro_scene.insertOriginalSentence(i, tmp_s);

			}

		}

	}

	tmp_vector.clear();

}