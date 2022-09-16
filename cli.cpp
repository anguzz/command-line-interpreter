

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
    printf("iPhone stimulator\n");
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
        else
        {
            cout << "Invalid command, input from command list." << endl;
        }

    }
}
void prompt()
{

    string command = "";
    cout << " \n Welome to my shell!\n\n";

    cout << " Windows commands\n";
    cout << " ----------\n";
    cout << " |dir     |\n";
    cout << " |help    |\n";
    cout << " |vol     |\n";
    cout << " |path    |\n";
    cout << " |tasklist|\n";
    cout << " |notepad |\n";
    cout << " |echo    |\n";
    cout << " |color   |\n";
    cout << " |ping    |\n";
    cout << " |exit    |\n";
    cout << " ---------\n";
}

int main()
{

    detectWindows();
    detectApple();
    prompt();
    shell();

}


