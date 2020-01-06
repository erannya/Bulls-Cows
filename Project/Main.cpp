// Project.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // introduce the game
    constexpr int WORLD_LENGTH = 5;
    cout << "Welcome to Bulls and Cows, a fun word game!\n";
    cout << "Can you guess the " << WORLD_LENGTH;
    cout << " letter isogram I'm thinking of?\n";
    cout << endl;

    // get a guess from the player
    cout << "Enter your guess: ";
    string Guess = ""; 
    cin >> Guess;

    // repeat the guess back to them
    cout << "Your guess was: " << Guess << endl;

    // get a guess from the player
    cout << "Enter your guess: ";
    cin >> Guess;

    // repeat the guess back to them
    cout << "Your guess was: " << Guess << endl;

    cout << endl;
    return 0;
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
