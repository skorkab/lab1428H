#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int Add(int var1, int var2);
int Sub(int var1, int var2);
int Mul(int var1, int var2);
int Div(int var1, int var2);
int Exp(int var1, int var2);
int Red();
int Wrt(int var1);
int Str(int var1);
int Jmp(int memory[256], int instruction[512][4], int i, int offset);
int Cjp(int cond1, int cond2, int memory[256], int instruction[512][4], int i, int offset);
int loadProgram(string filename, int program_memory[512][4]);
    int counter = 0;
int main()
{
	// Declare our variables
	const int OP_ADD = 0;
	const int OP_SUB = 1;
	const int OP_MUL = 2;
	const int OP_DIV = 3;
	const int OP_EXP = 4;
	const int OP_RED = 5;
	const int OP_WRT = 6;
	const int OP_STR = 7;
	const int OP_JMP = 8;
	const int OP_CJP = 9;
	int memory[256];
	int instruction[512][4]={0};
	int counter = 0;

	ifstream fin;
	fin.open("sumRange.txt");

	while(!(fin.eof())&&counter < 512)
	{
		fin >> instruction[counter][0] >> instruction[counter][1] >> instruction[counter][2] >> instruction[counter][3];
		counter ++;
	}


	for(int i=0; i<counter; i++)
	{

		switch(instruction[i][0])
		{
			case OP_ADD:
				memory[instruction[i][1]] = Add(memory[instruction[i][2]], memory[instruction[i][3]]);
				break;
			case OP_SUB:
				memory[instruction[i][1]] = Sub(memory[instruction[i][2]], memory[instruction[i][3]]);
				break;
			case OP_MUL:
				memory[instruction[i][1]] = Mul(memory[instruction[i][2]], memory[instruction[i][3]]);
				break;
			case OP_DIV:
				memory[instruction[i][1]] = Div(memory[instruction[i][2]], memory[instruction[i][3]]);
				break;
			case OP_EXP:
				memory[instruction[i][1]] = Exp(memory[instruction[i][2]], memory[instruction[i][3]]);
				break;
			case OP_RED:
				memory[instruction[i][1]] = Red();
				break;
			case OP_WRT:
				Wrt(memory[instruction[i][1]]);
				break;
			case OP_STR:
				memory[instruction[i][1]]= Str(instruction[i][2]);
				break;
			case OP_JMP:
				Jmp(memory, instruction, i, memory[instruction[i][1]]);
				break;
			case OP_CJP:
				Cjp(memory[instruction[i][2]], memory[instruction[i][3]], memory, instruction, i, memory[instruction[i][1]]);
				break;
		}
	}
	return 0;
}

int Add(int var1, int var2)
{
    return var1 + var2;
}

int Sub(int var1, int var2)
{
    return var1 - var2;
}

int Mul(int var1, int var2)
{
    return var1 * var2;
}

int Div(int var1, int var2)
{
    return var1 / var2;
}

int Exp(int var1, int var2)
{
    return pow(var1, var2);
}

int Red()
{
    cout << "Enter a number:";
    int input;
    cin >> input;
    return input;
}

int Wrt(int var1)
{
    cout << var1 << endl;
    return 0;
}

int Str(int var1)
{
    return var1;
}

int Jmp(int memory[256], int instruction[512][4], int i, int offset)
{
    if(i + offset > 512 || i + offset < 0)
    {
        cout << "Please use numbers that don't overflow next time. Operation canceled." << endl;
    }
    else
    {
        i += offset;
        switch(instruction[i][0])
        {
            case 0:
                memory[instruction[i][1]] = Add(memory[instruction[i][2]], memory[instruction[i][3]]);
                break;
            case 1:
                memory[instruction[i][1]] = Sub(memory[instruction[i][2]], memory[instruction[i][3]]);
                break;
            case 2:
                memory[instruction[i][1]] = Mul(memory[instruction[i][2]], memory[instruction[i][3]]);
                break;
            case 3:
                memory[instruction[i][1]] = Div(memory[instruction[i][2]], memory[instruction[i][3]]);
                break;
            case 4:
                memory[instruction[i][1]] = Exp(memory[instruction[i][2]], memory[instruction[i][3]]);
                break;
            case 5:
                memory[instruction[i][1]] = Red();
                break;
            case 6:
                Wrt(memory[instruction[i][1]]);
                break;
            case 7:
                memory[instruction[i][1]]= Str(instruction[i][2]);
                break;
            case 8:
                Jmp(memory, instruction, i, memory[instruction[i][1]]);
                break;
            case 9:
                Cjp(memory[instruction[i][2]], memory[instruction[i][3]], memory, instruction, i, memory[instruction[i][1]]);
				break;
        }
    }
    return 0;

}

int Cjp(int cond1, int cond2, int memory[256], int instruction[512][4], int i, int offset)
{
    if(cond1 == cond2)
    {
        Jmp(memory, instruction, i, memory[instruction[i][1]]);
    }
    return 0;
}
