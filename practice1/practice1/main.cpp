#include <iostream>
#include <math.h>
using namespace std;

/*факториал
int main()
{
    int n, res = 1;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        res *= i;
    }

    cout << res;
    return 0;
}
*/

/*кв уравн, дописать d < 0
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int d = b*b - 4*a*c;

    int x1, x2;

    if (d == 0) {
        int x = -b/(2*a);
        cout << x;
        return 0;
    }

    x1 = (-b + sqrt(d))/(2*a);
    x2 = (-b - sqrt(d))/(2*a);



    cout << x1 << " " << x2;

    return 0;
}*/

/*prostye
int main() {
    int f = 0;
    for (int i = 2; i < 100; i++) {
        for (int j = 2; j < i; j++) {
            if (i%j == 0) {
                f = 1;
                break;
            }
        }
        if (f == 1) {
            f = 0;
            continue;
        }
        cout << i << "\n";
    }
    return 0;
}
*/

/*bin
void bin(int n) {
    if (n > 1) {
        bin(n/2);
    }
    cout<<n%2;
    return 0;
}
int main() {
    int n;
    cin >> n;
    bin(n);
    return 0;
}
*/

/*prog
int main() {
    int a, e;
    float q;
    cin >> a >> q >> e;

    float res = 0;
    for (int i = 0; i < e; i++) {
        res += a*pow(q, 2*i);
    }

    cout << res;

    return 0;
}
*/

int main() {
    char ch;
    cin >> ch;

    int int_ch = (int)ch;

    if ((65 <= int_ch && int_ch <= 90) || (97 <= int_ch && int_ch <= 122)) {
        cout << "True";
        return 0;
    }

    cout << "False";

    return 0;
}