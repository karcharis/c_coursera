---
date: 2022-07-13
title: memory-pitfalss
---

#Use unitialized values#

##Reading uninitialized memory##

##Referencing nonexistent variables

#Dereferencing bad pointers#

##Dereference a pointer that points in wrong location##

* Always be carefull when there is involved pointer arithmetic.
* Use the correct pointer type. And do mot type cast pointers
* Be careful with the aritmetic of pointers to arrays
* Be careful when assign value to an once derefernced double pointer.
* see next point

##Do not use * with ++##

If you need some pointer arithmetic for a pointer `T ** p` the code 
```c
  *p++;
```
is a realy bad choice!

For reference we mention that:

1. The unitary postfix operator `\_++` first returns the increases the variable `\_`

2. The prefix operator `++\_` first increases and then returns. 

3. With respect to operator precedence we have that `\_++` = `++\_` = `*\_`.

4. The operators `++\_` and `*\_` have right-to-left associativity.

##Dereferencing null pointer##

#memory overwrite/overread#

#Common Problems with memory allocation and freeing#

##Check `malloc` and `realloc` for failure##

Make a habbit to use somthing like this

```c
  void * p\_temp = malloc(4*sizeof(int));
  if (p\_temp == NULL) {
    /*...*/
  }
  int * p = p\_temp;
```

##double freeing##

Trying to free the same block of memory more than one time is called double freeing. Generally, your program will crash (segfault), although, other more sinister behaviors can occur. A segfault on the line where the double free happened is nice: it makes debugging easier. However, you may get stranger symptoms—including your program crashing the next time you call malloc. In general, if malloc crashes, an earlier error in your code has corrupted its bookkeeping structures, and you have just now exposed the problem. Run your code in valgrind, and it is quite likely to help you expose the error sooner.

##free memory not pointed to the adress returned by malloc##

Another common problem, is freeing something that is not at the start of the block returned by malloc. Neither of malloc and free is magical. They need to do their own bookkeeping to track which parts of memory are free and which are in use, as well as how big each block that is in use is. Bookkeeping requires memory: they must store their own data structures to track the information—but where do they get the memory to track what memory is in use? The answer is that malloc actually allocates more memory than you ask for, and keeps a bit for itself, right before the start of what it gives you. You might ask for 16 bytes, and malloc gives you 32—the first 16 contain its information about the block, and the next 16 it gives you to use. When you free the block, the free function calculates the address of the metadata from the pointer you give it (e.g., subtract 16). If you give it a pointer in the middle of the block, it looks for the metadata in the wrong place.

##free memory on the stack##

A third common mistake is freeing memory that is not on the heap. If you try to free a variable that is on the stack (or global), something bad will happen—most likely, your program will crash.

##Leaking memory##

Failing to free blocks can result in two cases. A programmer should always remember to free any allocated memory when the data stored there is no longer useful for the program. The memory freeing should be done carefully! We have to be thoutful to never free memory that gives as access to a allocated memory block, e.g never free an array of pointers, where each pointer points to a memory block allocated by `malloc`. If this happens, then there is no way to access that memory blocks and never deallocated to be used by the program.

##Referencing freed blocks##

As a rull of thumb. Always after `free` assigng to the freed pointer the adress of `NULL`. And check before accessing a pointer if it is `NULL`.

#Summary#

To avoid memory-related problems, it is good practice to:

* Always use memset along with malloc, or always use calloc.
* Whenever writing values to pointers, make sure you cross check the number of bytes available and number of bytes being written.
* Before assigning the pointers, make sure no memory locations will become orphaned.
* Whenever freeing the structured element (which in turn contains the pointer to dynamically allocated memory location), first traverse to the child memory location and start freeing from there, traversing back to the parent node.
* Always properly handle return values of functions returning references of dynamically allocated memory.
* Have a corresponding free to every malloc.
* Make sure you are not accessing null pointer.
