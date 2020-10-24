// mergesort.cpp | yangjaq@oregonstate.edu
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
using namespace std::chrono;
using namespace std;

void merge(int array[], int begin, int middle, int end){
	int i, j, k;
	//split array into 2 sets
	int set1 = middle - begin + 1;
	int set2 = end - middle;

	int array1[set1], array2[set2];

	//copy values from input array into sub-arrays
	for(i = 0; i < set1; i++){
		array1[i] = array[begin + i];
	}
	for(j = 0; j < set2; j++){
		array2[j] = array[middle + 1 + j];
	}

	//set counters back to 0 so we can go back to beginning of array
	i = 0;
	j = 0;
	k = begin;

	//sort in descending order
	while(i < set1 && j < set2){
		if(array1[i] >= array2[j]){
			array[k] = array1[i];
			i++;
		}
		else {
			array[k] = array2[j];
			j++;
		}
		k++;
	}
	while(i < set1){
		array[k] = array1[i];
		i++;
		k++;
	}
}

void mergeSort(int array[], int begin, int end){
	if(begin < end){
		int middle = (begin + end)/2;
	
		//recursively call to sort
		mergeSort(array, begin, middle);
		mergeSort(array, middle+1, end);

		merge(array, begin, middle, end);
	}
}

//fill array with random numbers
void arrayFill(int n, int array[]){
	default_random_engine gen;
	uniform_int_distribution<int> dis(1, 10000);
	for(int i=0; i<n; i++){
		 array[i] = dis(gen);
	}
};

//calculate runtime for arrays
void mergeTimer(int n, int array[]){
	auto start = high_resolution_clock::now();
	mergeSort(array,0,n-1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "For n = " << n << " Merge Sort took: ";
	cout << duration.count() <<" microseconds."<<endl;
};	

//preset array sizes
int main(){
	int n[10] = {5000, 10000, 15000, 20000, 25000, 
				 30000, 35000, 40000, 45000, 50000};
	for(int i=0; i < 10; i++){
		int* array= new int[n[i]];
		arrayFill(n[i], array);	
		mergeTimer(n[i], array);
		delete[] array;
	}

	return 0;
} 
