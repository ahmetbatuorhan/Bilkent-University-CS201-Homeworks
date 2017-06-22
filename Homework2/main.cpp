#include <iostream>
#include <vector>
#include "time.h"

/**
 * Ahmet Batu Orhan
 * 21402365
 * Sec-02
 */


using namespace std;


int main(int argc, const char * argv[])
{
      int timerArray[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 12500, 15000, 17500, 20000, 25000, 50000, 75000, 100000, 150000, 200000,
                              250000, 300000, 350000, 400000, 450000, 500000, 550000, 600000, 650000, 700000, 750000, 800000, 850000, 900000, 950000, 1000000,
                              1500000, 2000000, 2500000, 3000000, 3500000,4000000, 4500000, 5000000, 5500000, 6000000, 6500000, 7000000, 7500000, 8000000,
                              8500000, 9000000, 9500000, 10000000 };
      vector <int> vector1;
      vector <int> vector2;
      vector <int> vector3;
      vector <int> vector4;

      double duration1;
      double duration2;
      double duration3;
      double duration4;


      for(int j = 0 ; j < 13 ; j++)
      {
            for(int i = 0 ; i < timerArray[j] ; i++)
            {
                  vector1.push_back(i);
            }

      }
      clock_t startTime1 = clock();
      maxSubSum1(vector1);
      duration1 = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;
      cout << "Execution took " << duration1 << " milliseconds." << endl;
      vector1.clear();

     for(int j = 0 ; j < 25 ; j++)
      {
            for(int i = 0 ; i < timerArray[j] ; i++)
                  vector2.push_back(i);
      }

      clock_t startTime2 = clock();
      maxSubSum2(vector2);
      duration2 = 1000 * double( clock() - startTime2 ) / CLOCKS_PER_SEC;
      cout << "Execution took " << duration2 << " milliseconds." << endl;
      vector2.clear();


      for(int j = 0 ; j < 53 ; j++)
      {
            for(int i = 0 ; i < timerArray[j] ; i++)
                  vector3.push_back(i);
      }
      clock_t startTime3 = clock();
      maxSubSum3(vector3);
      duration3 = 1000 * double( clock() - startTime3 ) / CLOCKS_PER_SEC;
      cout << "Execution took " << duration3 << " milliseconds." << endl;
      vector3.clear();


      for(int j = 0 ; j < 53 ; j++)
      {
            for(int i = 0 ; i < timerArray[j] ; i++)
                  vector4.push_back(i);
      }
      clock_t startTime4 = clock();
      maxSubSum4(vector4);
      duration4 = 1000 * double( clock() - startTime4 ) / CLOCKS_PER_SEC;
      cout << "Execution took " << duration4 << " milliseconds." << endl;
      vector4.clear();


    return 0;
}



