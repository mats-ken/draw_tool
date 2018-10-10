#include	"stdafx.h"


#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	<algorithm>

#include	"dt_bitmap.h"

#include	"dt_group.h"


using	namespace	std;


const	string		dt_group::to_string(void) const
{
	stringstream	ss;

	ss	<< "[GROUP]" << endl	// object_type
		<< "1" << endl;		// version

	ss	<< objects.size() << endl;
	for (const auto o : objects) {
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
		for (int k = 0; k < i; k++) {
			dt_obj	obj;
			obj.from_string(ss);
			objects.push_back(obj);
		}
		break;

	default:
		throw("invalid version");
		break;
	}
}


const	string		dt_group::to_xml(void) const
{
	stringstream	ss;


	return	ss.str();
}

void	dt_group::from_xml(const string & str)
{
}


const	string		dt_group::to_svg(const bool finalise) const
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

	for (const auto o : objects) {
		ss << o.to_svg();
	}

	if (finalise) {
		ss << "</svg>" << endl;
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

	for (const auto o : objects) {
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
