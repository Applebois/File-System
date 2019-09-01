#include <iostream>
#include <conio.h>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "md5.h"
#include "login.h"
#include "copyright.h"
#include "windows.h"
#include "help.h"
#include "storelog.h"
#include "Verify_prohibitwords.h"

using namespace std;
void makenewpassword(string &);
int processing();
int processing2();
int main();
int enter();
void SYSSTART();
void registeraccount(string);
void LastLoginRecord(string);
bool verifyprohibitwords(string);

int pass(string & user , string& password)
{
int ch;
string temppw="",tempuser="",temprights="";
string saltuser="",salt="",dump,user_decscription,group;
cout<<"\n\nSalt is retrieving ";

    cout<<".";
    Sleep (500);
    cout<<".";
    Sleep (500);
    cout<<".";
    Sleep (500);

system("CLS");
cout<<"Salt is retrieved , please proceed to next steps"<<endl;
cout<<"Enter password"<<endl;
 ifstream shadowread,saltread,passwdread;
   shadowread.open(".\\etc\\shadow.txt",ios::app);
   passwdread.open(".\\etc\\passwd.txt",ios::app);
    saltread.open(".\\etc\\salt.txt",ios::app);
        if(!shadowread.good())
    {
cout<<"file cannot write"<<endl;
    }
    while(ch=getch())
    {
        if (ch==13)
        {
    while(!shadowread.eof())
            {
    getline (shadowread,tempuser,':');
    getline (shadowread,temppw,':');
    getline (shadowread,temprights);
    getline(passwdread,dump,':');
    getline(passwdread,dump,':');
    getline(passwdread,dump,':');
    getline(passwdread,group,':');
    getline(passwdread,user_decscription,':');
    getline(passwdread,dump);
    getline (saltread,saltuser,':');
    getline (saltread,salt);
           if( user==tempuser && "$1$"+md5(salt+password+salt+user) == temppw)
            {
                system("CLS");
              cout<<"The user clearance for "<<user<<" is "<<temprights<<endl;
               cout<<"\n\n"<<endl;
               cout<<"Hold on while logging in .";

    cout<<".";
    Sleep (500);
    cout<<".";
    Sleep (500);
    cout<<".";
    Sleep (500);


                system("CLS");
                shadowread.close();
               if(temprights == "1")
                {
                    CheckLastLoginRecord(user);
                    LastLoginRecord(user);
                    level1(user,user_decscription,group);
                }
                else if(temprights == "0")
                {
                    CheckLastLoginRecord(user);
                    LastLoginRecord(user);
                    level0(user,user_decscription,group);
                }
                else
                {
                    CheckLastLoginRecord(user);
                    LastLoginRecord(user);
                    level2(user,user_decscription,group);
                }

            }
            }
            system("CLS");
            cout<<"Password is incorrect redo the process\n"<<endl;
            cin.ignore();
            processing2();
        }
    else if(ch==8)
        {
        if(password.length()>0)
            password.erase(password.length()-1); ///Erase String length
}
    else
   {
        password += ch;
   }
}

}

