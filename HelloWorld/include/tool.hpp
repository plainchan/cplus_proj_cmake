#ifndef _TOOL_HPP
#define _TOOL_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <queue>

#include <algorithm>
#include <utility>
#include <functional>

#include <cmath>



template <typename T>
void print(const std::vector<T> &v)
{
    std::cout << "[";
    for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        if (it == v.end() - 1)
            std::cout << *it;
        else
            std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}
template <typename T>
void print(const std::vector<std::vector<T>> &v)
{
    for (const std::vector<T> &m : v)
        print<T>(m);
    std::cout << "-----------------" << std::endl;
}

template <typename T>
struct ListNode
{
    T val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(T x) : val(x), next(nullptr) {}
    ListNode(T x, ListNode *next) : val(x), next(next) {}
};



template <typename T>
ListNode<T> *creatNode(std::vector<T> &v)
{
    if(v.empty())
        return nullptr;
    
    ListNode<T> *head = new ListNode<T>(v[0]);
    ListNode<T> *cur = head;

    for(int i=1;i<v.size();++i)
    {
        cur->next = new ListNode<T>(v[i]);
        cur=cur->next;
    }
    return head;
}
template <typename T>
void print(ListNode<T> *head)
{
    std::cout << "[";
    while(head)
    {
        if(head->next)
            std::cout << head->val << " ";
        else
            std::cout << head->val;
        head=head->next;
    }
    std::cout << "]" << std::endl;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



#endif