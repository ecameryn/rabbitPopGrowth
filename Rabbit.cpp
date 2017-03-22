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
    
    
    string getName(){return name;}
    string getSex(){return sex;}
    string getColor(){return color;}
    int getAge(){return age;}
    bool isRadioactiveMutant(){return radioactive_mutant_vampire_bunny;}
    bool isDeceased(){return deceased;}
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


Rabbit::Rabbit()
{
    setName("sameName");
    
    
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
    
    
    setColor("white");
    
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
	setName("sameName");
	
	
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
