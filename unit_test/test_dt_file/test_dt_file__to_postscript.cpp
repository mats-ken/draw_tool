#include "stdafx.h"


#include	<iostream>

#include	"../../lib/dt_file.h"

#include	"../../CUnit/CUnit.h"

#include	"../common/create_data.h"

#include	"test_dt_file__to_postscript.h"


using	namespace	std;


void	test_dt_file__to_postscript_path1(void)
{
	const	dt_obj		obj(create_path2());

	dt_group	grp;
	grp.objects.push_back(obj);

	dt_layer	layer;
	layer.groups.push_back(grp);

	dt_file		file;
	file.layers.push_back(layer);


	// to postscript
	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << file.to_postscript(true);
	ofs.close();

	// to xml
	ofstream	ofs2("../../for_test/out/" __FUNCTION__ ".mydx");
	ofs2 << file.to_xml(true);
	ofs2.close();

	// to svg
	ofstream	ofs3("../../for_test/out/" __FUNCTION__ ".svg");
	ofs3 << file.to_svg(true);
	ofs3.close();
}


void	test_dt_file__to_postscript_text1(void)
{
	const	dt_obj		obj(create_text());

	dt_group	grp;
	grp.objects.push_back(obj);

	dt_layer	layer;
	layer.groups.push_back(grp);

	dt_file		file;
	file.layers.push_back(layer);


	// to postscript
	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << file.to_postscript(true);
	ofs.close();

	// to xml
	ofstream	ofs2("../../for_test/out/" __FUNCTION__ ".mydx");
	ofs2 << file.to_xml(true);
	ofs2.close();

	// to svg
	ofstream	ofs3("../../for_test/out/" __FUNCTION__ ".svg");
	ofs3 << file.to_svg(true);
	ofs3.close();
}


void	test_dt_file__to_postscript_oval(void)
{
	const	dt_obj		obj1(create_path_oval1());
	const	dt_obj		obj2(create_path_oval2());

	dt_group	grp;
	grp.objects.push_back(obj1);
	grp.objects.push_back(obj2);

	dt_layer	layer;
	layer.groups.push_back(grp);

	dt_file		file;
	file.layers.push_back(layer);


	// to postscript
	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << file.to_postscript(true);
	ofs.close();

	// to xml
	ofstream	ofs2("../../for_test/out/" __FUNCTION__ ".mydx");
	ofs2 << file.to_xml(true);
	ofs2.close();

	// to svg
	ofstream	ofs3("../../for_test/out/" __FUNCTION__ ".svg");
	ofs3 << file.to_svg(true);
	ofs3.close();
}


void	test_dt_file__to_postscript_rectangle(void)
{
	const	dt_obj		obj1(create_path_rect1());
	const	dt_obj		obj2(create_path_rect2());

	dt_group	grp;
	grp.objects.push_back(obj1);
	grp.objects.push_back(obj2);

	dt_layer	layer;
	layer.groups.push_back(grp);

	dt_file		file;
	file.layers.push_back(layer);


	// to postscript
	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << file.to_postscript(true);
	ofs.close();

	// to xml
	ofstream	ofs2("../../for_test/out/" __FUNCTION__ ".mydx");
	ofs2 << file.to_xml(true);
	ofs2.close();

	// to svg
	ofstream	ofs3("../../for_test/out/" __FUNCTION__ ".svg");
	ofs3 << file.to_svg(true);
	ofs3.close();
}


void	test_dt_file__to_postscript_text(void)
{
	const	dt_obj		obj1(create_text());
	const	dt_obj		obj2(create_text_rand());

	dt_group	grp;
	grp.objects.push_back(obj1);
	grp.objects.push_back(obj2);

	dt_layer	layer;
	layer.groups.push_back(grp);

	dt_file		file;
	file.layers.push_back(layer);


	// to postscript
	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".ps");
	ofs << file.to_postscript(true);
	ofs.close();

	// to xml
	ofstream	ofs2("../../for_test/out/" __FUNCTION__ ".mydx");
	ofs2 << file.to_xml(true);
	ofs2.close();

	// to svg
	ofstream	ofs3("../../for_test/out/" __FUNCTION__ ".svg");
	ofs3 << file.to_svg(true);
	ofs3.close();
}
