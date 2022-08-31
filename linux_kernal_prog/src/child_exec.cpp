#include<iostream>
#include<unistd.h>
using namespace std;
int main(int argc,char **argv)
{
    while(true)
    {
        cout << "----------------------" << endl;
        cout << "process id: " << argv[0] << endl;
        sleep(1);//500ms
    }
    return 0;
}