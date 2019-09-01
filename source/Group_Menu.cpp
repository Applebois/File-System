#include <iostream>
#include "god_power.h"
#include <fstream>
#include "storelog.h"
#include "help.h"
#include <windows.h>
#include <sstream>
#include "UploadLog.h"

using namespace std;
void UploadLogTOFTP();
string usernames;
void successful_login(string,string);
void failed_to_enter_password(string ,string );
void successful_logout(string);
void menu();
void god_read(string);
void god_write(string);
int blacklist(string);
void removeBlackList();
void Unbanned_Group_User(string,string);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string globaluser;

void MASTER(string user, string userlevel)
{
    char choice;
    string string_fot2,dump,dump2;
    usernames=user;
    system("CLS");
    ofstream outfile (".\\Logs\\logs.txt",ios::app);
    int counter=0;
    string password;
   /*cout<<" Enter (P)assword or(F)iles to verify you "<<endl;
    cin>>string_fot2;
           filter:
        if(string_fot2.length()==1)
        {
        choice=string_fot2[0];
        }
        if(string_fot2.length()!= 1)
        {
        string_fot2.erase(string_fot2.length()-1);
        goto filter;
        }
        if(choice=='P' || choice =='p')
       {
             cout<<"Enter THE SECRET to proceed"<<endl;
    here:
    if (counter != 0)

    cout<<"Password Incorrect!\nRe-enter your password . "<<endl;
    cin>>password;

    if(password.compare("12345")==1)
    {
        counter ++;
        if(counter == 4)
        {
        failed_to_enter_password(user,userlevel);///logs
        system("pause");
        exit(0);
        }
        goto here;
    }
    if(password.compare("12345")==0)
    {
        successful_login(user,userlevel); ///logs
        menu();
        successful_logout(user);///logs
    }
       }

       if(choice == 'F' || choice =='f')
       {
         */
         top:
             ifstream md5file;
            md5file.open("etc\\md5verify.config");
            if(!md5file.good())
            {
                system("echo 103120f58dc84267baca0c11ae8a7db9>etc\\md5verify.config");
                goto top;
            }
            getline(md5file,dump2);
            cout<<"Enter the files name , please include the files extension "<<endl;
            cout<<"Please to include this file -> ""fciv.exe"" md5:e2c6d562bd35352b73c00a744e9c07c6   || SHA-1: F5259423EB42664DEC7A32BA6A7CF0D85D13E752"<<endl;
            cin>>password;
            password = "fciv.exe " + password +" -md5 >validating.txt";
            system(password.c_str());
            ifstream opens;
            opens.open("validating.txt",ios::app);
            getline(opens,dump);
            getline(opens,dump);
            getline(opens,dump);
            getline(opens,dump,' ');
            if(int(dump.compare(dump2) == 0))
            {
            opens.close();
            password = "del /f validating.txt";
            system(password.c_str());
            system("CLS");
            cout<<"Validating";Sleep(500);cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"."<<endl;
            successful_login(user,userlevel); ///logs
            globaluser=user;
            menu();
            successful_logout(user);///logs
            }
            else
            {
                opens.close();
                password = "del /f validating.txt";
                system(password.c_str());
                cout<<"Failed to authenticate "<<endl;
                counter ++;
                cout<<"Please enter your files to authenticate again "<<endl;
                    if(counter<3)
                    {
                        goto top;
                    }
                    if(counter>=3)
                    {
                    failed_to_authenticate(user,userlevel);
                    blacklist(user);
                    cout<<"Your group level 500 account have been locked , Error \"10352\" "<<endl;
                    }
            }
      // }
    return ;

}

void menu()
{
    string string_fot2="";
    char choice;
    menus:
    cout<<"(W)rite, (R)ead , (U)pload Logs through F T P ,un(B)anned Users , (E)xit"<<endl;
    cin>>string_fot2;
           filter:
        if(string_fot2.length()==1)
        {
        choice=string_fot2[0];

        }
        if(string_fot2.length()!= 1)
        {
        string_fot2.erase(string_fot2.length()-1);
        goto filter;
        }
      switch(choice)
      {
    case'r':
    case'R':
        god_read(usernames);
        goto menus;
        break;
    case 'W':
    case 'w':
        god_write(usernames);
        goto menus;
        break;
    case 'u':
    case 'U':
        UploadLogTOFTP();
        goto menus;
        break;
    case'b':
    case'B':
        removeBlackList();
        goto menus;
        break;
    case 'E':
    case 'e':
    break;
    default:cout<<"Invalid Choice"<<endl;
    break;
      }
}

