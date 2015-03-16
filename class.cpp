#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "class.h"

using namespace std;

Class::Class()
{
	mName = "";
	mAverage = 0;
}
Class::Class(const string name)
{
	mName = name;
}
string Class::name()const
{
	return mName;
}
string Class::grades()const
{
	ostringstream sout;
	for (map<string, vector<Grade> >::const_iterator it = mGrades.begin(); it != mGrades.end(); it++){
		sout<<it->first;
		for(vector<Grade>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
			sout<< *it2;
		}
		sout<<endl;
	}
	return sout.str();
}
double Class::average()const
{
	//Learn the algorithm to find class averages
	return mAverage;
}
string Class::weights()
{
	ostringstream sout;
	for(map<string, int >::iterator it = mWeights.begin(); it != mWeights.end(); it++)
		sout<< it->first << it->second;
	return sout.str();
}
int Class::weight(const string key)
{
	return mWeights[key];
}

void Class::setName(const string name)
{
	mName = name;
}
void Class::addGrade(const string type, Grade grade)
{
	mGrades[type].push_back(grade);
}
void Class::addWeight(const string type, const int weight)
{
	if(mGrades.find(type) == mGrades.end())
		cerr<<"Grade type "<< type << " does not exist!"<<endl;
	else
		mWeights[type] = weight;
}
void  Class::setWeight(const string type, const int weight){
	mWeights[type] = weight;
}
void Class::setGrades(const string type, const vector<Grade>grades)
{
	mGrades[type] = grades;
}
