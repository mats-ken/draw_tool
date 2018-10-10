#include "stdafx.h"


#include	<iostream>

#include	"../../CUnit/CUnit.h"

#include	"test_obj_to_from_string.h"
#include	"test_dt_obj__to_postscript.h"

#include	"test_obj.h"


using	namespace	std;


void	test_obj(void)
{
	cout << __FUNCTION__ << endl;

	test_dt_obj_to_from_string_path1();
	test_dt_obj_to_from_string_path1000();

	test_dt_obj_to_from_string_text1();
	test_dt_obj_to_from_string_text1000();

	test_dt_obj__to_postscript();
	test_dt_obj__to_postscript_oval();
	test_dt_obj__to_postscript_rectangle();
	test_dt_obj__to_postscript_text();
}
