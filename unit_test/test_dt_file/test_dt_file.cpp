#include "stdafx.h"


#include	<iostream>

#include	"../../CUnit/CUnit.h"

#include	"test_dt_file__to_from_string.h"
#include	"test_dt_file__to_postscript.h"

#include	"test_dt_file.h"


using	namespace	std;


void	test_dt_file(void)
{
	cout << __FUNCTION__ << endl;

	test_dt_file__to_from_string_path1();
	//test_dt_file__to_from_string();
	//test_dt_file__to_postscript();
}
