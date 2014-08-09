#include "Entity.h"
#include "CharacterMap.h"
#include "Animation.h"

namespace spriter{

Entity::Entity( XMLElement* e )
{
	//エンティティーの名前だ
	name = e->Attribute( "name" );
	//キャラクターマップとアニメーションの初期化だ
	XMLElement* c = e->FirstChildElement();
	while( true ){
		if( !c ){
			break;
		}
		string str = c->Name();
		if( str == "character_map" ){
			characterMaps.push_back( new CharacterMap( c ) );
		}else if( str == "animation" ){
            Animation* ay = new Animation(c);
			animations.insert(map<string, Animation*>::value_type(ay->name, ay));
		}
		c = c->NextSiblingElement();
	}
}


Entity::~Entity(void)
{
	for( map<string, Animation*>::iterator it; it != animations.end(); it++ ){
        if(animations.empty()) break;
		delete it->second;
        it->second = 0;
	}
	int size = (int)characterMaps.size();
	for( int i = 0; i < size; i++ ){
		delete characterMaps[ i ];
        characterMaps[ i ];
	}
}

}