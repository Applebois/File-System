#include <iostream>
#include <fstream>
#include <string>
#include "Verify_prohibitwords.h"
#include "windows.h"
using namespace std;

bool verifyprohibitwords(string test)
{
    top:
    string tesst;
    string temp = test;
    ifstream verifyprohibitwords;
    verifyprohibitwords.open("etc\\filterword.txt");

    if(!verifyprohibitwords.good())
    {
      //  cout<<"Creating prohibitword text"<<endl;
        system("echo shit> etc\\filterword.txt");
        goto top;
    }

    for(int i =0 ; i < temp.length() ;i++)
   {
       temp[i]=tolower(temp[i]);
   }
    while(!verifyprohibitwords.eof())
    {
            getline(verifyprohibitwords,tesst);

            if ( temp.compare(tesst) == 0 )
            {
                    cout<<"Vulgar words are not available "<<endl;
                    return false;
            }
    }
                return true ;

}
