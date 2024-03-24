#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive Binary Search
int recursiveBinarySearch(const vector<int>& arr, int target, int low, int high) {
    if (low > high) {
        return -1; // Not found
    }

    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid; // Found
    }
    else if (arr[mid] > target) {
        return recursiveBinarySearch(arr, target, low, mid - 1);
    }
    else {
        return recursiveBinarySearch(arr, target, mid + 1, high);
    }
}

// Iterative Binary Search
int iterativeBinarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Found
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1; // Not found
}

// Sequential Search
int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Found
        }
    }
    return -1; // Not found
}

int main() {
    // Test data
    vector<int> items = { 10, 20, 30, 40, 50, 60, 70 };
    int target1 = 30; // Item in the list
    int target2 = 35; // Item not in the list

    // Sort the vector
    sort(items.begin(), items.end());

    // Recursive Binary Search
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

    // Iterative Binary Search
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

    // Sequential Search
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