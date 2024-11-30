#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int attempts=8;
string note="You have eight attempts";
void hangman(char state){
	string headstring="|";
	string death="==============";
	string pully="/";
	if(state=='f'){
		headstring=" ";
		pully="\\";
	}
	if(state=='h'){
		death="               ";
	}
    cout<<"\t\t\t\t\t_____________________________"<<endl;
    cout<<"\t\t\t\t\t               "<<headstring<<"           |"<<endl;
    cout<<"\t\t\t\t\t               O           |"<<endl;
    cout<<"\t\t\t\t\t              / \\          |"<<"\t       "<<note<<endl;
    cout<<"\t\t\t\t\t               |           |"<<"\t        /"<<endl;
    cout<<"\t\t\t\t\t              / \\          |           o  "<<endl;
    cout<<"\t\t\t\t\t         "<<death<<"    |          / \\"<<endl;
    cout<<"\t\t\t\t\t         |            |    |     __"<<pully<<"__ |  "<<endl;
    cout<<"\t\t\t\t\t         |            |    |     |   |/ \\"<<endl;
    cout<<"\t\t\t\t\t============================================|"<<endl;
};

int checkguess(char guess,string realcountry,string &hiddencountry)
{
	int matches=0;
	int len=realcountry.length();
	for(int i=0;i<len;i++){
		if(guess==hiddencountry[i])
		return 0;
		if(guess==realcountry[i]){
			hiddencountry[i]=guess;
			matches++;
		}
	}
	return matches;
}
int main(){
	char letter;
	string country;
	string countries[]={"india","pakistan","bangladesh"};
	srand(time(0));
	int countrynumber=rand()%3;
	country=countries[countrynumber];
	string hidecountry(country.length(),'X');
	system("cls");
	while(attempts!=0){
		hangman('n');
		cout<<"\t\t\t\t\tLife  "<<attempts<<endl;
		cout<<"\t\t\t\t\tHidden Country Name  "<<hidecountry<<endl;
		cout<<"\t\t\t\t\tGuess the letter  "<<letter<<endl;
		cin>>letter;
		system("cls");
		if(checkguess(letter,country,hidecountry)==0){
			note="Wrong";
			attempts--;
			hangman('n');
		}
		else
		note="good";
		if(hidecountry==country){
			note="Congrajulations!!! You are free.";
        hangman('f');
        cout<<"\t\t\t\t\tLife "<<attempts<<endl;
        cout<<"\t\t\t\t\tThe country is "<<country<<endl;break;
		}
	}	
	if(attempts==0)
	{
		  note="Sorry!, you are hanged!!";
    hangman('h');
    cout<<"\t\t\t\t\tLife "<<attempts<<endl;
        cout<<"\t\t\t\t\tThe country is "<<country<<endl;
	}
	return 0;
}

