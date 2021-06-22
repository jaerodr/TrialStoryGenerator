#include "IntroductionNode.h"
#include "IntroductionLinkedList.h"
#include "LittleRed.h"
#include "Enums.h"
#include <iostream>
#include <fstream>

/*  Set the linked list's "head" pointer to NULL. */
IntroductionLinkedList::IntroductionLinkedList() {

	head = NULL;

}

/*  Remove all the sentences from the linked list at the
	end of the program. */
IntroductionLinkedList::~IntroductionLinkedList() {

	if (head == NULL) {

		std::cout << "\nNothing happened in this scene." << std::endl;

		return;

	}

	IntroductionNode *tmp = head;

	while (tmp != NULL) {

		head = head->next;
		delete tmp;
		tmp = head;

	}

	head = NULL;

	std::cout << "\nThe scene has been cleared." << std::endl;

}

/*  Check if the linked list is devoid of introductory
	sentences. */
bool IntroductionLinkedList::isEmpty() {

	if (head == NULL) {

		return true;

	}
	else {

		return false;

	}

}

/*  Insert the sentences from the file into the linked list. Note that
	this class method words alongside the lone function listed in
	MainFunctions.h and defined in MainFunctions.cpp. */
void IntroductionLinkedList::insertOriginalSentence(int t, std::string s) {

	if (isEmpty()) {

		IntroductionNode *tmp = new IntroductionNode;
		tmp->sentence_type = t;
		tmp->sentence = s;
		head = tmp;

	}
	else {

		IntroductionNode *current = new IntroductionNode;
		current = head;

		while (current->next != NULL) {

			current = current->next;

		}

		IntroductionNode *tmp = new IntroductionNode;
		tmp->sentence_type = t;
		tmp->sentence = s;
		tmp->next = NULL;
		current->next = tmp;

	}

}

/*  Substitute a random selection of words form a separate list into
	the blank spaces of the sentences. Note that this method is used
	in conjunction with addRedVectorMemberSentences. */
void IntroductionLinkedList::substituteRedWordsIntoSentences(LittleRed l_r) {

	IntroductionNode *current = new IntroductionNode;
	current = head;

	std::string placeholder = "_";
	std::string replacement;
	int loc;

	while (current != NULL) {

		loc = current->sentence.find(placeholder);

		if (current->sentence_type == 0) {

			replacement = l_r.name;
			current->sentence.replace(loc, placeholder.length(), replacement);
			
		}
		else if (current->sentence_type == RED_AGE) {

			replacement = std::to_string(l_r.age);
			current->sentence.replace(loc, placeholder.length(), replacement);

		}
		else if (current->sentence_type == RED_PLACE_OF_RESIDENCE) {

			replacement = l_r.place_of_residence;
			current->sentence.replace(loc, placeholder.length(), replacement);

		}
		else if (current->sentence_type == RED_PARENTS) {

			if (l_r.parents) {

				replacement = "parents";
				current->sentence.replace(loc, placeholder.length(), replacement);

			}

		}

		current = current->next;

	}
	
	current = head;

	while (current != NULL) {

		loc = current->sentence.find(placeholder);

		if (current->sentence_type == RED_CHARACTER_DESCRIPTIONS) {

			addRedVectorMemberSentences(current, l_r.character_descriptions, loc, placeholder);

		}
		else if (current->sentence_type == RED_LIKES) {

			addRedVectorMemberSentences(current, l_r.likes, loc, placeholder);

		}

		current = current->next;

	}

}

/*  Simplify the substitutions performed in the previous method. */
void IntroductionLinkedList::addRedVectorMemberSentences(IntroductionNode *&curr, std::vector<std::string> vect, int loc, std::string placeholder) {

	std::string replacement;

	int sentence_type = curr->sentence_type;
	std::string sentence = curr->sentence;

	IntroductionNode *tmp = new IntroductionNode;
	tmp = head;

	replacement = vect.front();
	curr->sentence.replace(loc, placeholder.length(), replacement);

	for (std::string s : vect) {

		if (s != vect.front()) {

			IntroductionNode *next_node = new IntroductionNode;
			next_node->sentence_type = sentence_type;
			next_node->sentence = sentence;

			while (tmp->next->sentence_type != sentence_type) {

				tmp = tmp->next;

			}

			next_node->sentence.replace(loc, placeholder.length(), s);

			next_node->next = tmp->next;
			tmp->next = next_node;

			tmp = head;

		}

	}

}

