#pragma once
#ifndef INTRODUCTIONLINKEDLIST_H
#define INTRODUCTIONLINKEDLIST_H
#include "IntroductionNode.h"
#include "LittleRed.h"
#include <string>

/*  Create a class that will store a linked list of sentences
	pertaining to the introduction of the story. */
class IntroductionLinkedList {

private:
	IntroductionNode *head;
public:
	IntroductionLinkedList();
	~IntroductionLinkedList();
	bool isEmpty();
	void insertOriginalSentence(int t, std::string s);
	void substituteRedWordsIntoSentences(LittleRed l_r);
	void addRedVectorMemberSentences(IntroductionNode *&curr, std::vector<std::string> vect, int loc, std::string placeholder);
	void addRedUserInputtedSentences(LittleRed &l_r, enum little_red_enum type, std::string new_word);
	void addRedDecisionSentences(LittleRed l_r);
	void displayIntroduction();

};

#endif