/**************************************************************************************
Filename:          Student.cpp
Version:           1.2
Author:            Tim Osse
Student No:        040585009
Lab Sect:          310
Assignment #:      3
Assignment name:   CST8219 Assignment 3
Due Date:          December 02, 2012
Submission Date:   December 02, 2012
Professor:         Andrew Tyler
Purpose:           Creates the student objects
**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
using namespace std;
#include "Name.h"
#include "Student.h"

/********************************************************************
 Function name:	Student(Student& R)
 Purpose:		copy constructor
 In parameters:	Student& R
 Out parameters:none
 Version:		1.1
 Author:		Tim Osse
 **********************************************************************/
Student::Student(Student& R){
	this->m_name = R.m_name;
	this->m_id = R.m_id;
	this->m_mark = R.m_mark;
}
/********************************************************************
 Function name:	operator=(Student& R)
 Purpose:		Overloaded assignment operator for student
 In parameters:	Student& R
 Out parameters:none
 Version:		1.0
 Author:		Tim Osse
 **********************************************************************/
Student& Student::operator=(Student& R){
	this->m_name = R.m_name;
	this->m_id = R.m_id;
	this->m_mark = R.m_mark;
	return *this;
}
/********************************************************************
 Function name:	operator>(Student& R)
 Purpose:		overloaded comparison operator
 In parameters:	Student& R
 Out parameters:none
 Version:		1.0
 Author:		Tim Osse
 **********************************************************************/
bool Student::operator>(Student& R){

	return(this->m_mark > R.m_mark);
}
/********************************************************************
 Function name:	operator<(Student& R)
 Purpose:		overloaded comparison operator
 In parameters:	Student& R
 Out parameters:none
 Version:		1.0
 Author:		Tim Osse
 **********************************************************************/
bool Student::operator<(Student& R){

	return(this->m_mark < R.m_mark);
}
/********************************************************************
 Function name:	operator==(Student& R)
 Purpose:		overloaded comparison operator
 In parameters:	Student& R
 Out parameters:none
 Version:		1.0
 Author:		Tim Osse
 **********************************************************************/
bool Student::operator==(Student& R){

	return(this->m_mark == R.m_mark);
}


ofstream& operator<<(ofstream& fout, Student& RS){

	fout<<RS.m_name << " ";
	fout<<RS.m_id << " ";
	fout<<RS.m_mark << " ";
	return fout;
}