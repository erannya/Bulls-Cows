#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

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
    std::cout << "Witamy w grze Bulls and Cows, najlepszej grze slownej!\n";
    std::cout << "Czy potrafisz zgadnac " << WORLD_LENGTH;
    std::cout << " literowe slowo, o ktorym wlasnie mysle?\n";
    std::cout << std::endl;
    return;
}


void PlayGame()
{
    int MaxTries = BCGame.GetMaxTries();

    // loop for the number of turns asking for guesses
	for (int count = 1; count <= MaxTries; count++) {
		std::string Guess = GetGuess();
		std::cout << "Twoja propozycja: " << Guess << std::endl;
		std::cout << std::endl;
	}

}


std::string GetGuess()
{
    int CurrentTry = BCGame.GetCurrentTry();

    // get a guess from the player
    std::cout << "Proba " << CurrentTry << ". Wpisz swoja propozycje: ";
    std::string Guess = "";
    std::getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Chcesz sprobowac jeszcze raz? (Tak/Nie)";
    std::string Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 't') || (Response[0] == 'T');
}