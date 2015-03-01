#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

#include "class.cpp"

using namespace std;

//GLOBALS
string mainFile = "grades.dat";
string temps;
double tempd;
int tempi;

vector <Class> semester;


void initGradus();
void updateGradus();
int main()
{
	initGradus();
	cout<<"<GRADUS v1.0a>"<<endl;
	
	return 0;
}
void initGradus()
{
	Class temp;
	string line;
	ifstream fin(mainFile.c_str());
	if(fin.good())
	while(!fin.eof()){
		getline(fin,line);
		istringstream sin(line);
		sin>>temps;
		overhere:
		if(temps == "name:"){
			sin>>temps;
			temp.setName(temps);
		}
		else if(temps == "settings:"){
			while(!sin.eof()){
				sin>>temps;
				sin>>tempi;
				temp.setWeight(temps,tempi);
			}
		}
		else if(temps == "grades:"){
			vector <double> tempv;
			while(!sin.eof()){
				while(temps != "name:"){
					sin>>temps;
					if (temps == "name:")
						goto overhere;
					sin>>tempd;
					tempv.push_back(tempd);
					getline(fin,line);
					istringstream sin(line);
				}
			}
			temp.setGrades(temps, tempv);
		}
	}
	fin.close();
	
}
void updateGradus()
{
	ofstream fout(mainFile.c_str());
	for(vector<Class>::iterator it = semester.begin(); it != semester.end(); it++){
		fout<<"name: "<<(*it).name()<<endl;
		fout<<"settings: "<<(*it).weights()<<endl;
		fout<<"grades: "<<(*it).grades()<<endl;
	}
}
