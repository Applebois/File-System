#include <iostream>
#include <fstream>
#include "filelevel.h"
#include "Create_text.h"

using namespace std;
void createtxt(string makefile,string file,int currentuserlevel)
{
                string filename;
                ifstream txtfile ;
                ofstream makefiles;
                cout<<"Enter the name for text , File extension don't have to be mention  "<<endl;
                cout<<"$: ";
                cin>>filename;
                makefile =filename+".txt";
                makefile= file + makefile;
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
 }
