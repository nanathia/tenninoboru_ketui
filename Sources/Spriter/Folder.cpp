#include "Folder.h"
#include "File.h"

namespace spriter{

Folder::Folder( XMLElement* e )
{
	//フォルダパス
	name = e->Attribute( "name" ) ? e->Attribute( "name" ) : "";
	
	XMLElement* c = e->FirstChildElement();
    while( c ){
		string name = c->Name();
		if( name == "file" ){
			files.push_back( new File( c ) );
		}
		c = c->NextSiblingElement();
	}
}


Folder::~Folder(void)
{
	int size = (int)files.size();
	for( int i = 0; i < size; i++ ){
		delete files[ i ];
        files[ i ] = 0;
	}
}

}