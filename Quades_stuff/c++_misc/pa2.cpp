#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//what i would have put into the header file... if it had worked properly
void bestUse();                                                                
void worseUse();                                                               
void displayOption();                                                           
void initPg(struct pagenode *head, string programName);      
int kbtoPg(int kb);                                                         
int listLength(struct pagenode *head);                        
void addPg(struct pagenode *head, string programName);                         
bool deletePage(struct pagenode **head, pagenode *pageDelete);                         
void deleteEnd(struct pagenode *head);                                              
void outputMemory(struct pagenode *head, struct pagenode *head2);                      
void allocateFF(struct pagenode **head, pagenode *pagetoFree);                        
void countFragments(struct pagenode *head, struct pagenode *head2);                                                               
void writeToUsed(pagenode *startNode, int numPages, string pgrmName);               
struct pagenode *usedLargest(struct pagenode *head, int &lrgstFree);                    
struct pagenode *smallestUse(struct pagenode *head, int &smlstFree, int minimumSize);  
struct pagenode *searchPg(struct pagenode *head, string programName);                
bool inMemory(struct pagenode *head, string programName);                           

// the os memory, pages whichever you want to call it
struct pagenode{
    string programName;
    pagenode *nextPage;
};
// tried to implement reading command line it gave segmentation
//fault which didnt occur when used like this if you know why please let me know.
int main(int argc, char* argv[]){
    cout << "Please enter what kind of algorithm you want to use, Best or Worst" << endl;
    string n;
    cin >> n;
    //no longer case sensitive.
    for(int i = 0; n[i] != '\0'; i++){
        n[i] = tolower(n[i]);
    }

    if(n == "worst"){
        worseUse();
    }

    else if(n == "best"){
        bestUse();
    }

    else {
        cout << "Unrecognized Parameter!" << endl;
        return -1;
    }

    return 0;

}

