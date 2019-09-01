#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "help.h"
#include "quit_r_w_c_func.h"
using namespace std;
void read_file_normal(int ,string ,string);
void read(int level,string username)
{
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char answer,answer2;
    string string_fot2;
    string continuepath=".\\";
    ifstream shadowread,checkfilelevel;
    cout<<"If the files is not in a folder just enter no space is require"<<endl;
    do {
            here:
        cin.ignore();
        directories:
        cout<<"Enter your directories name ,*--h for help "<<endl;
        cout<<"$: ";
        string directories,directories1="";
       getline(cin,directories);
        if (directories == "*root*")
        {
            directories="";
        }
        if(directories == "*--h")
    {
        readhelp(level);
         goto directories;
    }
         if(directories =="*esc" )
    {
    return ;
    }
     if(directories =="*pwd" || directories =="*pwd")
    {
        system("CLS");
        cout<<"your current path";
        SetConsoleTextAttribute(hConsole, 9);
        cout<<continuepath<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        goto directories;
    }
    if(directories =="*dir" || directories =="*ls")
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
        continuepath= continuepath+directories+"\\";
        string systems= "chdir "+continuepath;
        if( int(system(systems.c_str()))== 1)
        {
            return ;
        }
        system("CLS");
        loops:
    cout<<"You currently in this path -> ";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    cout<< continuepath <<endl;
    SetConsoleTextAttribute(hConsole, 7);
    cout<<"\n(S)top at this directories  or (C)ontinue browser deeper or (L)ist the directories "<<endl;
    cout<<"Your answer ->";
    cin>>string_fot2;
                filter4:
        if(string_fot2.length()!= 1)
        {
                string_fot2.erase(string_fot2.length()-1);
                goto filter4;
        }
           if(string_fot2.length()==1)
               {
            answer=string_fot2[0];
               }
    if(answer =='L' || answer=='l')
    {
        system("CLS");
        string dir="dir "+continuepath;
        system(dir.c_str());
        goto loops;
    }
    if(answer =='S' || answer=='s')
    {
        break;
    }
    if(answer == 'C' || answer == 'c' )
        goto here;
       if(answer != 'S' || answer != 's' || answer != 'L'|| answer != 'l' || answer !='c' || answer !='C')
    {
            //system("CLS");
            goto loops;
    }

    }while(answer =='c' || answer =='C');

//    string dire=directories;
 //   directories=".\\"+directories+"\\";

////////////////files

    file:
    string file;
    cout<<"Enter file name , *--h for help "<<endl;

    cout<<"your current path";
    SetConsoleTextAttribute(hConsole, 9);
    cout<<continuepath<<endl;
    SetConsoleTextAttribute(hConsole, 7);
    cout<<"$: ";
    fflush(stdin);
    getline(cin,file);
  if(file =="*--h")
    {
        readhelp(level);
         goto file;
    }
             if(file =="*esc" )
    {
        quit();
    }
       if(file=="*ls" || file=="*dir")
    {
        string temp;
        temp="dir "+continuepath;
        system(temp.c_str());
        goto file;
    }
    continuepath=continuepath+file+".txt";
    cout<<"the path is";

     SetConsoleTextAttribute(hConsole, 9);
    cout<<continuepath<<endl;
    SetConsoleTextAttribute(hConsole, 7);
    shadowread.open(continuepath.c_str());
    string data;

checkfilelevel.open(".\\fileslevel\\filestore.txt",ios::app);
string path,lvl;
int ss;
for (int i=0;i<continuepath.length();i++)
{
continuepath[i]=tolower(continuepath[i]);
}
    while(!checkfilelevel.eof())
    {
        getline(checkfilelevel,path,':');
        getline(checkfilelevel,lvl);
        istringstream inputs(lvl);
        inputs>>ss;
        if( path == continuepath )
        {
            if((ss ==1 && level==1) ||(ss==2 && level == 2))
               {
                    if(shadowread.fail())
                {
                    cout<<"File is not found"<<endl;
                    return ;
                }
                else
                    {
                    read_file_normal(level,username,continuepath);
                    cout<<"\n\n------------------------------------  Beginning of File  -------------------------------------\n\n"<<endl;
                    while(!shadowread.eof())
                {
                    getline(shadowread,data);
                    cout<<data<<endl;

                }
                    cout<<"\n------------------------------------  File End  ------------------------------------------------"<<endl;
                    return;
                    }
               }
               else
                {
                    system("CLS");
                    cout<<"WARNING **** File is there but you have no rights to view **** WARNING"<<endl;
                    return ;
                }
        }

    }cout<<"File is not found "<<endl;

}




