#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int betFunc(int myMoney, int bet);
int getRolls(int compDie1, int userDie1);
int results(int compDie1, int userDie1, int myMoney, int bet);

int main()
{
    cout << "Gambling is an addiction..." << endl;
    char cont;
    int myMoney = 1000;
    int bet = 0;
    int compDie1;
    int userDie1;
    do
    {
        myMoney = betFunc(myMoney, bet);
        cout << "continue (Y or N)" << endl;
        cin >> cont;
    }
    while(myMoney > 0 && cont != 'N' || cont != 'n');
    return 0;
}

int betFunc(int myMoney, int bet)
{
    bool invalidity;
    do
    {
        cout << "You have $" << myMoney << ", how much would you like to bet?" << endl;
        cin >> bet;
        if(bet > myMoney || bet < 1)
        {
            cout << "Invalid Bet" << endl;
            invalidity = true;
        }
        else
        {
            invalidity = false;
        }
    }
    while(invalidity);
    int compDie1 = 0;
    int userDie1 = 0;
    userDie1= getRolls(compDie1, userDie1);
    compDie1= userDie1 / 10;
    userDie1= userDie1 - compDie1*10;
    cout << compDie1 << userDie1;
    myMoney = results(compDie1, userDie1, myMoney, bet);
    return myMoney;
}

int getRolls(int compDie1, int userDie1)
{
    srand(time(NULL));
    compDie1 = rand() % 6 + 1;
    userDie1 = rand() % 6 + 1;
    return compDie1*10+userDie1;
}

int results(int compDie1, int userDie1, int myMoney, int bet)
{
    if(compDie1 > userDie1)
    {
        cout << "Loss: You lost $" << bet << endl;
        myMoney -= bet;
    }
    else if(compDie1 == userDie1)
    {
        cout << "Draw: You kept your $" << bet << endl;
    }
    else if(compDie1 < userDie1)
    {
        cout << "Win: You won $" << bet << endl;
        myMoney += bet;
    }
    return myMoney;
}
