using namespace std;
#include "bits/stdc++.h"
#define elif else if
#define all(Z) (Z).begin(), (Z).end()
#define len(x) (int)(x).size()
#define ceil(x,y) (x + y-1)/y
void IO(string Bessie);

#define int long long

int32_t main() {
    IO("baubles");//baubles

    int R, B, s , r, b;
    cin>>R >> B >> s >> r >> b;

    // if(R == 8 and B == 4 and s==3 and r==7 and b==1 ) {
        // cout <<5 << '\n';
        // return 0;
    // }
    int cnt{};
    
    if(s==0) {

        int rr = max( (R-r)+1, 0LL);
        int bb = max((B-b)+1, 0LL);

        if(not r) rr = 5e9+7;
        elif(not b) bb = 5e9+7;

        cnt += min(rr, bb);
        cout << cnt << '\n';
        return 0;
    }

    if(not r) {
        cnt = max(((B+s) - b)+1, 0LL);
        cout << cnt << '\n';
        return 0;
    }
    
    elif(not b) {
        cnt = max(((R+s) - r)+1, 0LL);
        cout << cnt << '\n';            
        return 0;
    }
    
    else {
        // if(R>=r and B>=b) {
        //     int red_remove = (R-r)+1;
        //     int blue_remove = (B-b)+1;
        //     if(red_remove>=blue_remove) {
        //         B -= blue_remove;
        //         cnt += blue_remove;
        //         cnt += s;
        //     }
        //     else {
        //         R -= red_remove;
        //         cnt += red_remove;
        //         cnt += s;
        //     }
        // }
        
        if(R >= r and B >= b) {

            int rr = (R-r);
            int bb = (B-b);
            if(bb > rr) {swap (rr,bb);}

            //bb always <= rr

            cnt += (bb+s+1);

        }
        
        elif(R < r and B < b) {//smol = want

            int rr = r-R;
            int bb = b - B;

            cnt += max(0LL, ((s+1) - (rr+bb)) );
        }

        else if((R<r and B>=b) or (B < b and R >= r) ) {//number of r want is low 

            if(R>=r and B<b) {
                swap(r,b);
                swap(R,B);
            }

            if(R+s >= r) {
                cnt += (R+s) - (r-1);
            }
        }
    }
    // elif (B < b and R >= r) {
    //     if(not (B+s <= r-1)) {
    //         cnt += (B+s) - (b-1);
    //     }
    // }


    cout << cnt;
    cerr << "\nTime Elapsed: [" << 1e3*clock()/CLOCKS_PER_SEC << " ms]\n";
}

void IO(string Bessie = "") { 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if (len(Bessie)) {
        freopen((Bessie+"in.txt").c_str(), "r", stdin);
        freopen((Bessie+"out.txt").c_str(), "w", stdout);
     }
}
// taskkill /IM "A.exe" /F
