#include"winsock2.h"
#include"stdio.h"
int paramCheck(int argv,char **args){
	int paramError(){
		printf("%s [target_port]\n",*args);
		return 1;		
	}
	if(argv!=2){
		return paramError();
	}
	else if(strlen(args[1])>5){
		return paramError();
	}
	int i;
	for(i=strlen(args[1])-1;i>=0;i--){
		if(args[1][i]<'0'||args[1][i]>'9'){
			return paramError();
		}
	}
	return 0;
}
void main(int argv,char **args){
	if(paramCheck(argv,args)){
		return;
	}
	WSADATA wsa;	
	WSAStartup(MAKEWORD(1,0),&wsa);
	SOCKET ss;
	ss=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	SOCKADDR_IN sAddr;
	memset(&sAddr,0,sizeof(SOCKADDR_IN));
	sAddr.sin_family=AF_INET;
	sAddr.sin_port=htons(atoi(args[1]));
	sAddr.sin_addr.s_addr=inet_addr("0.0.0.0");
	bind(ss,(const SOCKADDR *)&sAddr,sizeof(sAddr));
	listen(ss,1);
	SOCKET cs;
	SOCKADDR cAddr;
	int cAddrSize=sizeof(cAddr);
	cs=accept(ss,&cAddr,&cAddrSize);
	char *respond="Hello";
	send(cs,respond,(strlen(respond)+1)*sizeof(char),0);
	closesocket(cs);
	closesocket(ss);
	WSACleanup();
	return;	
}