//
//  LinkedList.hpp
//  
//
//  Created by Cameryn Holstick
//
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "Rabbit.cpp"

class LinkedList
{
private:
    
    typedef struct node
    {
        Rabbit data;
        node* next;
    }* nodePtr;
    
    nodePtr head;
    nodePtr current;
    //nodePtr newCurrent;
    nodePtr temp;
    int size;
    int colonyAge;
    
    
public: //Functions go here
    
    LinkedList();
    //~LinkedList(){delete head;};
    
    void addNode(Rabbit addBunny);
    void deleteNode(Rabbit deleteBunny);
    void printList();
    int getSize(){return size;};
    nodePtr getHead(){return head;};
    int getColonyAge(){return colonyAge;};
    
    
    LinkedList bunniesAreBorn();
    int howManyMutantsBorn(LinkedList newbornsList);
    bool hasOneNonMutantMale();
    void bunniesGetOlder();
    void mutantBunniesInfect(int amountToInfect);
    LinkedList bunniesDie();
    LinkedList combineNewbornsList(LinkedList newbornsList);
    LinkedList removeOlderBunnies(LinkedList seniorsList);
    LinkedList cullHalfPopulation();
    bool allDead();
    
    
};


#endif /* LinkedList_hpp */
