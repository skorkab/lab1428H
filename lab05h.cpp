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
int inst, data0, data1, data2;
char exit;
//loop to allow multiple calculations
while(true)
{
    //prompt user for inputs and acquire them
    cout << "What operation do you wish to preform?" << endl;
    cin >> inst;
    cout << "What is the first value?" << endl;
    cin >> data1;
    cout << "What is the second value?" << endl;
    cin >> data2;
        //addition
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
        case 4: data0 = data1%data2;
        break;
        case 5: data0 = pow(data1,data2);
        break;
        default:
        cout << "Unable to preform operation." << endl;
        data0 = -1;
    }
    //print result and offer to end/continue
    cout << "Calculation complete, " << data0 << " is your result. Press f to cancel, or any other character to continue." << endl;
    cin >> exit;
    //end if they want to end
    if(exit == 'f'||exit == 'F')
    {
        break;
    }
    //return to top of while loop to allow multiple calculations
}


    //exit
return 0;
}
