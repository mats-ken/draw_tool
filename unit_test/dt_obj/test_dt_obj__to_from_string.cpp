#include "stdafx.h"


#include	<iostream>

#include	"../../lib/dt_path.h"
#include	"../../lib/dt_text.h"
#include	"../../lib/dt_obj.h"

#include	"../../CUnit/CUnit.h"

#include	"../common/create_data.h"

#include	"test_dt_obj__to_from_string.h"


using	namespace	std;


void	test_dt_obj_to_from_string_path1(void)
{
	dt_obj		obj1(create_path());
	dt_obj		obj2;

	const	string	s = obj1.to_string();
	obj2.from_string(s);

	CU_ASSERT_EQUAL(obj1, obj2);
	CU_ASSERT_EQUAL(obj1.to_string(), obj2.to_string());

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydobj");
	ofs << s << endl;
	ofs.close();
}

void	test_dt_obj_to_from_string_path1000(void)
{
	for (int i = 0; i < 1000; i++) {
		dt_obj		obj1(create_path_rand(i));
		dt_obj		obj2;

		const	string	s = obj1.to_string();
		obj2.from_string(s);

		CU_ASSERT_EQUAL(obj1, obj2);
		CU_ASSERT_EQUAL(obj1.to_string(), obj2.to_string());
	}
}


void	test_dt_obj_to_from_string_text1(void)
{
			dt_obj		obj1(create_text());
			dt_obj		obj2;

	const	string	s = obj1.to_string();
	obj2.from_string(s);


	CU_ASSERT_EQUAL(obj1, obj2);
	CU_ASSERT_EQUAL(obj1.to_string(), obj2.to_string());

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydobj");
	ofs << s << endl;
	ofs.close();
}

void	test_dt_obj_to_from_string_text1000(void)
{
	for (int i = 0; i < 1000; i++) {
		dt_obj		obj1(create_text_rand(i));
		dt_obj		obj2;

		const	string	s = obj1.to_string();
		obj2.from_string(s);

		CU_ASSERT_EQUAL(obj1, obj2);
		CU_ASSERT_EQUAL(obj1.to_string(), obj2.to_string());
	}
}
