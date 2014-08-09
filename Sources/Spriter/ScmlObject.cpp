#include "ScmlObject.h"
#include "Animation.h"
#include "File.h"
#include "Folder.h"
#include "Entity.h"
#include "CharacterMap.h"
#include "MapInstruction.h"
#include "Karakuri.h"
#include <fstream>
#include <string>

namespace spriter{

ScmlObject::ScmlObject( const char* filename ):
	currentAnimation( -1 ),
	currentEntity( -1 ),
	currentTime( -1.0 )
{
	document = new XMLDocument();
	document->LoadFile( filename );

	XMLElement* c = document->FirstChildElement( "spriter_data" )->FirstChildElement();
	while( c ){
		string name = c->Name();
		if( name == "folder" ){
			folders.push_back( new Folder( c ) );
		}
		if( name == "entity" ){
            Entity* ey = new Entity(c);
			entities.insert(map<string, Entity*>::value_type(ey->name, ey));
		}
		c = c->NextSiblingElement();
	}

}


ScmlObject::~ScmlObject(void)
{
	for( map<string, Entity*>::iterator it; it != entities.end(); it++ ){
        if(entities.empty()) break;
		delete it->second;
        it->second = 0;
	}
	int size = (int)folders.size();
	for( int i = 0; i < size; i++ ){
		delete folders[ i ];
        folders[ i ] = 0;
	}
    
	delete document;
	document = 0;
    
}

void ScmlObject::setCurrentTime( double newTime ){

    // TODO:ScmlObject::setCurrentTimeの実装
    GMException( "未実装" );
//	//å„Ç≈
//	Entity* currentEnt = entities[ currentEntity ];
//	Animation* currentAnim = currentEnt->animations[ currentAnimation ];
//	currentAnim->setCurrentTime( newTime, GMVector3D( );
}
    
Animation* ScmlObject::getAnimation(const string& entityName, const string& animationName){
    return entities[entityName]->animations[animationName];
}

void ScmlObject::applyCharacterMap( CharacterMap charMap, bool reset ){
	////Ç±Ç±Ç™Ç‹ÇæÉCÉ}ÉCÉ`ÇÌÇ©ÇÁÇÒÅBÉLÉÉÉâÉNÉ^Å[É}ÉbÉvÇ¡ÇƒÇ»ÇÒÇºÅH
	////ä÷êîñºÇÃapplyÇÕìKâûÇ∑ÇÈÅAìñÇƒÇÈÇ∆Ç©Ç¢Ç§à”ñ°ÇæÅB
	////ÉLÉÉÉâÉNÉ^Å[ÇÕÇªÇÃÇ‹Ç‹ÅAÉAÉjÉÅÅ[ÉVÉáÉìÇÇ∑ÇÈÉLÉÉÉâÉNÉ^Å[Ç∆Ç¢Ç§à”ñ°ÇæÇ∆évÇ§ÅB
	////ÉvÉçÉOÉâÉÄìIÇ»à”ñ°ÅAÇ¬Ç‹ÇËï∂éöÇ∆Ç¢Ç§à”ñ°Ç…ë®Ç¶ÇÈÇ∆ÅAÇ±ÇÃèÍçáÇ®Ç©ÇµÇ¢ÅBï∂éöÇ»Ç«Ç«Ç±Ç…Ç‡ìoèÍÇµÇƒÇ¢Ç»Ç¢ÅB
	////Ç¬Ç‹ÇËÅAñÛÇµÇƒÇ›ÇÈÇ…ÅAÅuÉAÉjÉÅÅ[ÉVÉáÉìÉLÉÉÉâÉNÉ^Å[ï\Ç…ìKópÅuí«â¡ÅvÅvÇ∑ÇÈÅH

	//if( reset ){
	//	//ÉäÉZÉbÉgÉtÉâÉOÇ™óßÇ¡ÇƒÇ¢ÇÈèÍçáÇ…ÅAÇ±ÇÃèàóùÇé¿çsÇ∑ÇÈÇÌÇØÇ≈Ç∑ÇÀï™Ç©ÇËÇ‹Ç∑ÅB
	//	//ÉAÉNÉeÉBÉuÉLÉÉÉâÉNÉ^Å[É}ÉbÉvÇ…ÉtÉHÉãÉ_Å[ÇÇ‘ÇøçûÇÒÇ≈Ç¢ÇÈÅEÅEÅEÇ±ÇÍÇÕÇ¬Ç‹ÇËÅEÅEÅE
	//	//åªç›ÅAÉAÉNÉeÉBÉuÇ…Ç∑Ç◊Ç´ÉtÉHÉãÉ_Å[ÇçXêVÇµÇƒÇ¢ÇÈÅHÉtÉâÉOÇ≈éwíËÇ∑ÇÈéñÇ≈ÅB
	//	//ÇæÇ™ÇªÇÍÇ™Ç»Ç∫ÉtÉHÉãÉ_Å[ÉYÇä€ÅXÇ‘ÇøçûÇﬁÇ±Ç∆Ç…Ç»ÇÈÇÃÇ©ÅH
	//	//àÍÇ¬ñ⁄ÇÃçlÇ¶Ç∆ÇµÇƒÅAÉAÉvÉäÉPÅ[ÉVÉáÉìÇìÆçÏÇ≥ÇπÇÈÇ∆ÅAì‡ïîÇÃílÇ™Ç¢ÇÎÇ¢ÇÎÇ∆ïœâªÇµÇƒÇµÇ‹Ç§ÇΩÇﬂÇ…
	//	//ÉAÉjÉÅÅ[ÉVÉáÉìÇé¸âÒÇ∑ÇÈÇ‹ÇΩÇÕï ÉAÉjÉÅÅ[ÉVÉáÉìÇégÇ§Ç∆Ç´Ç…èâä˙ílÇ…ñﬂÇ∑ìÆçÏÅB
	//	//
	//	activeCharacterMap = folders;
	//}

	////à¯êîÇ∆ÇµÇƒéÛÇØéÊÇ¡ÇΩÉ}ÉbÉvÇÃÅAíÜêgÇÃêîÇæÇØÉãÅ[ÉvÇ∑ÇÈ
	//int size = charMap.maps.size();
	//for( int m = 0; m < size; m++ ){
	//	MapInstruction currentMap = charMap.maps[ m ];
	//	//àÍå¬àÍå¬î≤Ç´èoÇµÇƒÅAÇ≈ÅAÇ±ÇÍÇÇ«Ç§Ç∑ÇÈÇ∆Ç¢Ç§ÇÃÇ©Ç™ëàì_ÇæÅB
	//	if( ( currentMap.tarFolder > -1 ) && currentMap.tarFile > -1 /*ÉoÉbÉtÉ@Ç…ÉGÉâÅ[Ç™ì¸Ç¡ÇƒÇ¢Ç»Ç¢èÍçá*/ ){	
	//		//ÉtÉHÉãÉ_Å[Å@É^Å[ÉQÉbÉgÉtÉHÉãÉ_ÅBÇ±ÇÍÇÕÅAÉAÉNÉeÉBÉuÉLÉÉÉâÉ}ÉbÉvÇÃ
	//		Folder targetFolder = activeCharacterMap[ currentMap.tarFolder ];
	//		File targetFile = targetFolder.files[ currentMap.tarFile ];
	//		activeCharacterMap[ folder ].files[ file ] = targetFile;
	//	}else{
	//		//HALT( ScmlObject::applyCharacterMap ÉoÉbÉtÉ@Ç…ÉGÉâÅ[Ç™ì¸Ç¡ÇƒÇ¢ÇÈÅ@);
	//	}
	//}à”ñ°Ç™ÇÌÇ©ÇÁÇÒ
}
//
//SpatialInfo ScmlObject::charcterInfo(){
//	return 0;
//}

}