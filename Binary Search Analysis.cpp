#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

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
    const int N = 100;                                                      //Size of index                                

    vector<int> items;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);                                 //Creates a system for creating random numbers

    for (int i = 0; i < N; ++i) {                                           //For the size of N
        items.push_back(dis(gen));                                          //Fills the vector with random numbers
    }

    sort(items.begin(), items.end());                                       //Sorts the vector

    int target = dis(gen);                                                  //Creates random target

    //Recursive Binary Search
    int index = recursiveBinarySearch(items, target, 0, items.size() - 1);
    cout << "Recursive Binary Search:" << endl;
    if (index != -1) {
        cout << target << " found at location " << index << endl;
    }
    else {
        cout << target << " was not found." << endl;
    }

    //Iterative Binary Search
    index = iterativeBinarySearch(items, target);
    cout << "\nIterative Binary Search:" << endl;
    if (index != -1) {
        cout << target << " found at location " << index << endl;
    }
    else {
        cout << target << " was not found." << endl;
    }

    //Sequential Search
    index = sequentialSearch(items, target);
    cout << "\nSequential Search:" << endl;
    if (index != -1) {
        cout << target << " found at location " << index << endl;
    }
    else {
        cout << target << " was not found." << endl;
    }

    return 0;
}