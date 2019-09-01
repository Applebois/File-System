#include<iostream>
#include "quit_r_w_c_func.h"
#include "storelog.h"
#include "launch_exit.h"
using namespace std;
void SYSSTOP();

 void case_exit()
 {
     char option;
     cout <<"Shut down the FileServer? (Y)es or (N)o"<<endl;
     cout<<"$: ";
    cin >> option;
        if(option == 'Y' || option =='y')
        {
            exit_display();
            SYSSTOP();
        }
        else
        {
             quit();
        }
 }
