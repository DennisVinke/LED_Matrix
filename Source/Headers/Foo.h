#pragma once
// Header foo.h
#include "common.h"
#include <stdio.h>
class Foo { 
public:
	inline Foo() { printf("Hallo ik ben Foo"); };
};

typedef typename concat<TYPE_LIST, Foo>::type TypeListFoo;
#undef TYPE_LIST
#define TYPE_LIST TypeListFoo