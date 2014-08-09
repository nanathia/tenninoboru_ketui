#include "CharacterMap.h"
#include "MapInstruction.h"


namespace spriter{

CharacterMap::CharacterMap( XMLElement* e )
{
	name = e->Attribute( "name" );
}


CharacterMap::~CharacterMap(void)
{
	int size = (int)maps.size();
	for( int i = 0; i < size; i++ ){
		delete maps[ i ];
        maps[ i ] = 0;
	}
}

}

// std::map 使用の場合の参考
//SKTextureManager::~SKTextureManager(){
//    std::map<int, GMTexture2D*>::iterator it;
//    if(m_tex.empty()){
//        return;
//    }
//    for(it = m_tex.begin(); it == m_tex.end(); it++){
//        delete it->second;
//        it->second = 0;
//    }
//    m_tex.clear();
//}
//
//GMTexture2D* SKTextureManager::get(int name){
//    return m_tex[name];
//}
//
//void SKTextureManager::add(int name, const char* fileName){
//    GMTexture2D* tex = new GMTexture2D(fileName);
//    m_tex.insert(std::map<int, GMTexture2D*>::value_type(name, tex));
//}
