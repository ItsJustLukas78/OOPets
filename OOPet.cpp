#include <iostream>
#include <stdlib.h>
#include <vector>
#include "OOPet.h"

int random(int max);
int selection(int min = 0, int max = 1);

void OOPet::feed() {
	std::cout << "You fed " << name << "!" << '\n';

	if (random(5)) {
		std::cout << name << " enjoyed the food and is now happy!" << '\n';
		level += 0.1;
		happy = true;
	}
	else {
		if (happy == true) {
			std::cout << name << " is full! They are still happy!" << '\n';
		}
		else {
			std::cout << name << " doesn't eat and remains to be sad! They will not respond well to interations without eating food!" << '\n';
		}
	}
}

void OOPet::stats() {
	std::cout << "Name: " << name << '\n';
	std::cout << "Level: " << level << '\n';
	std::cout << "Mood: " << ((happy) ? "Happy" : "Sad") << '\n';
}

OOPet::OOPet(std::string newName) {
	name = newName;
	level = 0.0f;
	happy = true;
}

void Dog::walk() {
	if (happy) {
		std::cout << "You took " << name << " on a walk and they enjoyed it! " << goodNoises[random(goodNoises.size())] << '\n';
		level += 0.5;
		happy = random(5);
	}
	else {
		std::cout << name << " is unhappy! They refuse to take a walk! " << badNoises[random(badNoises.size())] << '\n';
	}
}

void Dog::fetch() {
	if (happy) {
		std::cout << "You played fetch with " << name << " who had so much fun! " << goodNoises[random(goodNoises.size())] << '\n';
		level += 0.5;
		happy = random(5);
	}
	else {
		std::cout << name << " is unhappy! They refuse to fetch the ball! Now you have to fetch it, how depressing! " << badNoises[random(badNoises.size())] << '\n';
	}
}

std::vector<std::string> Dog::goodNoises = {"bark", "woof", "arf", "ruff", "woof woof"};
std::vector<std::string> Dog::badNoises = {"ROOOFFFFF", "BARK BARK BARK", "GROWWWLLLLL"};

Dog::Dog(std::string newName) : OOPet(newName) {}

void Dog::interact() {
	int loop = 1;
	while (loop) {
		std::cout << "What would you like to do with " << name << "?" << '\n';
		std::cout << "1. Feed " << name << '\n';
		std::cout << "2. Walk " << name << '\n';
		std::cout << "3. Play fetch with " << name << '\n';
		std::cout << "4. Check stats" << '\n';
		std::cout << "0. Exit" << '\n';

		switch (selection(0, 4)) {
			case 1:
				feed();
				break;
			case 2:
				walk();
				break;
			case 3:
				fetch();
				break;
			case 4:
				stats();
				break;
			case 0:
				loop = 0;
		}
	}
}

void Cat::pat() {
	if (happy) {
		std::cout << "You patted  " << name << " .." << goodNoises[random(goodNoises.size())] << " they enjoy your presence!" << '\n';
		level += 0.5;
		happy = random(5);
	}
	else {
		std::cout << badNoises[random(badNoises.size())] << " " << name << " does not want to be patted!!" << " Stay away human!" << '\n';
	}
}

void Cat::play() {
	if (happy) {
		std::cout << "You brought out a toy mouse that  " << name << " playfully hunted for. " << goodNoises[random(goodNoises.size())] << " they love it!" << '\n';
		level += 0.5;
		happy = random(5);
	}
	else {
		std::cout << badNoises[random(badNoises.size())] << " " << name << " didn't even notice the toy mouse! They want to hunt you instead! RUN!" << '\n';
	}
}

std::vector<std::string> Cat::goodNoises = {"meow", "purrr", "meew"};
std::vector<std::string> Cat::badNoises = {"MEWL", "HISS", "GROWL", "MEOWWW"};


Cat::Cat(std::string newName) : OOPet(newName) {}

void Cat::interact() {
	int loop = 1;
	while (loop) {
		int choice = 0;
		std::cout << "What would you like to do with " << name << "?" << '\n';
		std::cout << "1. Feed " << name << '\n';
		std::cout << "2. Pat " << name << '\n';
		std::cout << "3. Play with " << name << '\n';
		std::cout << "4. Check stats" << '\n';
		std::cout << "0. Exit" << '\n';

		switch (selection(0, 4)) {
			case 1:
				feed();
				break;
			case 2:
				pat();
				break;
			case 3:
				play();
				break;
			case 4:
				stats();
				break;
			case 0:
				loop = 0;
		}
	}
}