#include <iostream>
#include "pa1.h"
using namespace std;


int main(){
	int z;
	cout << "Enter the size of a magic square: ";
	cin >> z;
	int **arr1;
	
	arr1 = new int*[z];
	//initializing the pointer array
	for (int w = 0; w < z; ++w) {
  		arr1[w] = new int[z];
  	
	
	}
	// giving each reference a value of 0
	for (int i = 0; i < z; ++i) {   
  		for (int j = 0; j < z; ++j) { 
    		arr1[i][j] = 0;
  		}
	}
	
	//creating the object
	Pal pls;
	pls.Square1(arr1, z);
	pls.printsquare(arr1,z);
	pls.Checksquare(z, arr1);
	//changing into the 2nd square
	
	pls.Square2(arr1,z);
	pls.printsquare(arr1,z);
	pls.Checksquare(z, arr1);
	//changing int the 3rd square
	
	pls.Square3(arr1, z);
	pls.printsquare(arr1,z);
	pls.Checksquare(z, arr1);
	
	return 0;
}