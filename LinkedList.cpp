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
        cout<< "\n" << endl;
        
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
    //cout << "\n\ninside bunnies are born" << endl;
    LinkedList babyBunniesList;
    current = head;
    Rabbit newBaby;
    //bool atLeast1ViableMale = false;
    //Rabbit bunny = current->data;
    
    while(current != NULL)
    {
        if(current->data.getSex() == "female" && !current->data.isRadioactiveMutant())
        {
            cout <<current->data.getColor() <<" "
                << current->data.getSex()
                << " is about to give birth! "
                <<endl;
            
            newBaby = Rabbit(current->data.getColor());
            babyBunniesList.addNode(newBaby);
            
            cout<< current->data.getSex() <<" "
                << " just gave birth to "
                << newBaby.getColor() <<" "
                << newBaby.getName() <<"\n"
                << endl;
        }
        
        current = current->next;
    }
    
    return babyBunniesList;
    
}


bool LinkedList::hasOneNonMutantMale()
{
    bool nonMutantMale = false;
    current = head;
    
    while (current != NULL)
    {
        if(current->data.getSex().compare("male") && !current->data.isRadioactiveMutant())
        {
            nonMutantMale = true;
            return nonMutantMale;
        }
    }
    
    return nonMutantMale;
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
            cout << current->data.getName() << " was infected!" << endl;
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
    
    colonyAge++;
    
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

bool LinkedList::atLeastOneElder()
{
    current = head;
    bool isElder = false;
    
    while(current != NULL)
    {
        if(current->data.getAge() >= 10)
        {
            isElder = true;
            return isElder;
        }
        current = current->next;
    }
    
    return isElder;
}

LinkedList LinkedList::cullHalfPopulation()
{
    LinkedList afterCullList;
    int cullBy = getSize() / 2;
    current = head;
    
    cout << "In cullHalfPop. Will Cull: "<< cullBy << endl;
    while (cullBy >= 0 && afterCullList.getSize() == cullBy)
    {
        afterCullList.addNode(current->data);
        nodePtr oldCurr = current;
        current = current->next;
        deleteNode(oldCurr->data);
        cullBy--;
        cout << "In cullHalfPop->while." << endl;
        cout << "Size of afterCullList: " << afterCullList.getSize()<< endl;
    }
    
    cout << "Coming out of cullHalfPop." << endl;
    return afterCullList;
}

bool LinkedList::allDead()
{
    if(getSize() < 2) return true;
    //if()
    else return false;
}

#endif /* LINKEDLIST_CPP */
