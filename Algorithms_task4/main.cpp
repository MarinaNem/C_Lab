#include <iostream>
#include <cstdlib>
#include <time.h>
#include "QuickSort.h"
#include "SearchMethods.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

constexpr int SmallSize = 100;
constexpr int BigSize = 10000;
#define duration(start, end) duration_cast<nanoseconds>(end - start).count()
#define сlockNow high_resolution_clock::now();

void PrintResult(string method, int index, int time)
{
    if (index == -1)
        cout << "Number not found \nAlgorithm execution time: " << time << endl;
    else
    {
        cout << "Index found by " << method << ": " << index << endl;
        cout << "Algorithm execution time : " << time << " nanoseconds" << endl << endl;
    }
}

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[BigSize];
    int sortArr[SmallSize];
    srand(time(0));
    int number;

    for (int i = 0; i < BigSize; i++)  // Array[10000] for Search()
        arr[i] = (rand() % 2001) - 1000;

    cout << endl << "Insert the number: in the range of -1000 to 1000: ";
    cin >> number;

    //Search in an unsorted array and measure runtime
    auto start1 = сlockNow;
    int index1 = Search(number, arr, BigSize);
    auto end1 = сlockNow;
    PrintResult("Search()", index1, duration(start1,end1));

    for (int i = 0; i < SmallSize; i++)  //Array[100] for QuickSort() and BSearch()
        sortArr[i] = (rand() % 21) - 10;

    cout << "Unsorted array :" << endl;
    PrintArray(sortArr, SmallSize/2 );
    int* sortArray = sortArr;
    QuickSortRecursive(sortArray, 0, SmallSize - 1); //Sort array recursive
    //QuickSortNotRecursive(sortArr, 0, SmallSize - 1);  //Sort array not recursive
    cout << "\nSorted array :" << endl;
    PrintArray(sortArr, SmallSize/2);

    cout << "\nInsert the number: in the range of -10 to 10: ";
    cin >> number;

    //Searching in a sorted array is not recursive and measuring runtime
    auto start2 = сlockNow;
    int index2 = BSearchNotRecursive(number, sortArr, 0, SmallSize - 1);
    auto end2 = сlockNow;
    PrintResult("BSearchNotRecursive()", index2, duration(start2, end2));

    //Searching in a sorted array is recursive and measuring runtime
    auto start3 = сlockNow;
    int index3 = BSearchRecursive(number, sortArr, 0, SmallSize - 1);
    auto end3 = сlockNow;
    PrintResult("BSearchRecursive()", index3, duration(start3, end3));
}
