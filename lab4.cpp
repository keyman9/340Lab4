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
Team * fastestTeam(Team* t[], int size);
int main() {
	cout <<"##################################"<<endl;
	cout <<"## WELCOME TO THE AMAZING RACE! ##"<<endl;
	cout <<"##################################"<<endl;
	cout <<"Enter team list file naem: ";
	cout <<endl;
	cout <<"Enter cit list file name: ";
	cout <<endl;
	int lap = 0;
	vector<string> cities = readCityName(lap);


	Queue theRace = Queue();
	Queue theFinish = Queue();

    readTeamName(theRace);
   
	cerr << "--Print queue." << endl;
	theRace.printQueue();

	cerr << "--Print queue." << endl;
	theRace.printQueue();

	cerr << "Original Size: " << theRace.getSize() << endl;
	string nextCity = "Brussels";
	

	//while cities to race
	Team* slowest = NULL;
	theRace.nextLeg(nextCity);
	theFinish.push(slowest);


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

vector<string> readCityName(int &lap){
	ifstream infile;
	string cityName;
	vector<string> city;
	infile.open("cities.txt");
	while(!infile.eof()){
		getline(infile,cityName);
		city.push_back(cityName);
	}
	lap =city.size();
	return city;
}
Team * fastestTeam(Team* t[], int size){
	Team *tempArray [size];
	Team *fastest =  NULL;
	Team *next = NULL;
	int min= 50000;
	int index;
	for(int n=0; n < size; n++){
		fastest = t[n];
		for (int i = n + 1; i < size; i ++){
			next= t[i];
			if(fastest->getTimeInMin() < next->getTimeInMin()){
				tempArray[n]=t[n];
			}
			else{
				fastest= t[i];
			}	
		}
		tempArray[n] = fastest;
	}
	return *tempArray;
}
