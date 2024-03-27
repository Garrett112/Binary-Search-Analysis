#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Recursive Binary Search
int recursiveBinarySearch(const vector<int>& arr, int target, int low, int high) {
    if (low > high) {                                                       //Checks if search range is still valid
        cout << "Target Not Found" << endl;
        return -1;                                                          
    }

    int mid = low + (high - low) / 2;                                       //Finds the midpoint of the index
    if (arr[mid] == target) {                                               //Checks if the midpoint of the index is the target
        return mid;
    }
    else if (arr[mid] > target) {                                           //Checks if the midpoint is greater than the target
        return recursiveBinarySearch(arr, target, low, mid - 1);            //If the target is smaller, the function calls itself and replaces high with mid-1
    }
    else {
        return recursiveBinarySearch(arr, target, mid + 1, high);           //If the target is bigger, the function calls itself and replaces low with mid+1
    }
}

//Iterative Binary Search
int iterativeBinarySearch(const vector<int>& arr, int target) {
    int low = 0;                                                            //Sets the low to zero
    int high = arr.size() - 1;                                              //Sets the high to the size of the index

    while (low <= high) {                                                   //While the search range is valid
        int mid = low + (high - low) / 2;                                   //Finds the midpoint of the index

        if (arr[mid] == target) {                                           //Checks if the midpoint is the target
            return mid;                                                     
        }
        else if (arr[mid] > target) {                                       //Checks if the midpoint is greater than the target
            high = mid - 1;                                                 //If the midpoint is bigger, high is set equal to mid-1
        }
        else {                                                               
            low = mid + 1;                                                  //If the midpoint is smaller, low is set equal to mid+1
        }
    }
    cout << "Target Not Found" << endl;
    return -1;
}

//Sequential Search
int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {                                  //For every item in the index
        if (arr[i] == target) {                                             //If that item is equal to the target
            return i;                                                       //Return that item
        }
    }
    cout << "Target Not Found" << endl;
    return -1;
}

int main() {
    const int N = 1000000;                                                  //Size of index
    double SumRBS = 0.0;                                                    //Time (in ms) for Recursive Binary Search
    double SumIBS = 0.0;                                                    //Time (in ms) for Iterative Binary Search
    double SumSeqS = 0.0;                                                   //Time (in ms) for Sequential Search

    for (int loop = 0; loop < 10; ++loop) {                                 //Loop to run 10 times
        vector<int> items; 
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100);                             //Creates a system for creating random numbers

        for (int i = 0; i < N; ++i) {                                       //For the size of N
            items.push_back(dis(gen));                                      //Fills the vector with random numbers
        }

        sort(items.begin(), items.end());                                   //Sorts the vector

        int target = dis(gen);                                              //Generates a random target value

        //Recursive Binary Search
        auto start = high_resolution_clock::now();                          //Begins measuring time
        recursiveBinarySearch(items, target, 0, items.size() - 1);          //Searches for the target value using RBS
        auto stop = high_resolution_clock::now();                           //Stops measuring time
        auto duration = duration_cast<microseconds>(stop - start);          //Counts measured time
        SumRBS += static_cast<double>(duration.count());                    //Adds measured time to the RBS count

        //Iterative Binary Search
        start = high_resolution_clock::now();                               //Begins measuring time
        iterativeBinarySearch(items, target);                               //Searches for the target value using IBS
        stop = high_resolution_clock::now();                                //Stops measuring time
        duration = duration_cast<microseconds>(stop - start);               //Counts measured time
        SumIBS += static_cast<double>(duration.count());                    //Adds measured time to the IBS count

        //Sequential Search
        start = high_resolution_clock::now();                               //Begins measuring time
        sequentialSearch(items, target);                                    //Searches for the target value using SS
        stop = high_resolution_clock::now();                                //Stops measuring time
        duration = duration_cast<microseconds>(stop - start);               //Counts measured time
        SumSeqS += static_cast<double>(duration.count());                   //Adds measured time to the SS count
    }

    //Output average running times
    cout << "Average Running Time for Recursive Binary Search in microseconds is " << SumRBS / 10 << endl;
    cout << "Average Running Time for Iterative Binary Search in microseconds is " << SumIBS / 10 << endl;
    cout << "Average Running Time for Sequential Search in microseconds is " << SumSeqS / 10 << endl;

    return 0;
}