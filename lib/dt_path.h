#ifndef		DT_PATH_H
#define		DT_PATH_H


#include	<string>
#include	<vector>
#include	<sstream>

#include	"dt_position.h"
#include	"dt_colour.h"
#include	"dt_area.h"
#include	"dt_bitmap.h"


class	dt_path {
private:

public:
	//int							id;
	bool						closed;
	double						line_width;
	dt_colour					line_colour;
	dt_colour					fill_colour;
	dt_position					position;
	dt_position					scale;
	double						rotation;
	std::vector<dt_position>	anchor_pts;
	std::vector<int>			selected_pts;
	int							edge_shape;
	enum textstyle{
		NONE,
		ON,
		INSIDE,
	}		text_style;
	//int							text_id;
	dt_area						bb;			// bounding box


	// Constructors
	dt_path(void) {
		scale = {1.0, 1.0};
	}
	dt_path(std::stringstream&ss) {
		from_string(ss);
	}
	dt_path(const std::string&type, const dt_area&area) {
		if ("rect" == type) {
			new_rectangle_ltrb(area.left_top, area.right_bottom);
		} else if ("oval" == type) {
			new_oval_ltbr(area.left_top, area.right_bottom);
		}
	}
	dt_path(const std::string&type, const dt_position&centre, const dt_position&right_bottom) {
		if ("rect" == type) {
			new_rectangle_crb(centre, right_bottom);
		} else if ("oval" == type) {
			new_oval_crb(centre, right_bottom);
		}
	}


	void	new_oval_ltbr(const dt_position&left_top, const dt_position&right_bottom) {	// new oval by left, top, right, and bottom
		const	dt_position		centre = (left_top + right_bottom) / 2;
		new_oval_crb(centre, right_bottom);
	}

	void	new_oval_crb(const dt_position&centre, const dt_position&right_bottom) {	// new oval by center, right and bottom
		const	double	c = (sqrt(2) - 1) * 4 / 3;

		position = centre;
		scale = {
			fabs(right_bottom.x - centre.x),
			fabs(right_bottom.y - centre.y)
		};
		rotation = 0.0;
		closed = true;

		anchor_pts.push_back({  0.0,  1.0 });	// 0 top
		anchor_pts.push_back({    c,  1.0 });	// 1
		anchor_pts.push_back({  1.0,    c });	// 2
		anchor_pts.push_back({  1.0,  0.0 });	// 3 right
		anchor_pts.push_back({  1.0,   -c });	// 4
		anchor_pts.push_back({    c, -1.0 });	// 5
		anchor_pts.push_back({  0.0, -1.0 });	// 6 bottom
		anchor_pts.push_back({   -c, -1.0 });	// 7
		anchor_pts.push_back({ -1.0,   -c });	// 8
		anchor_pts.push_back({ -1.0,  0.0 });	// 9 left
		anchor_pts.push_back({ -1.0,    c });	// 10
		anchor_pts.push_back({   -c,  1.0 });	// 11
		anchor_pts.push_back({  0.0,  1.0 });	// 0 top again
	}

	void	new_rectangle_ltrb(const dt_position&left_top, const dt_position&right_bottom) {	// new oval by left, top, right, and bottom
		const	dt_position		centre = (left_top + right_bottom) / 2;
		new_rectangle_crb(centre, right_bottom);
	}

	void	new_rectangle_crb(const dt_position&centre, const dt_position&right_bottom) {	// new oval by center, right and bottom
		position = centre;
		scale = {
			fabs(right_bottom.x - centre.x),
			fabs(right_bottom.y - centre.y)
		};
		rotation = 0.0;
		closed = true;

		anchor_pts.push_back({ -1.0,  1.0 });	// 0 left-top
		anchor_pts.push_back({ -1.0,  1.0 });	// 1 left-top
		anchor_pts.push_back({  1.0,  1.0 });	// 2 right-top
		anchor_pts.push_back({  1.0,  1.0 });	// 3 right-top
		anchor_pts.push_back({  1.0,  1.0 });	// 4 right-top
		anchor_pts.push_back({  1.0, -1.0 });	// 5 right-bottom
		anchor_pts.push_back({  1.0, -1.0 });	// 6 right-bottom
		anchor_pts.push_back({  1.0, -1.0 });	// 7 right-bottom
		anchor_pts.push_back({ -1.0, -1.0 });	// 8 left-bottom
		anchor_pts.push_back({ -1.0, -1.0 });	// 9 left-bottom
	}


	const	std::string	to_string(void) const;
	void	from_string(std::stringstream&ss);
	void	from_string(const std::string&str) {
		std::stringstream	ss(str);
		from_string(ss);
	}

	const	std::string	to_xml(void) const;
	void	from_xml(const std::string&str);

	const	std::string	to_svg(const bool finalise = false) const;
	void	from_svg(const std::string&str);

	const	std::string	to_postscript(const bool finalise = false) const;
	//void	from_postscript(const std::string&str);

	const	std::string	to_pdf(const bool finalise = false) const;
	//void	from_pdf(const std::string&str);


	void	rasterise(const dt_area&area, dt_bitmap&bmp) const;


	bool	operator==(const dt_path&rhs) const {
		if (
			//(id				== rhs.id			) &&
			(closed			== rhs.closed		) &&
			(line_width		== rhs.line_width	) &&
			(line_colour	== rhs.line_colour	) &&
			(fill_colour	== rhs.fill_colour	) &&
			(rotation		== rhs.rotation		) &&
			(anchor_pts		== rhs.anchor_pts	) &&
			(selected_pts	== rhs.selected_pts	) &&
			(edge_shape		== rhs.edge_shape	) &&
			(text_style		== rhs.text_style	)
			//(text_id		== rhs.text_id		)
			) {
			return	true;
		}
		return	false;
	}
	bool	operator!=(const dt_path&rhs) const { return !(*this == rhs); }
};


#endif	//	DT_PATH_H
