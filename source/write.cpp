#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include "help.h"
#include "quit_r_w_c_func.h"
using namespace std;

void write_file_normal(int ,string ,string);

void edit(int level,string username)
{
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ifstream writetext;
    ifstream outtext;
    char answer;
    cin.ignore();
    string continuepath=".\\",directories,file,dire;
    do {
    directories:
    cout<<"Enter your directories name , *--h for help "<<endl;
    cout<<"$: ";
    fflush(stdin);
    getline(cin,directories);
     if(directories =="*--h")
    {
        writehelp(level);
         goto directories;
    }
        if(directories == "*esc")
    {
         quit();
    }
    if(directories == "*dir" || directories == "*ls")
    {
        system("CLS");
        string dir= "dir "+ continuepath;
        system(dir.c_str());
        goto directories;
    }
     if (directories =="")
    {
        continuepath= continuepath+directories;
    }
     else
     {
        continuepath= continuepath+directories+"\\";
     }
      string systems= "chdir "+continuepath;
        if( int(system(systems.c_str()))== 1)
        {
            return ;
        }
    top:
    cout<<"\n\nYour current path ";
     SetConsoleTextAttribute(hConsole, 9);
    cout<<continuepath<<endl;
    SetConsoleTextAttribute(hConsole, 7);
    cout<<"Do you want to continue browse deeper files or stop at this directories \n"<<endl;
    cout<<"(C)ontinue browser deeper to continue , (S)top at this directories  , (L)ist the directories "<<endl;
    cout<<"Your answer ->";
    cin>>answer;
      if(answer =='l' ||answer=='L')
    {
        system("CLS");
        string dire = "dir " + continuepath;
        system(dire.c_str());
        goto top;
    }
    if(answer =='S' ||answer=='s')
    {
        break;
    }
    if(answer =='c' ||answer=='C')
    {
        goto directories;
        break;
    }
    system("CLS");
    if(answer != 'S' || answer != 's' || answer != 'L'|| answer != 'l')
    {
         system("CLS");
        goto top;
    }
        }while(answer =='c' || answer =='C');










    file:
    cout<<"Enter file name , *--h for help"<<endl;
    cout<<"$: ";
    fflush(stdin);
    getline(cin,file);
 if(file =="*--h")
    {
        writehelp(level);
         goto file;
    }
      if(file=="*esc")
    {
        //quit();
        return;
    }
         if(file=="*ls" || file=="*dir")
    {
        string temp;
        temp="dir "+continuepath;
        system(temp.c_str());
        goto file;
    }
    continuepath=continuepath+file+".txt";
    cout<<"The path is ";
    SetConsoleTextAttribute(hConsole, 9);
    cout<<continuepath<<endl;
         SetConsoleTextAttribute(hConsole, 7);
    writetext.open(continuepath.c_str());
    outtext.open(".\\fileslevel\\filestore.txt",ios::app);
    string direct,lvl;
    int ss;
    for (int i=0;i<continuepath.length();i++)
    {
    continuepath[i]=tolower(continuepath[i]);
    }
    while(!outtext.eof())
    {
        getline(outtext,direct,':');
        getline(outtext,lvl);
        istringstream inputs(lvl);
        inputs>>ss;
        if(writetext.fail())
                {
                cout<<"File is not found ."<<endl;
                return ;
                }
        if (continuepath == direct)
        {
            if( (level==0 && ss==2 ) || (level ==1 && ss!=1) || (level==0 && ss==1 ) )
                {
             cout<<"No permission to read the files"<<endl;
             return;
                }
            else
            {
                if(writetext.fail())
                {
                cout<<"Not found , REPORT to administrator immediate files got deleted !!!! "<<endl;
                return ;
                }
                else
                {
                write_file_normal(level, username,continuepath);
                continuepath="notepad "+continuepath;
                system(continuepath.c_str());
                }
            }
        }
    }
}

