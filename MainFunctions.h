#pragma once
#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H
#include "IntroductionLinkedList.h"
#include <string>
#include <vector>

/*  Create a function that will add sentences to the linked list from a 
	specific file. Note that these sentences come with blanks denoting
	the spaces where specific character traits will be added. Also note
	that this function can be used anywhere within the program (as long
	as the appropriate header file has been included. */
void addOriginalSentencesToIntroductionLinkedList(IntroductionLinkedList &intro_scene);

#endif