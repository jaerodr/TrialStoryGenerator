#pragma once
#ifndef LITTLERED_H
#define LITTLERED_H
#include <string>
#include <vector>

/*  Create a class that will contain all information that is
	relevant to Little Red. */
class LittleRed {

private:
	std::string name;
	int age;
	std::string place_of_residence;
	bool parents;
	std::vector<std::string> character_descriptions;
	std::vector<std::string> likes;
	std::vector<std::string> decisions;
	friend class IntroductionLinkedList;
public:
	void setName();
	void setAge();
	void setPlaceOfResidence();
	void setParents();
	void addElementsToVector(std::vector<std::string> &vect, std::string filename);
	void setCharacterDescriptions();
	void setLikes();
	void setDecisions();
	void displayCharacterData();

};

#endif LITTLERED_H