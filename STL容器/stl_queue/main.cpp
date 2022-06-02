#include <iostream>
#include <queue>
using namespace std;

/*
* Queue是一种先进先出(First In First Out,FIFO)的数据结构
* 不可遍历，没有迭代器
* 只能往队尾加入元素，往对头删除元素
* 可变大小，队尾每加入一个元素，队列大小加1
* 队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
*/
int main()
{
    cout << "-----构造------ " << endl;
    queue<int> q;
    for (int i = 0; i < 10; i++)
    {
        q.push(i);
        cout << i << " ";
    }
    cout << endl;
    queue<int> q1(q);

    cout << "-----访问 增删------ " << endl;
    cout << "q的第一个元素 = " << q.front() << endl;
    cout << "q的最后一个元素 = " << q.back() << endl;
    cout << "q的大小 " << q.size() << endl;
    q.push(10);
    cout << "q.push(10) 队尾加入一个元素" << endl;
    cout << "q的第一个元素 = " << q.front() << endl;
    cout << "q的最后一个元素 = " << q.back() << endl;
    cout << "q的大小 " << q.size() << endl;
    q.pop();
    cout << "q.pop() 队头弹出一个元素" << endl;
    cout << "q的第一个元素 = " << q.front() << endl;
    cout << "q的最后一个元素 = " << q.back() << endl;
    cout << "q的大小 " << q.size() << endl;

    return 0;
}