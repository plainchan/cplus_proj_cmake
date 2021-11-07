#include <iostream>
#include <vector>
using namespace std;

/*
*   string封装了char，管理字符串，是char型的一个容器(typedef basic_string<char> string)
*   
*/

int main()
{
    {
        cout << "**************** 构造 *************" << endl;
        // string str{"Hello World"};
        string str("Hello World");
        string str1 = "Hello World";
        string str2(str1);
        string str3("Hello", 5); //声明空间大小

        cout << "str: " << str << endl;
        cout << "str1: " << str1 << endl;
        cout << "str2: " << str2 << endl;
        cout << "str3: " << str3 << endl;
    }

    {
        cout << "**************** string 与char str[] *************" << endl;
        string str("Hello World");
        char cstr[] = "Hello World";                                            //会自动在字符串后面添加结束符\0,占用一个字节
        char cstr1[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'}; //不会自动在字符串后面添加结束符\0
        cout << "sizeof(cstr) = " << sizeof(cstr) << endl;
        cout << "str.capacity = " << str.capacity() << endl; //通常会比字符串的实际容量大
        // char *p =cstr1;
        // while (*p)
        // {
        //     cout << *p++;
        // }  //没有停止符会溢出
        // cout << endl;

        const char *cstr2 = str.c_str();
        cout << "cstr2 = " << cstr2 << endl;
    }

    {
        cout << "**************** 访问 *************" << endl;
        string str = "Hello World!";
        cout << str.at(1) << endl;
        cout << str.front() << endl;
        cout << str.back() << endl;

        const char *p = str.data(); //返回指向字符串首字符的指针
        cout << p << endl;
    }

    {
        cout << "**************** 迭代器 *************" << endl;
        string str = "Hello World!";
        for (string::iterator it = str.begin(); it != str.end(); it++)
        {
            // *it = 'H';
            cout << *it << ' ';
        }
        cout << endl;

        //常迭代器 不允许修改迭代器指向的值
        for (string::const_iterator it = str.cbegin(); it != str.cend(); it++)
        {
            // *it = 'H';   错误： it 是常迭代器
            cout << *it << ' ';
        }
        cout << endl;

        //从尾部到头部迭代
        for (string::reverse_iterator it = str.rbegin(); it != str.rend(); it++)
        {
            cout << *it << ' ';
        }
        cout << endl;

        //从尾部到头部迭代 常迭代器 不允许修改迭代器指向的值
        for (string::const_reverse_iterator it = str.crbegin(); it != str.crend(); it++)
        {
            cout << *it << ' ';
        }
        cout << endl;
    }
    {
        cout << "**************** 容量大小 *************" << endl;
        string str = "Hello World!";
        cout << str.size() << endl;
        cout << str.length() << endl;
        cout << str.capacity() << endl;
        cout << str.max_size() << endl; //可以存储的最大字符数

        str.clear();
        if (str.empty())
            cout << "空字符串" << endl;
    }

    {
        cout << "**************** 插入 删除 *************" << endl;
        string str = "Hello World";
        cout << "str = " << str << endl;

        //子串
        string str1 = str.substr(0, 5); //返回[0,0+5)之间的字符串
        cout << str1 << endl;
        //尾部插入
        str.append("!");
        cout << "str = " << str << endl;
        str.push_back('!');
        cout << "str = " << str << endl;
        str.pop_back();
        cout << "str = " << str << endl;

        //插入字符
        str.insert(str.end(), '!');
        cout << "str = " << str << endl;
        str.insert(str.end(), 5, '#');
        cout << "str = " << str << endl;
        str.insert(0, "Good Morning.");
        cout << "str = " << str << endl;

        //移除
        str.erase(str.begin());
        str.erase(0, 12);
        cout << "str = " << str << endl;

        //替换
        str.replace(12, 6, ""); //替换[12,12+6)之间的字符串
        cout << "str = " << str << endl;

        //交换
        str.swap(str1);
        cout << "str = " << str << endl;
        cout << "str1 = " << str1 << endl;
    }

    {
        cout << "**************** 数值转换 *************" << endl;
        string num_str = "123";
        int num = stoul(num_str);
        cout << "num = " << num << endl;
        num_str = to_string(123456);  //转换成字符串
        cout << "num_str = " << num_str << endl;
    }
    {
        cout << "**************** 查找 *************" << endl;
        string str = "Hello World";
        int  index = str.find('W');
        cout << str[index] << endl;
        
    }

    return 0;
}