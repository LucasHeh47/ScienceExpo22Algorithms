#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <random>

using namespace std::chrono;
using namespace std;

// Function Prototypes
void UI();

void swapInts(int *, int *);
list<int> getListFromFile(string);
void heapify(int[], int, int);
void merge(int[], int, int, int);
void mergeSort(int[], int, int);

void createRandomList(int);
void createReversedList(int);
void createFewUnique(int);
void createNearlySortedList(int);

void bubbleSort(list<int>, string);
void selectionSort(list<int>, string);
void insertionSort(list<int>, string);
void shellSort(list<int>, string);
void mergeSort(list<int>, string);
void heapSort(list<int>, string);

void fewUniqueList();
void reversedList();
void randomList();
void nearlySortedList();

void massDataRetrieve();

bool isSorted(int[]);

//  --- Main Function ---
int main() {
  srand(time(NULL)); // This is important for random

  // createRandomList(100000);
  // createReversedList(100000);
  // createFewUnique(100000);
  // createNearlySortedList(100000);

  // fewUniqueList();
  // randomList();
  // nearlySortedList();
  // reversedList();
  UI();
}

// User Interface
void UI() {
  cout << "=============================\n";
  cout << "Sorting Algorithms Project\n";
  cout << "=============================\n";
  cout << "\nChose a few options to run 5 tests on\n\n";
  
  int algResponse;
  while(true) {
    cout << "What algorithm do you want to use [1-7]\n\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Shell Sort\n";
    cout << "5. Heap Sort\n";
    cout << "6. Merge Sort\n";
    cout << "7. All\n\n";
    cout << "> ";
    cin >> algResponse;
    if(algResponse < 1 || algResponse > 7) {
      continue;
    } else {
      break;
    }
  }

  int listResponse;
  while(true) {
    cout << "What type of list do you want to use [1-5]\n\n";
    cout << "1. Few Unique Items (Ex. 6, 13, 6, 3, 3, 13, 3, 13)\n";
    cout << "2. Random Items (Ex. 3, 5, 26, 14, 6, 18)\n";
    cout << "3. Nearly Sorted Items (Ex. 1, 2, 5, 3, 4, 6, 9, 7, 8, 10)\n";
    cout << "4. Reversed Items (Ex. 10, 9, 8, 7, 6...)\n";
    cout << "5. All\n\n";
    cout << "> ";
    cin >> listResponse;
    if(listResponse < 1 || listResponse > 5) {
      continue;
    } else {
      break;
    }
  }

  if(listResponse == 5 && algResponse == 7) {
    massDataRetrieve();
    return;
  }

  // Retrieve list based on which list
  list<int> list;
  string listType;
  switch(listResponse) {
    case 1:
      list = getListFromFile("few_unique_list");
      listType = "few_unique";
      break;
    case 2:
      list = getListFromFile("random_list");
      listType = "random";
      break;
    case 3:
      list = getListFromFile("nearly_sorted_list");
      listType = "nearly_sorted";
      break;
    case 4:
      list = getListFromFile("reversed_list");
      listType = "reversed";
      break;
    case 5: // Every List
      switch(algResponse) { // Check which sort to use and do every list with that sort
        case 1:
          cout << "\nFew Unique:\n";
          for(int i = 0; i < 5; i++) bubbleSort(getListFromFile("few_unique_list"), "few_unique");
          for(int i = 0; i < 5; i++) cout << "\nRandom:\n";
          for(int i = 0; i < 5; i++) bubbleSort(getListFromFile("random_list"), "random");
          cout << "\nNearly Sorted:\n";
          for(int i = 0; i < 5; i++) bubbleSort(getListFromFile("nearly_sorted_list"), "nearly_sorted");
          cout << "\nReversed:\n";
          for(int i = 0; i < 5; i++) bubbleSort(getListFromFile("reversed_list"), "reversed");
          break;
        case 2:
          cout << "\nNew Unique:\n";
          for(int i = 0; i < 5; i++) selectionSort(getListFromFile("few_unique_list"), "few_unique");
          cout << "\nRandom:\n";
          for(int i = 0; i < 5; i++) selectionSort(getListFromFile("random_list"), "random");
          cout << "\nNearly Sorted:\n";
          for(int i = 0; i < 5; i++) selectionSort(getListFromFile("nearly_sorted_list"), "nearly_sorted");
          cout << "\nReversed:\n";
          for(int i = 0; i < 5; i++) selectionSort(getListFromFile("reversed_list"), "reversed");
          break;
        case 3:
          cout << "\nFew Unique:\n";
          for(int i = 0; i < 5; i++) insertionSort(getListFromFile("few_unique_list"), "few_unique");
          cout << "\nRandom:\n";
          for(int i = 0; i < 5; i++) insertionSort(getListFromFile("random_list"), "random");
          cout << "\nNearly Sorted:\n";
          for(int i = 0; i < 5; i++) insertionSort(getListFromFile("nearly_sorted_list"), "nearly_sorted");
          cout << "\nReversed:\n";
          for(int i = 0; i < 5; i++) insertionSort(getListFromFile("reversed_list"), "reversed");
          break;
        case 4:
          cout << "\nFew Unique:\n";
          for(int i = 0; i < 5; i++) shellSort(getListFromFile("few_unique_list"), "few_unique");
          cout << "\nRandom:\n";
          for(int i = 0; i < 5; i++) shellSort(getListFromFile("random_list"), "random");
          cout << "\nNearly Sorted:\n";
          for(int i = 0; i < 5; i++) shellSort(getListFromFile("nearly_sorted_list"), "nearly_sorted");
          cout << "\nReversed:\n";
          for(int i = 0; i < 5; i++) shellSort(getListFromFile("reversed_list"), "reversed");
          break;
        case 5:
          cout << "\nFew Unique:\n";
          for(int i = 0; i < 5; i++) heapSort(getListFromFile("few_unique_list"), "few_unique");
          cout << "\nRandom:\n";
          for(int i = 0; i < 5; i++) heapSort(getListFromFile("random_list"), "random");
          cout << "\nNearly Sorted:\n";
          for(int i = 0; i < 5; i++) heapSort(getListFromFile("nearly_sorted_list"), "nearly_sorted");
          cout << "\nReversed:\n";
          for(int i = 0; i < 5; i++) heapSort(getListFromFile("reversed_list"), "reversed");
          return;
        case 6:
          cout << "\nFew Unique:\n";
          for(int i = 0; i < 5; i++) mergeSort(getListFromFile("few_unique_list"), "few_unique");
          cout << "\nRandom:\n";
          for(int i = 0; i < 5; i++) mergeSort(getListFromFile("random_list"), "random");
          cout << "\nNearly Sorted:\n";
          for(int i = 0; i < 5; i++) mergeSort(getListFromFile("nearly_sorted_list"), "nearly_sorted");
          cout << "\nReversed:\n";
          for(int i = 0; i < 5; i++) mergeSort(getListFromFile("reversed_list"), "reversed");
          return;
      }
      return;
  }
  
  switch(algResponse) {
    case 1:
      for(int i = 0; i < 5; i++) bubbleSort(list, listType);
      break;
    case 2:
      for(int i = 0; i < 5; i++) selectionSort(list, listType);
      break;
    case 3:
      for(int i = 0; i < 5; i++) insertionSort(list, listType);
      break;
    case 4:
      for(int i = 0; i < 5; i++) shellSort(list, listType);
      break;
    case 5:
      for(int i = 0; i < 5; i++) heapSort(list, listType);
      break;
    case 6:
      for(int i = 0; i < 5; i++) mergeSort(list, listType);
      break;
    case 7: // Every algorithm with chosen list
      cout << "\nBubble Sort:\n";
      for(int i = 0; i < 5; i++) bubbleSort(list, listType);
      cout << "\nSelection Sort:\n";
      for(int i = 0; i < 5; i++) selectionSort(list, listType);
      cout << "\nInsertion Sort:\n";
      for(int i = 0; i < 5; i++) insertionSort(list, listType);
      cout << "\nShell Sort:\n";
      for(int i = 0; i < 5; i++) shellSort(list, listType);
      cout << "\nHeap Sort:\n";
      for(int i = 0; i < 5; i++) heapSort(list, listType);
      cout << "\nMerge Sort:\n";
      for(int i = 0; i < 5; i++) mergeSort(list, listType);
      break;
  }
  
}

