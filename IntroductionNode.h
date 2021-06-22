#pragma once
#ifndef INTRODUCTIONNODE_H
#define INTRODUCTIONNODE_H
#include <string>

/*  Create a class that will hold each sentential node within the
	introductory paragraph. */
class IntroductionNode {

private:
	int sentence_type;
	std::string sentence;
	IntroductionNode *next;
	friend class IntroductionLinkedList;

};

#endif