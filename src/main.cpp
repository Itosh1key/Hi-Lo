#include "ErrorHandling.h"
#include "Random.h"
#include <iostream>

namespace AboutProgram {
    std::string name { "Hi-Lo" };
    std::string version { "1.0.0" };
    std::string author { "Itosh1key" };

    void print()
    {
        std::cout << name << " v" << version << '\n'
                  << "By " << author << "\n\n";
    }
} // namespace AboutProgram

int getGuess(int count, int min, int max)
{
    while (true) {
        std::cout << "Guess #" << count << ": ";
        int guess {};
        std::cin >> guess;

        if (ErrorHandling::clearFailedExtraction()) {
            std::cout << "Error: Invalid input. Please try again.\n";
            continue;
        }

        if ((guess < min) || (guess > max)) {
            std::cout << "Error: Your guess is out of bounds. Please try again.\n";
            continue;
        }

        ErrorHandling::ignoreLine();

        return guess;
    }
}

// returns true if the user won, false if they lost
bool playHiLo(int guesses, int min, int max)
{
    std::cout << "Let's play a game. I'm thinking of a number between "
              << min << " and " << max << ". You have " << guesses
              << " tries to guess what it is.\n";
    int number { Random::get(min, max) }; // this is the number the user needs to guess

    // Loop through all of the guesses
    for (int count { 1 }; count <= guesses; ++count) {
        int guess { getGuess(count, min, max) };

        if (guess > number)
            std::cout << "Your guess is too high.\n";
        else if (guess < number)
            std::cout << "Your guess is too low.\n";
        else // guess == number, so the user won
        {
            std::cout << "Correct! You win!\n";
            return true;
        }
    }

    // The user lost
    std::cout << "Sorry, you lose. The correct number was " << number << '\n';
    return false;
}

bool playAgain()
{
    // Keep asking the user if they want to play again until they pick y or n.
    while (true) // Loop until user enters a valid input
    {
        char ch {};
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> ch;

        // we'll handle error messaging if extraction failed below
        if (!ErrorHandling::clearFailedExtraction())
            // remove any extraneous input (only if extraction succeded)
            ErrorHandling::ignoreLine();

        switch (ch) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            std::cout << "Error: Invalid input. Please try again.\n";
        }
    }
}

int main()
{
    AboutProgram::print();

    constexpr int guesses { 7 }; // the user has this many guesses
    constexpr int min { 1 };
    constexpr int max { 100 };

    do {
        playHiLo(guesses, min, max);
    } while (playAgain());

    std::cout << "\nThank you for playing.\n";
}