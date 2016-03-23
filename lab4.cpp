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
vector<string> readCityName(int &round);

int main() {
	cout <<"##################################"<<endl;
	cout <<"## WELCOME TO THE AMAZING RACE! ##"<<endl;
	cout <<"##################################"<<endl;
	cout <<"Enter team list file naem: ";
	cout <<endl;
	cout <<"Enter cit list file name: ";
	cout <<endl;
	int round = 0;
	vector<string> cities = readCityName(round);
	Queue theRace = Queue();
    readTeamName(theRace);
	//cerr << "--Print queue." << endl;
	//theRace.printQueue();
	//Team* thisThingy = theRace.pop();
	//cerr << "--Pop: ";
	//cout << thisThingy->getName() << endl;
	//Team* other = theRace.pop();
	//cerr << "--Pop ";
	//cout << other->getName() << endl;
	//cerr << "--Print queue." << endl;
	//theRace.printQueue();
	//theRace.nextLeg();
	//theRace.printQueue();

	cout <<"This is the round vale " <<round <<endl;

	for (int x = 0; x < round; x ++){
		cout <<"The "<<x <<" were the last team to reach " <<cities[x]<<endl;

	}
	cout <<"TEAMS         ";
	for (int x = 0; x < round; x ++){
		cout<< "      Round " << x;
			}
	cout <<endl;
	theRace.printQueue();
	cout <<"##################################"<<endl;
	cout <<"##       THANKS  FOR PLAYING!   ##"<<endl;
	cout <<"##################################"<<endl;

    return 0;
}

void readTeamName(Queue &list){
    ifstream infile;
    infile.open("teams.txt");
	string teamName;
	Team* tempTeam;
 	while(!infile.eof()){
		getline(infile,teamName);
		//cout << teamName << endl;
  		tempTeam = new Team(teamName);
		//cout << tempNode->getData().getName() << endl;
		list.push(tempTeam);
	}

}

vector<string> readCityName(int &round){
	ifstream infile;
	string cityName;
	vector<string> city;
	infile.open("cities.txt");
	while(!infile.eof()){
		getline(infile,cityName);
		city.push_back(cityName);
	}
	round =city.size();
	return city;
}
