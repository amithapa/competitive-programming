# competitive-programming
Preparing to become a grand master champion :D 

In macos we are not able to use <bits/stdc++.h> header file to create it follow the steps given bellow:

Copy the file from [here](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/precompiled/stdc%2B%2B.h) to the following destination, please create the `bits`
```
/Library/Developer/CommandLineTools/usr/include/c++/v1
```

## Setting memory for an array
```c++
memset(bucket, 0, sizeof(bucket));
```
# Sorting

- Ascending order
```c++
sort(v.begin(), v.end());
```
- Decending Order
```c++
sort(v.rbegin(), v.rend());
```

# Reversing
```c++
reverse(path.begin(), path.end());
```

## Optimizing cin/cout
```c++
std::ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
```

## Using queues

```c++
queue<int> q;

q.push(v);
q.empty()

q.front(); 
q.pop();
```

## Setting defualt values
```c++
memset(vis, 0, sizeof(vis));
```

### Maximum Number
```c++

#include <climits>

INT_MAX
```