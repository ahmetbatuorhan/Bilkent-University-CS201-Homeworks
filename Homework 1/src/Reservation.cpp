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
Reservation::Reservation()
{
    totalReservations = 0;

    flightNoArr = NULL;
    passangerArr = NULL;
    rowArr = NULL;
    colArr = NULL;
}

// Destructor
Reservation::~Reservation()
{
        if(passangerArr != NULL)
        {
            delete[] passangerArr;
        }

        if(flightNoArr != NULL)
        {
            delete[] flightNoArr;
        }

        for(int i = 0 ; i < totalReservations ; i++)
        {
            if(rowArr[i] != NULL)
            {
                delete[] rowArr[i];
            }

            if(colArr[i] != NULL)
            {
                delete[] colArr[i];
            }
        }
        if(rowArr != NULL)
            {
                delete[] rowArr;
            }
        if(colArr != NULL)
            {
                delete[] colArr;
            }
}

// METHODS

// This method gets an int input(Flight Number) and then deletes all the reservations that related with this Flight Number.
void Reservation::deleteAllReservations(const int flightNo)
{
    if(totalReservations > 0)
    {
        for (int i  = 0 ; i < totalReservations ; i++)
        {
            if(flightNoArr[i] == flightNo)
            {
                cancelReservation2(i  + 1);
            }
        }
    }
    else
    {
        cout << "Please first add Flights" << endl;
    }
}

// This method gets an int input(Reservation Code) and then deletes the reservation by using specific reservation code.
void Reservation::cancelReservation(int resCode)
{
    resCode--;
    if(resCode >= 0 && resCode <= totalReservations)
    {
        cout << "Reservation for the seats ";

        for(int i = 0 ; i < passangerArr[resCode] ; i++)
        {
            cout  << rowArr[resCode][i] << intToLetter(colArr[resCode][i]) << " ";
        }

        cout << "is canceled in flight " << flightNoArr[resCode] << endl;

        flightNoArr[resCode] = 0;
        passangerArr[resCode] = 0;

        if(rowArr[resCode] != NULL )
        {
            delete[] rowArr[resCode];
        }
        if(colArr[resCode] != NULL)
        {
            delete[] colArr[resCode];
        }
            rowArr[resCode] = NULL;
            colArr[resCode]  = NULL;
    }
    else
    {
        cout << "Invalid reservation code: Reservation Code " << resCode + 1 << endl;
    }
}

// Same with the cancelReservation(int resCode) method but this
// method does not prints anything to console.
void Reservation::cancelReservation2(int resCode)
{
    if(resCode > 0 && resCode <= totalReservations)
    {
        flightNoArr[resCode - 1] = 0;
        passangerArr[resCode - 1] = 0;

        if(rowArr[resCode - 1] != NULL )
        {
            delete[] rowArr[resCode - 1];
        }
        if(colArr[resCode - 1] != NULL)
        {
            delete[] colArr[resCode - 1];
        }
            rowArr[resCode - 1] = NULL;
            colArr[resCode - 1]  = NULL;
    }
}

// This method gets an int input(Reservation Code) and then shows the reservation by using specific reservation code.
void Reservation::showReservation(const int resCode)
{
    if( passangerArr[resCode - 1] != 0)
    {
        if(resCode -  1 <= totalReservations )
        {
            cout << "Reservations under Code " <<  resCode << " in Flight " << flightNoArr[resCode - 1] << ": ";

            for(int i = 0 ; i < passangerArr[resCode - 1] ; i++)
            {
                cout << rowArr[resCode - 1][i] << intToLetter(colArr[resCode - 1][i]) ;
                if(i != passangerArr[resCode - 1] - 1)
                {
                    cout << "/";
                }
            }
            cout << endl;
        }
        else
        {
            cout << "No reservation under code " << resCode << endl;
        }
    }
    else
    {
         cout << "No reservation under code " << resCode << endl;
    }
}

