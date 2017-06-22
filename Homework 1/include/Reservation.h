#ifndef RESERVATION_H
#define RESERVATION_H
#include "Flight.h"

/*
**
** Name: Ahmet Batu
** Surname : Orhan
** ID: 21402365
**
*/

class Reservation
{
    public:
        // CONSTRUCTORS
        Reservation();
        ~Reservation();

        // METHODS
        // Void:
        int addReservation(const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol);
        void deleteAllReservations(const int flightNo);
        void cancelReservation(int resCode);
        void showReservation(const int resCode);
        void cancelReservation2(int resCode);
        // Boolean:
        bool isFlightHasReservation(const int flightNo);
        bool isReserved(const int flightNo, const int rowInput, const int colInput);
        // Others
        char intToLetter(const int n);
        int letterToInt(const char input);


    private:
        //VARIABLES
        int totalReservations;
        int* passangerArr;
        int* flightNoArr;
        int** rowArr;
        int** colArr;
};

#endif // RESERVATION_H
