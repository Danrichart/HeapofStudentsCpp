#include "Address.h"

//address class getters and setters
void Address::setAddressLine1(string add){
	addressLine1 = add;
}
string Address::getAddressLine1(){
	return addressLine1;
}
void Address::setAddressLine2(string add){
	addressLine2 = add;
}
string Address::getAddressLine2(){
	return addressLine2;
}
void Address::setCity(string c){
	city = c;
}
string Address::getCity(){
	return city;
}
void Address::setState(string st){
	state = st;
}
string Address::getState(){
	return state;
}
void Address::setZipcode(string zip){
	zipcode = zip;
}
string Address::getZipcode(){
	return zipcode;
}
