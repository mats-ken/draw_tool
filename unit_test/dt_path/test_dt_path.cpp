#include "stdafx.h"


#include	<iostream>

#include	"../../CUnit/CUnit.h"

#include	"test_path_to_from_string.h"
#include	"test_path_to_postscript.h"


using	namespace	std;


void	test_path(void)
{
	cout << __FUNCTION__ << endl;

	test_path_to_from_string_1();
	test_path_to_from_string_1000();

	test_path_to_postscript();
	test_path_to_postscript_oval();
	test_path_to_postscript_rectangle();
}
