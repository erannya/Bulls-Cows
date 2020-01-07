// Project.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// the entry point for our application
int main()
{
    PrintIntro();

    GetGuessAndPrintBack();
    GetGuessAndPrintBack();

    cout << endl;
    return 0;
}

// introduce the game
void PrintIntro() {
    constexpr int WORLD_LENGTH = 5;
    cout << "Welcome to Bulls and Cows, a fun word game!\n";
    cout << "Can you guess the " << WORLD_LENGTH;
    cout << " letter isogram I'm thinking of?\n";
    cout << endl;
}

// get a guess from the player
string GetGuessAndPrintBack() {
    cout << "Enter your guess: ";
    string Guess = "";
    getline(cin, Guess);

    // print the guess back
    cout << "Your guess was: " << Guess << endl;
    return Guess;
}
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
