#pragma once
#include <vector>
#include <string>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

namespace spriter{
    
class SpatialInfo
{
public:
	SpatialInfo( XMLElement* e );
	SpatialInfo( void );
	~SpatialInfo(void);

	double x;
	double y;
	double angle;
	double scaleX;
	double scaleY;
	double a;
	int spin;


	//���ߕۗ���
	//���������B�e�q�֌W���\�����Ă�����C���X�^���X�Ƃ��ĕԂ��̂��B�I�[���R�s�[�ł������낤�B
	SpatialInfo unmapFromParent( const SpatialInfo& parentInfo ) const;
};

}