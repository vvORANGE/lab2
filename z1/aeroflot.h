#ifndef AEROFLOT_H
#define AEROFLOT_H

#include <iostream>
#include <string>
#include <stdexcept>

class AEROFLOT {
private:
    std::string destination;
    int flightNumber;
    std::string aircraftType;

public:
    AEROFLOT();
    AEROFLOT(const std::string& dest, int num, const std::string& type);
    AEROFLOT(const AEROFLOT& other);
    ~AEROFLOT();

    void setDestination(const std::string& dest);
    void setFlightNumber(int num);
    void setAircraftType(const std::string& type);

    const std::string& getDestination() const;
    int getFlightNumber() const;
    const std::string& getAircraftType() const;

    friend std::ostream& operator<<(std::ostream& os, const AEROFLOT& flight);
    friend std::istream& operator>>(std::istream& is, AEROFLOT& flight);

    static void validateFlightNumber(int num);
};

#endif // AEROFLOT_H
