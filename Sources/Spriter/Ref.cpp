#include "Ref.h"

namespace spriter{

Ref::Ref( XMLElement* e ):
	parent( -1 )
{
	if( e->Attribute( "parent" ) ){
		parent = e->IntAttribute( "parent" );
	}
	timeline = e->IntAttribute( "timeline" );
	key = e->IntAttribute( "key" );
}


Ref::~Ref(void)
{
}

}