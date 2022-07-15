---
date: 2022-07-14
title: valgrading
tags:
 - @programming
  - @c
  - @debugging
---

##Best practises:##
1. use the option --track-origins=yes

2. `just below the stack ptr` means that the error occured when a function returned.

3. If we run Valgrind with the options --vgdb=full --vgdb-error=0, then Valgrind will stop on the first error it encounters and give control to GDB. For monitor commands available for Memcheck. See [](http://valgrind.org/docs/manual/mc-manual.html#mc-manual.monitor-commands).

5.  If you have memory leaks, you will want to run with the --leak-check=full option. When you do so, Memcheck will report the location of each allocation which was not freed. You can then use this information to figure out where you should free that memory.

Note that when running Valgrind's Memcheck with GDB, you can run the leak checker at any time with the monitor command monitor leak_check full reachable any.

6. memcheck.h
Sometimes we may want to interact with Valgrind's tools directly in our program. For example, we might want to explicitly check if a value is initialized at a certain point in the program (e.g., as part of debugging an error about uninitialized values). Valgrind provides header files, such as memcheck.h, which contains a variety of macros for exactly this purpose. For example, we could change the function we were using earlier as an example of uninitialized values to

6
void f(int x) {
  int y;
  int z = x + y;
  VALGRIND_CHECK_MEM_IS_DEFINED(&z,sizeof(z));
  printf("%d\n", z);
}
Now, when we run this program in valgrind, we get the error message more immediately:

Many of Memcheck's features are available through these macros. Most other tools have similar header files for programs to interact directly with them. See [](http://valgrind.org/docs/manual/mc-manual.html#mc-manual.clientreqs for more details.)

5. The Valgrind tool Helgrind is designed to check for a variety of errors related to multi-threaded programming. See http://valgrind.org/docs/manual/hg-manual.html for more details on Helgrind.

Valgrind’s tools are not limited to helping your find correctness bugs in your program, but also can be helpful in understanding performance memory usage issues. For example, the Callgrind tool gives information about the performance characteristics of a program based on Valgrind’s simulation of hardware resources as it executes the program. Another tool is Massif, which profiles the dynamic memory allocations in the heap, and gives information about how much memory is allocated at any given time and where in the code the memory was allocated.

See http://valgrind.org/info/tools.html for an overview of the tools. Also note that many of these other tools have header files that you can include with macros that allow your program to interact directly with Valgrind (similarly to the functionality in  memcheck.h).

4. For some extra insight run gdb with the option -fsanitize=address. This will provide gdb tools to chech if you violate in reading/writting boundaries of arraies. Do not run valgrind with a program compiled with this option! as they do not work good together.
