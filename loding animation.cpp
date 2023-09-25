#include <iostream>

using namespace std;


void loading()  /////////////////////////////////////For loading animation
{
    system("cls");
    int r,q;


    printf("\t \t \t LOADING...");

    for(r=1; r<=20; r++)
    {
        for(q=0; q<=10000000; q++);
        printf("%c",177);
    }
    system("cls");


}


int main()
{

   loading();

    return 0;
}
