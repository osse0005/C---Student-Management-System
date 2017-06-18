/* 
 * File:   DBManager.h
 * Author: timosse448
 *
 * Created on December 02, 2012
 */


class DBManager
{
    Student** m_ppRecords;
    int m_numRecords;
    char* m_FileName;
public:
    DBManager();
	DBManager(DBManager&);
    ~DBManager();
	Student*& operator[](int);

    void ReadFile();
    void ListRecords();
    void AddRecord();
	void OverwriteRecordByID();
	void SelectRecordByID();
	void HighestMark();
	void LowestMark();
    void DeleteRecordByID();
    void WriteFile();
};


