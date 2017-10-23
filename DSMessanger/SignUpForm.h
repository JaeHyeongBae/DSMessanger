#pragma once
#include <msclr/marshal_cppstd.h>
#include "MessangerApp.h"
namespace DSMessanger {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SignUpForm
	/// </summary>
	public ref class SignUpForm : public System::Windows::Forms::Form
	{
	private:
		MessangerApp* app;
	public:
		SignUpForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			app = MessangerApp::GetInstance();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SignUpForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  submit_button;
	protected:

	private: System::Windows::Forms::TextBox^  id_textbox;
	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  password_textbox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  name_textbox;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  phoneNumber_textbox;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::PictureBox^  profileImage_picturebox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  backgroundImage_picturebox;
	private: System::Windows::Forms::LinkLabel^  openProfileImage_linklabel;
	private: System::Windows::Forms::LinkLabel^  openBackgroundImage_linklabel;
	private: System::Windows::Forms::TextBox^  birthdate_textbox;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  profileMessage_textbox;
	private: System::Windows::Forms::Label^  label8;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->submit_button = (gcnew System::Windows::Forms::Button());
			this->id_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->password_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->name_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->phoneNumber_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->profileImage_picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->backgroundImage_picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->openProfileImage_linklabel = (gcnew System::Windows::Forms::LinkLabel());
			this->openBackgroundImage_linklabel = (gcnew System::Windows::Forms::LinkLabel());
			this->birthdate_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->profileMessage_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profileImage_picturebox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundImage_picturebox))->BeginInit();
			this->SuspendLayout();
			// 
			// submit_button
			// 
			this->submit_button->Location = System::Drawing::Point(426, 435);
			this->submit_button->Name = L"submit_button";
			this->submit_button->Size = System::Drawing::Size(117, 23);
			this->submit_button->TabIndex = 8;
			this->submit_button->Text = L"Submit";
			this->submit_button->UseVisualStyleBackColor = true;
			this->submit_button->Click += gcnew System::EventHandler(this, &SignUpForm::submit_button_Click);
			// 
			// id_textbox
			// 
			this->id_textbox->Location = System::Drawing::Point(120, 12);
			this->id_textbox->Name = L"id_textbox";
			this->id_textbox->Size = System::Drawing::Size(423, 21);
			this->id_textbox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"ID";
			// 
			// password_textbox
			// 
			this->password_textbox->Location = System::Drawing::Point(120, 39);
			this->password_textbox->Name = L"password_textbox";
			this->password_textbox->PasswordChar = '*';
			this->password_textbox->Size = System::Drawing::Size(423, 21);
			this->password_textbox->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Password";
			// 
			// name_textbox
			// 
			this->name_textbox->Location = System::Drawing::Point(120, 66);
			this->name_textbox->Name = L"name_textbox";
			this->name_textbox->Size = System::Drawing::Size(423, 21);
			this->name_textbox->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 12);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Name";
			// 
			// phoneNumber_textbox
			// 
			this->phoneNumber_textbox->Location = System::Drawing::Point(120, 93);
			this->phoneNumber_textbox->Name = L"phoneNumber_textbox";
			this->phoneNumber_textbox->Size = System::Drawing::Size(423, 21);
			this->phoneNumber_textbox->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 96);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 12);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Phone Number";
			this->label4->Click += gcnew System::EventHandler(this, &SignUpForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 176);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 12);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Profile Image";
			this->label5->Click += gcnew System::EventHandler(this, &SignUpForm::label4_Click);
			// 
			// profileImage_picturebox
			// 
			this->profileImage_picturebox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->profileImage_picturebox->Location = System::Drawing::Point(23, 191);
			this->profileImage_picturebox->Name = L"profileImage_picturebox";
			this->profileImage_picturebox->Size = System::Drawing::Size(257, 213);
			this->profileImage_picturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->profileImage_picturebox->TabIndex = 3;
			this->profileImage_picturebox->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(284, 176);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(111, 12);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Background Image";
			this->label6->Click += gcnew System::EventHandler(this, &SignUpForm::label4_Click);
			// 
			// backgroundImage_picturebox
			// 
			this->backgroundImage_picturebox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->backgroundImage_picturebox->Location = System::Drawing::Point(286, 191);
			this->backgroundImage_picturebox->Name = L"backgroundImage_picturebox";
			this->backgroundImage_picturebox->Size = System::Drawing::Size(257, 213);
			this->backgroundImage_picturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->backgroundImage_picturebox->TabIndex = 3;
			this->backgroundImage_picturebox->TabStop = false;
			// 
			// openProfileImage_linklabel
			// 
			this->openProfileImage_linklabel->AutoSize = true;
			this->openProfileImage_linklabel->Location = System::Drawing::Point(245, 407);
			this->openProfileImage_linklabel->Name = L"openProfileImage_linklabel";
			this->openProfileImage_linklabel->Size = System::Drawing::Size(35, 12);
			this->openProfileImage_linklabel->TabIndex = 6;
			this->openProfileImage_linklabel->TabStop = true;
			this->openProfileImage_linklabel->Text = L"Open";
			this->openProfileImage_linklabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SignUpForm::openProfileImage_linklabel_LinkClicked);
			// 
			// openBackgroundImage_linklabel
			// 
			this->openBackgroundImage_linklabel->AutoSize = true;
			this->openBackgroundImage_linklabel->Location = System::Drawing::Point(508, 407);
			this->openBackgroundImage_linklabel->Name = L"openBackgroundImage_linklabel";
			this->openBackgroundImage_linklabel->Size = System::Drawing::Size(35, 12);
			this->openBackgroundImage_linklabel->TabIndex = 7;
			this->openBackgroundImage_linklabel->TabStop = true;
			this->openBackgroundImage_linklabel->Text = L"Open";
			this->openBackgroundImage_linklabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SignUpForm::openBackgroundImage_linklabel_LinkClicked);
			// 
			// birthdate_textbox
			// 
			this->birthdate_textbox->Location = System::Drawing::Point(120, 120);
			this->birthdate_textbox->Name = L"birthdate_textbox";
			this->birthdate_textbox->Size = System::Drawing::Size(423, 21);
			this->birthdate_textbox->TabIndex = 4;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(21, 123);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(54, 12);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Birthdate";
			this->label7->Click += gcnew System::EventHandler(this, &SignUpForm::label4_Click);
			// 
			// profileMessage_textbox
			// 
			this->profileMessage_textbox->Location = System::Drawing::Point(120, 147);
			this->profileMessage_textbox->Name = L"profileMessage_textbox";
			this->profileMessage_textbox->Size = System::Drawing::Size(423, 21);
			this->profileMessage_textbox->TabIndex = 5;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(21, 150);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(97, 12);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Profile Message";
			this->label8->Click += gcnew System::EventHandler(this, &SignUpForm::label4_Click);
			// 
			// SignUpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(571, 468);
			this->Controls->Add(this->openBackgroundImage_linklabel);
			this->Controls->Add(this->openProfileImage_linklabel);
			this->Controls->Add(this->backgroundImage_picturebox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->profileImage_picturebox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->profileMessage_textbox);
			this->Controls->Add(this->birthdate_textbox);
			this->Controls->Add(this->phoneNumber_textbox);
			this->Controls->Add(this->name_textbox);
			this->Controls->Add(this->password_textbox);
			this->Controls->Add(this->id_textbox);
			this->Controls->Add(this->submit_button);
			this->Name = L"SignUpForm";
			this->Text = L"Create Account";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profileImage_picturebox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundImage_picturebox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void openProfileImage_linklabel_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
{
	OpenFileDialog^ opener = gcnew OpenFileDialog();
	opener->Title = "Select a Image File";
	opener->Filter = "Image files (*.jpg, *.jpeg, *.jpe, *.jfif, *.png) | *.jpg; *.jpeg; *.jpe; *.jfif; *.png";

	if (opener->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		profileImage_picturebox->ImageLocation = opener->FileName;
		
	}
}
private: System::Void openBackgroundImage_linklabel_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
{
	OpenFileDialog^ opener = gcnew OpenFileDialog();
	opener->Title = "Select a Image File";
	opener->Filter = "Image files (*.jpg, *.jpeg, *.jpe, *.jfif, *.png) | *.jpg; *.jpeg; *.jpe; *.jfif; *.png";

	if (opener->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		backgroundImage_picturebox->ImageLocation = opener->FileName;
		//IO::File::Copy(opener->FileName, IO::Directory::GetCurrentDirectory() + "\\pictures\\"+);
	}
}
private: System::Void submit_button_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (app->CreateAccount(
		msclr::interop::marshal_as<std::string>(id_textbox->Text),
		msclr::interop::marshal_as<std::string>(password_textbox->Text),
		msclr::interop::marshal_as<std::string>(name_textbox->Text),
		msclr::interop::marshal_as<std::string>(birthdate_textbox->Text),
		msclr::interop::marshal_as<std::string>(phoneNumber_textbox->Text),
		msclr::interop::marshal_as<std::string>(profileMessage_textbox->Text)
	)) {
		if(profileImage_picturebox->Image != nullptr) {
			profileImage_picturebox->Image->Save(IO::Directory::GetCurrentDirectory() + "\\pictures\\profile\\" + id_textbox->Text);
			
		}
		if (backgroundImage_picturebox->Image != nullptr) {
			backgroundImage_picturebox->Image->Save(IO::Directory::GetCurrentDirectory() + "\\pictures\\background\\" + id_textbox->Text);

		}
		this->Close();
	}
	else
		MessageBox::Show("Existing ID!");
}
};
}
