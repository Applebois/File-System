#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Verify_prohibitwords.h"

using namespace std;

bool verifyprohibitwords(string temp);

int login(string &a,string &b) /// prompt user to enter login id , next function is int pass(); , not does not match go to makenewpassword();
{
    ifstream shadowread,saltread;
    ofstream ofiles;
    string value;
    string temp = a;
    again:
    cout<<"Enter your Login ID (case sensitive) :";
    cin>>a;
    if(a.size()<3 || a.size()>20)
        {
            system("CLS");
            cout<<"Your ID length should be range of 3 - 20 character . "<<endl;                ///User ID policy
            goto again;
        }
        srand(time(0));
   int  r= (rand()%8999 + 1000);
string rs=to_string(r);
   shadowread:
    shadowread.open(".\\etc\\shadow.txt",ios::app);                 ///check if the shadow files exists in etc folder
    if(!shadowread.good())                                          ///if not exist
    {
    goto shadowread;                                                ///jump back to line 25
    }
    string users,compareuser,dump;
    while(!shadowread.eof())
    {
       getline(shadowread,b,':');                                   ///Read words before :
       getline(shadowread,dump);                                    ///Read after the first word dumps all trash value just to go to nextline
       if(a.compare(b) == 0 )                                       ///if id found then do ask them for captcha
       {
            break;
       }
       else if (a != b && !shadowread.eof())
       {

       }
       else
    return 1;
    }
}
