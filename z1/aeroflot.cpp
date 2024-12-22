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
