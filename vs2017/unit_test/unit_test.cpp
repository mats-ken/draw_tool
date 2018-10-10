#include "stdafx.h"


#include	<string>
#include	<iostream>

#include	"../../CUnit/CUnit.h"

#include	"../../unit_test/unit_test_main.h"


using	namespace	std;


int		main(void)
{
	unit_test_main();

	string	s;
	getline(cin, s);

	return	EXIT_SUCCESS;
}
