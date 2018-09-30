#include "stdafx.h"


#include	<string>
#include	<iostream>

#include	"../../lib/dt_group.h"

#include	"../../CUnit/CUnit.h"

#include	"../common/create_data.h"

#include "test_dt_group__to_from_string.h"


using	namespace	std;

void	test_dt_group__to_from_string_path1()
{
	const	dt_obj		obj_path(create_path());

	dt_group	gr1;
	gr1.objects.push_back(obj_path);

	const	string	s = gr1.to_string();

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydgrp");
	ofs	 << s << endl;
	ofs.close();

	dt_group	gr2;
	gr2.from_string(s);


	CU_ASSERT_EQUAL(gr1, gr2);
	CU_ASSERT_EQUAL(gr1.to_string(), gr2.to_string());
}

void	test_dt_group__to_from_string_text1()
{
	const	dt_obj		obj_text(create_text());

	dt_group	gr1;
	gr1.objects.push_back(obj_text);

	const	string	s = gr1.to_string();

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydgrp");
	ofs << s << endl;
	ofs.close();

	dt_group	gr2;
	gr2.from_string(s);


	CU_ASSERT_EQUAL(gr1, gr2);
	CU_ASSERT_EQUAL(gr1.to_string(), gr2.to_string());
}

void	test_dt_group__to_from_string_path1_text1()
{
	const	dt_obj		obj_path(create_path());
	const	dt_obj		obj_text(create_text());

	dt_group	gr1;
	gr1.objects.push_back(obj_path);
	gr1.objects.push_back(obj_text);

	const	string	s = gr1.to_string();

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydgrp");
	ofs << s << endl;
	ofs.close();

	dt_group	gr2;
	gr2.from_string(s);


	CU_ASSERT_EQUAL(gr1, gr2);
	CU_ASSERT_EQUAL(gr1.to_string(), gr2.to_string());
}

void	test_dt_group__to_from_string_path2()
{
	const	dt_obj		obj_path(create_path());

	dt_group	gr1;
	gr1.objects.push_back(obj_path);
	gr1.objects.push_back(obj_path);

	const	string	s = gr1.to_string();

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydgrp");
	ofs << s << endl;
	ofs.close();

	dt_group	gr2;
	gr2.from_string(s);


	CU_ASSERT_EQUAL(gr1, gr2);
	CU_ASSERT_EQUAL(gr1.to_string(), gr2.to_string());
}

void	test_dt_group__to_from_string_text2()
{
	const	dt_obj		obj_text(create_text());

	dt_group	gr1;
	gr1.objects.push_back(obj_text);
	gr1.objects.push_back(obj_text);

	const	string	s = gr1.to_string();

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydgrp");
	ofs << s << endl;
	ofs.close();

	dt_group	gr2;
	gr2.from_string(s);


	CU_ASSERT_EQUAL(gr1, gr2);
	CU_ASSERT_EQUAL(gr1.to_string(), gr2.to_string());
}

void	test_dt_group__to_from_string_path2_text2()
{
	const	dt_obj		obj_path(create_path());
	const	dt_obj		obj_text(create_text());

	dt_group	gr1;
	gr1.objects.push_back(obj_path);
	gr1.objects.push_back(obj_path);
	gr1.objects.push_back(obj_text);
	gr1.objects.push_back(obj_text);

	const	string	s = gr1.to_string();

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydgrp");
	ofs << s << endl;
	ofs.close();

	dt_group	gr2;
	gr2.from_string(s);


	CU_ASSERT_EQUAL(gr1, gr2);
	CU_ASSERT_EQUAL(gr1.to_string(), gr2.to_string());
}

void	test_dt_group__to_from_string_path1000_text1000()
{
	dt_group	gr1;

	for (int k = 0; k < 1000; k++) {
		const	dt_obj		obj_path(create_path_rand(k));
		const	dt_obj		obj_text(create_text_rand(k));

		gr1.objects.push_back(obj_path);
		gr1.objects.push_back(obj_text);
	}
	const	string	s = gr1.to_string();

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydgrp");
	ofs << s << endl;
	ofs.close();

	dt_group	gr2;
	gr2.from_string(s);


	CU_ASSERT_EQUAL(gr1, gr2);
	CU_ASSERT_EQUAL(gr1.to_string(), gr2.to_string());
}
