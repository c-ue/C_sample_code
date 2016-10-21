#include"stdio.h"
#include"windows.h"
void __stdcall MsgHello(char* str){
	MessageBox(NULL,(LPCSTR)str,(LPCSTR)"This is the message", MB_ICONINFORMATION|MB_OK);
	return;
}
