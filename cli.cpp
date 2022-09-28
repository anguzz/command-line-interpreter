
#include <iostream>
#include <windows.h>
#include <string.h>

//Angel Santoyo
//Github:Angus-1
using namespace std;

const int LEN = 100;
char cmd[LEN];


DWORD WINAPI exec(LPVOID lpParamter)
{
    system(cmd);
    return 0;
}

void detectWindows()
{
#ifdef _WIN32 // Includes both 32 bit and 64 bit
#ifdef _WIN64
    printf("Windows 64 bit\n");
#else 
    printf("Windows 32 bit\n");
#endif
#else
    printf("Not a Windows OS\n");
#endif

}

void detectApple()
{
#if __APPLE__
#include "TargetConditionals.h"
#if TARGET_OS_IPHONE && TARGET_IPHONE_SIMULATOR
    printf("iPhone simulator\n");
#elif TARGET_OS_IPHONE
    printf("iPhone\n");
#elif TARGET_OS_MAC
    printf("MacOS\n");
#else
    printf("Other Apple OS\n");
#endif
#else
    printf("Not an Apple OS\n");
#endif
}



int shell()
{
    while (1)
    {
        cout << ">> ";
        cin.getline(cmd, LEN);
        size_t pos = string(cmd).find(" ");

        if (string(cmd) == "dir" || string(cmd) == "help" || string(cmd) == "vol" || string(cmd) == "path" || string(cmd) == "tasklist" || string(cmd) == "notepad")
        {
            HANDLE hThread = CreateThread(NULL, 0, exec, NULL, 0, NULL);
            WaitForSingleObject(hThread, INFINITE);
            CloseHandle(hThread);
        }
        else if (string(cmd).substr(0, pos) == "echo" || string(cmd).substr(0, pos) == "ping" || string(cmd).substr(0, pos) == "color")
        {
            HANDLE hThread = CreateThread(NULL, 0, exec, NULL, 0, NULL);
            WaitForSingleObject(hThread, INFINITE);
            CloseHandle(hThread);
        }
        else if (string(cmd) == "exit" || string(cmd) == "quit")
        {
            cout << "Thanks for using my shell!\n";
            return 0;
        }
        else if (string(cmd) == "color-table")
        {
            cout << "Syntax is  color <b><f> where  <b> is background and  <f> is foreground\n"; 
            cout << "color table list\n";
            cout << " ----------------------------\n";
            cout << " |0          Black          |\n";
            cout << " |1          Blue           |\n";
            cout << " |2          Green          |\n";
            cout << " |3          Aqua           |\n";
            cout << " |4          Red            |\n";
            cout << " |5          Purple         |\n";
            cout << " |6          Yellow         |\n";
            cout << " |7          White          |\n";
            cout << " |8          Gray           |\n";
            cout << " |9          Light blue     |\n";
            cout << " |a          Light green    |\n";
            cout << " |b          Light aqua     |\n";
            cout << " |c          Light red      |\n";
            cout << " |d          Light yellow   |\n";
            cout << " |e          Light purple   |\n";
            cout << " |f          Bright white   |\n";
            cout << " ----------------------------\n";
        }
        else
        {
            cout << "Invalid command, input from command list." << endl;
        }

    }
}
void prompt()
{
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << " \n Welome to my shell!\n\n";

    cout << " Windows commands\n";
    cout << " ------------\n";
    cout << " |dir        |\n";
    cout << " |help       |\n";
    cout << " |vol        |\n";
    cout << " |path       |\n";
    cout << " |tasklist   |\n";
    cout << " |notepad    |\n";
    cout << " |echo       |\n";
    cout << " |color      |\n";
    cout << " |color-table|\n";
    cout << " |ping       |\n";
    cout << " |exit       |\n";
    cout << " -----------\n";

}

int main()
{

    detectWindows();
    detectApple();
    prompt();
    shell();

}


