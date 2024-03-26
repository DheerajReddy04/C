#include <stdio.h>
void main(){
    int n, i, flag = 0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i+1]>a[i]){
            continue;
        }
        else if(a[i+1] <a[i]){
            for(i = i; i<n;i++){
                if(a[i+1]<a[i]) {
                    continue;
                }
                else if(a[i+1]<a[i]){
                    printf("No");
                    flag += 1;
                    break;
                }
            }
        }
        if(flag == 1){
            break;
        }
    }
    if(flag == 0){
        printf("Yes");
    }
}