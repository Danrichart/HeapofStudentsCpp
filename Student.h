#ifndef Student_h
#define Student_h
#endif

#include <string>
#include "Address.h"
#include "Date.h"
using namespace std;

//student class
class Student {
	string firstName;
	string lastName;
	string gpa;
	string hoursComplete;
public:
	Address address;
	Date dateOfBirth;
	Date completionDate;
	void setFirstname(string first);
	string getFirstname();
	void setLastname(string last);
	string getLastname();
	void setGPA(string g);
	string getGPA();
	void setHours(string hours);
	string getHours();
};