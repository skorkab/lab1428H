// preprocessor directives
#include <iostream>
#include <cmath>
#include <fstream>
#include <istream>
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
int ram[256];
int ops;
int inst[512];
int data0[512];
int data1[512];
int data2[512];
int index;
//loop to allow multiple calculations
ifstream fin;
fin.open("AssemblyCommands.txt");
if( !fin )
{
    cout << "Error- File Failed to open." << endl;
}
fin >> ops;
while(true)
{
    //prompt user for inputs and acquire them
    for(int i = 0; i < ops; i++)
    {
    fin >> inst[i] >> data0[i] >> data1[i] >> data2[i];
    }
    for(int i = 0; i < ops; i++)
    {
        index = data0[i];
        switch(inst[i])
        {
            case 0: ram[index] = data1[i]+data2[i];
            break;
            case 1: ram[index] = data1[i]-data2[i];
            break;
            case 2: ram[index] = data1[i]*data2[i];
            break;
            case 3: ram[index] = data1[i]/data2[i];
            break;
            case 4: ram[index] = data1[i]%data2[i];
            break;
            case 5: ram[index] = data1[i];
            break;
            case 6: cout << ram[index];
            break;
            default:
            cout << "Unable to preform operation." << endl;
            ram[index] = -1;
        }
    }


    //exit
    return 0;
    }
}
