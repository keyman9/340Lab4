#include <string>

using namespace std;

struct Time{
    int hour;
    int min;
	string city;
    Time *next;
    Time *prev;
    Time(){ hour = min = 0; }
};
