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
    
    
public: //Functions go here
    
    LinkedList();
    //~LinkedList(){delete head;};
    
    void addNode(Rabbit addBunny);
    void deleteNode(Rabbit deleteBunny);
    void printList();
    int getSize(){return size;};
    nodePtr getHead(){return head;};
    
    LinkedList bunniesAreBorn();
    int howManyMutantsBorn(LinkedList newbornsList);
    void bunniesGetOlder();
    void mutantBunniesInfect(int amountToInfect);
    LinkedList bunniesDie();
    LinkedList combineNewbornsList(LinkedList newbornsList);
    LinkedList removeOlderBunnies(LinkedList seniorsList);
    
};


#endif /* LinkedList_hpp */
