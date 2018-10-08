#include "stdafx.h"


#include "dt_layer.h"


using	namespace	std;


const	string	dt_layer::to_string(void) const
{
	stringstream ss;

	ss	<< "LAYER" << endl	// object_type
		<< "1" << endl;		// version

	//ss << id << endl;

	ss	<< name << endl
		<< sel_colour.to_string() << endl
		<< (int)visible << endl;

	ss << groups.size() << endl;
	for (const auto g : groups) {
		ss << g.to_string();
	}

	return	ss.str();
}

void	dt_layer::from_string(stringstream&ss)
{
	int		i;
	string	s;

	ss >> s;
	if ("LAYER" != s) {
		throw	"illegal type";
	}

	int		ver;
	ss >> ver;

	switch (ver) {
	case 1:
		//ss >> id;

		getline(ss, s);	// dummy read
		getline(ss, name);
		sel_colour.from_string(ss);
		ss >> i;
		visible = (0 != i);

		ss >> i;
		for (int k = 0; k < i; k++) {
			dt_group	group(ss);
			groups.push_back(group);
		}

		break;

	default:
		throw("invalid version");
		break;
	}
}


const	string	dt_layer::to_xml(void) const
{
	stringstream	ss;


	return	ss.str();
}

void	dt_layer::from_xml(const string&str)
{

}


const	string	dt_layer::to_svg(const bool finalise) const
{
	stringstream	ss;

	if (finalise) {
		ss << R"###(<?xml version="1.0" encoding="utf-8"?>
<!-- Generator: MyDrawer -->
<svg version="1.1"
xmlns="http://www.w3.org/2000/svg"
xmlns:xlink="http://www.w3.org/1999/xlink"
x="0px" y="0px"
viewBox="0 0 1000 600" >

)###";
	}

	for (const auto g : groups) {
		ss << g.to_svg();
	}

	if (finalise) {
		ss << "</svg>" << endl;
	}

	return	ss.str();
}

void	dt_layer::from_svg(const string&str)
{

}


const	string	dt_layer::to_postscript(const bool finalise) const
{
	stringstream	ss;

	if (finalise) {
		ss << "%!" << endl;
	}

	for (const auto g : groups) {
		ss << g.to_postscript();
	}

	if (finalise) {
		ss << endl
			<< "showpage" << endl;
	}

	return	ss.str();
}


const	string	dt_layer::to_pdf(const bool finalise) const
{
	stringstream	ss;

	for (auto g : groups) {
		ss << g.to_postscript();
	}

	return	ss.str();
}


void dt_layer::rasterise(dt_bitmap & bmp) const
{
}
