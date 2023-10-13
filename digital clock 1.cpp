#include<iostream>
using namespace std;

int main(){

int h=0,m=0,s=0;
cout<<"Enter hours ,minutes ,seconds"<<endl;
cin>>h>>m>>s;
start:
    for(h;h<24;h++)
    {
        for(m;m<60;m++){

        for(s;s<60;s++){

            system("cls");
            cout<<h<<":"<<m<<":"<<s<<endl;
            if(h<12)
                cout<<"AM";
            else
                cout<<"PM";
            for(double i=1;i<3910000;i++){

                i++;i--;
            }
            } s=0;

        }m=0;

    }h=0;
  goto start;
  return 0;
}
