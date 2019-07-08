#include<bits/stdc++.h>

using namespace std;

int main() {
    pair<int,int> next;
    int o, d, k, num, res, i;
    while(true) {
        scanf("%d%d%d",&o,&d,&k);
        if(o==0 and d==0 and k==0) break;
        vector<int> forbidden(500000,0);
        for(i=0; i<k; i++) {
            scanf("%d",&num);
            forbidden[num] = 1;
        }
        res = -1;
        queue<pair<int,int>> myQueue;
        myQueue.push(make_pair(o,0));
        forbidden[0] = 1; 
        while(!myQueue.empty()) {
            next = myQueue.front();
            myQueue.pop();
            if(next.first==d) {
                res = next.second;
                break;
            }
            if(next.first-1>=0 and forbidden[next.first-1]==0) {
                forbidden[next.first-1] = 1;
                myQueue.push(make_pair(next.first-1,next.second+1));
            } 
            if(next.first+1<=100000 and forbidden[next.first+1]==0) {
                forbidden[next.first-+1] = 1;
                myQueue.push(make_pair(next.first+1,next.second+1));
            }
            if(next.first%2==0 and forbidden[next.first/2]==0) {
                forbidden[next.first/2] = 1;
                myQueue.push(make_pair(next.first/2,next.second+1));
            }
            if(next.first*2<=100000 and forbidden[next.first*2]==0) {
                forbidden[next.first*2] = 1;
                myQueue.push(make_pair(next.first*2,next.second+1));
            }
            if(next.first*3<=100000 and forbidden[next.first*3]==0) {
                forbidden[next.first*3] = 1;
                myQueue.push(make_pair(next.first*3,next.second+1));
            }
            
        }
        printf("%d\n",res);
    }
    return 0;
}