void god_read(string usernames)
{

    char answer;
    string string_fot2;
    string continuepath=".\\";
    ifstream shadowread,checkfilelevel;
    cout<<"If the files is not in a folder just enter no space is require"<<endl;
    do {
        here:
        cin.ignore();
        directories:
        cout<<"Enter your directories name ,*h for help "<<endl;
        cout<<"$: ";
        string directories,directories1="";
       getline(cin,directories);
        if (directories == "*root*")
        {
            directories="";
        }
        if(directories == "*h")
        {
        SetConsoleTextAttribute(hConsole, 11);
        cout<<"*esc";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<" to exit , ";
        SetConsoleTextAttribute(hConsole, 11);
        cout<<"*ls or *dir ";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"to view your directories files , ";
        SetConsoleTextAttribute(hConsole, 11);
        cout<<"*pwd ";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"to view your current path"<<endl;
        goto directories;
    }
         if(directories =="*esc" )
    {
    return ;
    }
     if(directories =="*pwd")
    {
        system("CLS");
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
            menu();
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
    if(answer == 'c' || answer == 'c' )
        goto here;
       if(answer != 'S' || answer != 's' || answer != 'L'|| answer != 'l' || answer !='c' || answer !='C')
    {

            goto loops;
    }

    }while(answer =='c' || answer =='C');



    file:
    string file;
    cout<<"your current path";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    cout<<continuepath<<endl;
    SetConsoleTextAttribute(hConsole, 11);
    cout<<"*esc";
    SetConsoleTextAttribute(hConsole, 7);
    cout<<" to exit ,";
    SetConsoleTextAttribute(hConsole,11);
    cout<<" *ls or *dir ";
    SetConsoleTextAttribute(hConsole, 7);
    cout<<"to view your directories files "<<endl;
    cout<<"$: ";
    fflush(stdin);
    getline(cin,file);
    if(file =="*esc" )
    {
        menu();
    }
       if(file=="*ls" || file=="*dir")
    {
        string temp;
        temp="dir "+continuepath;
        system(temp.c_str());
        goto file;
    }
    continuepath=continuepath+file+".txt";
    read_file_log(usernames,continuepath);
    cout<<"the path is";
    SetConsoleTextAttribute(hConsole, 9);
    cout<< continuepath<<endl;
    SetConsoleTextAttribute(hConsole, 7);
    shadowread.open(continuepath.c_str());
    string data;


string path,lvl;
            if(shadowread.fail())
                {
                    cout<<"File is not found"<<endl;
                   menu();
                }
                else
                    {
                    cout<<"\n\n------------------------------------  Beginning of File  -------------------------------------\n\n"<<endl;
                    while(!shadowread.eof())
                    {
                    getline(shadowread,data);
                    cout<<data<<endl;

                    }
                    cout<<"\n------------------------------------  File End  ------------------------------------------------"<<endl;
                    menu();
                    }
    }

void god_write(string username)
{
  ifstream writetext;
    ifstream outtext;
    char answer;
    cin.ignore();
    string continuepath=".\\",directories,file,dire;
    do {
    directories:
    cout<<"Enter your directories name , *h for help "<<endl;
    cout<<continuepath<<endl;
    cout<<"$: ";
    fflush(stdin);
    getline(cin,directories);
     if(directories =="*h")
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
    cout<<"\n\n----------------------------End of Helps----------------------------------------------------------------------"<<endl;
         goto directories;
    }
        if(directories == "*esc")
    {
      menu();
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
            menu();
        }
    top:
    cout<<"\n\nYour current path ";
    SetConsoleTextAttribute(hConsole,9);
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
    cout<<"Enter file name , *h for help"<<endl;
    cout<<"$: ";
    fflush(stdin);
    getline(cin,file);
 if(file =="*h")
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
    cout<<"\n\n----------------------------End of Helps----------------------------------------------------------------------"<<endl;
         goto file;
    }
      if(file=="*esc")
    {
        menu();
    }
    if(file=="*ls" || file=="*dir")
    {
        string temp;
        temp="dir "+continuepath;
        system(temp.c_str());
        goto file;
    }
    continuepath=continuepath+file+".txt";
    string converted;
    for(int i = 0; i < continuepath.size(); ++i)
		converted += toupper(continuepath[i]);
    cout<<"The path is ";
    SetConsoleTextAttribute(hConsole, 9);
    cout<<continuepath<<endl;
    SetConsoleTextAttribute(hConsole, 7);
    writetext.open(continuepath.c_str());
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                if(writetext.fail())
                {

                    cout<<"Error:1506 Not found , REPORT to administrator immediate files got deleted !!!! "<<endl;
                    SetConsoleTextAttribute(hConsole, 7);
                return ;
                }
                else if (converted.compare(".\\Logs\\blacklist.txt")==0)
                {

                    cout<<"Error:1507 Blacklist not able to edit , please use un(B)anned features "<<endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    return ;
                }
                else if(converted.compare(".\\LOGS\\LOGS.TXT")==0)
                {
                        cout<<"Error:1505 Logs.txt is not permitted to edit "<<endl;
                        SetConsoleTextAttribute(hConsole, 7);
                        return ;
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, 7);
                write_file_log(username,continuepath);
                continuepath="notepad "+continuepath;
                system(continuepath.c_str());
                }
            }

