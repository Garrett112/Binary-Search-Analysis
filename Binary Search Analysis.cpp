#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive Binary Search
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

// Iterative Binary Search
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

// Sequential Search
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
    vector<int> items = { 10, 20, 30, 40, 50, 60, 70 };                     //Creates list
    int target1 = 30;                                                       //Item in the list
    int target2 = 35;                                                       //Item not in the list

    sort(items.begin(), items.end());                                       //Sorts the vector

    //Recursive Binary Search
    int index = recursiveBinarySearch(items, target1, 0, items.size() - 1);
    cout << "Recursive Binary Search:" << endl;
    if (index != -1) {
        cout << target1 << " found at location " << index << endl;
    }
    else {
        cout << target1 << " was not found." << endl;
    }

    index = recursiveBinarySearch(items, target2, 0, items.size() - 1);
    if (index != -1) {
        cout << target2 << " found at location " << index << endl;
    }
    else {
        cout << target2 << " was not found." << endl;
    }

    //Iterative Binary Search
    index = iterativeBinarySearch(items, target1);
    cout << "\nIterative Binary Search:" << endl;
    if (index != -1) {
        cout << target1 << " found at location " << index << endl;
    }
    else {
        cout << target1 << " was not found." << endl;
    }

    index = iterativeBinarySearch(items, target2);
    if (index != -1) {
        cout << target2 << " found at location " << index << endl;
    }
    else {
        cout << target2 << " was not found." << endl;
    }

    //Sequential Search
    index = sequentialSearch(items, target1);
    cout << "\nSequential Search:" << endl;
    if (index != -1) {
        cout << target1 << " found at location " << index << endl;
    }
    else {
        cout << target1 << " was not found." << endl;
    }

    index = sequentialSearch(items, target2);
    if (index != -1) {
        cout << target2 << " found at location " << index << endl;
    }
    else {
        cout << target2 << " was not found." << endl;
    }

    return 0;
}