void bestUse(){

    int prgmS;
    int pagesUsed = 0;
    struct pagenode *freeMemory = new pagenode;
    struct pagenode *usedMemory = new pagenode;
    int pageDeleteCounter = 0;
    int smallestFreePages = 0;
    string fileName;
    int userChoice = 0;

    // Initialize the pages
    for(int counter = 1; counter <= 32; counter++){
        addPg(freeMemory, "Free");
    }

    
    cout << "Using the Best Fit Algorithm" << endl;
    cout << endl;
    displayOption();
    cout << "Option: ";
    cin >> userChoice;

    while(true){

        switch (userChoice) {

            
            default: {
                cout << "Sorry, Unrecognized Input!" << endl;
                cout << endl;
                displayOption();
                cout << "Option: ";
                cin >> userChoice;
                break;
            }

            case 1:{

                // no memory been used
                if(listLength(usedMemory) == 0){

                    
                    cout << "Enter the Program Name: ";
                    cin >> fileName;
                    cout << "Program Size (KB): ";
                    cin >> prgmS;
                    prgmS = kbtoPg(prgmS);

                    
                    if (pagesUsed + prgmS <= 32 && !inMemory(usedMemory, fileName)) {

                        // checking for bad hombres
                        if (listLength(freeMemory) >= prgmS) {

                            // keeping pagenode use count
                            pagesUsed = pagesUsed + prgmS;
                            //replace open memory for the file
                            for (int counter = 1; counter <= prgmS; counter++) {
                                addPg(usedMemory, fileName);
                                deleteEnd(freeMemory);
                            }

                            // no bad hombres here
                            cout << "Program " << fileName << " Successfully Added! ("
                                    << prgmS << " Page(s) Used)" << endl;
                            displayOption();
                            cout << "Option: ";
                            cin >> userChoice;

                        }
   
                        else{

                            cout << "Error, Not Enough Memory to Add " << fileName << "!" << endl;
                            displayOption();
                            cout << "Option: ";
                            cin >> userChoice;

                        }
                    }

                    
                    else if(pagesUsed + prgmS > 32){
                        cout << "Error, Not Enough Memory to Add " << fileName << "!" << endl;
                        displayOption();
                        cout << "Option: ";
                        cin >> userChoice;
                    }
   
                    else if(inMemory(usedMemory, fileName)){
                        cout << "Error, Program " << fileName << " is Already in Memory!" << endl;
                        displayOption();
                        cout << "Option: ";
                        cin >> userChoice;
                    }

                        // catch all error
                    else{
                        cout << "Unknown Error!" << endl;
                        displayOption();
                        cout << "Option: ";
                        cin >> userChoice;
                    }

                }
                //end of the first scenario

                // okay its not empty
                else if(listLength(usedMemory) != 0){

                    cout << "Enter the Program Name: ";
                    cin >> fileName;
                    cout << "Program Size (KB): ";
                    cin >> prgmS;
                    prgmS = kbtoPg(prgmS);

                    pagenode *startingBlock = smallestUse(usedMemory, smallestFreePages, prgmS);

                    if(startingBlock != NULL && smallestFreePages != 0) {

                        if (smallestFreePages >= prgmS) {

                            pagesUsed = pagesUsed + prgmS;
                            writeToUsed(startingBlock, prgmS, fileName);

                            
                            cout << "Program " << fileName << " Successfully Added! ("
                                    << prgmS << " Page(s) Used)" << endl;
                            displayOption();
                            cout << "Option: ";
                            cin >> userChoice;

                        }

                        else if(smallestFreePages < prgmS){
                            cout << "Error, Not Enough Memory to Add " << fileName << "!" << endl;
                            displayOption();
                            cout << "Option: ";
                            cin >> userChoice;
                        }

                        smallestFreePages = 0;

                    }

                    else if(startingBlock == NULL || smallestFreePages == 0){

                        if (pagesUsed + prgmS <= 32 && !inMemory(usedMemory, fileName)) {

                           
                            if (listLength(freeMemory) >= prgmS) {

                                //update pages
                                pagesUsed = pagesUsed + prgmS;

                                for (int counter = 1; counter <= prgmS; counter++) {
                                    addPg(usedMemory, fileName);
                                    deleteEnd(freeMemory);
                                }

                                
                                cout << "Program " << fileName << " Successfully Added! ("
                                        << prgmS << " Page(s) Used)" << endl;
                                displayOption();
                                cout << "Option: ";
                                cin >> userChoice;

                            }

                            else{

                                cout << "Error, Not Enough Memory to Add " << fileName << "!" << endl;
                                displayOption();
                                cout << "Option: ";
                                cin >> userChoice;

                            }

                        }

                            
                        else if(pagesUsed + prgmS > 32){
                            cout << "Error, Not Enough Memory to Add " << fileName << "!" << endl;
                            displayOption();
                            cout << "Option: ";
                            cin >> userChoice;
                        }

                            //to many hombres in the pages with the same name
                        else if(inMemory(usedMemory, fileName)){
                            cout << "Error, Program " << fileName << " is Already in Memory!" << endl;
                            displayOption();
                            cout << "Option: ";
                            cin >> userChoice;
                        }

                           
                        else{
                            cout << "Unknown Error!" << endl;
                            displayOption();
                            cout << "Option: ";
                            cin >> userChoice;
                        }

                    }

                }

                break;
            }

                
            case 2: {

                cout << "Enter the Program Name: ";
                cin >> fileName;

                if (!inMemory(usedMemory, fileName)) {
                    cout << "Program " << fileName << " is not in Memory!" << endl;
                    displayOption();
                    cout << "Option: ";
                    cin >> userChoice;
                }
                    //it is in
                else if (inMemory(usedMemory, fileName)) {

                    
                    while (inMemory(usedMemory, fileName)) {
                        pagenode *pageInMemory = searchPg(usedMemory, fileName);
                        allocateFF(&usedMemory, pageInMemory);
                        pagesUsed--;
                        pageDeleteCounter++;
                    }

                    cout << "Program " << fileName << " Killed Successfully! (" << pageDeleteCounter << " pagenode(s) freed)" << endl;
                    pageDeleteCounter = 0;
                    displayOption();
                    cout << "Option: ";
                    cin >> userChoice;

                }

                    
                else {
                    cout << "Unknown Error!" << endl;
                    displayOption();
                    cout << "Option: ";
                    cin >> userChoice;
                }

                break;
            }

            case 3:{

                if(listLength(freeMemory) == 32){
                    cout << "There is No Fragmentation" << endl;
                    displayOption();
                    cout << "Option: ";
                    cin >> userChoice;
                    break;
                }

                else {
                    countFragments(usedMemory, freeMemory);
                    cout << endl;
                    displayOption();
                    cout << "Option: ";
                    cin >> userChoice;
                    break;
                }

            }

                
            case 4: {
                outputMemory(usedMemory, freeMemory);
                cout << endl;
                displayOption();
                cout << "Option: ";
                cin >> userChoice;
                break;
            }

                
            case 5: {
                exit(0);
                break;
            }

        }

    }

}

