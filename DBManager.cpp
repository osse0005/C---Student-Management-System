/**************************************************************************************
Filename:          DBManager.cpp
Version:           1.2
Author:            Tim Osse
Student No:        040585009
Lab Sect:          310
Assignment #:      3
Assignment name:   CST8219 Assignment 3
Due Date:          December 02, 2012
Submission Date:   December 02, 2012
Professor:         Andrew Tyler
Purpose:           To manage memory allocation for a database of student records.
**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <typeinfo>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
#include "Name.h"
#include "Student.h"
#include "RegularStudent.h"
#include "COOPStudent.h"
#include "DBManager.h"

/********************************************************************
Function name:	DBManager
Purpose:		default constructor
In parameters:	none
Out parameters:none
Version:		1.1
Author:		Tim Osse
**********************************************************************/
DBManager::DBManager():
	m_ppRecords(NULL),m_numRecords(0),m_FileName(NULL){
}

/********************************************************************
Function name:	DBManager
Purpose:		Copy constructor for the DBManager
In parameters:	R
Out parameters:none
Version:		1.1
Author:		Tim Osse
**********************************************************************/
DBManager::DBManager(DBManager& R){

	int i, numRecords;
	numRecords = R.m_numRecords;
	this->m_ppRecords = new Student*[numRecords];

	for(i=0; i < numRecords; i++){
		if(dynamic_cast<COOPStudent*>(R.m_ppRecords[i]) != NULL){
			this->m_ppRecords[i] = new COOPStudent(* dynamic_cast<COOPStudent*>(R.m_ppRecords[i]));
		}
		else
			this->m_ppRecords[i] = new RegularStudent(* dynamic_cast<RegularStudent*>(R.m_ppRecords[i]));
	}

	this->m_numRecords = numRecords;
	this->m_FileName = new char[strlen(R.m_FileName)+1];
	strcpy(this->m_FileName, R.m_FileName);
}

/********************************************************************
Function name:	~DBManager
Purpose:		Destructor for the DBManager
In parameters:	none
Out parameters:none
Version:		1.0
Author:		Tim Osse
**********************************************************************/
DBManager::~DBManager() {

	int i;
	for(i=0;i<m_numRecords; ++i){
		delete m_ppRecords[i];
	}
	delete [] m_ppRecords;
	delete [] m_FileName;
}

/********************************************************************
Function name:	operator[]
Purpose:		overloaded indexing operator
In parameters:	none
Out parameters:none
Version:		1.0
Author:		Tim Osse
**********************************************************************/
Student*& DBManager::operator[] (int index){

	return (this->m_ppRecords[index]);
}

