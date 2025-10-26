#include "animal.h"
#include <iostream>

using namespace std;

void Zebra::printInfo() const {
	std::cout << "Zebra, Name: " << name << ", Age: " << age << ", Number of stripes: " << numStripes << std::endl;
}

void Cat::printInfo() const {
	std::cout << "Cat, Name: " << name << ", Age: " << age << ", Favorite toy: " << favoriteToy << std::endl;
}

Animal::Animal(string _name, int _age) : name(_name), age(_age) {}