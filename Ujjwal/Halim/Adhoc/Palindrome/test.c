#include<stdio.h>
#include<string.h>
int main(){
	char inp[1000];
	scanf("%[^EOF]s", inp);
	int count = 1;
	for(int i=0; i<strlen(inp); i++){
		if(inp[i] == '"'){
			if(count%2 == 0){
				printf("''");
			}
			
			else{
				printf("``");
			}
			count++;
		}else{
			printf("%c", inp[i]);
		}
	}
	return 0;
}
