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
void displayArr(int [][4][2], string, int );
int avgTime(int [][4][2], int , int);


int main() {

    string raceNames[5] = {"Reading", "Sorting", "Inserting", "Deleting", "Averages"};
    int currentSim = 0;
    string tempCode;
    int vectId = 0;
    int listId = 1;
    int setId = 2;
    int readId = 0;
    int sortId = 1;
    int insertId = 2;
    int deleteId = 3;
    string fileArr[SZ_CODES];
    

    //Declaring a 3d array the first side hold the operations, the second side holds the type of race, and the third hold the total time (operation, race, total time):
    int raceTimes[3][4][2] = {0};
    



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
    raceTimes[0][0][0] = duration.count();
    raceTimes[0][0][1] += duration.count();


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
    raceTimes[1][0][0] = duration.count();
    raceTimes[1][0][1] += duration.count();
    



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
   raceTimes[2][0][0] = duration.count();
    raceTimes[2][0][1] += duration.count();
    
    //Displaying the times for reading:
    displayArr(raceTimes, raceNames[0], readId);

    currentSim++;
    }
    
    currentSim = 0; //Resetting currentSim for future use.
    
    

    //Sorting:
    while (currentSim < AMNT_SIM){
    auto start = high_resolution_clock::now();

    //Sorting the vector so that the Codes are sorted alphabetically
    sort(vectCode.begin(), vectCode.end());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    //adding the time to the raceTimes array:
    raceTimes[0][1][0] = duration.count();
    raceTimes[0][1][1] += duration.count();



    //Sorting the list:
    start = high_resolution_clock::now();

    listCode.sort();

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    //adding the time to the raceTimes array:
    raceTimes[1][1][0] = duration.count();
    raceTimes[1][1][1] += duration.count();
   



    //Sorting the set:

    //adding the time to the raceTimes array:
    raceTimes[2][1][0] = 0;
    raceTimes[2][1][1] += 0;
    

    //Displaying the times for sorting:

    displayArr(raceTimes, raceNames[1], sortId);
        currentSim++;
    }

    currentSim = 0; //Resetting currentSim for future use.

    //Inserting:

    while (currentSim < AMNT_SIM){
    string insert_str = "TESTCODE";

    //Timing and inserting a test string into the middle of the vector
    auto start = high_resolution_clock::now();

    vectCode.insert(vectCode.begin() + vectCode.size() / 2, insert_str);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    //adding the time to the raceTimes array:
    raceTimes[0][2][0] = duration.count();
    raceTimes[0][2][1] += duration.count();
    



    //Timing and inserting a test string into the middle of the list
    start = high_resolution_clock::now();

    auto itList = listCode.begin();
    advance(itList, SZ_CODES/2);

    listCode.insert(itList, insert_str);

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);


    //adding the time to the raceTimes array:
    raceTimes[1][2][0] = duration.count();
    raceTimes[1][2][1] += duration.count();
    



    //Timing and inserting a test string into the middle of the set

    start = high_resolution_clock::now();

    setCode.insert(insert_str);

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);


    //adding the time to the raceTimes array:
    raceTimes[2][2][0] = duration.count();
    raceTimes[2][2][1] += duration.count();
    


    //Displaying the values of the inserting:
    displayArr(raceTimes, raceNames[2], insertId);

    currentSim++;
    }


    currentSim = 0; //Resetting currentSim for future use.
    //Timing the deleting the middlish value:


    while(currentSim < AMNT_SIM){
    //vector:
    auto start = high_resolution_clock::now();

    vectCode.erase(vectCode.begin() + SZ_CODES/2);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    //adding the time to the raceTimes array:
    raceTimes[0][3][0] = duration.count();
    raceTimes[0][3][1] += duration.count();
    


    //List:
    auto itList = listCode.begin();
    advance(itList, SZ_CODES/2);
    start = high_resolution_clock::now();

    listCode.erase(itList);

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    //adding the time to the raceTimes array:
    raceTimes[1][3][0] = duration.count();
    raceTimes[1][3][1] += duration.count();

    //Set:
    
    start = high_resolution_clock::now();
    auto itSet = setCode.begin(); //using a iterator to find the right position.
    advance(itSet, SZ_CODES/2);

    setCode.erase(itSet);

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    //adding the time to the raceTimes array:
    raceTimes[2][3][0] = duration.count();
    raceTimes[2][3][1] += duration.count();


    //Displaying the times for the Deleting:
    displayArr(raceTimes, raceNames[3], deleteId);

    currentSim++;
    }

    //Getting the average times for each operation:
    //Reading Averages:
    raceTimes[0][0][0] = avgTime(raceTimes, readId, vectId);
    raceTimes[1][0][0] = avgTime(raceTimes, readId, listId);
    raceTimes[2][0][0] = avgTime(raceTimes, readId, sortId);

    //Sorting Averages:
    raceTimes[0][1][0] = avgTime(raceTimes, sortId, vectId);
    raceTimes[1][1][0] = avgTime(raceTimes, sortId, listId);
    raceTimes[2][1][0] = avgTime(raceTimes, sortId, setId);

    //Inserting Averages:
    raceTimes[0][2][0] = avgTime(raceTimes, insertId, vectId);
    raceTimes[1][2][0] = avgTime(raceTimes, insertId, listId);
    raceTimes[2][2][0] = avgTime(raceTimes, insertId, setId);

    //Deleting Averages:
    raceTimes[0][3][0] = avgTime(raceTimes, deleteId, vectId);
    raceTimes[1][3][0] = avgTime(raceTimes, deleteId, listId);
    raceTimes[2][3][0] = avgTime(raceTimes, deleteId, setId);


    //Displaying the average times:
    displayArr(raceTimes, raceNames[4], readId);
    displayArr(raceTimes, raceNames[4], sortId);
    displayArr(raceTimes, raceNames[4], insertId);
    displayArr(raceTimes, raceNames[4], deleteId);

    
    //Clearing all the operations:
    vectCode.clear();
    listCode.clear();
    setCode.clear();

    return 0;
}

void displayArr(int arr[][4][2], string race, int raceId){

        cout <<  right << setw(8) << race << ": " << setw(8) << 
        arr[0][raceId][0]<< setw(8) << arr[1][raceId][0]  << setw(8) << arr[2][raceId][0]  << endl;
    
}


int avgTime(int arr[][4][2], int raceId, int opId){

    return (arr[opId][raceId][1]/AMNT_SIM);
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/