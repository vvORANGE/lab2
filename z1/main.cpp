#include <iostream>
#include "AEROFLOT.h"

void sortFlights(AEROFLOT* flights, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (flights[j].getFlightNumber() > flights[j + 1].getFlightNumber()) {
                std::swap(flights[j], flights[j + 1]);
            }
        }
    }
}

void displayAllFlights(const AEROFLOT* flights, int count) {
    if (count == 0) {
        std::cout << "No flights available.\n";
        return;
    }
    std::cout << "All recorded flights:\n";
    for (int i = 0; i < count; ++i) {
        std::cout << flights[i] << std::endl;
    }
}

int main() {
    int count = 0;
    AEROFLOT* flights = nullptr;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Add flight\n";
        std::cout << "2. Search flights by destination\n";
        std::cout << "3. Display all flights\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            AEROFLOT* temp = new AEROFLOT[count + 1];
            for (int i = 0; i < count; ++i) {
                temp[i] = flights[i];
            }
            delete[] flights;
            flights = temp;

            std::cin >> flights[count];
            count++;

            sortFlights(flights, count);

        } else if (choice == 2) {
            std::string destination;
            std::cout << "Enter destination to search: ";
            std::cin >> destination;

            bool found = false;
            for (int i = 0; i < count; ++i) {
                if (flights[i].getDestination() == destination) {
                    std::cout << flights[i] << std::endl;
                    found = true;
                }
            }
            if (!found) {
                std::cout << "No flights found for destination: " << destination << std::endl;
            }

        } else if (choice == 3){
            displayAllFlights(flights, count);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    delete[] flights;
    return 0;
}
