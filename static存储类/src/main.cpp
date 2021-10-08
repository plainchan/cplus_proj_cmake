#include "example.h"

using namespace std;

int main()
{ 

  cout << "全局变量number_global =" << number_global << endl;
  cout << "全局变量static_number_global =" << static_number_global << endl;

  int cnt = 0;
  while(true)
  {
    cnt++;
    keepLocalValueLive();
    LocalValueDestroye();
    if(cnt >5)
      break;
  }
 
  return 0;
}

