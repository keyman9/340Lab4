struct Time{
    int hour;
    int min;
	bool setTime;
    Time *next;
    Time *prev;
    Time(){ hour = min = 0; setTime = false; }
};
