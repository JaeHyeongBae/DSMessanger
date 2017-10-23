#pragma once
#include <msclr/marshal_cppstd.h>
#include "MemberType.h"
#include "MessangerApp.h"
namespace DSMessanger {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SettingForm
	/// </summary>
	public ref class SettingForm : public System::Windows::Forms::Form
	{
	private:
		MemberType* my_mem;
		MessangerApp* app;

		String^ prof_src = "";
		String^ bg_src = "";
	public:
		SettingForm(MemberType* mem)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			my_mem = mem;
			app = MessangerApp::GetInstance();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SettingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox_profile;
	protected:

	protected:


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button_profile;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox_tel;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox_msg;

	private: System::Windows::Forms::Button^  button_save;




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox_background;
	private: System::Windows::Forms::Button^  button_background;



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
			this->pictureBox_profile = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button_profile = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_tel = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox_msg = (gcnew System::Windows::Forms::TextBox());
			this->button_save = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_background = (gcnew System::Windows::Forms::PictureBox());
			this->button_background = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_profile))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_background))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox_profile
			// 
			this->pictureBox_profile->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox_profile->Location = System::Drawing::Point(105, 12);
			this->pictureBox_profile->Name = L"pictureBox_profile";
			this->pictureBox_profile->Size = System::Drawing::Size(136, 129);
			this->pictureBox_profile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_profile->TabIndex = 2;
			this->pictureBox_profile->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Profile Image";
			this->label2->Click += gcnew System::EventHandler(this, &SettingForm::label1_Click);
			// 
			// button_profile
			// 
			this->button_profile->Location = System::Drawing::Point(10, 118);
			this->button_profile->Name = L"button_profile";
			this->button_profile->Size = System::Drawing::Size(75, 23);
			this->button_profile->TabIndex = 3;
			this->button_profile->Text = L"Open";
			this->button_profile->UseVisualStyleBackColor = true;
			this->button_profile->Click += gcnew System::EventHandler(this, &SettingForm::button_profile_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 190);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(90, 12);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Phone Number";
			this->label3->Click += gcnew System::EventHandler(this, &SettingForm::label1_Click);
			// 
			// textBox_tel
			// 
			this->textBox_tel->Location = System::Drawing::Point(105, 183);
			this->textBox_tel->Name = L"textBox_tel";
			this->textBox_tel->Size = System::Drawing::Size(383, 21);
			this->textBox_tel->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 217);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 12);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Profile Msg.";
			this->label4->Click += gcnew System::EventHandler(this, &SettingForm::label1_Click);
			// 
			// textBox_msg
			// 
			this->textBox_msg->Location = System::Drawing::Point(105, 210);
			this->textBox_msg->Name = L"textBox_msg";
			this->textBox_msg->Size = System::Drawing::Size(383, 21);
			this->textBox_msg->TabIndex = 4;
			// 
			// button_save
			// 
			this->button_save->Location = System::Drawing::Point(413, 269);
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(75, 23);
			this->button_save->TabIndex = 5;
			this->button_save->Text = L"Save";
			this->button_save->UseVisualStyleBackColor = true;
			this->button_save->Click += gcnew System::EventHandler(this, &SettingForm::button_save_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(244, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Background Image";
			this->label1->Click += gcnew System::EventHandler(this, &SettingForm::label1_Click);
			// 
			// pictureBox_background
			// 
			this->pictureBox_background->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox_background->Location = System::Drawing::Point(352, 12);
			this->pictureBox_background->Name = L"pictureBox_background";
			this->pictureBox_background->Size = System::Drawing::Size(136, 129);
			this->pictureBox_background->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_background->TabIndex = 2;
			this->pictureBox_background->TabStop = false;
			// 
			// button_background
			// 
			this->button_background->Location = System::Drawing::Point(257, 118);
			this->button_background->Name = L"button_background";
			this->button_background->Size = System::Drawing::Size(75, 23);
			this->button_background->TabIndex = 3;
			this->button_background->Text = L"Open";
			this->button_background->UseVisualStyleBackColor = true;
			this->button_background->Click += gcnew System::EventHandler(this, &SettingForm::button_background_Click);
			// 
			// SettingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 295);
			this->Controls->Add(this->button_save);
			this->Controls->Add(this->textBox_msg);
			this->Controls->Add(this->textBox_tel);
			this->Controls->Add(this->button_background);
			this->Controls->Add(this->button_profile);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox_background);
			this->Controls->Add(this->pictureBox_profile);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Name = L"SettingForm";
			this->Text = L"Account Settings";
			this->Load += gcnew System::EventHandler(this, &SettingForm::SettingForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_profile))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_background))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button_profile_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenFileDialog^ opener = gcnew OpenFileDialog();
		opener->Title = "Select a Image File";
		opener->Filter = "Image files (*.jpg, *.jpeg, *.jpe, *.jfif, *.png) | *.jpg; *.jpeg; *.jpe; *.jfif; *.png";

		if (opener->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			pictureBox_profile->ImageLocation = opener->FileName;
			prof_src = opener->FileName;

		}
	}
private: System::Void button_background_Click(System::Object^  sender, System::EventArgs^  e) 
{
	OpenFileDialog^ opener = gcnew OpenFileDialog();
	opener->Title = "Select a Image File";
	opener->Filter = "Image files (*.jpg, *.jpeg, *.jpe, *.jfif, *.png) | *.jpg; *.jpeg; *.jpe; *.jfif; *.png";

	if (opener->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		pictureBox_background->ImageLocation = opener->FileName;
		bg_src = opener->FileName;
	}
}
private: System::Void SettingForm_Load(System::Object^  sender, System::EventArgs^  e) 
{
	//show current profile on load
	pictureBox_profile->ImageLocation = IO::Directory::GetCurrentDirectory() + "\\pictures\\profile\\" + gcnew String(my_mem->ID.c_str());
	pictureBox_background->ImageLocation = IO::Directory::GetCurrentDirectory() + "\\pictures\\background\\" + gcnew String(my_mem->ID.c_str());
	textBox_tel->Text = gcnew String(my_mem->PhoneNumber.c_str());
	textBox_msg->Text = gcnew String(my_mem->ProfileMessage.c_str());
}

private: System::Void button_save_Click(System::Object^  sender, System::EventArgs^  e) 
{
	my_mem->PhoneNumber = msclr::interop::marshal_as<std::string>(textBox_tel->Text);
	my_mem->ProfileMessage = msclr::interop::marshal_as<std::string>(textBox_msg->Text);

	//If an image is loaded to picturebox, copy the image to server folder as id
	if(prof_src != "")
		IO::File::Copy(prof_src, IO::Directory::GetCurrentDirectory() + "\\pictures\\profile\\" + gcnew String(my_mem->ID.c_str()), true);
	if(bg_src != "")
		IO::File::Copy(bg_src, IO::Directory::GetCurrentDirectory() + "\\pictures\\background\\" + gcnew String(my_mem->ID.c_str()), true);
	this->Close();
}
};
}
