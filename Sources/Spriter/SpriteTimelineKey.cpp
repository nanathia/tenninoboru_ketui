#include "SpriteTimelineKey.h"
#include "ScmlObject.h"
#include "ScmlFunctions.h"
#include "SpatialInfo.h"
#include "File.h"
#include "Folder.h"
#include "SKPlayScene.h"
#include "MyTexture.h"

namespace spriter{

SpriteTimelineKey::SpriteTimelineKey( XMLElement* e ):
	SpatialTimelineKey( e ),
	pivot_x( 0 ),
	pivot_y( 1 ),
	useDefaultPivot( true ),
	folder( e->FirstChildElement()->IntAttribute( "folder" ) ),
	file( e->FirstChildElement()->IntAttribute( "file" ) )
{
	//if( e->FirstChildElement()->Attribute( "pivot_x" ) || e->FirstChildElement()->Attribute( "pivot_y" ) ){
	//	useDefaultPivot = 0;
	//}
	//if( !useDefaultPivot ){
		if( e->FirstChildElement()->Attribute( "pivot_x" ) ){
			pivot_x = e->FirstChildElement()->DoubleAttribute( "pivot_x" );
		}
		if( e->FirstChildElement()->Attribute( "pivot_y" ) ){
			pivot_y = e->FirstChildElement()->DoubleAttribute( "pivot_y" );
		}
	//}
}


SpriteTimelineKey::~SpriteTimelineKey(void)
{
}


void SpriteTimelineKey::paint(const GMVector3D& pos, const double scale, const GMVector3D& rota) const{
	int paintPivotX;
	int paintPivotY;
	MyTexture* tex;
	if( useDefaultPivot ){
		//ここで、画像のファイル情報が必要となる。つまり、大元のポインタが必要となる。
		//これをどう持ってくるか。
		paintPivotX = ScmlFunctions::nowScmlFile->folders[ folder ]->files[ file ]->pivotX;
		paintPivotY = ScmlFunctions::nowScmlFile->folders[ folder ]->files[ file ]->pivotY;
	}else{
		paintPivotX = pivot_x;
		paintPivotY = pivot_y;
	}

	tex = ScmlFunctions::nowScmlFile->folders[ folder ]->files[ file ]->tex;

	tex->draw( &this->info, pivot_x, pivot_y, pos, scale, rota);
    
//    if( file == ScmlFunctions::nowScmlFile->folders[ folder ]->files.size()-1 ){
//        gPlayScene->getCurrentEffect()->setTexture(spriter::ScmlFunctions::nowScmlFile->folders[0]->files[7]->tex->m_tex);
//        
//        GMDraw::Begin();
//        GMDraw::FillQuad(GMVector3D(200, 200, 100), GMVector3D(600, 200, 100),
//                         GMVector3D(600, 400, 100), GMVector3D(200, 400, 100),
//                         GMVector3D(0, 0, 1), GMVector3D(0, 0, 1), GMVector3D(0, 0, 1), GMVector3D(0, 0, 1),
//                         GMVector2D(0, 0), GMVector2D(1, 0), GMVector2D(1, 1), GMVector2D(0, 1));
//        GMDraw::End();
//    }
}

TimelineKey* SpriteTimelineKey::linear( TimelineKey* KeyB, double currentTime ){
	SpriteTimelineKey* returnKey = new SpriteTimelineKey( *this );
	SpriteTimelineKey* castedKeyB = dynamic_cast< SpriteTimelineKey* >( KeyB );
	returnKey->info = ScmlFunctions::linear( this->info, castedKeyB->info, this->info.spin, currentTime );

	if( !useDefaultPivot ){
		returnKey->pivot_x = ScmlFunctions::linear( pivot_x, castedKeyB->pivot_x, currentTime );
		returnKey->pivot_y = ScmlFunctions::linear( pivot_y, castedKeyB->pivot_y, currentTime );
	}

	return returnKey;
}
    
}