#pragma once

#include <string>
#include <vector>
#include "Karakuri.h"
using namespace std;

namespace spriter{

class SpatialInfo;

class MyTexture
{
public:
	MyTexture( const char* string );
	~MyTexture(void);
	void draw( double* p1, double* p2, double* p3, double* p4, unsigned color ) const;
	void draw( const SpatialInfo* info, double pivot_x, double pivot_y, const GMVector3D& pos, const double scale, const GMVector3D& rota );
	string name;
    
	double t1_x, t1_y;
	double t2_x, t2_y;
	double t3_x, t3_y;
	double t4_x, t4_y;
    
    static bool deleteFrag;
    
    GMTexture2D* m_tex;
};

}