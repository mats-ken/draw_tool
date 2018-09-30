#ifndef		DT_COLOUR_H
#define		DT_COLOUR_H


#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	<algorithm>
#include	<iomanip>

#include	"dt_colour.h"


class	dt_colour {
private:

public:
	enum	colourtype {
		NONE,
		GREY,	// grey scale
		RGB,	// RGB colour
		CMYK	// CMYK colour
	}		type;
	double	a, b, c, d;		// Y, RGB or CMYK values
	double	tranparency;	// alpha channel (0.0 to 1.0)


	// Constructors
	dt_colour(void) {
		type			= GREY;
		a				= 1.0;
		b				= 1.0;
		c				= 1.0;
		d				= 1.0;
		tranparency		= 1.0;
	}
	dt_colour(const colourtype&type_in, const double a_in, const double b_in, const double c_in, const double d_in, const double tranparency_in = 1.0) {
		type			= type_in;
		a				= a_in;
		b				= b_in;
		c				= c_in;
		d				= d_in;
		tranparency		= tranparency_in;
	}
	dt_colour(const double y_in) {
		type			= GREY;
		a				= y_in;
		b				= 0.0;
		c				= 0.0;
		d				= 0.0;
		tranparency		= 1.0;
	}
	dt_colour(const double r_in, const double g_in, const double b_in) {
		type			= RGB;
		a				= r_in;
		b				= g_in;
		c				= b_in;
		d				= 0.0;
		tranparency		= 1.0;
	}
	dt_colour(const double c_in, const double m_in, const double y_in, const double k_in) {
		type			= CMYK;
		a				= c_in;
		b				= m_in;
		c				= y_in;
		d				= k_in;
		tranparency		= 1.0;
	}


	const	dt_colour	to_rgb(void) const {
		dt_colour	rgb;

		rgb.type = RGB;
		switch (type) {
		case	NONE:
			rgb.type = NONE;
			break;

		case	GREY:
			rgb.a = rgb.b = rgb.c = a;
			break;

		case	RGB:
			rgb = *this;
			break;

		case	CMYK:
			rgb.a = (1 - a) * (1 - d);	// R=(1-C)*(1-K)
			rgb.b = (1 - b) * (1 - d);	// G=(1-M)*(1-K)
			rgb.c = (1 - c) * (1 - d);	// B=(1-Y)*(1-K)
			break;
		}

		return	rgb;
	}


	const	std::string	to_webstr(void) const {
		std::stringstream	ss;
		dt_colour	rgb = to_rgb();

		if (NONE == rgb.type) {
			return	"none";
		} else {
			ss	<< std::hex
				<< std::setfill('0') << std::setw(2) << (int)(rgb.a * 255)
				<< std::setfill('0') << std::setw(2) << (int)(rgb.b * 255)
				<< std::setfill('0') << std::setw(2) << (int)(rgb.c * 255);
		}

		return	ss.str();
	}

	std::string	to_string(void) const {
		std::stringstream	ss;
		ss	<< (int)type << std::endl
			<< a << std::endl << b << std::endl << c << std::endl << d << std::endl
			<< tranparency;
		return	ss.str();
	}

	void	from_string(const std::string&str) {
		std::stringstream	ss(str);
		from_string(ss);
	}
	void	from_string(std::stringstream&ss) {
		int		i;

		ss >> i;
		type = (colourtype)i;
		if (ss.peek() == '\n') {
			ss.ignore();
		}

		ss >> a;
		if (ss.peek() == '\n') {
			ss.ignore();
		}

		ss >> b;
		if (ss.peek() == '\n') {
			ss.ignore();
		}

		ss >> c;
		if (ss.peek() == '\n') {
			ss.ignore();
		}

		ss >> d;
		if (ss.peek() == '\n') {
			ss.ignore();
		}

		ss >> tranparency;
	}

	const	std::string	to_postscript(void) const {
		std::stringstream	ss;

		switch (type) {
		case	dt_colour::NONE:
			break;

		case	dt_colour::GREY:
			ss	<< a
				<< " setgray";
			break;

		case	dt_colour::RGB:
			ss	<< a << " "
				<< b << " "
				<< c
				<< " setrgbcolor";
			break;

		case	dt_colour::CMYK:
			ss	<< a << " "
				<< b << " "
				<< c << " "
				<< d
				<< " setcmykcolor";
			break;
		}

		return	ss.str();
	}


	bool	operator==(const dt_colour&rhs) const {
		if ((type == rhs.type) &&
			(a == rhs.a) &&
			(b == rhs.b) &&
			(c == rhs.c) &&
			(d == rhs.d) &&
			(tranparency == rhs.tranparency)) {
			return	true;
		}
		return	false;
	}
	bool	operator!=(const dt_colour& rhs) const { return !(*this == rhs); }
};


#endif	//	DT_COLOUR_H
