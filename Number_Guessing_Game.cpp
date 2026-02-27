#include <iostream>
#include <random>
#include <cctype>
#include <algorithm>

int main()
{
    std::string user_difficulty, play_again; // I like declaring the variables at the start as it makes the code more readable to ME
    int max_num, tries, original_tries, random_number, guess;

    std::random_device rd;
    std::mt19937 gen(rd());

    while (true)
    {
        std::cout << "========== Number Guessing Game ==========\n";
        std::cout << "***** Difficulties *****\n";
        std::cout << "Easy - Range(1, 10), Tries = 3\n";
        std::cout << "Medium - Range(1, 50), Tries= 7\n";
        std::cout << "Hard - Range(1, 100), Tries = 12\n";
        std::cout << "*************************\n";

        std::cout << "Enter Difficulty(Easy, Medium, Hard): ";
        std::getline(std::cin, user_difficulty);

        std::transform(user_difficulty.begin(), user_difficulty.end(), user_difficulty.begin(), ::tolower); // Converts user input into lowercase to reduce (or) conditionals in if/else

        if (user_difficulty == "easy")
        {
            max_num = 10; 
            tries = 3;
        }
        else if (user_difficulty == "medium")
        {
            max_num = 50;
            tries = 7;
        }
        else if (user_difficulty == "hard")
        {
            max_num = 100;
            tries = 12;
        }
        else
        {
            std::cout << "Invalid Input\n";
            continue;
        }

        original_tries = tries;

        std::uniform_int_distribution<> rand_num(1, max_num);
        random_number = rand_num(gen); // Generates a random number according to the difficulty the user picked

        while (tries > 0)
        {
            std::cout << "Guess a number between 1 and " << max_num << ": ";
            std::cin >> guess;
            std::cin.ignore(); // It ignores the \n(next line) when we take input so that it doesn't cause error further ahead in the code

            tries--;

            if (guess == random_number)
            {
                std::cout << "You won\n";
                break; 
            }
            else if (guess > random_number)
            {
                std::cout << "Try guessing lower\n";
                std::cout << tries << " tries are left\n";
            }
            else if (guess < random_number)
            {
                std::cout << "Try guessing higher\n";
                std::cout << tries << " tries are left\n";
            }
        }

        if (guess == random_number)
        {
            std::cout << "You took " << tries << " tries\n";
        }
        else
        {
            std::cout << "You lost.\nThe number was " << random_number << '\n';
        }

        while (true)
        {
            std::cout << "Do you wanna play again (yes/no): ";
            std::getline(std::cin, play_again);

            std::transform(play_again.begin(), play_again.end(), play_again.begin(), ::tolower); // It converts the us

            if (play_again == "yes" || play_again == "y")
            {
                std::cout << "==========================================\n";
                break; 
            }
            else if (play_again == "no" || play_again == "n")
            {
                std::cout << "Thanks for playing\n";
                std::cout << "==========================================\n";
                return 0; // Didn't use break cuase then it would just have just broken the inner loop not the main game loop
            }
            else
            {
                std::cout << "Please answer in yes/no or y/n\n";
            }
        }
    }

    return 0;
}