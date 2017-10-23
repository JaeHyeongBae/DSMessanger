#pragma once
#include <msclr/marshal_cppstd.h>
#include "MessangerApp.h"
#include "SettingForm.h"

namespace DSMessanger {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		MessangerApp* app;
		Thread^ update;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  birthdate_label;

	public:
		String^ my_id;
	private: System::Windows::Forms::Label^  status_label;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteAccountToolStripMenuItem;
	private: System::Windows::Forms::LinkLabel^  linkLabel_deleteFriend;



	public:

	public:

	public:
		MemberType* my_mem;
		MainForm(String^ id)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			app = MessangerApp::GetInstance();
			my_id = id;
			my_mem = app->memberList.Retrieve(msclr::interop::marshal_as<std::string>(id));
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  send_button;
	private: System::Windows::Forms::RichTextBox^  chatlog_richtextbox;
	protected:


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  accountToolStripMenuItem;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  chat_textbox;



	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ListBox^  friend_listbox;

	private: System::Windows::Forms::ToolStripMenuItem^  signOutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  accountSettingsToolStripMenuItem;

	private: System::Windows::Forms::PictureBox^  profile_picturebox;
	private: System::Windows::Forms::Label^  name_label;
	private: System::Windows::Forms::Label^  id_label;
	private: System::Windows::Forms::Label^  phoneNumer_label;

	private: System::Windows::Forms::Label^  profileMessage_label;


	private: System::Windows::Forms::Button^  friendAdd_button;
	private: System::Windows::Forms::TextBox^  friend_textbox;






	private: System::Windows::Forms::ToolStripMenuItem^  friendsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  refreshToolStripMenuItem;



