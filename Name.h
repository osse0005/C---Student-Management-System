//Name.h
class Name
{
	char* m_firstName;
	char* m_lastName;
public:
	Name():m_firstName(0),m_lastName(0){}
	Name(char*,char*);
	Name(Name&);
	Name& operator=(Name&);
	~Name();
	void Report(){cout<<m_firstName<<" "<<m_lastName<<endl;}
	friend ofstream& operator<<(ofstream& , Name&);
};
