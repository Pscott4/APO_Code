#include<iostream> 

using namespace std;
 class Node{   //Create Node Class
 public:

Node(int n); 
Node* nextNodePointer; 
int number;
 };  
 Node::Node(int n){
 number=n; //Set node value to n
 };  
 

 class LinkedList{//Create Linked List Class
 public:

Node*head=NULL; 
void insertNodeAtHead(int num); 
void printList();
 };  

void LinkedList::insertNodeAtHead(int num){ 
Node* temp=head;  //Set temp equal to head

head=new Node(num); //Create a new node based on 
head->nextNodePointer=temp;//Set the new head node to     the old head node
 };  

 void LinkedList::printList(){
 Node *temp=head; //Start temp at the beginning of List  
 while(temp!=NULL){ //When nextNode points to Null it is end of the list
 cout<<temp->number<<" "; //Print number at Node temp  temp=temp->nextNodePointer; //Set temp to next Node in list
 }  };  

 int main(){
 int num;
LinkedList *L1= new LinkedList();
 //Set Number of Elements (50,000 is noticeable)  LinkedList *L1= new LinkedList();//Instantiate L1 object from Linked List

 for(int i=0;i<num;i++){
 L1->insertNodeAtHead(i); //insert i into L1 at Head
 }  L1->printList();    //Print L1 return 0;
 };