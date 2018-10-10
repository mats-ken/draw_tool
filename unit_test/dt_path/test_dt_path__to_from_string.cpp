#include "stdafx.h"


#include	<iostream>

#include	"../../lib/dt_path.h"
#include	"../../lib/dt_text.h"

#include	"../../CUnit/CUnit.h"

#include	"../common/create_data.h"

#include	"test_dt_path__to_from_string.h"


using	namespace	std;


void	test_path_to_from_string_1(void)
{
	dt_path		pa1 = create_path_rand();
	dt_path		pa2;

	const	string	s = pa1.to_string();
	pa2.from_string(s);

	CU_ASSERT_EQUAL(pa1, pa2);
	CU_ASSERT_EQUAL(pa1.to_string(), pa2.to_string());

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydpath");
	ofs << s << endl;
	ofs.close();
}

void	test_path_to_from_string_1000(void)
{
	for (int i = 0; i < 1000; i++) {
		dt_path		pa1 = create_path_rand(i);
		dt_path		pa2;

		const	string	s = pa1.to_string();
		pa2.from_string(s);

		CU_ASSERT_EQUAL(pa1, pa2);
		CU_ASSERT_EQUAL(pa1.to_string(), pa2.to_string());
	}
}
