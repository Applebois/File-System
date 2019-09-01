#include <iostream>
#include <fstream>
#include <windows.h>
#include "filelevel.h"
#include "case_c.h"
#include "help.h"
#include "quit_r_w_c_func.h"
#include "Create_text.h"

using namespace std;

void selection_for_text();
void createtxt(string makefile,string file,int currentuserlevel);

void case_c(int currentuserlevel,string userdirectories)
{
        string display = userdirectories;
        display= display.erase(display.length()-1);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string filename,directories,makefile,case1string,casetstring,file=userdirectories,string_fot,string_fot2;
    char fot,answer,ans, choice,reply;
    cout<<"Choices -> (F)older & Text or (T)ext "<<endl;
    ifstream txtfile;
    ofstream makefiles;
    cin>>string_fot;
    minuss:
        if(string_fot.length()!=1)
        {
        string_fot.erase(string_fot.length()-1);
        goto minuss;
        }
    fot=string_fot[0];
   switch(fot)
    {
    case 'F':
    case 'f':
        cout<<"You want to create in your directories or custom directories ?? User directories is \"";
        SetConsoleTextAttribute(hConsole, 9);
        cout<<userdirectories;
        cout<<"\""<<endl;
         SetConsoleTextAttribute(hConsole, 7);
        cout<<"1.Own directories("<<display<<")";     cout<<"\t 2. custom directories(.\\)    \t "<<endl;
        cout<<"Choice -> ";
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
 if(choice =='1' || choice =='2')
{
cout<<"Enter the name for the folder"<<endl;
        cout<<"$: ";
        cin>>filename;
        case1string= userdirectories + filename;
        if (choice =='1')
        {
            filename = case1string;
        }
        makefile="mkdir ";
        makefile =makefile+filename;
        directories= filename;
        top:
            do
            {
                 cout<<"Do you want to continue ? or you want to stop at this directories (C)ontinue , (S)top  , (L)ist current directories "<<endl;
                 cout<<"Your path \"";
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 9);
                 cout<<directories<<"\""<<endl;
SetConsoleTextAttribute(hConsole, 7);
                 cout<<"Choice -> ";
                    cin>>string_fot2;
           filter1:
        if(string_fot2.length()==1)
               {
        answer=string_fot2[0];
               }
        if(string_fot2.length()!= 1)
        {
        string_fot2.erase(string_fot2.length()-1);
        goto filter1;
        }
                   if(answer=='C' || answer=='c')
                   {
                        cout<<"Enter the name for the folder"<<endl;
                        cout<<"$: ";
                        cin>>filename;
                        directories=directories+"\\"+filename;
                        system("CLS");
                   }
                   if(answer =='l' || answer =='L')
                    {
                system("CLS");
                string dires="dir "+directories;
                system(dires.c_str());
                goto top;
                    }
                     if(answer =='S' || answer=='s')
                        {
                cout<<"Enter the name for text , File extension don't have to be mention  "<<endl;
                cout<<"$: ";
                directories=directories+"\\";
                cin>>filename;
                string mkdir = "mkdir "+directories;
                makefile =filename+".txt";
                makefile= directories + makefile;
               system(mkdir.c_str());
                txtfile.open(makefile.c_str());
                cout<<"The directories is ";
        SetConsoleTextAttribute(hConsole, 9);
                cout<<makefile<<endl;
                SetConsoleTextAttribute(hConsole, 7);
                if(txtfile.good())
                    {
                    cout<<"File is exist"<<endl;
                return;
                    }
                else{
                    makefiles.open(makefile.c_str());
                    checkfile(makefile.c_str(),currentuserlevel);
                    filename="";
                    cout<<"File is created "<<endl;
                    return ;
                    }
                    }
            } while (answer == 'C' || answer == 'c');
               cout<<"Folder failed to create "<<endl;
                break;
}
else{
    cout<<"Invalid Selection"<<endl;
    break;
}



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
    case 'T':
    case 't':
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        cout<<"Your directories ";
        SetConsoleTextAttribute(hConsole, 9);
        cout<<userdirectories<<endl;
        SetConsoleTextAttribute(hConsole, 7);
         cout<<"1.Start from my directories("<<display<<")";     cout<<"\t 2. Create at (.\\)    \t "<<endl;
        cout<<"Choices -> ";
         cin>>string_fot2;
           filter3:
        if(string_fot2.length()!= 1)
        {
        string_fot2.erase(string_fot2.length()-1);
        goto filter3;
        }
           if(string_fot2.length()==1)
               {
        reply=string_fot2[0];
               }
             loop:
            switch(reply)
            {
                case '1' :                ///go deeper directories

                do {
                cout<<"Do you want to create at the text file at this ";
                SetConsoleTextAttribute(hConsole, 9);
                cout<<file;
                SetConsoleTextAttribute(hConsole, 7);
                cout<<"  ?"<<endl;
                cout<<"Choice -> ";
                cin>>string_fot2;
                filter4:
        if(string_fot2.length()!= 1)
        {
                string_fot2.erase(string_fot2.length()-1);
                goto filter4;
        }
           if(string_fot2.length()==1)
               {
            ans=string_fot2[0];
               }
                if(ans=='?')
                {
                    selection_for_text();
                    goto loop;
                }
                  if(ans=='E' || ans =='e')
                {
                    break;
                }
                if(ans=='y'||ans=='Y')
                {
                    createtxt(makefile,file,currentuserlevel);
                    break;
                }
                dirloop:
                cout<<"Enter the sub directories , *-h for help "<<endl;
                cout<<"$: ";
                cin>>casetstring;
                if(casetstring =="*-h")
                {
                    create_text();
                }
                if(casetstring =="*esc")
                {
                    quit();
                }
                if(casetstring=="*dir" || casetstring=="*ls")
                {
                    string dir = "dir "+file;
                    system(dir.c_str());
                    goto dirloop;
                }
                file=file + casetstring + "\\";
                string temp = "chdir "+file;
                if(int(system(temp.c_str())) ==1)
                {
                    return ;
                }
                cout<<"Your current location is  -> """;
                SetConsoleTextAttribute(hConsole, 9);
                cout<<file;
                SetConsoleTextAttribute(hConsole, 7);
                cout<<"\""<<endl;
                cout<<"Do you want to continue to browser deeper directories  ??"<<endl;
                cout<<"Your answer -> ";
                cin >>answer;
                if(answer=='Y' || answer=='y')
                {
                    goto dirloop;
                }
                }while(answer=='n'|| answer=='N');
                break;


                case '2':
                cout<<"Enter the name for text , File extension don't have to be mention  "<<endl;
                cout<<"$: ";
                cin>>filename;
                makefile =filename+".txt";
                txtfile.open(makefile.c_str());
                if(txtfile.good())
                    {
                    cout<<"File is exist"<<endl;
                return;
                    }
                else{
                    makefiles.open(makefile.c_str());
                    checkfile(makefile.c_str(),currentuserlevel);
                    filename="";
                    cout<<"File is created "<<endl;
                    return ;
                    }
                break;

                default: system("CLS");
                cout<<"Invalid Selection"<<endl;
                break;
            }

    }

}
