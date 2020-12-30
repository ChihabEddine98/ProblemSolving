/* Description :  This document solves the k-nearst points to the origin */
/*----------------------------------------------------------------------*/
/*  Problem :  
             input  : ([(x,y)],k) list of points in 2D plan and an integer k
             output : [(x,y)] a list of size k for the nearest to origin 
*/
/*
    Test : g++ -o main.exe .\k_nearst_naive.cpp
*/
/*----------------------------------------------------------------------*/
#include<iostream>
#include<algorithm>
using namespace std;


class Point{
   private:
   int x, y;
   public:
   Point(int x = 0, int y = 0){
      this->x = x;
      this->y = y;
   }
   void display(){
      cout << "("<<x<<", "<<y<<")";
   }
   friend bool comparePoints(Point &p1, Point &p2);
};
/* NB : no need to calculate all sqrt(...) because we are not interested to the distance*/
bool comparePoints(Point &p1, Point &p2){
   float dist1 = (p1.x * p1.x) + (p1.y * p1.y);
   float dist2 = (p2.x * p2.x) + (p2.y * p2.y);
   return dist1 < dist2;
}
void kNearestPoints(Point points[], int n, int k){
   sort(points, points+n, comparePoints);
   for(int i = 0; i<k; i++){
      points[i].display();
      cout << endl;
   }
}
int main() {
   Point points[] = {{3, 3},{5, -1},{-2, 4},{6,6},{1,0},{-1,0}};
   int n = sizeof(points)/sizeof(points[0]);
   int k = 2;
   kNearestPoints(points, n, k);
}