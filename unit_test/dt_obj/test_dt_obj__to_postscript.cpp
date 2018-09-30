#include "stdafx.h"


#include	<iostream>

#include	"../../lib/dt_path.h"
#include	"../../lib/dt_text.h"
#include	"../../lib/dt_obj.h"

#include	"../../CUnit/CUnit.h"

#include	"../common/create_data.h"

#include	"test_dt_obj__to_postscript.h"


using	namespace	std;


void	test_dt_obj__to_postscript(void)
{
	const	dt_obj		obj(create_path2());

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << obj.to_postscript(true);
	ofs.close();
}


void	test_dt_obj__to_postscript_oval(void)
{
	const	dt_obj		obj1(create_path_oval1());
	const	dt_obj		obj2(create_path_oval2());

	// to postscript
	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << "%!" << endl
		<< obj1.to_postscript() << endl
		<< obj2.to_postscript() << endl
		<< "showpage" << endl;
	ofs.close();

	// to svg
	ofstream	ofs2("../../for_test/out/" __FUNCTION__ ".svg");
	ofs2 << R"###(<?xml version="1.0" encoding="utf-8"?>
<!-- MyDrawer  -->
<svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
viewBox="0 0 1000 600" style="enable - background:new 0 0 1000 600; " xml:space="preserve">
)###"
		<< obj1.to_svg() << endl
		<< obj2.to_svg() << endl
		<< "</svg>" << endl;
	ofs2.close();
}


void	test_dt_obj__to_postscript_rectangle(void)
{
	const	dt_obj		obj1(create_path_rect1());
	const	dt_obj		obj2(create_path_rect2());

	// to postscript
	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << "%!" << endl
		<< obj1.to_postscript() << endl
		<< obj2.to_postscript() << endl
		<< "showpage" << endl;
	ofs.close();

	// to svg
	ofstream	ofs2("../../for_test/out/" __FUNCTION__ ".svg");
	ofs2 << R"###(<?xml version="1.0" encoding="utf-8"?>
<!-- MyDrawer  -->
<svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
viewBox="0 0 1000 600" style="enable - background:new 0 0 1000 600; " xml:space="preserve">
)###"
		<< obj1.to_svg() << endl
		<< obj2.to_svg() << endl
		<< "</svg>" << endl;
	ofs2.close();
}


void	test_dt_obj__to_postscript_text(void)
{
	const	dt_obj		obj1(create_text());
	const	dt_obj		obj2(create_text_rand());

	// to postscript
	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << "%!" << endl
		<< obj1.to_postscript() << endl
		<< obj2.to_postscript() << endl
		<< "showpage" << endl;
	ofs.close();

	// to svg
	ofstream	ofs2("../../for_test/out/" __FUNCTION__ ".svg");
	ofs2 << R"###(<?xml version="1.0" encoding="utf-8"?>
<!-- MyDrawer  -->
<svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
viewBox="0 0 1000 600" style="enable - background:new 0 0 1000 600; " xml:space="preserve">
)###"
		<< obj1.to_svg() << endl
		<< obj2.to_svg() << endl
		<< "</svg>" << endl;
	ofs2.close();
}
