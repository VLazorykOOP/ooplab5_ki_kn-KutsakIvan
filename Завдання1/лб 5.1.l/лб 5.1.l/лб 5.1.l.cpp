#include <iostream>
#include <Windows.h>

using namespace std;

class point
{
	float x, y;
public:
	point() { x = 0; y = 0; }
	point(float X, float Y);
	~point()
	{
		cout << "\npoint dtor\n";
	}
	void input_point();
	void print_point();
	void set_xy(float X, float Y) { x = X; y = Y; }
	void set_x(float X) { x = X; }
	void set_y(float Y) { y = Y; }
	float get_x() { return x; }
	float get_y() { return y; }
};

point::point(float X, float Y)
{
	x = X;
	y = Y;
}

void point::input_point()
{
	cout << "Bведіть х: "; cin >> x;
	cout << "Bведіть y: "; cin >> y;
}

void point::print_point()
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

class ellipse : private point 
{
	float a, b;
public:
	ellipse():point() { a = 2; b = 1; }
	ellipse(float A, float B, float X, float Y): point(X,Y) { a = A; b = B; }
	~ellipse() { cout << "\nellipse dtor\n"; }
	void input_ellipse();
	void print_ellipse();
	float S() { return 3.14 * a * b; }
	void set_ellipse(float A, float B, float X, float Y) { a = A; b = B; set_xy(X, Y); }
	void set_center(float X, float Y) { set_xy(X, Y); }
	void set_a(float A);
	void set_b(float B);
	float get_a() { return a; }
	float get_b() { return b; }
	float get_center_x() { return get_x(); }
	float get_center_y() { return get_y(); }
};

void ellipse::input_ellipse()
{
	int k = 0;
	cout << "Введіть велику піввісь еліпса: "; cin >> a;
	cout << "Введіть малу піввісь еліпса: "; cin >> b;
	while (k == 0) 
	{
		if (b < a)k = 1;
		else
		{
			cout << "Значення млої піввісі повинно бути меншим за велику піввісь\n";
			cout << "Введіть інше значення млої піввісі, менше за " << a << ": "; cin >> b;
		}
	}
	cout << "Введіть коордтнати центра еліпса\n";
	input_point();
}

void ellipse::print_ellipse()
{
	cout << "Координати центра еліпса: O(" << get_center_x() << ";" << get_center_y() << ")\n";
	cout << "Велика піввісь еліпса: " << a << endl;
	cout << "Мала піввісь еліпса: " << b << endl;
}

void ellipse::set_a(float A)
{
	int k = 0;
	a = A;
	while (k == 0)
	{
		if (a > b) k = 1;	
		else
		{
			cout << "Значення великої піввісі повинно бути більшим за малу піввісь\n";
			cout << "Введіть інше значення великої піввісі, більше за " << b << ": "; cin >> a;
		}
	}
}

void ellipse::set_b(float B)
{
	int k = 0;
	b = B;
	while (k == 0)
	{
		if (b < a) k = 1;
		else
		{
			cout << "Значення млої піввісі повинно бути меншим за велику піввісь\n";
			cout << "Введіть інше значення млої піввісі, менше за " << a << ": "; cin >> b;
		}
	}
}

class circle : private point
{
	float r;
public:
	circle() :point() { r = 1; }
	circle(float R, float X, float Y) : point(X, Y) { r = R; }
	~circle() { cout << "\ncircle dtor\n"; }
	void input_circle();
	void print_circle();
	float S() { return 3.14 * (r * r); }
	void set_circle(float R, float X, float Y) { r = R; set_xy(X, Y); }
	void set_center(float X, float Y) { set_xy(X, Y); }
	void set_r(float R);
	float get_r() { return r; }
	float get_center_x() { return get_x(); }
	float get_center_y() { return get_y(); }
};

void circle::input_circle()
{
	int k = 0;
	cout << "Введіть коордтнати цетнра кола\n";
	input_point();
	cout << "Введіть радіус кола: "; cin >> r;
	while (k == 0)
	{
		if (r > 0)k = 1;
		else
		{
			cout << "Радіус не може бути від'ємним. Введіть додатнє заначення радіуса: "; cin >> r;
		}
	}

}

