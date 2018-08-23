#ifndef		DT_COLOUR_H
#define		DT_COLOUR_H


#include	<string>

#include	"dt_colour.h"


class	dt_colour {
private:

public:
	enum colourtype {
		GREY,	// grey scale
		RGB,	// RGB colour
		CMYK	// CMYK colour
	}		type;
	int		a, b, c, d;		// Y, RGB or CMYK values
	double	tranparency;	// alpha channel (0.0 to 1.0)
};


#endif	//	DT_COLOUR_H
