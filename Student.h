/* Student.h */

class Student
{
protected:
    int m_id;
    float m_mark;
    Name m_name;
public:
	Student(){}
	Student(char* fname, char* lname, int id, float mark): m_name(fname,lname),m_id(id), m_mark(mark) {}
	Student(Student&);
	Student& operator=(Student&);
	virtual ~Student() {}
	bool operator>(Student&);
	bool operator<(Student&);
	bool operator==(Student&);
    int GetID(){return m_id;}
	virtual void Report() = 0;
	/* overloaded insertion operator for saving records to file */
	friend ofstream& operator<<(ofstream& fout, Student& RS);
};

