#include <iostream>
#include <cmath>
using namespace std;

class Animal
{
public:
    virtual void species()
    {
        cout << "this is animal" << endl;
    }
};

class Dog :public Animal
{
public:
    virtual void species()
    {
        cout << "this is dog" << endl;
    }
};




int main()
{
    //转换数据
    char  ch='A';
    int num = static_cast<int>(ch);
    cout << num << endl;

    //把空指针转换成目标类型的空指针，指针必须是空指针，不能指向实体！！
    void *p=nullptr;
    int *p1=static_cast<int*>(p);
    p=static_cast<int*>(p1);

    //上行转换
    Dog *dog=new Dog();
    // Animal *animalPtr = dog;
    Animal *animalPtr = dynamic_cast<Animal*>(dog);
    animalPtr->species();


    delete dog;

}
