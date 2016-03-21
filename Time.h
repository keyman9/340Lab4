using namespace std;

struct Time{
    int hour;
    int min;
    Time *next;
    Time *prev;
    Time(){ hour = min = 0; }
};

