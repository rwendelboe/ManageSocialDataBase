#ifndef Friend_H
#define Friend_H
#include <string>
using namespace std;

struct Friend{
	string ScreenName; 
	int Age;
	string Interests;
};
//accessors
float ReportAge(Friend friends[], int size);
bool IsBefore (Friend friend1, Friend friend2) ;


//mutator functions
void AddFriend(Friend friends[], int size);
void RemoveFriend(Friend friends[], int size);
void SearchInterest(Friend friends[], int size, string keywords);
void DisplayFriend(Friend friends[], int size);
void ListFriend(Friend friends[], int size);



#endif