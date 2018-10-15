#include "stdafx.h"


#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	<algorithm>

#include	"finalisers.h"

#include	"dt_obj.h"


using	namespace	std;


const	string	dt_obj::to_string(void) const
{
	stringstream ss;

	ss	<< "[OBJECT]" << endl	// object_type
		<< "1" << endl;		// version

	//ss << id << endl;

	if (0 < paths.size()) {
		ss << "path" << endl;
		ss	<< paths[0].to_string();
	} else if (0 < texts.size()){
		ss << "text" << endl;
		ss	<< texts[0].to_string();
	}

		return	ss.str();
}

void	dt_obj::from_string(stringstream&ss)
{
	//int		i;
	string	s;

	ss >> s;
	if ("[OBJECT]" != s) {
		throw	"illegal type";
	}

	int		ver;
	ss >> ver;

	switch (ver) {
	case 1:
		//ss >> id;

		ss >> s;
		if ("path" == s) {
			dt_path		path;
			path.from_string(ss);
			paths.push_back(path);
		} else if ("text" == s) {
			dt_text		text;
			text.from_string(ss);
			texts.push_back(text);
		}

		break;

	default:
		throw("invalid version");
		break;
	}
}


const	string	dt_obj::to_xml(const bool finalise) const
{
	stringstream	ss;


	return	ss.str();
}

void	dt_obj::from_xml(const string&str)
{

}


const	string	dt_obj::to_svg(const bool finalise) const
{
	stringstream	ss;

	if (finalise) {
		ss << SVG_HEADER;
	}

	if (0 < paths.size()) {
		ss << paths[0].to_svg();
	} else if (0 < texts.size()) {
		ss << texts[0].to_svg();
	}

	if (finalise) {
		ss << "</svg>" << endl;
	}

	return	ss.str();
}

void	dt_obj::from_svg(const string&str)
{

}


const	string	dt_obj::to_postscript(const bool finalise) const
{
	stringstream	ss;

	if (finalise) {
		ss << "%!" << endl;
	}

	if (0 < paths.size()) {
		ss	<< paths[0].to_postscript();
	} else if (0 < texts.size()){
		ss	<< texts[0].to_postscript();
	}

	if (finalise) {
		ss << endl
			<< "showpage" << endl;
	}

	return	ss.str();
}


const	string	dt_obj::to_pdf(const bool finalise ) const
{
	stringstream	ss;


	return	ss.str();
}


void	dt_obj::rasterise(const dt_area&area, dt_bitmap&bmp) const
{

}
