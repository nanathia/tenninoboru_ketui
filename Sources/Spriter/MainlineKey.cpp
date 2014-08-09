#include "MainlineKey.h"
#include "Ref.h"

namespace spriter{

MainlineKey::MainlineKey( XMLElement* e ):
	time( 0 )
{
	if( e->Attribute( "time" ) ){
		time = e->IntAttribute( "time" );
	}

	XMLElement* c = e->FirstChildElement();
	while( c ){
		string str = c->Name();
		if( str == "bone_ref" ){
			boneRefs.push_back( new Ref( c ) );
		}else if( str == "object_ref" ){
			objectRefs.push_back( new Ref( c ) );
		}
		c = c->NextSiblingElement();
	}
}


MainlineKey::~MainlineKey(void)
{
	int size = (int)boneRefs.size();
	for( int i = 0; i < size; i++ ){
		delete boneRefs[ i ];
        boneRefs[ i ] = 0;
	}
	size = (int)objectRefs.size();
	for( int i = 0; i < size; i++ ){
        delete objectRefs[ i ];
		objectRefs[ i ] = 0;
	}
}
    
}
