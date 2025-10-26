#include <iostream>
#include <string>
#include "vehicle.h"
#include <sstream>

using namespace std;

int main() {
	Vehicle* vehicle_arr = new Vehicle[10];
	int vehicleCount = 0;

	for (int i=0; i < 10; i++) {
		string brand;
		int year, mileage;

		cin >> brand;

		if (brand == "0") {
			break;
		}

		cin >> year >> mileage;

		vehicle_arr[i] = Vehicle(brand, year, mileage);
		vehicleCount++;
	
	}

	while(true) {
		string input;

		std::cout << "Update?\n";

		getline(cin >> ws, input);
		
		istringstream iss(input);
		string command;
		int vehicleIndex;
		int newMileage, currentMileage, distance;

		iss >> command;

		if(command == "y") {
			
			
			iss >> vehicleIndex;

			if (vehicleIndex < 0 || vehicleIndex >= vehicleCount) {
				exit(1);
			}

			if(iss >> newMileage) {
				if (iss >> distance) {
					vehicle_arr[vehicleIndex].updateMileage(newMileage, distance);
				} else {
					vehicle_arr[vehicleIndex].updateMileage(newMileage);
				}
			} else {
				exit(1);
			}



			for (int i=0; i < vehicleCount; i++) {
				vehicle_arr[i].printVehicle();
			}
		} else {
			break;
		}
	}

	delete[] vehicle_arr;

			
	return 0;
}
