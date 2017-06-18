/**************************************************************************************
Filename:          Name.cpp
Version:           1.2
Author:            Tim Osse
Student No:        040585009
Lab Sect:          310
Assignment #:      3
Assignment name:   CST8219 Assignment 3
Due Date:          Decemeber 02, 2012
Submission Date:   Decemeber 02, 2012
Professor:         Andrew Tyler
Purpose:           Creates the name objects
**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define NULL 0
#include <string.h>
#include <iostream>
using namespace std;
#include <fstream>
#include "Name.h"

/********************************************************************
 Function name:	Name
 Purpose:		Default constructor
 In parameters:	none
 Out parameters:none
 Version:		1.1
 Author:		Tim Osse
 **********************************************************************/
Name::Name(char* fName, char* lName){
   
	if(fName == NULL){
		this->m_firstName = NULL;
	}
	else{
		this->m_firstName = new char[strlen(fName)+1];
		strcpy(m_firstName, fName);
	}
	if(lName == NULL){
		this->m_lastName = NULL;
	}
	else{
		this->m_lastName = new char[strlen(lName)+1];
		strcpy(m_lastName, lName);
	}
}

/********************************************************************
 Function name:	Name(Name& R)
 Purpose:		Name copy constructor
 In parameters:	Name& R
 Out parameters:none
 Version:		1.0
 Author:		Tim Osse
 **********************************************************************/
Name::Name(Name& R){
	if(R.m_firstName != NULL){
		this->m_firstName = new char[strlen(R.m_firstName)+1];
		strcpy(this->m_firstName, R.m_firstName);
	}
	if(R.m_lastName != NULL){
		this->m_lastName = new char[strlen(R.m_lastName)+1];
		strcpy(this->m_lastName, R.m_lastName);
	}
}
/********************************************************************
 Function name:	operator=(Name& R)
 Purpose:		Overloaded assignment operator for name
 In parameters:	Name& R
 Out parameters:none
 Version:		1.0
 Author:		Tim Osse
 **********************************************************************/
Name& Name::operator=(Name& R){
	
	if(this == &R){
		return *this;
	}
	if(this->m_firstName != NULL){
		delete[] this->m_firstName;
	}
	if(this->m_lastName != NULL){
		delete[] this->m_lastName;
	}
	if(R.m_firstName != NULL){
		this->m_firstName = new char[strlen(R.m_firstName)+1];
		strcpy(this->m_firstName, R.m_firstName);
	}
	if(R.m_lastName != NULL){
		this->m_lastName = new char[strlen(R.m_lastName)+1];
		strcpy(this->m_lastName, R.m_lastName);
	}
	return *this;
}

/********************************************************************
 Function name:	Student
 Purpose:		Destructor for the Name
 In parameters:	none
 Out parameters:none
 Version:		1.0
 Author:		Tim Osse
 **********************************************************************/
Name::~Name(){

   if(m_firstName != NULL){
		delete [] m_firstName;
   }
   
   if(m_lastName != NULL){
		delete [] m_lastName;
	}
}

ofstream& operator<<(ofstream& output,Name& name){

	output << name.m_firstName << " ";
	output << name.m_lastName << " ";
	return output;
}

