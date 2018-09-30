#include	"stdafx.h"


#include	<iostream>

#include	"../../lib/dt_path.h"
#include	"../../lib/dt_text.h"

#include	"../../CUnit/CUnit.h"

#include	"create_data.h"


using	namespace	std;


static	double		rand3(void)	// random value 0.xxx0000
{
	const	int		n = rand() % 1000;

	return	n / 1.0e3;
}


const	dt_path		create_path(void)
{
	const	dt_colour				co1(dt_colour::CMYK, 0.7, 0.8, 0.9, 0.4);
	const	dt_colour				co2(dt_colour::CMYK, 1.0, 0.3, 0.2, 0.0);
	const	vector<dt_position>		pv({
		{ 687.453, 18.1530 },
		{ 521.257, 873.237 },
		{ 888.621, 532.713 },
		{ 435.577, 988.938 },
		{ 797.850, 287.206 },
		{ 951.225, 70.5830 },
		{ 424.898, 127.583 },
		{ 762.022, 522.981 },
		{ 639.351, 652.977 },
		{ 742.277, 951.225 },
		{ 988.938, 801.068 },
		{ 616.229, 482.148 },
		{ 192.005, 77.4040 },
		{ 967.847, 534.524 },
		{ 624.783, 885.280 },
		{ 312.472, 362.709 },
	});
	const	vector<int>				iv({ 3, 4, 7, 10 });

	dt_path							path;

	path.closed			= true;
	path.line_width		= 12;
	path.line_colour	= co1;
	path.fill_colour	= co2;
	path.position		= { 321, 765 };
	path.scale			= { 0.876, 0.789 };
	path.rotation		= 123;
	path.anchor_pts		= pv;
	path.selected_pts	= iv;
	path.edge_shape		= 1;
	path.text_style		= dt_path::textstyle::NONE;

	return	path;
}

const	dt_path		create_path2(void)
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

	dt_path							path;
	dt_path							pa2;

	path.closed			= false;
	path.line_width		= 12;
	path.line_colour	= co1;
	path.fill_colour	= co2;
	path.rotation		= 56;
	path.anchor_pts		= pv;
	path.selected_pts	= iv;
	path.edge_shape		= 1;
	path.text_style		= dt_path::textstyle::NONE;
	//path.text_id			= -1;

	return	path;
}

const	dt_path		create_path_rand(const int seed)
{
	srand(seed);

	const	dt_colour				co1(dt_colour::CMYK, rand3(), rand3(), rand3(), rand3());
	const	dt_colour				co2(dt_colour::CMYK, rand3(), rand3(), rand3(), rand3());
	const	vector<dt_position>		pv({
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
		{ rand3(), rand3() },
	});
	const	vector<int>				iv({ 3, 4, 7, 10 });

	dt_path							path;

	path.closed			= true;
	path.line_width		= rand3();//////// * 10.0;
	path.line_colour	= co1;
	path.fill_colour	= co2;
	path.position		= { rand3(), rand3() };
	path.scale			= { rand3(), rand3() };
	path.rotation		= rand3();
	path.anchor_pts		= pv;
	path.selected_pts	= iv;
	path.edge_shape		= 1;
	path.text_style		= dt_path::textstyle::NONE;

	return	path;
}

const	dt_path		create_path_oval1(void)
{
	const	dt_colour				co1(dt_colour::CMYK, 0.7, 0.8, 0.9, 0.4);
	const	dt_colour				co2(dt_colour::CMYK, 1.0, 0.3, 0.2, 0.0);

	dt_path	path("oval", { 200.0, 200.0 }, { 100.0, 100.0 });
	path.line_colour	= co1;
	path.fill_colour	= co2;
	path.line_width		= 12;

	return	path;
}

const	dt_path		create_path_oval2(void)
{
	const	dt_colour				co1(dt_colour::CMYK, 0.7, 0.8, 0.9, 0.4);
	const	dt_colour				co2(dt_colour::CMYK, 1.0, 0.3, 0.2, 0.0);

	dt_path	path("oval", { { 200.0, 200.0 },{ 100.0, 100.0 } });
	path.line_colour	= co2;
	path.fill_colour	= co1;
	path.line_width		= 23;

	return	path;
}

const	dt_path		create_path_rect1(void)
{
	const	dt_colour				co1(dt_colour::CMYK, 0.7, 0.8, 0.9, 0.4);
	const	dt_colour				co2(dt_colour::CMYK, 1.0, 0.3, 0.2, 0.0);

	dt_path	path("rect", { 200.0, 200.0 }, { 100.0, 100.0 });
	path.line_colour = co1;
	path.fill_colour = co2;
	path.line_width = 12;

	return	path;
}

const	dt_path		create_path_rect2(void)
{
	const	dt_colour				co1(dt_colour::CMYK, 0.7, 0.8, 0.9, 0.4);
	const	dt_colour				co2(dt_colour::CMYK, 1.0, 0.3, 0.2, 0.0);

	dt_path	path("rect", { { 200.0, 200.0 },{ 100.0, 100.0 } });
	path.line_colour = co2;
	path.fill_colour = co1;
	path.line_width	= 23;

	return	path;
}


const	dt_text		create_text(void)
{

	const	dt_colour		co1(dt_colour::CMYK, 0.1, 0.2, 0.3, 0.4);
	const	dt_colour		co2(dt_colour::RGB, 63.0, 127.0, 255.0, 0.0);

	dt_text					text;

	text.pos = dt_position({ 123, 456 });
	text.line_colour = co1;
	text.fill_colour = co2;
	text.rotation = 123.456;
	text.text = "this  \t  \n\tis\t\n a\n   test  \n\n   \t\n\n  s t r i n g .  ";
	text.mag_h = 1.2;
	text.mag_v = 0.8;
	text.font_name = "Garamond Italic";
	text.font_size = 12.0;
	text.underline = false;
	text.cursor_pos[0] = 1234;
	text.cursor_pos[1] = 4567;

	return	text;
}

const	dt_text		create_text_rand(const int seed)
{
	srand(seed);

	const	dt_colour		co1(dt_colour::CMYK, 0.1, 0.2, 0.3, 0.4);
	const	dt_colour		co2(dt_colour::RGB, 63.0, 127.0, 255.0, 0.0);

	dt_text					text;

	text.pos = dt_position({ rand3(), rand3() });
	text.line_colour = co1;
	text.fill_colour = co2;
	text.rotation = rand3();
	text.text = "this  \t  \n\tis\t\n a\n   test  \n\n   \t\n\n  s t r i n g .  ";
	text.mag_h = rand3();
	text.mag_v = rand3();
	text.font_name = "Garamond Italic";
	text.font_size = rand3();
	text.underline = false;
	text.cursor_pos[0] = (int)(rand3() * 1.0e3);
	text.cursor_pos[1] = text.cursor_pos[0] + (int)(rand3() * 1.0e3);

	return	text;
}
