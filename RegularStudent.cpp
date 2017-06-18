/**************************************************************************************
Filename:          RegularStudent.cpp
Version:           1.1
Author:            Tim Osse
Student No:        040585009
Lab Sect:          310
Assignment #:      3
Assignment name:   CST8219 Assignment 3
Due Date:          December 02, 2012
Submission Date:   December 02, 2012
Professor:         Andrew Tyler
Purpose:           
**************************************************************************************/
#include <iostream>
using namespace std;
#include "Name.h"
#include "Student.h"
#include "RegularStudent.h"

RegularStudent::RegularStudent(char* fname,char* lname,int id,float mark, CompletionStatus status):Student(fname,lname,id,mark){

	this->m_status = status;
}

RegularStudent& RegularStudent::operator=(RegularStudent& rec){
	this->m_status=rec.m_status;
	return *this;
}

void RegularStudent::Report(){
		
		cout << "Regular Student" << endl;
		cout <<"Completion Status: ";

		switch(this->m_status){
			case JUST_STARTED: 
				cout<< "just started"; break;
			case ONE_SIXTH:
				cout<< "1/6"; break;
			case ONE_THIRD:
				cout<< "2/6"; break;
			case HALF:
				cout<< "3/6"; break;
			case TWO_THIRDS:
				cout<< "4/6"; break;
			case FIVE_SIXTH:
				cout<< "5/6"; break;
			case COMPLETE:
				cout<< "complete"; break;
		}
		cout<< endl;
		this->m_name.Report();
		cout<< "id = "<< this->m_id;
		cout<< "; mark = "<< this->m_mark<<endl;
		cout<<endl;
}
