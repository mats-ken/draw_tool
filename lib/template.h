#ifndef		dt_XXX_H
#define		dt_XXX_H


#include	<string>
#include	<vector>

#include	"dt_yyy.h"


class	dt_xxx {
private:

public:
	int						id;

	std::vector<dt_yyy>		yyy;


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


	void	rasterise(dt_bitmap&bmp) const;


	bool	operator==(const dt_xxx&rhs) const {
		if (
			//(id				== rhs.id			) &&
			1	// dummy
			) {
			return	true;
		}
		return	false;
	}
	bool	operator!=(const dt_xxx&rhs) const { return !(*this == rhs); }
};


#endif	//	dt_XXX_H
