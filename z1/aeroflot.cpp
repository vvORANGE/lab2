#include "AEROFLOT.h"

// Конструктор по умолчанию
AEROFLOT::AEROFLOT() : flightNumber(0) {
    std::cout << "Default constructor called for AEROFLOT\n";
}

// Конструктор с параметрами
AEROFLOT::AEROFLOT(const std::string& dest, int num, const std::string& type) {
    std::cout << "Parameterized constructor called for AEROFLOT\n";
    setDestination(dest);
    setFlightNumber(num);
    setAircraftType(type);
}

// Конструктор копирования
AEROFLOT::AEROFLOT(const AEROFLOT& other) : destination(other.destination), flightNumber(other.flightNumber), aircraftType(other.aircraftType) {
    std::cout << "Copy constructor called for AEROFLOT\n";
}

// Деструктор
AEROFLOT::~AEROFLOT() {
    std::cout << "Destructor called for AEROFLOT\n";
}

// Установка значения пункта назначения
void AEROFLOT::setDestination(const std::string& dest) {
    destination = dest;
}

// Установка номера рейса
void AEROFLOT::setFlightNumber(int num) {
    validateFlightNumber(num);
    flightNumber = num;
}

// Установка типа самолета
void AEROFLOT::setAircraftType(const std::string& type) {
    aircraftType = type;
}

// Получение значения пункта назначения
const std::string& AEROFLOT::getDestination() const {
    return destination;
}

// Получение номера рейса
int AEROFLOT::getFlightNumber() const {
    return flightNumber;
}

// Получение типа самолета
const std::string& AEROFLOT::getAircraftType() const {
    return aircraftType;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const AEROFLOT& flight) {
    os << "Flight Number: " << flight.flightNumber 
       << ", Destination: " << flight.destination 
       << ", Aircraft Type: " << flight.aircraftType;
    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, AEROFLOT& flight) {
    std::string buffer;
    std::cout << "Enter destination: ";
    is >> buffer;
    flight.setDestination(buffer);
    
    int num;
    std::cout << "Enter flight number: ";
    is >> num;
    flight.setFlightNumber(num);
    
    std::cout << "Enter aircraft type: ";
    is >> buffer;
    flight.setAircraftType(buffer);

    return is;
}

// Проверка номера рейса
void AEROFLOT::validateFlightNumber(int num) {
    if (num <= 0) {
        throw std::invalid_argument("Flight number must be positive.");
    }
}

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

void editFlight(AEROFLOT& flight) {
    std::string newDestination, newAircraftType;
    int newFlightNumber;

    std::cout << "Editing flight: " << flight << std::endl;

    std::cout << "Enter new destination: ";
    std::getline(std::cin >> std::ws, newDestination);
    if (!newDestination.empty()) {
        flight.setDestination(newDestination);
    }

    std::cout << "Enter new flight number: ";
    std::string input;
    std::getline(std::cin >> std::ws, input);
    if (!input.empty()) {
        newFlightNumber = std::stoi(input);
        flight.setFlightNumber(newFlightNumber);
    }

    std::cout << "Enter new aircraft type: ";
    std::getline(std::cin >> std::ws, newAircraftType);
    if (!newAircraftType.empty()) {
        flight.setAircraftType(newAircraftType);
    }

    std::cout << "Flight updated: " << flight << std::endl;
}

void deleteFlight(AEROFLOT*& flights, int& count, int index) {
    if (index < 0 || index >= count) {
        std::cout << "Invalid index. Flight cannot be deleted." << std::endl;
        return;
    }

    AEROFLOT* temp = new AEROFLOT[count - 1];
    for (int i = 0, j = 0; i < count; ++i) {
        if (i != index) {
            temp[j++] = flights[i];
        }
    }

    delete[] flights;
    flights = temp;
    count--;

    std::cout << "Flight deleted successfully." << std::endl;
}