#include <iostream>
#include "Friend.h"

using namespace std;

int main(){
	Friend FriendsArray[5];
	for (int i = 0; i<5; i++){
		FriendsArray[i].ScreenName = "EMPTY";
		FriendsArray[i].Interests = "EMPTY";
		FriendsArray[i].Age = 0;
	}
	string keyword;
	char choice;

	do
	{
		
		cout<<"*** Network of My Friends *** "<<endl;
		cout<<"A: Add a Friend "<<endl;
		cout<<"R: Remove a Friend"<<endl;
		cout<<"S: Search Interests"<<endl;
		cout<<"D: Display All Friends"<<endl;
		cout<<"L: List All Friends in Alphabetic Order Based on ScreenName "<<endl;
		cout<<"C: Calculate the Average Age of All Friends in My Network "<<endl;
		cout<<"E: Exit"<<endl;
		cout<<endl;
		
		cin>>choice;

			switch (choice)
		{
			case 'A':
				AddFriend(FriendsArray, 5);
				break;
			case 'R':
				RemoveFriend(FriendsArray, 5);
				break;
			case 'S':
				cout<<"Input the keyword you want to search"<<endl;
				cin>>keyword;
				SearchInterest(FriendsArray, 5,keyword);
				break;
			case 'D':
				DisplayFriend(FriendsArray, 5);
				break;
			case 'L':
				ListFriend(FriendsArray, 5);
				break;
			case 'C':
				ReportAge(FriendsArray, 5);
				break;
			default:
				cout<<"I do not understand\n";

			}
	} while (choice != 'E');

	return 0;
}