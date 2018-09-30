#include "stdafx.h"


#include	<iostream>

#include	"../../CUnit/CUnit.h"

#include	"test_dt_layer__to_from_string.h"
#include	"test_dt_layer__to_postscript.h"

#include	"test_dt_layer.h"


using	namespace	std;


void	test_dt_layer(void)
{
	cout << __FUNCTION__ << endl;

	test_dt_layer__to_from_string_path1();
	//test_dt_layer__to_from_string();

	test_dt_layer__to_postscript();
	//test_dt_layer__to_postscript();
}
