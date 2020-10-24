// mergesort.cpp | yangjaq@oregonstate.edu
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
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

int main(){
	string num;

	ifstream myFile("data.txt");
	ofstream newFile("merge.out");

	while(getline(myFile, num)) {
		stringstream numbers(num);
		int value, firstNum;
		int i = 0; 
		numbers>>firstNum; //read in first number
		//create an array with size of firstNum
		int* arr = new int[firstNum];
		while(numbers>>value || numbers.peek() != EOF){
			arr[i] = value;
			i++;
		}
		i = 0; //using i to loop thru array
		//reset array for next line by setting to 0
		mergeSort(arr, 0, firstNum-1);
		for(int i = 0; i < firstNum; i++){
			newFile << arr[i] << " ";
		}
		newFile << '\n';
		delete[] arr;
	}

	myFile.close();
	newFile.close();
	return 0;
} 