void makenewpassword(string & user) // for new user
{
    srand(time(0));
    string temp,password,user_description,string_fot,trash;
    int ch,counter=0;
    char a;
 if(temp=="\0")
 {
     top:
      cout<<"Welcome new user ,need help type **h seek for help"<<endl;
      cout<<"\n\n----------------------- Enter user details ----------------------"<<endl;
     cout<<"Enter create your password"<<endl;
       while(ch=getch())
    {
         if(temp.compare("esc")==0)
     {
         system("CLS");
         cout<<"Quited"<<endl;
       cin.ignore();
       enter();
     }
      if(temp.compare("**h")==0)
     {
        registration(); ///HELP DISPLAY  HELP.CPP
            temp="";
     }

      if (ch==13 && temp.length()<4)
        {

                cout<<"Password require minimum 3 character"<<endl;
                makenewpassword(user);
                temp="";
                goto top;
        }

        else if(ch==13 && temp.length()>=4 )
        {
            temp;
            break;
        }

    else if(ch==8){
   if(temp.length()>0)
    temp.erase(temp.length()-1); ///Erase String length
    }
    else if (ch==35 || ch==45 || ch==33 || ch==61 || ch==44 || ch==39)
    {
        cout<<"Symbol in the brackets are not allow to be part of your password ( ! # ' = - , )"<<endl;
    }
    else
   {
        temp += ch;
   }
        }
 }
///Re-enter password
cout<<"Enter password confirmation "<<endl;
       while(ch=getch())
    {
            if(password.compare("esc")==0)
     {
             system("CLS");
         cout<<"Quited"<<endl;
       cin.ignore();
       main();
     }
          if(password.compare("**h")==0)
     {
        registration(); ///HELP DISPLAY  HELP.CPP
     }

        if (ch==13 && password.length()<4)
        {
                cout<<"Password require minimum 3 character"<<endl;
                makenewpassword(user);
                password="";
                goto top;
        }
        else if(ch==13 && password.length()>=4 )
        {
            password;
            break;
            }


    else if(ch==8){
   if(password.length()>0)
    password.erase(password.length()-1); ///Erase String length
    }
    else if (ch==35 || ch==45 || ch==33 || ch==61 || ch==44 || ch==39)
    {
        cout<<"Symbol in the brackets are not allow to be part of your password ( ! # ' = - , ) "<<endl;
    }
    else
   {
        password += ch;
   }
        }

if(temp == password) ///check password is enter correctly twice
 {
    int saltvalue=rand()%9999+1000;
    int saltvalue2=rand()%9999+1000;
    stringstream ss;
    ss << saltvalue;
    string str = ss.str();
    ss<<saltvalue2;
    str= ss.str();                      ///LOOP 2 TIME RANDOM
    enterdes:
    cout<<"Enter user descriptions ";
    cin>>user_description;
    if(!verifyprohibitwords(user_description))
    {
        goto enterdes;
    }
    cout<<"Enter group , if don't have enter 1000"<<endl;
    tops:
    cin>>string_fot;
        if(string_fot.compare("IAMTHEFUTURE")==0)
        {
            trash="500";
            cout<<"Your account have been register"<<endl;
            registeraccount(user);
            Coupon_Used(user);
            ////////////////////////////////////////////ADD USE COUPON LOGS
        }
        else if(string_fot.length()!=4 && string_fot.length()>4)
        {
            do
            {
            string_fot.erase(string_fot.length()-1);
            if(string_fot.compare("1000") ==0 && string_fot.length()==4)
            {
            trash=string_fot;
            registeraccount(user);
            cout<<"Your account have been register"<<endl;
            }
        }while(string_fot.length()!=4);
        if(string_fot.compare("1000")==1)
                {
                    counter++;
                    goto tops;
                }
        }
        else if (string_fot.length()==4 && string_fot.compare("1000")==0)
        {
            trash =string_fot;
            registeraccount(user);
            cout<<"Your account have been register"<<endl;
        }
        else
        {
            cout<<"Invalid Group"<<endl;
            counter++;
            if(counter < 3)
            {
                goto tops;
            }
            if(counter == 3 )
            {
                registeraccount(user);
                cout<<"Your account have been register , to change the group please contact administrator "<<endl;
                trash = "1000";
            }
        }

    ifstream shadowread,saltread,pass;

   // system("CLS");                      ///CLEAR ABOVE COMMAND

    ofstream shadow,salt,passwdread;
    password =str+password+str+user;            /// HOW PASSWORD PROCESS TO A SECURE PASSWORD = SALT + PASSWORD + SALT + USER
    shadow.open(".\\etc\\shadow.txt",ios::app);
    salt.open(".\\etc\\salt.txt",ios::app);
    copyright();                                ///RUN COPYRIGHT FUNCTION JUST A ALTERNATE DATE STREAM
    shadow<<user<<":";
    salt<<user<<":";
    string dump;
    string uid;
    pass.open(".\\etc\\passwd.txt",ios::app);
 while(!pass.eof())
 {
    getline (pass,dump,':');                    ///READ ALL PASSWD ENTRIES
    getline (pass,dump,':');
    getline (pass,uid,':');                     ///READ UID IN STRING MODE
    getline(pass,dump);
 }
  pass.close();
    if(uid == "" )                              ///IF PASSWD FILES DOES NOT HAVE ANY ENTRIES
    {
        uid="1000";                             ///FIRST UID IS 1000
    }
    else
    {
    istringstream pass(uid);                    ///CHECK UID IS UID IS 1050
    int b;
    pass >>b;                                   ///1050 VALUE IS INSERT TO INTEGER B VARIABLE
    b=b+1;                                      ///B WILL DO INCREMENTAL SO FOR REGISTER USER THE NEXT USER UID WILL BE 1051
    ostringstream conversion;                   ///CREATE A NEW VARIABLE "CONVERSION"
    conversion<<b;                              ///INTEGER B VALUE IS OUTPUT TO CONVERSION
    uid=conversion.str();                       ///CONVERSION VARIABLE IS A STRING AND WITH VALUE OF 1051 , NOW ASSIGN THE 1051 TO UID
    }
    passwdread.open(".\\etc\\passwd.txt",ios::app);
    passwdread<<user<<":x:"<<uid<<":"<<trash<<":"<<user_description<<":home/"<<user<<endl;
    string p1="mkdir ";
    string makefile= "home\\";
    makefile=makefile+user;
      cout<<"ID of "<<user<<" directories have been created "<<makefile<<endl;

      cout<<"\n\n"<<endl;
      makefile=p1+makefile;
    system(makefile.c_str());
    shadow<<"$1$"+(md5(password))<<":2"<<endl;
    salt<<str<<endl;
    salt.close();
    shadow.close();
    passwdread.close();
    cin.ignore();
    enter();

 }
else
{
    system("CLS");
    cout<<"Password does not match."<<endl;
    processing();

}
    cin.ignore();
    enter();
}

