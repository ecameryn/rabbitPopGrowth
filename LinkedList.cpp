#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "LinkedList.hpp"

int size = 0;

LinkedList::LinkedList()
{
    head = NULL;
    current = NULL;
    temp = NULL;
}


void LinkedList::addNode(Rabbit addBunny)
{
    nodePtr newNode = new node;
    newNode->next = NULL;
    newNode->data = addBunny;
    
    if(head != NULL)
    {
        current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        
    }
    else
    {
        head = newNode;
    }
    
    size++;
}


void LinkedList::deleteNode(Rabbit deleteBunny)
{
    nodePtr deletePtr = NULL;
    temp = head;
    current = head;
    
    while(current != NULL && !current->data.getName().compare(deleteBunny.getName()))
    {
        temp = current;
        current = current->next;
    }
    if(current == NULL)
    {
        cout << deleteBunny.getName() << "was not in the list\n" << endl;
        delete deletePtr;
    }
    else
    {
        deletePtr = current;
        current = current->next;
        temp->next = current;
        if(deletePtr == head)
        {
            head = head->next;
            temp = NULL;
        }
        
        delete deletePtr;
        
        
        
        size--;
    }
}


void LinkedList::printList()
{
    current = head;
    
    while(current != NULL)
    {
        
        cout << "\nName: " << current->data.getName() << endl;
        cout << "Sex: "<< current->data.getSex() << endl;
        cout << "Color: "<< current->data.getColor() << endl;
        cout << "Age: "<< current->data.getAge() << endl;
        cout << "MutantVamp?: "<< current->data.isRadioactiveMutant() << endl;
        cout << "Dearly Departed: "<< current->data.isDeceased() << "\n" << endl;
        
        current = current->next;
        
    }
}

LinkedList LinkedList::combineNewbornsList(LinkedList newbornsList)
{
    LinkedList newCombinedList;
    current = head;
    
    while(current != NULL)
    {
        newCombinedList.addNode(current->data);
        current = current->next;
    }
    
    current = newbornsList.head;
    
    //current = head;
    
    while(current != NULL)
    {
        newCombinedList.addNode(current->data);
        //newCombinedList.size++;
        current = current->next;
    }
    
    return newCombinedList;
    
}

/*LinkedList LinkedList::removeOlderBunnies(LinkedList seniorsList)
{
    LinkedList afterDeathsList;
    nodePtr seniorsListCurrent = seniorsList.getHead();
    
    current = head;
    
    while(current != NULL)
    {
        while(seniorsListCurrent != NULL)
        {
            //if(current->data.getName());
        }
    }
    return afterDeathsList;
}*/

LinkedList LinkedList::bunniesAreBorn()
{
    LinkedList babyBunniesList;
    current = head;
    //Rabbit bunny = current->data;
    bool isAtLeastOneMale = false;
    
    while(current != NULL && !isAtLeastOneMale)
    {
        if(!current->data.isRadioactiveMutant())
        {
            if(current->data.getSex().compare("male"))
            {
                if(current->data.getAge() >= 2)
                {
                    isAtLeastOneMale = true;
                    cout << "there is @least 1 non-mutantVamp male w/age > 2\n "<<endl;
                }
                else
                {
                    current = current->next;
                    //if(current != NULL) bunny = current->data;
                }
            }
            else
            {
                current = current->next;
                //if(current != NULL) bunny = current->data;
            }
        }
        
        current = current->next;
        //if(current != NULL) bunny = current->data;
    }
    
    current = head;
    //bunny = current->data;
    Rabbit newBaby;
    
    if(isAtLeastOneMale)
    {
        while(current != NULL)
        {
            if(current->data.getSex() == "female" && current->data.getAge() >= 2)
            {
                cout <<current->data.getColor() <<" "<< current->data.getSex() << " is about to give birth! " <<endl;
                
                newBaby = Rabbit(current->data.getColor());
                babyBunniesList.addNode(newBaby);
                
                cout << current->data.getSex() << " just gave birth to " << newBaby.getColor() <<" "<< newBaby.getName() <<"\n"<< endl;
            }
            
            current = current->next;
            //if(current != NULL) bunny = current->data;
            
        }
    }
    
    //babyBunniesList.printList();
               
    return babyBunniesList;
    
}

int LinkedList::howManyMutantsBorn(LinkedList newbornsList)
{
    int count = 0;
    current = newbornsList.getHead();
    
    while(current != NULL)
    {
        if(current->data.isRadioactiveMutant())
        {
            count++;
        }
        
        current = current->next;
    }
    
    return count;
}

void LinkedList::mutantBunniesInfect(int amountToInfect)
{
    current = head;
    int amountInfected = 0;
    
    while(current != NULL && amountInfected <= amountToInfect)
    {
        if(!current->data.isRadioactiveMutant())
        {
            current->data.setRadioMutantVampStatus(true);
            amountInfected++;
            cout << current->data.getName() << " was infected!"
            <<endl;
        }
        current = current->next;
    }
    
}
       

void LinkedList::bunniesGetOlder()
{

    current = head;
        
    while(current != NULL)
    {
        int ageOfBunny = current->data.getAge();
        current->data.increaseAge(ageOfBunny);
        /*cout << "A bunny just aged to " << current->data.getAge() << " yr(s) old" << endl;*/
        current = current->next;
    }
    
}

LinkedList LinkedList::bunniesDie()
{
    LinkedList olderBunniesList;
    current = head;
    nodePtr deadBunny;
    
    while(current != NULL)
    {
        if(current->data.getAge() > 10)
        {
            olderBunniesList.addNode(current->data);
            deadBunny = current;
            
        }
        
        
        if(deadBunny != NULL)
        {
            deleteNode(deadBunny->data);
            deadBunny = NULL;
        }
        current = current->next;
    }
    
    return olderBunniesList;
}

#endif /* LINKEDLIST_CPP */
