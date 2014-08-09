#include "Animation.h"
#include "BoneTimelineKey.h"
#include "SpriteTimelineKey.h"
#include "MainlineKey.h"
#include "Timeline.h"
#include "TimelineKey.h"
#include "SpatialTimelineKey.h"
#include "Ref.h"
#include "SKPlayScene.h"
#include "Globals.h"
#include "spriterFiles.h"

namespace spriter{

Animation::Animation( XMLElement* e ):
	loopType( LOOPING )
{
	name = e->Attribute( "name" );
	length = e->IntAttribute( "length" );
	XMLElement* c = e->FirstChildElement();
	while( true ){
		if( !c ){
			break;
		}
		string str = c->Name();
		if( str == "mainline" ){
			XMLElement* c2 = c->FirstChildElement( "key" );
			while( true ){
				if( !c2 ){
					break;
				}
				mainlineKeys.push_back( new MainlineKey( c2 ) );
				c2 = c2->NextSiblingElement();
			}
		}else if( str == "timeline" ){
			timelines.push_back( new Timeline( c ) );
		}
		c = c->NextSiblingElement();

	}
}


Animation::~Animation(void)
{
	int size = (int)timelines.size();
	for( int i = 0; i < size; i++ ){
        delete timelines[ i ];
        timelines[ i ] = 0;
	}
	size = (int)mainlineKeys.size();
	for( int i = 0; i < size; i++ ){
		delete mainlineKeys[ i ];
        mainlineKeys[ i ] = 0;
	}
}


void Animation::setCurrentTime( double newTime, const GMVector3D& pos, double scale, const GMVector3D& rota){
    if( loopType == NO_LOOPING ){
		newTime = min( newTime, static_cast< double >( length ) );
	}else if( loopType == LOOPING ){
		newTime = static_cast< double >( static_cast< int >( newTime )  );
	}

	int currentTime = static_cast< int >( newTime );

	updateCharacter( *mainlineKeyFromTime( currentTime ), currentTime, pos, scale, rota );
}


void Animation::updateCharacter( const MainlineKey& mainKey, int newTime, const GMVector3D& pos, const double scale, const GMVector3D& rota ){
    
	vector< BoneTimelineKey* > transformedBoneKeys;
	int size = (int)mainKey.boneRefs.size();
	for( int b = 0; b < size; b++ ){
		SpatialInfo parentInfo;
		Ref currentRef = *mainKey.boneRefs[ b ];
		if( currentRef.parent >= 0 ){
			parentInfo = transformedBoneKeys[ currentRef.parent ]->info;
		}else{
			//parentInfoÇÃêeÇÕ0ÇÃà íuÅAÇ¬Ç‹ÇËèâä˙ílÇ≈ÇªÇÃÇ‹Ç‹ï˙ÇËçûÇﬂÇŒÇ¢Ç¢ÇÕÇ∏ÇæÅB
		}
		TimelineKey* currentKey = keyFromRef( currentRef, newTime );
		currentKey->setInfo( currentKey->getInfo().unmapFromParent( parentInfo ) );
		transformedBoneKeys.push_back( dynamic_cast< BoneTimelineKey* >( currentKey ) );
	}

	vector< TimelineKey* > objectKeys;
	size = (int)mainKey.objectRefs.size();
	for( int o = 0; o < size; o++ ){
		SpatialInfo parentInfo;
		Ref* currentRef = mainKey.objectRefs[ o ];

		if( currentRef->parent >= 0 ){
			parentInfo = transformedBoneKeys[ currentRef->parent ]->info;
		}else{
		}

		TimelineKey* currentKey = keyFromRef( *currentRef, newTime );
		currentKey->setInfo( currentKey->getInfo().unmapFromParent( parentInfo ) );
		objectKeys.push_back( currentKey );
	}

	size = (int)objectKeys.size();
    
//    GMGraphics::CurrentGraphics->enablePointSprite(true);
//    GMDraw::Begin();
    // 描画
	for( int k = 0; k < size; k++ ){
		objectKeys[ k ]->paint(pos, scale, rota);
	}
    
//    GMDraw::End();
    ScmlFunctions::m_sortNum = 0;
    // 抽出情報の削除
	for( int i = 0; i < size; i++ ){
        delete objectKeys[ i ];
        objectKeys[ i ] = 0;
	}
	size = (int)transformedBoneKeys.size();
	for( int i = 0; i < size; i++ ){
        delete transformedBoneKeys[ i ];
        transformedBoneKeys[ i ] = 0;
	}
    
    
}


TimelineKey* Animation::keyFromRef( const Ref& ref, int newTime ) const{
	Timeline* timeline = timelines[ ref.timeline ];
	TimelineKey* keyA = timeline->keys[ ref.key ];

	if( timeline->keys.size() == 1 ){
		TimelineKey* t = 0;
		if( timeline->objectType == Timeline::BONE ){
			t = new BoneTimelineKey( *dynamic_cast< BoneTimelineKey* >( keyA ) );
		}else if( timeline->objectType == Timeline::SPRITE ){
			t = new SpriteTimelineKey( *dynamic_cast< SpriteTimelineKey* >( keyA ) );
		}
		return 	t;
	}

	int nextKeyIndex = ref.key + 1;
	if( nextKeyIndex >= timeline->keys.size() ){
		if( loopType == LOOPING ){
			nextKeyIndex = 0;
		}else{
			return keyA;
		}
	}

	TimelineKey& keyB = *timeline->keys[ nextKeyIndex ];
	int keyBTime = keyB.time;

	if( keyBTime < keyA->time ){
		keyBTime = keyBTime + length;
	}

	return keyA->interpolate( &keyB, keyBTime, newTime );
}

MainlineKey* Animation::mainlineKeyFromTime( int newTime ){
	int currentMainKey = 0;
	int size = (int)mainlineKeys.size();
	for( int m = 0; m < size; m++ ){
		if( mainlineKeys[ m ]->time <= newTime ){
			currentMainKey = m;
		}
		if( mainlineKeys[ m ]->time >= newTime ){
			break;
		}
	}
	return mainlineKeys[ currentMainKey ];
}

}