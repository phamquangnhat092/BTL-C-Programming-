#include<stdio.h>
#include<math.h>
int gt(int a) //ham giai thua
{ int giaithua=1;
  for(int i=1;i<=a;i++){
    giaithua=giaithua*i;
  }
  return giaithua;
}
int main()
{
    int n,k;
    printf("Nhap n,k:\n");
    scanf("%d %d",&n,&k);
    if(n>=k){
    int tohop =(gt(n))/((gt(k))*(gt(n-k)));
    printf("%d",tohop);
    }
    else printf("So nhap vao khong hop le!\n");
    return 0;
}
