//Regular Student.h

class RegularStudent:public Student
{
public:
	typedef enum{JUST_STARTED, ONE_SIXTH, ONE_THIRD, HALF, TWO_THIRDS, FIVE_SIXTH, COMPLETE}CompletionStatus;
	RegularStudent():Student(),m_status(JUST_STARTED){}
	RegularStudent(char*,char*,int,float,CompletionStatus=JUST_STARTED);	//default argument
	RegularStudent(RegularStudent& RRS):Student(RRS),m_status(RRS.m_status){}
	RegularStudent& operator=(RegularStudent&);
	void Report();
private:
	CompletionStatus m_status;
};