void worseUse(){

    // essentially copy pasted from the previous bestUse function with slight differences
    int userChoice = 0;
    int prgmS;
    int pagesUsed = 0;
    int pageDeleteCounter = 0;
    int largestFreePages = 0;
    string fileName;
    struct pagenode *freeMemory = new pagenode;
    struct pagenode *usedMemory = new pagenode;

    for(int counter = 1; counter <= 32; counter++){
        addPg(freeMemory, "Free");
    }

    cout << "Using the Worst Fit Algorithm" << endl;
    cout << endl;
    displayOption();
    cout << "Option: ";
    cin >> userChoice;

    while(true) {

        
        switch (userChoice) {

            default: {
                cout << "Sorry, Unrecognized Input!" << endl;
                cout << endl;
                displayOption();
                cout << "Option: ";
                cin >> userChoice;
                break;
            }

            case 1: {

                if (pagesUsed < 32) {

                    cout << "Enter the Program Name: ";
                    cin >> fileName;
                    cout << "Program Size (KB): ";
                    cin >> prgmS;
                    prgmS = kbtoPg(prgmS);

                    if (pagesUsed + prgmS <= 32 && !inMemory(usedMemory, fileName)) {

                        if (listLength(freeMemory) >= prgmS) {

                            pagesUsed = pagesUsed + prgmS;

                            for (int counter = 1; counter <= prgmS; counter++) {
                                addPg(usedMemory, fileName);
                                deleteEnd(freeMemory);
                            }

                            cout << "Program " << fileName << " Successfully Added! ("
                                    << prgmS << " Page(s) Used)" << endl;
                            displayOption();
                            cout << "Option: ";
                            cin >> userChoice;

                        }
                        else{

                            pagenode *startingBlock = usedLargest(usedMemory, largestFreePages);

                            if(largestFreePages >= prgmS){

                                pagesUsed = pagesUsed + prgmS;
                                writeToUsed(startingBlock, prgmS, fileName);

                                cout << "Program " << fileName << " Successfully Added! ("
                                        << prgmS << " Page(s) Used)" << endl;
                                displayOption();
                                cout << "Option: ";
                                cin >> userChoice;

                            }

                            else if(largestFreePages < prgmS){
                                cout << "Error, Not Enough Memory to Add " << fileName << "!" << endl;
                                displayOption();
                                cout << "Option: ";
                                cin >> userChoice;
                            }

                            largestFreePages = 0;

                        }

                    }
                    else if(pagesUsed + prgmS > 32){
                        cout << "Error, Not Enough Memory to Add " << fileName << "!" << endl;
                        displayOption();
                        cout << "Option: ";
                        cin >> userChoice;
                    }

                    else if(inMemory(usedMemory, fileName)){
                        cout << "Error, Program " << fileName << " is Already in Memory!" << endl;
                        displayOption();
                        cout << "Option: ";
                        cin >> userChoice;
                    }

                    else{
                        cout << "Unknown Error!" << endl;
                        displayOption();
                        cout << "Option: ";
                        cin >> userChoice;
                    }

                }

                else {
                    cout << "Not Enough Memory to Add More Programs!" << endl;
                    displayOption();
                    cout << "Option: ";
                    cin >> userChoice;
                }

                break;

            }

            case 2: {

                cout << "Enter the Program Name: ";
                cin >> fileName;

                if (!inMemory(usedMemory, fileName)) {
                    cout << "Program " << fileName << " is not in Memory!" << endl;
                    displayOption();
                    cout << "Option: ";
                    cin >> userChoice;
                }

                else if (inMemory(usedMemory, fileName)) {

                    while (inMemory(usedMemory, fileName)) {
                        pagenode *pageInMemory = searchPg(usedMemory, fileName);
                        allocateFF(&usedMemory, pageInMemory);
                        pagesUsed--;
                        pageDeleteCounter++;
                    }

                    cout << "Program " << fileName << " Killed Successfully! (" << pageDeleteCounter << " pagenode(s) freed)" << endl;
                    pageDeleteCounter = 0;
                    displayOption();
                    cout << "Option: ";
                    cin >> userChoice;

                }

                else {
                    cout << "Unknown Error!" << endl;
                    displayOption();
                    cout << "Option: ";
                    cin >> userChoice;
                }

                break;
            }
            case 3:{

                if(listLength(freeMemory) == 32){
                    cout << "There is No Fragmentation" << endl;
                    displayOption();
                    cout << "Option: ";
                    cin >> userChoice;
                    break;
                }

                else {
                    countFragments(usedMemory, freeMemory);
                    cout << endl;
                    displayOption();
                    cout << "Option: ";
                    cin >> userChoice;
                    break;
                }

            }

            case 4: {
                outputMemory(usedMemory, freeMemory);
                cout << endl;
                displayOption();
                cout << "Option: ";
                cin >> userChoice;
                break;
            }

            case 5: {
                exit(0);
                break;
            }

        }
    }

}
//all the other functions used in the main two
int kbtoPg(int kb){
    int pat;
    pat = kb / 4;
    if(kb % 4 > 0){
        pat++;
    }
    return pat;
}
//starting with the easiest one

