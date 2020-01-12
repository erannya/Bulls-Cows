#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
    std::cout << "Witamy w grze Bulls and Cows, najlepszej grze slownej!\n";
    std::cout << "Czy potrafisz zgadnac " << WORLD_LENGTH;
    std::cout << " literowe slowo, o ktorym wlasnie mysle?\n";
    std::cout << std::endl;
    return;
}


void PlayGame()
{
    // loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		std::string Guess = GetGuess();
		std::cout << "Twoja propozycja: " << Guess << std::endl;
		std::cout << std::endl;
	}

}


std::string GetGuess()
{
    // get a guess from the player
    std::cout << "Wpisz swoja propozycje: ";
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