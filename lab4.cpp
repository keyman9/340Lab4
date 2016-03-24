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
int main() {
	cout <<"##################################"<<endl;
	cout <<"## WELCOME TO THE AMAZING RACE! ##"<<endl;
	cout <<"##################################"<<endl;
	cout <<"Enter team list file naem: ";
	cout <<endl;
	cout <<"Enter city list file name: ";
	cout <<endl;
	int lap = 0;
	vector<string> cities = readCityName();
	vector<string> teamNames = readTeamNames();

	Queue theRace = Queue();
	Queue theFinish = Queue();

   // readTeamName(theRace);
   
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


/*
void readTeamName(Queue &list){
    ifstream infile;
    infile.open("teams.txt");
	string teamName;
	Team* tempTeam;
	int c;
	
 	while(!infile.eof()){
		getline(infile,teamName);
		if (teamName!=""){
  			tempTeam = new Team(teamName);
  			teamList.push_back(tempTeam);
			list.push(tempTeam);
		}
	}
}
*/



vector<string> readCityName(){
	ifstream infile;
	string cityName;
	vector<string> city;
	infile.open("cities.txt");
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
	infile.open("teams.txt");
	while(!infile.eof()){
		getline(infile,teamName);
		if(teamName!=""){
			teamNames.push_back(teamName);
		}
	}
	return teamNames;
}



