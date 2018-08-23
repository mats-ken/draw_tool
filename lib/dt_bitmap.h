#ifndef		DT_BITMAP_H
#define		DT_BITMAP_H


#include	<string>
#include	<vector>

#include	"dt_position.h"
#include	"dt_colour.h"


class	dt_bitmap {
private:
	std::vector<std::vector<dt_colour>>	bmp;

public:
						dt_bitmap(const int wid, const int hei);
			void		resize(const int wid, const int hei);
	const	dt_colour	get_pixel(const int x, const int y) const;
			void		set_pixel(const int x, const int y, const dt_colour&clr);
};


#endif	//	DT_BITMAP_H
