#include "stdafx.h"


#include	<iostream>

#include	"../lib/dt_path.h"
#include	"../lib/dt_text.h"
#include	"../lib/dt_file.h"

#include	"../CUnit/CUnit.h"


#include	"dt_colour/test_colour.h"
#include	"dt_position/test_position.h"
#include	"dt_path/test_path.h"
#include	"dt_text/test_text.h"
#include	"dt_obj/test_obj.h"
#include	"dt_group/test_dt_group.h"
#include	"test_dt_layer/test_dt_layer.h"
#include	"test_dt_file/test_dt_file.h"

#include	"unit_test_main.h"


using	namespace	std;


void	unit_test_main(void)
{
	cout << "*** unit-test started. ***" << endl;

	test_colour();
	test_position();
	test_path();
	test_text();
	test_obj();
	test_dt_group();
	test_dt_layer();
	test_dt_file();

	cout << "*** unit-test finished. ***" << endl;
}
