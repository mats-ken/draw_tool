#ifndef		DT_FILE_H
#define		DT_FILE_H


#include	<vector>
#include	<map>
#include	<string>

#include	"dt_area.h"
#include	"dt_layer.h"


class	dt_file {
private:
	std::map<std::string, size_t>	layer_names;
	std::vector<dt_area>			bounding_boxes;


public:
	std::vector<dt_layer>			layers;


	// Constructors
	dt_file(void) {}
	dt_file(const std::string&s) {
		from_string(s);
	}
	dt_file(std::stringstream&ss) {
		from_string(ss);
	}


	void	new_layer(void) {
				dt_layer	layer;
		const	size_t		n = layers.size() + 1;
		layer.name = "Layer " + std::to_string(n);
		layer_names[layer.name] = n;
		layers.push_back(layer);
	}

	void	del_layer(const std::string&name) {

	}


	void	from_file(const std::string&path) {
		std::ifstream		ifs(path);
		std::stringstream	ss;

		ss << ifs.rdbuf();
		ifs.close();

		from_string(ss);
	}
	void	to_file(const std::string&path) const {
		std::ofstream	ofs(path);
		ofs << to_string() << std::endl;
		ofs.close();
	}
	void	to_xml_file(const std::string&path) const {
		std::ofstream	ofs(path);
		ofs << to_xml(true) << std::endl;
		ofs.close();
	}
	void	to_svg_file(const std::string&path) const {
		std::ofstream	ofs(path);
		ofs << to_svg(true) << std::endl;
		ofs.close();
	}
	void	to_postscript_file(const std::string&path) const {
		std::ofstream	ofs(path);
		ofs << to_postscript(true) << std::endl;
		ofs.close();
	}
	void	to_pdf_file(const std::string&path) const {
		std::ofstream	ofs(path);
		ofs << to_pdf(true) << std::endl;
		ofs.close();
	}

	const	std::string	to_string(void) const;
	void	from_string(std::stringstream&ss);
	void	from_string(const std::string&str) {
		std::stringstream	ss(str);
		from_string(ss);
	}

	const	std::string	to_xml(const bool finalise = false) const;
	void	from_xml(const std::string&str);

	const	std::string	to_svg(const bool finalise = false, double width = 0.0, double height = 0.0) const;
	void	from_svg(const std::string&str);

	const	std::string	to_postscript(const bool finalise = false) const;
	//void	from_postscript(const std::string&str);

	const	std::string	to_pdf(const bool finalise = false) const;
	//void	from_pdf(const std::string&str);


	void	rasterise(const dt_area&area, dt_bitmap&bmp) const;


	bool	operator==(const dt_file&rhs) const {
		if (
			//(id				== rhs.id			) &&
			//(layer_names		== rhs.layer_names		) &&
			//(bounding_boxes		== rhs.bounding_boxes	) &&
			(layers				== rhs.layers			)
			) {
			return	true;
		}
		return	false;
	}
	bool	operator!=(const dt_file&rhs) const { return !(*this == rhs); }
};


#endif	//	DT_FILE_H
