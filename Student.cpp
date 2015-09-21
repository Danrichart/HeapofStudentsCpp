#include "Student.h"

//student class getters and setters
void Student::setFirstname(string first){
	firstName = first;
}
string Student::getFirstname(){
	return firstName;
}
void Student::setLastname(string last){
	lastName = last;
}
string Student::getLastname(){
	return lastName;
}
void Student::setGPA(string g){
	gpa = g;
}
string Student::getGPA(){
	return gpa;
}
void Student::setHours(string hours){
	hoursComplete = hours;
}
string Student::getHours(){
	return hoursComplete;
}
