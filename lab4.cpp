/* 
 * File:   main.cpp
 * Author: Usman Khalid, Koy Voss, Spencer Scott, Diego Bustamante, Shane Chamberlain
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
vector<string> readCityName(int &lap);
vector<string> readTeamNames();
string teamFile;
string cityFile;
int lap= 1;
int main() {
	cout <<"##################################"<<endl;
	cout <<"## WELCOME TO THE AMAZING RACE! ##"<<endl;
	cout <<"##################################"<<endl;
	cout <<"Enter team list file name: ";
	cin >> teamFile;
	cout << endl;
	cout <<"Enter city list file name: ";
	cin >> cityFile;
	cout <<endl;
	int lap = 0;
	vector<string> cities = readCityName(lap);
	vector<string> teamNames = readTeamNames();

	Queue theRace = Queue();
	Queue theFinish = Queue();

	for(int i = 0; i < teamNames.size(); i++){
		theRace.push(new Team(teamNames.at(i)));
	   // readTeamName(theRace);
	}
	int teamsInRace = theRace.getSize();
	   
	cerr << "--Print theRace queue." << endl;
	theRace.printQueue();

	cerr << "--Print theFinish queue." << endl;
	theFinish.printQueue();

	cerr << "Original Size: " << theRace.getSize() << endl;
	string nextCity = "Brussels";
	
	
	//while teamsInRace to race
	Team* slowest = new Team();
	//for(int i = 0; i < teamsInRace; teamsInRace--){
		//for(int j = 0; j < cities.size(); j++){
	for(int i = 0; i < teamNames.size(); i++){
			nextCity = cities[i];
			slowest = theRace.nextLeg(nextCity,teamsInRace,slowest);
			teamsInRace--;
			cout << "Slowest " << slowest->getName() << endl;
			theFinish.push(slowest);
	}
			//theFinish.push(slowest);
		//}
	//}


	cerr << "Original Queue: " << endl;
	//theRace.printQueue();
	cerr << "Finish Queue after round 1: " << endl;
	theFinish.printQueue();

///
	//cout <<"This is the round vale " << lap <<endl;

	for (int x = 0; x < lap; x ++){
		cout <<"The "<< theFinish.pop()->getName() <<" were the last team to reach " <<cities[x]<<endl;
		cout <<endl;

	}
	cout <<"TEAMS         ";
	for (int x = 1; x <= lap; x ++){
		cout<< "      Round " << x;
	}
	cout <<endl;

	cout << 
	cout <<"##################################"<<endl;
	cout <<"##       THANKS  FOR PLAYING!   ##"<<endl;
	cout <<"##################################"<<endl;

    return 0;

}
vector<string> readCityName(int &lap){
	ifstream infile;
	string cityName;
	vector<string> city;
	infile.open(cityFile.c_str());
	//infile.open("cities.txt");
	while(!infile.eof()){
		getline(infile,cityName);
		if(cityName!=""){
			lap ++;
			city.push_back(cityName);
			//cout <<"the value of lap is " << lap <<endl;
		}
	}
	return city;
}

vector<string> readTeamNames(){
	ifstream infile;
	string teamName;
	vector<string> teamNames;
	infile.open(teamFile.c_str());
	//infile.open("teams.txt");
	while(!infile.eof()){
		getline(infile,teamName);
		if(teamName!=""){
			teamNames.push_back(teamName);
		}
	}
	return teamNames;
}
