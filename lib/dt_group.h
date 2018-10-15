#ifndef		DT_GROUP_H
#define		DT_GROUP_H


#include	<string>
#include	<vector>

//#include	"dt_path.h"
//#include	"dt_text.h"
#include	"dt_obj.h"


class	dt_group {
private:

public:
	//int						id;

	std::vector<dt_obj>		objects;
	//std::vector<dt_path>	paths;
	//std::vector<dt_text>	texts;


	// Constructors
	dt_group(void){
	}
	dt_group(std::stringstream&ss) {
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


	bool	operator==(const dt_group&rhs) const {
		if (
			//(id		== rhs.id		) &&
			(objects	== rhs.objects	)// &&
			) {
			return	true;
		}
		return	false;
	}
	bool	operator!=(const dt_group&rhs) const { return !(*this == rhs); }
};


#endif	//	DT_GROUP_H
