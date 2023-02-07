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

void swapInts(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

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
       << " milliseconds, Saving data now...\n";
  ofstream file;
  file.open("results/bubble_sort/" + listType);
  for (i = 0; i < unsortedList.size() - 1; i++) {
    file << arr[i] << " ";
  }
  file.close();
  cout << "Data saved in results/bubble_sort/" << listType << "\n";
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
       << " milliseconds, Saving data now...\n";
  
  ofstream file;
  file.open("results/selection_sort/" + listType);
  for (i = 0; i < unsortedList.size() - 1; i++) {
    file << arr[i] << " ";
  }
  file.close();
  cout << "Data saved in results/selection_sort/" << listType << "\n";
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
       << " milliseconds, Saving data now...\n";
  
  ofstream file;
  file.open("results/insertion_sort/" + listType);
  for (i = 0; i < unsortedList.size() - 1; i++) {
    file << arr[i] << " ";
  }
  file.close();
  cout << "Data saved in results/selection_sort/" << listType << "\n";
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
       << " milliseconds, Saving data now...\n";
  
  ofstream file;
  file.open("results/shell_sort/" + listType);
  for (int i = 0; i < unsortedList.size() - 1; i++) {
    file << arr[i] << " ";
  }
  file.close();
  cout << "Data saved in results/shell_sort/" << listType << "\n";
}