#pragma once
#include "MessangerApp.h"
namespace DSMessanger {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ServerForm
	/// </summary>
	public ref class ServerForm : public System::Windows::Forms::Form
	{
	private:
		MessangerApp* app;
	public:
		ServerForm(void)
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
		~ServerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  process_button;
	private: System::Windows::Forms::TextBox^  textBox_interval;
	private: System::Windows::Forms::CheckBox^  checkBox_automode;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->process_button = (gcnew System::Windows::Forms::Button());
			this->textBox_interval = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_automode = (gcnew System::Windows::Forms::CheckBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// process_button
			// 
			this->process_button->Location = System::Drawing::Point(12, 53);
			this->process_button->Name = L"process_button";
			this->process_button->Size = System::Drawing::Size(194, 124);
			this->process_button->TabIndex = 0;
			this->process_button->Text = L"Process";
			this->process_button->UseVisualStyleBackColor = true;
			this->process_button->Click += gcnew System::EventHandler(this, &ServerForm::process_button_Click);
			// 
			// textBox_interval
			// 
			this->textBox_interval->Location = System::Drawing::Point(12, 17);
			this->textBox_interval->Name = L"textBox_interval";
			this->textBox_interval->Size = System::Drawing::Size(102, 21);
			this->textBox_interval->TabIndex = 1;
			this->textBox_interval->TextChanged += gcnew System::EventHandler(this, &ServerForm::textBox_interval_TextChanged);
			// 
			// checkBox_automode
			// 
			this->checkBox_automode->AutoSize = true;
			this->checkBox_automode->Location = System::Drawing::Point(120, 17);
			this->checkBox_automode->Name = L"checkBox_automode";
			this->checkBox_automode->Size = System::Drawing::Size(100, 16);
			this->checkBox_automode->TabIndex = 2;
			this->checkBox_automode->Text = L"Auto Process";
			this->checkBox_automode->UseVisualStyleBackColor = true;
			this->checkBox_automode->CheckedChanged += gcnew System::EventHandler(this, &ServerForm::checkBox_automode_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &ServerForm::timer1_Tick);
			// 
			// ServerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(218, 189);
			this->Controls->Add(this->checkBox_automode);
			this->Controls->Add(this->textBox_interval);
			this->Controls->Add(this->process_button);
			this->Name = L"ServerForm";
			this->Text = L"ServerForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void process_button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		app->SendMessageToClient();
	}
	private: System::Void checkBox_automode_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox_automode->Checked)
		{
			timer1->Enabled = true;
		}
	}
	private: System::Void textBox_interval_TextChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		timer1->Interval = Int32::Parse(textBox_interval->Text);
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	app->SendMessageToClient();
}
};
}
