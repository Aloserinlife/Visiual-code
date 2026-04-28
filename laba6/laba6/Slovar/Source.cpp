#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// ВНИМАНИЕ: Проверь, чтобы имя Laba2 совпадало с твоим проектом!
	Slovar::MyForm form;
	Application::Run(% form);
}