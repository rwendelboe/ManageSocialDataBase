#include <iostream>
#include "Friend.h"

float ReportAge(Friend friends[], int size){
	float average;
	float TotalAge = 0;
	float NumberofPeople = 0;
	for(int i = 0; i< size; i++){
		if (friends[i].ScreenName != "EMPTY")
		{
			NumberofPeople = NumberofPeople+1;
			TotalAge = friends[i].Age + TotalAge;
		}
		
	}
		average = (TotalAge / NumberofPeople);
		cout<<"The Average Age of All My Friends is: "<<average<<endl;
		cout<<endl;
		return average;
		

}

bool IsBefore (Friend friend1, Friend friend2)
{
	for( int i = 0; i< friend1.ScreenName.size(); i++){
		friend1.ScreenName[i]= tolower(friend1.ScreenName[i]);
	}
	for( int i = 0; i< friend2.ScreenName.size(); i++){
		friend2.ScreenName[i]= tolower(friend2.ScreenName[i]);
	}

	if ( friend1.ScreenName < friend2.ScreenName){
		return true;
	}
	if (friend1.ScreenName > friend2.ScreenName){
		return false;
	}
	if(friend1.Age < friend2.Age) return true;

	if(friend1.Age > friend2.Age) return false;

	return true;
}
		void Swap (Friend &a, Friend &b) 
	{
		Friend temp ; 
		temp = a ; 
		a=b ;
		b = temp ;
	}
		void BubbleSort (Friend array[ ], int size)
	{
		bool done = false;
		while (!done) 
		{
			done = true;
			for (int n=0; n<size-1; n++)
				if (! IsBefore (array[n], array[n+1]) )
				{
					Swap (array[n], array[n+1]); done = false;
				} 
		}
		size -- ; 
	}



//mutator functions
void AddFriend(Friend friends[], int size){
	int i = 0;
	while ((friends[i].ScreenName!= "EMPTY"|| friends[i].Interests!= "EMPTY" || friends[i].Age!= 0) && i<size){
		i++;
	}
	cout<<"Add a New Friend"<<endl;
	cout<<"Type The Friends Name ";
	cin>>friends[i].ScreenName;
	cout<<"Type the Friends Interests ";
	cin.get();
	getline(cin,friends[i].Interests);
	cout<<"Type The Friends Age ";
	cin>>friends[i].Age;
	cout<<endl;
	cout<<endl;

}
void RemoveFriend(Friend friends[], int size){
	int index;

	cout<<"Remove a Friend"<<endl;
	if(friends[0].ScreenName!= "EMPTY"){
		for(int i = 0; i<size; i++){
			cout<<i<<" "<<friends[i].ScreenName<<endl;
			cout<<endl;
		}
		cout<<"Enter the number of the Friend You want to remove"<<endl;
		cin>>index;
		friends[index].ScreenName = "EMPTY";
		friends[index].Interests = "EMPTY";
		friends[index].Age = 0;

	}
}
void SearchInterest(Friend friends[], int size, string keywords){
	string temp;
	int index;
	for(int i = 0; i< static_cast<int>(keywords.size()); i++){
		keywords[i]= tolower(keywords[i]);
	}

	for( int j = 0; j< size; j++){
		temp = friends[j].Interests;
		for(int i = 0; i< static_cast<int>(temp.size()); i++){
			temp[i]= tolower(temp[i]);
		}
		index = temp.find(keywords, 0);
		if (index != -1){
		cout<<friends[j].ScreenName<<endl;
		cout<<endl;
		}
	}
}
void DisplayFriend(Friend friends[], int size){
	for( int i = 0; i < size; i++){
		if((friends[i].ScreenName!= "EMPTY"|| friends[i].Interests!= "EMPTY" || friends[i].Age!= 0) && i<size){
		cout<<"Index: "<<i<<endl;
		cout<<"Screen Name: "<< friends[i].ScreenName<<endl;
		cout<<"Interests: "<<friends[i].Interests<<endl;
		cout<<"Age: "<< friends[i].Age<<endl;
		cout<<endl;
		}
	}
}
void ListFriend(Friend friends[], int size){
	Friend TempArray[5];
	int i;
	for ( int i = 0 ; i < 5; i++){
		TempArray[i].ScreenName = friends[i].ScreenName;
		TempArray[i].Interests = friends[i].Interests;
		TempArray[i].Age = friends[i].Age;
		
	}
	BubbleSort(TempArray, 5);
	
	for (int i = 0; i<5; i++){
		if(TempArray[i].ScreenName != "EMPTY"){
		cout<<TempArray[i].ScreenName<<endl;
		}
	}
}