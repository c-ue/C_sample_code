#include"stdio.h"
#include"windows.h"
void main(){
	char a[10];	
	scanf("%10s",a);
	HINSTANCE DllHandler;
	typedef void (__stdcall *func)();
	func MsgBox;
	DllHandler=LoadLibrary(TEXT("print.dll"));
	if(!DllHandler){
		printf("Dll is not exist!");
		return;
	}
	MsgBox=(func)GetProcAddress(DllHandler,"MsgHello");
	if(!MsgBox){
		printf("Func not exist!");
		return;
	}
	MsgBox(a);
	FreeLibrary(DllHandler);
	return;
}