	private: System::ComponentModel::IContainer^  components;

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
			this->send_button = (gcnew System::Windows::Forms::Button());
			this->chatlog_richtextbox = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->accountToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->signOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->accountSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteAccountToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->friendsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->refreshToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->chat_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->friend_listbox = (gcnew System::Windows::Forms::ListBox());
			this->profile_picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->id_label = (gcnew System::Windows::Forms::Label());
			this->phoneNumer_label = (gcnew System::Windows::Forms::Label());
			this->profileMessage_label = (gcnew System::Windows::Forms::Label());
			this->friendAdd_button = (gcnew System::Windows::Forms::Button());
			this->friend_textbox = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->birthdate_label = (gcnew System::Windows::Forms::Label());
			this->status_label = (gcnew System::Windows::Forms::Label());
			this->linkLabel_deleteFriend = (gcnew System::Windows::Forms::LinkLabel());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profile_picturebox))->BeginInit();
			this->SuspendLayout();
			// 
			// send_button
			// 
			this->send_button->Location = System::Drawing::Point(245, 379);
			this->send_button->Name = L"send_button";
			this->send_button->Size = System::Drawing::Size(75, 23);
			this->send_button->TabIndex = 0;
			this->send_button->Text = L"Send";
			this->send_button->UseVisualStyleBackColor = true;
			this->send_button->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// chatlog_richtextbox
			// 
			this->chatlog_richtextbox->BackColor = System::Drawing::SystemColors::Window;
			this->chatlog_richtextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->chatlog_richtextbox->Location = System::Drawing::Point(14, 39);
			this->chatlog_richtextbox->Name = L"chatlog_richtextbox";
			this->chatlog_richtextbox->Size = System::Drawing::Size(306, 328);
			this->chatlog_richtextbox->TabIndex = 1;
			this->chatlog_richtextbox->Text = L"Me     >> Hello!\nFriend >> Hi!";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->accountToolStripMenuItem,
					this->friendsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(659, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// accountToolStripMenuItem
			// 
			this->accountToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->signOutToolStripMenuItem,
					this->accountSettingsToolStripMenuItem, this->deleteAccountToolStripMenuItem
			});
			this->accountToolStripMenuItem->Name = L"accountToolStripMenuItem";
			this->accountToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->accountToolStripMenuItem->Text = L"Account";
			// 
			// signOutToolStripMenuItem
			// 
			this->signOutToolStripMenuItem->Name = L"signOutToolStripMenuItem";
			this->signOutToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->signOutToolStripMenuItem->Text = L"Sign Out";
			this->signOutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::signOutToolStripMenuItem_Click);
			// 
			// accountSettingsToolStripMenuItem
			// 
			this->accountSettingsToolStripMenuItem->Name = L"accountSettingsToolStripMenuItem";
			this->accountSettingsToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->accountSettingsToolStripMenuItem->Text = L"Account Settings";
			this->accountSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::accountSettingsToolStripMenuItem_Click);
			// 
			// deleteAccountToolStripMenuItem
			// 
			this->deleteAccountToolStripMenuItem->Name = L"deleteAccountToolStripMenuItem";
			this->deleteAccountToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->deleteAccountToolStripMenuItem->Text = L"Delete Account";
			this->deleteAccountToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::deleteAccountToolStripMenuItem_Click);
			// 
			// friendsToolStripMenuItem
			// 
			this->friendsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->refreshToolStripMenuItem });
			this->friendsToolStripMenuItem->Name = L"friendsToolStripMenuItem";
			this->friendsToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->friendsToolStripMenuItem->Text = L"Friends";
			// 
			// refreshToolStripMenuItem
			// 
			this->refreshToolStripMenuItem->Name = L"refreshToolStripMenuItem";
			this->refreshToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->refreshToolStripMenuItem->Text = L"Refresh";
			this->refreshToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::refreshToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 12);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Chat";
			// 
			// chat_textbox
			// 
			this->chat_textbox->Location = System::Drawing::Point(14, 380);
			this->chat_textbox->Name = L"chat_textbox";
			this->chat_textbox->Size = System::Drawing::Size(225, 21);
			this->chat_textbox->TabIndex = 4;
			this->chat_textbox->TextChanged += gcnew System::EventHandler(this, &MainForm::chat_textbox_TextChanged);
			this->chat_textbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::chat_textbox_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(324, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 12);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Friends";
			// 
			// friend_listbox
			// 
			this->friend_listbox->FormattingEnabled = true;
			this->friend_listbox->ItemHeight = 12;
			this->friend_listbox->Location = System::Drawing::Point(326, 39);
			this->friend_listbox->Name = L"friend_listbox";
			this->friend_listbox->Size = System::Drawing::Size(120, 328);
			this->friend_listbox->TabIndex = 5;
			this->friend_listbox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::friend_listbox_SelectedIndexChanged);
			// 
			// profile_picturebox
			// 
			this->profile_picturebox->BackColor = System::Drawing::Color::Transparent;
			this->profile_picturebox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->profile_picturebox->ImageLocation = L"";
			this->profile_picturebox->Location = System::Drawing::Point(452, 39);
			this->profile_picturebox->Name = L"profile_picturebox";
			this->profile_picturebox->Size = System::Drawing::Size(195, 153);
			this->profile_picturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->profile_picturebox->TabIndex = 6;
			this->profile_picturebox->TabStop = false;
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->BackColor = System::Drawing::SystemColors::Control;
			this->name_label->Location = System::Drawing::Point(452, 195);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(43, 12);
			this->name_label->TabIndex = 7;
			this->name_label->Text = L"Name:";
			// 
			// id_label
			// 
			this->id_label->AutoSize = true;
			this->id_label->Location = System::Drawing::Point(452, 220);
			this->id_label->Name = L"id_label";
			this->id_label->Size = System::Drawing::Size(20, 12);
			this->id_label->TabIndex = 7;
			this->id_label->Text = L"ID:";
			// 
			// phoneNumer_label
			// 
			this->phoneNumer_label->AutoSize = true;
			this->phoneNumer_label->Location = System::Drawing::Point(452, 245);
			this->phoneNumer_label->Name = L"phoneNumer_label";
			this->phoneNumer_label->Size = System::Drawing::Size(94, 12);
			this->phoneNumer_label->TabIndex = 7;
			this->phoneNumer_label->Text = L"Phone Number:";
			// 
			// profileMessage_label
			// 
			this->profileMessage_label->AutoSize = true;
			this->profileMessage_label->Location = System::Drawing::Point(452, 310);
			this->profileMessage_label->Name = L"profileMessage_label";
			this->profileMessage_label->Size = System::Drawing::Size(101, 12);
			this->profileMessage_label->TabIndex = 7;
			this->profileMessage_label->Text = L"Profile Message:";
			// 
			// friendAdd_button
			// 
			this->friendAdd_button->Location = System::Drawing::Point(422, 380);
			this->friendAdd_button->Name = L"friendAdd_button";
			this->friendAdd_button->Size = System::Drawing::Size(24, 23);
			this->friendAdd_button->TabIndex = 0;
			this->friendAdd_button->Text = L"+";
			this->friendAdd_button->UseVisualStyleBackColor = true;
			this->friendAdd_button->Click += gcnew System::EventHandler(this, &MainForm::friendAdd_button_Click);
			// 
			// friend_textbox
			// 
			this->friend_textbox->Location = System::Drawing::Point(326, 381);
			this->friend_textbox->Name = L"friend_textbox";
			this->friend_textbox->Size = System::Drawing::Size(90, 21);
			this->friend_textbox->TabIndex = 4;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 200;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// birthdate_label
			// 
			this->birthdate_label->AutoSize = true;
			this->birthdate_label->Location = System::Drawing::Point(452, 268);
			this->birthdate_label->Name = L"birthdate_label";
			this->birthdate_label->Size = System::Drawing::Size(44, 12);
			this->birthdate_label->TabIndex = 7;
			this->birthdate_label->Text = L"Status:";
			// 
			// status_label
			// 
			this->status_label->AutoSize = true;
			this->status_label->Location = System::Drawing::Point(452, 290);
			this->status_label->Name = L"status_label";
			this->status_label->Size = System::Drawing::Size(44, 12);
			this->status_label->TabIndex = 7;
			this->status_label->Text = L"Status:";
			// 
			// linkLabel_deleteFriend
			// 
			this->linkLabel_deleteFriend->AutoSize = true;
			this->linkLabel_deleteFriend->Location = System::Drawing::Point(568, 390);
			this->linkLabel_deleteFriend->Name = L"linkLabel_deleteFriend";
			this->linkLabel_deleteFriend->Size = System::Drawing::Size(79, 12);
			this->linkLabel_deleteFriend->TabIndex = 8;
			this->linkLabel_deleteFriend->TabStop = true;
			this->linkLabel_deleteFriend->Text = L"Delete Friend";
			this->linkLabel_deleteFriend->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainForm::linkLabel_deleteFriend_LinkClicked);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(659, 414);
			this->Controls->Add(this->linkLabel_deleteFriend);
			this->Controls->Add(this->status_label);
			this->Controls->Add(this->birthdate_label);
			this->Controls->Add(this->profileMessage_label);
			this->Controls->Add(this->phoneNumer_label);
			this->Controls->Add(this->id_label);
			this->Controls->Add(this->name_label);
			this->Controls->Add(this->profile_picturebox);
			this->Controls->Add(this->friend_listbox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->friend_textbox);
			this->Controls->Add(this->chat_textbox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->friendAdd_button);
			this->Controls->Add(this->chatlog_richtextbox);
			this->Controls->Add(this->send_button);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"DS Messanger";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profile_picturebox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		sendMessage();
	}
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		refreshFriendList();
		updateChatLog();
	}
	private: System::Void chat_textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void refreshToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	refreshFriendList();
}
		 //update listbox that displays list of friends
