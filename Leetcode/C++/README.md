[TOC]

## 算法

### 框架思想
#### 并查集

```c++
class UF {
    // 记录连通分量个数
    private int count;
    // 存储若干棵树
    private int[] parent;
    // 记录树的“重量”
    private int[] size;

    public UF(int n) {
        this.count = n;
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    /* 将 p 和 q 连通 */
    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;

        // 小树接到大树下面，较平衡
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }

    /* 判断 p 和 q 是否互相连通 */
    public boolean connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        // 处于同一棵树上的节点，相互连通
        return rootP == rootQ;
    }

    /* 返回节点 x 的根节点 */
    private int find(int x) {
        while (parent[x] != x) {
            // 进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    public int count() {
        return count;
    }
}
```
算法的关键点有 3 个：
1、用 parent 数组记录每个节点的父节点，相当于指向父节点的指针，所以 parent 数组内实际存储着一个森林（若干棵多叉树）。
2、用 size 数组记录着每棵树的重量，目的是让 union 后树依然拥有平衡性，而不会退化成链表，影响操作效率。
3、在 find 函数中进行路径压缩，保证任意树的高度保持在常数，使得 union 和 connected API 时间复杂度为 O(1)。
#### 动态规划
>遇事不决，动态规划；一维不行，二维来凑。
>万物皆可动态规划

三步 https://juejin.im/post/5dcb8201e51d45210f046f5a

what is dp[i] stand for?  
  * 因为是一次遍历，所以定义要具有方向性（累计前面（1维：左；2维：上）的 个数/值）
  * 每个 dp[i] 对应的意义管好自己的最 大/小
  * 动中找定
  * 表的作用层次
  1. 仅 dp[i-1] -> 贪心
  2. 确定个数（>= 2）个 dp[j], j = i-1, i-2, ... -> 动态规划
  3. 不确定个数个 -> always: 里面加个 for || 换方法

how dp[i] transfer?

boardary conditions.
 * 最后考虑

#### 双指针
##### 对撞指针
有序数组，优先想到

##### 快慢指针
速度-->比例关系->循环链表、中位数

距离/条件(先后指针/滑动窗口)-->长度关系->倒数k位

##### 滑动窗口
unordered_map / unordered_set 存窗口里的东东
**窗口大小可变**
```c++
int left = 0, right = 0;
// 消减时间复杂度，可提前判断窗口是否溢出
// right, left 看情况定
while (right < s.size()) {`
    // 增大窗口
    window.add(s[right]);
    right++;

    while (window needs shrink) {
        // 缩小窗口
        window.remove(s[left]);
        left++;
    }
}
```
**窗口大小固定**

```cpp
 for (int i = 0; i < n; i++) {
        ........
        set.add((long) nums[i]);
        if (i >= k) {
            set.remove((long)nums[i - k]);
        }
    }
```
#### Floyd 判圈算法
快慢指针 && 对撞指针。找交叉点

#### 回溯算法--递归
https://www.cxyxiaowu.com/7103.html
```python
result = []
def backtrack(路径, 选择列表/当前下标/可用于剪枝的参数):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表/当前下标/可用于剪枝的参数)
        撤销选择
```
决策树
全排列

#### 单调栈
https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/dan-tiao-zhan
左/右 边第一个 大/小 于
> 右边第一个大于 == 左边第一个小于

```c++
stack<int> st;
for(int i = 0; i < nums.size(); i++)
{
	while(!st.empty() && st.top() >= nums[i]){
		st.pop();
	}
  a[i] = (s.empty() ? boundary_conditions : st.top());
	st.push(nums[i]);
}

