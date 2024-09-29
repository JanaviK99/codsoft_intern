#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    //Seed the random number generator
    srand((unsigned)time(NULL));

    //Generate an random number between 1 and 100
    int secretNumber=rand() % 100+1;

    cout<<"Welcome to the Number Guessing Game!"<<"\nI have thought a random number in the range 1 to 100"<<"\nYou have to guess it in less attempts.\n";

    int guess,attempts=0;
    
    do{
        cout<<"Guess the number:";
        cin>>guess;

        attempts++;
        if(guess<secretNumber){
        cout<<"Too Low! Try again.\n";
        }
        else if(guess>secretNumber){
            cout<<"Too High! Try again.\n";
        }
        else{
            cout<<"CONGRATULATIONS, You have guessed the number "<<secretNumber<<" correctly.\n";
             
             cout<<"You have made total "<<attempts<<" attempts.";
        }
    
    }while(guess!=secretNumber);
    return 0;
}