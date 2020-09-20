#include <math.h>
class quadratic{
    float a,b,c;
    float roots[2];
    public:
    quadratic(float a, float b, float c):a(a),b(b),c(c){}
    float* solve(){
        int disc = sqrt( (b*b) - (4*a*c) );
        roots[0] = ( (-b) + disc) / (2*a);
        roots[1] = ( (-b) - disc) / (2*a);
        return roots;
    }
    float* get_roots(){
        return roots;
    }
};