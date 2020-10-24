// insertsort.cpp | yangjaq@oregonstate.edu
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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

int main(){
	string num;

	ifstream myFile("data.txt");
	ofstream newFile("insert.out");

	while(getline(myFile, num)) {
		stringstream numbers(num);
		int value, firstNum;
		int i = 0; 
		numbers>>firstNum; //read in first number
		//create array with size of firstNum
		int* arr = new int[firstNum];
		while(numbers>>value || numbers.peek() != EOF){
			arr[i] = value;
			i++;
		}
		i = 0; //using i to loop thru array
		//reset array for next line by setting to 0
		
		insert(firstNum, arr);
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
