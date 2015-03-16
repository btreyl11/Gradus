#ifndef GRADE_H
#define GRADE_H
using namespace std;
class Grade
{
	private:
		string m_id;
		double m_percent;
	public:
		Grade();
		
		string id()const;
		double percent()const;
		
		void set_id(const string id);
		void set_percent(const double percent);
		
		friend istream& operator>>(istream& is, Grade& grade );
		friend ostream& operator<<(ostream& os, const Grade& grade);
};
#endif
