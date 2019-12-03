This small example demonstrates an issue with static constexpr class members

If I compile that example without optimization disabled:

```sh
g++ -std=c++14 a.cpp b.cpp main.cpp -O0
```

I get the following errors:
```
/tmp/ccHv44S3.o: In function `a(unsigned int&)':
a.cpp:(.text+0x1e): undefined reference to `qvalue_t::maximum'
/tmp/ccIQACTW.o: In function `b(unsigned int&)':
b.cpp:(.text+0x1e): undefined reference to `qvalue_t::maximum'
collect2: error: ld returned 1 exit status
```

But if I compile that example with `-O2` there is no any errors:
```sh
$ g++ -std=c++14 a.cpp b.cpp main.cpp -O2
$ ./a.out 
value from a(): 1000
value from b(): 1000
```

I've checked this code with GCC-5.5.0, GCC-7.4.0, GCC-9.2.1 and clang-9.0.1.

Note. clang-3.8.0 reports those errors even with `-O2`.

