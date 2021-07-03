#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>

typedef struct
{
	char Diem[10];
	char HoTen[40];
} Student;

void ReadFile(char *FileName);
void WriteFile(char *FileName);
void Search(char *FileName);

int main()
{
	int key;
	for (;;)
	{
		system("cls");
        printf("CHUONG TRINH QUAN LY SINH VIEN \n");
        printf("*******************************************************\n");
        printf("**  1. Hien thi danh sach sinh vien.                 **\n");
        printf("**  2. Them sinh vien.                               **\n");
        printf("**  3. Tim kiem sinh vien theo ten.                  **\n");
        printf("**  4. Thoat.                                        **\n");
        printf("*******************************************************\n");
		printf("Tuy chon 1, 2, 3, 4: ");
		scanf("%d",&key);
		fflush(stdin);
		switch(key){
		case 1:
        ReadFile("SV2021.dat");
		break;
		case 2:
        WriteFile("SV2021.dat");
		break;
		case 3:
        Search("SV2021.dat");
		break;
		case 4:
        printf("\nBan da chon thoat chuong trinh!");
        getch();
        return 0;
        default:
        printf("\nKhong co chuc nang nay!");
        getch();
        system("cls");
        break;
	}
}
}
void WriteFile(char *FileName)
{
	FILE *f;
	int n,i;
	Student sv;
	f=fopen(FileName,"ab");
	printf("Nhap vao so luong sinh vien ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Sinh vien thu %i\n",i);
		fflush(stdin);
		printf(" - Ho ten: ");
		gets(sv.HoTen);
		printf(" - Diem: ");
		gets(sv.Diem);
		fwrite(&sv,sizeof(sv),1,f);
	}
	fclose(f);
	printf("Bam phim bat ky de tiep tuc.");
	getch();
}
void ReadFile(char *FileName)
{
	FILE *f;
	Student sv;

	f=fopen(FileName,"rb");
	printf("  Ho va ten | Diem\n");
    printLine(55);
	fread(&sv,sizeof(sv),1,f);
	while (!feof(f))
	{
		printf(" %s | %s \n",sv.HoTen,sv.Diem);
		fread(&sv,sizeof(sv),1,f);
	}
	fclose(f);
	printf("Bam phim bat ky de tiep tuc.");
	getch();
}

void Search(char *FileName)
{
	char HoTen[40];
	FILE *f;
	int Found=0;
	Student sv;
	fflush(stdin);
	printf("Ten sinh vien can tim: ");
	gets(HoTen);
	f=fopen(FileName,"rb");
	while (!feof(f) && Found==0)
	{
		fread(&sv,sizeof(sv),1,f);
		if (strcmp(sv.HoTen,HoTen)==0)
			Found=1;
	}
	fclose(f);
	if (Found == 1)
	{
		printf("Tim thay SV co ten %s. Diem la: %s",sv.HoTen,sv.Diem);
		char fileName[] = "output.txt";
		f=fopen(fileName,"w");
		fprintf(f, "%30s%30s\n", "Ho Ten","Diem");
    	fprintf(f, "%30s%30s\n", sv.HoTen, sv.Diem);
		fclose(f);
	}
	else
	{
		printf("Khong thay sinh vien co ten %s",HoTen);
	}
	printf("\nBam phim bat ky de tiep tuc.");
	getch();
}
void printLine(int n) {
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%c",95);
    }
    printf("\n");
}
