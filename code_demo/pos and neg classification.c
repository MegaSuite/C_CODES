#include<stdio.h>
int main(){
    int k = 1;
    int x;
    int pos = 0;
    int neg = 0;

    while(k<=10){
        printf("please input 第 %d 个 number:\n",k);
        scanf("%d",&x);
        if (x!=0){
            if(x>0) pos ++;
            else if(x<0) neg ++;
        }
        k++;
        printf("pos = %d\n",pos);
        printf("neg = %d\n",neg);
    
    }
    return 0;
}