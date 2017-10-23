#pragma once
#include <msclr/marshal_cppstd.h>
#include "MessangerApp.h"
#include "MainForm.h"
#include "SignUpForm.h"
namespace DSMessanger {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LogInForm
	/// </summary>
	public ref class LogInForm : public System::Windows::Forms::Form
	{
	private: MessangerApp* app;
	public:
		LogInForm(void)
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
		~LogInForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  id_textbox;
	private: System::Windows::Forms::TextBox^  pw_textbox;
	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  signIn_button;
	private: System::Windows::Forms::LinkLabel^  newaccount_label;


	protected:

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
			this->id_textbox = (gcnew System::Windows::Forms::TextBox());
			this->pw_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->signIn_button = (gcnew System::Windows::Forms::Button());
			this->newaccount_label = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// id_textbox
			// 
			this->id_textbox->Location = System::Drawing::Point(45, 12);
			this->id_textbox->Name = L"id_textbox";
			this->id_textbox->Size = System::Drawing::Size(165, 21);
			this->id_textbox->TabIndex = 0;
			// 
			// pw_textbox
			// 
			this->pw_textbox->Location = System::Drawing::Point(45, 39);
			this->pw_textbox->Name = L"pw_textbox";
			this->pw_textbox->PasswordChar = '*';
			this->pw_textbox->Size = System::Drawing::Size(165, 21);
			this->pw_textbox->TabIndex = 1;
			this->pw_textbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LogInForm::pw_textbox_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"ID ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"PW";
			// 
			// signIn_button
			// 
			this->signIn_button->Location = System::Drawing::Point(216, 12);
			this->signIn_button->Name = L"signIn_button";
			this->signIn_button->Size = System::Drawing::Size(56, 48);
			this->signIn_button->TabIndex = 4;
			this->signIn_button->Text = L"Sign In";
			this->signIn_button->UseVisualStyleBackColor = true;
			this->signIn_button->Click += gcnew System::EventHandler(this, &LogInForm::signIn_button_Click);
			// 
			// newaccount_label
			// 
			this->newaccount_label->AutoSize = true;
			this->newaccount_label->Location = System::Drawing::Point(12, 64);
			this->newaccount_label->Name = L"newaccount_label";
			this->newaccount_label->Size = System::Drawing::Size(81, 12);
			this->newaccount_label->TabIndex = 5;
			this->newaccount_label->TabStop = true;
			this->newaccount_label->Text = L"New Account";
			this->newaccount_label->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LogInForm::newaccount_label_LinkClicked);
			// 
			// LogInForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 85);
			this->Controls->Add(this->newaccount_label);
			this->Controls->Add(this->signIn_button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pw_textbox);
			this->Controls->Add(this->id_textbox);
			this->Name = L"LogInForm";
			this->Text = L"Sign In";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void signIn_button_Click(System::Object^  sender, System::EventArgs^  e) {
		if (app->Login(msclr::interop::marshal_as<std::string>(id_textbox->Text), msclr::interop::marshal_as<std::string>(pw_textbox->Text)))//Request log in
		{
			MainForm^ mainform = gcnew MainForm(id_textbox->Text);
			this->Visible = false;
			mainform->Show();
		}
		else
			MessageBox::Show("No Such ID/PW pair exists!");
	}
private: System::Void newaccount_label_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
{
	SignUpForm^ signup = gcnew SignUpForm();
	signup->Show();
}

private: System::Void pw_textbox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
{
	if (e->KeyChar.Equals((char)13))//Enter key is hit
	{
		if (app->Login(msclr::interop::marshal_as<std::string>(id_textbox->Text), msclr::interop::marshal_as<std::string>(pw_textbox->Text)))//Request log in
		{
			MainForm^ mainform = gcnew MainForm(id_textbox->Text);
			this->Visible = false;
			mainform->Show();
		}
		else
			MessageBox::Show("No Such ID/PW pair exists!");
		e->Handled = true;
	}
}
};
}
