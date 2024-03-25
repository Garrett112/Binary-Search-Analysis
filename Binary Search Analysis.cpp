#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    const int N = 50000;
    double SumRBS = 0.0;
    double SumIBS = 0.0;
    double SumSeqS = 0.0;

    // Loop to run 10 times
    for (int loop = 0; loop < 10; ++loop) {
        vector<int> items;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100);

        // Fill the vector with random numbers
        for (int i = 0; i < N; ++i) {
            items.push_back(dis(gen));
        }

        // Sort the vector
        sort(items.begin(), items.end());

        // Generate a random target value within the range of the generated numbers
        int target = dis(gen);

        // Recursive Binary Search
        auto start = high_resolution_clock::now();
        recursiveBinarySearch(items, target, 0, items.size() - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        SumRBS += static_cast<double>(duration.count());

        // Iterative Binary Search
        start = high_resolution_clock::now();
        iterativeBinarySearch(items, target);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        SumIBS += static_cast<double>(duration.count());

        // Sequential Search
        start = high_resolution_clock::now();
        sequentialSearch(items, target);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        SumSeqS += static_cast<double>(duration.count());
    }

    // Output average running times
    cout << "Average Running Time for Recursive Binary Search in microseconds is " << SumRBS / 10 << endl;
    cout << "Average Running Time for Iterative Binary Search in microseconds is " << SumIBS / 10 << endl;
    cout << "Average Running Time for Sequential Search in microseconds is " << SumSeqS / 10 << endl;

    return 0;
}