```

#### 图的遍历
##### BFS--非递归
hash -- visited // 记录访问历史，避免重复访问
queue -- q      // core
//初始化：q.push(...)与visited.add(...)当作一个操作
q.push(...) & visited.add(...)
while(!q.empty()){
  tmp = q.poll()
  ...
  for(x:tmp.adj){  // 遍历队列头结点的相邻结点，并把新的结点加入队列
    if(x not in visited){
      q.push(...) & visited.add(...)
    }
  }
}

```c++
// LeetCode: 113 克隆图
unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        visited[node] = new Node(node->val);
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for(auto x:cur->neighbors){
                if(visited.count(x) == 0){
                    visited[x] = new Node(x->val);
                    q.push(x);
                }
                visited[cur]->neighbors.push_back(visited[x]);
            }  
        }
```
#### 二分查找
**思路很简单，细节是魔鬼**
一、寻找一个数（基本的二分搜索）
区间为[left, right]; <, >, ==, 分开讨论，全写 else if, 宁滥勿缺。

right = nums.length - 1 <==> while left <= right

left = mid + 1 <==> if not left >= nums.length
```c++
int binarySearch(int[] nums, int target) {
    int left = 0, right = ...;

    while(...) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ...
        } else if (nums[mid] < target) {
            left = ...
        } else if (nums[mid] > target) {
            right = ...
        }
    }
    return ...;
}
```

二、寻找左/右侧边界的二分搜索
分开讨论，左：
```java
int left_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    // 搜索区间为 [left, right]
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            // 搜索区间变为 [mid+1, right]
            left = mid + 1; // 与 left >= nums.length 对应
        } else if (nums[mid] > target) {
            // 搜索区间变为 [left, mid-1]
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 收缩右侧边界
            right = mid - 1;
        }
    }
    // 检查出界情况
    //-right + left = 1 时停止，此时right过了，left是终止时候的情况。
    if (left >= nums.length || nums[left] != target)
        return -1;
    return left;
}
```
#### 前缀和
```c++
int subarraySum(int[] nums, int k) {
    int n = nums.length;
    // map：前缀和 -> 该前缀和出现的次数
    HashMap<Integer, Integer> 
        preSum = new HashMap<>();
    // base case
    preSum.put(0, 1);

    int ans = 0, sum0_i = 0;
    for (int i = 0; i < n; i++) {
        sum0_i += nums[i];
        // 这是我们想找的前缀和 nums[0..j]
        int sum0_j = sum0_i - k;
        // 如果前面有这个前缀和，则直接更新答案
        if (preSum.containsKey(sum0_j))
            ans += preSum.get(sum0_j);
        // 把前缀和 nums[0..i] 加入并记录出现次数
        preSum.put(sum0_i, 
            preSum.getOrDefault(sum0_i, 0) + 1);
    }
    return ans;
}
```

#### 自动机

1. 画图，初步确定状态，框架。
2. 列表，精确确定状态，unordered_map<string, vector<string>> 存好
3. 写一个根据输入返回位置的函数，e.g. int s_to_i(input_value)
4. 设计其它函数注意优先选择：先转移，后改变累计值，即把函数写在 status = status_trans[status][s_to_i(i)] 后面
## STL
### 速记
#### queue
empty // Test whether container is empty (public member function )
size  // Return size (public member function )
front // Access next element (public member function )
back  // Access last element (public member function )
push  // Insert element (public member function )
emplace // Construct and insert element (public member function )
pop // Remove next element (public member function )
swap // Swap contents (public member function )

### 数学
#### 分析法/由果推因 -- 递归
映射关系 -> 递归式 -> 换元 e.g. 约瑟夫环
#### 通项式推导

#### deque
a.push_front(0);//在头部加入数据0
a.push_back(11);//在尾部加入数据11
a.pop_front();//在头部删除数据
a.pop_back();//在尾部删除数据
a.resize(num);//重新指定队列的长度
a.size() //返回容器中实际数据个数
a.max_size() //返回容器中最大数据的数量
#### vector
clear()清空
resize()改变大小
push_back()在尾部添加元素
pop_back()在尾部删除元素
empty()测试是否为空
#### string
begin // Return iterator to beginning
end // Return iterator to end
size // Return length of string
resize // Resize string
clear // Clear string
empty // Test if string is empty
at // Get character in string
back // Access last character
front // Access first character
operator += // Append to string
append // Append to string
push_back // Append character to string
pop_back // Delete last character
find // Find content in string. Return the position of the first character of the first match. If no matches were found, the function returns string::npos.
substr // Generate substring
#### map / multimap
begin() – Returns an iterator to the first element in the map
end() – Returns an iterator to the theoretical element that follows last element in the map
size() – Returns the number of elements in the map
max_size() – Returns the maximum number of elements that the map can hold
empty() – Returns whether the map is empty
pair insert(keyvalue, mapvalue) – Adds a new element to the map
erase(iterator position) – Removes the element at the position pointed by the iterator  // first, second 访问 key, value
erase(const g)– Removes the key value ‘g’ from the map
clear() – Removes all the elements from the map

#### list
Normally, when we say a List, we talk about doubly linked list.
front() – Returns the value of the first element in the list.
back() – Returns the value of the last element in the list .
push_front(g) – Adds a new element ‘g’ at the beginning of the list .
push_back(g) – Adds a new element ‘g’ at the end of the list.
pop_front() – Removes the first element of the list, and reduces size of the list by 1.
pop_back() – Removes the last element of the list, and reduces size of the list by 1
list::begin() and list::end() in C++ STL– begin() function returns an iterator pointing to the first element of the list
end()– end() function returns an iterator pointing to the theoretical last element which follows the last element.
list rbegin() and rend() function in C++ STL– rbegin() returns a reverse iterator which points to the last element of the list. rend() returns a reverse iterator which points to the position before the beginning of the list.
empty() – Returns whether the list is empty(1) or not(0).
insert() – Inserts new elements in the list before the element at a specified position.
erase() – Removes a single element or a range of elements from the list.
reverse() – Reverses the list.
size() – Returns the number of elements in the list.
sort() – Sorts the list in increasing order.
list::clear() in C++ STL– clear() function is used to remove all the elements of the list container, thus making it size 0.
#### 输入
##### getline(...)
in Windows a newline is represented as CR + LF which is: "\r\n" and in Unix it is LF which is just "\n"
* \r is a carriage return character; it tells your terminal emulator to move the cursor at the start of the line. The cursor is the position where the next characters will be rendered. So, printing a \r allows to override the current line of the terminal emulator.
* std::getline(...) command is reading till the "\n"
* 空白字符: '\r', '\n', '\t', '\v', '\f', ' '
getline is a function while cin is an object.
```c++
string S, T;
getline(cin, S);
stringstream X(S);
while (getline(X, T, ' ')) {  //类型为 stringstream 的 X 以 ' ' 为界分割成一段段，返回的是指向 T 的指针，最后指向 NULL。一段段的值为 T 
    cout << T << endl;
}
```
X.clear() // to clear the stream
X.str()  // to get and set string object whose content is present in stream.

#### 容器
>排列：最基本 > 复杂 > 基本 > 偶尔

>[]为类型，()为可选，pi为默认，其它类型直接英文名

```c++
//vector
std::vector<[data_type]> v; // 声明 (+ 初始化) v(data_length, data_value)
vector<vector<int>> v(m ,vector<int>(n,0));  //初始化二维数组，m*nr，所有元素为0  

