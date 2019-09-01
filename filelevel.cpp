#include <iostream>
#include <fstream>
#include "filelevel.h"

using namespace std;

void checkfile(string files,int filesec)
{
ifstream check;
string directories, directories0 , level;
check.open(".\\fileslevel\\filestore.txt",ios::app);
files=".\\"+files;
while(!check.eof())
{
    getline(check,directories0,'\\');
    getline(check,directories,'\\');
    directories=directories0+"\\"+directories+"\\";
    getline(check,level);
        if(directories == files)
        {
cout<<"Failed to create because file "<<directories<<" already exist. "<<endl;
break;
        }
}
   if ( directories != files)
        {
            ofstream outcheck;
            outcheck.open(".\\fileslevel\\filestore.txt",ios::app);
            for (int i=0;i<files.length();i++)
            {
                files[i]=tolower(files[i]);
            }
            outcheck<<files<<":"<<filesec<<endl;
            switch(filesec)
            {
            case 1:cout<<"File level now is 1"<<endl;break;
            case 2:cout<<"File level now is 2"<<endl;break;
            case 0:cout<<"File level now is 0"<<endl;break;
            break;
            }
        }
}
