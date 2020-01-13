/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
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
    constexpr int32 WORD_LENGTH = 9;
    std::cout << "Witamy w grze Bulls and Cows, najlepszej grze slownej!\n";
    std::cout << "Czy potrafisz zgadnac " << WORD_LENGTH;
    std::cout << " literowe slowo, o ktorym wlasnie mysle?\n";
    std::cout << std::endl;
    return;
}


void PlayGame()
{
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();

    // loop for the number of turns asking for guesses
	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess();
		std::cout << "Twoja propozycja: " << Guess << std::endl;
		std::cout << std::endl;
	}

}


FText GetGuess()
{
    int32 CurrentTry = BCGame.GetCurrentTry();

    // get a guess from the player
    std::cout << "Proba " << CurrentTry << ". Wpisz swoja propozycje: ";
    FText Guess = "";
    std::getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Chcesz sprobowac jeszcze raz? (Tak/Nie)";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 't') || (Response[0] == 'T');
}