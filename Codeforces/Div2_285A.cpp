#include <bits/stdc++.h>

using namespace std;

int main() {

    double a, b, c, d, misha, vasya;

    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);

    misha = max( (3*a)/10., a-(a/250.)*c);
    vasya = max( (3*b)/10., b-(b/250.)*d);

    if( misha==vasya ) printf("Tie\n");
    else if( misha > vasya ) printf("Misha\n");
    else printf("Vasya\n");
    return 0;
}
