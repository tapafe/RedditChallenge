#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    long long result = 0;
    result = div2(-10, 2);
    printf("%d\n", result);
}

int add2(a, b) {
    return a + b;
}

int mult2(a,b){
    if (a > 0 && b < 0){
        return mult2(b,a);
    }else if(a < 0 && b < 0){
        return mult2(sub2(0, a), sub2(0, b));
    }
    int res = 0;
    int i;
    for(i=0; i<b; i++){
        res = res + a;
    }
    return res;
}

int sub2(a,b){
    int c = UINT_MAX;
    while(c+b != 0){
        c++;
    }
    return a + c;
}

int div2(a,b){

    if (b == 0){
        return -1;
    }else if (a == 0){
        return 0;
    }

    if (a < 0 && b > 0) {
            // if a negative
            // return - (a/b)
        return sub2(0, div2(sub2(0, a),b));
    } else if (a > 0 && b < 0) {
        //return sub2(0, div2(a, sub2(0,b));
    } else if (a < 0 && b < 0) {
        return sub2(0, div2(sub2(0, a),sub2(0,b)));
    }

    short n = 0;
    while(1){
        a = sub2(a, b);

        if (a == 0){
            return n+1;
        } else if (a < 0){
            return -1;
        }
        n++;
    }
}

int expon(a, b) {
    short res = 1;
    int i;
    for (i=0; i < b; i++) {
        res = mult2(res, a);
    }
    return res;
}
