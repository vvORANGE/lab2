#include <iostream>
#include "AEROFLOT.h"



int main() {
    int count = 0;
    AEROFLOT* flights = nullptr;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Add flight\n";
        std::cout << "2. Search flights by destination\n";
        std::cout << "3. Edit flight\n";
        std::cout << "4. Delete flight\n";
        std::cout << "5. Show flights\n";
        std::cout << "6. Exit\n";
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

        } else if (choice == 3) {
            int index;
            std::cout << "Enter index of flight to edit (0 to " << count - 1 << "): ";
            std::cin >> index;
            if (index >= 0 && index < count) {
                editFlight(flights[index]);
                sortFlights(flights, count);
            } else {
                std::cout << "Invalid index." << std::endl;
            }

        } else if (choice == 4) {
            int index;
            std::cout << "Enter index of flight to delete (0 to " << count - 1 << "): ";
            std::cin >> index;
            deleteFlight(flights, count, index);
            sortFlights(flights, count);

        } else if(choice == 5) {
            displayAllFlights(flights, count);
        } else if (choice == 6) {
            break;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    delete[] flights;
    return 0;
}
