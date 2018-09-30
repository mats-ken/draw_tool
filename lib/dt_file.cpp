#include	"stdafx.h"


#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	<algorithm>

#include	"dt_bitmap.h"

#include	"dt_file.h"


using	namespace	std;


const	string		dt_file::to_string(void) const
{
	stringstream	ss;

	ss	<< "FILE" << endl	// object_type
		<< "1" << endl;		// version

	for (const auto l : layers) {
		ss << l.to_string();
	}

	return	ss.str();
}

void	dt_file::from_string(stringstream & ss)
{
	int		i;
	string	s;

	ss >> s;
	if ("FILE" != s) {
		throw	"illegal type";
	}

	int		ver;
	ss >> ver;

	switch (ver) {
	case 1:
		//ss >> id;

		ss >> i;
		for (int k = 0; k < i; k++) {
			dt_layer	layer(ss);
			layers.push_back(layer);
		}

		break;

	default:
		throw("invalid version");
		break;
	}
}


const	string		dt_file::to_xml(void) const
{
	stringstream	ss;


	return	ss.str();
}

void	dt_file::from_xml(const string & str)
{
}

const	string	dt_file::to_svg(const bool finalise) const
{
	stringstream	ss;


	return	ss.str();
}

void	dt_file::from_svg(const string&str)
{

}


const	string		dt_file::to_postscript(const bool finalise) const
{
	stringstream	ss;

	if (finalise) {
		ss << "%!" << endl;
	}



	if (finalise) {
		ss << endl
			<< "showpage" << endl;
	}

	return	ss.str();
}


const	string		dt_file::to_pdf(const bool finalise) const
{
	stringstream	ss;


	return	ss.str();
}


void	dt_file::rasterise(const dt_area&area, dt_bitmap&bmp) const
{
}
