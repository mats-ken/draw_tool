#include	"stdafx.h"


#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	<algorithm>

#include	"dt_bitmap.h"

#include	"dt_XXX.h"


using	namespace	std;


const	std::string		dt_XXX::to_string(void) const
{
	stringstream	ss;

	ss	<< "XXX" << endl	// object_type
		<< "1" << endl;		// version

	ss	<< objects.size() << endl;
	for (auto o : objects) {
		ss << o.to_string();
	}

	return	ss.str();
}

void	dt_XXX::from_string(std::stringstream & ss)
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

const	std::string		dt_XXX::to_xml(void) const
{
	stringstream	ss;


	return	ss.str();
}

void	dt_XXX::from_xml(const std::string & str)
{
}

const	std::string		dt_XXX::to_postscript(void) const
{
	stringstream	ss;


	return	ss.str();
}

const	std::string		dt_XXX::to_pdf(void) const
{
	stringstream	ss;


	return	ss.str();
}

void	dt_XXX::rasterise(dt_bitmap & bmp) const
{
}
