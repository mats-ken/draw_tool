#ifndef		DT_IMAGE_H
#define		DT_IMAGE_H


#include	<string>

#include	"dt_position.h"
#include	"dt_bitmap.h"


class	dt_image {
private:
	std::string		path;	// Path to the linked image file.
	dt_bitmap		bmp;


public:
	dt_position		position;
	dt_position		scale;
	double			rotation;


	// Constractors
	dt_image(void) {
	}
	dt_image(const std::string&path_in){
		path = path_in;
	}

	//const	dt_colour	get_pixel(const int x, const int y) const;
	//		void		set_pixel(const int x, const int y, const dt_colour&clr);


	const	std::string	to_string(void) const;
	void	from_string(std::stringstream&ss);
	void	from_string(const std::string&str) {
		std::stringstream	ss(str);
		from_string(ss);
	}

	const	std::string	to_xml(void) const;
	void	from_xml(const std::string&str);

	const	std::string	to_svg(void) const;
	void	from_svg(const std::string&str);

	const	std::string	to_postscript(void) const;
	//void	from_postscript(const std::string&str);

	const	std::string	to_pdf(void) const;
	//void	from_pdf(const std::string&str);


	//void	rasterise(const dt_area&area, dt_bitmap&bmp) const;


	bool	operator==(const dt_image&rhs) const {
		if (
			1	// dummy
			) {
			return	true;
		}
		return	false;
	}
	bool	operator!=(const dt_image&rhs) const { return !(*this == rhs); }
};


#endif	//	DT_IMAGE_H
