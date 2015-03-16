#ifndef CLASS_H
#define CLASS_H
#include "grade.h"
using namespace std;
class Class {
	private:
		string mName;
		//Finish implementing Grades.h into the Class class!!!
		map <string, vector<Grade> > mGrades;
		map <string, int> mWeights;
		double mAverage;
		int mlistSize;
	public:
		Class();
		Class(const string name);

		string name() const;
		string grades() const;
		double average() const;
		string weights();
		int weight(const string key);

		void setName(const string name);
		void addGrade(const string type, Grade grade);
		void addWeight(const string type, const int weight);
		void setWeight(const string type, const int weight);
		void setGrades(const string type, const vector<Grade>grades);


};
#endif
