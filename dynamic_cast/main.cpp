#include <iostream>

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


// dynamic_cast < 新类型 > ( 表达式 ) 		
// 新类型 	- 	指向完整类类型的指针，到完整类类型的引用，或指向（可有 cv 限定的）void 的指针
// 表达式 	- 	如果 新类型 是引用，那么是完整类类型的左值 (C++11 前)泛左值 (C++11 起)表达式，
//             如果 新类型 是指针，那么是指向完整类类型的指针纯右值。

// 如果转型成功，那么 dynamic_cast 就会返回 新类型 类型的值。如果转型失败且 新类型 是指针类型，那么它会返回该类型的空指针。
// 如果转型失败且 新类型 是引用类型，那么它会抛出与类型 std::bad_cast 的处理块匹配的异常。 
// @ref https://zh.cppreference.com/w/cpp/language/dynamic_cast


// 基类向派生类转换，基类指针指向派生类对象，或者基类引用派生类对象时，类型转换才会成功，否则转换失败。
int main()
{

    {
        //下行转换Downcast
        Dog thedog;
        Animal &animal =thedog;
        Dog dog = dynamic_cast<Dog&>(animal);
        dog.species();
    }

    {
        //下行转换Downcast
        Dog thedog;
        Animal *animal =&thedog;   //基类指针指向
        if(Dog *dog = dynamic_cast<Dog*>(animal))
            dog->species();
    }

    {
        //上行转换
        Dog *dog=new Dog();

        // Animal *animalPtr = dog;
        Animal *animalPtr = dynamic_cast<Animal*>(dog);
        animalPtr->species();


        delete dog;
   
    }

	return 0;
}
