#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
int n = 4;

int fn = n;
int f1 = 1;
int f2 = 0;

for(int i = 2; i<= n; i++){

    fn = f2 + f1;

    f2 = f1;
    f1 = fn;

}
    
    printf("%d\n", fn);
    return 0;
}
