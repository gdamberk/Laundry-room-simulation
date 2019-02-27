/*person.cc
Contains definition of all the functions in list.h 
*/
#include "person.h"

//Costructor for person class
person::person(int s, int p, int c, int l){
	seq = s;
	priority = p;
	clothes = c;
	laundryTime = l;
}

//This function is used while inserting the person in sorted list
//This function comapres Priorities of person. 
int person::compare(person* p1, person* p2){

	int p1Priority = p1->getPriority();
	int p2Priority = p2->getPriority();

	if(p1Priority < p2Priority)
		return -1;
	if(p1Priority == p2Priority)
		return 0;
	else
		return 1;
}

//setter for sequence number
void person::setSeq(int s){
	seq = s;
}

//setter for Priority
void person::setPriority(int p){
	priority = p;
}

//setter for clothes
void person::setClothes(int c){
	clothes = c;
}

//setter for laundry time
void person::setLaundryTime(int l){
	laundryTime = l;
}

//getter for sequence number
int person::getSeq(){
	return seq;
}

//getter for priority
int person::getPriority(){
	return priority;
}

//getter for clothes
int person::getClothes(){
	return clothes;
}

//getter for laundry time
int person::getLaundryTime(){
	return laundryTime;
}
