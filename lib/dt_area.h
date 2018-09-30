#ifndef		DT_AREA_H
#define		DT_AREA_H


#include	"dt_position.h"


class	dt_area {
private:

public:
	dt_position	left_top, right_bottom;

	const	double	get_width(void) {
		return	fabs(left_top.x - right_bottom.x);
	}

	const	double	get_height(void) {
		return	fabs(left_top.y - right_bottom.y);
	}

	const	dt_position	get_centre(void) {
		return	(left_top - right_bottom) / 2.0;
	}
};


#endif	//	DT_AREA_H
