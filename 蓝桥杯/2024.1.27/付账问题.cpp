//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <iomanip>
//using namespace std;
//const int N = 5e5 + 10;
//int a[N];
//int main() {
//    long long n;
//    double S;
//    cin >> n >> S;
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    sort(a, a + n);
//    double average = 1.0 * S / n;
//    double ans = 0;
//    for (int i = 0; i < n; i++) {
//        if (a[i] * (n - i) < S) {
//            ans += (average - a[i]) * (average - a[i]);
//            S -= a[i];
//        }
//        else {
//            double current = 1.0 * S / (n - i);
//            ans += (current - average) * (current - average) * (n - i);
//            break;
//        }
//    }
//    cout << setprecision(4) << fixed << sqrt(ans / n) << endl;
//    return 0;
//}