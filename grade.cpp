#include <iostream>
#include <string>
#include "grade.h"

using namespace std;

Grade::Grade(): m_id(""),m_percent(0)
{}
string Grade::id() const
{
	return m_id;
}
double Grade::percent() const
{
	return m_percent;
}
void Grade::set_percent(const double percent){
	m_percent = percent;
}
void Grade::set_id(const string id){
	m_id = id;
}

istream& operator>>(istream& is, Grade& grade)
{
	is>> grade.m_percent;
	ws(is);
	getline(is,grade.m_id);
	
	return is;
}
ostream& operator<<(ostream& os, const Grade& grade)
{
	os<< grade.m_id << ": "<< grade.m_percent;
	
	return os;
}
