#ifndef		DT_FILE_H
#define		DT_FILE_H


#include	<string>


class	dt_file {
private:

public:
	const	std::string	to_string(void);
	void	from_string(const std::string&str);

	const	std::string	to_xml(void);
	void	from_xml(const std::string&str);

	const	std::string	to_svg(void);
	void	from_svg(const std::string&str);
};


#endif	//	DT_FILE_H
