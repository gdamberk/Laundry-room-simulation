/*person.h
Contains all the information of a person for Laundry Simulation. 
*/

#include "debug.h"
class person
{

private:
	int seq;
	int priority;
	int clothes;
	int laundryTime;
public:
	~person();
	person(int s, int p, int c, int l);

	void setSeq(int s);
	void setPriority(int p);
	void setClothes(int c);
	void setLaundryTime(int l);

	static int compare(person* p1, person* p2);
	int getSeq();
	int getPriority();
	int getClothes();
	int getLaundryTime();
	int getOrder();
};