#include "stdafx.h"


#include	<string>
#include	<iostream>

#include	"../../lib/dt_file.h"

#include	"../../CUnit/CUnit.h"

#include	"../common/create_data.h"

#include "test_dt_file__to_from_string.h"


using	namespace	std;

void	test_dt_file__to_from_string_path1(void)
{
	const	dt_obj		obj_path(create_path());
	const	dt_obj		obj_text(create_text());

	dt_group	grp;
	grp.objects.push_back(obj_path);
	grp.objects.push_back(obj_text);
	grp.objects.push_back(obj_path);
	grp.objects.push_back(obj_text);

	dt_layer	layer1;
	layer1.groups.push_back(grp);
	layer1.groups.push_back(grp);
	layer1.groups.push_back(grp);
	layer1.groups.push_back(grp);
	layer1.name			= "Layer 1";
	layer1.sel_colour	= dt_colour(0.1, 0.2, 0.3, 0.4);
	layer1.visible		= true;

	dt_file		file1;
	file1.layers.push_back(layer1);
	file1.layers.push_back(layer1);
	file1.layers.push_back(layer1);

	const	string	s = file1.to_string();

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".myd");
	ofs	 << s << endl;
	ofs.close();

	dt_file	file2;
	file2.from_string(s);


	CU_ASSERT_EQUAL(file2, file2);
	CU_ASSERT_EQUAL(file2.to_string(), file2.to_string());
}

//void	test_dt_file__to_from_string_text1()
//{
//	const	dt_obj		obj_text(create_text());
//
//	dt_group	gr1;
//	gr1.objects.push_back(obj_text);
//
//	const	string	s = gr1.to_string();
//
//	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".myd");
//	ofs << s << endl;
//	ofs.close();
//
//	dt_group	gr2;
//	gr2.from_string(s);
//
//
//	CU_ASSERT_EQUAL(gr1, gr2);
//}
//
//void	test_dt_file__to_from_string_path1_text1()
//{
//	const	dt_obj		obj_path(create_path());
//	const	dt_obj		obj_text(create_text());
//
//	dt_group	gr1;
//	gr1.objects.push_back(obj_path);
//	gr1.objects.push_back(obj_text);
//
//	const	string	s = gr1.to_string();
//
//	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".myd");
//	ofs << s << endl;
//	ofs.close();
//
//	dt_group	gr2;
//	gr2.from_string(s);
//
//
//	CU_ASSERT_EQUAL(gr1, gr2);
//}
//
//void	test_dt_file__to_from_string_path2()
//{
//	const	dt_obj		obj_path(create_path());
//
//	dt_group	gr1;
//	gr1.objects.push_back(obj_path);
//	gr1.objects.push_back(obj_path);
//
//	const	string	s = gr1.to_string();
//
//	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".myd");
//	ofs << s << endl;
//	ofs.close();
//
//	dt_group	gr2;
//	gr2.from_string(s);
//
//
//	CU_ASSERT_EQUAL(gr1, gr2);
//}
//
//void	test_dt_file__to_from_string_text2()
//{
//	const	dt_obj		obj_text(create_text());
//
//	dt_group	gr1;
//	gr1.objects.push_back(obj_text);
//	gr1.objects.push_back(obj_text);
//
//	const	string	s = gr1.to_string();
//
//	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".myd");
//	ofs << s << endl;
//	ofs.close();
//
//	dt_group	gr2;
//	gr2.from_string(s);
//
//
//	CU_ASSERT_EQUAL(gr1, gr2);
//}
//
//void	test_dt_file__to_from_string_path2_text2()
//{
//	const	dt_obj		obj_path(create_path());
//	const	dt_obj		obj_text(create_text());
//
//	dt_group	gr1;
//	gr1.objects.push_back(obj_path);
//	gr1.objects.push_back(obj_path);
//	gr1.objects.push_back(obj_text);
//	gr1.objects.push_back(obj_text);
//
//	const	string	s = gr1.to_string();
//
//	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".myd");
//	ofs << s << endl;
//	ofs.close();
//
//	dt_group	gr2;
//	gr2.from_string(s);
//
//
//	CU_ASSERT_EQUAL(gr1, gr2);
//}

void	test_dt_file__to_from_string_path1000_text1000(void)
{
	dt_group	gr1;

	for (int k = 0; k < 1000; k++) {
		const	dt_obj		obj_path(create_path_rand(k));
		const	dt_obj		obj_text(create_text_rand(k));

		gr1.objects.push_back(obj_path);
		gr1.objects.push_back(obj_text);
	}

	dt_layer	layer1;
	layer1.groups.push_back(gr1);
	layer1.name			= "Layer 1";
	layer1.sel_colour	= dt_colour(0.1, 0.2, 0.3, 0.4);
	layer1.visible		= true;

	dt_file		file1;
	file1.layers.push_back(layer1);

	const	string	s = file1.to_string();

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".myd");
	ofs << s << endl;
	ofs.close();

	dt_file		file2;
	file2.from_string(s);


	CU_ASSERT_EQUAL(file1, file2);
	CU_ASSERT_EQUAL(file1.to_string(), file2.to_string());
}
