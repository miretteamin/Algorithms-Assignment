#include <iostream>
#include <set>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include<cmath>
typedef long long ll;
using namespace std;

int main()
{
    ll n;
    cout << "Enter the number of points: ";
    cin >> n ;
    double h;
    set<tuple<ll,ll,ll>> tuples;
    cout << "Input x then y values " <<endl;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin >> x>> y;

        tuples.insert(make_tuple(x,y,i));

    }
    auto it1 = tuples.begin();
    auto it2 = tuples.begin();
    it2++;
    ll a = 0;
    ll b = 1;
    h = sqrt( ( get<0>(*it1) -  get<0>(*it2)) * ( get<0>(*it1) -  get<0>(*it2))  + ( get<1>(*it1) -  get<1>(*it2))* ( get<1>(*it1) -  get<1>(*it2)) );

    auto it = tuples.begin();

    while(it != tuples.end()){
        auto upperb = tuples.upper_bound(make_tuple( get<0>(*it) + (ll)(h),0,0));

        auto lowerb = tuples.upper_bound(make_tuple( get<0>(*it) - (ll)(h),0,0));
        if (lowerb == tuples.end()) lowerb--;

        while (true){
            if (lowerb == upperb) break;
            if (lowerb == it){
                lowerb++;
                continue;
            };
            double candidateH = sqrt( ( get<0>(*it) -  get<0>(*lowerb)) * ( get<0>(*it) -  get<0>(*lowerb))  + ( get<1>(*it) -  get<1>(*lowerb))* ( get<1>(*it) -  get<1>(*lowerb)) );
            if (candidateH < h) {
                h = candidateH;
                ll index1 = get<2>(*it);
                ll index2 = get<2>(*lowerb);
                if (index1 > index2) {
                    a= index2 ;
                    b = index1;
                }else{
                    a = index1 ;
                    b = index2;
                }
            }

            lowerb++;

        }
        it++;

    }

    cout <<   h <<endl;




    return 0;
}
