/*#include "ApplicationManager.hpp"
#include <vector>

//ApplicationManager applicationManager;
*/

// Header main.h 
#include "Foo.h"
#include "Bar.h"

struct list_of_types {
	typedef TYPE_LIST type;
};
// Or just typedef TYPE_LIST list_of_types;

// Test
#include <iostream>
#include <typeinfo>

template <template <typename ...> class List, typename T, typename ...Types>
void info();

template <typename T, typename ...Types>
inline void info(TypeList<T, Types...>) {
	std::cout << typeid(T).name() << std::endl;
	// std::cout << T << std::endl;
	info(TypeList<Types...>());
}

template <typename T>
inline void info(TypeList<T>) {
	std::cout << typeid(T).name() << std::endl;
	auto test = T();

}	
/**/