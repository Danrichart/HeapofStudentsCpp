#ifndef Address_h
#define Address_h
#endif


#include<string>
using namespace std;

//address class
class Address {
	string addressLine1;
	string addressLine2;
	string city;
	string state;
	string zipcode;
public:
	void setAddressLine1(string add);
	string getAddressLine1();
	void setAddressLine2(string add);
	string getAddressLine2();
	void setCity(string c);
	string getCity();
	void setState(string st);
	string getState();
	void setZipcode(string zip);
	string getZipcode();
};