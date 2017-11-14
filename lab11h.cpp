#include <iostream>

using namespace std;
int sumNumbers(int val);

int main()
{
    int x;
    cout << "Input Value: ";
    cin >> x;
    cout << sumNumbers(x);
	return 0;
}

int sumNumbers(int val)
{
    if (val < 0)
    {
        cout << "Invalid Input." << endl;
        return -1;
    }
    else if (val == 0)
    {
        return val;
    }
    else
    {
        val += sumNumbers(val - 1);
        return val;
    }
}

