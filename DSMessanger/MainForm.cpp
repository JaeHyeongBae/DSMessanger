#include "MainForm.h"
#include "LogInForm.h"
#include "SignUpForm.h"
#include "MessangerApp.h"
#include "StartForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DSMessanger::LogInForm login;
	DSMessanger::SignUpForm signup;
	DSMessanger::StartForm start;
	MessangerApp::GetInstance();
	Application::Run(%start);

	//Application::Run(%login);
}