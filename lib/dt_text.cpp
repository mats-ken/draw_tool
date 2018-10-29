#include "stdafx.h"


#include	<string>
#include	<iostream>
#include	<sstream>

#include	"finalisers.h"
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

	ss	<< "[TEXT]"					<< endl		// object_type=text
		<< "1"						<< endl		// version=1
		//<< id						<< endl
		<< pos.to_string()			<< endl
		<< line_colour.to_string()	<< endl
		<< fill_colour.to_string()	<< endl
		<< rotation					<< endl
		<< lines					<< endl
		<< text						<< endl
		<< mag_h					<< endl
		<< mag_v					<< endl
		<< font_name				<< endl
		<< font_size				<< endl
		<< underline				<< endl
		<< cursor_pos[0]			<< endl
		<< cursor_pos[1]			<< endl;

	return	ss.str();
}

void	dt_text::from_string(stringstream&ss)
{
	string	s;

	ss >> s;
	if ("[TEXT]" != s) {
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


const	string	dt_text::to_xml(const bool finalise) const
{
	stringstream	ss;
	string			s;

	int		lines = 0;
	stringstream	ss2(text);
	while (getline(ss2, s)) {
		lines++;
	}

	ss	<< "<text>"					<< endl		// object_type=path,
		<< "<version>1</version>"	<< endl		// version=1
		//							<< id << endl
		<< "<position>"				<< pos.to_string()			<< "</position>"		<< endl
		<< "<line_colour>"			<< line_colour.to_string()	<< "</line_colour>"		<< endl
		<< "<fill_colour>"			<< fill_colour.to_string()	<< "</fill_colour>"		<< endl
		<< "<rotation>"				<< rotation					<< "</rotation>"		<< endl
		<< "<lines>"				<< lines					<< "</lines>"			<< endl
		<< "<text>"					<< text						<< "</text>"			<< endl
		<< "<mag_h>"				<< mag_h					<< "</mag_h>"			<< endl
		<< "<mag_v>"				<< mag_v					<< "</mag_v>"			<< endl
		<< "<font_name>"			<< font_name				<< "</font_name>"		<< endl
		<< "<font_size>"			<< font_size				<< "</font_size>"		<< endl
		<< "<underline>"			<< underline				<< "</underline>"		<< endl;
		//<< "<cursor_pos>"			<< cursor_pos[0]			<< "</cursor_pos>"		<< endl
		//<< "<cursor_pos>"			<< cursor_pos[1]			<< "</cursor_pos>"		<< endl
	ss << "</text>" << endl;

	return	ss.str();
}

void	dt_text::from_xml(const string&str)
{

}


const	string	dt_text::to_svg(const bool finalise) const
{
	stringstream	ss;

	if (finalise) {
		ss << SVG_HEADER;
	}

	ss	<< "<text transform=\"matrix(1 0 0 1 "
		<< pos.x << " " << pos.y
		<< ")\" font-size=\""
		<< font_size
		<< "\" font-family=\""
		<< font_name
		<< "\">"
		<< text
		<< "</text>" << endl << endl;

	if (finalise) {
		ss << SVG_FOOTER << endl;
	}

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