.push_back(p1) // 在尾部插入元素
.pop_back(p1) // 在尾部删除元素

.clear()  // 清空
.empty()  // 是否为空

.erase(iterator_position) // e.g. iterator_position = 2, delete index 为 2 的...
.erase(iterator_start_position, iterator_end_position_NotIncluded)
  // e.g. iterator_position = v.begin() + 2

.resize(size) // 改变大小
//vector
*******************************************************************************
//string
// <cstring>
std::string string_name(char_length, char_type) // convert char to string
std_string_type.push_back(char_type)
std_string_type.append(char_length, char_type)
std_string_type.append(string_type)
std_string_type += char_type

.substr(start_index, length)  // 取子字符串

memset(start_point, value, length) //按字节填充 e.g.
  int a[20];
      memset(a, 0, sizeof a); // (sizeof a) == 20*4

sizeof(data_type/variable) //e.g.
  #define ARR_LEN(array, length){length = sizeof(array)/sizeof(array[0]);}
  int arr[] = {1,2,3,4,5}; int len;
  ARR_LEN(arr, len); cout<<len;


.data() // 返回指向 array 类型的指针 e.g.
  const char* p = string_type.data();

 .pop_back()  // delete the last character from the string.
 .push_back() // input a character at the end of the string

  // 输入
