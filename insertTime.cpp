// insertTime.cpp | yangjaq@oregonstate.edu
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void insert(int length, int array[]){
	int i, key, j; //i and j are counters; key is value being evaluated
	for(i=1; i < length; i++){
		key = array[i];
		j = i - 1;
		//compare every number before key with key
		//swap if num less than key	
		while (j >= 0 && array[j]<key){
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j+1] = key;
	}
};

//fill array with random numbers
void arrayFill(int n, int array[]){
	default_random_engine gen;
	uniform_int_distribution<int> dis(1, 10000);
	for(int i=0; i<n; i++){
		 array[i] = dis(gen);
	}
};

//calculate runtime for arrays
void insertTimer(int n, int array[]){
	auto start = high_resolution_clock::now();
	insert(n, array);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "For n = " << n << " Insertion Sort took: ";
	cout << duration.count() <<" microseconds."<<endl;
};	

//preset array sizes
int main(){
	int n[10] = {5000, 10000, 15000, 20000, 25000, 
				 30000, 35000, 40000, 45000, 50000};
	for(int i=0; i < 10; i++){
		int* array= new int[n[i]];
		arrayFill(n[i], array);	
		insertTimer(n[i], array);
		delete[] array;
	}

	return 0;
} 
