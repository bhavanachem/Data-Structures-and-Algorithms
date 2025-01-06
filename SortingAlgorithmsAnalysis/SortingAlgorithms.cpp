/*
Bhavana Chemuturi

        Program Description:
        --------------------
        //Project 1 - Sorting Algorithms
        This program performs an analysis of various sorting algorithms including
        Insertion Sort, Quicksort, Heapsort, and Merge Sort, applied to two different
        data types: Random order and Ascending order. The analysis focuses on the performance of
        each sorting algorithm in terms of number of comparisons and movements.
        ---------------------

        Changelog:
        ---------
        9/16/24: Program created, wrote program description, imported sorting functions
                 Approach for project:
                 - Create Random array and initialize counters and size of array
                 - Run each sort function, record comparisons and swaps and output results
                 - Reset counters, repeat process for ReverseOrder
        9/17/24: Finished Step 1: Test each implementation with a small list of numbers to verify
                that the sorting works correctly.
                 - There is a lot of repeating code, Come back to this
                 - Can I make testArray into randomArray, just utilizing first 10? (Completed 9/19)
                 - Make main method more readable (Completed 9/21)
                 - Finished Steps 1-5
                 - In Class Note: insertion sort: only swap is a movement
        9/18/24: Working on Step 6: Add probing code to count the number of comparisons and movements
                 - Decided to initialize comparisons and movements vars at beginning of certain functions
                 - Finished MergeSort
        9/19/24: Finished finding comparisons and movements for all functions. Need to repeat for InOrder Array
                 - Crashing for InOrder because of stack overflow
                 - Fixed by increasing the stack size for this program in Code Blocks
        9/20/24: Checking accuracy of each method
                 - InsertionSort: Correct O(N)
                 - QuickSort: Correct O(N^2)
                 - MergeSort: Not O(nlogn), currently showing 784,464 > 780,500
        9/21/24: Final changes to code, clean-up
                 - Make main method more readable (completed)
                 - Make output more readable
                 - Time each algorithm
        ----------
*/
#include <iostream> // cout and cin
#include <chrono> //for timing for algorithms
#include <algorithm> // for copying arrays

using namespace std;
using namespace std::chrono; //to use chrono class(timing)

//--------------------Program Starts------------------------//

//global variables
int comparisons=0;
int movements =0;
const int SIZE = 50000;
int sortArray [SIZE];
int copyRandomArray [SIZE];
const int randomArrayRange =1000;   //range for creating an array with random values
//end of global variables

void outputArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ",";
        }
    }
    cout << "]\n" << endl;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            movements++; //swap has occurred
            j = j - 1;
        }
        if(j>=0)
            comparisons++; //comparing arr[j] and key; one more when while terminates
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++; //comparing pivot and arr[j]
        if (arr[j] < pivot) {
            i++;
            movements++; //swapping
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    movements++; //swapping
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]){
        largest = left;
        comparisons++;
    }

    if (right < n && arr[right] > arr[largest]){
        largest = right;
        comparisons++;
    }

    if (largest != i) {
        movements++; //swapping
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        movements++; //swapping
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++; //comparing L[i] and R[j]
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            movements++; //movement in if or else
            i++;
        } else {
            arr[k] = R[j];
            movements++; //movement in if or else
            j++;
        }
        k++;
    }

    while (i < n1) {
        comparisons++;
        arr[k] = L[i];
        i++;
        k++;
        movements++;
    }

    while (j < n2) {
        comparisons++;
        arr[k] = R[j];
        j++;
        k++;
        movements++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void analysis(long long duration){
    cout <<"Comparisons:  " << comparisons << "\nMovements: " << movements <<endl;
    cout <<"Time taken: "<<duration<<" microseconds"<<endl;
}

void createRandomArray(int size){
    for(int i=0;i<size;i++)
    {
        sortArray [i] = (rand() % randomArrayRange); // Random integers between 0 and randomArrayRange-1
    }
}
void createReverseOrderArray(int size){
    for(int i=0;i<size;i++)
    {
        sortArray [i] = i;
    }
}
void sortInsertionHeap(void (*sortFunction)(int[], int), int arr[],int size, int showNums, const string& sortName){
    comparisons=0;
    movements =0;
    copy(sortArray , sortArray +SIZE, arr);
    auto startTime = high_resolution_clock::now();
    sortFunction(arr,size);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime-startTime).count();
    cout << "\nAfter " << sortName << ": " <<endl;
    outputArray(arr, showNums);
    analysis(duration);
}
void sortQuickMerge(void (*sortFunction)(int[], int, int), int arr[], int low, int high, int showNums, const string& sortName){
    comparisons=0;
    movements =0;
    copy(sortArray , sortArray +SIZE, arr);
    auto startTime = high_resolution_clock::now();
    sortFunction(arr,low, high);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime-startTime).count();
    cout << "\nAfter " << sortName << ": " <<endl;
    outputArray(arr, showNums);
    analysis(duration);
}
void ascendingInsertionHeap(void (*sortFunction)(int[], int),int size, int showNums, const string& sortName)
{
    movements =0;
    comparisons = 0;
    auto startTime = high_resolution_clock::now();
    sortFunction(sortArray, SIZE);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime-startTime).count();
    cout << "\nAfter "<< sortName << ": " <<endl;
    outputArray(sortArray,showNums);
    analysis(duration);
}
void ascendingQuickMerge(void (*sortFunction)(int[], int, int),int low, int high, int showNums, const string& sortName)
{
    movements =0;
    comparisons=0;
    auto startTime = high_resolution_clock::now();
    sortFunction(sortArray,low, high);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime-startTime).count();
    cout << "\nAfter "<< sortName << ": " <<endl;
    outputArray(sortArray,showNums);
    analysis(duration);
}
void outputSortingType(void (*createArrayFunction)(int), string sortType, int size, int showNums)
{
    cout << "\nCreating a " << sortType<<" array of size " << size <<endl;
    cout << "------------ " << endl;
    createArrayFunction(size);

    cout <<"\nArray before sorting: "<<endl;
    outputArray(sortArray,showNums);
    cout << "------------ " << endl;

}
int main(){
    //Step 2: Test each implementation with a small list of nums to verify sorting works correctly

    outputSortingType(createRandomArray, "Random", 10, 10);

    sortInsertionHeap(insertionSort, copyRandomArray, 10, 10, "Insertion Sort");
    sortQuickMerge(quicksort, copyRandomArray, 0, 9, 10,"Quick Sort");
    sortQuickMerge(mergeSort, copyRandomArray, 0, 9, 10,"Merge Sort");
    sortInsertionHeap(heapSort, copyRandomArray, 10, 10,"Heap Sort");


    //Step 3: Generate a list of 50,000 random numbers and store them in an array

    outputSortingType(createRandomArray,"Random", SIZE, 100);

    //Step 4: Test your implementations using this array to confirm sorting accurate
    sortInsertionHeap(insertionSort, copyRandomArray, SIZE, 100, "Insertion Sort");
    sortQuickMerge(quicksort, copyRandomArray, 0, SIZE-1, 100,"Quick Sort");
    sortQuickMerge(mergeSort, copyRandomArray, 0, SIZE-1, 100,"Merge Sort");
    sortInsertionHeap(heapSort, copyRandomArray, SIZE, 100,"Heap Sort");

    //Final Step: Repeat; This time use a pre-sorted (ReverseOrder) list in ascending order as the input.
    outputSortingType(createReverseOrderArray, "Reverse Order", SIZE, 100);

    ascendingInsertionHeap(insertionSort, SIZE, 100, "Insertion Sort");
    ascendingQuickMerge(quicksort, 0, SIZE-1, 100, "Quick Sort");
    ascendingInsertionHeap(heapSort, SIZE, 100, "Heap Sort");
    ascendingQuickMerge(mergeSort, 0, SIZE-1, 100, "Merge Sort");


    return 0;

}
