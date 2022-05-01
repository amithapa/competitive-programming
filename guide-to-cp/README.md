# Guide to Competitive programming

## Table of contents
- [Programing Techniques](#programming-techniques-chapter-2)
    - [Input and output](#input-and-output)
    - [Working with numbers](#working-with-numbers)

## Programming Techniques (Chapter 2)

### Input and output

- Input and output is sometimes a bottleneck in program. The folloiwing lines at the beginning of the code make input and output more efficient:
    ```c++
    ios:sync_with_stdio(0);
    cin.tie(0);
    ```
- Read a whole input line, possibly conatining spaces.
  ```c++
  string s;
  getline(cin, s);
  ```
- If the amount of data is unknown, the following loop is useful:
  ```c++
  int x;
  while (cin >> x) {
      // code
  }
  ```
- If files are to be used for input and output. Easy solution for this is to write the code as usual using standard streams, but add the following lines to the beginning of the code:
    ```c++
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ```

### Working with numbers
### Integers
- The most used integer type in competitive programming is int which is a 32-bit type with a value range of -2<sup>31</sup>...2<sup>31</sup> - 1 (about -2\*10<sup>9</sup>...2\*10<sup>31</sup>)
- If the type `int` is not enough, the 64-bit type `long long` can be used. It has a value range of -2<sup>63</sup>...2<sup>63</sup>-1 (about -9\*10<sup>18</sup>...9\*10<sup>18</sup>).
- Note: Never mix using int and long long together, this can cause some wierd issues.
### Modular Arithmetic
Sometimes, the answer to a problem is a very large number, but it is enough to output it "modulo m", i.e, the remainder when the anser is divided by m (e.g, "modulo 10<sub>9</sub> + 7"). The idea is that even if the actual answer is very large, it suffices to use the type int and long long.
### Floating point numbers
It is risky to compare floating point numbers with the `==` operator, because it is possible that the values should be equal but they are not because of precision erros. A better way to compare floating point numbers is to assume that two numbers are equal if the difference between them is less than `ε`, where `ε` is a small number.
```c++
if (abs(a-b) < 1e-9) {
    // a and b are equal.
}
```
### Shortening Code
`Type Names` The command `typedef` can be used to give a short name to a type. For example. the name `long long` is long, so we can define a short name `ll` as follows:
```c++
typedef long long ll;
```
After this, the code
```c++
long long a = 123456789;
long long b = 987654321;
cout << a * b << "\n";
```
can be shortened as follows:
```c++
ll a = 123456789;
ll b = 987654321;
cout << a * b << "\n";
```
Create more complex `typedef` For example following code gives the name `vi` for a vector of integers, and name `pi` for a pair that contains two integers.
```c++
typedef vector<int> vi;
typedef pair<int, int> pi;
```

**Macros** Another way to shorten code to define *macros*. A macro specifies that certain strings in the code will be changed before the compilation. In C++ macros are defined using the #define keyword.
For example, we can define the following macros:
```c++
#define F first
#define S second
#define PB push_back
#define MP make_pair
```
After this, the code
```c++
v.push_back(make_pair(y1, x1));
v.push_back(make_pair(y2, x2));
int d = v[i].first + v[i].second;
```
can be shortened as follows:
```c++
v.PB(MP(y1, x1));
v.PB(MP(y2, x2));
int d = v[i].F + v[i].S;
```
A macro can also have parameters, which makes it possible to shorten loops and other structures. For example, we can define the following macro:
```c++
#define REP(i, a, b) for (int i = a; i <= b; i++)
```
After this, the code
```c++
for(int i=0; i <= n; i++) {
    search(i);
}
```
can be shortened as follows:
```c++
REP(i, 0, n) {
    search(i);
}
```