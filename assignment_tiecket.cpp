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

    if (checkNumber[0] == '0' || number < 10 /*a_b: a != 0*/|| (number > 189 && number <= 1000) /*ab_c: ab <= 18*/|| number > 1818 /*ab_cd: ab, cd <= 18*/)
    {
        std::cout << X;
        return 0;
    }

    int numberOne, numberTwo; // check digits

    switch (std::to_string(number).size())
    {
    case 2:
        // a_b: (a != 0) + (a > b) ==> (a)_00 or (b)_0a
        numberOne = number / 10;
        numberTwo = number % 10;

        if (numberOne >= numberTwo)
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
        // a_bc: (a > bc) dung khi b = 0 ==> LOAI: do khong ton tai 2 so nao cong lai co dang 0_K
        // ab_c: (c <= 9 < ab <= 18) ==> (100 <= ab_c <= 189) and (ab)_00 or (c)_(ab)
        numberOne = number / 10;
        numberTwo = number % 10;

        convert(numberOne);
        if (numberTwo != 0)
        {
            convert(numberTwo);
            std::swap(numberOne, numberTwo);
        }

        X = combine(numberOne, numberTwo);
        break;
    case 4:
        // ab_cd: (9 < ab <= 18, cd <= 18) + (9 < cd) + (ab >= cd) ==> (cd)_(ab)
        numberOne = number / 100;
        numberTwo = number % 100;

        if (!(numberTwo > 9)) // do khong ton tai 2 so nao cong lai co dang 0_K
        {
            break;
        }
        if (numberOne >= numberTwo)
        {
            convert(numberOne);
            convert(numberTwo);

            X = combine(numberTwo, numberOne);
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