#include "stdafx.h"


#include	<string>
#include	<iostream>
#include	<sstream>
#include	<fstream>
#include	<algorithm>

#include	"finalisers.h"

#include	"dt_path.h"


using	namespace	std;


const	string	dt_path::to_string(void) const
{
	stringstream ss;
	ss	<< "[PATH]"							<< endl		// object_type=path,
		<< "1"								<< endl		// version=1
		//<< id								<< endl
		<< (int)closed						<< endl
		<< line_width						<< endl
		<< line_colour.to_string()			<< endl
		<< fill_colour.to_string()			<< endl
		<< position.to_string()				<< endl
		<< scale.to_string()				<< endl
		<< rotation							<< endl
		<< edge_shape						<< endl
		<< (int)text_style					<< endl
		//<< text_id						<< endl
		<< anchor_pts.size()				<< endl;
	for (const auto&pt : anchor_pts) {
		ss << pt.to_string() << endl;
	}
	ss << endl;

	ss << selected_pts.size() << endl;
	for (const auto&pt : selected_pts) {
		ss << pt << endl;
	}

	return	ss.str();
}

void	dt_path::from_string(stringstream&ss)
{
	int		i;
	string	s;

	ss >> s;
	if ("[PATH]" != s) {
		throw	"illegal type";
	}

	int		ver;
	ss >> ver;

	switch (ver) {
	case 1:
		//ss >> id;
		ss >> i;
		closed = (0 == i) ? false : true;
		ss >> line_width;
		line_colour.from_string(ss);
		fill_colour.from_string(ss);
		position.from_string(ss);
		scale.from_string(ss);
		ss >> rotation;
		ss >> edge_shape;
		ss >> i;
		text_style = (textstyle)i;
		//ss >> text_id;

		ss >> i;
		anchor_pts.resize(i);

		for (int n = 0; n < i; n++) {
			anchor_pts[n].from_string(ss);
		}

		ss >> i;
		selected_pts.resize(i);

		for (int n = 0; n < i; n++) {
			ss >> selected_pts[n];
		}

		break;

	default:
		throw("invalid version");
		break;
	}
}


const	string	dt_path::to_xml(const bool finalise) const
{
	stringstream ss;

	ss	<< "<path>"					<< endl		// object_type=path,
		<< "<version>1</version>"	<< endl		// version=1
		//							<< id << endl
		<< "<closed>"				<< (int)closed				<< "</closed>"			<< endl
		<< "<line_width>"			<< line_width				<< "</line_width>"		<< endl
		<< "<line_colour>"			<< line_colour.to_string()	<< "</line_colour>"		<< endl
		<< "<fill_colour>"			<< fill_colour.to_string()	<< "</fill_colour>"		<< endl
		<< "<position>"				<< position.to_string()		<< "</position>"		<< endl
		<< "<scale>"				<< scale.to_string()		<< "</scale>"			<< endl
		<< "<rotation>"				<< rotation					<< "</rotation>"		<< endl
		<< "<edge_shape>"			<< edge_shape				<< "</edge_shape>"		<< endl
		<< "<text_style>"			<< (int)text_style			<< "</(int)text_style>"	<< endl;
		//<< text_id << endl
	for (const auto&pt : anchor_pts) {
		ss << "<anchor_pt>" << pt.to_string() << "</anchor_pt>" << endl;
	}
	ss << "</path>" << endl;

	return	ss.str();
}

void	dt_path::from_xml(const string&str)
{

}


const	string	dt_path::to_svg(const bool finalise) const
{
	stringstream	ss;

	const	double	height =  600.0;	// dummy

	if (finalise) {
		ss << SVG_HEADER;
	}

	ss	<< "<path" << endl
		<< "stroke=\"#" << line_colour.to_webstr() << "\" stroke-width=\"" << line_width << "\" fill=\"#" << fill_colour.to_webstr() << "\"" << endl
		<< "d=\"" << endl
		<< "M" << anchor_pts[0].x * scale.x + position.x << "," << height - (anchor_pts[0].y * scale.y + position.y) << endl;
	for (size_t i = 1; i < anchor_pts.size(); i += 3) {
		ss	<< "C"
			<< anchor_pts[i    ].x * scale.x + position.x << " " << height - (anchor_pts[i    ].y * scale.y + position.y) << ","
			<< anchor_pts[i + 1].x * scale.x + position.x << " " << height - (anchor_pts[i + 1].y * scale.y + position.y) << ","
			<< anchor_pts[i + 2].x * scale.x + position.x << " " << height - (anchor_pts[i + 2].y * scale.y + position.y) << endl;
	}
	if (closed) {
		ss << "Z" << endl;
	}
	ss << "\"/>" << endl << endl;

	if (finalise) {
		ss << SVG_FOOTER << endl;
	}

	return	ss.str();
}

void	dt_path::from_svg(const string&str)
{

}


const	string	dt_path::to_postscript(const bool finalise) const
{
	if (0 == anchor_pts.size()) {
		return	"";
	}

	stringstream	ss;

	if (finalise) {
		ss << "%!" << endl;
	}

	ss //<< "gsave" << endl
		//<< position.x << " " << position.y << " translate" << endl
		//<< scale.x << " " << scale.y << " scale" << endl
		//<< rotation << " rotate" << endl
		<< "newpath" << endl
		<< anchor_pts[0].x * scale.x + position.x << " " << anchor_pts[0].y * scale.x + position.x << " moveto" << endl;
	for (size_t i = 1; i < anchor_pts.size(); i += 3) {
		ss	<< anchor_pts[i    ].x * scale.x + position.x << " " << anchor_pts[i    ].y * scale.x + position.x << endl
			<< anchor_pts[i + 1].x * scale.x + position.x << " " << anchor_pts[i + 1].y * scale.x + position.x << endl
			<< anchor_pts[i + 2].x * scale.x + position.x << " " << anchor_pts[i + 2].y * scale.x + position.x << " curveto" << endl;
	}

	if (closed) {
		ss << "closepath" << endl;
	}

	ss << "gsave" << endl;

	switch (fill_colour.type) {
	case	dt_colour::NONE:
		break;

	case	dt_colour::GREY:
	case	dt_colour::RGB:
	case	dt_colour::CMYK:
		ss	<< fill_colour.to_postscript()
			<< " fill" << endl;
		break;
	}

	ss << "grestore" << endl;

	switch (line_colour.type) {
	case	dt_colour::NONE:
		break;

	case	dt_colour::GREY:
	case	dt_colour::RGB:
	case	dt_colour::CMYK:
		ss	<< line_colour.to_postscript() << " "
			<< line_width << " setlinewidth stroke" << endl;
		break;

	default:
		throw	"illegal colour-type";
	}

	switch (text_style) {
	case	dt_path::textstyle::NONE:
		break;
	}
	//ss << "grestore" << endl;

	if (finalise) {
		ss	<< endl
			<< "showpage" << endl;
	}

	return	ss.str();
}


const	string	dt_path::to_pdf(const bool finalise) const
{
	return	"";
}


void	dt_path::rasterise(const dt_area&area, dt_bitmap&bmp) const
{

}