private: void refreshFriendList()
{
	friend_listbox->Items->Clear();
	FriendType mem;
	SortedLinkedList<FriendType>& friend_list = my_mem->friendList;
	friend_list.ResetList();
	for (int i = 0; i < friend_list.GetLength(); i++)
	{
		friend_list.GetNextItem(mem);
		if(gcnew System::String(mem.ID.c_str()) != my_id)
			friend_listbox->Items->Add(gcnew System::String(mem.Name.c_str()));
	}
}
private: void sendMessage()
{
	if (friend_listbox->SelectedItem) {
		MemberType* mem = app->memberList.RetrieveByName(msclr::interop::marshal_as<std::string>(friend_listbox->SelectedItem->ToString()));
		if (mem != nullptr)
			app->GetMessageFromClient(msclr::interop::marshal_as<std::string>(chat_textbox->Text), mem->ID, my_mem->ID);
		updateChatLog();
		chat_textbox->Text = "";
	}
}

		 //update chat log textbox with latest friend selection & messages
private: void updateChatLog()
{
	if (friend_listbox->SelectedIndex >= 0) {
		MemberType* mem = app->memberList.RetrieveByName(msclr::interop::marshal_as<std::string>(friend_listbox->SelectedItem->ToString()));
		if (mem == nullptr)
		{
			refreshFriendList();
			chatlog_richtextbox->Text = "";
			return;
		}
		String^ log = gcnew String("");
		my_mem->chatList.ResetList();
		for (int i = 0; i < my_mem->chatList.GetLength(); i++)
		{
			MessageType msg;
			my_mem->chatList.GetNextItem(msg);
			if (msg.reciever == mem->ID || msg.sender == mem->ID)
				log += gcnew String((msg.sender + ">> " + msg.message + "\n").c_str());
		}
		chatlog_richtextbox->Text = log;
	}
	else
		chatlog_richtextbox->Text = "";
}

