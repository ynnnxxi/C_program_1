#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 100
#define SIZE 100
#include<stdio.h>
#include <string.h>

int main() {
	char code[5] = { 0, };
	char crc[5] = { 0, };
	char str[MAX_LEN];
	char o[5] = "0000";
	char str2[15] = { 0, };
	char *pch;
	int num = 0;

	printf("please, type 4-bit generation code: ");
	scanf("%s", code);
	
	printf("Please, type 10-dight data bits: ");
	scanf("%s", str);

	strcpy(str2, str);
	strcat(str2, o);

	while (num <= 9) {
		for (int i = num; i < 4 + num; i++) {
			
			if (str2[i] == code[i - num]) {
				str2[i] = '0';
			}

			else {
				str2[i] = '1';
			}
			
		}

		pch = strchr(str2, '1');
		num = pch - str2;
	}

	crc[0] = str2[13];
	crc[1] = str2[12];
	crc[2] = str2[11];
	crc[3] = str2[10];

	strcat(str, crc);
	
	printf("The data with Checksum is %s", str);
	
	return 0;
}