int enter()
{
    SetConsoleTitle("Terminal > ");
    ifstream shadowread,passread,saltread, ifiles;
    ofstream  ofiles;
    string enter,dump;
        top:
        cout<<"$: ";
        getline(cin,enter);
        if(enter.compare("version -?")==0)
        {
            cout<<"Version 1.5.3.2"<<endl;
            cout << "Compiled on: " << __DATE__ << endl;
            cout << "Compiled at: " << __TIME__ << endl;
              goto top;
        }
        if(enter.compare("FileSystem ?")==0 || enter.compare("FileSystem -?")==0 || enter.compare("?")==0)
        {
         filesystem(); ///HELP DISPLAY IN HELP.CPP
            goto top;
        }
        if (!enter.compare("FileSystem -i")==0 && !enter.compare("FileSystem")==0)
        {
            cout<<"Having trouble ? try launch the command Filesystem with '?' or '-?' argument or just '?' "<<endl;
            goto top;
        }
    cout<<"Loading ";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0);
    system("mkdir etc");
    SetConsoleTextAttribute(hConsole, 7);
    shadowread.open(".\\etc\\shadow.txt",ios::app);
    passread.open(".\\etc\\passwd.txt",ios::app);
    saltread.open(".\\etc\\salt.txt",ios::app);
    system("mkdir fileslevel");
    ofiles.open(".\\fileslevel\\filestore.txt",ios::app);
    ifiles.open(".\\fileslevel\\filestore.txt",ios::app);
    getline(ifiles,dump);
    if(int(dump.compare(""))==0)
    {
    ofiles<<".\\fileslevel\\filestore.txt:0"<<endl;
    ofiles<<".\\etc\\passwd.txt:2"<<endl;                                 ///set shadow.txt as read right only
    ofiles<<".\\etc\\salt.txt:0"<<endl;                                   ///set only write only
    ofiles<<".\\etc\\shadow.txt:0"<<endl;
    }
    system("CLS");
    if(enter.compare("FileSystem -i")==0)
    {
        SetConsoleTitle("Register");
        cout<<"Register function"<<endl;
        processing();

    }
    if(enter.compare("FileSystem")==0)
    {
        cout<<"Login function"<<endl;
        SetConsoleTitle("Login");
        processing2();

    }
    system("CLS");
       return 0;

}

int processing()            ///register
{
    top:
    string user,password="", usercmp="";
    string *pointer1=&user;
    string *pointer2=&usercmp;
    string *pointer3=&password;
    login(*pointer1,*pointer2);
    if(user != usercmp)
    {
    if(!verifyprohibitwords(user))
    {
        goto top;
    }

    makenewpassword(*pointer1);
    }
    else
    {
    cout<<"Wrong syntax "<<endl;
    cout<<"Error 1054 , you may try FileSystem"<<endl;
    cin.ignore();
    enter();
    }
    return 0;
}

int processing2()           ///login
{
    string user,password="", usercmp="";
    string value;
    string *pointer1=&user;
    string *pointer2=&usercmp;
    string *pointer3=&password;
    login(*pointer1,*pointer2);
    if(user != usercmp)
    {
    cout<<"Wrong syntax , and account not found "<<endl;
    cout<<"Error 1053 , you may try FileSystem -i "<<endl;
    cin.ignore();
    enter();
    }
    else
    {

            redocap:
            srand(time(NULL));
            int  r= (rand()%8999 + 1000);
            string rs=to_string(r);
         cout<<"Captcha please enter following number : "<<rs<<endl;
           cout<<"Validation -> ";
           cin >>value;
           if(value.compare(rs)==0 )
           {
               system("CLS");
               cout<<"Thanks for your authentication to authenticate you are not a stupid ."<<endl;
           }
           else
           {
               system("CLS");
               cout<<"Validate is wrong , re-do process"<<endl;
               value="";
               goto redocap;
           }
    pass(*pointer1,*pointer3);
    }
    return 0;
}


int main()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0);
    system("mkdir Logs");
    system("CLS");
    SetConsoleTextAttribute(hConsole, 7);
    SYSSTART();
    enter();
   // processing();
}


