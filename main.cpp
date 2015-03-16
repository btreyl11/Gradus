#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

#include "class.cpp"
#include "grade.cpp"

using namespace std;

//GLOBALS
string mainFile = "grades.dat";
string temps;
double tempd;
int tempi;
Grade tempg;

vector <Class> semester;


void initGradus();
void updateGradus();
string lower_com( string command);
bool class_search(const string name);
void class_mode(const string c_name);
void help(char c);
int main()
{
	string com;
	bool terminate = false;
	initGradus();
	
	cout<<"<GRADUS v1.0a>"<<endl;
	while (!terminate){
	//finish implementing stringstream to the command stream	
		getline(cin, com);
		istringstream sin(com);
		
		sin>>temps;
		
		if( lower_com(temps) == "help"){
			help('o');
		}
		else if(lower_com(temps) == "add"){
			if(sin.eof()){
				cerr<<"Invalid command! \n\n";
				help('a');
			}
			else{
				sin>>com;
				
				if(temps == "-c"){
					getline(sin, temps);
					semester.push_back(Class(temps));
					cout<<"done.";
				}
				else if(temps == "-h")
					help('a');
			}
		}
		else if(lower_com(temps) == "view"){
			if(sin.eof()){
				cerr<<"Invalid command! \n\n";
				help('v');
			}
			else{
				sin>>com;
				if(temps == "-a"){
					for(vector<Class>::iterator it = semester.begin(); it != semester.end(); it++)
						cout<<it->name();
					cout<<"done.";
				}
				else if(temps == "-h")
					help('v');
			}
		}
		else if (lower_com(temps) == "quit")
		{
			terminate = true;
		}
	}	
	return 0;
}
void help(char c)
{
	if (c == 'o'){
		cout<<"\nGRADUS COMMANDS\n"<<endl;
		cout<<"add <type>  ADD CLASS, GRADE TYPE, OR GRADE"<<endl;//-c,-gt,-g
		cout<<"view <grade type>   VIEW GRADES FOR A CLASS"<<endl;
		cout<<"delete <type> DELETE CLASS, GRADE TYPE, OR GRADE"<<endl;//-c,-gt,-g
		cout<<"goto <class> ENTER CLASS VIEW/EDIT MODE"<<endl;
	}
	else if(c == 'a'){
		cout<<"\nGRADUS ADD COMMANDS\n"<<endl;
		cout<<"add <type>  ADD CLASS, GRADE TYPE, OR GRADE"<<endl;//-c,-gt,-g
		cout<<"\t"<<"-c <class> CLASS"<<endl;
		cout<<"IN CLASS VIEW/EDIT MODE:"<<endl;
		cout<<"\t"<<"-gt <type>    GRADE TYPE"<<endl;
		cout<<"\t"<<"-g  <nm & grd> GRADE"<<endl;
	}
	if(c == 'v'){
	cout<<"\nGRADUS ADD COMMANDS\n"<<endl;
	cout<<"view <class name> VIEW CLASS, GRADE TYPE, OR GRADE"<<endl;//-c,-gt,-g
	cout<<"\t"<<"-a ALL CLASSES"<<endl;
	cout<<"IN CLASS VIEW/EDIT MODE:"<<endl;
	cout<<"\t"<<"-gt <type>    GRADE TYPE"<<endl;
	cout<<"\t"<<"-g <nm & grd> GRADE"<<endl;
	}
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
			vector <Grade> tempv;
			while(!sin.eof()){
				while(temps != "name:"){
					sin>>temps;
					if (temps == "name:")
						goto overhere;
					sin>>tempg;
					tempv.push_back(tempg);
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
string lower_com( string command)
{
	for(int i = 0; i < command.length(); ++i)
		command[i] = tolower(command[i]);
	return command;
}
bool class_search(const string name)
{
	for(vector<Class>::const_iterator it = semester.begin(); it!= semester.end(); it++){
		if(it->name() == name){
			return true;
		}
	}
	return false;
}
