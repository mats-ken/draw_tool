#pragma once


#include	<string>
#include	<vector>
#include	<map>

#include	"../../lib/dt_file.h"


using	namespace	std;


vector<dt_file>		files;
vector<size_t>		current_layers;
vector<dt_area>		current_areas;
vector<dt_bitmap>	masks;


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
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->simulsaveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonSelect
			// 
			this->buttonSelect->Location = System::Drawing::Point(12, 27);
			this->buttonSelect->Name = L"buttonSelect";
			this->buttonSelect->Size = System::Drawing::Size(28, 23);
			this->buttonSelect->TabIndex = 0;
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
			this->buttonReflect->Text = L"O";
			this->buttonReflect->UseVisualStyleBackColor = true;
			this->buttonReflect->Click += gcnew System::EventHandler(this, &Form1::buttonReflect_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->viewToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(624, 24);
			this->menuStrip1->TabIndex = 16;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->simulsaveToolStripMenuItem, this->exportToolStripMenuItem,
					this->printToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->openToolStripMenuItem->Text = L"Open....";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->saveAsToolStripMenuItem->Text = L"Save as....";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->exportToolStripMenuItem->Text = L"Export....";
			this->exportToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exportToolStripMenuItem_Click);
			// 
			// printToolStripMenuItem
			// 
			this->printToolStripMenuItem->Name = L"printToolStripMenuItem";
			this->printToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->printToolStripMenuItem->Size = System::Drawing::Size(157, 22);
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
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->aboutToolStripMenuItem->Text = L"About....";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// simulsaveToolStripMenuItem
			// 
			this->simulsaveToolStripMenuItem->Name = L"simulsaveToolStripMenuItem";
			this->simulsaveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt)
				| System::Windows::Forms::Keys::S));
			this->simulsaveToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->simulsaveToolStripMenuItem->Text = L"Simul-save";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 441);
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
			this->MinimumSize = System::Drawing::Size(640, 480);
			this->Name = L"Form1";
			this->Text = L"My Drawer v0.3";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void	proc_tool_buttons(const string&name) {
			const	map<string, int>		names/* = {
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
			}*/;
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
		System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
	};
}

