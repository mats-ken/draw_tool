#ifndef		DT_LAYER_H
#define		DT_LAYER_H


#include	<string>
#include	<vector>

#include	"dt_colour.h"
#include	"dt_bitmap.h"


class	dt_text {
private:

public:
	int		id;
	std::string	name;
	dt_colour	sel_colour;	// colour to indicates selected items

	void	rasterise(dt_bitmap&bmp) const;
};


#endif	//	DT_LAYER_H
