//COOPStudent.h

class COOPStudent:public Student
{
public:
	typedef enum{UNPLACED,PLACED,SUSPENDED,PENDING}PlacementStatus;
	COOPStudent():Student(),m_status(UNPLACED){}
	COOPStudent(char*,char*,int,float,PlacementStatus=UNPLACED); //default argument
	COOPStudent(COOPStudent& RCS):Student(RCS),m_status(RCS.m_status){}
	COOPStudent& operator=(COOPStudent&);
	void Report();
private:
	PlacementStatus m_status;
};