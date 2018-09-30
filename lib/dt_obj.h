#ifndef		DT_OBJ_H
#define		DT_OBJ_H


#include	"dt_path.h"
#include	"dt_text.h"
#include	"dt_image.h"
#include	"dt_replica.h"


class	dt_obj {
private:


public:
	//int						id;

	// Only one path or text object can be registered so far.
	std::vector<dt_path>	paths;
	std::vector<dt_text>	texts;


	// Constructors
	dt_obj(void) {
	}
	dt_obj(const dt_path&path) {
		paths.push_back(path);
	}
	dt_obj(const dt_text&text) {
		texts.push_back(text);
	}
	dt_obj(std::stringstream&ss) {
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


	void	rasterise(const dt_area&area, dt_bitmap&bmp) const;


	bool	operator==(const dt_obj&rhs) const {
		if (
			//(id				== rhs.id			) &&
			(paths			== rhs.paths		) &&
			(texts			== rhs.texts		)
			) {
			return	true;
		}
		return	false;
	}
	bool	operator!=(const dt_obj&rhs) const { return !(*this == rhs); }
};


#endif	//	DT_OBJ_H
