/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    
    cout << "\n\nPRINTING NEW POPULATION:" << endl;
    bunnyList.printList();
    cout << "***********************************" << endl;
    cout << bunnyList.getSize() << " bunnies are in the population"<< endl;
    cout << "***********************************\n" << endl;
    
    
    bunnyList.bunniesGetOlder();
    /*bunnyList.bunniesGetOlder();
    bunnyList.bunniesGetOlder();
    bunnyList.bunniesGetOlder();
    bunnyList.bunniesGetOlder();
    bunnyList.bunniesGetOlder();
    bunnyList.bunniesGetOlder();
    bunnyList.bunniesGetOlder();
    bunnyList.bunniesGetOlder();
    bunnyList.bunniesGetOlder();
    bunnyList.bunniesGetOlder();*/
    
    //cout << "\n\nBunnies got older!\n\n" << endl;
    int newMutantsCount = 0;
    int x = 0;
    
    while(x < 100)
    {
        //Age the bunnies by 1 year through each pass
        bunnyList.bunniesGetOlder();
        //Bunnies Are Born
        if(bunnyList.getColonyAge() > 2 && bunnyList.hasOneNonMutantMale())
        {
            LinkedList newbornBunniesList = bunnyList.bunniesAreBorn();
            
            cout << "****************Newborns(TOP)*******************" << endl;
            
            if(newbornBunniesList.getHead() != NULL) newbornBunniesList.printList();
            else cout << "noBirths" << endl;
            
            cout << "****************Newborns(END)*******************\n" << endl;
            
            //Newborn Bunnies Added to bunnyList
            if(newbornBunniesList.getHead() != NULL)
            {
                //cout << "\n\nAdding newborns to family!\n\n" << endl;
                bunnyList = bunnyList.combineNewbornsList(newbornBunniesList);
            }
            
             newMutantsCount = bunnyList.howManyMutantsBorn(newbornBunniesList);
            
            cout << "\n\nNewBornRadioactiveMutantVampires Attack!!!" << endl;
            if(newMutantsCount > 0){
                bunnyList.mutantBunniesInfect(newMutantsCount);}
        }
        
        
        
        cout << "\n\nPRINTING NEW POPULATION:" << endl;
        bunnyList.printList();
        
        cout << "***********************************" << endl;
        cout << bunnyList.getSize() << " bunnies are in the population"<< endl;
        cout << "***********************************\n" << endl;
    
        if(bunnyList.getColonyAge() > 10)
        {
            //Bunnies Get Old and Die
            LinkedList olderBunnies = bunnyList.bunniesDie();
            //cout << "\n\nSlowSingingAndFlowerBringing\n\n" << endl;
            cout << "****************Obituary(TOP)*******************" << endl;
            
            if(olderBunnies.getHead() != NULL) olderBunnies.printList();
            else cout<< "noDeaths" << endl;
            
            cout << "****************Obituary(END)*******************\n" << endl;
            
            
            cout << "\n\nPRINTING NEW POPULATION:" << endl;
            bunnyList.printList();
            
            cout << "***********************************" << endl;
            cout << bunnyList.getSize() << " bunnies are in the population"<< endl;
            cout << "***********************************\n" << endl;
        }
    
    
    
    
    
    
        x++;
    }
    
    
    // x = x + 1;
    //}
    
    //bunnyList.printList();
    //delete bunnyList.getHead();
    return 0;
    
}
