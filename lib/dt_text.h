#ifndef		DT_TEXT_H
#define		DT_TEXT_H


#include	<string>
#include	<vector>

#include	"dt_position.h"
#include	"dt_colour.h"
#include	"dt_bitmap.h"


class	dt_text {
private:

public:
	int		id;
	dt_position	pos;
	dt_colour	line_colour;
	dt_colour	fill_colour;
	double		rotation;
	std::string	text;
	double		mag_h, mag_v;	// horizontal and vertical maginification
	std::string	font_name;
	double		font_size;
	int			cursor_pos[2];	// cursor position and selected charaters

	void	rasterise(dt_bitmap&bmp) const;
};


#endif	//	DT_TEXT_H
