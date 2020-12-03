## 运行效率问题
vector  <  预先reserve的vector  <<  动态数组  <  数组

**vector:** 动态自增加，影响效率。

**预先reserve的vector:** v.reserve(n+1); -> only allocates memory, but leaves it uninitialized. Change capacity but not size.

**动态数组:** int  *p=new int[n+1]; p[i]=i; delete []p;

**数组:** int  a[n]; a[i]=i;
## 输入规范总结
### PAT
#### 特色
顺序友好输入 -> 输入由次数已知的循环输入，一\n\t
变量长度固定 -> 优先选择数组
时间限制宽松 -> 模拟面试，考试用。敏捷开发 :)
英语单词积累 -> 常背下面的单词
链表什么的   -> 用 vector 存储
#### 基础
scanf("%d%f", &t, &num); //遇空白字符结束
// 复习evernote

#### 易遗忘
sort(,,cmp)
前两个参数：地址（数组指针/迭代器）
cmp: 数组/容器 中的元素类型，两个，比较，<, ascending
 * 明确：要排什么/排序的规则，排了以后改变什么/排序的对象。
```c++
bool cmp(pair<int, int> a, pair<int, int> b){
  return a.first < b.first || (a.first == b.first && a.second > b.second);
}
vector<pair<int, int>> v;
v.reserve(10);
sort(v.begin(), v.end(), cmp);
for(auto i:v) cout<<i.first<<" "<<i.second<<endl;
```


## 单词
>remember, delete

```
guaranteed      肯定
permutation     排列
polynomials     多项式
nonzero terms   非零项
exponents   *    指数  
coefficients *   系数
test case 		测试用例
digits 			位数
occupies 		占用
accurate 		准确的
accurate up to 
  2 decimal places 精确到小数后2位
decimal 		小数的； 十进制的
scattered 		分散的
call up 	*	打电话召集
positive integers 正整数
currently 		当前的
respectively  *	分别的； 独自的
hierarchy 		层级
sequence 		序列； 顺序； 按顺序排列
sake 			目的
simplicity 		简化； 简易
negative integer 负整数
continuous 		连续的
specified 		规定的
product 		乘积
odds 			几率
odd 			奇数
even 			偶数
profit 			利润； 获利
distinct 		明显的； 独特的； 有区别的
corresponding 	相应的
evaluate 		评估
emphasizing 	强调
priorities 		优先顺序
fractional portion	小数部分
integer portion 	整数部分
radix 				进制； 基数
priority 			优先级
processing 			加工； 处理； 运算
suppose 			假设
be supposed to 		应该
capacity 			能力； 容量； 资格
queries 			询问
reversible 			可逆的
primes 				素数
consists of 		由....组成
determined by 		由....决定
rate 				比率； 速度； 价格； 等级
structure 			结构； 构造； 组织； 构成
denote/denoting 	表示； 意味着
toll 	*			通行费； 代价
string of up to 20 characters 最多20个字符的字符串
chronologically 	按时间顺序
alphabetical 		按字母顺序
queueing 			排队
monitoring 			监控；检验
figure 				数字； 人物； 图形； 计算
vertex/vertices 	顶点
traversal 			遍历
binary tree 		二叉树
preorder 			前序
inorder 			中序
postorder 			后序
level order 		层序
general 			全体的； 普遍的； 一般的
palindromic number		回文数
numeral 			数字； 数字的
notation 			符号； 注释
simultaneously 		同时地
merge 				合并
registration 		登记； 注册
testee 				测验对象
nonincreasing 		非递增
nondecreasing 		非递减
assign 				分配；指派
privilege 			特权；
ordinary 			普通的
median 				中位数； 中间的
elements 			元素； 原理； 成分
bottom 				底部； 末端
alphabetical order		字母顺序
generate 			使…形成
lowercase 			小写的
segment 			片段
registered 			注册的； 记名的； 登记过的
capital 			大写的（字母）
symmetric 			对称的
inadequate 			不充分的
recursively 		递归的
sufficient 			足够的
minimized 			最小化的
maximized 			最大化的
subtraction 		减法
structures 			结构
adjacent 			邻近的
pointer 			指针
proportional 		成比例的； 均衡的
resolution 			分辨率
simulate 			模仿
submits 			提交
initial 			最初的； 字首的
invalid 			无效的
qualification 		资格；条件； 限制
similarity 			相似度
illustrate 			举例说明；图解
rotation 			旋转
patterns 			模式
validating 			确认
candidate 			候选的
scientific notation 科学计数法
conventional 		传统的
absolute 			绝对的；完全的
trailing zeros 		后导零
indirect 			间接的
suffix *			后缀； 词尾
quadratic probing 	二次探测法
exceed 				超过
proceed 			开始； 继续进行； 发生
applicants 			申请人
rational 			有理数； 合理的
numerators 			分子
denominators 		分母
boundaries 			边界；界线
interval 			间隔
implement 			实施； 执行
quotient 			商； 系数
pixels 				像素
threshold 			入口； 门槛； 临界值
regions 			地区； 地域
pedigree *			家谱
ascending 			上升的； 增长的
consecutive *		连贯的
factored *			因式分解
factorization 		因式分解
deduplication 		去重
mutual 				共同的； 相互的
partition 			划分
pivot 				以…为中心
invert 				使…反转
spiral 				螺旋
clusters 			群集
rear 				后面； 后面的
current 			现在的； 通用的； 最近的
intersections 		交集
union 				并集
hamiltonian cycle 	哈密顿环
eulerian path 		欧拉路径
configuration 		配置；结构；外形
infix expression 	中缀表达式
prefix 				前缀
postfix 			后缀
parenthesis/parentheses 插入语； 圆括号
reflecting 			反射的
precedences 		优先级
symbols 			符号；象征；标志
conjunction *		结合；
transfers 			传输； 转移
split 				分裂； 分解
rearrange 			重新排列
grade/grading 		评分； 分等级
certificate 		合格证书； 文凭
qualified 			合格的；有资格的
contact 			联系；接触
analogous	*	 	类似的
gender 				性别
total weighted score 总加权分数
institutions		 体系；制度； 院校
increments 			增量
topological order 	拓补排序
specialized 		专业的； 专门的
incompatible 		不相容的
compatible 			相容的
descendants 		后代； 子节点
statistics 			统计； 统计学
label 				标签； 标记； 标号
lower bound 		下界
upper bound 		上界
```


