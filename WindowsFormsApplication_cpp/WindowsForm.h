#pragma once
#include"DataManager.h"
#include"DotNetUtilities.h"
#include "string"
#include "VectorOperate.h"
#include "MatrixOperate.h"
#include "string"

namespace WindowsFormsApplication_cpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// WindowsForm 的摘要
	/// </summary>
	public ref class WindowsForm : public System::Windows::Forms::Form
	{
	public:
		WindowsForm(void)
		{
			InitializeComponent();
			matrixoperate = new MatrixOperate();
			vectoroperate = new VectorOperate();
			dataManager = new DataManager();
			lastInputLength = -1;
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~WindowsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  FileToolStripMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStripMenuItem^  LoadVectorToolStripMenuItem;



	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::Label^  OutputLabel;
	private: System::Windows::Forms::TextBox^  Output;

	private: System::Windows::Forms::Label^  InputLabel;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::Label^  VectorLabel;
	private: System::Windows::Forms::ListBox^  VectorList;



	protected:















	protected:

	private:
		/// <summary>
		bool vectormode;
		bool matrixmode;
			MatrixOperate* matrixoperate;
			VectorOperate* vectoroperate;
			DataManager* dataManager;
			String^ userInput;
			int lastInputLength;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;
	private: System::Windows::Forms::BindingSource^  bindingSource1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadMatrixToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;
			 /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InputLabel = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->VectorLabel = (gcnew System::Windows::Forms::Label());
			this->VectorList = (gcnew System::Windows::Forms::ListBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->OutputLabel = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->menuStrip2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			this->SuspendLayout();
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip2->Size = System::Drawing::Size(710, 27);
			this->menuStrip2->TabIndex = 1;
			this->menuStrip2->Text = L"menuStrip2";
			this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->LoadVectorToolStripMenuItem,
					this->loadMatrixToolStripMenuItem
			});
			this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			this->FileToolStripMenuItem->Size = System::Drawing::Size(45, 23);
			this->FileToolStripMenuItem->Text = L"File";
			this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
			this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->LoadVectorToolStripMenuItem->Text = L"Load Vector";
			this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
			this->loadMatrixToolStripMenuItem->Name = L"loadMatrixToolStripMenuItem";
			this->loadMatrixToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->loadMatrixToolStripMenuItem->Text = L"Load Matrix";
			this->loadMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadMatrixToolStripMenuItem_Click);
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 27);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(710, 569);
			this->tableLayoutPanel1->TabIndex = 2;
			this->flowLayoutPanel1->Controls->Add(this->InputLabel);
			this->flowLayoutPanel1->Controls->Add(this->Input);
			this->flowLayoutPanel1->Controls->Add(this->VectorLabel);
			this->flowLayoutPanel1->Controls->Add(this->VectorList);
			this->flowLayoutPanel1->Location = System::Drawing::Point(359, 4);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(342, 560);
			this->flowLayoutPanel1->TabIndex = 0;
			this->InputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InputLabel->AutoSize = true;
			this->InputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->InputLabel->Location = System::Drawing::Point(4, 0);
			this->InputLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->InputLabel->Name = L"InputLabel";
			this->InputLabel->Size = System::Drawing::Size(48, 19);
			this->InputLabel->TabIndex = 0;
			this->InputLabel->Text = L"Input";
			this->Input->Location = System::Drawing::Point(4, 23);
			this->Input->Margin = System::Windows::Forms::Padding(4);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(329, 228);
			this->Input->TabIndex = 1;
			this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged);
			this->VectorLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->VectorLabel->AutoSize = true;
			this->VectorLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->VectorLabel->Location = System::Drawing::Point(4, 255);
			this->VectorLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->VectorLabel->Name = L"VectorLabel";
			this->VectorLabel->Size = System::Drawing::Size(58, 19);
			this->VectorLabel->TabIndex = 2;
			this->VectorLabel->Text = L"Vector";
			this->VectorList->FormattingEnabled = true;
			this->VectorList->ItemHeight = 15;
			this->VectorList->Location = System::Drawing::Point(4, 278);
			this->VectorList->Margin = System::Windows::Forms::Padding(4);
			this->VectorList->Name = L"VectorList";
			this->VectorList->Size = System::Drawing::Size(329, 274);
			this->VectorList->TabIndex = 3;
			this->flowLayoutPanel2->Controls->Add(this->OutputLabel);
			this->flowLayoutPanel2->Controls->Add(this->Output);
			this->flowLayoutPanel2->Location = System::Drawing::Point(4, 4);
			this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(341, 560);
			this->flowLayoutPanel2->TabIndex = 1;
			this->OutputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OutputLabel->AutoSize = true;
			this->OutputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->OutputLabel->Location = System::Drawing::Point(4, 0);
			this->OutputLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->OutputLabel->Name = L"OutputLabel";
			this->OutputLabel->Size = System::Drawing::Size(61, 19);
			this->OutputLabel->TabIndex = 0;
			this->OutputLabel->Text = L"Output";
			this->Output->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Output->Location = System::Drawing::Point(4, 23);
			this->Output->Margin = System::Windows::Forms::Padding(4);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->Size = System::Drawing::Size(323, 529);
			this->Output->TabIndex = 1;
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openFileDialog1_FileOk);
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openFileDialog2_FileOk);
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(710, 596);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip2);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"WindowsForm";
			this->Text = L"VectorExample";
			this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void WindowsForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void LoadVectorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//開啟Dialog
	openFileDialog1->ShowDialog();
}
private: System::Void LoadMatrixToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	//開啟Dialog
	openFileDialog2->ShowDialog();
}
private: System::Void Input_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	//當Input textbox中的輸入改變時，便會進入此函式
	//判斷輸入自元為'\n'，並防止取到字串-1位置
	if (Input->Text->Length-1 >= 0 &&Input->Text[Input->Text->Length - 1] == '\n')
	{
		if (vectormode) {
			//取得向量資料
			std::vector<Vector> vectors = dataManager->GetVectors();
			//將使用者輸入字串(在userInput中)，依空白作切割
			array<String^> ^userCommand = userInput->Split(' ');
			//字串比較，若指令為"print"的情況
			if (userCommand[0] == "print")
			{
				//定意輸出暫存
				String^ outputTemp = "";
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{
					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].Name.c_str()))
					{
						//將輸出格式存入暫存
						outputTemp += "[";
						//將輸出資料存入暫存
						//std::cout << vectors[i].Data.size() << std::endl;
						//std::cout << vectoroperate->test(userCommand[1], vectors);
						for (unsigned int j = 0; j < vectors[i].Data.size(); j++)
						{
							outputTemp += vectors[i].Data[j].ToString();
							if (j != vectors[i].Data.size() - 1)
								outputTemp += ",";
						}
						//將輸出格式存入暫存，並且換行
						outputTemp += "]" + Environment::NewLine;
						//輸出暫存資訊
						Output->Text += gcnew String(vectors[i].Name.c_str()) + " = " + outputTemp;
						break;
					}
				}
			}
			else if (userCommand[0] == "1" || userCommand[0] == "2" || userCommand[0] == "3" || userCommand[0] == "4") {
				Output->Text = "";
				try
				{
					Vector a = vectoroperate->Ope1(userCommand[1], vectors);
					if (a.Name == "int") {
						Output->Text += userCommand[1] + " = " + a.Data[0];
					}
					else {
						Output->Text += userCommand[1] + " = [";
						for (int i = 0; i < a.Data.size(); i++) {
							Output->Text += a.Data[i];
							if (i < a.Data.size() - 1) Output->Text += " , ";
						}
						Output->Text += "]" + Environment::NewLine;
					}
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "5") {
				try {
					Output->Text = "";
					double out = vectoroperate->Ope5(userCommand[1], vectors);
					Output->Text += "Norm[" + userCommand[1] + "] = " + out + Environment::NewLine;
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "6") {
				try {
					Output->Text = "";
					Vector out = vectoroperate->Ope6(userCommand[1], vectors);
					Output->Text += "Normal[" + userCommand[1] + "] = [";
					for (int i = 0; i < out.Data.size(); i++) {
						Output->Text += out.Data[i];
						if (i < out.Data.size() - 1) Output->Text += " , ";
					}
					Output->Text += "]" + Environment::NewLine;
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "7") {
				try {
					Output->Text = "";
					Vector out = vectoroperate->Ope7(userCommand[1], vectors);
					Output->Text += "Cross [" + userCommand[1] + "] = [";
					for (int i = 0; i < out.Data.size(); i++) {
						Output->Text += out.Data[i];
						if (i < out.Data.size() - 1) Output->Text += " , ";
					}
					Output->Text += "]" + Environment::NewLine;
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "8") {
				try {
					Output->Text = "";
					Vector a = vectoroperate->Ope8(userCommand[1], vectors);
					Output->Text += "Com [" + userCommand[1] + "] = ";
					Output->Text += a.Data[0] + Environment::NewLine;
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "9") {
				try {
					Output->Text = "";
					Vector out = vectoroperate->Ope9(userCommand[1], vectors);
					Output->Text += "Proj [" + userCommand[1] + "] = [";
					for (int i = 0; i < out.Data.size(); i++) {
						Output->Text += out.Data[i];
						if (i < out.Data.size() - 1) Output->Text += " , ";
					}
					Output->Text += "]" + Environment::NewLine;
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "10") {
				try {
					Output->Text = "";
					double out = vectoroperate->Ope10(userCommand[1], vectors);
					Output->Text += "Area [" + userCommand[1] + "] = " + out + Environment::NewLine;
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "11") {
				try {
					Output->Text = "";
					bool out = vectoroperate->Ope11(userCommand[1], vectors);
					Output->Text += "Parallel [" + userCommand[1] + "] = ";
					if (out) Output->Text += "Yes" + Environment::NewLine;
					else Output->Text += "No" + Environment::NewLine;
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "12") {
				try {
					Output->Text = "";
					bool out = vectoroperate->Ope12(userCommand[1], vectors);
					Output->Text += "Orthogonal [" + userCommand[1] + "] = ";
					if (out) Output->Text += "Yes" + Environment::NewLine;
					else Output->Text += "No" + Environment::NewLine;
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "13") {
				try {
					Output->Text = "";
					double out = vectoroperate->Ope13(userCommand[1], vectors);
					Output->Text += "Theta [" + userCommand[1] + "] = " + out + Environment::NewLine;
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "14") {
				try {
					Output->Text = "";
					Vector out = vectoroperate->Ope7(userCommand[1], vectors);
					Output->Text += "pN [" + userCommand[1] + "] = [";
					for (int i = 0; i < out.Data.size(); i++) {
						Output->Text += out.Data[i];
						if (i < out.Data.size() - 1) Output->Text += " , ";
					}
					Output->Text += "]" + Environment::NewLine;
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "15") {
				try {
					Output->Text = "";
					bool out = vectoroperate->Ope15(userCommand[1], vectors);
					Output->Text += "isLI [" + userCommand[1] + "] = ";
					if (out) Output->Text += "Yes" + Environment::NewLine;
					else Output->Text += "No" + Environment::NewLine;
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else if (userCommand[0] == "16") {
				try {
					Output->Text = "";
					Vector out = vectoroperate->Ope16(userCommand[1], vectors);
					Output->Text += "ob [" + userCommand[1] + "] = ";
					int num = std::stoi(out.Name);
					for (int i = 0; i < num; i++) {
						Output->Text += "[";
						for (int k = 0; k < num; k++) {
							if (k < num - 1)Output->Text += out.Data[i * 3 + k] + ",";
							else Output->Text += out.Data[i * 3 + k];
						}
						if (i < num - 1)Output->Text += "] , ";
						else Output->Text += "]";
					}
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			//反之則判斷找不到指令
			else
			{
				Output->Text += "-Command not found-" + Environment::NewLine;
			}
			userInput = "";
		}
		else if (matrixmode) {
			std::vector<std::vector<Vector>> matrixs = dataManager->GetMatrixs();
			//反之則判斷找不到指令
			//將使用者輸入字串(在userInput中)，依空白作切割
			array<String^> ^userCommand = userInput->Split(' ');
			//字串比較，若指令為"print"的情況
			if (userCommand[0] == "print")
			{
				//定意輸出暫存
				String^ outputTemp = "";
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < matrixs.size(); i++)
				{
					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(matrixs[i][0].Name.c_str()))
					{
						//將輸出格式存入暫存
						outputTemp += "[";
						//將輸出資料存入暫存
						int num = 0;
						//std::cout << vectors[i].Data.size() << std::endl;
						//std::cout << vectoroperate->test(userCommand[1], vectors);
						for (unsigned int j = 0; j < matrixs[i].size(); j++)
						{
							for (unsigned int k = 0; k < matrixs[i][j].Data.size(); k++) {
								outputTemp += matrixs[i][j].Data[k].ToString();
								num++;
								if (k != matrixs[i][j].Data.size() - 1)
									outputTemp += ",";
							}
							if (j < matrixs[i].size() - 1)outputTemp += "],[";
						}
						//std::cout << num << "  ";
						//將輸出格式存入暫存，並且換行
						outputTemp += "]" + Environment::NewLine;
						//輸出暫存資訊
						Output->Text += gcnew String(matrixs[i][0].Name.c_str()) + " = " + outputTemp;
						break;
					}
				}
			}
			else if (userCommand[0] == "1"|| userCommand[0] == "2") {
				Output->Text = "";
				std::vector<Vector> out = matrixoperate->Ope1(userCommand[1], matrixs);
				Output->Text += "[";
				for (unsigned int j = 0; j < out.size(); j++)
				{
					for (unsigned int k = 0; k < out[j].Data.size(); k++) {
						Output->Text += out[j].Data[k].ToString();
						//num++;
						if (k != out[j].Data.size() - 1)
							Output->Text += ",";
					}
					if (j < out.size() - 1)Output->Text += "],[";
				}
				Output->Text += "]";
			}
			else if (userCommand[0] == "3") {
				Output->Text = "";
				int out = matrixoperate->Ope3(userCommand[1], matrixs);
				Output->Text += "Rank(" + userCommand[1] + ") = " + out;
			}
			else if (userCommand[0] == "4") {
				Output->Text = "";
				std::vector<Vector> out = matrixoperate->Ope4(userCommand[1], matrixs);
				Output->Text += "Tran[";
				for (unsigned int j = 0; j < out.size(); j++)
				{
					for (unsigned int k = 0; k < out[j].Data.size(); k++) {
						Output->Text += out[j].Data[k].ToString();
						//num++;
						if (k != out[j].Data.size() - 1)
							Output->Text += ",";
					}
					if (j < out.size() - 1)Output->Text += "],[";
				}
				Output->Text += "]";
			}
			else if (userCommand[0] == "5") {
				Output->Text = "";
				std::vector<Vector> out = matrixoperate->Ope5(userCommand[1], matrixs);
				Output->Text += "a/b = [";
				for (unsigned int j = 0; j < out.size(); j++)
				{
					for (unsigned int k = 0; k < out[j].Data.size(); k++) {
						Output->Text += out[j].Data[k].ToString();
						//num++;
						if (k != out[j].Data.size() - 1)
							Output->Text += ",";
					}
					if (j < out.size() - 1)Output->Text += "],[";
				}
				Output->Text += "]";
			}
			else if (userCommand[0] == "6") {
				Output->Text = "";
				double out = matrixoperate->Ope6(userCommand[1], matrixs);
				Output->Text += "det(" + userCommand[1] + ") =  " + out;
			}
			else if (userCommand[0] == "7") {
				try {
					Output->Text = "";
					std::vector<Vector> out = matrixoperate->Ope7(userCommand[1], matrixs);
					Output->Text += "Inverse = [";
					for (unsigned int j = 0; j < out.size(); j++)
					{
						for (unsigned int k = 0; k < out[j].Data.size(); k++) {
							Output->Text += out[j].Data[k].ToString();
							//num++;
							if (k != out[j].Data.size() - 1)
								Output->Text += ",";
						}
						if (j < out.size() - 1)Output->Text += "],[";
					}
					Output->Text += "]";
				}
				catch (const char *message)
				{
					std::string s = message;
					String^ output = gcnew String(s.c_str());
					Output->Text += output;
				}
			}
			else{
				Output->Text += "-Command not found-" + Environment::NewLine;
			}
			userInput = "";
		}
	}
	else
	{
		//將使用者輸入字串(在Text box中)，依'\n'作切割
		array<String^> ^userCommand = Input->Text->Split('\n');
		//並將最後一行，作為目前使用者輸入指令
		userInput = userCommand[userCommand->Length-1];
	}

}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
{
	vectormode = true;
	matrixmode = false;
	//在Dialog按下OK便會進入此函式
	//字串轉制string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog1->FileName, tempFileName);
	//將檔案路徑名稱傳入dataManager
	dataManager->SetFileName(tempFileName);
	dataManager->VectorVariableIndex = 0;
	dataManager->ResetVectors();
	//從讀取讀取向量資料
	if (dataManager->LoadVectorData())
	{
		//將VectorList中項目先做清除
		VectorList->Items->Clear();
		//取得所有向量資料
		std::vector<Vector> vectors = dataManager->GetVectors();

		for (unsigned int i = 0; i < vectors.size(); i++)
		{
			//將檔案名稱存入暫存
			std::string tempString = vectors[i].Name;
			//將輸出格式存入暫存
			tempString += " [";
			//將輸出資料存入暫存
			for (unsigned int j = 0; j<vectors[i].Data.size(); j++)
			{
				std::string scalarString = std::to_string(vectors[i].Data[j]);
				tempString += scalarString.substr(0, scalarString.size() - 5);
				if (j != vectors[i].Data.size() - 1)
					tempString += ",";
			}
			//將輸出格式存入暫存
			tempString += "]";
			//將項目加入VectorList中
			VectorList->Items->Add(gcnew String(tempString.c_str()));
		}
		Output->Text += "-Vector datas have been loaded-" + Environment::NewLine;
	}
}
private: System::Void openFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	vectormode = false;
	matrixmode = true;
	//在Dialog按下OK便會進入此函式
	//字串轉制string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog2->FileName, tempFileName);
	//std::cout << tempFileName;
	//將檔案路徑名稱傳入dataManager
	dataManager->SetFileName(tempFileName);
	dataManager->MatrixVariableIndex = 0;
	dataManager->ResetMatrixs();
	//從讀取讀取向量資料
	if (dataManager->LoadMatrixData())
	{
		//將VectorList中項目先做清除
		VectorList->Items->Clear();
		//取得所有矩陣資料
		std::vector<std::vector<Vector>> matrixs = dataManager->GetMatrixs();
		for (unsigned int i = 0; i < matrixs.size(); i++)
		{
			//將檔案名稱存入暫存
			std::string tempString = matrixs[i][0].Name;
			//將輸出格式存入暫存
			tempString += " [";
			//將輸出資料存入暫存
			for (unsigned int j = 0; j < matrixs[i].size(); j++)
			{
				for (int l = 0; l < matrixs[i][j].Data.size(); l++) {
					std::string scalarString = std::to_string(matrixs[i][j].Data[l]);
					tempString += scalarString.substr(0, scalarString.size() - 5);
					if (l != matrixs[i][j].Data.size() - 1)
						tempString += ",";
				}
				if (j < matrixs[i].size() - 1)tempString += "],[";
			}
			//將輸出格式存入暫存
			tempString += "]";
			//將項目加入VectorList中
			VectorList->Items->Add(gcnew String(tempString.c_str()));
		}
		Output->Text += "-Matrixs datas have been loaded-" + Environment::NewLine;
	}		
}
};
}
