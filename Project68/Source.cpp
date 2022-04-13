#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <windows.h>

using namespace std;

void process(const char* file, const char* file1);
void diy(const char* strin, char* strout);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	process("file.txt", "file1.txt");
}

void process(const char* file, const char* file1)
{
	FILE* f = fopen(file, "rt");
	if (f == NULL)
	{
		cout << "File is not open  " << endl;
		return;
	}
	ofstream fo;
	fo.open(file1);
	if (!fo.is_open())
	{
		cout << "File is not open " << endl;
		fclose(f);
		return;
	}
	while (!feof(f))
	{
		char buff[250];
		buff[0] = 0;
		fgets(buff, 250, f);
		if (strlen(buff) > 0)
		{
			char buff2[250];
			diy(buff, buff2);
			fo << buff2;
		}
	}
	fclose(f);
	fo.close();
}



void diy(const char* str_l, char* resault_l) {
	memset(resault_l, 0, sizeof(char) * 250);

	char str[250] = {};
	for (short i = 0; i < strlen(str_l); i++) {
		str[i] = str_l[i];
	}
	
	char name[] = "Зая";
	int i = 0;
	char result[250] = {};
	int slice = 0;
	char second_processing[50] = {};
	while (true) {
		memset(second_processing, 0, sizeof(char) * 50);
		slice = strcspn(i+str, " ");
		int adr = slice + i;
		if (i == adr)break;
		strncpy(second_processing, i + str, slice);

		if (second_processing[0] == 'н' && second_processing[1] == 'е'&& second_processing[2] == 'т' && second_processing[3] == 0|| second_processing[0] == 'д' && second_processing[1] == 'а' && second_processing[2] == 0) {
			strcat(result, "может быть");
			strcat(result, " ");
		}
		else if (second_processing[0] >= 'А' && second_processing[0] <= 'Я') {
			strcat(result, name);
			strcat(result, " ");
		}
		else
		{
			strncat(result, i + str, slice);
			strcat(result, " ");
		}
		i = slice+i+1;
	}
	for (int i = 0; i < strlen(result); i++)
	{
		resault_l[i] = result[i];
	}
}