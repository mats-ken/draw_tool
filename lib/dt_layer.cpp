#include "stdafx.h"

#include	"finalisers.h"

#include "dt_layer.h"


using	namespace	std;


const	string	dt_layer::to_string(void) const
{
	stringstream ss;

	ss	<< "[LAYER]" << endl	// object_type
		<< "1" << endl;		// version

	//ss << id << endl;

	ss	<< name << endl
		<< sel_colour.to_string() << endl
		<< (int)visible << endl;

	ss << groups.size() << endl;
	for (const auto&g : groups) {
		ss << g.to_string();
	}

	return	ss.str();
}

void	dt_layer::from_string(stringstream&ss)
{
	int		i;
	string	s;

	ss >> s;
	if ("[LAYER]" != s) {
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
		groups.resize(i);

		for (int k = 0; k < i; k++) {
			groups[k].from_string(ss);
		}

		break;

	default:
		throw("invalid version");
		break;
	}
}


const	string	dt_layer::to_xml(const bool finalise) const
{
	stringstream	ss;

	ss << "<layer>" << endl;

	for (const auto&g : groups) {
		ss << g.to_xml();
	}

	ss << "</layer>" << endl;

	return	ss.str();
}

void	dt_layer::from_xml(const string&str)
{

}


const	string	dt_layer::to_svg(const bool finalise) const
{
	stringstream	ss;

	if (finalise) {
		ss << SVG_HEADER;
	}

	for (const auto&g : groups) {
		ss << g.to_svg();
	}

	if (finalise) {
		ss << SVG_FOOTER << endl;
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

	for (const auto&g : groups) {
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

	for (const auto&g : groups) {
		ss << g.to_postscript();
	}

	return	ss.str();
}


void dt_layer::rasterise(dt_bitmap & bmp) const
{
}
