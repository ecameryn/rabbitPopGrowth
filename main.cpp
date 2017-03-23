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
    
    bunnyList.printList();
    cout << "***********************************" << endl;
    cout << bunnyList.getSize() << " bunnies are in the list"<< endl;
    cout << "***********************************\n" << endl;
    
   /* bunnyList.deleteNode(bunny3);
    bunnyList.deleteNode(bunny4);
    bunnyList.deleteNode(bunny5);
    
    bunnyList.printList();
    cout << "***********************************" << endl;
    cout << bunnyList.getSize() << " bunnies are in the list"<<endl;
    cout << "***********************************\n" << endl;*/
    
    /*cin >> "Press "
    int x = 1;
    while(x < 2)
    {*/
        
        
        //then the totalBirths increases by femaleBunnyCount
        
        //loop through vector and for each female,
        //create/add a newBunny to vector, with their
        //color as: newBunny.setColor(female.getColor())
        
        //loop through vector destroying any dead bunnies:
        // if (bunny.getAge > 10 && !bunny.isRadioactiveMutant) totalDeaths++; setDeceased(true);
        // if (bunny.isRadioactiveMutant && bunny.age > 50) totalDeaths++; setDeceased(true);
        
        //loop through vecotor: if(bunny.age == 0 && bunny.isRadioactiveMutant)
        //						{ pick random vectorIndex# to change to mutant}
        
        
        //loop through vector toString for each bunny
        
        //loop through vector: if(bunny.age == 0 && bunny.isRadioactiveMutant)
        //					   {print Bunny bunny.getName was born}
        //					   if(bunny.age == 0 && !bunny.isRadioactiveMutant)
        //					   {print Radio mut vamp bunny bunny.getName was born}
        //					   if(isDeceased()){Bunny bunny.getName died; if female/male reduce female or male bunny count}
        
        //write output to file
        
        //if(getPopulationTotal == 0) GAME OVER
        //if(getPopulationTotal > 1000) food shortage kills half @random
        
        bunnyList.bunniesGetOlder();
        bunnyList.bunniesGetOlder();
        bunnyList.bunniesGetOlder();
        cout << "\n\nBunnies got older!\n\n" << endl;
    
    
        LinkedList newbornBunnies = bunnyList.bunniesAreBorn();
        cout << "****************Newborns*******************" << endl;
    
        newbornBunnies.printList();
    
        cout << "****************Newborns*******************\n" << endl;
        if(newbornBunnies.getHead() != NULL)
        {
            cout << "\n\nAdding newborns to family!\n\n" << endl;
            bunnyList = bunnyList.combineNewbornsList(newbornBunnies);
        }
    
    
        cout << "\n\nPRINTING LAST LIST:\n" << endl;
        bunnyList.printList();
    
        delete bunnyList.getHead();
        bunnyNamesFile.close();
    
    
    
      // x = x + 1;
    //}
    
    //bunnyList.printList();
    
    return 0;
    
}

