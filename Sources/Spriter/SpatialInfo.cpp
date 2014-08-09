#include "SpatialInfo.h"
#include "Math2.h"

namespace spriter{

SpatialInfo::SpatialInfo( XMLElement* e ):
	x( 0 ),
	y( 0 ),
	angle( 0 ),
	scaleX( 1 ),
	scaleY( 1 ),
	a( 1 ),
	spin( 1 )
{
	if( e->Attribute( "x" ) ){
		x = e->DoubleAttribute( "x" );
	}
	if( e->Attribute( "y" ) ){
		y = e->DoubleAttribute( "y" );
	}
	if( e->Attribute( "angle" ) ){
		angle = e->DoubleAttribute( "angle" );
	}
	if( e->Attribute( "scale_x" ) ){
		scaleX = e->DoubleAttribute( "scale_x" );
	}
	if( e->Attribute( "scale_y" ) ){
		scaleY = e->DoubleAttribute( "scale_y" );
	}
	if( e->Attribute( "a" ) ){
		a = e->IntAttribute( "a" );
	}
	if( e->Attribute( "spin" ) ){
		spin = e->IntAttribute( "spin" );
	}
}

SpatialInfo::SpatialInfo():
	x( 0 ),
	y( 0 ),
	angle( 0 ),
	scaleX( 1 ),
	scaleY( 1 ),
	a( 1 ),
	spin( 1 )
{
}


SpatialInfo::~SpatialInfo(void)
{
}


SpatialInfo SpatialInfo::unmapFromParent( const SpatialInfo& parentInfo ) const{

	SpatialInfo unmappedObj = *this;
	unmappedObj.angle += parentInfo.angle;
	unmappedObj.scaleX *= parentInfo.scaleX;
	unmappedObj.scaleY *= parentInfo.scaleY;
	unmappedObj.a *= parentInfo.a;

	if( x || y ){
		double preMultX = x * parentInfo.scaleX;
		double preMultY = y * parentInfo.scaleY;
		double s = GameLib::sin( parentInfo.angle );
		double c = GameLib::cos( parentInfo.angle );
		unmappedObj.x = ( preMultX * c ) - ( preMultY * s );
		unmappedObj.y = ( preMultX * s ) + ( preMultY * c );
		unmappedObj.x += parentInfo.x;
		unmappedObj.y += parentInfo.y;
	}else{
		unmappedObj.x = parentInfo.x;
		unmappedObj.y = parentInfo.y;
	}

	return unmappedObj;
}

}