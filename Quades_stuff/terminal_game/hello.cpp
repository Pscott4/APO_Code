#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
using namespace std;


int changetext(string clas);

class Character {
private:
  int iq;
  int strength;
  int speed;
  int luck;
  int stamina;
  int wisdom;
  int defense;
  int Dexterity;
  int maxhealth;
  int health;
  string name;
  string clas;
  int xloc;
  int yloc;
  
  

public: 
  int mobhealth;
  int x;
  int y;
  void CheckStats();
  void MakeWizard();
  void MakeFighter();
  void MakeRogue();
  void MakeKnight();
  void Rest(int);
  void Setname(string);
  void takecommand(string);
  void intro();
  void movearound();
  void CheckHealth();
  void Hurtself();
  void Suicide();
  void Attack();
  void Mobs(string);
  int Ghost();
};



int Character::Ghost(){
  

  if( 2 >= abs(xloc - x) && 2 >= abs(yloc - y)){

    string line;
        ifstream myfile ("ghost.txt");
        if (myfile.is_open()){
      
        while ( getline (myfile,line) )
      {
      cout << "\e[90m\e[5m" << line << "\n\e[0m";
    }
    myfile.close();
  }

    health = health -2;
    cout << "You've been attacked by a ghost" << endl;
    return 0;
  }
  if(0 >= mobhealth){
    cout <<"\n You Killed the ghost" << endl;
    return 1;
  }

  return 0;

}


void Character::Attack(){
  
  
  string attack;
  if(!clas.compare("Wizard")){
    cout << "Fireball" << endl;
    cout << "Lightning" << endl;
    cout << "Ice Baby" << endl;
    cout << "Fireball \n" << endl;
    getline(cin,attack);

      if(!attack.compare("Fireball")){
        mobhealth = mobhealth - 2;
        cout << "You catapault a ball of fire towards your enemy"

        

  }
  else if(!attack.compare("Lightning")){
    mobhealth = mobhealth - 2;
    
  }
  else if(!attack.compare("Ice Baby")){
    mobhealth = mobhealth - 2;
    
  }
  else if(!attack.compare("Fireball")){
    mobhealth = mobhealth - 2;
  }
  else{cout << "Thats not a move you can use." << endl;}

  }
  else if(!clas.compare("Knight")){
    cout << "Slash" << endl;
    cout << "Stab" << endl;
    cout << "Holy Smight" << endl;
    cout << "Heavens meteor" << endl;
    getline(cin,attack);

      if(!attack.compare("Slash")){
      int dmg = 0;
  }
  else if(!attack.compare("Stab")){
    mobhealth = mobhealth - 2;
    
  }
  else if(!attack.compare("Holy Smight")){
    mobhealth = mobhealth - 2;
    
  }
  else if(!attack.compare("Heavens meteor")){
    mobhealth = mobhealth - 2;
  }
  else{cout << "Thats not a move you can use." << endl;}
    
  }
  else if(!clas.compare("Rogue")){
    cout << "BackStab" << endl;
    cout << "Poison Dart" << endl;
    cout << "flapflap" << endl;
    cout << "Slash" << endl;
    getline(cin,attack);

      if(!attack.compare("BackStab")){
        mobhealth = mobhealth - 2;
  }
  else if(!attack.compare("Poison Dart")){
    mobhealth = mobhealth - 2;
    
  }
  else if(!attack.compare("flapflap")){
    mobhealth = mobhealth - 2;
    
  }
  else if(!attack.compare("Slash")){
    mobhealth = mobhealth - 2;
  }
  else{cout << "Thats not a move you can use." << endl;}
    
  }
  else if(!clas.compare("Fighter")){
    cout << "Holy fist" << endl;
    cout << "gatlen fist" << endl;
    cout << "Mega Fist" << endl;
    cout << "Kickers Delight" << endl;
    getline(cin,attack);

      if(!attack.compare("Holy fist")){
    
  }
  else if(!attack.compare("gatlen fist")){
    mobhealth = mobhealth - 2;
    
  }
  else if(!attack.compare("Mega fist")){
    mobhealth = mobhealth - 2;
    
  }
  else if(!attack.compare("Kickers Delight")){
    mobhealth = mobhealth - 2;
  }
  else{cout << "Thats not a move you can use." << endl;}
  }
  else{cout << "What are you?!!" << endl;}

}

void Character::Hurtself(){
  health--;
}
void Character::Suicide(){
  cout << "Pussy" << endl;
  health = 0;
}
void Character::CheckHealth(){
  if(health <= 0){
    system("cat test.txt");
    system("killall afplay");
    exit(0);
  }
}

