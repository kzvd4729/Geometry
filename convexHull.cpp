/*
in a N*N grid a convexhull can have maximum N^(2/3) vertices of lattice point 
after omitting straight line point. for random input it is N^(1/3);
*/
struct point
{
  int x,y;
  point(){}point(int _x,int _y):x(_x), y(_y){}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  double operator^(point p){return x*p.y-y*p.x;}
};
point stck[N+2];int top=0;
void balance(void)
{
  while(top>=3)
  {
    //>=0 to omit straight line point;
    if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>=0)
      stck[top-1]=stck[top],top--;
    else break;
  }
}
//returns counter-clock-wise, a path, not closed circuit
vector<point>monotoneChain(vector<point>&v)
{
  sort(v.begin(),v.end());
  vector<point>hull;int n=v.size();
  for(int i=n-1;i>=0;i--)stck[++top]=v[i],balance();
  while(top>0)hull.push_back(stck[top--]);
  for(int i=0;i<n;i++)stck[++top]=v[i],balance();
  top--;
  while(top>0)hull.push_back(stck[top--]);
  if(hull.size()>1)hull.pop_back();
  return hull;
}
