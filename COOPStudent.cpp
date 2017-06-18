/**************************************************************************************
Filename:          COOPStudent.cpp
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
#include <fstream>
using namespace std;
#include "Name.h"
#include "Student.h"
#include "COOPStudent.h"

COOPStudent::COOPStudent(char* fname,char* lname,int id,float mark, PlacementStatus placement):Student(fname,lname,id,mark){

	this->m_status = placement;
}

COOPStudent& COOPStudent::operator=(COOPStudent& rec){
	this->m_status=rec.m_status;
	return *this;
}

void COOPStudent::Report(){
	cout<<"COOP Student"<<endl;
	cout<<"Placement Status: ";

	switch(this->m_status){
	case UNPLACED:
		cout<< "unplaced"; break;
	case PLACED:
		cout<< "placed"; break;
	case SUSPENDED:
		cout<< "suspend"; break;
	case PENDING:
		cout<< "pending"; break;
	}
	cout<<endl;

	this->m_name.Report();
	cout<< "id = "<< this->m_id;
	cout<< "; mark = "<< this->m_mark<<endl;
	cout<<endl;
}
