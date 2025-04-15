#include<bits/stdc++.h>
using namespace std;
#define int long long

double area1(double a, double b, double c){
    double s = (a+b+c)/2.0;
    double x = (s-a);
    double y = (s-b);
    double z = (s-c);
    double temp = s*x*y*z;

    return sqrt(temp);
}

double calc(double x, double ab, double abc){
    double k = x / ab; 
    return abc * k * k; 
}

int ok(double x, double ab, double ratio, double abc){
    
    double newArea = calc(x, ab, abc);
    double current_ratio = newArea / (abc - newArea);
    return current_ratio <= ratio;
}

signed main(){
    int count = 1;
    int t;cin>>t;
    while(t--){
        double ab,ac,bc,ratio;
        cin>>ab>>ac>>bc>>ratio;

        double abc = area1(ab,ac,bc);

        double l = 0, r = ab;
        double x;
        for(int i = 0; i < 100; i++){
            x = l+(r-l)/2;
            if(ok(x, ab, ratio, abc)){
                l = x;
            }else{
                r = x;
            }
        }
        cout<<setprecision(20)<<"Case "<<count<<": "<<l<<endl;
        
        count++;
    }

    

    return 0;
}