// Retrieve Data Trials --------------------------

void massDataRetrieve() {
  fewUniqueList();
  randomList();
  nearlySortedList();
  reversedList();
}

void fewUniqueList() {
  cout << "\n\nRetrieving Few Unique List Data Trials\n\n";
  list<int> list = getListFromFile("few_unique_list");
  cout << "\nBubble Sort:\n";
  for(int i = 0; i < 5; i++)
    bubbleSort(list, "few_unique");
  cout << "\nSelection Sort:\n";
  for(int i = 0; i < 5; i++)
    selectionSort(list, "few_unique");
  cout << "\nInsertion Sort:\n";
  for(int i = 0; i < 5; i++)
    insertionSort(list, "few_unique");
  cout << "\nShell Sort:\n";
  for(int i = 0; i < 5; i++)
    shellSort(list, "few_unique");
  cout << "\nHeap Sort:\n";
  for(int i = 0; i < 5; i++)
    heapSort(list, "few_unique");
  cout << "\nMerge Sort:\n";
  for(int i = 0; i < 5; i++)
    mergeSort(list, "few_unique");
}
void randomList() {
  cout << "\n\nRetrieving Random List Data Trials\n\n";
  list<int> list = getListFromFile("random_list");
  cout << "\nBubble Sort:\n";
  for(int i = 0; i < 5; i++)
    bubbleSort(list, "random");
  cout << "\nSelection Sort:\n";
  for(int i = 0; i < 5; i++)
    selectionSort(list, "random");
  cout << "\nInsertion Sort:\n";
  for(int i = 0; i < 5; i++)
    insertionSort(list, "random");
  cout << "\nShell Sort:\n";
  for(int i = 0; i < 5; i++)
    shellSort(list, "random");
  cout << "\nHeap Sort:\n";
  for(int i = 0; i < 5; i++)
    heapSort(list, "random");
  cout << "\nMerge Sort:\n";
  for(int i = 0; i < 5; i++)
    mergeSort(list, "random");
}
void nearlySortedList() {
  cout << "\n\nRetrieving Nearly Sorted List Data Trials\n\n";
  list<int> list = getListFromFile("nearly_sorted_list");
  cout << "\nBubble Sort:\n";
  for(int i = 0; i < 5; i++)
    bubbleSort(list, "nearly_sorted");
  cout << "\nSelection Sort:\n";
  for(int i = 0; i < 5; i++)
    selectionSort(list, "nearly_sorted");
  cout << "\nInsertion Sort:\n";
  for(int i = 0; i < 5; i++)
    insertionSort(list, "nearly_sorted");
  cout << "\nShell Sort:\n";
  for(int i = 0; i < 5; i++)
    shellSort(list, "nearly_sorted");
  cout << "\nHeap Sort:\n";
  for(int i = 0; i < 5; i++)
    heapSort(list, "nearly_sorted");
  cout << "\nMerge Sort:\n";
  for(int i = 0; i < 5; i++)
    mergeSort(list, "nearly_sorted");
}
void reversedList() {
  cout << "\n\nRetrieving Reversed List Data Trials\n\n";
  list<int> list = getListFromFile("reversed_list");
  cout << "\nBubble Sort:\n";
  for(int i = 0; i < 5; i++)
    bubbleSort(list, "reversed");
  cout << "\nSelection Sort:\n";
  for(int i = 0; i < 5; i++)
    selectionSort(list, "reversed");
  cout << "\nInsertion Sort:\n";
  for(int i = 0; i < 5; i++)
    insertionSort(list, "reversed");
  cout << "\nShell Sort:\n";
  for(int i = 0; i < 5; i++)
    shellSort(list, "reversed");
  cout << "\nHeap Sort:\n";
  for(int i = 0; i < 5; i++)
    heapSort(list, "reversed");
  cout << "\nMerge Sort:\n";
  for(int i = 0; i < 5; i++)
    mergeSort(list, "reversed");
}