void Character::takecommand(string word){
  if(!word.compare("rest")){
    int n;
    
    cout << "How long would you like to rest for?" << endl;
    cin >> n;
    Rest(n);
  }
  else if(!word.compare("fuck")){
    cout << "well okay" << endl << endl;
  }
  else if(!word.compare("check myself")){
    CheckStats();
  }
  else if(!word.compare("save")){
    cout << "that hasnt been implemented yet" << endl;
  }
  else if(!word.compare("exit")){
    system("killall afplay");
    exit(0);
  }
  else if(!word.compare("help")){
    cout << "Okay man its not complete but the commands are" << endl;
    cout << " rest \n save \n exit \n fuck \n check myself \n move \n hurt yourself \n commit suicide \n Attack" << endl;
  }
  else if(!word.compare("move")){
    movearound();
    }
  else if(!word.compare("hurt myself")){
    Hurtself();
  }
  else if(!word.compare("commit suicide")){
    Suicide();
  }
  else if(!word.compare("attack")){
    cout << "what move are you going to use?" << endl;
    Attack();
  }
  else{
    cout << "Well you cant \n" << endl ;
  }

}

void Character::MakeWizard(){
  iq = 40;
  maxhealth = 20;
  speed = 20;
  strength = 10;
  wisdom = 25;
  defense = 10;
  Dexterity = 20;
  health = maxhealth;
  clas = "Wizard";
  luck = rand() % 100 + 1;
  xloc = 0;
  yloc = 0;
//I slightly favor Wizards + 5 points
}

void Character::MakeRogue(){
  iq = 20;
  maxhealth = 20;
  speed = 30;
  strength = 20;
  wisdom = 15;
  defense = 5;
  Dexterity = 30;
  health = maxhealth;
  clas = "Rogue";
  luck = rand() % 100 + 1;
  xloc = 0;
  yloc = 0;
}

void Character::MakeFighter(){
  iq = 15;
  maxhealth = 25;
  speed = 30;
  strength = 25;
  wisdom = 15;
  defense = 10;
  Dexterity = 20;
  health = maxhealth;
  clas = "Fighter";
  luck = rand() % 100 + 1;
  xloc = 0;
  yloc = 0;
}

void Character::MakeKnight(){
  iq = 10;
  maxhealth = 30;
  speed = 10;
  strength = 25;
  wisdom = 20;
  defense = 35;
  Dexterity = 10;
  health = maxhealth;
  clas = "Knight";
  luck = rand() % 100 + 1;
  xloc = 0;
  yloc = 0;
}

void Character::CheckStats(){
  cout << "Name: " << name << endl;
  cout << "IQ: " << iq << endl;
  cout << "Health: " << health << "/" << maxhealth << endl;
  cout << "Speed: " << speed << endl;
  cout << "Strength:  " << strength << endl; 
  cout << "Wisdom: " << wisdom << endl;
  cout << "Defense: " << defense << endl;
  cout << "Dexterity: " << Dexterity << endl;
  cout << "Luckiness: " << luck << endl << endl;
  
}

void Character::Setname(string yes){
  name = yes;
}

void Character::Rest(int tim){
  health += tim;
  if(health > maxhealth){
    health = maxhealth;
  }
  cout << "You have rested for " << tim * 10  << " minutes"<< endl;
}

void Character::intro(){
  string line;
  ifstream myfile ("intro.txt");
        if (myfile.is_open()){
      
        while ( getline (myfile,line) )
      {
      cout << "\e[91m" << line << "\n";
    }
    myfile.close();
  }   
}

void Character::movearound(){
    string direction;
    cout << "Which way are you moving?" << endl;
    cin >> direction;
    if(!direction.compare("left")){
      xloc--;
    }
    else if(!direction.compare("right")){
      xloc++;
    }
    else if(!direction.compare("forward")){
      yloc++;
    }
    else if(!direction.compare("back")){
      yloc--;
    }
    else{ cout << "thats not a accepted direction" << endl << endl;}
    cout << "your current loaction is x: " << xloc << " y: " << yloc << endl;
}

void Character::Mobs(string name){
      if(!name.compare("goblin")){
        //goblin();
      }
      if(!name.compare("skeleton")){
        //skeleton();
      }
      if(!name.compare("ghost")){
        Ghost();
      }
}

