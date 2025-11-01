//COMSC-210|Ethan Aylard|Lab-26
//IDE Used: Visual Studio Code
//This Program is to time and an 3d array to measure multiple races of different methods of storing information.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int SZ_CODES = 20000; int AMNT_SIM = 15;

//Prototype functions:
void displayArr(int [][2], string );


int main() {

    int currentSim = 0;
    string tempCode;
    int durVect;
    int durList;
    int durSet;
    string fileArr[SZ_CODES];
    

    //Declaring a 3d array one side hold the times for each race, the second side holds the accumulator sums of each operation:
    int raceTimes[4][2] = {0};




    //Declaring the different competetors in the race:
    vector<string> vectCode;
    list<string> listCode;
    set<string> setCode;
    
    cout << right << setw(8) << "Operation" << setw(8) 
    << "Vector" << setw(8) << "List" << setw(8) << "Set" << endl;
    //Opening the codes for the race:
    ifstream iFile("codes.txt");

   

    //Using a for loop to read the file to the vector:
    for(int i = 0; i < SZ_CODES; i++){

    getline(iFile, tempCode);

    fileArr[i] = tempCode;
    }

    iFile.close();
    

    while(currentSim < AMNT_SIM){
    //Getting the time for the start of the timer:
    auto start = high_resolution_clock::now();

    //Using a for loop to read the file to the vector:
    for(int i = 0; i < SZ_CODES; i++){

    vectCode.push_back(fileArr[i]);

    
    }
    //Getting the time for the end of the timer and then getting the difference between the start and end:
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    //adding the time to the raceTimes array:
    raceTimes[0][0] = duration.count();
    raceTimes[0][1] += duration.count();


    //Reading to the list:
    //Getting the time for the start of the timer:
    start = high_resolution_clock::now();

    //Using a for loop to read the file to the list:
    for(int i = 0; i < SZ_CODES; i++){

    listCode.push_back(fileArr[i]);
    }
    //Getting the time for the end of the timer and then getting the difference between the start and end:
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    //adding the time to the raceTimes array:
    raceTimes[1][0] = duration.count();
    raceTimes[1][1] += duration.count();
    



    //Reading to the set:
    //Getting the time for the start of the timer:
    start = high_resolution_clock::now();

    //Using a for loop to read the file to the set:
    for(int i = 0; i < SZ_CODES; i++){

    setCode.insert(fileArr[i]);
    }
    //Getting the time for the end of the timer and then getting the difference between the start and end:
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    //adding the time to the raceTimes array:
    raceTimes[2][0] = duration.count();
    raceTimes[2][1] += duration.count();
    
    //Displaying the times for reading:
    cout <<  right << setw(8) << "Reading:" << setw(8) << 
    raceTimes[0][0] << setw(8) <<raceTimes[1][0]  << setw(8) << raceTimes[2][0]  << endl;

    currentSim++;
    }
    
    
    

    //Sorting:

    start = high_resolution_clock::now();

    //Sorting the vector so that the Codes are sorted alphabetically
    sort(vectCode.begin(), vectCode.end());
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    durVect = duration.count();



    //Sorting the list:
    start = high_resolution_clock::now();

    listCode.sort();

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    durList = duration.count();



    //Sorting the set:

    durSet = -1;

    //Displaying the times for sorting:

    cout << right << setw(8) << "Sorting:" << setw(8) <<
    durVect << setw(8) << durList << setw(8) << durSet << endl;




    //Inserting:
    string insert_str = "TESTCODE";

    //Timing and inserting a test string into the middle of the vector
    start = high_resolution_clock::now();

    vectCode.insert(vectCode.begin() + vectCode.size() / 2, insert_str);

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    durVect = duration.count();



    //Timing and inserting a test string into the middle of the list
    start = high_resolution_clock::now();

    auto itList = listCode.begin();
    advance(itList, SZ_CODES/2);

    listCode.insert(itList, insert_str);

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    durList = duration.count();



    //Timing and inserting a test string into the middle of the set

    start = high_resolution_clock::now();

    setCode.insert(insert_str);

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    durSet = duration.count();


    //Displaying the values of the inserting:
    cout << right << setw(8) << "Insert:" << setw(8) <<
    durVect << setw(8) << durList << setw(8) << durSet << endl;



    //Timing the deleting the middlish value:

    //vector:
    start = high_resolution_clock::now();

    vectCode.erase(vectCode.begin() + SZ_CODES/2);

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    durVect = duration.count();


    //List:
    start = high_resolution_clock::now();

    listCode.erase(itList);

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    durList = duration.count();



    //Set:
    
    start = high_resolution_clock::now();
    auto itSet = setCode.begin(); //using a iterator to find the right position.
    advance(itSet, SZ_CODES/2);

    setCode.erase(itSet);

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    durSet = duration.count();



    //Displaying the times for the Deleting:
    cout << right << setw(8) << "Delete:" << setw(8) << durVect 
    << setw(8) << durList << setw(8) << durSet << endl;


    //Clearing all the operations:
    vectCode.clear();
    listCode.clear();
    setCode.clear();

    return 0;
}

void displayArr(int arr[][2], string race){

        cout <<  right << setw(8) << race << ": " << setw(8) << 
        arr[0][0] << setw(8) <<arr[1][0]  << setw(8) << arr[2][0]  << endl;
    
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/