#include	"stdafx.h"


#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	<algorithm>

#include	"dt_bitmap.h"

#include	"dt_xxx.h"


using	namespace	std;


const	string		dt_xxx::to_string(void) const
{
	stringstream	ss;

	ss	<< "XXX" << endl	// object_type
		<< "1" << endl;		// version

	ss	<< yyy.size() << endl;
	for (auto o : yyy) {
		ss << o.to_string();
	}

	return	ss.str();
}

void	dt_xxx::from_string(stringstream & ss)
{
	int		i;
	string	s;

	ss >> s;
	if ("XXX" != s) {
		throw	"illegal type";
	}

	int		ver;
	ss >> ver;

	switch (ver) {
	case 1:
		ss >> id;

		break;

	default:
		throw("invalid version");
		break;
	}
}


const	string		dt_xxx::to_xml(void) const
{
	stringstream	ss;


	return	ss.str();
}

void	dt_xxx::from_xml(const string & str)
{
}


const	string	dt_xxx::to_svg(void) const
{
	stringstream	ss;


	return	ss.str();
}

void	dt_xxx::from_svg(const string&str)
{

}


const	string		dt_xxx::to_postscript(void) const
{
	stringstream	ss;


	return	ss.str();
}


const	string		dt_xxx::to_pdf(void) const
{
	stringstream	ss;


	return	ss.str();
}


void	dt_xxx::rasterise(dt_bitmap & bmp) const
{
}
