/**
	CSCI 24000 - Spring 2015
	date.h
	date.cpp
	student.h
	student.cpp
	address.h
	address.cpp
	main.cpp
	Purpose: Reads student data file into array and sorts information.
			 Display information per input from user. Full for full report. 
			 Simple for simple list. Alpha for alphabetical sorting students. 
			 Exit to exit program.

	@author Daniel Richart
	@date 4/5/2015
*/


#include <string>
#include<iostream>
#include<fstream>
#include<sstream>
#include "Student.h"
using namespace std;


// function accepts student array and outputs detailed report of Students.
void printFullReport(Student student[50]){
	
	//for loop to iterate student array
	for (int x = 0; x < 50; x++){
		cout << "Firstname: " << student[x].getFirstname()<< endl;
		cout << "Lastname: " << student[x].getLastname() << endl;
		cout << "Date of Birth: " << student[x].dateOfBirth.getMonth() << "/" << student[x].dateOfBirth.getDay() << "/" << student[x].dateOfBirth.getYear() << endl;
		cout << "Address Line 1: " << student[x].address.getAddressLine1() << endl;
		cout << "Address Line 2: " << student[x].address.getAddressLine2() << endl;
		cout << "City: " << student[x].address.getCity() << endl;
		cout << "State: " << student[x].address.getState() << endl;
		cout << "Zipcode: " << student[x].address.getZipcode() << endl;
		cout << "GPA: " << student[x].getGPA() << endl;
		cout << "Credit Hours Completed: " << student[x].getHours() << endl;
		cout << "Date of Completion: " << student[x].completionDate.getMonth() << "/" << student[x].completionDate.getDay() << "/" << student[x].completionDate.getYear() << endl;
		cout << endl;
	}
}

// function outputs a simple list of first and last names
void printSimpleList(Student student[50]){
	for (int x = 0; x < 50; x++){
		cout << student[x].getFirstname() << " " << student[x].getLastname() << endl;
	}
}

//function uses bubble sort to organize students alphabetically.
void alphaSort(Student student[50]){
	Student tempvar; // tempvar to hold any switches
	
	//nested for loop to iterate student array to fully sort
	for (int x = 0; x < 49; x++){
		for (int k = 0; k < 49; k++){
			if (student[k].getLastname() > student[k + 1].getLastname()){
				tempvar = student[k + 1]; 
				student[k + 1]= student[k]; 
				student[k] = tempvar;
			};
		}
		
	}

}

// function to break m/d/y in data file to m = m, d=d, y=y. it takes the input, and parses it by /

void dateInit(string s, Student &student, string direct){
	string tstring[3]; // creates temp array to hold results of parse
	int x = 0; // init counter
	while (x < 3){ // while loop to iterate through 3 strings needed
		int pos = s.find('/'); // finds first / and assigns position 
		tstring[x] = s.substr(0, pos); // assigns value from start position to location of first / found
		s.erase(0, pos + 1); // removes previous substring, creating a new start point just after first found /
		x++;
	}
	// initializes dob and completionhours using reference.
	if (direct == "dob"){
		student.dateOfBirth.setMonth(tstring[0]);
		student.dateOfBirth.setDay(tstring[1]);
		student.dateOfBirth.setYear(tstring[2]);
	};
	if (direct == "comp"){
		student.completionDate.setMonth(tstring[0]);
		student.completionDate.setDay(tstring[1]);
		student.completionDate.setYear(tstring[2]);
	};
}

int main(){
	
	Student student[50];  // init student array
	string line;
	string tarray[550]; //  init temp array to hold parsed data from text file
	int x = 0;
	
	ifstream f("StudentData.txt"); // opens file stream
	if (f.is_open()){
		while (getline(f, line)){ // parses strings by line
			stringstream ss(line);
			string word = "";
			while (getline(ss, word, ',')){ // parses string by commas
				tarray[x] = word; // assigns line and comma parsed words to array
				x++;
			}
		}
		
		// initalizes student array uses modular math
		for (int k = 0; k < 50; k++){
			student[k].setFirstname(tarray[(11 * k) + 0]);
			student[k].setLastname(tarray[11 * k + 1]);
			student[k].address.setAddressLine1(tarray[11 * k + 2]);
			student[k].address.setAddressLine2(tarray[11 * k + 3]);
			student[k].address.setCity(tarray[11 * k + 4]);
			student[k].address.setState(tarray[11 * k + 5]);
			student[k].address.setZipcode(tarray[11 * k + 6]);
			dateInit(tarray[11 * k + 7], student[k], "dob");
			dateInit(tarray[11 * k + 8], student[k], "comp");
			student[k].setGPA(tarray[11 * k + 9]);
			student[k].setHours(tarray[11 * k + 10]);	
		}

		f.close(); // closes file
	}
	else cout << "Unable to open file";
	

	string input;
	// while loop to control program from user input
	while (input != "exit"){
		cout << "Print [full] report, [simple] list, [alpha]sort, or [exit] program: ";
		cin >> input;

		//control structure of user input
		if (input == "full"){
			printFullReport(student);
		}
		else if (input == "simple"){
			printSimpleList(student);
		}
		else if (input == "alpha"){
			alphaSort(student);
			cout << "Student Data has been Sorted" << endl;
		}
		else if (input == "exit"){
			cout << "";
		}
		else{
			cout << "Input is incorrect, use all lower case letters" << endl;
		}
	}
}