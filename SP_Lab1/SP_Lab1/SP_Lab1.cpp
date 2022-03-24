#include <iostream>
#include <string>
using namespace std;

bool implication(bool, bool);
void binary(bool*, bool*, bool*, bool*, bool*, bool*, bool*, const int);
void draw(bool*, bool*, bool*, bool*, bool*, bool*, bool*, const int);

int main()
{
	const int n = 8;
	bool p[n] = { 1,1,0,0,1,1,0,0 }; bool* pp = p;
	bool q[n] = { 1,0,1,0,1,0,1,1 }; bool* qq = q;
	bool p1q[n]; bool* p11q = p1q;
	bool p2q[n]; bool* p22q = p2q;
	bool p3q[n]; bool* p33q = p3q;
	bool p4q[n]; bool* p44q = p4q;
	bool p5q[n]; bool* p55q = p5q;
	cout << "Do you want to enter your own values?(y/n): ";
	char y = ' '; cin >> y;
	if (y == 'y')
	{
		for (int i = 0; i < n; i++)
		{
			cout << "p" << i << " = "; cin >> p[i];
			cout << "q" << i << " = "; cin >> q[i];
		}
	}

	binary(pp, qq, p11q, p22q, p33q, p44q, p55q, n);
	draw(pp, qq, p11q, p22q, p33q, p44q, p55q, n);
}

void draw(bool* p, bool* q, bool* p1q, bool* p2q, bool* p3q, bool* p4q, bool* p5q, const int n)
{
	cout << "---------------------------------------------------------------------\n";
	cout << "|  p  |  q  |  p ^ q  |  p || q  |  p (+) q  |  p -> q  |  p <-> q  |\n";
	cout << "---------------------------------------------------------------------\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|  " << p[i] << "  " << "|  " << q[i] << "  " << "|    " << p1q[i] << "    " << "|    "  << p2q[i] << "     " << "|     " << p3q[i] << "     " << "|    " << p4q[i] << "     |     " << p5q[i] << "     |" << '\n';
	}
	cout << "---------------------------------------------------------------------\n";
}

void binary(bool* p, bool* q, bool* p1q, bool* p2q, bool* p3q, bool* p4q, bool* p5q, const int n)
{
	for (int i = 0; i < n; i++)
	{
		p1q[i] = *(p + i) && *(q + i); //  AND	Conunction
	}
	for (int i = 0; i < n; i++)
	{
		p2q[i] = *(p + i) || *(q + i); //  OR	Disunction
	}
	for (int i = 0; i < n; i++)        
	{
		p3q[i] = *(p + i) ^ *(q + i);  //  XOR  Alternative OR
	}
	for (int i = 0; i < n; i++)
	{
		p4q[i] = implication(*(p + i), *(q + i));  //  Implication 
	}
	for (int i = 0; i < n; i++) 
	{
		p5q[i] = !(*(p + i) ^ *(q + i));  //  Equivalence
	}
}

bool implication(bool a, bool b)
{
	bool resp;
	if (a == 1 && b == 0) 
		resp = 0;
	else { resp = 1; }
	return resp;
}