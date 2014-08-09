#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include "randam_dungeon.h"
#include "SKMass.h"
using namespace std;


randam_dungeon::randam_dungeon():
map(0)
{
}

randam_dungeon::~randam_dungeon(){
	int size = 0;

	size = (int)list.size();
	for( int i = 0; i < size; i++ ){
		delete list[ i ];
		list[ i ] = 0;
	}
	list.clear();
	size = (int)couple_list.size();
	for( int i = 0; i < size; i++ ){
		delete couple_list[ i ];
		couple_list[ i ] = 0;
	}
	couple_list.clear();
	size = (int)room_list.size();
	for( int i = 0; i < size; i++ ){
		delete room_list[ i ];
		room_list[ i ] = 0;
	}
	room_list.clear();
}

_rect* _rect::justConectRect( bool isWidth, int value ){
	int size = (int)childRects.size();
	_rect* returnRect = 0;
	for( int i = 0; i < size; i++ ){
		if( isWidth && this->hx == value ){
			returnRect = this;
			break;
		}else if( !isWidth && this->hy == value ){
			returnRect = this;
			break;
		}
		returnRect = childRects[ i ]->justConectRect( isWidth, value );
		if( returnRect ){
			break;
		}
	}
	return returnRect;
};

enum{
	MINIMUM_ROOM_SIZE = 4,
	MARGIN_BETTWEEN_RECT_ROOM = 2,
	MINIMUM_RECT_SIZE = MINIMUM_ROOM_SIZE + (MARGIN_BETTWEEN_RECT_ROOM * 2),
};

int randam_dungeon::rand( int i, int j ){
	random_device rnd;
	mt19937 rand2( rnd() );
	std::uniform_int_distribution< int > dist( i, j );
	return dist( rand2 );
}

void randam_dungeon::rect_split(_rect* parent, bool pre_isWidth){
	_rect* rect_child = 0;

	//çƒãAÇÃèIóπèåèÇÕãÊâÊÇ™ç◊Ç©Ç≠Ç»ÇËÇ∑Ç¨ÇÈÇ±Ç∆ÅB
	if( (parent->hx - parent->lx) <= MINIMUM_RECT_SIZE*2 )return;
	if( (parent->hy - parent->ly) <= MINIMUM_RECT_SIZE*2 )return;


	//Ç‹Ç∏éqÇ…ÉRÉsÅ[
	rect_child = new _rect( *parent );
	parent->childRects.push_back( rect_child );

	bool isWidth = !pre_isWidth;

	if( isWidth ){
		random_device rnd3;
		mt19937 rand3( rnd3() );
		std::uniform_int_distribution< int > dist( parent->lx+MINIMUM_RECT_SIZE, parent->hx - MINIMUM_RECT_SIZE );
		int boarder_x = dist( rand3 );
		parent->hx = boarder_x;
		rect_child->lx = boarder_x;

		couple_list.push_back( 
			new _couple( parent, rect_child, _couple::COUPLE_HORIZONAL )
			);

		rect_split( parent, isWidth );
		rect_split( rect_child, isWidth );
		list.push_back( rect_child );
	}else{
		random_device rnd3;
		mt19937 rand3( rnd3() );
		std::uniform_int_distribution< int > dist( parent->ly+MINIMUM_RECT_SIZE, parent->hy - MINIMUM_RECT_SIZE );
		int boarder_y = dist( rand3 );
		parent->hy = boarder_y;
		rect_child->ly = boarder_y;

		couple_list.push_back(
			new _couple( parent, rect_child, _couple::COUPLE_VERTICAL )
			);

		rect_split( parent, isWidth );
		rect_split( rect_child, isWidth );
		list.push_back( rect_child );
	}

}