// Utility Functions
list<int> getListFromFile(string fileName) {
  ifstream file;
  file.open("lists/" + fileName + ".txt");
  if (!file) {
    cout << "Error while opening file";
    list<int> failedList = {0};
    return failedList;
  }
  list<int> list;
  while (!file.eof()) {
    int num;
    file >> num;
    list.push_back(num);
  }
  return list;
}

void swapInts(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// --- Creating Lists -----------------------------

void createRandomList(int size) {
  ofstream file;
  file.open("lists/random_list.txt", ios::app);
  if (!file) {
    cout << "Error while creating random list";
    return;
  }
  for (int i = 0; i < size; i++) {
    int num = rand() % size;
    file << num << " ";
  }
  file.close();
  cout << "Successfully Created Random list";
}

void createReversedList(int size) {
  ofstream file;
  file.open("lists/reversed_list.txt", ios::app);
  if (!file) {
    cout << "Error while creating random list";
    return;
  }
  for (int i = size; i >= 0; i--) {
    file << i << " ";
  }
  file.close();
  cout << "Successfully Created Reversed List";
}

void createFewUnique(int size) {
  if (size < 1000) {
    cout << "Error > Few Unique list has to be > 1000 items";
    return;
  }
  ofstream file;
  file.open("lists/few_unique_list.txt", ios::app);
  if (!file) {
    cout << "Error while opening file.";
    return;
  }
  // size amt of items that can be from 0 - size/100
  for (int i = 0; i < size; i++) {
    file << rand() % (size / 100) << " ";
  }
  file.close();
  cout << "Successfully created a few unique list";
}

void createNearlySortedList(int size) {
  ofstream file;
  file.open("lists/nearly_sorted_list.txt", ios::app);
  if (!file) {
    cout << "Error while opening file.";
  }
  // create a normal sorted list but 1/5 chance if its greater than 100 sub/add
  // a random amount between 0 - 100
  for (int i = 0; i < size; i++) {
    int num = i;
    int chance = rand() % 5;
    if (num > size / 1000 && chance == 3) {
      int randNum =
          rand() % (((size / 1000) - (size / -1000)) + 1) + (size / -1000);
      num = num + randNum;
    }
    file << num << " ";
  }
  file.close();
  cout << "Successfully created a nearly sorted list";
}

// Different Sorting Algorithm Functions --------------------------

void bubbleSort(list<int> unsortedList, string listType) {
  // Convert list to array
  int arr[unsortedList.size()];
  int k = 0;
  for (int num : unsortedList) {
    arr[k] = num;
    k++;
  }
  // Start timer
  auto start = high_resolution_clock::now();
  int i, j;
  for (i = 0; i < unsortedList.size() - 1; i++)
    // Last i elements are already in place
    for (j = 0; j < unsortedList.size() - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swapInts(&arr[j], &arr[j + 1]);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Sorting finished in " << duration.count() / 1000
       << " milliseconds\n";

  // Saves sorted file for confirming it is sorted
  ofstream file;
  file.open("results/bubble_sort/" + listType);
  for (i = 0; i < unsortedList.size() - 1; i++) {
    file << arr[i] << " ";
  }
  file.close();
}



void selectionSort(list<int> unsortedList, string listType) {
  int i, j, min_idx;

  int n = unsortedList.size();

  // Convert list to array
  int arr[n];
  int k = 0;
  for (int num : unsortedList) {
    arr[k] = num;
    k++;
  }

  // Start timer
  auto start = high_resolution_clock::now();

  // One by one move boundary of
  // unsorted subarray
  for (i = 0; i < n - 1; i++) {

    // Find the minimum element in
    // unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    // Swap the found minimum element
    // with the first element
    if (min_idx != i)
      swapInts(&arr[min_idx], &arr[i]);
  }
  // Stop timer
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Sorting finished in " << duration.count() / 1000
       << " milliseconds\n";
  
  ofstream file;
  file.open("results/selection_sort/" + listType);
  for (i = 0; i < unsortedList.size() - 1; i++) {
    file << arr[i] << " ";
  }
  file.close();
}



void insertionSort(list<int> unsortedList, string listType)
{

  int n = unsortedList.size();

  // Convert list to array
  int arr[n];
  int k = 0;
  for (int num : unsortedList) {
    arr[k] = num;
    k++;
  }

  // Start timer
  auto start = high_resolution_clock::now();
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    // Move elements of arr[0..i-1], 
    // that are greater than key, to one
    // position ahead of their
    // current position
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
  }

  // Stop timer
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Sorting finished in " << duration.count() / 1000
       << " milliseconds\n";
  
  ofstream file;
  file.open("results/insertion_sort/" + listType);
  for (i = 0; i < unsortedList.size() - 1; i++) {
    file << arr[i] << " ";
  }
  file.close();
}



void shellSort(list<int> unsortedList, string listType) {
  int n = unsortedList.size();

  // Convert list to array
  int arr[n];
  int k = 0;
  for (int num : unsortedList) {
    arr[k] = num;
    k++;
  }
  
  // Start timer
  auto start = high_resolution_clock::now();
  // Start with a big gap, then reduce the gap
  for (int gap = n/2; gap > 0; gap /= 2)
  {
    // Do a gapped insertion sort for this gap size.
    // The first gap elements a[0..gap-1] are already in gapped order
    // keep adding one more element until the entire array is
    // gap sorted 
    for (int i = gap; i < n; i += 1)
    {
      // add a[i] to the elements that have been gap sorted
      // save a[i] in temp and make a hole at position i
      int temp = arr[i];

      // shift earlier gap-sorted elements up until the correct 
      // location for a[i] is found
      int j;            
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
          arr[j] = arr[j - gap];
        
      //  put temp (the original a[i]) in its correct location
      arr[j] = temp;
    }
  }

  // Stop timer
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Sorting finished in " << duration.count() / 1000
       << " milliseconds\n";
  
  ofstream file;
  file.open("results/shell_sort/" + listType);
  for (int i = 0; i < unsortedList.size() - 1; i++) {
    file << arr[i] << " ";
  }
  file.close();
}

// MERGE SORT UTILITY FUNCTIONS

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
  auto const subArrayOne = mid - left + 1;
  auto const subArrayTwo = right - mid;

  // Create temp arrays
  auto *leftArray = new int[subArrayOne],
       *rightArray = new int[subArrayTwo];

  // Copy data to temp arrays leftArray[] and rightArray[]
  for (auto i = 0; i < subArrayOne; i++)
      leftArray[i] = array[left + i];
  for (auto j = 0; j < subArrayTwo; j++)
      rightArray[j] = array[mid + 1 + j];

  auto indexOfSubArrayOne
      = 0, // Initial index of first sub-array
      indexOfSubArrayTwo
      = 0; // Initial index of second sub-array
  int indexOfMergedArray
      = left; // Initial index of merged array

  // Merge the temp arrays back into array[left..right]
  while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
      array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
    }
    else {
      array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
    }
    indexOfMergedArray++;
  }
  // Copy the remaining elements of
  // left[], if there are any
  while (indexOfSubArrayOne < subArrayOne) {
    array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    indexOfSubArrayOne++;
    indexOfMergedArray++;
  }
  // Copy the remaining elements of
  // right[], if there are any
  while (indexOfSubArrayTwo < subArrayTwo) {
    array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    indexOfSubArrayTwo++;
    indexOfMergedArray++;
  }
  delete[] leftArray;
  delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mSort(array, begin, mid);
    mSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void mergeSort(list<int> unsortedList, string listType) {
  int n = unsortedList.size();

  // Convert list to array
  int arr[n];
  int k = 0;
  for (int num : unsortedList) {
    arr[k] = num;
    k++;
  }
  
  // Start timer
  auto start = high_resolution_clock::now();


  // MERGE SORT arr
  mSort(arr, 0, n - 1);

  // Stop timer
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Sorting finished in " << duration.count() / 1000
       << " milliseconds\n";
  
  ofstream file;
  file.open("results/merge_sort/" + listType);
  for (int i = 0; i < unsortedList.size() - 1; i++) {
    file << arr[i] << " ";
  }
  file.close();
  
}

