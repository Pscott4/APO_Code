#include <iostream>
using namespace std;

class Iterate{
	
	public: int even(int,int);
	
};
int Iterate::even(int num,int count=1){
	while(num>1){
		count += 1;
		if(num%2 == 0){
			num = num/2;
		}
		else{ num = (num*3) + 1;}

	}
		return count;
	
}





int main(){
	int foo[2];
	Iterate pls;
	for(int i = 1; i<1000000; i++){
		int c = pls.even(i);
		if(c > foo[0]){
			foo[0] = c;
			foo[1] = i;
		}
	}
	cout << "at point " << foo[1] << " length of " << foo[0] << endl;
}






