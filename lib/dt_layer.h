#ifndef		DT_LAYER_H
#define		DT_LAYER_H


#include	<string>
#include	<vector>

#include	"dt_group.h"


class	dt_layer {
private:

public:
	//int						id;

	std::string				name;
	dt_colour				sel_colour;	// colour to indicates selected items
	bool					visible;
	//bool					print; // to be printed

	std::vector<dt_group>	groups;


	// Constructors
	dt_layer(void) {
	}
	dt_layer(std::stringstream&ss) {
		from_string(ss);
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


	void	rasterise(dt_bitmap&bmp) const;


	bool	operator==(const dt_layer&rhs) const {
		if (
			//(id				== rhs.id			) &&
			(name			== rhs.name			) &&
			(sel_colour		== rhs.sel_colour	) &&
			(groups			== rhs.groups		) &&
			(visible		== rhs.visible		)
			) {
			return	true;
		}
		return	false;
	}
	bool	operator!=(const dt_layer&rhs) const { return !(*this == rhs); }
};


#endif	//	DT_LAYER_H
