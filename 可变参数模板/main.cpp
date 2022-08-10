#include <iostream>

using namespace std;

template<typename T,typename...Args>
void print(Args...args)
{
    std::cout << args << std::endl ;
    print(args...);
}




int main()
{

	print(1,2,34,5,1.1);
	return 0;
}