string str;
getline(cin,str);//可以输出空格，回车停止
// cin>>str;//输出到空格停止
cout<<str<<endl;

//string
*******************************************************************************
//algorithm
sort()

pow(底数, 指数) // just like max/min, + std::


fill(iterator_or_address_begin, iterator_or_address_end, value) //按单元赋值 e.g.
  int arr[10];
      fill(arr, arr + 10, 2);
  vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
      fill(v.begin(), v.end(), -1);
//algorithm

//deque
deque<int> a; // 定义一个int类型的双端队列a
deque<int> a(10); // 定义一个int类型的双端队列a，并设置初始大小为10
deque<int> a(10, 1); // 定义一个int类型的双端队列a，并设置初始大小为10且初始值都为1
deque<int> b(a); // 定义并用双端队列a初始化双端队列b
deque<int> b(a.begin(), a.begin()+3); // 将双端队列a中从第0个到第2个(共3个)作为双端队列b的初始值
int n[] = { 1, 2, 3, 4, 5 };
deque<int> a(n, n + 5);   // 将数组n的前5个元素作为双端队列a的初值
deque<int> a(&n[1], &n[4]); // 将n[1]、n[2]、n[3]作为双端队列a的初值

.(push/pop)_(back/front)()

deque<int> deq;
deque<int>::iterator it = deq.begin(); // 任意位置删除一个元素
deq.erase(it);
deq.erase(deq.begin(), deq.end()+1);	// 删除[first,last]之间的元素

下标访问：deq[1]; // 并不会检查是否越界
at 方法访问：deq.at(1); // 以上两者的区别就是 at 会检查是否越界，是则抛出 out of range 异常
访问第一个元素：deq.front();
访问最后一个元素：deq.back();

//deque

//unordered_set  --hash 无序
insert
erase



//map  --红黑 有序 无重复 //multimap --+ 可重复
map <int, int> m1;
m1.insert ( pair <int, int>  ( 1, 10 ) );
map <int, int>::iterator m1_Iter;
for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " " << m1_Iter->second;
// 如果已经存在键值2015，则会作赋值修改操作，如果没有则插入
ID_Name[2015] = "Tom";

//map



//unordered_map  --hash 无序 无重复
unordered_map<string, double> umap;
umap["PI"] = 3.14;  // inserting values by using [] operator
umap.insert(make_pair("e", 2.718)); // inserting value by insert function

if (umap.find(key) == umap.end()) // If key not found in map iterator to end is returned
        cout << key << " not found\n\n";
else  // If key found then iterator to that key is returned
        cout << "Found " << key << "\n\n";
/////////////////////////////////////////////////////////
map<int,int> emptyMap{};
int i = emptyMap[100]; // i = 0
////////////////////////////////////////////////////////
struct IntDefaultedToOne {
		int num = 1;
	};
map<int,IntDefaultToOne> emptyMap{};
int i = map[0].num; // i = 1
//////////////////////////////////////////////////////////
//unordered_map

//set --RB-Tree 有序 无重复 // multiset --+ 可重复
.count() //The set::count() is a built-in function in C++ STL which returns the number of times an element occurs in the set. It can only return 1 or 0 as the set container contains unique elements only.
//set

//stack
若为空，.top() 会有地址错误
top()
push()
pop()
size()
empty()
//stack

//常用方法
  //copy
set<vector<int>> mr;
vector<vector<int>> result;
std::copy(mr.begin(), mr.end(), std::back_inserter(result));

  //initalize & iterator option
