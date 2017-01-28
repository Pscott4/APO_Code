#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
class Calculate{
	public: float dist(int,int,int ,int);
	string lik(int, int, int, bool);
	float arrival(int,int,int);
	bool luck(int);
	
};

float Calculate::dist (int latm, int lonm, int lonp, int latp){
	float x = abs(latm - latp);
	float y = abs(lonm - lonp);
	return (x+y)*1000;
}
float Calculate::arrival(int app, int ws, int distance){
  return (app + float(distance/ws));
}

string Calculate::lik(int arrival, int las,int appeartime, bool lucky){
 float per = 100*(arrival-(appeartime+las))/las;
 if(arrival <= appeartime + las){
 	return "Definitely Capture";
 }
 if(lucky){
 	if (per <= 10 ){
 	return "Highly Likely";
 }
 if(per <=30){
 	return "Likely";
 }
 if(per <= 40){
 	return "Unsure";
 }
 if(per <= 50){
 	return "Unlikely";
 }
 else{return "Highly Unlikely";}
 }
 else{
 	if (per <= 5 ){
 	return "Highly Likely";
 }
 if(per <=20){
 	return "Likely";
 }
 if(per <= 35){
 	return "Unsure";
 }
 if(per <= 40){
 	return "Unlikely";
 }
 else{return "Highly Unlikely";}
 }
}

bool Calculate::luck(int lucky){
	if(lucky <= 49){
		return true;
	}
	else{ return false; }
}




class Check {
	public: bool checking(int, int, int ,int ,int , int ,int ,int ,int );
};

bool Check::checking (int lonm, int latm, int tim,int las,int id, int app,int  latp,int  lonp,int ws){
	string test = to_string(id);

	if(!(latm >= 1 && latm <= 10)) { return false; }

	if(!(lonm >= 1 && lonm <= 10)){ return false;}

	if(!(tim >= 1 && tim <= 1440)){ return false;}

	if(!(las >= 10 && las <= 59)){ return false; }

	if(!(test.length() == 8)){ return false; }

	if(!(app > 1 && app <= 1440 && app > tim)){return false;  }

	if(!(lonp >= 1 && lonp <= 10)){ return false; }

	if(!(latp >= 1 && latp <= 10)){ return false; }

	if(!(ws >= 10 && ws <= 200)){ return false; }

	return true;
}




int main(){
	int lonm, latm, tim, las, id, app, latp, lonp, ws;
	while(true){
	cout << "Please enter the latitude of the monster (1-10): ";

	cin >> latm;

	cout << endl << "Please enter the longitude of the monster (1-10): ";

	cin >> lonm;

	cout << endl << "Please enter the time of the monster appear (1-1440): ";

	cin >> tim;

	cout << endl << "Please enter the possible time of the monster will exist (10-59): ";

	cin >> las;

	cout << endl << "Please enter the player’s ID (8 digits): ";

	cin >> id;

	cout << endl << "Please enter the time of the player noticing monster (1-1440 and greater than the time the monster appear): ";

	cin >> app;

	cout << endl << "Please enter the latitude of the player (1-10): ";

	cin >> latp;

	cout << endl << "Please enter the longitude of the player (1-10): ";

	cin >> lonp;

	cout << endl << "Please enter the player's walking speed (10-200): ";

	cin >> ws;

	Check pls;

	 bool a = pls.checking(lonm, latm, tim, las, id, app, latp, lonp, ws);
     if(a){
     	break;
     }
     cout << "You didn't enter some variable correctly try again." << endl;
	}

	Calculate yeh;
	int luckyid = id%100;
	bool lucky = yeh.luck(luckyid);
	string typ = "Normal list";
	if(lucky){
		string typ = "Lucky List";
	}
	float distance = yeh.dist(latm, lonm, lonp, latp);
	float arrival = yeh.arrival(app, ws, distance);
	int appeartime = las + tim;
	string chance = yeh.lik(arrival, las, appeartime,lucky);
	cout << endl << "Player " << id << " who is on the " << typ << endl;
	cout << "noticed the monster at time " << app << endl;
	cout << "is " << distance << " m away from the monster," << endl;
	cout << "The monsters's disappear time is about " << appeartime << endl;
	cout << "So the player will capture this monster with " << chance << " possibility" << endl;

	return 0;


}