#### from [liuchuo][1]
```txt
`	grave accent	重音符
~	tilde	/‘tɪldə/ 波浪符号
～	swung dash	代字号，swing 摇摆
!	exclamation point	/ˌɛksklə’meʃən/ 感叹号
@	at	在…
#	① pound ②number	① 井号 ② …号
$	dollar	美元符号
%	per cent	百分比
^	caret	插入符号
…	ellipsis points	/ɪ’lɪpsɪs/ 省略号
&	ampersand = and	和
*	asterisk	/‘æstərɪsk/ 星号
( )	① parenthesis ② round brackets	/pə’rɛnθəsɪs/ 圆括号，复数parentheses
–	① hyphen ② minus	① /‘haɪfn/ 连字号 ② 减号
——	dash	破折号
_	underline	下划线
=	is equal to	等于号
[ ]	square brackets	方括号
{ }	curly brackets	花括号，大括号
\	backslash	反斜杠
|	vertical bar，vertical virgule	竖线
||	parallel	双线号
;	semicolon	分号
:	colon	冒号
‘’	quotation mark	引号
“”	double quotation mark	双引号

apostrophe	/ə’pɑstrəfi/ 撇号
,	comma	逗号
<>	angle brackets	尖括号
<	is less than	小于号
>	is greater than	大于号
《》	French quotes	书名号；法文符号
.	period，full stop，dot	句号
/	① slash ② virgule	① 斜线 ② /‘vɝgjʊl/ 置于二字之间表示任取一字均可的短斜线
//	① slash-slash ② comment	① 双斜线 ② 注释符
?	question mark	问号
∵	since，because	因为
∴	hence，therefore	因此，所以
√	square root	平方根
∞	infinity	/ɪn’fɪnəti/ 无穷号
℃	Celsius system	/‘selsiəs/ 摄氏度
⊥	perpendicular to	垂直于
∩	intersection of	交集
∪	union of	并集
∑	summation of	总和
≡	is equivalent to	全等于号
≌	Is congruent to	全等号
≈	is approximately equal to	约等于号
~	Is similar to	相似
±	plus or minus	正负号
x	is multiplied by	乘号
÷	is divided by	除号
≠	is not equal to	不等于号
→	arrow	箭头
§	section，division	分节号
○	circumference	圆周
∷	equals，as	等于，成比例
‰	per mill	千分比
°	degree	度
≥	greater than or equal to	大于等于号
≤	less than or equal to	小于等于号
—	division / fraction	分号
mod	modulo	模运算符
Δ	① triangle ② Delta	① 三角符号 ② 第四个希腊字母Delta
≪	much less than	远小于
≫	much greater than	远大于
n!	factorial	阶乘号
```


### 牛客
* input: 只给下面一行(无视个数)
  2 1 2 2 3
```c++
string line;
getline(cin, line);
float len = line.size();
int size = ceil(len/2), ii = 0, i;
int a[size];
istringstream tmp(line); // #include<sstream>
vector<int> v;
while (tmp>>i) {
  v.push_back(i);
  a[ii++] = i;
}
```
```c++
int i;
string line;
getline(cin, line);
istringstream tmp(line); // #include<sstream>
vector<int> v;
while (tmp>>i) {
  v.push_back(i);
}
```

* 预先不输入数据的组数
Sample Input 
1 5 
10 20
400 516
```c++
while (cin>>a>>b) {
  cout<<a+b<<endl;
}

// 读到空白符结束
scanf cin

// 带空白符
gets  cin.getline
```




## 输出格式问题



[1]:https://www.liuchuo.net/archives/8564
[2]:http://c.biancheng.net/cpp/biancheng/view/2972.html
