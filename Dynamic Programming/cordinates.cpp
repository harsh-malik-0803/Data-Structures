// Question : 
/*A point on the two-dimensional plane can be represented by two numbers: an X coordinate and Y coordinate. For example, (4,5) represents a point
 4 units to the right of the origin along the X axis, and 5 units up the Y axis. The sum of two points can be defined as a new point whose X 
 coordinate is the sum of the X coordinates of the two points, and whose Y coordinate is the sum of their Y coordinates.
Write a program that uses a structure called point to model a point. Define three points, and have the user input values to two of them.
 Then set the third point equal to the sum of the other two, and display the value of the new point.*/
#include<iostream>
using namespace std;

// class to define cordinates as x,y are of same point (x,y) 
class point_to_model_point{
    public:
    int x; // x cordinate
    int y; // y cordinate
};

int main(){

    // creating object p1,p2,p3
    point_to_model_point p1;
    point_to_model_point p2;
    point_to_model_point p3;

    // taking coordinates as input
    cout<<"Enter the X coordinate of point P1 : ";
    cin>>p1.x;
    cout<<"Enter the Y coordinate of point P1 : ";
    cin>>p1.y;
    cout<<"Enter the X coordinate of point P2 : ";
    cin>>p2.x;
    cout<<"Enter the Y coordinate of point P2 : ";
    cin>>p2.y;
    
    // representing your entered cordinates 
    cout<<"cordinates of point P1 is : ("<<p1.x<<","<<p1.y<<")"<<endl;
    cout<<"cordinates of point P2 is : ("<<p2.x<<","<<p2.y<<")"<<endl;

    // As p3 represent resultant cordinates 
    // so x cordinate of p3 = x(p1)+x(p2) 
    // so y cordinate of p3 = y(p1)+y(p2)
    cout<<"cordinates of P3 are : ("<<p2.x+p1.x<<","<<p2.y+p1.y<<")"<<endl;
    return 0;
}