void displayOption(){

    cout << endl;
    cout << "1. Add program" << endl;
    cout << "2. Kill program" << endl;
    cout << "3. Fragmentation" << endl;
    cout << "4. Print memory" << endl;
    cout << "5. Exit" << endl;
    cout << endl;

}
//okay maybe the second easiest one

void initPg(struct pagenode *head, string programName){

    // starts the first nod of the linkedlist
    head -> programName = programName;
    head -> nextPage = NULL;

}

void addPg(struct pagenode *head, string programName){

    
    if(head == NULL){
        initPg(head, programName);
        return;
    }

    pagenode *newPage = new pagenode;
    newPage -> programName = programName;
    newPage -> nextPage = NULL;
    pagenode *current = head;

    while(current){

        if(current -> nextPage == NULL){
            current -> nextPage = newPage;
            return;
        }

        current = current -> nextPage;
    }

}

bool deletePage(struct pagenode **head, pagenode *pageDelete){

    pagenode *current = *head;

    if(pageDelete == *head){
        *head = current -> nextPage;
        delete(pageDelete);
        return true;
    }

    while(current){

        if(current -> nextPage == pageDelete){
            current -> nextPage = pageDelete -> nextPage;
            delete(pageDelete);
            return true;
        }

        current = current -> nextPage;

    }

    return false;

}
//i dont like linkedlists
void deleteEnd(struct pagenode *head){

    if (head -> nextPage == NULL) {
        delete head;
        head = NULL;
    }

    else {
        pagenode *nextToEnd = head;
        pagenode *end = head -> nextPage;

        while (end->nextPage != NULL) {
            nextToEnd = end;
            end = end->nextPage;
        }

        delete end;
        nextToEnd->nextPage = NULL;
    }

}

void outputMemory(struct pagenode *head, struct pagenode *head2){

    int counter = 0;

    pagenode *usedMemory = head;
    pagenode *freeMemory = head2;

    usedMemory = usedMemory->nextPage;
    freeMemory = freeMemory->nextPage;

    while(usedMemory){

        if(counter % 9 == 0){
            cout << endl;
            counter++;
        }

        else {
            cout << setw(10) << usedMemory->programName;
            usedMemory = usedMemory->nextPage;
            counter++;
        }

    }
    while(freeMemory){

        if(counter % 9 == 0){
            cout << endl;
            counter++;
        }

        else {
            cout << setw(10) << freeMemory->programName;
            freeMemory = freeMemory->nextPage;
            counter++;
        }

    }

}


void countFragments(struct pagenode *head, struct pagenode *head2){

    int numberFrags = 0;      
    string placeHolder;            
    pagenode *mergedPage = new pagenode;    
    bool startingFragment = false;  

    pagenode *current = head;
    current = current->nextPage;

    //goes through the list
    while (current) {
        addPg(mergedPage, current -> programName);
        current = current->nextPage;
    }
    current = head2;
    current = current->nextPage;

    while (current) {
        addPg(mergedPage, current -> programName);
        current = current->nextPage;
    }

    current = mergedPage;
    current = current -> nextPage;
    placeHolder = current->programName;

    if (placeHolder == "Free") {
        startingFragment = true;
    }

    while(current){

        if (current->programName == placeHolder && current->nextPage != NULL) {}

        else if (current->programName != placeHolder && current->nextPage != NULL) {

            if (current->programName != "Free" && placeHolder == "Free") {
                numberFrags++;
                placeHolder = current->programName;
            }

            else if (current->programName != "Free" && placeHolder != "Free") {
                placeHolder = current->programName;
            }

            else if (current->programName == "Free" && placeHolder != "Free") {
                placeHolder = current->programName;
            }

        }

        current = current->nextPage;

    }

    if(!startingFragment){
        numberFrags++;
    }

    cout << "There are " << numberFrags << " fragment(s)" << endl;

}


int listLength(struct pagenode *head){
    int count = 0;

    // goes along the nodes till it hits the end
    while (head != NULL) {
        count++;
        head = head -> nextPage;
    }
    count = count - 1;
    return count;
}

