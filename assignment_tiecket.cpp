#include <iostream>
#include <string>

int combine(int numberOne, int numberTwo);
void convert(int &number);

int main()
{
    int number, X = 0;
    std::string checkNumber;

    std::getline(std::cin, checkNumber);
    number = std::stoi(checkNumber);

    if (checkNumber[0] == '0' || number > 1818 || number < 10)
    {
        std::cout << X;
        return 0;
    }

    int numberOne, numberTwo;
    int X1 = 10000, X2 = 10000; // check 3 digits

    switch (std::to_string(number).size())
    {
    case 2:
        // a_b: (a != 0) + (a > b) ==> (a)_00 or (b)_0a
        numberOne = number / 10;
        numberTwo = number % 10;

        if (numberOne > numberTwo)
        {
            if (numberTwo == 0)
            {
                std::swap(numberTwo, numberOne);
            }
            convert(numberTwo);

            X = combine(numberTwo, numberOne);
        }
        break;
    case 3:
        // a_bc: (a != 0) + (bc <  a <= 9) ==> (a)_00 or (c)_0a
        numberOne = number / 100;
        numberTwo = number % 100;

        if (numberOne > numberTwo)
        {
            if (numberTwo != 0)
            {
                std::swap(numberOne, numberTwo);
            }
            convert(numberOne);

            X1 = combine(numberOne, numberTwo);
        }
        // ab_c: (ab > 9, ab > c) + (ab <= 18) ==> (ab)_00 or (c)_(ab)
        numberOne = number / 10;
        numberTwo = number % 10;

        if (numberOne <= 18)
        {
            convert(numberOne);
            if (numberTwo != 0)
            {
                convert(numberTwo);
                std::swap(numberOne, numberTwo);
            }

            X2 = combine(numberOne, numberTwo);
        }

        if (X1 != 10000 || X2 != 10000)
        {
            X = (X1 < X2) ? X1 : X2;
        }
        break;
    case 4:
        // ab_cd: (ab > 9) + (ab <= 18, cd <= 18) + (ab > cd) ==> (ab)_00 or (cd)_(ab)
        numberOne = number / 100;
        numberTwo = number % 100;

        if (numberOne > numberTwo && numberOne <= 18)
        {
            convert(numberOne);
            if (numberTwo != 0)
            {
                convert(numberTwo);
                std::swap(numberOne, numberTwo);
            }

            X = combine(numberOne, numberTwo);
        }
    }

    std::cout << X;
    return 0;
}

int combine(int numberOne, int numberTwo)
{
    return numberOne * 100 + numberTwo;
}

void convert(int &number)
{
    if (number <= 9)
    {
        number = 10 + number - 1;
    }
    else // 9 < number <= 18
    {
        number = (number - 9) * 10 + 9;
    }
}