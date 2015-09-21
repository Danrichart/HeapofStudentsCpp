#ifndef Date_h
#define Date_h
#endif

#include <string>
using namespace std;


// date class
class Date {
	string month;
	string day;
	string year;
public:
	void setMonth(string m);
	string getMonth();
	void setDay(string d);
	string getDay();
	void setYear(string y);
	string getYear();
};