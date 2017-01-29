#include "pa3.h"
using namespace std;

                                    
int main(){
	deque<string> file_lines = userFileDialogue();

	vector< vector<string> > result = linetovector(file_lines);
	vector<string> tester = result[0];

    LexicalAnalysis(result);
	return 0;
}

deque<string> userFileDialogue(){
	cout << "Please enter the file path: " << endl;
	string line;
	string filelocation;
	deque<string> fileLines;
	cin >> filelocation;

	ifstream thefile(filelocation);
	if(thefile.is_open()){
		while(getline (thefile,line)){
			fileLines.push_back(line);
		}
		thefile.close();
	}
	else{
		cout << "The File didn't open \n ";
		exit(1);
	}
	return fileLines;



}

vector< vector<string> > linetovector(deque<string> linesInFile){

    // Token Lists
    // Keyword List
    string keywords[] = {"BEGIN","END","FOR"};
    // Delimiter List
    
    string delimiters[] = {"(",")", ";",","};
    // Operator List
   
    string operators[] = {"+","-","*","/","++","=","--","==","<",">","&&","||","!"};
    // Tokens Found Lists
    vector<string> keyword_list;
    vector<string> delimiter_list;
    vector<string> operator_list;
    vector<string> identifier_list;
    vector<string> found_constants;
    vector<string> found_errors;

    
   

    while(!linesInFile.empty()){

        string current_line = linesInFile.front();


        for(int i=0; i < (sizeof(keywords)/sizeof(*keywords)); i++){

            string token = keywords[i];

            
            while(current_line.find(token) != string::npos){

                
                keyword_list.push_back(token);
                current_line.replace(current_line.find(token),token.length(),"");

            }

        }

        for(int i=0; i < (sizeof(delimiters)/sizeof(*delimiters)); i++){

            string token = delimiters[i];


            while(current_line.find(token) != string::npos){

                delimiter_list.push_back(token);
                current_line.replace(current_line.find(token),token.length(),"");

            }

        }

        for(int i=0; i < (sizeof(operators)/sizeof(*operators)); i++){

            string token = operators[i];

            while(current_line.find(token) != string::npos){

                operator_list.push_back(token);
                current_line.replace(current_line.find(token),token.length()," ");

            }

        }

        
        istringstream ss(current_line);
        string token2;

        while(getline(ss, token2, ' ')) {

            string newString = delSpaces(token2);

            if(find(found_errors.begin(), found_errors.end(), newString) == found_errors.end()){

                found_errors.push_back(newString);

            }

        }

        
        linesInFile.pop_front();

    }

    
    found_errors.erase(std::remove(found_errors.begin(), found_errors.end(), ""), found_errors.end());

    
    for(int i=0; i < found_errors.size(); i++){

        string vector_element = found_errors.at(i);

        
        if(is_number(vector_element)){

            
            found_constants.push_back(vector_element);
            found_errors.at(i) = "DONE";

        }


        

        if(!is_number(vector_element) && is_lowercase(vector_element)){

            
            identifier_list.push_back(vector_element);
            found_errors.at(i) = "DONE";

        }

    }

    
    found_errors.erase(std::remove(found_errors.begin(), found_errors.end(), "DONE"), found_errors.end());

    
    vector< vector<string> > MasterVector;
    MasterVector.push_back(keyword_list);
    MasterVector.push_back(delimiter_list);
    MasterVector.push_back(operator_list);
    MasterVector.push_back(identifier_list);
    MasterVector.push_back(found_constants);
    MasterVector.push_back(found_errors);

    return MasterVector;

}

string delSpaces(string &str){

    // pass by reference so that it just edits the material
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    str.erase(remove(str.begin(), str.end(), '\t'), str.end());
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    
    str.erase(remove(str.begin(), str.end(), '\f'), str.end());
    str.erase(remove(str.begin(), str.end(), '\r'), str.end());
    return str;

}

bool is_number(const string& s){

    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();

}

bool is_lowercase(string name){

    int stringSize = name.length();
    bool isLowercase = true;

    // Traverse the String
    for(int i = 0; i < stringSize; i++){

        // If the Character is Lower-case, Return True
        if(islower(name[i])){
            isLowercase = true;
        }

        // If the Character is not Lower-case, Return False
        else{
            return false;
        }

    }

    // Return Whether the String is in All Lower-case
    return isLowercase;

}

