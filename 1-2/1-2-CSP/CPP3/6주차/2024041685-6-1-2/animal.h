#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>
using namespace std;

class Animal{
	public:
		Animal(string _name, int _age);
		virtual void printInfo() const = 0;
	protected:
		string name;
		int age;
};

class Zebra : public Animal {
	public:
		Zebra(string name, int age, int numStripes) : Animal(name, age), numStripes(numStripes) {}
		
		void printInfo() const override;
	
	private:
		int numStripes;
};

class Cat : public Animal {
	public:
		Cat(string name, int age, string favoriteToy) : Animal(name, age), favoriteToy(favoriteToy) {}
		
		void printInfo() const override;
	
	private:
		string favoriteToy;
};

#endif
