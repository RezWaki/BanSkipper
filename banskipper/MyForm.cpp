#include <Windows.h>
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace banskipper;

[STAThread]

INT WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, INT ) {
	Application::Run( gcnew MyForm );
	return TRUE;
}