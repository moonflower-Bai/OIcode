#include <bits/stdc++.h>
using namespace std;
class Rational
{
public:
	int a, b; // a is up, b is down
	Rational operator+(const Rational &x) const
	{
		Rational ans;
		ans.a = a * x.b + b * x.a;
		ans.b = b * x.b;
		int g = __gcd(ans.a, ans.b);
		ans.a /= g;
		ans.b /= g;
		return ans;
	}
	Rational operator-(const Rational &x) const
	{
		Rational ans;
		ans.a = a * x.b - b * x.a;
		ans.b = b * x.b;
		int g = __gcd(ans.a, ans.b);
		ans.a /= g;
		ans.b /= g;
		return ans;
	}
	friend Rational operator*(const Rational &x, const Rational &y)
	{
		Rational ans;
		ans.a = x.a * y.a;
		ans.b = x.b * y.b;
		int g = __gcd(ans.a, ans.b);
		ans.a /= g;
		ans.b /= g;
		return ans;
	}
	friend Rational operator/(const Rational &x, const Rational &y)
	{
		Rational ans;
		ans.a = x.a * y.b;
		ans.b = x.b * y.a;
		int g = __gcd(ans.a, ans.b);
		ans.a /= g;
		ans.b /= g;
		return ans;
	}
	Rational operator=(const Rational &x)
	{
		a = x.a;
		b = x.b;
		return *this;
	}
	Rational operator=(int x)
	{
		a = x;
		b = 1;
		return *this;
	}
	Rational operator++(int) // 后置++
	{
		Rational ans;
		ans.a = a;
		ans.b = b;
		a += b;
		return ans;
	}
	Rational operator++() // 前置++
	{
		a += b;
		return *this;
	}

	friend ostream& operator<<(ostream &out, const Rational &x)
	{
		if (x.b == 1)
		{
			out << x.a;
		}
		else
		{
			out << x.a << "/" << x.b;
		}
		return out;
	}
public:
	Rational(int x, int y): a(x), b(y) {}
	Rational(int x): a(x), b(1) {}
	Rational() : a(0), b(1) {}
};
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	Rational r1(a, b), r2(c, d);
	cout << (r1 + r2) << endl;
	cout << (r1 - r2) << endl;
	cout << (r1 * r2) << endl;
	cout << (r1 / r2) << endl;
	cout << (r1++) << ' ' << (r2++) << endl;
	cout << (r1 = Rational(r1.b, r1.a)) << ' ' << (r2 = Rational(r2.b, r2.a)) << endl;
	return 0;
}