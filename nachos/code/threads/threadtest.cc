#include "kernel.h"
#include "main.h"
#include "thread.h"
#include "person.h"
#include "list.h"

//Variables for storing order, prev person and total Laundry Time
int ord = 1;
person *prev;
int total = 0;

//Print the information of person standing in line.
void PrintWaiting(person* p){
    printf("Person with Sequence %d, Priority %d, Number of Clothes %d and Laundry Time %d \n", p->getSeq(), p->getPriority(), p->getClothes(), p->getLaundryTime());
}

//Print the infromation after people start entering the room.
void PrintLaundry(person* p){
    printf("Order %d,", ord);
    printf("Person with Sequence %d, Priority %d, Number of Clothes %d and Laundry Time %d enters. ", p->getSeq(), p->getPriority(), p->getClothes(), p->getLaundryTime());
    if(ord >1){
        printf("Person with Sequence %d and Laundry Time %d leaves the room.", prev->getSeq(), prev->getLaundryTime());
    }
    printf("\n");
    prev = p;
    total = total + p->getLaundryTime();
    if(ord == 20){
        printf("Person with Sequence %d and Laundry Time %d leaves the room.", p->getSeq(), p->getLaundryTime());
        printf("\n\nTotal Laundry Time %d\n",total );
    }
    ord++;
}


void
SimpleThread(int which)
{
    int num;

    for (num = 0; num < 5; num++) {
        //printf("*** thread %d looped %d times\n", which, num);
        kernel->currentThread->Yield();
    }
}

//Laundry-room simulations of 20 people
void LaundryQueue(){

    List<person*> *list = new List<person*>;
    SortedList<person*> *sList =  new SortedList<person*>(person::compare);

    int priority;
    int time;
   
   //Simulation 1
    for( int i= 1; i <=20 ; i++){
        priority = rand() % 10;
        time = rand() % 10 + 1;
        person *p = new person(i,priority,time + 1, time);
        sList->Insert(p);
    }  

    printf("\nSimulation 1 (line up sorted with priority): \n");
    sList->Apply(PrintWaiting);

    printf("\nSimulation 1 Begins: \n");
    sList->Apply(PrintLaundry);

    //Simulation 2
    for( int i= 1; i <=20 ; i++){
        priority = rand() % 10;
        time = rand() % 10 + 1;
        person *p = new person(i,priority,time + 1, time);
        list->Append(p);
    }  

    printf("\nSimulation 2 (line up according to Sequence): \n");
    list->Apply(PrintWaiting);

    
    List<person*> *temp = new List<person*>;
    int min = 10;
    printf("\nSimulation 2 Begins: \n");

    for(int i=1; i < 21 ;i++){
        ListIterator<person*> *iter1 = new ListIterator<person*>(list);
        person *p2;
        min = 10;
        for (; !iter1->IsDone(); iter1->Next()) {
           person *tempP = iter1->Item();
           if(min > tempP->getPriority()){
                min = tempP->getPriority();
                p2 = tempP;
           }
        }
        list->Remove(p2);
        temp->Append(p2);
    }
    ord =1;
    total =0;
    temp->Apply(PrintLaundry);
}

void ThreadTest()
{
    Thread *t = new Thread("forked thread");
    t->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);
    LaundryQueue();
}


