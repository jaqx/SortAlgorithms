//CS325 HW2 yangjaq@oregonstate.edu

#include <sstream>
#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>
#include <chrono>
#include <random>

using namespace std::chrono;
using namespace std;

void stoogeSort(int left, int right, int array[]){
	if(array[left] > array[right]){
		swap(array[left], array[right]);
	}
	if((right - left+1) > 2){
		int m = (right-left+1)/3;
		stoogeSort(left, right-m, array);
		stoogeSort(left+m, right, array);
		stoogeSort(left, right-m, array);
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
void timer(int n, int array[]){
	auto start = high_resolution_clock::now();
	stoogeSort(0, n-1, array);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "For n = " << n << " Stooge Sort took: ";
	cout << duration.count() <<" microseconds."<<endl;
};			

int main(){
	int n[7] = {5000, 6000, 7000, 8000, 9000, 
				 10000, 11000};
	for(int i=0; i < 7; i++){
		int* array= new int[n[i]];
		arrayFill(n[i], array);	
		timer(n[i], array);
		delete[] array;
	}
	/*string num;
	
	ifstream myFile("data.txt");
	ofstream newFile("stooge.out");

	while(getline(myFile, num)){
		stringstream numbers(num);
		int value, firstNum;
		int i = 0;
		numbers >> firstNum;

		int* arr = new int[firstNum];
		while(numbers >> value || numbers.peek() != EOF){
			arr[i]=value;
			i++;
		}
		i = 0;

		stoogeSort(0, firstNum-1, arr);
		for(int i=0; i<firstNum; i++){
			newFile <<arr[i] << " ";
		}
		newFile << '\n';
		delete[] arr;
	}
	myFile.close();
	newFile.close();*/

	return 0;
}

	