vector<int> v = {-1,-3,4,1,3,0};
for(auto i = v.begin(); i < v.end(); i++){
  cout<<*i<<" ";
}

  //结构体 delete
CoordLocation *coord = new CoordLocation();
delete coord;

// pair  <utility>  
pair <string,double> PAIR2 ("GeeksForGeeks", 1.23);
pair <int, char> PAIR1 ={100, 'G'};
pair <string, double> PAIR3 ;

//常用方法
  // next_permutation, prev_permutation
    // 若有下一个， 返回 true. 迭代器，指针移动。
   string getPermutation(int n, int k) {
        string s = string("123456789").substr(0,n);
        for(int j = 1; j < k; ++j) next_permutation(s.begin(), s.end());
        return s;
    }

  // reverse
    // Reversing elements from index 5 to index 7
      reverse(v.begin() + 5, v.begin() + 8);

  // to_string
    // Converting float to string
    std::string str1 = std::to_string(12.10);  // 12.100000
    // Converting integer to string
    std::string str2 = std::to_string(9999);   // 9999

  // convert string to int
  int_type = std::stoi(string_type)
  
  // memset: memory set
	char str[] = "geeksforgeeks"; 
    memset(str, 't', sizeof(str)); //tttttttttttttt
```

## object-oriented
```c++
  class Foo{ // 首字母大写
  public:
    int first, second;
    Foo(int a, int b){
      first = a;
      second = b;
    };

  Pair* b = new Pair(0,0);
  vector<vector<Pair>> vv(n, vector<Pair>(m, Pair(0,0)));
  }

```

## 常识

* 边界条件复杂，统一用闭区间(>=0&<=size-1 && 回溯|DFS 提前判断)

* [std::][2] C++ 的，为指定变量/方法的命名空间，若不加，可在开头指定 using namespace std。在头文件中引入名称空间不是一个好习惯。
* LeetCode 报错 https://zhang0peter.com/2019/03/24/LeetCode/
* delete 结构体：删除/释放 结构体地址后，原本指向这个结构体的指针指向 NULL
为 NULL 与指向 NULL 不是一回事，指向 NULL 返回的是地址。nullptr是一个对象/一个类，是一个新关键字，可以（并且应该！）用于表示NULL指针。。可以在NULL以前使用过的任何地方使用它
* 迭代器，只支持自增、自减操作。
for(auto i:m) i.first;
auto i = m.begin(); i->first;
![](https://img-blog.csdn.net/20150210102640981?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvamlhbmdxaW4xMTU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)
```c++
char s[] = "hello"; s[0] = 'e' s[1] = 'l'  
char* s =(char *)"adgf"; // *(s+1) == d
```
* size_t: Alias of one of the fundamental unsigned integer types. xxx.size()的返回值类型，不可与 int 类型运算
* int type 的值赋值给 long type, long 被转为int. 应该将int类型的值强制转为long. e.g. long l = (long) INT_MIN;
* c_str()（string_tyoe_value.c_str() ）函数返回一个指向正规C字符串的指针常量(const char*)，内容与本string串相同。这是为了与C语言兼容，在C语言中没有string类型，故必须通过string类对象的成员函数c_str()把string对象转换成C中的字符串样式。
* static 声明的全局变量的值只能在本文件中可以使用，但是extern声明的全局变量的值可以跨文件访问。
* 引用在声明引用的同时就要对它初始化，引用一经声明，就不可以再和其它对象绑定在一起了，一定不为空，可以把引用看做是通过一个常量指针来实现的，可以把引用理解成变量的别名；指针可以多次赋值。
* C++多态(polymorphism)是通过虚函数来实现的，虚函数允许子类重新定义成员函数，而子类重新定义父类的做法称为覆盖(override)，或者称为重写。纯虚函数是在基类中声明的虚函数，它在基类中没有定义，但要求任何派生类都要定义自己的实现方法。包含纯虚函数的类称为抽象类。由于抽象类包含了没有定义的纯虚函数，所以不能定义抽象类的对象。抽象类的主要作用是将有关的操作作为结果接口组织在一个继承层次结构中，由它来为派生类提供一个公共的根，派生类将具体实现在其基类中作为接口的操作。虚函数的作用是允许在派生类中重新定义与基类同名的函数，并且可以通过基类指针或引用来访问基类和派生类中的同名函数。
虚函数是C++中用于实现多态的机制。核心理念就是通过基类访问派生类定义的函数。虚函数 是在基类中使用关键字 virtual 声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态链接，或后期绑定。
* 构成多态的条件：
  必须存在继承关系；
  继承关系中必须有同名的虚函数，并且它们是遮蔽（覆盖）关系。
  存在基类的指针，通过该指针调用虚函数。
* 如果两个map键和对应的值都相等，直接用 == 比较返回的值为true
* set::upper_bound返回的是小于等于目标元素的最大元素的后一个元素（即大于目标元素的最小元素），所以对返回的迭代器进行自减操作，得小于等于目标元素的最大元素。所以要先判断 it != set::begin()。(*--set::upper_bound) 和(*set::lower_bound)是镜像操作。可进行范围的上下限判断。
* static_cast<int>(x) -- C++               （int）x -- C

```c++
// = 0 告诉编译器，函数没有主体，上面的虚函数是纯虚函数。
      virtual int area() = 0;