int blacklist(string username)
{
        ofstream blacklist("Logs\\blacklist.txt",ios::app);
        blacklist<<username<<endl;
}

void removeBlackList()
{
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"PLEASE DO TAKE NOTES"<<endl;
        cout<<"PLEASE DO TAKE NOTES"<<endl;
        cout<<"PLEASE DO TAKE NOTES"<<endl;
        cout<<"\nWARINING , IF YOU DOES NOT HAVE ANY PERMISSIONS OR INVESTIGATION IS NOT DONE YET ! YOU ARE NOT ALLOW TO UNBANNED A USER !"<<endl;
        cout<<"\nPLEASE DO TAKE NOTES"<<endl;
        cout<<"PLEASE DO TAKE NOTES"<<endl;
        cout<<"PLEASE DO TAKE NOTES"<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"To quit type -quit "<<endl;
        string dump,userid;
        ifstream blacklist("Logs\\blacklist.txt",ios::app);
        ofstream tempblacklist("Logs\\femiogbvefo12ERTGrew3e32wed.txt",ios::app);

        cout<<"--------------------- Black List ----------------------"<<endl;
        while(!blacklist.eof())
        {
            getline(blacklist,dump);
            cout<<dump<<endl;
            if(dump == "")
            {
            tempblacklist<<dump;
            }
            else{
            tempblacklist<<dump<<endl;
            }

        }
        cout<<"--------------------- End of Black List -------------------"<<endl;
        blacklist.close();
        system("del \f Logs\\blacklist.txt");
        ofstream blacklistW("Logs\\blacklist.txt",ios::app);
        ifstream tempblacklistRead("Logs\\femiogbvefo12ERTGrew3e32wed.txt",ios::app);

        cout<<"\nEnter the username you wish to unbanned "<<endl;
        cin>>userid;
        if(userid.compare("-quit")==0 )
        {
             while(!tempblacklistRead.eof())
                {
                    getline(tempblacklistRead,dump);
                     blacklistW<<dump<<endl;
                }
                cout<<"Program QUITED"<<endl;
        }

        while(!tempblacklistRead.eof())
        {
            getline(tempblacklistRead,dump);
            if(userid.compare(dump)==0)
            {
                blacklistW<<"";
                cout<<"Changes have been made"<<endl;
                Unbanned_Group_User(globaluser,userid);
            }
            else
            {
                blacklistW<<dump<<endl;
            }
        }
        tempblacklistRead.close();
        tempblacklist.close();
        system("del /f Logs\\femiogbvefo12ERTGrew3e32wed.txt");
}

bool verifyblacklist(string username)
{
    string dump;
    ifstream blacklist;
    blacklist.open("Logs\\blacklist.txt",ios::app);
    while(!blacklist.eof())
    {
        getline(blacklist,dump);
        if(username.compare(dump)== 0)
        return 0 ;
    }

}
