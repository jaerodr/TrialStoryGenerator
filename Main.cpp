/*  Julie Rodriguez - 2019
	Code for Senior Research Project
	A Simulated Automated Story Generator 
	(using "The Little Red Riding Hood") */
#include "LittleRed.h"
#include "IntroductionLinkedList.h"
#include "MainFunctions.h"
#include "Enums.h"
#include <iostream>
#include <string>
#include <vector>

int main() {

	/*  Create two objects--one for the LittleRed class and another
		for the IntroductionLinkedList class. */
	LittleRed little_red;
	IntroductionLinkedList little_red_introduction;

	/*  Set the starting descriptions for the story's main
		character. */
	little_red.setAge();
	little_red.setName();
	little_red.setParents();
	little_red.setPlaceOfResidence();
	little_red.setCharacterDescriptions();
	little_red.setLikes();
	little_red.setDecisions();

	/*  Create a variable to hold the response the user must
		enter if they wish to either add more information
		to Little Red or leave her as she is. */
	char add_more_info_response;

	std::cout << "\n-------------------------------------------------------------------------------------------------" << std::endl;

	/*  Create the opening paragraph to the story. */
	addOriginalSentencesToIntroductionLinkedList(little_red_introduction);
	little_red_introduction.substituteRedWordsIntoSentences(little_red);

	/*  Display the opening paragraph to the user. */
	std::cout << "\nHere is the story so far:" << std::endl;
	little_red_introduction.displayIntroduction();

	/*  Ask the user if he would like to enter additional information
		regarding Little Red. */
	std::cout << "\nWould you like to add any additional information about this character (Y/N)? ";
	std::cin >> add_more_info_response;

	if (toupper(add_more_info_response) == 'Y') {

		std::cout << "\nWould you like to add another character description (Y/N)? ";
		std::cin >> add_more_info_response;

		std::cin.ignore();

		if (toupper(add_more_info_response) == 'Y') {

			std::string adjective;

			std::cout << "Enter another adjective for Little Red: ";
			getline(std::cin, adjective);

			little_red_introduction.addRedUserInputtedSentences(little_red, RED_CHARACTER_DESCRIPTIONS, adjective);

		}

		std::cout << "\nWould you like to add something else the character likes (Y/N)? ";
		std::cin >> add_more_info_response;

		std::cin.ignore();

		if (toupper(add_more_info_response) == 'Y') {

			std::string like;

			std::cout << "Enter something else Little Red likes: ";
			getline(std::cin, like);

			little_red_introduction.addRedUserInputtedSentences(little_red, RED_LIKES, like);

		}

	}

	/*  Display the updated data pertaining to Little Red. */
	little_red.displayCharacterData();

	/*  Add Little Red's decisions to the opening paragraph. */
	little_red_introduction.addRedDecisionSentences(little_red);
	
	/*  Display the updated paragraph. */
	std::cout << "\nHere is the updated story:" << std::endl;
	little_red_introduction.displayIntroduction();

	std::cout << "\n-------------------------------------------------------------------------------------------------" << std::endl;
	
}