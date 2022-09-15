#pragma once
#include <iostream>
#include <vector>

class OOPet {
	
public:

	std::string name;
	OOPet(std::string newName);
	virtual void interact() = 0;

protected:

	void feed();
	void stats();
	float level; 
	bool happy;

};

class Dog : public OOPet {

	static std::vector<std::string> goodNoises;
	static std::vector<std::string> badNoises;
	void walk();
	void fetch();

public:

	void interact();
	Dog(std::string newName);

};

class Cat : public OOPet {

	static std::vector<std::string> goodNoises;
	static std::vector<std::string> badNoises;
	void pat();
	void play();

public:

	void interact();
	Cat(std::string newName);
	
};