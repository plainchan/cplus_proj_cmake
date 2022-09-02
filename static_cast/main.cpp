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
    void voice()
    {
        cout << "wang wang" << endl;
    }
    int legCount= 4;
};

class Cat :public Animal
{
public:
    virtual void species()
    {
        cout << "this is cat" << endl;
    }
    void voice()
    {
        cout << "miao miao" << endl;
    }
    int legCount= 4;
};


void test1()
{
    //转换数据
    char  ch='A';
    int num = static_cast<int>(ch); //int sum = ch;
    cout << "ch = " << ch << endl;
    cout << "num = " << num << endl;
}
void test2()
{
    //把空指针转换成目标类型的空指针，指针必须是空指针，不能指向实体！！
    void *p=nullptr;
    int *p1=static_cast<int*>(p);
    p=static_cast<int*>(p1);
}


// static_cast也可以用在于基类与派生类指针或引用类型之间的转换。
// 然而它不做运行时的检查，不如dynamic_cast安全。static_cast仅仅是依靠类型转换语句中提供的信息来进行转换，
// 而dynamic_cast则会遍历整个类继承体系进行类型检查,
// 因此dynamic_cast在执行效率上比static_cast要差一些。
void test3()
{
    //上行转换
    //基类指针指向派生类
    
    Animal *animalPtr;
    Dog *dogPtr=new Dog();
    Cat *catPtr=new Cat();


    //实现多态
    animalPtr = static_cast<Animal*>(dogPtr);  //安全，子类继承父类，子类总是包含父类的全部
    animalPtr->species();

    animalPtr = static_cast<Animal*>(catPtr); 
    animalPtr->species();


    //销毁
    delete dogPtr;
    delete catPtr;

    //置空
    dogPtr = nullptr;
    catPtr = nullptr;
    animalPtr = nullptr;
}


void test4()
{
    //下行转换
    //不安全
    //基类指针转换成派生类指针
    Animal *animalPtr=new Animal();
    Dog *dogPtr = static_cast<Dog*>(animalPtr);   //不安全，子类继承父类，子类总是包含父类的全部，但是父类可能不包含子类的方法
    dogPtr->species();          
    
    // dogPtr->voice();
    // cout << dogPtr->legCount << endl;    //父类没有这个成员变量，若使用dynamic_cast,会报错

    //销毁
    delete animalPtr;

    //置空
    animalPtr = nullptr;
    dogPtr = nullptr;
}


int main()
{
    test3();
    test4();
}
