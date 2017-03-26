

/*
 * File:   main.cpp
 * Author: Cameryn
 */


#include "Rabbit.cpp"
#include "LinkedList.cpp"


int main(int argc, char** argv)
{
    
    LinkedList bunnyList;
    
    Rabbit bunny1 = Rabbit();
    Rabbit bunny2 = Rabbit();
    Rabbit bunny3 = Rabbit();
    Rabbit bunny4 = Rabbit();
    Rabbit bunny5 = Rabbit();
    
    bunnyList.addNode(bunny1);
    bunnyList.addNode(bunny2);
    bunnyList.addNode(bunny3);
    bunnyList.addNode(bunny4);
    bunnyList.addNode(bunny5);
    
    cout << "\n\nPRINTING ORIGIN POPULATION:" << endl;
    bunnyList.printList();
    cout << "***********************************" << endl;
    cout << bunnyList.getSize() << " bunnies are in the population"<< endl;
    cout << "***********************************\n" << endl;

    int newMutantsCount = 0;
    int x = 0;
    
    //Begin
    while(x < 1000)
    {
        
        //Cull Half of Colony if Population is Greater Than 1000
        if(bunnyList.getSize() > 1000)
        {
            cout << "Colony Population = " << bunnyList.getSize() << endl;
            bunnyList = bunnyList.cullHalfPopulation();
            cout << "Famine Caused Population to Decrease to: " << bunnyList.getSize() << endl;
        }
        
        //Terminate Program When All Bunnies Die
        if(bunnyList.allDead())
        {
            cout<< "colony age: " << bunnyList.getColonyAge() << endl;
            return 0;
        }
        
        cout << "\n***************************************************" << endl;
        cout << "***************************************************" << endl;
        cout << "***************************************************" << endl;
        cout << "****************PASS # " << x << "*****************"<< endl;
        cout << "***************************************************" << endl;
        cout << "***************************************************" << endl;
        cout << "***************************************************\n" << endl;
        
        //Age the bunnies by 1 year through each pass
        bunnyList.bunniesGetOlder();
        
        
        //Bunnies Don't Live Past 10yrs of Age
        if(bunnyList.atLeastOneElder() )
        {
            //Bunnies Get Old and Die
            LinkedList olderBunniesList = bunnyList.bunniesDie();
            
            cout << "================DEAD Bunnies(TOP)===================" << endl;
            
            if(olderBunniesList.getHead() != NULL) olderBunniesList.printList();
            else cout<< "noDeaths" << endl;
            
            cout << "================DEAD Bunnies(END)===================\n\n\n" << endl;
            
        }
        
        //Bunnies Are Born And Can Infect Colony if They Are Mutants
        if(bunnyList.getColonyAge() > 2 && bunnyList.hasOneNonMutantMale())
        {
            LinkedList newbornBunniesList = bunnyList.bunniesAreBorn();
            
            cout <<"+++++++++++++++Newborns(TOP)++++++++++++++++" << endl;
            
            if(newbornBunniesList.getHead() != NULL) newbornBunniesList.printList();
            else cout << "noBirths" << endl;
            
            cout << "+++++++++++++++Newborns(END)++++++++++++++++\n" << endl;
            cout << "              ["
                 << newbornBunniesList.getSize()
                 <<" Total Newborns]"<<"              \n" << endl;
            
            //Newborn Bunnies Added to bunnyList
            if(newbornBunniesList.getHead() != NULL)
            {
                bunnyList = bunnyList.combineNewbornsList(newbornBunniesList);
            }
            
            newMutantsCount = bunnyList.howManyMutantsBorn(newbornBunniesList);
            
            
            if(newMutantsCount > 0)
            {
                cout << "\n\nNewBornRadioactiveMutantVampires Attack!!!" << endl;
                bunnyList.mutantBunniesInfect(newMutantsCount);
            }
        }
        
        cout << "\n\nPRINTING NEW POPULATION:" << endl;
        bunnyList.printList();
        
        cout << "***********************************" << endl;
        cout << bunnyList.getSize() << " bunnies are in the population"<< endl;
        cout << "***********************************\n" << endl;
    
    
        x++;
    }
    
    cout << "\n\nPRINTING FINAL POPULATION:" << endl;
    bunnyList.printList();
    
    cout << "***********************************" << endl;
    cout << bunnyList.getSize() << " bunnies are in the population (FINAL)"<< endl;
    cout << "***********************************\n" << endl;
    
    //cout<< "colony age: " << bunnyList.getColonyAge() << endl;
    //bunnyList.printList();
    delete bunnyList.getHead();
    return 0;
    
}
