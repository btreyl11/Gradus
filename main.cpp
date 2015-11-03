#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

#include "class.h"
#include "grade.h"

using namespace std;

//GLOBALS
string mainFile = "grades.dat";
string temps;
double tempd;
int tempi;
Grade tempg;
string com1,com2,com3;

vector <Class> semester;


void initGradus();
void updateGradus();
string lower_com( string command);
bool class_search(const string name);
void class_mode(const string c_name);
void help(char c);
void error_message(char type);

int main()
{
	
	bool done = false;
	initGradus();
	
	cout<<"<GRADUS v1.0a>"<<endl;
	while (!done){
	//finish implementing stringstream to the command stream
		cout<<"Normal-Mode$~ ";	
		getline(cin, temps);
		istringstream sin(temps);
		
		sin>>com1>>com2;
		getline(sin,com3);
		
		if( lower_com(com1) == "help"){
			help('o');
		}
		else if(lower_com(com1) == "add"){
			if(com2 == "-c"){
					semester.push_back(Class(com3));
					cout<<"done."<<endl;
			}
			else if(com2 == "-h"){
					help('a');
			}
			else{
				error_message('a');
			}
		}
		else if(lower_com(com1) == "view"){
			
			if(com2 == "-a"){
					for(vector<Class>::iterator it = semester.begin(); it != semester.end(); it++)
						cout<<it->name()<<endl;
					cout<<"done."<<endl;
				}
			else if(temps == "-h"){
					help('v');
			}
			else{
				error_message('v');
			}
		}
		else if(lower_com(com1) == "goto"){
			if(com2 == "-cm"||lower_com(com2)== "class" )
				if(com3 != ""){
					for(Class i : semester){
						if(i.name() == com3)
							class_mode(com3);
					}
				}
				else{
					error_message('g');
				}
			else{
				error_message('g');
			}
		}
		else if (lower_com(temps) == "quit")
		{
			done = true;
		}
	}
	updateGradus();	
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
	if(c == 'g'){
		cout<<"\nGRADUS GOTO COMMANDS\n"<<endl;
		cout<<"goto <mode> SWITCH MODES"<<endl;
		cout<<"\t -c OR class SWITCH TO CLASS VIEW/EDIT MODE"<<endl;
	}
	cout<< endl; 
}
void error_message(char type)
{
	cerr<<"Invalid command! \n\n";
				help(type);
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
			getline(sin, temps);
			temp.setName(temps);
			sin>>temps;
			if(temps == "settings:"){
				while(!sin.eof()){
					sin>>temps;
					if (temps == " ")
						break;
					sin>>tempi;
					temp.setWeight(temps,tempi);
				 
				}
					if(temps == "grades:"){
					vector <Grade> tempv;
					while(!sin.eof()){
						while(temps != "name:"){
							sin>>temps;
							string g_name;
							if (temps == "name:")
								goto overhere;
							sin>>tempd;
							getline(cin, g_name);
							tempg.set_percent(tempd);
							tempg.set_id(g_name);
							tempv.push_back(tempg);
							getline(fin,line);
							istringstream sin(line);
						}
					}
					temp.setGrades(temps, tempv);
				}
			}
			
		}
		semester.push_back(temp);
	}
	
	fin.close();
	
}
void updateGradus()
{
	ofstream fout(mainFile.c_str());
	for(vector<Class>::iterator it = semester.begin(); it != semester.end(); it++){
		fout<<"name:"<<(*it).name()<<endl;
		if(!((*it).num_weights() <= 0)){
			fout<<"settings:"<<(*it).weights()<<endl;
			fout<<"grades:"<<(*it).grades()<<endl;
		}
	}
}
void class_mode(const string c_name)
{
	bool done = false;
	
	while(!done){
		cout<<"Class-Mode$~ ";	
		getline(cin, temps);
		istringstream sin(temps);
		
		sin>>com1>>com2;
		getline(sin,com3);	
		if( lower_com(com1) == "help"){
			help('o');
		}
		//FINISH THIS PART!!!!!!
		else if(lower_com(com1) == "add"){
			if(com2 == "-g"){
					semester.push_back(Class(com3));
					cout<<"done."<<endl;
			}
			else if(com2 == "-h"){
					help('a');
			}
			else{
				error_message('a');
			}
		}
		else if(lower_com(com1) == "view"){
			
			if(com2 == "-a"){
					for(vector<Class>::iterator it = semester.begin(); it != semester.end(); it++)
						cout<<it->name()<<endl;
					cout<<"done."<<endl;
				}
			else if(temps == "-h"){
					help('v');
			}
			else{
				error_message('v');
			}
		}
		else if(lower_com(com1) == "goto"){
			if(com2 == "-cm"||lower_com(com2)== "class" )
				if(com3 != ""){
					for(Class i: semester){
						if(i.name() == com3)
							class_mode(com3);
					}
				}
				else{
					error_message('g');
				}
			else{
				error_message('g');
			}
		}
		else if (lower_com(temps) == "quit")
		{
		 done	=  true;
		}
	}
}
string lower_com( string command)
{
	for(unsigned i = 0; i < command.length(); ++i)
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
