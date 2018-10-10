#include "stdafx.h"


#include	<iostream>

#include	"../../CUnit/CUnit.h"

#include	"test_dt_position__to_from_string.h"


using	namespace	std;


void	test_position(void)
{
	cout << __FUNCTION__ << endl;

	test_position_to_from_string();
}
