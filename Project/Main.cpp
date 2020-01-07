#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

// the entry point for our application
int main()
{
    bool bPlayAgain = false;
    do {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while (bPlayAgain);

    return 0; //exit the application
}


// introduce the game
void PrintIntro() 
{
    constexpr int WORLD_LENGTH = 9;
    cout << "Witamy w grze Bulls and Cows, najlepszej grze slownej!\n";
    cout << "Czy potrafisz zgadnac " << WORLD_LENGTH;
    cout << " literowe slowo, o ktorym wlasnie mysle?\n";
    cout << endl;
    return;
}


void PlayGame()
{
    // loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		string Guess = GetGuess();
		cout << "Twoja propozycja: " << Guess << endl;
		cout << endl;
	}

}


string GetGuess()
{
    // get a guess from the player
    cout << "Wpisz swoja propozycje: ";
    string Guess = "";
    getline(cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    cout << "Chcesz sprobowac jeszcze raz? (Tak/Nie)";
    string Response = "";
    getline(cin, Response);
    return (Response[0] == 't') || (Response[0] == 'T');
}