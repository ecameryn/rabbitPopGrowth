#ifndef RABBIT_CPP
#define RABBIT_CPP

#include "Rabbit.hpp"

int Rabbit::maleBunnyCount = 0;
int Rabbit::femaleBunnyCount = 0;
int Rabbit::populationTotal = 0; 
int Rabbit::totalBirths = 0;
int Rabbit::totalDeaths = 0;

string lineWithName;
ifstream bunnyNamesFile("bunnyNames.txt");

Rabbit::Rabbit()
{
    //set bunny name from line in .txt file
    if(bunnyNamesFile.is_open())
    {
        getline(bunnyNamesFile, lineWithName);
        setName(lineWithName);
    }
    
    
    
    //set sex
    int sexNum = rand() % 2;
    if(sexNum == 0)
    {
        setSex("male");
        maleBunnyCount++;
    }
    if(sexNum == 1)
    {
        setSex ("female");
        femaleBunnyCount++;
    }
    
    //set color
    int colorNum = rand() % 4;
    //white=0,brown=1,black=2,spotted=3
    if(colorNum == 0) setColor("white");
    else if(colorNum == 1) setColor("brown");
    else if(colorNum == 2) setColor("black");
    else if(colorNum == 3) setColor("spotted");
    
    setAge(0);
    
    //set radioactive_mutant_vampire_bunny status
    int isRandNum1 = rand() % 100 + 1;
    int isRandNum2 = rand() % 100 + 1;
    if(isRandNum1 == 1 && isRandNum2 == 2){setRadioMutantVampStatus(true);}
    
    setDeceased(false);
}

Rabbit::Rabbit(string color)
{
    //set bunny name from line in .txt file
    if(bunnyNamesFile.is_open())
    {
        while(bunnyNamesFile.peek() == ' ') bunnyNamesFile.get();
        getline(bunnyNamesFile, lineWithName);
        while(bunnyNamesFile.peek() == ' ') bunnyNamesFile.get();
        setName(lineWithName);
    }
    
    
    //set sex
    int sexNum = rand() % 2;
    if(sexNum == 0)
    {
        setSex("male");
        maleBunnyCount++;
    }
    if(sexNum == 1)
    {
        setSex ("female");
        femaleBunnyCount++;
    }
    
    
    setColor(color);
    
    setAge(0);
    
    
    //set radioactive_mutant_vampire_bunny status
    int isRandNum1 = rand() % 100 + 1;
    int isRandNum2 = rand() % 100 + 1;
    if(isRandNum1 == 1 && isRandNum2 == 2){setRadioMutantVampStatus(true);}
    
    setDeceased(false);
    
}

Rabbit::Rabbit(string name, string sex, string color, int age, bool mutantStatus)
{
	setName(name);
	setSex(sex);
	setColor(color);
	setAge(age);
	setRadioMutantVampStatus(mutantStatus);
}



#endif /* RABBIT_CPP */
