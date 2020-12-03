>敏捷学习：语言先学基础的，频繁使用的，底层/需要理解 的。面试先背高频的，基础的，再慢慢深入。

>动态规划式学习：算法先学练框架，框架是现成的或经过自己归纳总结的，再滚动记忆。

## Java 集合框架
![](https://www.runoob.com/wp-content/uploads/2014/01/2243690-9cd9c896e0d512ed.gif)

## 基于 C++ 对 Java collection framework 基本数据结构的理解

### Integer
static String toString(int i) // convert int to string
static Integer valueOf(String s) // convert string to int

### Arrays
* Array can contains primitives (int, char, etc) as well as object (or non-primitives) references of a class depending on the definition of array. In case of primitives data types, the actual values are stored in contiguous memory locations.
```java
type[] var-name // general form of a one-dimensional array declaration  -- tells compiler type, only a reference of array is created
var-name = new type [size] // specific type of data being allocated
//in Java all arrays are dynamically allocated -- e.g.
int[] intArray = new int[20]	// clone -- deep copy

// multidimentional Arrays
// clone -- shallow copy -- it creates only a single new array with each element array a reference to an original element array but subarrays are shared.
int[][] intArray = new int[10][20]; //a 2D array or matrix
int[][][] intArray = new int[10][20][10]; //a 3D array
int arr[][] = { {2,7,9},{3,6,1},{7,4,2} }; 
```



### Character
boolean isLetter(char ch) -- This method is used to determine whether the specified char value(ch) is a letter or not. 

boolean isDigit(char ch) : This method is used to determine whether the specified char value(ch) is a digit or not.

boolean isWhitespace(char ch) : It determines whether the specified char value(ch) is white space

boolean isUpperCase(char ch) : It determines whether the specified char value(ch) is uppercase or not.

boolean isLowerCase(char ch) : It determines whether the specified char value(ch) is lowercase or not.

### ArrayList
* 数组；not synchronized

add(int index, Object element)	This method is used to insert a specific element at a specific position index in a list.

add(Object o)	This method is used to append a specific element to the end of a list.

clear()	This method is used to remove all the elements from any list.

<!-- clone()	This method is used to return a shallow copy of an ArrayList. -->

contains?(Object o)	Returns true(boolean) if this list contains the specified element.

isEmpty?()	Returns true if this list contains no elements

get?(int index)	Returns the element at the specified position in this list.

indexOf(Object O)	The index the first occurrence of a specific element is either returned, or -1 in case the element is not in the list.

set?(int index, E element)	Replaces the element at the specified position in this list with the specified element.

size?()	Returns the number of elements in this list.

toArray()	This method is used to return an array containing all of the elements in the list in the correct order.  converting ArrayList to Array

remove?(int index)	Removes the element at the specified position in this list.

remove?(Object o)	Removes the first occurrence of the specified element from this list, if it is present.
### LinkedList
* 链表；相当于C++中的list

peek()	This method retrieves, but does not remove, the head (first element) of this list.
peekFirst()	This method retrieves, but does not remove, the first element of this list, or returns null if this list is empty.
peekLast()	This method retrieves, but does not remove, the last element of this list, or returns null if this list is empty.
poll()	This method retrieves and removes the head (first element) of this list.
pollFirst()	This method retrieves and removes the first element of this list, or returns null if this list is empty.
pollLast()	This method retrieves and removes the last element of this list, or returns null if this list is empty.
offer(E e)	This method Adds the specified element as the tail (last element) of this list.
offerFirst(E e)	This method Inserts the specified element at the front of this list.
offerLast(E e)	This method Inserts the specified element at the end of this list.
clear()	This method removes all of the elements from this list.
clone()	This method returns a shallow copy of this LinkedList.
contains(Object o)	This method returns true if this list contains the specified element.

get(int index)	This method returns the element at the specified position in this list.
getFirst()	This method returns the first element in this list.
getLast()	This method returns the last element in this list.
indexOf(Object o)	This method returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element.
lastIndexOf(Object o)	This method returns the index of the last occurrence of the specified element in this list, or -1 if this list does not contain the element.

addFirst(E e)	This method Inserts the specified element at the beginning of this list.
addLast(E e)	This method Appends the specified element to the end of this list.

add(int index, E element)	This method Inserts the specified element at the specified position in this list.
add(E e)	This method Appends the specified element to the end of this list.

remove(int index)	This method removes the element at the specified position in this list.
remove(Object o)	This method removes the first occurrence of the specified element from this list, if it is present.
toArray()	This method returns an array containing all of the elements in this list in proper sequence (from first to last element).

### Vector
* Vector can use both Enumeration and Iterator for traversing

Vector(): Creates a default vector of initial capacity is 10.

Vector(int size): Creates a vector whose initial capacity is specified by size.

Vector(int size, int incr): Creates a vector whose initial capacity is specified by size and increment is specified by incr. It specifies the number of elements to allocate each time that a vector is resized upward.

Vector(Collection c): Creates a vector that contains the elements of collection c.

boolean add(Object obj): This method appends the specified element to the end of this vector.

void add(int index, Object obj): This method inserts the specified element at the specified position in this Vector.

boolean addAll(Collection c) This method appends all of the elements
in the specified Collection to the end of this Vector.

boolean addAll(int index, Collection c) This method inserts all of the elements in the specified Collection into this Vector at the specified.
position.

void clear() This method removes all of the elements from this vector

Object clone() This method returns a clone of this vector.

boolean contains(Object o): This method returns true if this vector contains the specified element.

void ensureCapacity(int minCapacity): This method increases the capacity of this vector, if necessary, to ensure that it can hold at least the number of components specified by the minimum capacity argument. // 相当于 C++ vector 中的 .reserve(int minCapacity)

Object get(int index):This method returns the element at the specified position in this Vector.

int indexOf(Object o): This method returns the index of the first occurrence of the specified element in this vector, or -1 if this vector does not contain the element.

int lastIndexOf(Object o): This method returns the index of the last occurrence of the specified element in this vector, or -1 if this vector does not contain the element

boolean remove(Object o): This method removes the first occurrence of the specified element in this Vector If the Vector does not contain the element, it is unchanged.

boolean isEmpty(): This method tests if this vector has no components

Object firstElement(): This method returns the first component (the item at index 0) of this vector.

String toString(): The toString() method is used to return a string representation of this Vector, containing the String representation of each element.

object[ ] toArray(): This method returns a array representation of this Vector, containing the String representation of each element.

void setElementAt(Object obj, int index): This method sets the component at the specified index of this vector to be the specified object.  // 参数位置和 set 相反
### HashMap
* hash table; no order(while **LinkedHashMap** preserves the insertion order); not synchronized (in contrast, **Hashtable** is synchronized)[if (at least one thread manipulates it structurally) {make it synchronized externally} else {wrap it around Collections.synchronizedMap() // Map m = Collections.synchronizedMap(new HashMap(...));}];  implements Cloneable and Serializable interface; doesn’t allow duplicate keys; fail-fast;

put
size
get

void clear(): Used to remove all mappings from a map.

boolean containsKey(Object key): Used to return True if for a specified key, mapping is present in the map.

boolean containsValue(Object value): Used to return true if one or more key is mapped to a specified value.

Object clone(): It is used to return a shallow copy of the mentioned hash map.

boolean isEmpty(): Used to check whether the map is empty or not. Returns true if the map is empty.

```java
HashMap<String, Integer> map = new HashMap<>();
map.put("key1", 89);  // Add elements to map
map.put("key2", 49);  
Integer a = map.get("key1");
map.containsKey("key1") // return true
```

### TreeMap
* red-black tree; ordered by key; not synchronized; [if (at least one thread manipulates it structurally) {make it synchronized externally} else {wrap it around Collections.synchronizedSortedMap () // Map m = Collections.synchronziedSet(new HashMap(...));}];

```Java
// Initialize


```


### HashSet
* hash table; no order(while **LinkedHashSet** provides insertion-ordered iteration); constant time performance for the basic operations (add, remove, contains and size); duplicate-free; not synchronized; alllow null object



### TreeSet
* guarantees log(n) time cost for the basic operations (add, remove and contains); sorted (ascending, natural, or the one specified by you via its constructor) (implements SortedSet); duplicate-free; not synchronized; doesn't alllow null object(because it uses compareTo() method to compare keys and compareTo() will throw java.lang.NullPointerException); [if (at least one thread manipulates it structurally) {make it synchronized externally} else {wrap it around Collections.synchronizedMap() // Map m = Collections.synchronziedSet(new HashMap(...));}];

clear()	The method removes all mappings from this TreeMap and clears the map.
clone()	The method returns a shallow copy of this TreeMap.
containsKey(Object key)	Returns true if this map contains a mapping for the specified key.
containsValue(Object value)	Returns true if this map maps one or more keys to the specified value.
entrySet()	Returns a set view of the mappings contained in this map.
firstKey()	Returns the first (lowest) key currently in this sorted map.
get(Object key)	Returns the value to which this map maps the specified key.

```Java
// initialize
TreeSet ts = new TreeSet(); // build an empty TreeSet object
TreeSet ts = new TreeSet(Comparator comp);  //  build an empty TreeSet object; external specificate sorting order.
TreeSet t = new TreeSet(Collection col);  // build a TreeSet object containing all the elements from the given collection


```

add()
contains()
first()   // get the first element
last()    // get the last element

add(Object o)	This method will add the specified element according to the same sorting order mentioned during the creation of the TreeSet. Duplicate entires will not get added.
addAll(Collection c)	This method will add all elements of specified Collection to the set. Elements in the Collection should be homogeneous otherwise ClassCastException will be thrown. Duplicate Entries of Collection will not be added to TreeSet.
ceiling?(E e)	This method returns the least element in this set greater than or equal to the given element, or null if there is no such element.
clear()	This method will remove all the elements.
clone()	The method is used to return a shallow copy of the set, which is just a simple copied set.
Comparator comparator()	This method will return Comparator used to sort elements in TreeSet or it will return null if default natural sorting order is used.
contains(Object o)	This method will return true if given element is present in TreeSet else it will return false.
descendingIterator?()	This method returns an iterator over the elements in this set in the descending order.
descendingSet?()	This method returns a reverse order view of the elements contained in this set.
first()	This method will return first element in TreeSet if TreeSet is not null else it will throw NoSuchElementException.

higher?(E e)	This method returns the least element in this set strictly greater than the given element, or null if there is no such element.
ceiling()

lower(val)   // find the value just smaller than the element 小于
floor?(E e)	// This method returns the greatest element in this set less than or equal to the given element, or null if there is no such element. 小于等于

pollFirst?()	This method retrieves and removes the first (lowest) element, or returns null if this set is empty.
pollLast?()	This method retrieves and removes the last (highest) element, or returns null if this set is empty.


### Math
sqrt
round
pow

### String
* 没有提供用于修改字符串的方法
* "Hello".equals(greeting)    // "==" 只能够确定两个字串是否放置在同一个位置上

String valueOf(boolean/char/char[]/char[] data, int offset, int count/double/long/float/Objsct) //  Return the string representation of XXX

substring
join   e.g. String all = String.join(" / ", "S", "M", "L", "XL"); // all is the string "S / H / L / XL"

charAt(i)		// 返回指定索引处的字符
String trim()	// Returns a copy of the string, with leading and trailing whitespace omitted.

int compareTo（Object o）// 将此字符串与另一个对象进行比较。

int indexOf（int ch）// 返回指定字符首次出现在此字符串中的索引。

可以使用静态的 String.format 方法创建一个格式化的字符串， 而不打印输出：
String message = String.format("Hello, %s. Next year , you'll be %d", name, age) ;
### StringBuider
* 避免每次连接字符串， 都会构建一个新的 String 对象   // e.g. 许多小段的字符串构建一个字符串

append(char/string)
toString    // 在需要构建字符串时就凋用
StringBuilder()  // 构造一个空的字符串构建器。 StringBuilder builder = new StringBuilderO;
length()
setCharAt(int i ,char c)  // 将第 i 个代码单元设置为 c。
StringBuilder insert(int offset,String str) // 在 offset 位置插入一个字符串并返回 this。
StringBuilder insert(int offset,Char c)  // 在 offset 位置插入一个代码单元并返回 this。
StringBui 1 der delete(1 nt startindex,int endlndex) // 删除偏移量从 startindex 到-endlndex-1 的代码单元并返回 this。

## BigInteger / BigDecimal
subtract
multiple
divide
mode

```Java
Biglnteger a = Biglnteger.valueOf(100);
Biglnteger c = a.add(b); // c = a + b
Biglnteger d = c.nulti piy(b.add(Biglnteger.val ueOf(2))); // d = c * (b + 2)
```
## Arrays
*

初始化、sort
```Java
// 规则数组
int[] a = new int[100];  // classical
double[][] balances = new double[10] [6];
Arrays.sort(a);
int[] small Primes = { 2, 3, 5, 7, 11, 13 };  // 无 new
int[][] magicSquare = { {16, 3, 2, 13}，
                        {5, 10, 11, 8},
                        (9, 6, 7, 12},
                        {4, 15, 14, 1}};
new intD { 17, 19, 23, 29, 31, 37 } // 匿名数组

// 不规则数组
int[][] odds = new int[NMAX + 1][] ;
for (int n = 0; n <= NMAX ; n++)
  odds[n] = new int[n + 1];
```

copy
```Java
intQ luckyNumbers = smallPrimes; // 只是引用
int[] copiedLuckyNumbers = Arrays.copyOf(luckyNumbers, luckyNumbers.length) ;
```

## 常识
* Object 是所有类的祖先，？作用效果上和 auto 差不多,可能丢失方法？
```c++
for ( auto var : object_array)
    std::cout << var << std::endl;
```
```Java
for ( Object var : object_array)
  System.out.println(var);
```

* synchronized: only one thread at a time can access the code,  acquired a lock on it, thread-safe
  not synchronized: multiple threads can work on it

* Enumeration, you can only traverse the collection. You can’t do any modifications to collection while traversing it.
  Iterator, you can remove an element of the collection while traversing it.

* Fail-Fast iterators immediately throw ConcurrentModificationException if there is structural modification of the collection. Structural modification means adding, removing or updating any element from collection while a thread is iterating over that collection. Iterator on ArrayList, HashMap classes are some examples of fail-fast Iterator.

  Fail-Safe iterators don’t throw any exceptions if a collection is structurally modified while iterating over it. This is because, they operate on the clone of the collection, not on the original collection and that’s why they are called fail-safe iterators. Iterator on CopyOnWriteArrayList, ConcurrentHashMap classes are examples of fail-safe Iterator.

* prefer HashSet to create the Set and then convert it into TreeSet
  e.g. SortedSet<String> s = new TreeSet<String>(hashSet);

* Math类中的sqrt方法处理的不是对象，这样的方法被称为静态方法。

* break 语句可以带标签。相当于c++ 的  goto

* **Load Factor:** The load factor is a measure of how full the HashSet is allowed to get before its capacity is automatically increased. When the number of entries in the hash table exceeds the product of the load factor and the current capacity, the hash table is rehashed (that is, internal data structures are rebuilt) so that the hash table has approximately twice the number of buckets. It is the percent value of the capacity after which the capacity of Hashmap is to be increased (It is the percentage fill of buckets after which Rehashing takes place). In java, it is 0.75f by default, meaning the rehashing takes place after filling 75% of the capacity.

Threshold – It is the product of Load Factor and Initial Capacity. In java, by default, it is (16 * 0.75 = 12). That is, Rehashing takes place after inserting 12 key-value pairs into the HashMap.

Rehashing – It is the process of doubling the capacity of the HashMap after it reaches its Threshold. In java, HashMap continues to rehash(by default) in the following sequence – 2^4, 2^5, 2^6, 2^7, …. so on.





List接口是一个有序的 Collection，使用此接口能够精确的控制每个元素插入的位置，能够通过索引(元素在List中位置，类似于数组的下标)来访问List中的元素，第一个元素的索引为 0，而且允许有相同的元素。查找元素效率高，插入删除效率低，因为会引起其他元素位置改变


## 输入
### Scanner
Scanner in = new Scanner(System.in);
nextLine
next //读取一个单词（以空白符作为分隔符)
nextInt //读取一个整数
nextDouble // 读取下一个浮点数
boolean hasNext( ) // 检测输人中是否还有其他单词
boolean hasNextInt( )  boolean hasNextDouble( ) // 检测是否还有表示整数或浮点数的下一个字符序列




```Java
//LinkedList
LinkedList<String> sites = new LinkedList<String>();
  sites.addLast("Wiki");  // 使用 addLast() 在尾部添加元素
  sites.addFirst("Wiki");  // 使用 addFirst() 在头部添加元素
  sites.removeFirst();  // 使用 removeFirst() 移除头部元素
  sites.removeLast();  // 使用 removeLast() 移除尾部元素
  System.out.println(sites.getFirst()); // 使用 getFirst() 获取头部元素
  System.out.println(sites.getLast()); // 使用 getLast() 获取尾部元素
  for (int size = sites.size(), i = 0; i < size; i++) {
            System.out.println(sites.get(i));
  }
public boolean add(E e)	链表末尾添加元素，返回是否成功，成功为 true，失败为 false。
public void add(int index, E element)	向指定位置插入元素。
public void clear()	清空链表。

```
## 系统化知识需求
Collection 抽象类
Map
iterat Map.Entry

Set

## 现在不理解
### 反射
程序运行时，对于任意一个类，都能够知道这个类的所有属性和方法；对于任意一个对象，都能够调用它的任意一个方法和属性。这种动态的获取信息以及动态调用对象的方法的功能称为java 的反射机制。
反射机制很重要的一点就是“运行时”，其使得我们可以在程序运行时加载、探索以及使用编译期间完全未知的 .class 文件。
