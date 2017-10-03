// preprocessor directives
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
//Declare Variables
const int OP_ADD = 0;
const int OP_SUB = 1;
const int OP_MUL = 2;
const int OP_DIV = 3;
const int OP_MOD = 4;
const int OP_EXP = 5;
double data0, data1, data2;
int inst;
//prompt user for inputs and acquire them
data1=0;
for(int i =3; i>0; i--)
{
    cout << endl << "Daily grade: ";
    cin >> inst;
    data1 += inst;
}
data1 = (data1/3)*0.4;
data2=0;
for(int i =2; i>0; i--)
{
    cout << endl << "Test grade: ";
    cin >> inst;
    data2 += inst;
}
data2 = (data2/2)*0.6;
inst = 0;
//out of range of operations
switch(inst)
{
    case 0: data0 = data1+data2;
    break;
    case 1: data0 = data1-data2;
    break;
    case 2: data0 = data1*data2;
    break;
    case 3: data0 = data1/data2;
    break;
    case 5: data0 = pow(data1,data2);
    break;
    default:
    cout << "Unable to preform operation." << endl;
    data0 = -1;
}
cout << "Calculation complete, " << data0 << " is your result." << endl;
//exit
return 0;
}
