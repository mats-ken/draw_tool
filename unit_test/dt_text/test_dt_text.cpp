#include "stdafx.h"


#include	<iostream>

#include	"../../CUnit/CUnit.h"

#include	"test_dt_text__to_from_string.h"
#include	"test_dt_text__to_postscript.h"


using	namespace	std;


void	test_text(void)
{
	cout << __FUNCTION__ << endl;

	test_text_to_from_string_1();
	test_text_to_from_string_1000();

	test_text_to_postscript();
}
