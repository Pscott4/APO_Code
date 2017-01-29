class Pal{
public: void Checksquare(int ,int**);
int** Square1(int**, int);
void printsquare(int**, int);
int** Square2(int**, int);
int** Square3(int**, int);
  
};

void Pal::Checksquare(int n,int** mag){
int horsum, colsum, diasum;
	
	//checks rows
    std::cout << "OUTPUT>> Checking the sums of every row: " ;
	for(int k = 0; k<n;k++ ){
		 horsum = 0;
		for(int j = 0;j<n; j++){
			horsum += mag[j][k];
		}
		std::cout << horsum << " ";
	}
	std::cout << std::endl;
    //checks columns
	std::cout << "OUTPUT>> Checking the sums of every column: ";
	for(int i = 0; i<n;i++ ){
		 colsum = 0;
		for(int j = 0;j<n; j++){
			colsum += mag[i][j];
		}
		std::cout << colsum << " ";
	}
	std::cout << std::endl;
	
	std::cout << "OUTPUT>> Checking the sums of every diagnol: ";
	diasum = 0;
    for(int i = 0; i<n;i++ ){
		 diasum += mag[i][i];
	//checked left to right	
		
	}
	std::cout << diasum << " ";
    //checked right to left
    int rev = 0;
    for(int j = n-1; j>=0;j--){
        rev += mag[j][(n-1)-j];
        }
    std::cout << rev << std::endl << std::endl;
}

int** Pal::Square1(int** mag,int n){
	int k = n/2;
    int j = n-1;
 
    // One by one put all values in magic square
    for (int num=1; num <= n*n; ){

        if (k==-1 && j==n){ 
            
            j = n-2;
            k = 0;
        }
        else
        {
            
            if (j == n)
                j = 0;
            
            if (k < 0)
                k=n-1;
        }
        if (mag[k][j]) 
        {
            j -= 2;
            k++;
            continue;
        }
        else
            mag[k][j] = num++; 
 
        j++;  k--; 
    }
    std::cout << "OUTPUT>> Magic Square #1 is:" << std::endl;
    return mag;
}

void Pal::printsquare(int** mag,int n){
	for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){

        	printf("%3d ", mag[i][j]);
        }
            
        std::cout << std::endl;
    }

}
int** Pal::Square2(int** mag,int n){
    int hold1;
    for(int i = 0;i<n;i++){
      hold1 = mag[0][i];
      mag[0][i] = mag[n-1][i];
      mag[n-1][i] = hold1;
    }



 std::cout << "OUTPUT>> Magic Square #2 is:" << std::endl;
 return mag;
}

int** Pal::Square3(int** mag,int n){
  int hold;
  for(int i = 0;i<n;i++){
      hold = mag[i][0];
      mag[i][0] = mag[i][n-1];
      mag[i][n-1] = hold;
    }

    std::cout << "OUTPUT>> Magic Square #3 is:" << std::endl;
  return mag;
}

