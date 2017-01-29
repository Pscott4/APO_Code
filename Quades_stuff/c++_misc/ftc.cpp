#include <iostream>
using namespace std;

int main(){
	float holder, result;
	char temp;

	cout << "Enter the temperature type and it will convert" << endl;
	cout << "Ex: f24.57" << endl;
	cin >> temp >> holder;
	

	if(tolower(temp) == 'c'){
		holder = (holder * 1.8) + 32;
		cout << "Farhienhit Conversion: " << holder << endl;
		return 0;
	}
	if(tolower(temp) == 'f'){
		holder = double(holder - 32) * double(5/9);
		cout << "Celsius Conversion: " << holder << endl;
		return 0;
	}
	if(tolower(temp) != 'f' or 'c'){
		cout << "Error you didnt do it right" << endl;
	return -1;
}
}