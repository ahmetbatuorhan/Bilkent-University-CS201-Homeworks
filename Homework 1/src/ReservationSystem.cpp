#include "ReservationSystem.h"
#include "Flight.h"
#include "Reservation.h"
#include <iostream>
#include <string>

/*
**
** Name: Ahmet Batu
** Surname : Orhan
** ID: 21402365
**
*/

using namespace std;

// CONSTRUCTORS
ReservationSystem::ReservationSystem()
{
    allFlights = 0;
    allReservations = 0;

    allFlightsArray = NULL;


}

ReservationSystem::~ReservationSystem()
{
    if(allFlightsArray != NULL)
    {
        delete[] allFlightsArray;
    }
}

// METHODS

// This method gets three int inputs(Flight Number/Row Number/Column Number) and then add Flight object
// to the Reservation System.
void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo)
{
    if(allFlightsArray == NULL)
    {
          allFlightsArray = new Flight[1];
        allFlightsArray[allFlights].setFlightNumber(flightNo);
        allFlightsArray[allFlights].setRowNumber(rowNo);
        allFlightsArray[allFlights].setColNumber(seatNo);

        cout << "Flight " << flightNo << " has been added" << endl;

        allFlights++;
    }
    else
    {
        bool sameFlight = false;
        for(int i = 0 ; i < allFlights ; i++)
        {
            if(allFlightsArray[i].getFlightNumber() == flightNo)
            {
                sameFlight = true;
            }
        }
        if(sameFlight)
        {
            cout << "Flight " << flightNo << " already exists" << endl;
        }
        else
        {
            Flight* temp = allFlightsArray;
            allFlightsArray = new Flight[allFlights + 1];

            for(int i = 0 ; i < allFlights ; i++)
            {
                allFlightsArray[i] = temp[i];
            }
            allFlightsArray[allFlights].setFlightNumber(flightNo);
            allFlightsArray[allFlights].setRowNumber(rowNo);
            allFlightsArray[allFlights].setColNumber(seatNo);

            cout << "Flight " << flightNo << " has been added" << endl;

            allFlights++;

            delete[] temp;
        }
    }
}

// This method gets an int input(Flight Number) and cancels the Selected Flight from the Reservation System.
void ReservationSystem::cancelFlight( const int flightNo)
{
    bool check = false;

    for(int i = 0 ; i < allFlights ; i++)
    {
        if(allFlightsArray[i].getFlightNumber() == flightNo)
        {
            Flight* temp = allFlightsArray;
            allFlightsArray = new Flight[allFlights - 1];

            for(int k = 0 ; k < i ; k++)
            {
                allFlightsArray[k] = temp[k];
            }
            for(int k = i + 1 ; k < allFlights ; k++)
            {
                allFlightsArray[(k - 1)] = temp[k];
            }

            reservation.deleteAllReservations(flightNo);
            cout << "Flight " << flightNo << " and all of its reservations are canceled." << endl;

            check = true;
            delete[] temp;
            allFlights--;
            break;
        }
    }

    if(!check)
    {
         cout << "Flight " << flightNo << " does not exist." << endl;
    }
}

// This method prints out all the flights with their available seats.
void ReservationSystem::showAllFlights()
{
    if(allFlights  == 0)
    {
            cout << "No flights exist." << endl;
    }
    else
    {
        cout <<  "Flights currently operated: " << endl;
        for(int i = 0 ; i < allFlights ; i++)
        {
                cout << "Flight " << allFlightsArray[i].getFlightNumber() << " ( " << allFlightsArray[i].allSeats() - totalReservations(allFlightsArray[i].getFlightNumber()) << " available seats.)" << endl;
        }
    }
}

// This method gets an int input(Reservation Code) and cancel the reservation from the Reservation System
// by using specific Reservation Code.
void ReservationSystem::cancelReservation(int resCode)
{
    reservation.cancelReservation(resCode);
}

// This method gets an int input (Flight Number) and print outs a detailed information about the Flight.
void ReservationSystem::showFlight( const int flightNo)
{
     if(allFlights  == 0)
    {
        cout << "No flight exists." << endl;
    }
    else
    {
        bool check = false;

        for(int i = 0 ; i < allFlights ; i++)
        {
            if(allFlightsArray[i].getFlightNumber() == flightNo)
            {
                cout << "Flight " << flightNo << " has " << allFlightsArray[i].allSeats() - totalReservations(flightNo) <<  " available seats" << endl;
                showDetailedInformation(flightNo);
                check = true;
                break;
            }
        }

        if(!check)
        {
            cout << "Flight " << flightNo << " does not exist." << endl;
        }
    }
}

// This method gets two int inputs(Flight Number/Number of Passengers ) and two integer arrays(seatRow/seatCol)
// and creates a reservation and a specific reservation code for that reservation.
int ReservationSystem::makeReservation (const int flightNo, const int numPassengers, const int* seatRow, const char* seatCol)
{
    return reservation.addReservation(flightNo, numPassengers, seatRow, seatCol);
}

// This method gets an int input(Reservation Code) and then shows the reservation by using specific reservation code.
void ReservationSystem::showReservation(const int resCode)
{
    reservation.showReservation(resCode);
}

// This method gets an int input(Flight Number) and shows a detailed information about Flight.
void ReservationSystem::showDetailedInformation(int flightNo)
{
    if(allFlights != 0)
    {
        for(int i = 0 ; i < allFlights ; i++)
        {
            if( allFlightsArray[i].getFlightNumber() == flightNo )
            {
                for(int j = 0 ; j < allFlightsArray[i].getColNumber() + 1 ; j++)
                {
                    if( j == 0 )
                    {
                            cout << "   ";
                    }
                    else
                    {
                        cout << intToLetter(j) << "  " ;
                    }
                }
                cout << endl;

                for(int k = 0 ; k < allFlightsArray[i].getRowNumber() ; k++)
                {
                   cout <<  k + 1 << "  " ;

                    if(!reservation.isFlightHasReservation(flightNo))
                    {
                        for(int z = 0 ; z < allFlightsArray[i].getColNumber() ; z++)
                        {
                            cout << "0  ";
                        }
                        cout << endl;
                    }
                    else
                    {
                        for(int z = 0 ; z < allFlightsArray[i].getColNumber() ; z++)
                        {
                            if(reservation.isReserved(flightNo, k + 1, z + 1))
                            {
                                cout << "X  ";
                            }
                            else
                            {
                                cout <<"0  ";
                            }
                        }
                        cout << endl;
                    }
                }

            }
        }
    }
}

// This method gets an int input (1 to 26) and coverts it to a char(A to Z).
char ReservationSystem::intToLetter( int n )
{
    if (n >= 1 && n <= 26 )
   {
           return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n-1];
   }
    return '-';
}

// This method gets an int input(Flight Number) and calculates the total reservations in specified Flight.
int ReservationSystem::totalReservations(int flightNo)
{
    int reservedSeats = 0;

    if(allFlights != 0)
    {
        for(int i = 0 ; i < allFlights ; i++)
        {
            if( allFlightsArray[i].getFlightNumber() == flightNo )
            {
                for(int k = 0 ; k < allFlightsArray[i].getRowNumber() ; k++)
                {
                    for(int z = 0 ; z < allFlightsArray[i].getColNumber() ; z++)
                    {
                        if(reservation.isReserved(flightNo, k + 1, z + 1))
                        {
                            reservedSeats++;
                        }
                    }
                }
            }
        }
    }
    return reservedSeats;
}

