#include <bits/stdc++.h>

using namespace std;
//GLOBAL VARIABLE:
struct Process {
    int Block_Size = 0, Process_Size = 0, Num_Block = -1, Real_Block_Size = 0, Ind = 0;
};
int Num_Process, Num_Block;
Process* Arr;

//INPUT:
void Get_Block_Size() {
    cout << "Enter Size Of Blocks :\n";
    for (int i = 0; i < Num_Block; i++) {
        cout << "Block [" << i + 1 << "] = ";
        cin >> Arr[i].Block_Size, Arr[i].Real_Block_Size = Arr[i].Block_Size;
    }
    cout << endl;
}

void Get_Process_Size() {
    cout << "Enter Size of Processes :\n";
    for (int i = 0; i < Num_Process; i++) {
        cout << "Process [" << i + 1 << "] = ";
        cin >> Arr[i].Process_Size;
    }
}

//PROCESS:
void Calc_Process() {
    for (int i = 0; i < Num_Process; i++)
        for (int j = 0; j < Num_Block; j++)
            if (Arr[i].Process_Size <= Arr[j].Block_Size) {
                Arr[i].Num_Block = j + 1, Arr[j].Block_Size -= Arr[i].Process_Size, Arr[i].Ind = j;
                break;
            }
}

//OUTPUT:
void Print_Process() {
    cout << "\nProcess No.\tProcess Size\tBlock No\tBlock_Size\tFragment.\n";
    for (int i = 0; i < Num_Process; i++) {
        cout << " " << i + 1 << "\t\t" << Arr[i].Process_Size << "\t\t";
        if (Arr[i].Num_Block != -1)
            cout << Arr[i].Num_Block << "\t\t" << Arr[Arr[i].Ind].Real_Block_Size << "\t\t" << Arr[Arr[i].Ind].Block_Size << '\n';

        else
            cout << "Not Allocated \n";

    }
}


int main() {

    cout << "Enter Number Of Blocks:  ";
    cin >> Num_Block;
    cout << "Enter Number Of Processes:  ";
    cin >> Num_Process;
    Arr = new Process[Num_Block];

    Get_Block_Size();
    Get_Process_Size();
    Calc_Process();
    Print_Process();

}