/**************************************************************************************
Function name:  ReadFile
Purpose:	    Opens file reads records and stores them in memory 
In parameters:  none
Out parameters: none
Version:        1.2
Author:         Tim Osse
**************************************************************************************/
void DBManager::ReadFile(void) {
	char file[20];	
	char line[128];
	int tID = 0; /*temp student id value*/
	float tMark = 0.0; /*temp student mark value*/
	char tempfName[20]; /*temp holder for first name string*/
	char templName [20]; /*temp holder for last name string*/
	int i = 0; /*index to loop through StudentRecords array*/

	ifstream input;
	ofstream out;
	cout << "OPEN FILE" <<endl;
	cout << "Please enter the name of the file to open: ";
	fflush(stdin);
	cin >> file; //file name
	m_FileName = new char[strlen(file)+1];
	strcpy(m_FileName, file);
	(input.open(m_FileName,ifstream::in));

	if (input.good()){/*if file exists*/
		cout << "READING RECORDS INTO MEMORY" << endl;
		while(input.getline(line, 100)){/*finds how pre-existing objects in the file there are*/
			++m_numRecords;
		}
		
		cout<<"There are "<<m_numRecords<<" records\n"<<endl;
		m_ppRecords = new Student*[m_numRecords];/*new student object created*/

		input.clear();
		input.seekg(0, ios::beg);/*go to the start of the file*/

		for(i = 0; i<m_numRecords; i++){
			input>>tempfName>>templName>>tID>>tMark;/*gets file data*/
			if(tMark <= 80){
				m_ppRecords[i] = new RegularStudent(tempfName, templName, tID, tMark);/*passes the file data into the objects*/
			}
			else
				m_ppRecords[i] = new COOPStudent(tempfName, templName, tID, tMark);/*passes the file data into the objects*/
		}
	}
	else{/*file doesnt exist*/
		cout<<"File doesn't exist - creating file"<<endl;
		cout<<" "<<endl;
		input.open(m_FileName, ofstream::app);
	}

}//DONE
/**************************************************************************************
Function name:  ListStudents
Purpose:        Displays all records on screen 
In parameters:  void
Out parameters: void
Version:        1.0
Author:         Tim Osse
**************************************************************************************/
void DBManager::ListRecords(void) {
	int i=0;
	cout << "LIST RECORDS IN MEMORY" << endl;
	if (m_numRecords == 0) {
		cout << "No records\n" << endl;
		return;
	}
	for (i = 0; i < m_numRecords; ++i) {
		cout<<"Student #"<<i+1<<endl;
		m_ppRecords[i]->Report();
		cout << endl;
	}
	cout<<endl;
}
/**************************************************************************************
Function name:  AddStudent
Purpose:        Adds one record input by user to the database 
In parameters:  void
Out parameters: void
Version:        1.2.2
Author:         Tim Osse
**************************************************************************************/
void DBManager::AddRecord(void) {
	
	int i; // loop counter
	char tempfName[80]; // temp first Name
	char templName[80]; // temp last Name
	int tID; // temp id
	float tMark; // temp mark
	bool looping = false; // loop switch
	Student** oldStudents; // old array
	Student** newStudents; // new array
	
	// if there are no records, build one
	if( m_ppRecords == NULL ){
		m_numRecords = 0;
		m_ppRecords = new Student*[1];
	}
	else {
		
		oldStudents = m_ppRecords;
		newStudents = new Student*[m_numRecords+1];

		for( i=0; i<m_numRecords; ++i )
			newStudents[i] = oldStudents[i];
		
		m_ppRecords = newStudents;
		delete []oldStudents;
	}

	++m_numRecords;

	cout << "Please enter First Name: ";
	cin >> tempfName;

	cout << "Please enter Last Name: ";
	cin >> templName;

	cout << "Please enter ID: ";
	cin >> tID;

	cout << "Please enter mark: ";
	cin >> tMark;

	if( tMark > 80.0 ){ // if mark is higher than COOP student
		// COOPStudent
		m_ppRecords[m_numRecords-1] = new COOPStudent( tempfName, templName, tID, tMark );
		cout << "Added a COOP Student" << endl;
	}
	else{ // RegularStudent
		m_ppRecords[m_numRecords-1] = new RegularStudent( tempfName, templName, tID, tMark );
		cout << "Added a Regular Student" << endl;
	}

	cout << "Number of Records = " << m_numRecords << endl;
	cout << endl << endl;
}

/**************************************************************************************
Function name:  HighestMark
Purpose:		Finds the record entry with the highest mark 
In parameters:  void
Out parameters: void
Version:        1.0
Author:         Andrew Tyler
**************************************************************************************/
void DBManager::HighestMark(void){

	DBManager DBM = *this;
	Student* highest = DBM[0];

	for(int i=0;i<m_numRecords;i++){
		if(*DBM[i]>*highest){
			highest=DBM[i];
		}
	}
	cout<<"Student with highest mark is:"<<endl;
	highest->Report();
}//end function highestmark

/**************************************************************************************
Function name:  LowestMark
Purpose:		Finds the record entry with the lowest mark 
In parameters:  none
Out parameters: 0 for successful execution
Version:        1.0
Author:         Tim Osse
**************************************************************************************/
void DBManager::LowestMark(void){

	DBManager DBM = *this;
	Student* lowest = DBM[0];

	for(int i=0;i<m_numRecords;i++){
		if(*DBM[i]<*lowest){
			lowest=DBM[i];
		}
	}
	cout<<"Student with lowest mark is:"<<endl;
	lowest->Report();
}