// UTILITY FUNCTION FOR HEAP SORT
void heapify(int arr[], int n, int i) {
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(list<int> unsortedList, string listType) {
  int n = unsortedList.size();

  // Convert list to array
  int arr[n];
  int k = 0;
  for (int num : unsortedList) {
    arr[k] = num;
    k++;
  }
  
  // Start timer
  auto start = high_resolution_clock::now();
  
  // HEAP SORT arr
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);

    // Heapify root element to get highest element at root again
    heapify(arr, i, 0);
  }
  

  // Stop timer
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Sorting finished in " << duration.count() / 1000
       << " milliseconds\n";
  
  ofstream file;
  file.open("results/heap_sort/" + listType);
  for (int i = 0; i < unsortedList.size() - 1; i++) {
    file << arr[i] << " ";
  }
  file.close();
}

bool isSorted(list<int> list) {
  int n = list.size();

  // Convert list to array
  int arr[n];
  int k = 0;
  for (int num : list) {
    arr[k] = num;
    k++;
  }

  for (int i = 0; i < list.size() - 1; i++)
    for (int j = 0; j < list.size() - i - 1; j++)
      if (arr[j] > arr[j + 1])
        return false;
  return true;
}
bool isSorted(int list[]) {
  int n = sizeof(list) / sizeof(list[0]);

  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (list[j] > list[j + 1])
        return false;
  return true;
}