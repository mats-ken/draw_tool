#include	"stdafx.h"


#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	<algorithm>

#include	"finalisers.h"
#include	"dt_bitmap.h"

#include	"dt_group.h"


using	namespace	std;


const	string		dt_group::to_string(void) const
{
	stringstream	ss;

	ss	<< "[GROUP]" << endl	// object_type
		<< "1" << endl;		// version

	ss	<< objects.size() << endl;
	for (const auto&o : objects) {
		ss << o.to_string();
	}

	return	ss.str();
}

void	dt_group::from_string(stringstream & ss)
{
	int		i;
	string	s;

	ss >> s;
	if ("[GROUP]" != s) {
		throw	"illegal type";
	}

	int		ver;
	ss >> ver;

	switch (ver) {
	case 1:
		//ss >> id;

		ss >> i;
		objects.resize(i);

		for (int k = 0; k < i; k++) {
			objects[k].from_string(ss);
		}

		break;

	default:
		throw("invalid version");
		break;
	}
}


const	string		dt_group::to_xml(const bool finalise) const
{
	stringstream	ss;

	ss << "<group>" << endl;

	for (const auto&o : objects) {
		ss << o.to_xml();
	}

	ss << "</group>" << endl;

	return	ss.str();
}

void	dt_group::from_xml(const string & str)
{
}


const	string		dt_group::to_svg(const bool finalise) const
{
	stringstream	ss;

	if (finalise) {
		ss << SVG_HEADER;
	}

	for (const auto&o : objects) {
		ss << o.to_svg();
	}

	if (finalise) {
		ss << SVG_FOOTER << endl;
	}

	return	ss.str();
}

void	dt_group::from_svg(const string & str)
{
}


const	string		dt_group::to_postscript(const bool finalise) const
{
	stringstream	ss;

	if (finalise) {
		ss << "%!" << endl;
	}

	for (const auto&o : objects) {
		ss << o.to_postscript();
	}

	if (finalise) {
		ss	<< endl
			<< "showpage" << endl;
	}

	return	ss.str();
}


const	string		dt_group::to_pdf(const bool finalise) const
{
	stringstream	ss;

	return	ss.str();
}

void	dt_group::rasterise(dt_bitmap & bmp) const
{
}
