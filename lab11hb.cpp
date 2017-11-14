#include <iostream>

using namespace std;

int Fibb(int i, int j, int recurr);
int Fibb (int recurr);

int x;
int main()
{
    cout << "Input Value: ";
    cin >> x;
    Fibb(x);
	return 0;
}

int Fibb(int recurr)
{
    if (recurr < 0)
    {
        cout << "Invalid Input." << endl;
        return -1;
    }
    else if (recurr == 0)
    {
        return recurr;
    }
    else if(recurr == x)
    {
        cout << "fib " << x - recurr << " : 0" << endl;
        Fibb(recurr-1);
        return recurr;
    }
    else if(recurr == x-1)
    {
        cout << "fib " << x - recurr << " : 1" << endl;
        Fibb(0,1,recurr-1);
        return recurr;
    }
    else
    {
        cout << "fib " << x - recurr << " : 0" << endl;
        Fibb(recurr-1);
        return recurr;
    }
}

int Fibb(int i, int j, int recurr)
{
    if (recurr < 0)
    {
        cout << "Invalid Input." << endl;
        return -1;
    }
    else if (recurr == 0)
    {
        return recurr;
    }
    else if(recurr == x)
    {
        cout << "fib " << x - recurr << " : 0" << endl;
        Fibb(recurr-1);
        return recurr;
    }
    else if(recurr == x-1)
    {
        cout << "fib " << x - recurr << " : 1" << endl;
        Fibb(recurr-1);
        return recurr;
    }
    else
    {
        cout << "fib " << x - recurr << " : " << i+j << endl;
        Fibb(j, i+j, recurr-1);
        return recurr;
    }
}
