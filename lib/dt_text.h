#ifndef		DT_TEXT_H
#define		DT_TEXT_H


#include	<string>
#include	<vector>

#include	"dt_position.h"
#include	"dt_area.h"
#include	"dt_colour.h"
#include	"dt_bitmap.h"


class	dt_text {
private:

public:
	//int			id;
	dt_position	pos;
	dt_colour	line_colour;
	dt_colour	fill_colour;
	double		rotation;
	std::string	text;
	double		mag_h, mag_v;	// horizontal and vertical maginification
	std::string	font_name;
	double		font_size;
	bool		underline;
	int			cursor_pos[2];	// cursor position and selected charaters
	dt_area		bb;				// bounding box


	// Constructors
	dt_text(void) {
	}
	dt_text(std::stringstream&ss) {
		from_string(ss);
	}


	const	std::string	to_string(void) const;
	void	from_string(std::stringstream&ss);
	void	from_string(const std::string&str) {
		std::stringstream	ss(str);
		from_string(ss);
	}

	const	std::string	to_xml(const bool finalise = false) const;
	void	from_xml(const std::string&str);

	const	std::string	to_svg(const bool finalise = false) const;
	void	from_svg(const std::string&str);

	const	std::string	to_postscript(const bool finalise = false) const;
	//void	from_postscript(const std::string&str);

	const	std::string	to_pdf(const bool finalise = false) const;
	//void	from_pdf(const std::string&str);


	void	rasterise(dt_bitmap&bmp) const;


		bool	operator==(const dt_text&rhs) const {
		if (
			//(id				== rhs.id			) &&
			(pos			== rhs.pos			) &&
			(line_colour	== rhs.line_colour	) &&
			(fill_colour	== rhs.fill_colour	) &&
			(text			== rhs.text			) &&
			(mag_h			== rhs.mag_h		) &&
			(mag_v			== rhs.mag_v		) &&
			(font_name		== rhs.font_name	) &&
			(font_size		== rhs.font_size	) &&
			(underline		== rhs.underline	) &&
			(cursor_pos[0]	== rhs.cursor_pos[0]) &&
			(cursor_pos[1]	== rhs.cursor_pos[1])
			) {
			return	true;
		}
		return	false;
	}
	bool	operator!=(const dt_text&rhs) const { return !(*this == rhs); }
};


#endif	//	DT_TEXT_H