/*  Add new sentences according to any additions that have been
	made by the user. */
void IntroductionLinkedList::addRedUserInputtedSentences(LittleRed &l_r, enum little_red_enum type, std::string new_word) {

	std::string extracted_sentence;
	int current_loc;
	int word_loc;
	std::string word;

	IntroductionNode *tmp = new IntroductionNode;
	tmp = head;

	IntroductionNode *next_node = new IntroductionNode;

	std::vector<std::string> tmp_vector;

	std::ifstream original_file;
	std::ofstream append_file;
	std::string check_original_file_words;
	bool found_in_file = false;

	if (type == RED_CHARACTER_DESCRIPTIONS) {

		tmp_vector = l_r.character_descriptions;

		for (std::string s : tmp_vector) {

			if (s == new_word) {

				std::cout << "\nThat word was already used to describe her." << std::endl;
				return;

			}

		}

		original_file.open("RedCharacterDescriptions.txt");

		while (std::getline(original_file, check_original_file_words) && !found_in_file) {

			if (check_original_file_words == new_word) {
				
				found_in_file = true;
				original_file.close();

			}

		}

		if (!found_in_file) {

			append_file.open("RedCharacterDescriptions.txt", std::ios::app);
			append_file << "\n" << new_word;

		}

		l_r.character_descriptions.push_back(new_word);

	}
	
	if (type == RED_LIKES)  {
		
		tmp_vector = l_r.likes;

		for (std::string s : tmp_vector) {

			if (s == new_word) {

				std::cout << "\nShe already likes that." << std::endl;
				return;

			}

		}

		original_file.open("RedLikes.txt");

		while (std::getline(original_file, check_original_file_words) && !found_in_file) {

			if (check_original_file_words == new_word) {

				found_in_file = true;
				original_file.close();

			}

		}

		if (!found_in_file) {

			append_file.open("RedLikes.txt", std::ios::app);
			append_file << "\n" << new_word;

		}

		l_r.likes.push_back(new_word);

	}

	append_file.close();

	while (tmp->next->sentence_type != type) {

		tmp = tmp->next;

	}

	extracted_sentence = tmp->next->sentence;

	for (std::string s : tmp_vector) {

		current_loc = extracted_sentence.find(s);

		if (current_loc != -1) {

			word = s;
			word_loc = current_loc;

		}

	}

	next_node->sentence_type = type;
	next_node->sentence = extracted_sentence;
	next_node->sentence.replace(word_loc, word.length(), new_word);
	next_node->next = tmp->next;
	tmp->next = next_node;

}

/*  Add the final "decision" sentences to the introductory 
	paragraph. For instance, if Little Red personally
	likes her grandmother, then she will decide to visit
	her relative without being told to do so. Otherwise,
	her parents will ask her to visit her grandmother. */
void IntroductionLinkedList::addRedDecisionSentences(LittleRed l_r) {

	IntroductionNode *current = new IntroductionNode;
	current = head;

	while (current->next != NULL) {

		current = current->next;

	}

	IntroductionNode *tmp = new IntroductionNode;
	tmp->sentence_type = RED_DECISIONS;
	tmp->sentence = l_r.decisions.at(0);

	tmp->next = NULL;
	current->next = tmp;

	int exclude_grandmother_from_basket;

	std::string placeholder = "_";
	int loc = l_r.decisions.at(1).find(placeholder);
	std::string substituted_sentence = l_r.decisions.at(1);

	for (std::string s : l_r.likes) {

		exclude_grandmother_from_basket = s.find("grandmother");

		if (exclude_grandmother_from_basket == -1) {

			substituted_sentence = substituted_sentence.replace(loc, placeholder.length(), s);

			insertOriginalSentence(RED_DECISIONS, substituted_sentence);

			substituted_sentence = l_r.decisions.at(1);

		}

	}

}

/*  Display all the sentences in the linked list. */
void IntroductionLinkedList::displayIntroduction() {

	if (head == NULL) {

		std::cout << "\nNothing happens in this scene." << std::endl;

	}
	else {

		IntroductionNode *current = new IntroductionNode;
		current = head;

		std::cout << "\n*************************************************************" << std::endl;
		std::cout << std::endl;

		while (current != NULL) {

			std::cout << current->sentence << std::endl;

			current = current->next;

		}

		std::cout << "\n*************************************************************" << std::endl;

	}

}