void circle::print_circle()
{
	cout << "Координати центра кола: O(" << get_center_x() << ";" << get_center_y() << ")\n";
	cout << "Радіус: " << r << endl;
}

void circle::set_r(float R)
{
	int k = 0;
	r = R;
	while (k == 0)
	{
		if (r > 0)k = 1;
		else
		{
			cout << "\nРадіус не може бути від'ємним. Введіть додатнє заначення радіуса: "; cin >> r;
		}
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	point POINT1, POINT2(0,2);
	cout << "POINT1\n";
	POINT1.print_point();

	cout << "POINT2(0,2)\n";
	POINT2.print_point();

	cout << "Введіть координаи точки\n";
	POINT1.input_point();
	cout << "POINT1\n";
	POINT1.print_point();

	POINT1.set_xy(5, 6);
	cout << "POINT1.set_xy(5, 6)\n";
	POINT1.print_point();

	POINT1.set_x(4);
	cout << "POINT1.set_x(4)\n";
	POINT1.print_point();

	POINT1.set_y(-3);
	cout << "POINT1.set_y(-3)\n";
	cout << "x = " << POINT1.get_x() << endl;
	cout << "y = " << POINT1.get_y() << endl;

	//#####################################
	ellipse ELLIPSE1, ELLIPSE2(3, 1, 1, 1);
	cout << "\nELLIPSE1\n";
	ELLIPSE1.print_ellipse();

	cout << "\nELLIPSE2(3,1,1,1)\n";
	ELLIPSE2.print_ellipse();

	cout << "\nВведіть інформацію про еліпс\n";
	ELLIPSE1.input_ellipse();
	cout << "\nELLIPSE1\n";
	ELLIPSE1.print_ellipse();

	cout << "\nПлоща ELLIPS1: " << ELLIPSE1.S();

	ELLIPSE1.set_ellipse(8, 5, 0, 0);
	cout << "\nELLIPSE1.set_ellipse(8, 5, 0, 0)\n";
	ELLIPSE1.print_ellipse();

	ELLIPSE1.set_center(3, -1);
	cout << "\nELLIPSE1.set_center(3, -1)\n";
	ELLIPSE1.print_ellipse();

	cout << "\nELLIPSE1.set_a(3);\n";
	ELLIPSE1.set_a(3);
	ELLIPSE1.print_ellipse();

	cout << "\nELLIPSE1.set_b(9);\n";
	ELLIPSE1.set_b(9);
	cout << "Координати центра еліпса: O(" << ELLIPSE1.get_center_x() << ";" << ELLIPSE1.get_center_y() << ")\n";
	cout << "Велика піввісь еліпса: " << ELLIPSE1.get_a() << endl;
	cout << "Мала піввісь еліпса: " << ELLIPSE1.get_b() << endl;

	//#####################################
	circle CIRCLE1, CIRCLE2(3, 2,-3);
	cout << "\nCIRCLE1\n";
	CIRCLE1.print_circle();

	cout << "\nCIRCLE2(3, 2,-3)\n";
	CIRCLE2.print_circle();

	cout << "\nВведіть інформацію про коло\n";
	CIRCLE1.input_circle();
	cout << "\nCIRCLE1\n";
	CIRCLE1.print_circle();

	cout << "\nПлоща CIRCLE1: " << CIRCLE1.S();

	CIRCLE1.set_circle(8, 5, 0);
	cout << "\nCIRCLE1.set_circle(8, 5, 0)\n";
	CIRCLE1.print_circle();

	CIRCLE1.set_center(3, -1);
	cout << "\nCIRCLE1.set_center(3, -1);\n";
	CIRCLE1.print_circle();

	cout << "\nCIRCLE1.set_r(9);\n";
	CIRCLE1.set_r(9);
	cout << "Координати центра кола: O(" << CIRCLE1.get_center_x() << ";" << CIRCLE1.get_center_y() << ")\n";
	cout << "Радіус кола: " << CIRCLE1.get_r() << endl;
}