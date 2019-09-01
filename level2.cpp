#include <iostream>
#include "level2.h"
#include <cstdlib>
#include <windows.h> // WinApi header
#include <errno.h>
#include "read_function.h"
#include "filelevel.h"
#include "list.h"
#include "case_c.h"
#include "case_exit.h"
#include "main.h"
#include "god_power.h"
#include "storelog.h"
#include "launch_exit.h"
using namespace std;

void MASTER(string,string);
void maliciousgroup(string,string,string);
void case_c(int currentuserlevel,string filename);
void read(int currentuserlevel,string username);
void displaylevel(int currentuserlevel);
bool verifyblacklist(string);



int level2(string username , string userdescription ,string group)
{
int currentuserlevel=2;
char command;
string filename,string_fot,console,dump;
filename = "\home\\"+username+"\\";
cout<<"Your menu"<<endl;
cout<<"You enjoying Read privilege ."<<endl;
menu:

cout<<"(C)reate, (R)ead, (L)ist , (S)wapAccount ";
if(int(group.compare("500"))==0)
{
    cout<<", (G)roup Menu ";
}
cout<<"or (E)xit."<<endl;
cout<<endl;

if(userdescription == "")
{
 int k = 10;
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, k);
cout<<username<<"@"<<username<<":~$ ";
console=username+"@"+username+":~";


}
else
{
 int k = 10;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, k);
cout<<username<<"@"<<userdescription<<":~$ ";
console = username+"@"+userdescription+":~";

}
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 7);

SetConsoleTitle(console.c_str());
cin>>string_fot;
  minuss:
        if(string_fot.length()!=1)
        {
        string_fot.erase(string_fot.length()-1);
        goto minuss;
        }

   cout<<string_fot<<endl;
command=string_fot[0];
switch(command)
{
case 'c':
case 'C':
  case_c(currentuserlevel,filename);
    goto menu;

case 'R':
case 'r':
    read(currentuserlevel,username);
    goto menu;


case 'l':
case 'L':
    displaylevel(currentuserlevel);
    goto menu;
    break;

case 'g':
case 'G':
       if(int(group.compare("1000"))==0)
        {
            cout<<"Invalid selection"<<endl;
            maliciousgroup(username,dump,group);
            goto menu;
            break;
        }
        else
        {
                if(verifyblacklist(username))
                {dump = to_string(currentuserlevel);
                MASTER(username,dump);
                goto menu;
                break;
                }
                else{
                    system("CLS");
                    cout<<"You have been banned by the system , contact root or group 500 user to unblock for you "<<endl;
                    goto menu;
                    break;
                }
        }


    case'S':
    case's':
    system("CLS");
    SetConsoleTitle("Terminal >");
    cin.ignore();
    enter();       ///in main();

    default :
    //system("CLS");
    cout<<"Invalid selection"<<endl;
    goto menu;
    break;


case 'E':
case 'e':

    case_exit();

    goto menu;
}



return 0;
}


