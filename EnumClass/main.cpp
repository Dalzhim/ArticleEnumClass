//
//  main.cpp
//  ArticleEnumClass
//
//  Created by Gabriel Aubut-Lussier on 16-02-16.
//  Copyright © 2016 Gabriel Aubut-Lussier. All rights reserved.
//

#include "EnumClass.h"
#include <iostream>

enum class eTest
{
	kEnumerator1 = 1 << 0,
	kEnumerator2 = 1 << 1,
	kEnumerator3 = 1 << 2
};
enableEnumClassBitfield(eTest);

int main(int argc, const char * argv[])
{
	eTest test = eTest::kEnumerator1 & eTest::kEnumerator2;
	std::cout << static_cast<std::underlying_type<eTest>::type>(test) << std::endl;
	test = eTest::kEnumerator1 | eTest::kEnumerator2;
	std::cout << static_cast<std::underlying_type<eTest>::type>(test) << std::endl;
}
