/* 
 * File:   main.cpp
 * Author: Usman Khalid, Koy Voss, Spencer Scott
 *
 * Created on March 17, 2016, 2:14 PM
 */

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Queue.h"

using namespace std;

void readTeamName(Queue &list);
vector<string> readCityName();
vector<string> readTeamNames();
string teamFile;
string cityFile;
int main() {
	cout <<"##################################"<<endl;
	cout <<"## WELCOME TO THE AMAZING RACE! ##"<<endl;
	cout <<"##################################"<<endl;
	cout <<"Enter team list file name: ";
	cin >> teamFile;
	cout <<endl;
	cout <<"Enter city list file name: ";
	cin >> cityFile;
	cout <<endl;
	int lap = 0;
	vector<string> cities = readCityName();
	vector<string> teamNames = readTeamNames();

	Queue theRace = Queue();
	Queue theFinish = Queue();

	for(int i = 0; i < teamNames.size(); i++){
		theRace.push(new Team(teamNames.at(i)));
	   // readTeamName(theRace);
	}
   
	cerr << "--Print queue." << endl;
	theRace.printQueue();

	cerr << "--Print queue." << endl;
	theRace.printQueue();

	cerr << "Original Size: " << theRace.getSize() << endl;
	string nextCity = "Brussels";
	

	//while cities to race
	//Team* slowest = NULL;
	theRace.nextLeg(nextCity);
	//theFinish.push(slowest);


	cerr << "Original Queue: " << endl;
	theRace.printQueue();
	cerr << "Finish Queue after round 1: " << endl;
	theFinish.printQueue();

///
	cout <<"This is the round vale " << lap <<endl;

	for (int x = 0; x < lap; x ++){
		cout <<"The "<<x <<" were the last team to reach " <<cities[x]<<endl;

	}
	cout <<"TEAMS         ";
	for (int x = 0; x < lap; x ++){
		cout<< "      Round " << x;
			}
	cout <<endl;
	theRace.printQueue();
	cout <<"##################################"<<endl;
	cout <<"##       THANKS  FOR PLAYING!   ##"<<endl;
	cout <<"##################################"<<endl;

    return 0;

}
vector<string> readCityName(){
	ifstream infile;
	string cityName;
	vector<string> city;
	infile.open(cityFile.c_str());
	while(!infile.eof()){
		getline(infile,cityName);
		if(cityName!=""){
			city.push_back(cityName);
		}
	}
	return city;
}

vector<string> readTeamNames(){
	ifstream infile;
	string teamName;
	vector<string> teamNames;
	infile.open(teamFile.c_str());
	while(!infile.eof()){
		getline(infile,teamName);
		if(teamName!=""){
			teamNames.push_back(teamName);
		}
	}
	return teamNames;
}



