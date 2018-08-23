#ifndef		DT_PATH_H
#define		DT_PATH_H


#include	<string>
#include	<vector>

#include	"dt_position.h"
#include	"dt_colour.h"
#include	"dt_area.h"
#include	"dt_bitmap.h"


class	dt_path {
private:

public:
	int							id;
	bool						closed;
	dt_colour					line_colour;
	dt_colour					fill_colour;
	double						rotation;
	std::vector<dt_position>	anchor_pts;
	std::vector<int>			selected_pts;
	int							edge_shape;


	const	std::string	to_string(void) const;
	void	from_string(const std::string&str) const;

	const	std::string	to_xml(void) const;
	void	from_xml(const std::string&str) const;

	const	std::string	to_svg(void) const;
	void	from_svg(const std::string&str) const;

	void	rasterise(const dt_area&area, dt_bitmap&bmp) const;
};


#endif	//	DT_PATH_H
