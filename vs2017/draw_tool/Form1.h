#pragma once


#include	<string>
#include	<map>


using	namespace	std;


namespace draw_tool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 の概要
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
		/// 使用中のリソースをすべてクリーンアップします。
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

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
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
			this->SuspendLayout();
			// 
			// buttonSelect
			// 
			this->buttonSelect->Location = System::Drawing::Point(12, 12);
			this->buttonSelect->Name = L"buttonSelect";
			this->buttonSelect->Size = System::Drawing::Size(28, 23);
			this->buttonSelect->TabIndex = 0;
			this->buttonSelect->Text = L"V";
			this->buttonSelect->UseVisualStyleBackColor = true;
			this->buttonSelect->Click += gcnew System::EventHandler(this, &Form1::buttonSelect_Click);
			// 
			// buttonDirectSelect
			// 
			this->buttonDirectSelect->Location = System::Drawing::Point(46, 12);
			this->buttonDirectSelect->Name = L"buttonDirectSelect";
			this->buttonDirectSelect->Size = System::Drawing::Size(28, 23);
			this->buttonDirectSelect->TabIndex = 1;
			this->buttonDirectSelect->Text = L"A";
			this->buttonDirectSelect->UseVisualStyleBackColor = true;
			this->buttonDirectSelect->Click += gcnew System::EventHandler(this, &Form1::buttonDirectSelect_Click);
			// 
			// buttonPen
			// 
			this->buttonPen->Location = System::Drawing::Point(12, 41);
			this->buttonPen->Name = L"buttonPen";
			this->buttonPen->Size = System::Drawing::Size(28, 23);
			this->buttonPen->TabIndex = 2;
			this->buttonPen->Text = L"P";
			this->buttonPen->UseVisualStyleBackColor = true;
			this->buttonPen->Click += gcnew System::EventHandler(this, &Form1::buttonPen_Click);
			// 
			// buttonScissors
			// 
			this->buttonScissors->Location = System::Drawing::Point(80, 128);
			this->buttonScissors->Name = L"buttonScissors";
			this->buttonScissors->Size = System::Drawing::Size(28, 23);
			this->buttonScissors->TabIndex = 3;
			this->buttonScissors->Text = L"C";
			this->buttonScissors->UseVisualStyleBackColor = true;
			this->buttonScissors->Click += gcnew System::EventHandler(this, &Form1::buttonScissors_Click);
			// 
			// buttonRectangle
			// 
			this->buttonRectangle->Location = System::Drawing::Point(12, 70);
			this->buttonRectangle->Name = L"buttonRectangle";
			this->buttonRectangle->Size = System::Drawing::Size(28, 23);
			this->buttonRectangle->TabIndex = 4;
			this->buttonRectangle->Text = L"M";
			this->buttonRectangle->UseVisualStyleBackColor = true;
			this->buttonRectangle->Click += gcnew System::EventHandler(this, &Form1::buttonRectangle_Click);
			// 
			// buttonEllipse
			// 
			this->buttonEllipse->Location = System::Drawing::Point(46, 70);
			this->buttonEllipse->Name = L"buttonEllipse";
			this->buttonEllipse->Size = System::Drawing::Size(28, 23);
			this->buttonEllipse->TabIndex = 5;
			this->buttonEllipse->Text = L"L";
			this->buttonEllipse->UseVisualStyleBackColor = true;
			this->buttonEllipse->Click += gcnew System::EventHandler(this, &Form1::buttonEllipse_Click);
			// 
			// buttonZoom
			// 
			this->buttonZoom->Location = System::Drawing::Point(12, 128);
			this->buttonZoom->Name = L"buttonZoom";
			this->buttonZoom->Size = System::Drawing::Size(28, 23);
			this->buttonZoom->TabIndex = 6;
			this->buttonZoom->Text = L"Z";
			this->buttonZoom->UseVisualStyleBackColor = true;
			this->buttonZoom->Click += gcnew System::EventHandler(this, &Form1::buttonZoom_Click);
			// 
			// buttonAnchorPoint
			// 
			this->buttonAnchorPoint->Location = System::Drawing::Point(80, 12);
			this->buttonAnchorPoint->Name = L"buttonAnchorPoint";
			this->buttonAnchorPoint->Size = System::Drawing::Size(28, 23);
			this->buttonAnchorPoint->TabIndex = 7;
			this->buttonAnchorPoint->Text = L"^";
			this->buttonAnchorPoint->UseVisualStyleBackColor = true;
			this->buttonAnchorPoint->Click += gcnew System::EventHandler(this, &Form1::buttonAnchorPoint_Click);
			// 
			// buttonAddAnchorPoint
			// 
			this->buttonAddAnchorPoint->Location = System::Drawing::Point(46, 41);
			this->buttonAddAnchorPoint->Name = L"buttonAddAnchorPoint";
			this->buttonAddAnchorPoint->Size = System::Drawing::Size(28, 23);
			this->buttonAddAnchorPoint->TabIndex = 8;
			this->buttonAddAnchorPoint->Text = L"P+";
			this->buttonAddAnchorPoint->UseVisualStyleBackColor = true;
			this->buttonAddAnchorPoint->Click += gcnew System::EventHandler(this, &Form1::buttonAddAnchorPoint_Click);
			// 
			// buttonDeleteAnchorPoint
			// 
			this->buttonDeleteAnchorPoint->Location = System::Drawing::Point(80, 41);
			this->buttonDeleteAnchorPoint->Name = L"buttonDeleteAnchorPoint";
			this->buttonDeleteAnchorPoint->Size = System::Drawing::Size(28, 23);
			this->buttonDeleteAnchorPoint->TabIndex = 9;
			this->buttonDeleteAnchorPoint->Text = L"P-";
			this->buttonDeleteAnchorPoint->UseVisualStyleBackColor = true;
			this->buttonDeleteAnchorPoint->Click += gcnew System::EventHandler(this, &Form1::buttonDeleteAnchorPoint_Click);
			// 
			// buttonType
			// 
			this->buttonType->Location = System::Drawing::Point(80, 70);
			this->buttonType->Name = L"buttonType";
			this->buttonType->Size = System::Drawing::Size(28, 23);
			this->buttonType->TabIndex = 10;
			this->buttonType->Text = L"T";
			this->buttonType->UseVisualStyleBackColor = true;
			this->buttonType->Click += gcnew System::EventHandler(this, &Form1::buttonType_Click);
			// 
			// buttonHand
			// 
			this->buttonHand->Location = System::Drawing::Point(46, 128);
			this->buttonHand->Name = L"buttonHand";
			this->buttonHand->Size = System::Drawing::Size(28, 23);
			this->buttonHand->TabIndex = 11;
			this->buttonHand->Text = L"H";
			this->buttonHand->UseVisualStyleBackColor = true;
			this->buttonHand->Click += gcnew System::EventHandler(this, &Form1::buttonHand_Click);
			// 
			// buttonScale
			// 
			this->buttonScale->Location = System::Drawing::Point(12, 99);
			this->buttonScale->Name = L"buttonScale";
			this->buttonScale->Size = System::Drawing::Size(28, 23);
			this->buttonScale->TabIndex = 12;
			this->buttonScale->Text = L"S";
			this->buttonScale->UseVisualStyleBackColor = true;
			this->buttonScale->Click += gcnew System::EventHandler(this, &Form1::buttonScale_Click);
			// 
			// buttonRotate
			// 
			this->buttonRotate->Location = System::Drawing::Point(46, 99);
			this->buttonRotate->Name = L"buttonRotate";
			this->buttonRotate->Size = System::Drawing::Size(28, 23);
			this->buttonRotate->TabIndex = 13;
			this->buttonRotate->Text = L"R";
			this->buttonRotate->UseVisualStyleBackColor = true;
			this->buttonRotate->Click += gcnew System::EventHandler(this, &Form1::buttonRotate_Click);
			// 
			// buttonReflect
			// 
			this->buttonReflect->Location = System::Drawing::Point(80, 99);
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
			this->labelSelectedTool->Location = System::Drawing::Point(12, 154);
			this->labelSelectedTool->Name = L"labelSelectedTool";
			this->labelSelectedTool->Size = System::Drawing::Size(23, 12);
			this->labelSelectedTool->TabIndex = 15;
			this->labelSelectedTool->Text = L"---";
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
			this->MinimumSize = System::Drawing::Size(640, 480);
			this->Name = L"Form1";
			this->Text = L"My Drawer";
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
	};
}

