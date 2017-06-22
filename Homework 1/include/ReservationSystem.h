#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H
#include "Flight.h"
#include "Reservation.h"
#include <iostream>

/*
**
** Name: Ahmet Batu
** Surname : Orhan
** ID: 21402365
**
*/

using namespace std;

class ReservationSystem
{
    public:
        // CONSTRUCTORS
        ReservationSystem();
        ~ReservationSystem();

        // METHODS
        // Void
        void addFlight( const int flightNo, const int rowNo, const int seatNo );
        void cancelFlight( const int flightNo );
        void showAllFlights();
        void showFlight( const int flightNo );
        void cancelReservation( const int resCode );
        void showReservation( const int resCode );
        // Others:
        int makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol );


    private:
        // VARIABLES
        int allFlights;
        int allReservations;
        Flight* allFlightsArray;
        Reservation reservation;

        // METHODS
        void showDetailedInformation(int flightNo);
        int totalReservations(int flightNo);
        char intToLetter(int n);

};

#endif // RESERVATIONSYSTEM_H
