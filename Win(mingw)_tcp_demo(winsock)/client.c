#include"winsock2.h"
#include"stdio.h"
#define BUFFER_LEN 4096
int paramCheck(int argv,char **args){
	int paramError(){
		printf("%s [target_ip] [target_port]\n",*args);
		return 1;		
	}
	if(argv!=3){
		return paramError();
	}
	else if(isValidIp4(args[1])){
		return paramError();
	}
	int i,j;
	for(i=0,j=0;i<strlen(args[2]);i++){
		if(args[2][i]<'0'||args[2][i]>'9'){
			return paramError();
		}
		j=j*10+args[2][i]-'0';
		if(j>65535){
			return paramError();
		}
	}
	return 0;
}
int isValidIp4(char *str){
    int segs = 0;
    int chcnt = 0;
    int accum = 0;
    if (str == NULL)
        return 1;
    while (*str != '\0') {
        if (*str == '.') {
            if (chcnt == 0)
                return 1;
            if (++segs == 4)
                return 1;
            chcnt = accum = 0;
            str++;
            continue;
        }
        if ((*str < '0') || (*str > '9'))
            return 1;
        if ((accum = accum * 10 + *str - '0') > 255)
            return 1;
        chcnt++;
        str++;
    }
    if (segs != 3)
        return 1;
    if (chcnt == 0)
        return 1;
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
	sAddr.sin_port=htons(atoi(args[2]));
	sAddr.sin_addr.s_addr=inet_addr(args[1]);
	connect(ss,(const SOCKADDR *)&sAddr,sizeof(sAddr));
	char *buf=(char *)malloc(sizeof(char)*BUFFER_LEN);
	recv(ss,buf,BUFFER_LEN,0);
	printf("%s",buf);
	free(buf);
	closesocket(ss);
	WSACleanup();
	return;	
}