private: System::Void signOutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	app->Logout(my_mem->ID);
	this->Close();
}
		 //Get Friend's Info and update displayed info
private: System::Void friend_listbox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
{
	if (friend_listbox->SelectedIndex >= 0) {
		MemberType* mem = my_mem->friendList.RetrieveByName(msclr::interop::marshal_as<std::string>(friend_listbox->SelectedItem->ToString()))->Pmem;
		name_label->Text = "Name:  " + gcnew String(mem->Name.c_str());
		id_label->Text = "ID:    " + gcnew String(mem->ID.c_str());
		phoneNumer_label->Text = "Tel:   " + gcnew String(mem->PhoneNumber.c_str());
		birthdate_label->Text = "BDate: " + gcnew String(mem->Birthdate.c_str());
		if (mem->IsLoggedIn)
			status_label->Text = "Status: Logged In";
		else
			status_label->Text = "Status: Not Logged In";
		profileMessage_label->Text = "Profile Message:\n" + gcnew String(mem->ProfileMessage.c_str());
		if (IO::File::Exists(IO::Directory::GetCurrentDirectory() + "\\pictures\\profile\\" + gcnew String(mem->ID.c_str())))
			profile_picturebox->ImageLocation = IO::Directory::GetCurrentDirectory() + "\\pictures\\profile\\" + gcnew String(mem->ID.c_str());
		else
			profile_picturebox->ImageLocation = IO::Directory::GetCurrentDirectory() + "\\pictures\\profile\\default.jpeg";

		if (IO::File::Exists(IO::Directory::GetCurrentDirectory() + "\\pictures\\background\\" + gcnew String(mem->ID.c_str()))) {
			Image^ bg = Image::FromFile(IO::Directory::GetCurrentDirectory() + "\\pictures\\background\\" + gcnew String(mem->ID.c_str()));
			this->BackgroundImage = bg;
		}
		updateChatLog();
	}
}
private: System::Void backgroundWorker_updatelog_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
{
}
		 //called every 200 ms
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	updateChatLog();
}
private: System::Void chat_textbox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
{
	if (e->KeyChar.Equals((char)13))//Hit Enter
	{
		sendMessage();
		e->Handled = true;
	}
}

private: System::Void friendAdd_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	try
	{
		if (!(app->AddFriend(my_mem->ID, msclr::interop::marshal_as<std::string>(friend_textbox->Text))))
		{
			MessageBox::Show(L"No such member found!");
		}
		friend_textbox->Text = "";
		refreshFriendList();
	}
	catch (char* e)
	{

	}
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	if(!delAccount) app->Logout(my_mem->ID);
}
private: System::Void accountSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	String^ tmp_id = my_id;
	SettingForm^ setting = gcnew SettingForm(my_mem);
	setting->ShowDialog();
}
private: bool delAccount = false;
private: System::Void deleteAccountToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	delAccount = true;
	app->DeleteAccount(my_mem->ID);
	my_mem = nullptr;
	this->Close();
}
private: System::Void contextMenuStrip1_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void menuStrip2_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
}
private: System::Void linkLabel_deleteFriend_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
{
	app->DeleteFriend(my_mem->ID, msclr::interop::marshal_as<std::string>(friend_listbox->SelectedItem->ToString()));
	refreshFriendList();
	updateChatLog();
}
};
}