void randam_dungeon::room_make(){
	_rect* rect = 0;
	int size = (int)list.size();
	int x=0, y=0, w=0, h=0;
	for( int i = 0; i < size; i++ ){

		rect = list[ i ];
		w = rand( MINIMUM_ROOM_SIZE, rect->hx - rect->lx - (MARGIN_BETTWEEN_RECT_ROOM*2) + 1 );
		h = rand( MINIMUM_ROOM_SIZE, rect->hy - rect->ly - (MARGIN_BETTWEEN_RECT_ROOM*2) + 1 );
		x = rand( rect->lx + MARGIN_BETTWEEN_RECT_ROOM, rect->hx - MARGIN_BETTWEEN_RECT_ROOM - w + 1 );
		y = rand( rect->ly + MARGIN_BETTWEEN_RECT_ROOM, rect->hy - MARGIN_BETTWEEN_RECT_ROOM - h + 1 );
	
		_room* r = new _room( x, y, x + w, y + h );
        // デバッグ用。部屋毎にナンバリングを変数で持つ。
        r->setRoomNumber(i);
		room_list.push_back( r );
		rect->mRoom = r;
	}
}


void randam_dungeon::render(int width, int height){
    // メンバに、指定幅を代入
    MAP_H = height;
    MAP_W = width;
    
    // 初めて使う場合以外は、前に抽出した配列を削除。
    if(map){
        delete [] map;
        map = 0;
    }
    
    // 新しい指定幅を確保
    map = new unsigned[height*width];
    
    // 一つ前の情報を削除
	int size = 0;
	size = (int)list.size();
	for( int i = 0; i < size; i++ ){
		delete list[ i ];
		list[ i ] = 0;
	}
	list.clear();
	size = (int)couple_list.size();
	for( int i = 0; i < size; i++ ){
		delete couple_list[ i ];
		couple_list[ i ] = 0;
	}
	couple_list.clear();
	size = (int)room_list.size();
	for( int i = 0; i < size; i++ ){
		delete room_list[ i ];
		room_list[ i ] = 0;
	}
	room_list.clear();

    // unsigned 配列を０で初期化
	int i, j;
	for( j = 0; j < MAP_H; j++ ){
		for( i = 0; i < MAP_W; i++ ){
			map[ i * MAP_W + j ] = 0;
		};
	};

    // まず、「全体」を表す領域を生成
	_rect* rect = new _rect( 0, 0, MAP_W-1, MAP_H-1 );
    // 領域リストに追加
	list.push_back( rect );
    // ある一定のサイズまで領域を分割
	rect_split( rect, false );
    // 分割した領域内に一つづつ部屋を生成
	room_make();
    // ここまでの結果を、unsigned フラグに格納。
	print();
}

