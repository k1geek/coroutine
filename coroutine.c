#include"coroutine.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stddef.h>
#include<string.h>
#include<stdint.h>

#if __APPLE__&&__MACH__//c library haven`t ucontext
    #include<sys/ucontext.h>
#else
    #include<ucontext.h>
#endif

#define STACK_SIZE (1024*1024)
#define DEFAULT_COROUTINE 16

struct coroutine;

struct schedule {
    char stack[STACK_SIZE];
    ucontext_t main;
    int nco;
    int cap;
    int running;
    struct coroutine **co;
};

struct coroutine {
    coroutine_func func;
}