#pragma once


#include	<string>
#include	<vector>
#include	<map>

#include	<math.h>

#include	"../../lib/dt_file.h"


using	namespace	System;
using	namespace	std;


#define		S2s(S)	MarshalString(S)				// Converts "System::String"	->	"std::string"
#define		s2S(s)	(gcnew String((s).c_str()))		// Converts "std::string"		->	"System::String"


// 方法: System::String を標準文字列に変換する
// https://msdn.microsoft.com/ja-jp/library/1b4az623.aspx

string	MarshalString(System::String^ s)
{
	const char* chars = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s)).ToPointer();
	const	string os = chars;
	Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)chars));
	return	os;
}


struct	file_stat_t {
	bool			new_file;
	string			path;
	dt_file			file;
	size_t			current_layer_no;
	dt_position		centre;
	double			scale;
	dt_bitmap		mask;
};


size_t					new_file_count = 1;
size_t					current_file_no = 0;
vector<file_stat_t>		file_stats;


namespace draw_tool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();

			textBox1->Anchor = AnchorStyles::Top + AnchorStyles::Right+ AnchorStyles::Bottom;
			pictureBox1->Anchor = AnchorStyles::Right + AnchorStyles::Bottom;
			buttonApply->Anchor = AnchorStyles::Right + AnchorStyles::Bottom;

			webBrowser1->ScrollBarsEnabled = true;
			textBox1->ScrollBars = ScrollBars::Both;
			textBox1->WordWrap = false;

			pictureBox1->Image = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height, Drawing::Imaging::PixelFormat::Format24bppRgb);

			proc_tool_buttons("Select");
		}

	protected:
		/// <summary>
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonSelect;
	private: System::Windows::Forms::Button^  buttonDirectSelect;
	private: System::Windows::Forms::Button^  buttonPen;
	private: System::Windows::Forms::Button^  buttonScissors;
	private: System::Windows::Forms::Button^  buttonRectangle;
	private: System::Windows::Forms::Button^  buttonEllipse;
	private: System::Windows::Forms::Button^  buttonZoom;
	private: System::Windows::Forms::Button^  buttonAnchorPoint;
	private: System::Windows::Forms::Button^  buttonAddAnchorPoint;
	private: System::Windows::Forms::Button^  buttonDeleteAnchorPoint;
	private: System::Windows::Forms::Button^  buttonType;
	private: System::Windows::Forms::Button^  buttonHand;
	private: System::Windows::Forms::Button^  buttonScale;
	private: System::Windows::Forms::Button^  buttonRotate;
	private: System::Windows::Forms::Button^  buttonReflect;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  labelSelectedTool;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  printToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  preferencesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zoomInToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zoomOutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  simulsaveToolStripMenuItem;
	private: System::Windows::Forms::WebBrowser^  webBrowser1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  buttonApply;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::CheckBox^  checkBoxWrap;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	private: System::Windows::Forms::VScrollBar^  vScrollBar1;
	private: System::Windows::Forms::TrackBar^  trackBarZoom;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownZoom;
	private: System::Windows::Forms::Button^  buttonRevert;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  windowsToolStripMenuItem;


	private:
		/// <summary>
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonSelect = (gcnew System::Windows::Forms::Button());
			this->buttonDirectSelect = (gcnew System::Windows::Forms::Button());
			this->buttonPen = (gcnew System::Windows::Forms::Button());
			this->buttonScissors = (gcnew System::Windows::Forms::Button());
			this->buttonRectangle = (gcnew System::Windows::Forms::Button());
			this->buttonEllipse = (gcnew System::Windows::Forms::Button());
			this->buttonZoom = (gcnew System::Windows::Forms::Button());
			this->buttonAnchorPoint = (gcnew System::Windows::Forms::Button());
			this->buttonAddAnchorPoint = (gcnew System::Windows::Forms::Button());
			this->buttonDeleteAnchorPoint = (gcnew System::Windows::Forms::Button());
			this->buttonType = (gcnew System::Windows::Forms::Button());
			this->buttonHand = (gcnew System::Windows::Forms::Button());
			this->buttonScale = (gcnew System::Windows::Forms::Button());
			this->buttonRotate = (gcnew System::Windows::Forms::Button());
			this->buttonReflect = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->labelSelectedTool = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->simulsaveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->printToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->preferencesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomInToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonApply = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->checkBoxWrap = (gcnew System::Windows::Forms::CheckBox());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
			this->trackBarZoom = (gcnew System::Windows::Forms::TrackBar());
			this->numericUpDownZoom = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonRevert = (gcnew System::Windows::Forms::Button());
			this->windowsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarZoom))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownZoom))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonSelect
			// 
			this->buttonSelect->Location = System::Drawing::Point(12, 27);
			this->buttonSelect->Name = L"buttonSelect";
			this->buttonSelect->Size = System::Drawing::Size(28, 23);
			this->buttonSelect->TabIndex = 0;
			this->buttonSelect->TabStop = false;
			this->buttonSelect->Text = L"V";
			this->buttonSelect->UseVisualStyleBackColor = true;
			this->buttonSelect->Click += gcnew System::EventHandler(this, &Form1::buttonSelect_Click);
			// 
			// buttonDirectSelect
			// 
			this->buttonDirectSelect->Location = System::Drawing::Point(39, 27);
			this->buttonDirectSelect->Name = L"buttonDirectSelect";
			this->buttonDirectSelect->Size = System::Drawing::Size(28, 23);
			this->buttonDirectSelect->TabIndex = 1;
			this->buttonDirectSelect->TabStop = false;
			this->buttonDirectSelect->Text = L"A";
			this->buttonDirectSelect->UseVisualStyleBackColor = true;
			this->buttonDirectSelect->Click += gcnew System::EventHandler(this, &Form1::buttonDirectSelect_Click);
			// 
			// buttonPen
			// 
			this->buttonPen->Location = System::Drawing::Point(12, 56);
			this->buttonPen->Name = L"buttonPen";
			this->buttonPen->Size = System::Drawing::Size(28, 23);
			this->buttonPen->TabIndex = 2;
			this->buttonPen->TabStop = false;
			this->buttonPen->Text = L"P";
			this->buttonPen->UseVisualStyleBackColor = true;
			this->buttonPen->Click += gcnew System::EventHandler(this, &Form1::buttonPen_Click);
			// 
			// buttonScissors
			// 
			this->buttonScissors->Location = System::Drawing::Point(66, 143);
			this->buttonScissors->Name = L"buttonScissors";
			this->buttonScissors->Size = System::Drawing::Size(28, 23);
			this->buttonScissors->TabIndex = 3;
			this->buttonScissors->TabStop = false;
			this->buttonScissors->Text = L"C";
			this->buttonScissors->UseVisualStyleBackColor = true;
			this->buttonScissors->Click += gcnew System::EventHandler(this, &Form1::buttonScissors_Click);
			// 
			// buttonRectangle
			// 
			this->buttonRectangle->Location = System::Drawing::Point(12, 85);
			this->buttonRectangle->Name = L"buttonRectangle";
			this->buttonRectangle->Size = System::Drawing::Size(28, 23);
			this->buttonRectangle->TabIndex = 4;
			this->buttonRectangle->TabStop = false;
			this->buttonRectangle->Text = L"M";
			this->buttonRectangle->UseVisualStyleBackColor = true;
			this->buttonRectangle->Click += gcnew System::EventHandler(this, &Form1::buttonRectangle_Click);
			// 
			// buttonEllipse
			// 
			this->buttonEllipse->Location = System::Drawing::Point(39, 85);
			this->buttonEllipse->Name = L"buttonEllipse";
			this->buttonEllipse->Size = System::Drawing::Size(28, 23);
			this->buttonEllipse->TabIndex = 5;
			this->buttonEllipse->TabStop = false;
			this->buttonEllipse->Text = L"L";
			this->buttonEllipse->UseVisualStyleBackColor = true;
			this->buttonEllipse->Click += gcnew System::EventHandler(this, &Form1::buttonEllipse_Click);
			// 
			// buttonZoom
			// 
			this->buttonZoom->Location = System::Drawing::Point(12, 143);
			this->buttonZoom->Name = L"buttonZoom";
			this->buttonZoom->Size = System::Drawing::Size(28, 23);
			this->buttonZoom->TabIndex = 6;
			this->buttonZoom->TabStop = false;
			this->buttonZoom->Text = L"Z";
			this->buttonZoom->UseVisualStyleBackColor = true;
			this->buttonZoom->Click += gcnew System::EventHandler(this, &Form1::buttonZoom_Click);
			// 
			// buttonAnchorPoint
			// 
			this->buttonAnchorPoint->Location = System::Drawing::Point(66, 27);
			this->buttonAnchorPoint->Name = L"buttonAnchorPoint";
			this->buttonAnchorPoint->Size = System::Drawing::Size(28, 23);
			this->buttonAnchorPoint->TabIndex = 7;
			this->buttonAnchorPoint->TabStop = false;
			this->buttonAnchorPoint->Text = L"^";
			this->buttonAnchorPoint->UseVisualStyleBackColor = true;
			this->buttonAnchorPoint->Click += gcnew System::EventHandler(this, &Form1::buttonAnchorPoint_Click);
			// 
			// buttonAddAnchorPoint
			// 
			this->buttonAddAnchorPoint->Location = System::Drawing::Point(39, 56);
			this->buttonAddAnchorPoint->Name = L"buttonAddAnchorPoint";
			this->buttonAddAnchorPoint->Size = System::Drawing::Size(28, 23);
			this->buttonAddAnchorPoint->TabIndex = 8;
			this->buttonAddAnchorPoint->TabStop = false;
			this->buttonAddAnchorPoint->Text = L"P+";
			this->buttonAddAnchorPoint->UseVisualStyleBackColor = true;
			this->buttonAddAnchorPoint->Click += gcnew System::EventHandler(this, &Form1::buttonAddAnchorPoint_Click);
			// 
			// buttonDeleteAnchorPoint
			// 
			this->buttonDeleteAnchorPoint->Location = System::Drawing::Point(66, 56);
			this->buttonDeleteAnchorPoint->Name = L"buttonDeleteAnchorPoint";
			this->buttonDeleteAnchorPoint->Size = System::Drawing::Size(28, 23);
			this->buttonDeleteAnchorPoint->TabIndex = 9;
			this->buttonDeleteAnchorPoint->TabStop = false;
			this->buttonDeleteAnchorPoint->Text = L"P-";
			this->buttonDeleteAnchorPoint->UseVisualStyleBackColor = true;
			this->buttonDeleteAnchorPoint->Click += gcnew System::EventHandler(this, &Form1::buttonDeleteAnchorPoint_Click);
			// 
			// buttonType
			// 
			this->buttonType->Location = System::Drawing::Point(66, 85);
			this->buttonType->Name = L"buttonType";
			this->buttonType->Size = System::Drawing::Size(28, 23);
			this->buttonType->TabIndex = 10;
			this->buttonType->TabStop = false;
			this->buttonType->Text = L"T";
			this->buttonType->UseVisualStyleBackColor = true;
			this->buttonType->Click += gcnew System::EventHandler(this, &Form1::buttonType_Click);
			// 
			// buttonHand
			// 
			this->buttonHand->Location = System::Drawing::Point(39, 143);
			this->buttonHand->Name = L"buttonHand";
			this->buttonHand->Size = System::Drawing::Size(28, 23);
			this->buttonHand->TabIndex = 11;
			this->buttonHand->TabStop = false;
			this->buttonHand->Text = L"H";
			this->buttonHand->UseVisualStyleBackColor = true;
			this->buttonHand->Click += gcnew System::EventHandler(this, &Form1::buttonHand_Click);
			// 
			// buttonScale
			// 
			this->buttonScale->Location = System::Drawing::Point(12, 114);
			this->buttonScale->Name = L"buttonScale";
			this->buttonScale->Size = System::Drawing::Size(28, 23);
			this->buttonScale->TabIndex = 12;
			this->buttonScale->TabStop = false;
			this->buttonScale->Text = L"S";
			this->buttonScale->UseVisualStyleBackColor = true;
			this->buttonScale->Click += gcnew System::EventHandler(this, &Form1::buttonScale_Click);
			// 
			// buttonRotate
			// 
			this->buttonRotate->Location = System::Drawing::Point(39, 114);
			this->buttonRotate->Name = L"buttonRotate";
			this->buttonRotate->Size = System::Drawing::Size(28, 23);
			this->buttonRotate->TabIndex = 13;
			this->buttonRotate->TabStop = false;
			this->buttonRotate->Text = L"R";
			this->buttonRotate->UseVisualStyleBackColor = true;
			this->buttonRotate->Click += gcnew System::EventHandler(this, &Form1::buttonRotate_Click);
			// 
			// buttonReflect
			// 
			this->buttonReflect->Location = System::Drawing::Point(66, 114);
			this->buttonReflect->Name = L"buttonReflect";
			this->buttonReflect->Size = System::Drawing::Size(28, 23);
			this->buttonReflect->TabIndex = 14;
			this->buttonReflect->TabStop = false;
			this->buttonReflect->Text = L"O";
			this->buttonReflect->UseVisualStyleBackColor = true;
			this->buttonReflect->Click += gcnew System::EventHandler(this, &Form1::buttonReflect_Click);
			// 
			// labelSelectedTool
			// 
			this->labelSelectedTool->AutoSize = true;
			this->labelSelectedTool->Location = System::Drawing::Point(12, 169);
			this->labelSelectedTool->Name = L"labelSelectedTool";
			this->labelSelectedTool->Size = System::Drawing::Size(23, 12);
			this->labelSelectedTool->TabIndex = 15;
			this->labelSelectedTool->Text = L"---";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->viewToolStripMenuItem, this->windowsToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1184, 24);
			this->menuStrip1->TabIndex = 16;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->newToolStripMenuItem,
					this->openToolStripMenuItem, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->simulsaveToolStripMenuItem, this->exportToolStripMenuItem,
					this->printToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->newToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->openToolStripMenuItem->Text = L"Open....";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::S));
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->saveAsToolStripMenuItem->Text = L"Save as....";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsToolStripMenuItem_Click);
			// 
			// simulsaveToolStripMenuItem
			// 
			this->simulsaveToolStripMenuItem->Name = L"simulsaveToolStripMenuItem";
			this->simulsaveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt)
				| System::Windows::Forms::Keys::S));
			this->simulsaveToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->simulsaveToolStripMenuItem->Text = L"Simul-save";
			this->simulsaveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::simulsaveToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->exportToolStripMenuItem->Text = L"Export....";
			this->exportToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exportToolStripMenuItem_Click);
			// 
			// printToolStripMenuItem
			// 
			this->printToolStripMenuItem->Name = L"printToolStripMenuItem";
			this->printToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->printToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->printToolStripMenuItem->Text = L"Print....";
			this->printToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::printToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->undoToolStripMenuItem,
					this->redoToolStripMenuItem, this->cutToolStripMenuItem, this->copyToolStripMenuItem, this->pasteToolStripMenuItem, this->preferencesToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// undoToolStripMenuItem
			// 
			this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
			this->undoToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->undoToolStripMenuItem->Text = L"Undo";
			this->undoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::undoToolStripMenuItem_Click);
			// 
			// redoToolStripMenuItem
			// 
			this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
			this->redoToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->redoToolStripMenuItem->Text = L"Redo";
			this->redoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::redoToolStripMenuItem_Click);
			// 
			// cutToolStripMenuItem
			// 
			this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
			this->cutToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->cutToolStripMenuItem->Text = L"Cut";
			this->cutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::cutToolStripMenuItem_Click);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->copyToolStripMenuItem->Text = L"Copy";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::copyToolStripMenuItem_Click);
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->pasteToolStripMenuItem->Text = L"Paste";
			this->pasteToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::pasteToolStripMenuItem_Click);
			// 
			// preferencesToolStripMenuItem
			// 
			this->preferencesToolStripMenuItem->Name = L"preferencesToolStripMenuItem";
			this->preferencesToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->preferencesToolStripMenuItem->Text = L"Preferences";
			this->preferencesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::preferencesToolStripMenuItem_Click);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->zoomInToolStripMenuItem,
					this->zoomOutToolStripMenuItem
			});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// zoomInToolStripMenuItem
			// 
			this->zoomInToolStripMenuItem->Name = L"zoomInToolStripMenuItem";
			this->zoomInToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->zoomInToolStripMenuItem->Text = L"Zoom In";
			this->zoomInToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::zoomInToolStripMenuItem_Click);
			// 
			// zoomOutToolStripMenuItem
			// 
			this->zoomOutToolStripMenuItem->Name = L"zoomOutToolStripMenuItem";
			this->zoomOutToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->zoomOutToolStripMenuItem->Text = L"Zoom Out";
			this->zoomOutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::zoomOutToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->aboutToolStripMenuItem->Text = L"About....";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// webBrowser1
			// 
			this->webBrowser1->Location = System::Drawing::Point(100, 27);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->Size = System::Drawing::Size(730, 400);
			this->webBrowser1->TabIndex = 17;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(857, 31);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(315, 732);
			this->textBox1->TabIndex = 18;
			// 
			// buttonApply
			// 
			this->buttonApply->Location = System::Drawing::Point(1097, 769);
			this->buttonApply->Name = L"buttonApply";
			this->buttonApply->Size = System::Drawing::Size(75, 23);
			this->buttonApply->TabIndex = 19;
			this->buttonApply->Text = L"Apply";
			this->buttonApply->UseVisualStyleBackColor = true;
			this->buttonApply->Click += gcnew System::EventHandler(this, &Form1::buttonApply_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(100, 451);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(730, 400);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 20;
			this->pictureBox1->TabStop = false;
			// 
			// checkBoxWrap
			// 
			this->checkBoxWrap->AutoSize = true;
			this->checkBoxWrap->Location = System::Drawing::Point(857, 773);
			this->checkBoxWrap->Name = L"checkBoxWrap";
			this->checkBoxWrap->Size = System::Drawing::Size(49, 16);
			this->checkBoxWrap->TabIndex = 21;
			this->checkBoxWrap->Text = L"Wrap";
			this->checkBoxWrap->UseVisualStyleBackColor = true;
			this->checkBoxWrap->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxWrap_CheckedChanged);
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(100, 431);
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(730, 17);
			this->hScrollBar1->TabIndex = 22;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::hScrollBar1_Scroll);
			// 
			// vScrollBar1
			// 
			this->vScrollBar1->Location = System::Drawing::Point(833, 451);
			this->vScrollBar1->Name = L"vScrollBar1";
			this->vScrollBar1->Size = System::Drawing::Size(17, 400);
			this->vScrollBar1->TabIndex = 23;
			this->vScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::vScrollBar1_Scroll);
			// 
			// trackBarZoom
			// 
			this->trackBarZoom->Location = System::Drawing::Point(853, 806);
			this->trackBarZoom->Maximum = 200;
			this->trackBarZoom->Minimum = -200;
			this->trackBarZoom->Name = L"trackBarZoom";
			this->trackBarZoom->Size = System::Drawing::Size(233, 45);
			this->trackBarZoom->TabIndex = 24;
			this->trackBarZoom->TabStop = false;
			this->trackBarZoom->Scroll += gcnew System::EventHandler(this, &Form1::trackBarZoom_Scroll);
			// 
			// numericUpDownZoom
			// 
			this->numericUpDownZoom->Location = System::Drawing::Point(1097, 806);
			this->numericUpDownZoom->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDownZoom->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownZoom->Name = L"numericUpDownZoom";
			this->numericUpDownZoom->Size = System::Drawing::Size(75, 19);
			this->numericUpDownZoom->TabIndex = 25;
			this->numericUpDownZoom->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDownZoom->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDownZoom_ValueChanged);
			// 
			// buttonRevert
			// 
			this->buttonRevert->Location = System::Drawing::Point(1016, 769);
			this->buttonRevert->Name = L"buttonRevert";
			this->buttonRevert->Size = System::Drawing::Size(75, 23);
			this->buttonRevert->TabIndex = 26;
			this->buttonRevert->Text = L"Revert";
			this->buttonRevert->UseVisualStyleBackColor = true;
			this->buttonRevert->Click += gcnew System::EventHandler(this, &Form1::buttonRevert_Click);
			// 
			// windowsToolStripMenuItem
			// 
			this->windowsToolStripMenuItem->Name = L"windowsToolStripMenuItem";
			this->windowsToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->windowsToolStripMenuItem->Text = L"Windows";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 861);
			this->Controls->Add(this->buttonRevert);
			this->Controls->Add(this->numericUpDownZoom);
			this->Controls->Add(this->trackBarZoom);
			this->Controls->Add(this->vScrollBar1);
			this->Controls->Add(this->hScrollBar1);
			this->Controls->Add(this->checkBoxWrap);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->buttonApply);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->webBrowser1);
			this->Controls->Add(this->labelSelectedTool);
			this->Controls->Add(this->buttonReflect);
			this->Controls->Add(this->buttonRotate);
			this->Controls->Add(this->buttonScale);
			this->Controls->Add(this->buttonHand);
			this->Controls->Add(this->buttonType);
			this->Controls->Add(this->buttonDeleteAnchorPoint);
			this->Controls->Add(this->buttonAddAnchorPoint);
			this->Controls->Add(this->buttonAnchorPoint);
			this->Controls->Add(this->buttonZoom);
			this->Controls->Add(this->buttonEllipse);
			this->Controls->Add(this->buttonRectangle);
			this->Controls->Add(this->buttonScissors);
			this->Controls->Add(this->buttonPen);
			this->Controls->Add(this->buttonDirectSelect);
			this->Controls->Add(this->buttonSelect);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(1200, 900);
			this->Name = L"Form1";
			this->Text = L"My Drawer v0.3";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarZoom))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownZoom))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void	proc_tool_buttons(const string&name) {
			const	map<string, int>		names = {
				{ "Select", 0 },
				{ "Direct Select", 1 },
				{ "Anchor Point", 2 },
				{ "Pen", 3 },
				{ "Add Anchor Point", 4 },
				{ "Delete Anchor Point", 5 },
				{ "Rectangle", 6 },
				{ "Ellipse", 7 },
				{ "Type", 8 },
				{ "Scale", 9 },
				{ "Rotate", 10 },
				{ "Reflect", 11 },
				{ "Zoom", 12 },
				{ "Hand", 13 },
				{ "Scissors", 14 },
			};
			cli::array<System::Windows::Forms::Button^>^	buttons = {
				buttonSelect,
				buttonDirectSelect,
				buttonAnchorPoint,
				buttonPen,
				buttonAddAnchorPoint,
				buttonDeleteAnchorPoint,
				buttonRectangle,
				buttonEllipse,
				buttonType,
				buttonScale,
				buttonRotate,
				buttonReflect,
				buttonZoom,
				buttonHand,
				buttonScissors,
			};

			labelSelectedTool->Text = gcnew String(name.c_str()) + " Tool";
			static	int		last_idx= -1;
			const	int		idx = names.at(name);
			buttons[idx]->Enabled = false;
			if (0 <= last_idx) {
				buttons[last_idx]->Enabled = true;
			}
			last_idx = idx;
		}

		void	redraw(void) {
			textBox1->Text = s2S(file_stats[current_file_no].file.to_string())->Replace("\r", "\n")->Replace("\n", "\r\n");
			webBrowser1->DocumentText = s2S(file_stats[current_file_no].file.to_svg(true));
			Bitmap^		bmp = gcnew Bitmap(webBrowser1->Width, webBrowser1->Height);
			Rectangle	bb(0, 0, webBrowser1->Width, webBrowser1->Height);	// bounding box
			webBrowser1->DrawToBitmap(bmp, bb);
			pictureBox1->Image = bmp;
		}

		System::Void buttonSelect_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Select");
		}
		System::Void buttonDirectSelect_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Direct Select");
		}
		System::Void buttonAnchorPoint_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Anchor Point");
		}
		System::Void buttonPen_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Pen");
		}
		System::Void buttonAddAnchorPoint_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Add Anchor Point");
		}
		System::Void buttonDeleteAnchorPoint_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Delete Anchor Point");
		}
		System::Void buttonRectangle_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Rectangle");
		}
		System::Void buttonEllipse_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Ellipse");
		}
		System::Void buttonType_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Type");
		}
		System::Void buttonScale_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Scale");
		}
		System::Void buttonRotate_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Rotate");
		}
		System::Void buttonReflect_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Reflect");
		}
		System::Void buttonZoom_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Zoom");
		}
		System::Void buttonHand_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Hand");
		}
		System::Void buttonScissors_Click(System::Object^  sender, System::EventArgs^  e) {
			proc_tool_buttons("Scissors");
		}

		// menu
		// file
		System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			file_stat_t		st;
			st.new_file = true;
			st.path = "New File " + to_string(new_file_count++) + ".myd";
			st.current_layer_no = 0;

			file_stats.push_back(st);
			current_file_no = file_stats.size() - 1;

			redraw();
		}
		System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				file_stat_t		st;
				st.path = S2s(openFileDialog1->FileName);
				st.file.from_file(st.path);
				st.current_layer_no = 0;

				file_stats.push_back(st);
				current_file_no = file_stats.size() - 1;

				redraw();
			}
		}
		System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (file_stats[current_file_no].new_file) {
				saveFileDialog1->FileName = s2S(file_stats[current_file_no].path);
				if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					file_stats[current_file_no].path = S2s(saveFileDialog1->FileName);
				} else {
					return;
				}
			}
			file_stats[current_file_no].file.to_file(file_stats[current_file_no].path);
		}
		System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				file_stats[current_file_no].path = S2s(saveFileDialog1->FileName);
				file_stats[current_file_no].file.to_file(file_stats[current_file_no].path);
			}
		}
		System::Void simulsaveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if (file_stats[current_file_no].new_file) {
				saveFileDialog1->FileName = s2S(file_stats[current_file_no].path);
				if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					file_stats[current_file_no].path = S2s(saveFileDialog1->FileName);
				} else {
					return;
				}
			}

			//save as myd
			file_stats[current_file_no].file.to_file(file_stats[current_file_no].path);

			//save as xml
			string	new_path = S2s(System::IO::Path::ChangeExtension(s2S(file_stats[current_file_no].path), "xml"));
			file_stats[current_file_no].file.to_xml_file(new_path);

			//save as svg
			new_path = S2s(System::IO::Path::ChangeExtension(s2S(file_stats[current_file_no].path), "svg"));
			file_stats[current_file_no].file.to_svg_file(new_path);

			//save as postscript
			new_path = S2s(System::IO::Path::ChangeExtension(s2S(file_stats[current_file_no].path), "ps"));
			file_stats[current_file_no].file.to_postscript_file(new_path);

			//save as PDF
			new_path = S2s(System::IO::Path::ChangeExtension(s2S(file_stats[current_file_no].path), "pdf"));
			file_stats[current_file_no].file.to_pdf_file(new_path);
		}
		System::Void exportToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void printToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		// edit
		System::Void undoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void redoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void cutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void preferencesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		// view
		System::Void zoomInToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void zoomOutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		// help
		System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}

		System::Void checkBoxWrap_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBoxWrap->Checked) {
				textBox1->WordWrap = true;
			} else {
				textBox1->WordWrap = false;
			}
		}
		System::Void buttonApply_Click(System::Object^  sender, System::EventArgs^  e) {
			String^	text = gcnew String(textBox1->Text);
			dt_file	file(S2s(text->Replace("\r\n", "\n")));
			file_stats[current_file_no].file = file;
			redraw();
		}
		System::Void buttonRevert_Click(System::Object^  sender, System::EventArgs^  e) {
			textBox1->Text = s2S(file_stats[current_file_no].file.to_string())->Replace("\r", "\n")->Replace("\n", "\r\n");
		}

		System::Void hScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		}
		System::Void vScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		}

		bool	zoom_processed = false;
		System::Void trackBarZoom_Scroll(System::Object^  sender, System::EventArgs^  e) {
			if (!zoom_processed) {
				file_stats[current_file_no].scale = pow(10.0, trackBarZoom->Value / 100.0);
				int		scale = file_stats[current_file_no].scale * 100.0;
scale=max(scale, 1);
scale=min(scale, 10000);
				numericUpDownZoom->Value = (Decimal)scale;
				zoom_processed = true;
			} else {
				zoom_processed = false;
			}
		}
		System::Void numericUpDownZoom_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			if (!zoom_processed) {
				file_stats[current_file_no].scale = (int)numericUpDownZoom->Value / 100.0;
				trackBarZoom->Value = (int)log10(file_stats[current_file_no].scale);
				zoom_processed = true;
			} else {
				zoom_processed = false;
			}
		}
	};
}