void randam_dungeon::print(){
    
    // フラグを全て０で初期化、ブロックを敷き詰めた状態にする。
	for( int i = 0; i < MAP_H; i++ ){
		for( int j = 0; j < MAP_W; j++ ){
			map[ i * MAP_W + j ] |= flag_on_block;
		}
	}
    
    // 部屋の領域をtrueに
	int i, j;
	int size = (int)room_list.size();
	for( int index = 0; index < size; index++ ){
		_room* room = room_list[ index ];
		for( int y = room->ly; y < room->hy; y++ ){
			for( int x = room->lx; x < room->hx; x++ ){
                // 部屋の中なので、ブロックを掘って消します。
				map[ y * MAP_W + x ] &= ~flag_on_block;
                // アイテムは置けます。
                map[y*MAP_W+x] |= flag_canTo_onTheObject;
			}
		}
	}
    
    // 通路の数だけ回します。（通路の通るべき場所を検索して、通路を掘る）
	size = (int)couple_list.size();
	for( int index = 0; index < size; index++ ){
		_couple* c = couple_list[ index ];
		int rand_1, rand_2, swap;
		_rect* realRect0 = 0;
		switch( c->v_or_h ){
                // 縦に分割して通路を掘る
            case _couple::COUPLE_VERTICAL:
                realRect0 = c->rect0->justConectRect( false, c->rect1->ly );
                if( !realRect0 ){
                    GMException("なんか異常");
                }
                j = rand( realRect0->mRoom->lx+1, realRect0->mRoom->hx-2 );
                rand_1 = j;
                for( i = realRect0->mRoom->hy; i < realRect0->hy; i++ ){
                    map[ i * MAP_W + j ] &= ~flag_on_block;
                }
                map[(realRect0->mRoom->hy-1)*MAP_W+j] &= ~flag_canTo_onTheObject;
                map[(realRect0->mRoom->hy-1)*MAP_W+j] |= flag_isRoom_entrance;
                j = rand( c->rect1->mRoom->lx+1, c->rect1->mRoom->hx-2 );
                rand_2 = j;
                for( i = c->rect1->ly; i < c->rect1->mRoom->ly; i++ ){
                    map[ i * MAP_W + j ] &= ~flag_on_block;
                }
                map[(c->rect1->mRoom->ly)*MAP_W+j] &= ~flag_canTo_onTheObject;
                map[(c->rect1->mRoom->ly)*MAP_W+j] |= flag_isRoom_entrance;
                if( rand_2 == rand_1 ){
                    break;
                }else if( rand_2 < rand_1 ){
                    swap = rand_2;
                    rand_2 = rand_1+1;
                    rand_1 = swap;
                }
                i = realRect0->hy;
                for( j = rand_1; j < rand_2; j++ ){
                    map[ i * MAP_W + j ] &= ~flag_on_block;
                }
                break;
                // 横に分割して通路を掘る
            case _couple::COUPLE_HORIZONAL:
                // 通路で繋ぐべき領域を取得
                // リアルレクトっていうのは非常に分かりにくい変数名なので、コメントに明記しておく。
                // _coupleクラスで結んである領域ではなく、実際に繋ぐべき領域０ー１。という意味。
                // まだ学校通ってない時代だったのでこんな変数名もあるのら。
                realRect0 = c->rect0->justConectRect( true, c->rect1->lx );
                if( !realRect0 || realRect0->hx != c->rect1->lx ){
                    GMException("なんかなってる");
                }
                
                // 部屋の通路入口をランダムで指定（分割方向と、繋ぐべき領域の場所から考えた一方向で）。
                // この場合、必ず左右のいずれか。
                // 一つ目の領域からの通路の入り口をランダム取得。ただし角は含まない。
                i = rand( realRect0->mRoom->ly+1, realRect0->mRoom->hy-2 );
                rand_1 = i;
                // 一つ目の領域の入り口から、もうひとつの領域との境界まで掘る。
                for( j = realRect0->mRoom->hx; j < realRect0->hx; j++ ){
                    map[ i * MAP_W + j ] &= ~flag_on_block;
                }
                // ちなみに、入り口に敵とアイテムの配置も不可である！
                map[i*MAP_W+(realRect0->mRoom->hx-1)] &= ~flag_canTo_onTheObject;
                map[i*MAP_W+(realRect0->mRoom->hx-1)] |= flag_isRoom_entrance;
                i = rand( c->rect1->mRoom->ly+1, c->rect1->mRoom->hy-2 );
                rand_2 = i;
                // ２つ目の領域からの通路の入口を（ｒｙ
                for( j = c->rect1->lx; j < c->rect1->mRoom->lx; j++ ){
                    map[ i * MAP_W + j ] &= ~flag_on_block;
                }
                // ちなみに（ｒｙ
                map[i*MAP_W+(c->rect1->mRoom->lx)] &= ~flag_canTo_onTheObject;
                map[i*MAP_W+(c->rect1->mRoom->lx)] |= flag_isRoom_entrance;
                if( rand_2 == rand_1 ){
                    break;
                }else if( rand_2 < rand_1 ){
                    swap = rand_2;
                    rand_2 = rand_1+1;
                    rand_1 = swap;
                }
                j = realRect0->hx;
                // ２つの掘った通路の、境界に当たった部分同士から直線で掘る。
                for( i = rand_1; i < rand_2; i++ ){
                    map[ i * MAP_W + j ] &= ~flag_on_block;
                }
                break;
		}
	}

}


vector<_room*>* randam_dungeon::getRoom(){
    return &room_list;
}

unsigned* randam_dungeon::getFlags(){
    return map;
}

void _room::addEntranceMasses(SKMass* mass){
    if(!mass){
        throw "実体がない";
    }
    m_entranceMasses.push_back(mass);
}

vector<SKMass*>* _room::getEntranceMasses(){
    return &m_entranceMasses;
}

bool _room::isInRoom(SKMass* mass) const{
    int x, y;
    mass->getPos(x, y);
    if(x>=lx && x<hx && y>=ly && y<hy){
        return true;
    }
    return false;
}

int _room::getRoomNumber() const{
    return mRoomIndex;
}

void _room::setRoomNumber(int num){
    mRoomIndex = num;
}