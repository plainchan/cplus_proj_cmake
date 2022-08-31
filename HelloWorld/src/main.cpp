#include "tool.hpp"
using namespace std;

class Solution
{

};


int main()
{
    Solution s;

    cout << "Hello World" << endl;
}






















// 399. 除法求值

// 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。

// 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

// 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。

// 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。

 

// 示例 1：

// 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
// 解释：
// 条件：a / b = 2.0, b / c = 3.0
// 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
// 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]

// 示例 2：

// 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// 输出：[3.75000,0.40000,5.00000,0.20000]

// 示例 3：

// 输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// 输出：[0.50000,2.00000,-1.00000,-1.00000]

 

// 提示：

//     1 <= equations.length <= 20
//     equations[i].length == 2
//     1 <= Ai.length, Bi.length <= 5
//     values.length == equations.length
//     0.0 < values[i] <= 20.0
//     1 <= queries.length <= 20
//     queries[i].length == 2
//     1 <= Cj.length, Dj.length <= 5
//     Ai, Bi, Cj, Dj 由小写英文字母与数字组成

// 通过次数57,761
// 提交次数97,410

// class Solution {
// public:
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

//     }
// };


// 207. 课程表

// 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，
// 其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

//     例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。

// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

 

// 示例 1：

// 输入：numCourses = 2, prerequisites = [[1,0]]
// 输出：true
// 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。

// 示例 2：

// 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
// 输出：false
// 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。

 

// 提示：

//     1 <= numCourses <= 105
//     0 <= prerequisites.length <= 5000
//     prerequisites[i].length == 2
//     0 <= ai, bi < numCourses
//     prerequisites[i] 中的所有课程对 互不相同

// 通过次数218,352
// 提交次数405,138


// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

//     }
// };




// 238. 除自身以外数组的乘积

// 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

// 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

 

// 示例 1:

// 输入: nums = [1,2,3,4]
// 输出: [24,12,8,6]

// 示例 2:

// 输入: nums = [-1,1,0,-3,3]
// 输出: [0,0,9,0,0]

 

// 提示：

//     2 <= nums.length <= 105
//     -30 <= nums[i] <= 30
//     保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内

 

// 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {

//     }
// };


// 208. 实现 Trie (前缀树)

// Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

// 请你实现 Trie 类：

//     Trie() 初始化前缀树对象。
//     void insert(String word) 向前缀树中插入字符串 word 。
//     boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
//     boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。

 


// 1873. 计算特殊奖金
// SQL架构

// 表: Employees

// +-------------+---------+
// | 列名        | 类型     |
// +-------------+---------+
// | employee_id | int     |
// | name        | varchar |
// | salary      | int     |
// +-------------+---------+
// employee_id 是这个表的主键。
// 此表的每一行给出了雇员id ，名字和薪水。

 

// 写出一个SQL 查询语句，计算每个雇员的奖金。如果一个雇员的id是奇数并且他的名字不是以'M'开头，那么他的奖金是他工资的100%，否则奖金为0。

// Return the result table ordered by employee_id.

// 返回的结果集请按照employee_id排序。

// 查询结果格式如下面的例子所示。

 

// 示例 1:

// 输入：
// Employees 表:
// +-------------+---------+--------+
// | employee_id | name    | salary |
// +-------------+---------+--------+
// | 2           | Meir    | 3000   |
// | 3           | Michael | 3800   |
// | 7           | Addilyn | 7400   |
// | 8           | Juan    | 6100   |
// | 9           | Kannon  | 7700   |
// +-------------+---------+--------+
// 输出：
// +-------------+-------+
// | employee_id | bonus |
// +-------------+-------+
// | 2           | 0     |
// | 3           | 0     |
// | 7           | 7400  |
// | 8           | 0     |
// | 9           | 7700  |
// +-------------+-------+
// 解释：
// 因为雇员id是偶数，所以雇员id 是2和8的两个雇员得到的奖金是0。
// 雇员id为3的因为他的名字以'M'开头，所以，奖金是0。
// 其他的雇员得到了百分之百的奖金。
