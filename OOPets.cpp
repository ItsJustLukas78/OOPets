#include <iostream>
#include <vector>
#include <limits>
#include "OOPet.h"

int random(int max);
int selection(int min = 0, int max = 1);
void clearStream();

int main() {   
	
	std::vector<OOPet*> ownedPets;
	
	int mainLoop = 1;
	while (mainLoop == 1) {
		
		std::cout << '\n';
		std::cout << "|| ========================= ||" << '\n';
		std::cout << "|| Hello, welcome to OOPets! ||" << '\n';
		std::cout << "||                           ||" << '\n';
		std::cout << "|| Your options are:         ||" << '\n';
		std::cout << "|| 1. Adopt an OOPet         ||" << '\n';
		std::cout << "|| 2. Sell an OOPet          ||" << '\n';
		std::cout << "|| 3. Interact with OOPets   ||" << '\n';
		std::cout << "|| 0. Exit                   ||" << '\n';
		std::cout << "|| ========================= ||" << '\n';

		switch (selection(0, 3)) {
			case 1:
				std::cout << "\n" << "Your adoption options are:" << '\n';
				std::cout << "1. Dog" << '\n';
				std::cout << "2. Cat" << '\n';
				std::cout << "0. Return" << '\n';

				switch (selection(0, 2)) {
					case 1: {
						std::cout << "\n" << "What would you like to name your dog?" << '\n';
						std::string name;
						std::cin >> name;
						Dog *newDog = new Dog(name);
						ownedPets.push_back(newDog);
						std::cout << "You adopted " << (newDog->name) << '\n';
						break;
					}
					case 2: {
						std::cout << "\n" << "What would you like to name your cat?" << '\n';
						std::string name;
						std::cin >> name;
						Cat *newCat = new Cat(name);
						ownedPets.push_back(newCat);
						std::cout << "You adopted " << (newCat->name) << '\n';
						break;
					}
				}
				break;
					
			case 2:
				if (ownedPets.size() == 0) {
					std::cout << "You don't have any pets to give way!" << '\n';
				}
				else {
					std::cout << "\n" << "Which pet would you like give away?" << '\n';
					for (int i = 0; i < ownedPets.size(); i++) {
						std::cout << i + 1 << ". " << ownedPets[i]->name << '\n';
					}

					ownedPets.erase(ownedPets.begin() + (selection(1 , ownedPets.size()) - 1));
					ownedPets.shrink_to_fit();
					std::cout << ownedPets.size() << '\n';
				}
				break;
				
			case 3:
				if (ownedPets.size() == 0) {
					std::cout << "You don't have any pets to interact with!" << '\n';
				}
				else {
					std::cout << "\n" << "Which pet would you like to interact with?" << '\n';
					for (int i = 0; i < ownedPets.size(); i++) {
						std::cout << i + 1 << ". " << ownedPets[i]->name << '\n';
					}

					ownedPets[selection(1, ownedPets.size()) - 1]->interact();	
				}
				break;
				
			case 0:
				mainLoop = 0;
		}
	}

	for (int i = 0; i < ownedPets.size(); i++) {
		delete ownedPets[i];
	}

	return 0;
}


int random(int max) {
	srand(time(NULL));
	return rand() % max;
}

int selection(int min, int max) {
	int selection = 0;

	while (true) {
		if (std::cin >> selection) {
			if (selection >= min && selection <= max) {
				break;
			}
			else {
				std::cout << "Selection does not exist!" << '\n';
			}
		}
		else {
			std::cout << "Input is not an integer value!" << '\n';
		}
		clearStream();
	}

	return selection;
}

void clearStream() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
