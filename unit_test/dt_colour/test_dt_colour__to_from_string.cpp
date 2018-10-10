#include "stdafx.h"


#include	<string>
#include	<iostream>

#include	"../../lib/dt_colour.h"

#include	"../../CUnit/CUnit.h"

#include	"test_dt_colour__to_from_string.h"


using	namespace	std;


void	test_colour_to_from_string(void)
{
	dt_colour	col1;

	col1.type			= dt_colour::CMYK;
	col1.a				= 123.0;
	col1.b				= 234.0;
	col1.c				= 345.0;
	col1.d				= 456.0;
	col1.tranparency	= 789.0;

	const	string	s(col1.to_string());

	dt_colour	col2;
	col2.from_string(s);

	CU_ASSERT_EQUAL(col1, col2);
	CU_ASSERT_EQUAL(col1.to_string(), col2.to_string());

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydcolour");
	ofs << s << endl;
	ofs.close();
}
