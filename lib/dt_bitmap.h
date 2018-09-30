#ifndef		DT_BITMAP_H
#define		DT_BITMAP_H


#include	<string>
#include	<vector>
#include	<map>

#include	"dt_position.h"
#include	"dt_colour.h"


class	dt_bitmap {
private:
	// Full colour
	std::vector<std::vector<dt_colour>>		full_bmp;		// Full bitmap
	std::map<dt_position, dt_colour>		sparse_bmp;		// Sparse bitmap

	// Single colour
	std::vector<std::vector<double>>		full_bmp_s;		// Full bitmap only with single colour
	std::map<dt_position, double>			sparse_bmp_s;	// Sparse bitmap only with single colour
	size_t									width, height;
	dt_colour								fore_colour;	// fg-colour for single colour bitmaps
	dt_colour								back_colour;	// bg-colour for single colour bitmaps


public:
	// Constractors
	dt_bitmap(void) {
	}
	dt_bitmap(const int wid, const int hei) {
		width	= wid;
		height	= hei;
	}


			void		resize(const int wid, const int hei);

	const	dt_colour	get_pixel(const int x, const int y) const;
			void		set_pixel(const int x, const int y, const dt_colour&clr);
};


#endif	//	DT_BITMAP_H
