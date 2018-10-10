#include "stdafx.h"


#include	<iostream>

#include	"../../lib/dt_text.h"

#include	"../../CUnit/CUnit.h"

#include	"../common/create_data.h"

#include	"test_dt_text__to_from_string.h"


using	namespace	std;


void	test_text_to_from_string_1(void)
{
	dt_text		tx1 = create_text_rand();
	dt_text		tx2;

	const	string	s = tx1.to_string();
	tx2.from_string(s);

	CU_ASSERT_EQUAL(tx1, tx2);
	CU_ASSERT_EQUAL(tx1.to_string(), tx2.to_string());

	ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydtext");
	ofs << s << endl;
	ofs.close();
}

void	test_text_to_from_string_1000(void)
{
	for (int i = 0; i < 1000; i++) {
		dt_text		tx1 = create_text_rand(i);
		dt_text		tx2;

		const	string	s = tx1.to_string();
		tx2.from_string(s);

		CU_ASSERT_EQUAL(tx1, tx2);
		CU_ASSERT_EQUAL(tx1.to_string(), tx2.to_string());
	}
}
