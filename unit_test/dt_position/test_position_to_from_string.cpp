#include "stdafx.h"


#include	<string>
#include	<iostream>

#include	"../../lib/dt_position.h"

#include	"../../CUnit/CUnit.h"


using	namespace	std;


void	test_position_to_from_string(void)
{
	dt_position	pos1;

	pos1.x = 123.456;
	pos1.y = 456.789;

	const	string	s(pos1.to_string());

	dt_position	pos2;
	pos2.from_string(s);

	CU_ASSERT_EQUAL(pos1, pos2);
	CU_ASSERT_EQUAL(pos1.to_string(), pos2.to_string());

	//////ofstream	ofs("../../for_test/out/" __FUNCTION__ ".mydpos");
	//////ofs << s << endl;
	//////ofs.close();
}