//get it? how deep are you goin in the matrix?
int keanu(vector<string> key){
	int matrix = 0;
	int final_matrix = 0;

	for(int i =0; i < key.size(); i++){
		
        string current = key.at(i);
		if(current == "FOR"){
			matrix++;
		}
		if(current == "END"){


			if(matrix > final_matrix){
				final_matrix = matrix;
			}
			matrix--;
		}
	}

	if(final_matrix < matrix){
		final_matrix = matrix;
	}

	return final_matrix;
}

void LexicalAnalysis(vector<vector<string> > masterVector){
	
	vector<string> keywords = masterVector[0];
	vector<string> delimiters = masterVector[1];
	vector<string> operators = masterVector[2];
	vector<string> Identifier = masterVector[3];
	vector<string> constants = masterVector[4];
	vector<string> Errors = masterVector[5];

     vector<string> unique_keywords = uniquevector(keywords);

     vector<string> unique_delimiters = uniquevector(delimiters);

     vector<string> unique_identifier = uniquevector(Identifier);

     vector<string> unique_constants = uniquevector(constants);

     vector<string> unique_operators = uniquevector(operators);



    int depth = keanu(keywords);
    cout << "The Depth of the Nested Loops is:" << depth << endl;

	cout << "Keywords: ";
	printVector(unique_keywords);

	cout << "Delimiters: ";
	printVector(unique_delimiters);

	cout << "Operators: ";
	printVector(unique_operators);

	cout << "Constants: ";
	printVector(unique_constants);

	cout << "Identifiers: ";
	printVector(unique_identifier);

    int rightBrace = 0;
    int leftBrace = 0;
    int loops = 0;
    int begins = 0;
    int ends = 0;
    int equals = 0;
    int semicolons = 0;
    int fors = 0;
    int colons = 0;

    for(int counter = 0; counter < Errors.size(); counter++){

        string current_Error = Errors.at(counter);

        cout << "Syntax Error(s): " << current_Error << endl;

    }

    //getting all the info needed to make error statements

    for(int count = 0; count < delimiters.size(); count ++){
        string word = delimiters.at(count);

        if(word == "("){
            leftBrace++;
        }

        if(word == ")"){
            rightBrace++;
        }

        if(word == ";"){
            semicolons++;
        }

        if(word == ","){
            colons++;
        }
    }

    for(int count = 0; count < operators.size(); count++){
        string word = operators.at(count);
        
        if(word == "="){
            equals++;
        }
    }

    for(int count = 0; count < keywords.size(); count++){
        string word = keywords.at(count);
        
        if(word == "FOR"){
            loops++;
            fors++;
        }

        if(word == "BEGIN"){
            begins++;
        }

        if(word == "END"){
            ends++;
        }
    }

    //proceeding to check everything
    if(rightBrace != leftBrace){
        cout << "Error: Incorrect () Symmetry!" << endl;
    }

    if(begins != ends){
        if(loops != begins){
            if(loops > begins){
                int dif = loops - begins;

                cout << "Error: Missing " << dif << " BEGIN statments!" << endl;
            }

            if(loops < begins){
                int dif = begins - loops;

                cout << "Error: " << dif << " Too Many BEGIN Statements!";
            }
        }

        if(loops != ends){
            if(loops > ends){
                int dif = loops - ends;

                cout << "Error: Missing " << dif << " END statments!" << endl;

            }

            if(ends > loops){
                int dif = ends - loops;

                cout << "Error: " << dif << " Too Many END Statements!";

            }
        }
    }


    if(semicolons != equals){

        if(semicolons > equals){
            cout << "Error: Missing ';' " << endl;
        }

        if(semicolons < equals){
            cout << "Error: Incorrect ';' Usage" << endl;
        }
    }


    if(colons != (2*fors)){
        if(colons > (2*fors)){
            cout << "Error: " << colons - (2*fors) << " Too Many ',' " << endl;
        }

        if(colons < (2*fors)){
            cout << "Error: Missing " << (2*fors) - colons << " ',' " << endl;
        }
    }

    if(begins == ends && begins != loops){
        cout << "Error: END/BEGIN Statements Don't Match the Number of Loops!" << endl;
    }

   



}

vector<string> uniquevector(vector<string> davec){
    sort( davec.begin(), davec.end() );
    davec.erase( unique( davec.begin(), davec.end() ), davec.end() );

    return davec;

}

void printVector(vector<string> input){

	for(int i = 0; i < input.size(); i++){
        cout << input.at(i) << " ";
    }
    cout << endl;
}


