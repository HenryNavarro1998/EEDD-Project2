/****************************************************
* Jorge Caraballo                            		*
* V-30.366.057                                   	*
* ESTRUCTURA DE DATOS                               *
* SECCIÓN 01                                        *
* PRACTICA #2, 'Listas, Pilas y Colas'.				*
*****************************************************/

//Librerias Incluidas
#include <iostream>
#include <cstdlib>
#include "list/list.hpp"

using namespace std;

struct Point
{
    int x;
    int y;

    Point(const int x, const int y):
        x(x), y(y) {};
};

ostream& operator<<(ostream& stream, const Point& p)
{
    stream << "(" << p.x << "," << p.y << ")";
    return stream;
}

inline bool operator==(const Point& p1, const Point& p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}


//Funcion Main
int main()
{

    list<Point> l;

    l.push_back(Point(1,2));
    l.push_back(Point(1,5));
    l.push_back(Point(3,2));
    l.push_back(Point(-1,2));
    l.push_back(Point(-1,-2));
    l.push_back(Point(10,26));

    cout << l.find(Point(-1,-2)) << endl;

    return 0;
}
