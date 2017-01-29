#include <string>
using namespace std;
struct page{
    string programName;
    page *nextPage;
};

class Pal{
	
    public:
    	
     void bestUse();                                                                 
void worstUse();                                                               
void displayOption();                                                             
void initPG(struct page *head, string programName);                           
void addPg(struct page *head, string programName);                            
bool deletePg(struct page **head, page *pageDelete);                          
void deleteEnd(struct page *head);                                              
void outputMemory(struct page *head, struct page *head2);                       
void allocateFF(struct page **head, page *pagetoFree);                        

void countFragments(struct page *head, struct page *head2);                    
int kbtoPg(int kb);                                                         
int listLength(struct page *head);                                             
void writeToUsed(page *startNode, int numPages, string pgrmName);               
struct page *usedLargest(struct page *head, int &lrgstFree);                    
struct page *smallestUse(struct page *head, int &smlstFree, int minimumSize);  
struct page *searchPg(struct page *head, string programName);                 
bool inMemory(struct page *head, string programName);                           

// Memory Page Structure:

//ended up not using this since it gave extremely weird error even asked TA and he didnt know what to do

};