bool inMemory(struct pagenode *head, string programName){
    pagenode *current = head;

    while(current){
        if(current -> programName == programName) return true;
        current = current -> nextPage;
    }

    return false;

}

struct pagenode *smallestUse(struct pagenode *head, int &smlstFree, int minimumSize){
    int smallestNumberFreePages = 32;
    int freePageCounter = 0;
    struct pagenode *theSmallestBlock = NULL;
    struct pagenode *smallestBlockStart = NULL;

    pagenode *current = head;
    current = current -> nextPage;

    while(current){

        if(current -> programName == "Free" && current -> nextPage != NULL){
            if(smallestBlockStart == NULL){
                smallestBlockStart = current;
            }

            freePageCounter++;
        }

        else if(current -> programName == "Free" && current -> nextPage == NULL){
            if(smallestBlockStart == NULL){
                smallestBlockStart = current;
            }

            freePageCounter++;

            if(freePageCounter <= smallestNumberFreePages && freePageCounter >= minimumSize){
                theSmallestBlock = smallestBlockStart;
                smallestBlockStart = NULL;
                smallestNumberFreePages = freePageCounter;
                freePageCounter = 0;
            }

        }

        else if(current -> programName != "Free" && current ->nextPage == NULL){
            if(freePageCounter <= smallestNumberFreePages && freePageCounter >= minimumSize && freePageCounter != 0){
                theSmallestBlock = smallestBlockStart;
                smallestBlockStart = NULL;
                smallestNumberFreePages = freePageCounter;
                freePageCounter = 0;
            }

            else if(freePageCounter == 0 && (smallestNumberFreePages == 0 || smallestNumberFreePages == 32)){
                smallestNumberFreePages = 0;
            }

        }

        else if(current -> programName != "Free" && current ->nextPage != NULL){
            if(freePageCounter <= smallestNumberFreePages && freePageCounter >= minimumSize && freePageCounter != 0){
                theSmallestBlock = smallestBlockStart;
                smallestBlockStart = NULL;
                smallestNumberFreePages = freePageCounter;
                freePageCounter = 0;
            }
        }

        current = current -> nextPage;

    }

    smlstFree = smallestNumberFreePages;
    cout << "Number of Pages Available: " << smlstFree << endl;

    return theSmallestBlock;

}

struct pagenode *usedLargest(struct pagenode *head, int &lrgstFree){

    int largestNumberFreePages = 0;             
    int freePageCounter = 0;                    
    struct pagenode *theLargestBlock = NULL;     
    struct pagenode *largestBlockStart = NULL;     

    
    pagenode *current = head;
    current = current -> nextPage;

   
    while(current){

        if(current -> programName == "Free" && current -> nextPage != NULL){

            if(largestBlockStart == NULL){
                largestBlockStart = current;
            }

            freePageCounter++;
        }

        else if(current -> programName == "Free" && current -> nextPage == NULL){

            if(largestBlockStart == NULL){
                largestBlockStart = current;
            }

            freePageCounter++;

            if(freePageCounter > largestNumberFreePages) {
                theLargestBlock = largestBlockStart;
                largestBlockStart = NULL;
                largestNumberFreePages = freePageCounter;
                freePageCounter = 0;
            }

        }

        else if(current -> programName != "Free"){
            if(freePageCounter > largestNumberFreePages) {
                theLargestBlock = largestBlockStart;
                largestBlockStart = NULL;
                largestNumberFreePages = freePageCounter;
                freePageCounter = 0;
            }
        }
        current = current -> nextPage;

    }
    lrgstFree = largestNumberFreePages;

    return theLargestBlock;

}

void writeToUsed(pagenode *startNode, int numPages, string pgrmName){
    pagenode *current = startNode;


    for(int counter = 1; counter <= numPages; counter++){

        if(current -> programName == "Free"){
            current -> programName = pgrmName;
        }

        else if(current -> programName != "Free"){
            cout << "ERROR! Attempted Overwrite of Program in Memory!";
            return;
        }
        current = current -> nextPage;

    }
}
void allocateFF(struct pagenode **head, pagenode *pagetoFree){
    pagetoFree -> programName = "Free";

}

struct pagenode *searchPg(struct pagenode *head, string programName){
//did i mention i find using linkedlist for this assignments a little redundant? and i needed stackoverflow shoutout to them
    pagenode *current = head;

    while(current){
        if(current -> programName == programName) return current;
        current = current -> nextPage;
    }


    throw 1;

}
