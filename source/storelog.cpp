#include <iostream>
#include "storelog.h"
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <ratio>
#include <chrono>
#include <windows.h>

using namespace std ::chrono;

string dumper;


void capture_publicIP()
{
string trash;
int length;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 0);
system("nslookup myip.opendns.com resolver1.opendns.com > catch.txt ");
ifstream publiccatch("catch.txt");
while(!publiccatch.eof())
{
    getline(publiccatch,dumper,':');
    getline(publiccatch,dumper,':');

    if(dumper.compare("  UnKnown\nAddress")==0)
    {
        dumper="localhost 127.0.0.1";
         publiccatch.close();
        break;
    }
        getline(publiccatch,dumper,':');
        getline(publiccatch,dumper,':');
         if(dumper.compare("  208.67.222.222\n\n")==0)
         {
              dumper = "UNKNOWN PUBLIC IP";
              break;
         }
       // getline(publiccatch,dumper,':');
        //getline(publiccatch,dumper,':');
        getline(publiccatch,dumper,' ');
        getline(publiccatch,dumper,' ');

        getline(publiccatch,dumper);
        getline(publiccatch,trash);
        getline(publiccatch,trash);
        //getline(publiccatch,trash);
        //getline(publiccatch,dumper,'\n');
        publiccatch.close();
}
   system("del /f catch.txt");
   SetConsoleTextAttribute(hConsole, 7);
    return;
}

void maliciousgroup(string user , string userlevel , string group)
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    outfile<<"[SECURITY : MALICIOUS ] Account : \""<<user<<"\"  at  userlevel "<<userlevel<<" with group level"<<group<<" from IP ADDRESS "<<dumper<<" is trying to attempt a (G)roup switch at "<<ctime(&tt);
}

void failed_to_enter_password(string user , string userlevel)
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    cout<<"Logs have been store , password attempting is more than enough  "<<endl;
    outfile<<"[SECURITY : FAILED TO ENTER PASSWORD ] Account : \""<<user<<"\"  at  userlevel "<<userlevel<<" from IP ADDRESS "<<dumper<<" have entered incorrect files name while logging into group menu more than 3 times at "<<ctime(&tt);

}

void successful_login(string user , string userlevel)
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    cout<<"Welcome Back , AGENT "<<user<<endl;
    outfile<<"[SYSTEM : LOGIN INTO GROUP ] Account : \""<<user<<"\"  at  userlevel "<<userlevel<<" from IP ADDRESS "<<dumper<<" have login into group menu at "<<ctime(&tt);

}

void successful_logout(string user)
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    cout<<"GoodBye , AGENT"<<user<<endl;
    outfile<<"[SYSTEM : LOG OUT FROM GROUP ] Account : \""<<user<<"\" from IP ADDRESS "<<dumper<<" have logout from group menu at "<<ctime(&tt);

}

void read_file_log(string user, string file )
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
        outfile<<"[SYSTEM : READ FILES FROM GROUP ] Account : \""<<user<<"\" read -> \""<<file<<"\" from IP ADDRESS "<<dumper<<" using (G)roup menu at "<<ctime(&tt);
}

void write_file_log(string user, string file )
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    outfile<<"[SYSTEM : WRITE FILES FROM GROUP ] Account : \""<<user<<"\" write/modify -> \""<<file<<"\" from IP ADDRESS "<<dumper<<" using (G)roup menu at "<<ctime(&tt);
}

void failed_to_authenticate(string user, string file )
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    outfile<<"[SECURITY : FAILED TO ENTER FILE NAME VALIDATION ] Account : \""<<user<<"\" Failed to authenticate using a files from IP ADDRESS "<<dumper<<" while attempting to login to (G)roup menu at "<<ctime(&tt);
}

void Coupon_Used(string user)
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    outfile<<"[WARNING : NEW ACCOUNT REGISTER UNDER GROUP ID 500 ] Account : \""<<user<<"\" register himself into group level 500 connecting from IP ADDRESS "<<dumper<<" at "<<ctime(&tt);
}

void SYSSTART()
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    outfile<<"[SYSTEM : START ] File System Start ..."<<ctime(&tt);
}

void SYSSTOP()
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    outfile<<"[SYSTEM : SHUT DOWN ] File System Close ..."<<ctime(&tt);
}

void registeraccount(string user)
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    outfile<<"[SYSTEM : REGISTRATION ] Account : \""<<user<<"\" New Account "<<dumper<<" at "<<ctime(&tt);
}

void write_file_normal(int level ,string username,string file)
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    outfile<<"[SYSTEM : WRITE FILES ] Account : \""<<username<<"\" at \""<<level<<"\" write -> \""<<file<<"\"  from IP ADDRESS "<<dumper<<" "<<ctime(&tt);

}

void read_file_normal(int level ,string username,string file)
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    outfile<<"[SYSTEM : READ FILES ] Account : \""<<username<<"\" at \""<<level<<"\" read -> \""<<file<<"\" from IP ADDRESS "<<dumper<<" "<<ctime(&tt);

}

void LastLoginRecord(string username)
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\LoginRecord.txt",ios::app);
    outfile<<username<<":Login IP : "<<dumper<<" at "<<ctime(&tt);
}

void CheckLastLoginRecord(string username)
{
        ifstream outfile(".\\Logs\\LoginRecord.txt",ios::app);
        string usr,dump,dumpdump;
        while(!outfile.eof())
        {
            getline(outfile,usr,':');
            getline(outfile,dump);
            if(usr.compare(username)==0)
            {
                dumpdump=dump;
            }

        }
        if(dumpdump == "")
        {
        cout<<"Welcome "<<endl;
          return ;
        }
        else
        {
            cout<<"Welcome back , \""<<username<<"\"\nYour last login record "<<dumpdump<<endl;
        }

}


void Unbanned_Group_User(string username,string victim)
{
    capture_publicIP();
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\Logs\\logs.txt",ios::app);
    outfile<<"[WARNING : UNBANNED ] Account : \""<<username<<"\" UNBANNED USER - > \""<<victim<<"\" <- packets came from IP ADDRESS "<<dumper<<" "<<ctime(&tt);

}
