#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define MAXM 13
#define MAXN 4

void khoiTaoMangC(bool c[][MAXN], int m, int n);
void chiaBai(int ngChoi[][MAXN], int m, int n, bool c[][MAXN]);
bool ok(int x, bool c[][MAXN]);
void baiCuaNgChoi(int ngChoi[][MAXN], int m, int j);
void inLaBai(int x);
void inTuQuy(int ngChoi[][MAXN], int m, int j);
void inDiem(int diem);
void inChat(int chat);
//void dungManHinh();

int main()
{
    bool c[MAXM][MAXN];
    int m=MAXM, n=MAXN;
    int ngChoi[MAXM][MAXN];
    //
    srand((unsigned)time(NULL));
    khoiTaoMangC(c, m, n);
    chiaBai(ngChoi, m, n, c);
    for(int j=0; j<n; j++) baiCuaNgChoi(ngChoi, m, j);
    //
    return 0;
}

//tat ca cac gia tri cua mang c duoc gan gia tri false
void khoiTaoMangC(bool c[][MAXN], int m, int n)
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++) c[i][j] = false;
}

//ham chia bai cho nguoi choi
void chiaBai(int ngChoi[][MAXN], int m, int n, bool c[][MAXN])
{
    int x;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            x = rand() % 52;
            while (!ok(x, c))
            {
                x++;
                if (x == 52) x = 0;
            }
            ngChoi[i][j] = x;
        }
    }
}

//ham kiem tra quan bai x da duoc chia hay chua
bool ok(int x, bool c[][MAXN])
{
    int i, j;
    i = x / 4;
    j = x % 4;
    if (!c[i][j])
    {
        c[i][j] = true;
        return true;
    }else return false;
}

//thong bao nguoi choi j co nhung la bai nao va co tu quy gi
void baiCuaNgChoi(int ngChoi[][MAXN], int m, int j)
{
    printf("Bai cua nguoi choi thu %d gom cac la bai:\n ", j+1);
    for(int i=0; i<m; i++)
    {
        inLaBai(ngChoi[i][j]);
        printf("\n");
    }
    inTuQuy(ngChoi, m, j);
}

void inLaBai(int x)
{
    inDiem(x/4);
    inChat(x%4);
}

//ham kiem tra xem nguoi choi co tu quy hay khong
//neu co thi thong bao la tu quy gi, neu khong thi thong bao khong co tu quy
void inTuQuy(int ngChoi[][MAXN], int m, int j)
{
    int tuQuy[MAXM], diem;
    bool coTuQuy = false;
    //
    for(int i=0; i<m; i++) tuQuy[i] = 0;
    for(int i=0; i<m; i++)
    {
        diem = ngChoi[i][j] / 4;
        tuQuy[diem]++;
        if (tuQuy[diem] == 4)
        {
            printf("Co tu quy ");
            inDiem(diem);
            printf("\n");
            coTuQuy = true;
        }
    }
    if (!coTuQuy) printf("Khong co tu quy!\n");
}

//in diem so tren la bai
void inDiem(int diem)
{
    switch (diem)
    {
        case 0:
            printf("A");
            break;
        case 10:
            printf("J");
            break;
        case 11:
            printf("Q");
            break;
        case 12:
             printf("K");
            break;
        default:
            printf("%d",diem+1);
    }
}

//in chat cua la bai
void inChat(int chat)
{
    switch (chat)
    {
        case 0:
             printf("co");
            break;
        case 1:
             printf("ro");
            break;
        case 2:
             printf("bich");
            break;
        case 3:
             printf("tep");
            break;
    }
}