// This method gets two int inputs(Flight Number/Number of Passengers ) and two integer arrays(seatRow/seatCol) and creates a reservation and a specific
// reservation code for that reservation.
int Reservation::addReservation(const int flightNo, const int numPassengers, const int* seatRow, const char* seatCol)
{
    if(totalReservations == 0)
    {

       flightNoArr = new int[1];
    passangerArr = new int[1];
    rowArr = new int*[1];
    colArr = new int*[1];

        flightNoArr[totalReservations] = flightNo;
        passangerArr[totalReservations] = numPassengers;

        rowArr[totalReservations] = new int[numPassengers];
        colArr[totalReservations] = new int[numPassengers];

        for(int i = 0 ; i < numPassengers ; i++)
        {
            rowArr[totalReservations][i] = seatRow[i];
            colArr[totalReservations][i] = letterToInt(seatCol[i]);
        }
        totalReservations++;
        return totalReservations;
    }
    else
    {
        int reservedCounter = 0;
        bool checkReserved = false;

        for(int i = 0 ; i < numPassengers ; i++)
        {
            if(isReserved(flightNo,seatRow[i] , letterToInt(seatCol[i])))
            {
                checkReserved = true;
                reservedCounter++;
                cout << seatRow[i] << (seatCol[i]) << " " ;
            }
        }
        if( !checkReserved)
        {
            int* TEMPflightNoArr = flightNoArr;
            int* TEMPpassangerArr = passangerArr;
            int** TEMProwArr = rowArr;
            int** TEMPcolArr = colArr;

            flightNoArr = new int[totalReservations + 1];
            passangerArr = new int[totalReservations + 1];
            rowArr = new int*[totalReservations + 1];
            colArr = new int*[totalReservations + 1];

            for(int i = 0 ; i < totalReservations ; i++)
            {
                flightNoArr[i] = TEMPflightNoArr[i];
                passangerArr[i] = TEMPpassangerArr[i];

                rowArr[i] = new int[passangerArr[i]];
                colArr[i] = new int[passangerArr[i]];

                for(int j = 0 ; j < passangerArr[i] ; j++)
                {
                    rowArr[i][j] = TEMProwArr[i][j];
                    colArr[i][j]  = TEMPcolArr[i][j];
                }
            }

            flightNoArr[totalReservations] = flightNo;
            passangerArr[totalReservations] = numPassengers;

            rowArr[totalReservations] = new int[numPassengers];
            colArr[totalReservations] = new int[numPassengers];

            for(int i = 0 ; i < numPassengers ; i++)
            {
                rowArr[totalReservations][i] = seatRow[i];
                colArr[totalReservations][i] = letterToInt(seatCol[i]);
            }

            delete[] TEMPpassangerArr;
            delete[] TEMPflightNoArr;

            for (int i = 0 ; i < totalReservations ; i++)
            {
                delete[] TEMProwArr[i];
                delete[] TEMPcolArr[i];
            }

            delete[] TEMProwArr;
            delete[] TEMPcolArr;

            totalReservations++;
            return totalReservations;
        }
        else
        {
            if(reservedCounter == 1)
            {
                cout << "is not available." << endl;
                return -1;
            }
            else
            {
                cout << "are not available." << endl;
                return -1;
            }

        }
    }
}

// This methods gets an int input(Flight Number) and checks whether is this Flight has any reservations or not.
bool Reservation::isFlightHasReservation(const int flightNo)
{
    if(totalReservations == 0) {return false;}

    for(int i = 0 ; i < totalReservations ; i++)
    {
        if(flightNoArr[i] == flightNo) {return true;}
    }

    return false;
}

// This method gets a char input (A to Z) and coverts it to an integer(1 to 26).
int Reservation::letterToInt(const char input)
{
    return (input - 'A') + 1;
}

bool Reservation::isReserved(const int flightNo, const int rowInput, const int colInput)
{
    if(totalReservations == 0)
    {
        return false;
    }
    else
    {
        for(int i = 0 ; i < totalReservations ; i++)
        {
            if(flightNoArr[i] == flightNo)
            {
                for(int k = 0 ; k < passangerArr[i] ; k++)
                {
                    if(rowArr[i][k] == rowInput && colArr[i][k] == colInput)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// This method gets an int input (1 to 26) and coverts it to a char(A to Z).
char Reservation::intToLetter(const int input)
{
    if (input >= 1 && input <= 26 )
   {
           return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[input - 1];
   }
    return '-';
}

