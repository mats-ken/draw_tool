#include "stdafx.h"


#include	<string>
#include	<iostream>
#include	<sstream>

#include	"dt_bitmap.h"
#include	"dt_text.h"


using	namespace	std;


const	string	dt_text::to_string(void) const
{
	stringstream	ss;
	string			s;

	int		lines = 0;
	stringstream	ss2(text);
	while (getline(ss2, s)) {
		lines++;
	}

	ss	<< "TEXT" << endl	// object_type=text
		<< "1" << endl		// version=1
		//<< id << endl
		<< pos.to_string() << endl
		<< line_colour.to_string() << endl
		<< fill_colour.to_string() << endl
		<< rotation << endl
		<< lines << endl
		<< text << endl
		<< mag_h << endl
		<< mag_v << endl
		<< font_name << endl
		<< font_size << endl
		<< underline << endl
		<< cursor_pos[0] << endl
		<< cursor_pos[1] << endl;

	return	ss.str();
}

void	dt_text::from_string(stringstream&ss)
{
	string	s;

	ss >> s;
	if ("TEXT" != s) {
		throw	"illegal type";
	}

	int		ver;
	ss >> ver;

	switch (ver) {
	case 1:
		//ss >> id;
		pos.from_string(ss);
		line_colour.from_string(ss);
		fill_colour.from_string(ss);
		ss >> rotation;
		int		lines;
		ss >> lines;
		getline(ss, s);
		for (int i = 0; i < lines; i++) {
			getline(ss, s);
			if (0 < i) {
				text += "\n";
			}
			text += s;
		}
		ss >> mag_h;
		ss>>mag_v;
		getline(ss, s);
		getline(ss, font_name);
		ss >> font_size;
		ss >> underline;
		ss >> cursor_pos[0];
		ss >> cursor_pos[1];
		break;

	default:
		throw("invalid version");
		break;
	}
}


const	string	dt_text::to_xml(void) const
{
	return	"";
}

void	dt_text::from_xml(const string&str)
{

}


const	string	dt_text::to_svg(const bool finalise) const
{
	stringstream	ss;


	return	ss.str();
}

void	dt_text::from_svg(const string&str)
{

}


const	string	dt_text::to_postscript(const bool finalise) const
{
	stringstream	ss;

	if (finalise) {
		ss << "%!" << endl;
	}

	ss	<< "/" + font_name + " findfont" << endl
		<< font_size << " scalefont" << endl
		<< "setfont" << endl
		<< fill_colour.to_postscript() << endl
		<< pos.to_string(string(" ")) << " moveto" << endl
		<< "(" + text + ") show" << endl;

	if (finalise) {
		ss	<< endl
			<< "showpage" << endl;
	}

	return	ss.str();
}


const	string	dt_text::to_pdf(const bool finalise) const
{
	stringstream	ss;


	return	ss.str();
}


void	dt_text::rasterise(dt_bitmap & bmp) const
{
}
