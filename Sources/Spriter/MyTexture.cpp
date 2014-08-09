#include "MyTexture.h"
#include "SpatialInfo.h"
#include "spriterFiles.h"
#include "GameMain.h"
#include "SaKumas_includes.h"
#include "Karakuri.h"
#include <string>
using namespace std;

namespace spriter{
    
bool MyTexture::deleteFrag = false;
    
MyTexture::MyTexture( const char* filename ):
	name( filename ),
    m_tex(0)
{
	/*Framework f = Framework::instance();

	f.createTexture( &texture, filename );
	int sx, sy, ox, oy;
	f.getTextureSizes( texture, &sx, &sy, &ox, &oy );
	double tx = static_cast< double >( ox ) / static_cast< double >( sx );
	double ty = static_cast< double >( oy ) / static_cast< double >( sy );
	t1_x = 0.0;  t1_y = 0.0;
	t2_x = tx; t2_y = 0.0;
	t3_x = 0.0; t3_y = ty;
	t4_x = tx; t4_y = ty;*/
    m_tex = new GMTexture2D(filename);
    printf("MyTexture(%s)\n", filename);
}


MyTexture::~MyTexture(void)
{
    delete m_tex;
    m_tex = 0;
}

void MyTexture::draw( double* p1, double* p2, double* p3, double* p4, unsigned color ) const{
	/*Framework f = Framework::instance();
	f.setBlendMode( Framework::BLEND_LINEAR );
	f.enableDepthTest( true );
	f.setTexture( texture );

	f.drawTriangle3D( p1, p2, p3, &t1_x, &t2_x, &t4_x, color, color, color );
	f.drawTriangle3D( p1, p4, p3, &t1_x, &t3_x, &t4_x, color, color, color );
    */
}


void MyTexture::draw(const SpatialInfo* info, double pivot_x, double pivot_y, const GMVector3D& pos, const double _scale, const GMVector3D& rota){
    // 再度のDirectXへの移行の可能性を考慮しコメントとして描画を残しておく。
    /*
    // テクスチャ、
	int tex_xi, tex_yi, damy1, damy2;
	Framework::instance().getTextureSizes( this->texture, &damy1, &damy2, &tex_xi, &tex_yi );
	double texSize[ 4 ][ 4 ];
	double px = static_cast< double >( tex_xi ) * pivot_x;
	pivot_y = 1.0 - pivot_y;
	double py = static_cast< double >( tex_yi ) * pivot_y;
	tex_xi = -tex_xi;
//	tex_yi = -tex_yi;

	for( int i = 0; i < 4; i++ ){
		texSize[ i ][ 2 ] = 400.0;
		texSize[ i ][ 3 ] = 400.0;
		switch( i ){
		case 0:
			texSize[ i ][ 0 ] = static_cast< double >( 0 ) + px;
			texSize[ i ][ 1 ] = static_cast< double >( 0 ) - py;
			break;
		case 1:
			texSize[ i ][ 0 ] = static_cast< double >( tex_xi ) + px;
			texSize[ i ][ 1 ] = static_cast< double >( 0 ) - py;
			break;
		case 2:
			texSize[ i ][ 0 ] = static_cast< double >( 0 ) + px;
			texSize[ i ][ 1 ] = static_cast< double >( tex_yi ) - py;
			break;
		case 3:
			texSize[ i ][ 0 ] = static_cast< double >( tex_xi ) + px;
			texSize[ i ][ 1 ] = static_cast< double >( tex_yi ) - py;
			break;
		}
		texSize[ i ][ 0 ] *= info->scaleX;
		texSize[ i ][ 1 ] *= info->scaleY;
		double distance = GameLib::sqrt( texSize[ i ][ 0 ]*texSize[ i ][ 0 ] + texSize[ i ][ 1 ]*texSize[ i ][ 1 ] );
		double angle_t = GameLib::atan2( texSize[ i ][ 1 ], texSize[ i ][ 0 ] );
		double sin = GameLib::sin( info->angle + angle_t+180 );
		double cos = GameLib::cos( info->angle + angle_t+180 );
		texSize[ i ][ 0 ] = cos*distance;
		texSize[ i ][ 1 ] = sin*distance;
		texSize[ i ][ 0 ] += info->x;
		texSize[ i ][ 1 ] += info->y;
		texSize[ i ][ 1 ] = -texSize[ i ][ 1 ];
		texSize[ i ][ 0 ] += 320.0;
		texSize[ i ][ 1 ] += 240.0;
		texSize[ i ][ 1 ] *= (640.0/480.0);
	}
	Framework f = Framework::instance();
	f.enableDepthTest( true );
	f.enableDepthWrite( false );
	Framework::instance().setTexture( texture );
	Framework::instance().drawTriangle3DH( texSize[ 0 ], texSize[ 1 ], texSize[ 2 ], &t1_x, &t2_x, &t3_x );
	Framework::instance().drawTriangle3DH( texSize[ 1 ], texSize[ 2 ], texSize[ 3 ], &t2_x, &t3_x, &t4_x );
    */
    
    
    GMVector3D size = GMVector3D(m_tex->getSize().x, m_tex->getSize().y, 0);
    
    GMVector3D p[] = {
        GMVector3D::Zero, GMVector3D(size.x, 0 , 0), size, GMVector3D(0, size.y, 0)
    };
    
    const double sizeOffset = _scale;
    
    // 描画先座標
    GMVector3D harfScreen(SCREEN_SIZE.x/2, SCREEN_SIZE.y/2, 0);
    GMVector3D position(info->x, info->y, 0);
    GMVector3D scale(info->scaleX, info->scaleY, 0);
    position *= sizeOffset;
    scale *= sizeOffset;
    double radian = info->angle / 180.0;
    double addRadian = radian*M_PI;
    
    // 描画元座標
    GMVector2D t[] = {
        GMVector2D::Zero, GMVector2D::UnitX, GMVector2D::One, GMVector2D::UnitY
    };
    
    GMMatrix mat_angle = GMMatrix::CreateRotationX(0.5*M_PI);
    GMMatrix mat_rotaY = GMMatrix::CreateRotationY(rota.y*M_PI);
    GMMatrix mat_rotaZ = GMMatrix::CreateRotationZ(rota.z*M_PI);
    GMMatrix mat_rotaX = GMMatrix::CreateRotationX(rota.x*M_PI);
    GMMatrix mat = mat_rotaX*mat_rotaY*mat_rotaZ*mat_angle;
    
    GMVector3D pivot(pivot_x, pivot_y, 0);
    pivot *= size;
    for(int i = 0; i < 4; i++){
        // 変換中心軸に合わせる
        p[i] -= pivot;
        // 拡大縮小をする
        p[i] *= scale;
        // この状態で中心から頂点までの距離を出す
        double distance = sqrt(p[i].x * p[i].x + p[i].y * p[i].y);
        // この頂点の角度を出す
        double thisRadian = atan2(p[i].y, p[i].x);
        // この頂点の画像中心から見た角度と、この画像が回転するべき角度を足してsin, cosを出す。
        GMVector3D angle(std::cos(thisRadian+addRadian), std::sin(thisRadian+addRadian), 0);
        // 頂点までの距離にこの頂点のsin, cosを適用したものをバッファに入れる。
        p[i] = distance*angle;
        // 最終的に置く位置に移動する。
        p[i] += position;
        // 行列演算
        p[i] = p[i].transform(mat);
        // スクリーンポジションに移動する。
        p[i] += pos;
        p[i].y += ScmlFunctions::m_sortNum;
        ScmlFunctions::m_sortNum -= 0.005;
    }
    
    gPlayScene->getCurrentEffect()->setTexture(m_tex);
    
    GMDraw::Begin();
    GMDraw::FillQuad(p[0], p[1] ,p[2], p[3],
                     GMVector3D(0, 0, 1), GMVector3D(0, 0, 1), GMVector3D(0, 0, 1), GMVector3D(0, 0, 1),
                     t[0], t[1], t[2], t[3]);
    GMDraw::End();
    
}
    

}