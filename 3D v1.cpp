struct point3
{
  double x,y,z;
  point3(){};point3(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
  point3 operator+(point3 p){return point3(x+p.x,y+p.y,z+p.z);}
  point3 operator-(point3 p){return point3(x-p.x,y-p.y,z-p.z);}
  point3 operator*(double d){return point3(x*d,y*d,z*d);}
  point3 operator/(double d){return point3(x/d,y/d,z/d);}
  double value(){return sqrt(x*x+y*y+z*z);}
  double operator*(point3 p)
  {
    return x*p.x+y*p.y+z*p.z;//0 if vectors are perpendicular;
  }
  point3 unitVector()
  {
    //invalid if vector is (0,0)
    double v=value();return point3(x/v,y/v,z/v);
  }
};
