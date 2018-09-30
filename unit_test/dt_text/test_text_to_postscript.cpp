#include "stdafx.h"


#include	<iostream>

#include	"../../lib/dt_path.h"
#include	"../../lib/dt_text.h"

#include	"../../CUnit/CUnit.h"

#include	"test_text_to_postscript.h"


using	namespace	std;


void	test_text_to_postscript(void)
{
	const	dt_colour				co1(dt_colour::CMYK, 0.7, 0.8, 0.9, 0.4);
	const	dt_colour				co2(dt_colour::CMYK, 1.0, 0.3, 0.2, 0.0);

	dt_text		text;

	text.font_name		= "Garamond";
	text.font_size		= 12;
	text.text			= "This is\na test string.";
	text.line_colour	= co1;
	text.fill_colour	= co2;

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << text.to_postscript(true);
	ofs.close();
}
