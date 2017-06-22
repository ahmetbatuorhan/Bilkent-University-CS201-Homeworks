#include "Flight.h"
#include <iostream>

/*
**
** Name: Ahmet Batu
** Surname : Orhan
** ID: 21402365
**
*/

using namespace std;

// CONSTRUCTORS
Flight::Flight(int flightNumber, int rowNumber, int colNumber)
{
    this->flightNumber = flightNumber;
    this->rowNumber = rowNumber;
    this->colNumber = colNumber;
    this->totalReservations = 0;

}

Flight::Flight()
{
    this->flightNumber = 0;
    this->rowNumber = 0;
    this->colNumber = 0;
    this->totalReservations = 0;
}

Flight::~Flight()
{
}

// METHODS

int Flight::allSeats()
{
    return rowNumber * colNumber;
}

int Flight::availableSeats()
{
    return ((rowNumber * colNumber) - totalReservations);
}

void Flight::incrementReservation(int incrementNumber)
{
    totalReservations += incrementNumber;
}

void Flight::decreaseReservation(int decreaseNumber)
{
    totalReservations = totalReservations - decreaseNumber;
}

void Flight::makeSeatsDefault()
{
    this->totalReservations = 0;
}



// Getters and Setters
void Flight::setFlightNumber(int newFlightNumber)
{
    this->flightNumber = newFlightNumber;
}

void Flight::setRowNumber(int newRowNumber)
{
    this->rowNumber = newRowNumber;
}

void Flight::setColNumber(int newColNumber)
{
    this->colNumber = newColNumber;
}

int Flight::getFlightNumber()
{
    return this->flightNumber;
}

int Flight::getRowNumber()
{
    return this->rowNumber;
}

int Flight::getColNumber()
{
    return this->colNumber;
}

int Flight::getReservationNumber()
{
    return totalReservations;
}


