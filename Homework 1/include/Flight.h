#ifndef FLIGHT_H
#define FLIGHT_H

/*
**
** Name: Ahmet Batu
** Surname : Orhan
** ID: 21402365
**
*/


class Flight
{
    public:

        // CONSTRUCTORS
        Flight(int flightNumber, int rowNumber, int colNumber);
        Flight();
        ~Flight();

        // METHODS

        int availableSeats();
        int allSeats();
        void incrementReservation(int incrementNumber);
        void decreaseReservation(int decreaseNumber);
        void makeSeatsDefault();


        // Getters & Setters increment
        void setFlightNumber(int newFlightNumber);
        void setRowNumber(int newRowNumber);
        void setColNumber(int newColNumber);
        int getFlightNumber();
        int getRowNumber();
        int getColNumber();
        int getReservationNumber();


    private:
        int flightNumber;
        int rowNumber;
        int colNumber;
        int totalReservations;
};

#endif // FLIGHT_H
