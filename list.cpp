#include <sstream>
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
void displaylevel(int currentuserlevel)
{

ifstream checkfilelevel;
checkfilelevel.open(".\\fileslevel\\filestore.txt",ios::app);
int ss;
system("CLS");
   if (currentuserlevel == 2)
        cout<<"The files you can view"<<endl;
        string path ,lvl;
    if(currentuserlevel==1)
        cout<<"The files you can write and view"<<endl;
   if(currentuserlevel==0)
        cout<<"The file you can write "<<endl;

        cout<<"\n----Start of display----\n"<<endl;
    while(!checkfilelevel.eof())
    {
        getline(checkfilelevel,path,':');
        getline(checkfilelevel,lvl);
        istringstream inputs(lvl);
        inputs>>ss;
        if(ss == 2 && currentuserlevel == 2)
        cout<<path<<endl;
        if(ss ==0 && currentuserlevel == 0)
            cout<<path<<endl;
        if(ss ==1 && currentuserlevel== 1)
            cout<<path<<endl;
    }
    cout<<"\n----End of display----\n"<<endl;
}
