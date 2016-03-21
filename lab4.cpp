/* 
 * File:   main.cpp
 * Author: Usman Khalid, Koy Voss, Spencer Scott
 *
 * Created on March 17, 2016, 2:14 PM
 */

#include <cstdlib>
#include <string>
#include <fstream>
#include "Queue.h"
using namespace std;

void readTeamName(Queue &list);

int main(int argc, char** argv) {
	Queue theRace = Queue();
    readTeamName(theRace);
	cerr << "--Print queue." << endl;
	theRace.printQueue();
	Team* thisThingy = theRace.pop();
	cerr << "--Pop: ";
	cout << thisThingy->getName() << endl;
	Team* other = theRace.pop();
	cerr << "--Pop ";
	cout << other->getName() << endl;
	cerr << "--Print queue." << endl;
	theRace.printQueue();
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
