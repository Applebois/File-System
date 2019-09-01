#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;


void registration()
{
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
       cout<<"----------------------------------------------------------------------------------------\n"<<endl;
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"\tCommands  \t\t\t ";
            SetConsoleTextAttribute(hConsole, 7 );
            cout<<"Details of commands\n"<<endl;
            SetConsoleTextAttribute(hConsole,11 );
            SetConsoleTextAttribute(hConsole, 11);
            cout<<"\tesc";
            SetConsoleTextAttribute(hConsole, 7 );
            cout<<"\t\t\t\tQuit the registration  "<<endl;
            cout<<"\tReminder \t\t\tPassword minimum requirement >=4 character lengths and symbol ! # ' = - , are not allowed . \n"<<endl;
            cout<<"-----------------------------------------------------------------------------------------"<<endl;
}

void filesystem()
{
   cout<<"----------------------------------------------------------------------------------------\n"<<endl;
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"\tCommands  \t\t\t ";
            SetConsoleTextAttribute(hConsole, 7 );
            cout<<"Details of commands\n"<<endl;
            SetConsoleTextAttribute(hConsole,11 );
            cout<<"\tFileSystem -i";
            SetConsoleTextAttribute(hConsole, 7 );
            cout<<" \t\t\t To register your account using this syntax \n"<<endl;
            SetConsoleTextAttribute(hConsole, 11 );
            cout<<"\tFileSystem    ";
            SetConsoleTextAttribute(hConsole, 7 );
            cout<<"\t\t\t To log in your account using this syntax \n"<<endl;
            cout<<"-----------------------------------------------------------------------------------------"<<endl;
}

void readhelp(int level)
{
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<"\n----------------------------------Helps----------------------------------------------------------------------"<<endl;
    cout<<"\n\n\t";
    SetConsoleTextAttribute(hConsole,11);
    cout<<"*ls || *dir";
    SetConsoleTextAttribute(hConsole,7);
    cout<<"\t\t\t\t \t\t\t\tView current files in the directories"<<endl;
    SetConsoleTextAttribute(hConsole,11);
    cout<<"\n\t";cout<<"*esc";
    SetConsoleTextAttribute(hConsole,7);
    cout<<"  \t\t\t\t \t\t\t\t\tQuit this menu back to homepage "<<endl;
    cout<<"\n\t";
    SetConsoleTextAttribute(hConsole,11);
    cout<<"*root*";
    SetConsoleTextAttribute(hConsole, 7 );
    cout<<"\t\t\t\t \t\t\t\tPoint to current location , let say the text file does not have folder "<<endl;
    if (level==1)
    cout<<"\n\t\"Read file only able to read files level '1' \t\t\t\t eg  .\\fileslevel\\filestore.txt (not able to view)\n\t\t\t\t\t \t\t\t\t\t .\\etc\\salt.txt (not able to view)"<<endl;
    else
        cout<<"\n\t\"Read file only able to read files level '2' \t\t\t\t eg  .\\etc\\passwd.txt (able to view)"<<endl;
    cout<<"\n\n----------------------------End of Helps----------------------------------------------------------------------"<<endl;
}

void writehelp(int level)
{
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        cout<<"\n----------------------------------Helps----------------------------------------------------------------------"<<endl;
        cout<<"\n\t";
        SetConsoleTextAttribute(hConsole, 11);
        cout<<"*ls || *dir ";
        SetConsoleTextAttribute(hConsole, 7 );
        cout<<"\t\t\t\t \t\t\t\tView current files in the directories"<<endl;
         cout<<"\n\t";
        SetConsoleTextAttribute(hConsole, 11);
         cout<<"*esc";
        SetConsoleTextAttribute(hConsole, 7 );
         cout<<"\t\t\t\t\t\t\t\t\tQuit this menu back to homepage "<<endl;
        if(level == 1)
            cout<<"\n\t\"File editing only able to write/view files security level with '1'\"\t eg  .\\etc\\passwd.txt & .\\etc\\shadow.txt (not able to edit or view)"<<endl;
        else
            cout<<"\n\t\"File editing only able to edit files security level with '0'\"\t eg  .\\etc\\shadow.txt (able to edit)"<<endl;
        cout<<"\n\n----------------------------End of Helps----------------------------------------------------------------------"<<endl;
}

void create_text()
{
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            cout<<"\n----------------------------------Helps----------------------------------------------------------------------"<<endl;
        cout<<"\n\t";
          SetConsoleTextAttribute(hConsole,11);
        cout<<"*ls || *dir";
          SetConsoleTextAttribute(hConsole, 7 );
        cout<<" \t\t\t\t \t\t\t\tView current files in the directories"<<endl;
        cout<<"\n\t";
        SetConsoleTextAttribute(hConsole, 11);
         cout<<"*esc";
        SetConsoleTextAttribute(hConsole, 7 );
         cout<<"\t\t\t\t\t\t\t\t\tQuit this menu back to homepage "<<endl;
        cout<<"\n\n----------------------------End of Helps----------------------------------------------------------------------"<<endl;
}

void selection_for_text()
{
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        cout<<"\n----------------------------------Helps----------------------------------------------------------------------"<<endl;
        cout<<"\n\t";
        SetConsoleTextAttribute(hConsole, 11);
        cout<<"Y || y ";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t\t\t\t \t\t\t\tYes"<<endl;
        cout<<"\n\t";
        SetConsoleTextAttribute(hConsole, 11);
        cout<<"   ?   ";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t\t\t\t \t\t\t\tHelp"<<endl;
         cout<<"\n\t";
         SetConsoleTextAttribute(hConsole, 11);
         cout<<"E || e ";
         SetConsoleTextAttribute(hConsole, 7);
         cout<<"\t\t\t\t \t\t\t\tQuit this menu back to homepage "<<endl;


        cout<<"\n\n----------------------------End of Helps----------------------------------------------------------------------"<<endl;
}
