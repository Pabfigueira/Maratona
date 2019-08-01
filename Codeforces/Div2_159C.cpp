#include<bits/stdc++.h>

using namespace std;

double PI = acos(-1);

double getAngle(pair<double,double> one, pair<double,double> two) {

    double n1 = sqrt(one.first*one.first+one.second*one.second);
    double n2 = sqrt(two.first*two.first+two.second*two.second);
    return acos((one.first*two.first+one.second*two.second)/(n1*n2)) * 180 / PI;
}

int main() {
    int n, i;
    double ans, x, y;
    scanf("%d",&n);
    vector<double> angles(n);
    for(i=0; i<n; i++) {
        scanf("%lf%lf",&x,&y);
        angles[i] = atan2(x,y) * 180 / PI;
    }
    sort(angles.begin(), angles.end());
 
    ans = 0;
    for(i=1; i<n; i++) {
        ans = max(ans, angles[i]-angles[i-1]);    
    }
    ans = max(ans,(360+angles[0])-angles[n-1]);
    printf("%.7lf\n",360-ans);
    return 0;
}
