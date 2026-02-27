#include <iostream>
#include <algorithm>
#include <cctype>
#include <random>
#include <chrono>
#include <thread>
#include <iomanip>

int main()
{
    double balance, deposit, withdraw; // I declared all the variable at the start cause this is more readable to ME
    int user_pincode, pincode_confirmation;
    std::string user_choice, user_currency_unit;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> random_balance(1.00, 1000000.00); // Generates a random balance

    balance = random_balance(gen);

    std::cout << "========== Banking Program ==========\n";
    std::cout << "Enter Pincode: ";
    std::cin >> user_pincode;

    std::cout << "Enter your currency unit: ";
    std::getline(std::cin, user_currency_unit);
    std::cin.ignore(); // Ignores the \n(next line) of input so that it doesn\t cause problem further ahead in the code

    while (true)
    {
        std::cout << "***** Commands *****\n";
        std::cout << "1. Show balance\n";
        std::cout << "2. Deposit money\n";
        std::cout << "3. Withdraw money\n";
        std::cout << "4. Exit\n";
        std::cout << "********************\n";

        std::cout << "Enter commmand: ";
        std::getline(std::cin, user_choice);

        std::transform(user_choice.begin(), user_choice.end(), user_choice.begin(), ::tolower); // Converted the user input to lowercases to reduce (or) conditional in if/else

        if (user_choice == "1" || user_choice == "show balance")
        {
            std::cout << "Your balance is " << user_currency_unit << std::setprecision(2) << std::fixed << balance << '\n'; // It shows the balance till 2 decimal places
        }
        else if (user_choice == "2" || user_choice == "deposit money")
        {
        }
        else if (user_choice == "3" || user_choice == "withdraw money")
        {
            std::cout << "Enter amount to withdraw: ";
            std::cin >> withdraw;

            if (withdraw > balance)
            {
                std::cout << "You can't withdraw more money than you have!\n";
            }
            else
            {
                balance -= withdraw;
                std::cout << "Transaction in process...\n";
                std::this_thread::sleep_for(std::chrono::seconds(2)); // This next output will show after 2 seconds
                std::cout << "Transaction completed\n";
            }

            std::cin.ignore(); 
        }
        else if (user_choice == "4" || user_choice == "exit")
        {
            std::cout << "Enter your pincode: ";
            std::cin >> pincode_confirmation;

            if (pincode_confirmation == user_pincode)
            {
                std::cout << "Thank you for using our bank. We hope you have a great day ahead.\n";
                std::cout << "=====================================\n";
                return 0;
            }
            else
            {
                std::cout << "INCORRECT PINCODE\n"; // Thought it would be funny to add this
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::cout << "INITIALISING SELF DESTRUCT\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::cout << "3..\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::cout << "2..\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::cout << "1..\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::cout << "BOOM\n";
                std::cout << "=====================================\n";
                return 0;
            }
        }
    }
}
