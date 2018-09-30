#ifndef		CUNIT_H
#define		CUNIT_H


// ‚È‚ñ‚¿‚á‚Á‚ÄCUnit
#define		CU_OUTPUT_OK()	(cerr << "")
#define		CU_OUTPUT_ERR()	(cerr << "ERROR: " << __FILE__ << ", " << __FUNCTION__ << ", " << __LINE__ << endl)
#define		CU_ASSERT_EQUAL(actual, expected)	(((actual) == (expected)) ? CU_OUTPUT_OK() : CU_OUTPUT_ERR())
#define		CU_ASSERT_NOT_EQUAL(actual, expected)	(((actual) != (expected)) ? CU_OUTPUT_OK() : CU_OUTPUT_ERR())
#define		CU_ASSERT_DOUBLE_EQUAL(actual, expected, granularity)	((fabs((actual) - (expected)) < (granularity)) ? CU_OUTPUT_OK() : CU_OUTPUT_ERR()
#define		CU_ASSERT_DOUBLE_NOT_EQUAL(actual, expected, granularity)	((granularity) <= (fabs((actual) - (expected))) ? CU_OUTPUT_OK() : CU_OUTPUT_ERR()


#endif	//	CUNIT_H
