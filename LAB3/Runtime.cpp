#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sys/time.h>
#include "SortImpls.cpp" 
using namespace std;

void InitArray(vector<int>& array, int randMax, const string& condition);
void InitArrayMid(vector<int>& array, int randMax);
void PrintArrayDetails(const vector<int>& array, const string& name);
int elapsed(const timeval &startTime, const timeval &endTime);

void run_sorter(const string& sort_name, int size, const string& condition, bool printOut) {
    srand(1);
    vector<int> items(size);
    InitArray(items, size, condition);

    if (printOut) {
        cout << "Initial:" << endl;
        PrintArrayDetails(items, "items");
    }

    struct timeval startTime, endTime;
    gettimeofday(&startTime, 0); 

    if (sort_name == "BubbleSort") {
        BubbleSort(items, 0, size - 1);
    } else if (sort_name == "InsertionSort") {
        InsertionSort(items, 0, size - 1);
    } else if (sort_name == "MergeSort") {
        MergeSort(items, 0, size - 1);
    } else if (sort_name == "QuickSort") {
        QuickSort(items, 0, size - 1);
    } else if (sort_name == "ShellSort") {
        ShellSort(items, 0, size - 1);
    }

    gettimeofday(&endTime, 0);

    if (printOut) {
        cout << "Sorted:" << endl;
        PrintArrayDetails(items, "items"); 
    }

    int elapsed_secs = elapsed(startTime, endTime);
    cout << "Time (ms): " << elapsed_secs << endl;
}

int main(int argc, char *argv[]) {
    if ((argc != 2) && (argc != 3)) {
        cerr << "Usage: Sorter ARRAY_SIZE [YES|NO]" << endl;
        return -1;
    }

    int size = atoi(argv[1]);
    if (size <= 0) {
        cerr << "Array size must be positive" << endl;
        return -1;
    }

    bool printOut = true;
    if (argc == 3) {
        string printArr = string(argv[2]);
        if (printArr == "NO") {
            printOut = false;
        } else if (printArr != "YES") {
            cerr << "Usage: Sorter ARRAY_SIZE [YES|NO]" << endl;
            return -1;
        }
    }

    vector<string> sorting_algorithms = {"BubbleSort", "InsertionSort", "MergeSort", "QuickSort", "ShellSort"};
    vector<string> initial_conditions = {"Random", "Ordered", "Reversed", "PartiallyOrdered"};

    for (const auto& sort_name : sorting_algorithms) {
        for (const auto& condition : initial_conditions) {
            cout << "Running " << sort_name << " for size " << size << " with " << condition << " array" << endl;
            run_sorter(sort_name, size, condition, printOut);
        }
    }

    return 0;
}

void InitArray(vector<int>& array, int randMax, const string& condition) {
    if (condition == "Random") { //used GG (website) for the calculation logic 
        if (randMax < 0) {
            return;
        }

        vector<int> pool(randMax);
        for (int i = 0; i < randMax; i++) {
            pool[i] = i;
        }

        int spot;
        for (int i = 0; i < randMax; i++) {
            spot = rand() % (pool.size());
            array[i] = pool[spot];
            pool.erase(pool.begin() + spot);
        }
    } else if (condition == "Ordered") {
        for (int i = 0; i < randMax; ++i) {
            array[i] = i;
        }
    } else if (condition == "Reversed") {
        for (int i = randMax - 1, j = 0; i >= 0; --i, ++j) {
            array[j] = i;
        }
    } else if (condition == "PartiallyOrdered") { //used GG (website) for the calculation logic 
        InitArrayMid(array, randMax);
    }
}

void InitArrayMid(vector<int>& array, int randMax) {
    if (randMax < 0) {
        return;
    }

    vector<int> pool(randMax);
    for (int i = 0; i < randMax; i++) {
        pool[i] = i;
        array[i] = i;
    }

    int spot;
    int i1 = 0.01 * randMax;
    int i2 = 0.99 * randMax;

    for (int i = i1; i < i2; i++) {
        spot = rand() % (pool.size());
        array[i] = pool[spot];
        pool.erase(pool.begin() + spot);
    }
}

void PrintArrayDetails(const vector<int>& array, const string& name) {
    int size = array.size();
    for (int i = 0; i < size; i++)
        cout << name << "[" << i << "] = " << array[i] << endl;
}

int elapsed(const timeval &startTime, const timeval &endTime) {
    return (endTime.tv_sec - startTime.tv_sec) * 1000000 + (endTime.tv_usec - startTime.tv_usec);
}
