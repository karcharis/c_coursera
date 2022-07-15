---
date: 2022-07-12
title: array name to pointer decay
---

The name of an array of type `T arr[n]` decays, except three expressions, to a pointer of type `T * arr`. Note we may say that `arr` and `&arr[0]` are equivalent.

#The particular case of a 2-d array#

Consider the following code

```c

int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12}

int (*p\_to\_array)[4] = arr

int * p = arr[0]

```

Here the name `arr` decays to a pointer to an array of 4 int, in other words it has type `int (*)[4]` and stores the address of the first element of `arr`.

Note that:

1. `arr+i` points to `arr + sizeof(int)*4*i`, i.e `arr+2` points to the first element of the third row of `arr`.

2. When we dereference `arr` we get an `int [4]` value. The array to pointer decay apply here so that `*arr` is decayed to a `int *`. 
For example, `**arr` prints the first element of `arr`. Note that `**arr` is equivalent to `arr[0][0]`.

3. It is important to remember that the subscript operator `[]` has higher precedence in comparison to the dereference operator `*`. Hence be careful!
The following two expressions are deferent:
 
* `*arr[3]` prints the first element of the 3-rd row of `arr[3][4]`, while
* `(*arr)[3]` prints the 3-rd element of the first row of `arr[3][4]`.

#The three exeptions#

Know we discuss the three exeptions of the decay rule. The instances when the name of the array `T arr[n]` is different from the address `&arr[0]`

1. When an array is passed as an argument to `sizeof`

2. An array of type `char [n]` cannot decay to a `char *`, aka a string literal. (note that `const char *` and `char *` are equivalent)

3. When an array is the argument of the binary address-of operant `&`. Consider an array `T arr[n]`, the expression `&arr` has type `T (*)[n]`, while the expression `&(&arr[0])` is of type `T **`


 
