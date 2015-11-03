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
int Class::num_grades() const
{
	return mGrades.size();
}
int Class::num_weights()const
{
	return mWeights.size();
} 
double Class::average()
{	
  for(auto i: mGrades)
    mAverage += gradeAve(i.second)*weight(i.first);
	return mAverage;
}
string Class::weights()
{
	ostringstream sout;
	for(map<string, int >::iterator it = mWeights.begin(); it != mWeights.end(); it++)
		sout<< it->first << it->second;
	return sout.str();
}
double Class::weight(const string key)
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
double Class::gradeAve(vector <Grade> a)
{ 
  double average = 0;
  for(Grade i : a)
    average += i.percent();
  average = average/a.size();
  return average;
}
