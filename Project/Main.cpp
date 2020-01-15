#include <iostream>
#include <string>	
#include "FBullCowGame.h"
using FText = std::string;
using int32 = int;
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // nowa gra

// punkt wejścia do aplikacji
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0; // zamknięcie aplikacji
}

// przedstawienie gry
void PrintIntro()
{
	std::cout << "\nWitamy w grze Bulls and Cows, najlepszej grze slownej!\n";
	std::cout << "Czy potrafisz zgadnac " << BCGame.GetHiddenWordLength();
	std::cout << " literowe slowo, o ktorym wlasnie mysle?\n";
	std::cout << std::endl;
	return;
}
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// pętla z pytaniem o domysły podczas gry
	// dalsze próby zgadywania
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();

		// domysły gry i liczba błędnych i poprawnych liter
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();
	return;
}

// zapętlaj ciągle, aż gracz poprawnie zgadnie
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// próba zgadnięcia gracza
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Proba " << CurrentTry << ". Wpisz swoja propzycje: ";
		std::getline(std::cin, Guess);
		
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Wpisz " << BCGame.GetHiddenWordLength() << " literowe slowo.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word witout repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
	
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Chcesz sprobowac jeszcze raz odgadnac to samo ukryte slowo (Tak/Nie)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 't') || (Response[0] == 'T');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Dobra robota! WYGRALES!\n";
	}
	else
	{
		std::cout << "Powodzenia nastepnym razem!\n";
	}
}