```

* 迭代器前加个'*'可以访问其指向的元素，e.g. *v.begin()
* 本质来说，NULL，0，'\0'都是一样的，都是值0。但是含义却是不一样的。

## Better
### Lambda
[ capture clause ] (parameters) -> return-type { definition of method }
```c++
  vector<int> v = {5, 2, 1, 4, 3};
  vector<size_t> index(v.size());
  iota(index.begin(), index.end(), 0); //#include <numeric> // initialize original index locations
  sort(index.begin(), index.end(), [&v](size_t a, size_t b) {return v[a] < v[b];});
  for (auto i: index) cout << i <<" "<< v[i] << endl;
```
You can capture by both reference and value, which you can specify using & and = respectively:

[&epsilon] capture by reference
[&] captures all variables used in the lambda by reference
[=] captures all variables used in the lambda by value
[&, epsilon] captures variables like with [&], but epsilon by value
[=, &epsilon] captures variables like with [=], but epsilon by reference

## 基本
实现 链表，树等基本数据结构

```c++
switch (n)
{
    case 1: // code to be executed if n = 1;
        break;
    case 2: // code to be executed if n = 2;
        break;
    default: // code to be executed if n doesn't match any cases
}
```

long long bignum = [>2^31-1]LL  %lld  &n32位/10^9  int                   %d  &n10^18/64位  long long
float 6~7位有效精度       %f &fldouble 15~16位有效精度   %lf（scanf ） &db     %f（printf）

printf格式输出：%[flags][width][.perc][F|N|h|l]type
用到了flags中的 0 （注意是零不是欧） ，其百科描述为：将输出的前面补上0，直到占满指定列宽为止（不可以搭配使用-）
width 即表示需要输出的位数。
```c++
int a = 4; printf("%03d", a); // output: 004
```

大写字母 + 32 = 小写字母
\n 换行\0 空字符 NULL
char '' %c 仅单个          &cstring "" %s             (或char数组)str 【不用&】# include <string>   + 连接字符串                   <> 比较ASCII码，返回bool型
%.1f 保留一位小数
\#define CAL(x) (x * 2 + 1)CAL(a + 1)a + 1 * 2 + 1
/除法     %取模
逻辑 && || !位   a<<x   a>>y  a&b  a|b  a^b  ~a     左移x                   异或  非
A ？B : C  A真执行返回B，。。。 
scanf  按指定格式输入（）%c可以输入 【空格】【换行】     其它：输入自动跳过空格换行（都为结束判断标志）
输出%或\，前面加%或\
在程序中，局部变量和全局变量的名称可以相同，但是在函数内，局部变量的值会覆盖全局变量的值。

## 之后的方向
模板
宏
重载

http://www.cplusplus.com/reference/algorithm/find/