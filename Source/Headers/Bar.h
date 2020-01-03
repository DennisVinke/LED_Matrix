#pragma once
// Header bar.h
#include "common.h"
#include <stdio.h>

class Bar {
public:
	inline Bar() { printf("Hallo ik ben Bar"); }
};

typedef typename concat<TYPE_LIST, Bar>::type TypeListBar;
#undef TYPE_LIST
#define TYPE_LIST TypeListBar