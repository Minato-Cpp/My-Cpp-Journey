#include <iostream>
#include <algorithm>
#include <cctype>

int main()
{
    std::cout << "========== Calculator ==========\n";
    double num1, num2, result;
    char op;
    std::string another_calc;
    while (true)
    {
        std::cout << "Enter first number: ";
        std::cin >> num1;

        std::cout << "Enter second number: ";
        std::cin >> num2;

        std::cout << "Enter operator(+, -, *, /): ";
        std::cin >> op;
        std::cin.ignore(); // It ignores the \n(next line) when we enter input

        switch (op)
        {
        case '+':
            result = num1 + num2;
            std::cout << "Sum is " << result << '\n';
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Difference is " << result << '\n';
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Product is " << result << '\n';
            break;
        case '/':
            if (num2 == 0)
            {
                std::cout << "Can't divide with zero!\n";
            }
            else
            {
                result = num1 / num2;
                std::cout << "Quotient is " << result << '\n';
            }
            break;
        default:
            std::cout << "Invalid Input\n";
            break;
        }
        std::cout << "Do you wanna perform another calculation(yes/no): ";
        std::getline(std::cin, another_calc);

        transform(another_calc.begin(), another_calc.end(), another_calc.begin(), ::tolower);

        if (another_calc == "y" || another_calc == "yes")
        {
            continue;
        }
        else if (another_calc == "n" || another_calc == "no")
        {
            std::cout << "Bye\n";
            break;
        }
        else 
        {
            std::cout << "Invalid input. Please enter in yes or no\n";
            continue;
        }
    }
    std::cout << "================================\n";
    return 0;
}