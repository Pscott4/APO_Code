#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
using namespace std;


deque<string> userFileDialogue();                                       
vector< vector<string> > linetovector(deque<string> linesInFile);  
string delSpaces(string &str);                                     
int keanu(vector<string> keywords);                          
void LexicalAnalysis(vector< vector<string> > masterVector);       
void printVector(vector<string> input);                       
bool is_number(const string& s);                                    
bool is_lowercase(string name);
vector<string> uniquevector(vector<string> davec);