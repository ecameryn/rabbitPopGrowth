#ifndef RABBIT_CPP
#define RABBIT_CPP

#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

class Rabbit
{
private:
    string name; //get from bunnyName file
    string sex; //enum: 0 = male, 1 = female;
    string color;
    int age;
    bool radioactive_mutant_vampire_bunny; //2% probability
    bool deceased;
    
    static int maleBunnyCount;
    static int femaleBunnyCount;
    static int populationTotal;
    static int totalBirths;
    static int totalDeaths;
    
    
    
public:
    void setName(string name){this -> name = name;}
    void setSex(string sex){this -> sex = sex;}
    void setColor(string color){this -> color = color;}
    void setAge(int age){this -> age = age;}
    void setRadioMutantVampStatus(bool choice){radioactive_mutant_vampire_bunny = choice;}
    void setDeceased(bool choice){deceased = choice;}
    
    
    string getName(){return this->name;}
    string getSex(){return this->sex;}
    string getColor(){return this->color;}
    int getAge(){return this->age;}
    bool isRadioactiveMutant(){return this->radioactive_mutant_vampire_bunny;}
    bool isDeceased(){return this->deceased;}
    void increaseAge(int age)
    {
        this->setAge(this->getAge()+1);
    }
    void toString();
    int getPopulationTotal(){return totalBirths - totalDeaths;}
    
    
    Rabbit();
    
    Rabbit (string, string, string, int, bool);
    
    Rabbit(string);
    
    //~Rabbit(); Must implement all functions/methods that are declared
    
};

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

Rabbit::Rabbit(string name, string sex, string color, int age, bool mutantStatus)
{
	setName(name);
	setSex(sex);
	setColor(color);
	setAge(age);
	setRadioMutantVampStatus(mutantStatus);
}

Rabbit::Rabbit(string color)
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
	

	setColor(color);
	
	setAge(0);
	
	
	//set radioactive_mutant_vampire_bunny status
	int isRandNum1 = rand() % 100 + 1;
	int isRandNum2 = rand() % 100 + 1;
	if(isRandNum1 == 1 && isRandNum2 == 2){setRadioMutantVampStatus(true);}
	
	setDeceased(false);
		
}

#endif /* RABBIT_CPP */
