//ass3.cpp

#include <iostream>
#include <fstream>
using namespace std;
#include "Name.h"
#include "Student.h"
#include "RegularStudent.h"
#include "COOPStudent.h"
#include "DBManager.h"

int main()
{
	bool running = true;
	char response;
	DBManager db;
	db.ReadFile();

	while(running)
	{
		cout<<"1. List records in memory"
			  "\t\t2. Add a new student record\n"
			  "3. Overwrite a student record"
			  "\t\t4. Select a student record by ID\n"
			  "5. Get student with highest mark"
			  "\t6. Get student with lowest mark\n"
			  "7. Delete a student record by ID"
			  "\t8. Quit and save records to file\n"
			  <<endl;

		cin>>response;

		switch(response)
		{
		case'1':
			db.ListRecords();
			break;
		case'2':
			db.AddRecord();
			break;
		case'3':
			db.OverwriteRecordByID();
			break;
		case'4':
			db.SelectRecordByID();
			break;
		case'5':
			db.HighestMark();
			break;
		case'6':
			db.LowestMark();
			break;
		case'7':
			db.DeleteRecordByID();
			break;
		case'8':
			{
				running = false;
				db.WriteFile();
				break;
			}
		default:cout<<"Invalid choice<<endl";
		}
	}
	return 0;
}
