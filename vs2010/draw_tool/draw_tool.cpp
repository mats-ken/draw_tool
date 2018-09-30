#include "stdafx.h"


#include "Form1.h"


using namespace System;
using namespace draw_tool;


[STAThreadAttribute]
int main(cli::array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew Form1());

	return 0;
}