/**************************************************************************************
Function name:  OverwriteRecordByID
Purpose:		Overwrites student record, chosen by id 
In parameters:  void
Out parameters: void
Version:        1.1.4
Author:         Tim Osse
**************************************************************************************/
void DBManager::OverwriteRecordByID(void){
	bool coop;
	int i;
	Student * student = NULL;
	char tempfName[80], templName[80];
	int tempID;
	float tempMark;
	int status; // temp status


	cout << "Please enter the id of the student to overwrite: ";
	cin >> tempID;

	for( i=0; i<m_numRecords; ++i )
		if( m_ppRecords[i]->GetID() == tempID ){
			student = m_ppRecords[i];
			break;
		}
		// if record not found
		if( student == NULL ){
			cout << "Student record not found";
			cout << endl << endl;
			return;
		}

		if( dynamic_cast<COOPStudent*>( student ) != NULL ){
			coop = true;
			cout << "Identified as COOP Student" << endl;
		}
		else {
			coop = false;
			cout << "Identified as Regular Student" << endl;
		}
		cout<<"Please enter the new first name: ";
		cin>> tempfName;
		cout<<"Please enter the new last name: ";
		cin>> templName;
		cout<<"Please enter the new id: ";
		cin>> tempID;
		cout<<"Please enter the new mark: ";
		cin>> tempMark;

		// Create new student over old student

		if( coop == true ){
			if( tempMark > 80 ){
				cout << "COOP Student remains COOP Student" << endl;


				cout << "Please enter the integer for the placement status:" << endl;
				cout << "(unplaced = 0, placed = 1, suspended = 2, pending = 3): ";
				cin >> status;

				if( status < 0 || status > 3 ){
					cout<<"Invalid Selection."<<endl;
					return;
				}


				delete student;
				student = new COOPStudent(
					tempfName, templName, tempID, tempMark, (COOPStudent::PlacementStatus)status );
			}
			else {
				cout << "COOP Student demoted to Regular Student" << endl;
				delete student;
				student = new RegularStudent(tempfName, templName, tempID, tempMark);
				coop = false;
			}
		}
		else {
			if( tempMark > 80 ){
				cout << "Regular Student promoted to COOP Student" << endl;				//PROBLEM
				delete student;
				student = new COOPStudent(tempfName, templName, tempID, tempMark);
				coop = true;
			}
			else {
				cout << "Regular Student remains a Regular Student" << endl;

				cout << "Please enter the integer for the course completion fraction:"
					<< endl;
				cout << "(just started = 0, 1/6 = 1, 2/6 = 2, 3/6 = 3, "
					<< "4/6 = 4, 5/6 = 5, COMPLETE = 6):";
				cin >> status;

				if( status < 0 || status > 6 ){
					cout<<"Invalid selection"<<endl;
					return;
				}

				delete student;
				student = new RegularStudent( tempfName, templName, tempID, tempMark,
					(RegularStudent::CompletionStatus)status );		

			}
		}
		
		cout << endl << endl;
}
/**************************************************************************************
Function name:  SelectRecordByID
Purpose:		Finds the record entry based on its id 
In parameters:  void
Out parameters: void
Version:        1.2
Author:         Tim Osse
**************************************************************************************/
void DBManager::SelectRecordByID(void){

	int i;
	int idNum = 0;

	cout<<"Please enter the id of the student to select: ";
	cin>> idNum;

	for(i=0;i < m_numRecords; i++){
		if(idNum == m_ppRecords[i]->GetID()){
			m_ppRecords[i]->Report();
			return;
		}
	}
	
}
/**************************************************************************************
Function name:  DeleteRecordByID
Purpose:		Finds the record entry with the corresponding id and deletes it
In parameters:  void
Out parameters: void
Version:        1.1.2
Author:         Tim Osse
**************************************************************************************/
void DBManager::DeleteRecordByID(void){

	int id, i,j, student=-1;
	Student** oldStudents;
	Student** newStudents;

	// No records to delete
	if( m_numRecords == 0 ){
		cout << "FAIL : DELETE BY ID" << endl
			<<"No records" << endl<<endl;
		return;
	}
	cout << "m_numrecords=" << this->m_numRecords << endl;

		cout << "Please enter the id of the student to delete: ";
		cin >> id;
		

	for( i=0; i<m_numRecords; ++i )
		if( m_ppRecords[i]->GetID() == id ){
			student = i;
			break;
		}
	// record not found
	if( student == -1 ){
		cout << "Student record not found";
		cout << endl << endl;
		return;
	}
	//student record found
	cout << "Found record to delete." << endl;

	//delete the selected record
	delete m_ppRecords[student];
	m_ppRecords[student] = NULL;

	if( m_numRecords == 1 ){
		delete []m_ppRecords;
		m_ppRecords = NULL;
		m_numRecords = 0;
	}
	else {
		oldStudents = m_ppRecords;
		newStudents = new Student*[m_numRecords-1];

		for( i=0,j=0; i<m_numRecords-1; ++i,++j ){

			if(i==student) ++j; 
			newStudents[i] = oldStudents[j];
		}

		m_ppRecords = newStudents;
		delete []oldStudents;
		
		--m_numRecords;
	}

	cout << "Student record deleted" << endl;
	cout << "Number of Records = " << m_numRecords << endl << endl;
}
/**************************************************************************************
Function name:  WriteFile
Purpose:		Saves existing records to file 
In parameters:  void
Out parameters: void
Version:        1.1
Author:         Tim Osse
**************************************************************************************/
void DBManager::WriteFile(void) {

	int i;
	ofstream out(m_FileName);
	cout<<"File opened for Saving."<<endl;

	for (i=0; i < m_numRecords; i++) {

		out << *m_ppRecords[i] << endl;
	}

	out.close();
	cout<<"SAVED MEMORY TO FILE OK"<<endl;
}
