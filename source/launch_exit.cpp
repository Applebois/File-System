#include <iostream>
#include <windows.h>

using namespace std;

//void loading()
//{
//for(int i=1;i<=50;i++)
//      {
//system("CLS");
//  cout<<"\n\n\n\n\t\t\t\t   Loading "<<'\n'<<'\t'<<'\t';
// for(int j=1;j<=i;j++)
//  cout<<"²";
//  cout<<"\n\n\t "<<2*i<<"%";
// if( i > 1 && i < 20)
//  cout<<"\n\n\tCreating Temporary files";
// else if( i > 20 && i<40)
//  cout<<"\n\n\tAccessing Main Memory";
// else if(i >40 && i<48)
//  cout<<"\n\n\tAccessing Cache";
// else cout<<"\n\n\tComplete. Press Enter to Continue ";
//  Sleep(150 - i*3);
//      }
//}

void exit_display(){
for(int i=1;i<=50;i++)
      {
system("CLS");
  cout<<"\n\n\n\n\t\t\t\t   Loading "<<'\n'<<'\t'<<'\t';
 for(int j=1;j<=i;j++)
  cout<<"²";
  cout<<"\n\n\t "<<2*i<<"%";
 if( i > 1 && i < 20)
  cout<<"\n\n\tRemoving Cache";
 else if( i > 20 && i<40)
  cout<<"\n\n\tClearing Memory";
 else if(i >40 && i<48)
  cout<<"\n\n\tShutting Down";
 else cout<<"\n\n\t Shut Down ";
  Sleep(150 - i*3);
      }
exit(0);
}
