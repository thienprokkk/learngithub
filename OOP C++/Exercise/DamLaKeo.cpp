/*
intro
player choose
computer random
so sánh 2 lựa chọn của player và computer
bo sung them so luoc choi
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

class DamLaKeo
{
private:
    string player, computer, result;
    int round;

public:
    friend void runGame(DamLaKeo myGame);
    void introGame();
    void setResult();
    friend istream &operator>>(istream &input, DamLaKeo &player);
    friend ostream &operator<<(ostream &ouput, DamLaKeo player);
    void setRound(int round) { this->round = round; }
};

int main()
{
    DamLaKeo myGame;
    // start game
    myGame.introGame();

    // C1: chơi một lần
    cin >> myGame;
    myGame.setResult();
    cout << myGame;

    // C2: chơi nhiều lần
    myGame.setRound(5);
    runGame(myGame);
}

void DamLaKeo::introGame()
{
    cout << "Game Dam La Keo !!\n";
    cout << setfill('-') << setw(50) << '-' << "\n";
    cout << "Dam-La-Keo !!!\n\n";
}

void runGame(DamLaKeo myGame)
{
    for (int i = 1; i <= myGame.round; i++)
    {
        cout << "\tRound " << i << "\n";
        cin >> myGame;
        myGame.setResult();
        cout << myGame;
    }
}

void DamLaKeo::setResult()
{
    if (player == computer)
    {
        result = "Draw";
        return;
    }
    switch (player[0])
    {
    case 'D':
        result = (computer == "Keo") ? "win" : "close";
        break;
    case 'L':
        result = (computer == "Dam") ? "win" : "close";
        break;
    case 'K':
        result = (computer == "La") ? "win" : "close";
    }
}

istream &operator>>(istream &input, DamLaKeo &myGame)
{
    cout << "Please enter your choice: ";
    // player choose
    input >> myGame.player;
    myGame.player[0] = toupper(myGame.player[0]);
    // check player
    while (myGame.player != "Dam" && myGame.player != "La" && myGame.player != "Keo")
    {
        cout << "\tEnter again: ";
        input >> myGame.player;
        myGame.player[0] = toupper(myGame.player[0]);
    }
    // computer choose
    srand(time(nullptr));
    switch (rand() % 3)
    {
    case 0:
        myGame.computer = "Dam";
        break;
    case 1:
        myGame.computer = "La";
        break;
    case 2:
        myGame.computer = "Keo";
    }
    return input;
}

ostream &operator<<(ostream &output, DamLaKeo myGame)
{
    output << setfill('_') << setw(30) << "_" << "\n";
    // print chooses
    output << "You choose:\t\t" << myGame.player << "\n";
    output << "Computer choose:\t" << myGame.computer << "\n";
    output << setfill('_') << setw(30) << "_" << "\n";
    // print result
    if (myGame.result != "Draw")
    {
        output << "You ";
    }
    output << myGame.result << "\n\n";
    return output;
}