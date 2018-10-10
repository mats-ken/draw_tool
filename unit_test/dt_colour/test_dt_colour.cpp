#include "stdafx.h"


#include	<iostream>

#include	"../../lib/dt_colour.h"

#include	"../../CUnit/CUnit.h"

#include	"test_colour_to_from_string.h"


using	namespace	std;


void	test_colour_to_rgb(void)
{
	dt_colour	cmyk;
	cmyk.type = dt_colour::CMYK;
	cmyk.a = 0.12;
	cmyk.b = 0.23;
	cmyk.c = 0.34;
	cmyk.d = 0.45;

	dt_colour	rgb = cmyk.to_rgb();

	CU_ASSERT_EQUAL((int)(rgb.a * 255 + 0.5), 123);
	CU_ASSERT_EQUAL((int)(rgb.b * 255 + 0.5), 108);
	CU_ASSERT_EQUAL((int)(rgb.c * 255 + 0.5),  93);
}


void	test_colour_to_webstr(void)
{
	dt_colour	cmyk;
	cmyk.type = dt_colour::CMYK;
	cmyk.a = 0.123;
	cmyk.b = 0.234;
	cmyk.c = 0.345;
	cmyk.d = 0.456;

	const	string	s = cmyk.to_webstr();

	CU_ASSERT_EQUAL(s, "796a5a");
}


void	test_colour(void)
{
	cout << __FUNCTION__ << endl;

	test_colour_to_rgb();
	test_colour_to_webstr();
	test_colour_to_from_string();
}
