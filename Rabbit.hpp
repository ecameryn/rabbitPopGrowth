//
//  delete.hpp
//  
//
//  Created by Cameryn Holstick on 3/23/17.
//
//

#ifndef Rabbit_hpp
#define Rabbit_hpp

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
    Rabbit();
    Rabbit(string);
    Rabbit (string, string, string, int, bool);
    //~Rabbit(){}
    
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
    
};


#endif /* Rabbit_hpp */