int main () {
  Character quade;
  quade.intro();
  system("afplay test.wav &");
  int num;
  string userchoice;
  //intro screen
  string name;
  cout << "\e[0mHey kiddo what's your name?" << endl;
  cin >> name;
  
  quade.Setname(name);


  cout << "what class would you like to be? \n wizard \n knight \n rogue \n fighter" << endl;
  cin >> userchoice;
  num = changetext(userchoice);
  bool Charclass = true;

  while(Charclass){
    cout << num << endl;
    switch(num){
      default: {
        cout << "what?" << endl;
        cin >> userchoice;
        num = changetext(userchoice);
        break;
      }

      case 1:{
        string line;
        ifstream myfile ("wizard.txt");
        if (myfile.is_open()){
      
        while ( getline (myfile,line) )
      {
      cout << "\e[34m" << line << "\n";
    }
    myfile.close();
  }   
      quade.MakeWizard();
      quade.CheckStats();
      cout << "\e[0mIf you are sure you want to be this class type yes" << endl;
      string choice;
      cin >> choice;
      if(!choice.compare("yes")){
        Charclass = false;
        break;
      }
      cout << "\e[0mAlright what class would you like to be then?"<< endl;
      cin >> userchoice;
      num = changetext(userchoice);
      break;
      }

      case 2:{
        string line;
        ifstream myfile ("rogue.txt");
        if (myfile.is_open()){
      
        while ( getline (myfile,line) )
      {
      cout << "\e[90m" << line << "\n";
    }
    myfile.close();
  }   
      quade.MakeRogue();
      quade.CheckStats();
      cout << "\e[0mIf you are sure you want to be this class type yes" << endl;
      string choice;
      cin >> choice;
      if(!choice.compare("yes")){
        Charclass = false;
        break;
      }
      cout << "\e[0mAlright what class would you like to be then?"<< endl;
      cin >> userchoice;
      num = changetext(userchoice);
      break;
      }

      case 3:{
        string line;
        ifstream myfile ("fighter.txt");
        if (myfile.is_open()){
      
        while ( getline (myfile,line) )
      {
      cout << "\e[32m" << line << "\n";
    }
    myfile.close();
  }   
      quade.MakeFighter();
      quade.CheckStats();
      cout << "\e[0mIf you are sure you want to be this class type yes" << endl;
      string choice;
      cin >> choice;
      if(!choice.compare("yes")){
        Charclass = false;
        break;
      }
      cout << "\e[0mAlright what class would you like to be then?"<< endl;
      cin >> userchoice;
      num = changetext(userchoice);
      break;
      }

      case 4:{
        string line;
        ifstream myfile ("knight.txt");
        if (myfile.is_open()){
      
        while ( getline (myfile,line) )
      {
      cout << "\e[93m" << line << "\n";
    }
    myfile.close();
  }   
      quade.MakeKnight();
      quade.CheckStats();
      cout << "\e[0mIf you are sure you want to be this class type yes" << endl;
      string choice;
      cin >> choice;
      if(!choice.compare("yes")){
        Charclass = false;
        break;
      }
      cout << "\e[0mAlright what class would you like to be then?"<< endl;
      cin >> userchoice;
      num = changetext(userchoice);
      break;
      }

      case 5:{
        system("killall afplay");
        exit(0);
        break;
      }

    }


  }
  string line;
        ifstream myfile ("forest.txt");
        if (myfile.is_open()){
      
        while ( getline (myfile,line) )
      {
      cout << "\e[32m" << line << "\n";
    }
    myfile.close();
    }
  cout << "\e[41mYou Look Around and all you see is A forest, \n What do you do now?\e[0m" << endl;

    quade.mobhealth = 5;
    quade.x = 3;
    quade.y = 3;
    string command;
  while(true){
    quade.CheckHealth();
    
    
    cout << "\e[34mwhat do you want to do now?\e[0m" << endl;
    
    getline(cin,command);
    cout << endl;
    quade.takecommand(command);
    if(quade.Ghost() == 1){
      break;

    }

      
   }

  cout << "you did it you beat the game!" << endl;
  /* while(true){
    quade.CheckHealth();
    string command;
    
    getline(cin,command);
    cout << endl;
    quade.takecommand(command);
    


  }
*/


  system("killall afplay");

  return 0;
}


int changetext(string clas){
  if(!clas.compare("wizard") ){
    return 1;
  }
  if(!clas.compare("rogue") ){
    return 2;
  }
  if(!clas.compare("fighter")){
    return 3;
  }
  if(!clas.compare("knight")){
    return 4;
  }
  if(!clas.compare("Exit") ){
    return 5;
  }
  return 0;
}

