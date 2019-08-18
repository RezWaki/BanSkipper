#pragma once

namespace banskipper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(475, 286);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 289);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Your HL path:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(106, 288);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(295, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(404, 285);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(68, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Browse...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(159, 314);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Skip ban...";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(240, 314);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Fix client...";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(475, 379);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Text = L"BanSkipper v1.0";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 folderBrowserDialog1->ShowDialog();
				 textBox1->Text = folderBrowserDialog1->SelectedPath;
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 IO::File::Delete(textBox1->Text+"\\valve\\voice_ban.dt");
				 IO::File::Copy("data\\4byte_clear", textBox1->Text+"\\valve\\voice_ban.dt");
				 //IO::File::SetAttributes(textBox1->Text+"\\valve\\voice_ban.dt", IO::FileAttributes::ReadOnly);
				 IO::File::Delete(textBox1->Text+"\\valve\\custom.hpk");
				 IO::File::Delete(textBox1->Text+"\\valve\\config.cfg");
				 IO::File::Copy("data\\cfg", textBox1->Text+"\\valve\\config.cfg");
				 IO::File::WriteAllText(textBox1->Text+"\\valve\\userconfig.cfg", "name BanSkipper_By_RezWaki");
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 IO::File::Delete(textBox1->Text+"\\valve\\custom.hpk");
				 IO::File::Copy("data\\hpk_clear", textBox1->Text+"\\valve\\custom.hpk");
				 //IO::File::SetAttributes(textBox1->Text+"\\valve\\custom.hpk", IO::FileAttributes::ReadOnly);
				 if( IO::File::Exists(textBox1->Text+"\\valve\\custom.hp2") ) {
					 IO::File::Delete(textBox1->Text+"\\valve\\custom.hp2");
					 IO::File::WriteAllText(textBox1->Text+"\\valve\\custom.hp2", "");
					 //IO::File::SetAttributes(textBox1->Text+"\\valve\\custom.hp2", IO::FileAttributes::ReadOnly);
				 }
				 IO::File::Delete(textBox1->Text+"\\valve\\settings.scr");
				 IO::File::Copy("data\\scr", textBox1->Text+"\\valve\\settings.scr");
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 IO::File::WriteAllText("data\\path", textBox1->Text);
		 }
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = IO::File::ReadAllText("data\\path");
		 }
};
}