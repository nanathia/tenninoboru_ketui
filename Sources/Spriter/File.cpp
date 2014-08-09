#include "File.h"
#include "MyTexture.h"

namespace spriter{

File::File( XMLElement* e ):
	pivotX( 0 ),
	pivotY( 1 )
{
	name = e->Attribute( "name" );

	tex = new MyTexture( name.c_str() );
}


File::~File(void)
{
	delete tex;
	tex = 0;
}

}