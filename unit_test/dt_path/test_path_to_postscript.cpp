#include "stdafx.h"


#include	<iostream>

#include	"../../lib/dt_path.h"
#include	"../../lib/dt_text.h"

#include	"../../CUnit/CUnit.h"

#include	"../common/create_data.h"

#include	"test_path_to_postscript.h"


using	namespace	std;


void	test_path_to_postscript(void)
{
	const	dt_colour				co1(dt_colour::CMYK, 0.7, 0.8, 0.9, 0.4);
	const	dt_colour				co2(dt_colour::CMYK, 1.0, 0.3, 0.2, 0.0);
	const	vector<dt_position>		pv({
		{ 100.0, 100.0 },
		{ 100.0, 150.0 },
		{ 150.0, 200.0 },
		{ 200.0, 200.0 },
		{ 250.0, 200.0 },
		{ 300.0, 150.0 },
		{ 300.0, 100.0 },
	});
	const	vector<int>				iv;

	dt_path							pa1;
	dt_path							pa2;

	pa1.closed			= false;
	pa1.line_width		= 12;
	pa1.line_colour		= co1;
	pa1.fill_colour		= co2;
	pa1.rotation		= 56;
	pa1.anchor_pts		= pv;
	pa1.selected_pts	= iv;
	pa1.edge_shape		= 1;
	pa1.text_style		= dt_path::textstyle::NONE;
	//pa1.text_id			= -1;

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << pa1.to_postscript(true);
	ofs.close();
}


void	test_path_to_postscript_oval(void)
{
	const	dt_path	oval1 = create_path_oval1();
	const	dt_path	oval2 = create_path_oval2();


	// to postscript
	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << "%!" << endl
		<< oval1.to_postscript() << endl
		<< oval2.to_postscript() << endl
		<< "showpage" << endl;
	ofs.close();


	// to svg
	ofstream	ofs2("../../for_test/out/" __FUNCTION__ ".svg");
	ofs2 << R"###(<?xml version="1.0" encoding="utf-8"?>
<!-- Generator: MyDrawer -->
<svg version="1.1"
xmlns="http://www.w3.org/2000/svg"
xmlns:xlink="http://www.w3.org/1999/xlink"
x="0px" y="0px"
viewBox="0 0 1000 600" >

)###"
		<< oval1.to_svg() << endl
		<< oval2.to_svg() << endl
		<< "</svg>" << endl;
	ofs2.close();
}


void	test_path_to_postscript_rectangle(void)
{
	const	dt_path	rect1 = create_path_rect1();
	const	dt_path	rect2 = create_path_rect2();


	// to postscript
	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << "%!" << endl
		<< rect1.to_postscript() << endl
		<< rect2.to_postscript() << endl
		<< "showpage" << endl;
	ofs.close();


	// to svg
	ofstream	ofs2("../../for_test/out/" __FUNCTION__ ".svg");
	ofs2 << R"###(<?xml version="1.0" encoding="utf-8"?>
<!-- Generator: MyDrawer -->
<svg version="1.1"
xmlns="http://www.w3.org/2000/svg"
xmlns:xlink="http://www.w3.org/1999/xlink"
x="0px" y="0px"
viewBox="0 0 1000 600" >

)###"
		<< rect1.to_svg() << endl
		<< rect2.to_svg() << endl
		<< "</svg>" << endl;
	ofs2.close();
}
