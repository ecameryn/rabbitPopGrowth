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
    
   
    //Bunnies Are Born
    cout << "\n\before bunnies are born" << endl;
    LinkedList newbornBunnies = bunnyList.bunniesAreBorn();
    cout << "\n\nafter bunnies are born" << endl;
    cout << "****************Newborns(TOP)*******************" << endl;
    
    if(newbornBunnies.getHead() != NULL) newbornBunnies.printList();
    else cout << "noBirths" << endl;
    
    cout << "****************Newborns≥(END)*******************\n" << endl;
    
    int newMutantsCount = bunnyList.howManyMutantsBorn(newbornBunnies);
    
    //Newborn Bunnies Added to bunnyList
    if(newbornBunnies.getHead() != NULL)
    {
        //cout << "\n\nAdding newborns to family!\n\n" << endl;
        bunnyList = bunnyList.combineNewbornsList(newbornBunnies);
    }
    
    
    cout << "\n\nPRINTING NEW POPULATION:" << endl;
    bunnyList.printList();
    
    cout << "***********************************" << endl;
    cout << bunnyList.getSize() << " bunnies are in the population"<< endl;
    cout << "***********************************\n" << endl;
    
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
    
    cout << "\n\nMutantVampires Attack!!!" << endl;
    bunnyList.mutantBunniesInfect(newMutantsCount);
    
    //delete bunnyList.getHead();
    bunnyNamesFile.close();
    
    
    return 0;
}
