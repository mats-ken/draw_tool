#ifndef		DT_POSITION_H
#define		DT_POSITION_H


#include	<string>
#include	<sstream>


class	dt_position {
private:

public:
	double	x, y;


	dt_position(void) {
		x = y = 0.0;
	}

	dt_position(const double x_in, const double y_in) {
		x = x_in;
		y = y_in;
	}


	std::string	to_string(void) const {
		std::stringstream	ss;
		ss << x << std::endl << y;
		return	ss.str();
	}
	std::string	to_string(std::string&delim) const {
		std::stringstream	ss;
		ss << x << delim << y;
		return	ss.str();
	}

	void	from_string(const std::string&s) {
		std::stringstream	ss(s);
		from_string(ss);
	}
	void	from_string(std::stringstream&ss) {
		ss >> x;
		if (ss.peek() == '\n') {
			ss.ignore();
		}
		ss >> y;
	}


	bool	operator==(const dt_position&rhs) const {
		if ((x == rhs.x) &&
			(y == rhs.y)) {
			return	true;
		}
		return	false;
	}
	bool	operator!=(const dt_position&rhs) const { return !(*this == rhs); }

	const	dt_position	operator+(const dt_position&rhs) const {
		return{ x + rhs.x, y + rhs.y };
	}

	const	dt_position	operator-(const dt_position&rhs) const {
		return	{ x - rhs.x, y - rhs.y };
	}

	const	dt_position	operator/(const double&rhs) const {
		return	{ x / rhs, y / rhs };
	}
};


#endif	//	DT_POSITION_H
