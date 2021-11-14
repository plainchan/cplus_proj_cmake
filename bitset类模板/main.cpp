#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    {
        cout << "---------构造函数--------" << endl;
        bitset<8> b1(0);
        cout << "b1 = " << b1 << endl;
        bitset<8> b2("11100000");
        cout << "b2 = " << b2 << endl;
        bitset<8> b3(0xfe);
        cout << "b3 = " << b3 << endl;
    }

    {
        cout << "--------访问-------" << endl;
        bitset<8> b("11101010");
        bitset<8> b1("00000000");
        bitset<8> b2("11111111");
        cout << "b[0] = " << b[0] << endl;   //b[0]代表最右边的末尾值
        
        cout << "b size = " << b.size() << endl;
        cout << "b 中1的个数：" << b.count() << endl;

        
        cout << "最高位是" << b.test(7) << endl; //返回位的值

        if(b.any())
            cout << "有为1的位" << endl;   //

        if(b1.none())
            cout << "每个位都是0" << endl; //

        if(b1.all())
            cout << "每个位都是1" << endl; //
    }

    {
        cout << "-------位操作-------" << endl;
        bitset<8> b("11101010");
        cout << "b = " << b << endl; 
        b.flip();
        cout << "b = " << b << endl;
        b.reset();
        cout << "b = " << b << endl;
        b.set();
        cout << "b = " << b << endl;

        cout << b.to_string() << endl;
        cout << b.to_ulong() << endl;

        
    }
    return 0;
}