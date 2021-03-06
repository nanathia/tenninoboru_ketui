#pragma once
#include <vector>
using namespace std;

class _rect;
class _room;
class _couple;
class SKMass;

class randam_dungeon
{
public:
    enum RandomStage_Flags{
        flag_on_block = 1<<0,
        flag_canTo_onTheObject = 1<<1,
        flag_isWator_floor = 1<<2,
        flag_isRoom_entrance = 1<<3,
    };
    
	randam_dungeon(void);
	~randam_dungeon(void);
	
    // 使用者側からは、このrender関数のみを使って下さい。
	void render(int stageWidth, int StageHeight);
    
    // このrand()関数は、ランダムダンジョンで使われている指定された値のランダム値を即時生成する
    // アルゴリズムが入っている。直接は関係ないが、便利だから使うといいにょん。
	static int rand( int start_value, int end_value );
    // 部屋クラス配列の入るvectorを返す。
    vector<_room*>* getRoom();
    // マス分のunsigned 配列の先頭のポインタを返す。
    unsigned* getFlags();
    
private:
    // 内部での、生成に使う関数
	void rect_split( _rect* parent, bool pre_isWidth );
	void room_make();
	void print();

    // 最終出力されたステージ情報。
    unsigned* map;
    
    // 内部のランダムダンジョン生成で使う変数
	vector< _rect* > list;
	vector< _room* > room_list;
	vector< _couple* > couple_list;
    
    // render関数で出力指定をした際の、生成ステージ幅と高さ
    int MAP_H;
    int MAP_W;
    
};


// 領域クラス。分割した、そのままのもの。ある一定のサイズになると分割を終了する。
class _rect{
public:
    // 部屋。一つだけ持てる。
	_room* mRoom;
    // 領域のサイズ。
	int lx, ly, hx, hy;
	_rect( int lx, int ly, int hx, int hy ):
    mRoom( 0 )
	{
		this->lx = lx;
		this->ly = ly;
		this->hx = hx;
		this->hy = hy;
	}
    // 子の中で最も接続すべき領域は？
    // 生成時に分割された片割れの情報と、２つ持つ形で_couple_listクラスが別に存在する。片割れのメンバでこれを呼び、このインスタンスを掘って通路で接続すべき領域なのかを判定し、
    // 違った場合は更にこのインスタンスの子領域で再帰的に次々に判定する。
    // これをするのは、元は分割された片割れだったとしても、更にそれを次々に分割していく内に隣同士ではなくなり、通路で接続することができなくなるから。
    // だが、元は一つの領域なので子のどこかで必ず繋がる。なので見つかるまで末端まで検索する。見つからない場合はバグ。何かをミスっている。
	_rect* justConectRect( bool isWidth, int value );
    // 子領域。分割順から階層状にして
	vector< _rect* > childRects;
};

// 分割した領域の中に、更にランダムに生成された部屋クラス。
class _room{
    vector<SKMass*> m_entranceMasses;
    // デバッグ用。部屋としてのインデックスを格納
    int mRoomIndex;
public:
	int lx, ly, hx, hy;
	_room( int lx, int ly, int hx, int hy ):
    mRoomIndex(-99)
	{
		this->lx = lx;
		this->ly = ly;
		this->hx = hx;
		this->hy = hy;
	}
    vector<SKMass*>* getEntranceMasses();
    void addEntranceMasses(SKMass*);
    bool isInRoom(SKMass* mass) const;
    int getRoomNumber() const;
    void setRoomNumber(int num);
};

class _couple{
public:
	enum{
		COUPLE_VERTICAL = 0,
		COUPLE_HORIZONAL = 1,
	};
	int v_or_h;
	_rect* rect0,* rect1;
	_couple( _rect* _0, _rect* _1, int _v_or_h ):
    rect0( _0 ),
    rect1( _1 ),
    v_or_h( _v_or_h )
	{
	};
};


//
//
//
//                                                                                   ############
//                                                                                   ############
//                                                                                   ############
//                                                                                   ############
//      ##############################   #####             ########                    #
//      ##############################   #########         ########                    #
//      ################################ #####   #         ########                    #
//      ############################## # #####   #         ########                    #
//                            #        # #####   #         ##########                  #
//                            ######   # #####   #         ######## #                  #
//                                 #   # #####   #         ######## #                  #
//                                 #   # #####   #         ######## #                  #
//                                 #   # #####   #         ######## #                  #
//   ###################           #   # #####   #         ######## #   ################
//   ###################           #   # #####   #         ######## #   #
//   ###################           #   # #####   #         ######## #   #
//   #########################     #   # #####   #           #      #  #########
//   ###################     #     #   # #####   #           #      #  #########
//                  #        #     #   # #####   #           #      #  #########
//                  #        #     #   # #####   #           #      ############
//                  #        #     #   # #####   #           #         #########
//                  #        #     #   # #####   #           #         #########
//                  #        #     #   # #####   #           #         #########
//                  ####     #     #   # #####   #           #
//                     #     #     #   # #####   #           ####################################
//           ######    #     #     #   #######   #                                              #
//           ######    #     #     #     #####   #         ######              #####            #
//           ######    #     #     #             #         ######              #####            #
//    ####   ######    #     #     #             #         ######              #####            #
//    ###### ######    #     #     #             #         ######         ##########            #
//    #### # ######    #     #  #####            #         ######         #    #####            #
//    #### # ######    #     #  #####            #         ######         #    #####            #
//    #### # ######    #     ########            #         ######         #    #####            #
//    #### # ######   ######    #####            #         ######         #    #####            #
//    #### # ######   ######    #####            #         ######         #    #####            #
//    #### # ######   ######    #####            #         ######         #    #####            #
//    #### # ######   ######                     #         ######   ####  #    #####            #
//    #### # ######   ######                     #         ######   ####  #    #####            #
//    #### # ######   ######                     #         ######   ####  #    #####            #
//    #### # ######   ######                     #         ######   ####  #    #####            #
//    #### # ######   ######                     #         ######   ####  #    #####            #
//    #### # ######   ######                     #         ######   ####  #    #####            #
//    #### # ###### ########                     #         ######   ####  #    #####     ###########
//     #   # ###### # ######                     #         ######   ####  #    #####     ###########
//     #   # ###### # ######                     #         ######   ####  #    #####     ###########
//     #   # ###### # ######                     #         ######   ####  #    #####     ###########
//     #   # ###### # ######                     #  ####   ######   ####  #    #####     ###########
//     #   # ###### # ######                     #  ####   ######   ####  #    #####     ###########
//     #   ######## # ######                     #  ####   ######   ####  #    #####     ###########
//     #     ###### #                            #  ####   ######## ####  #    #####     ###########
//     #            #                            #######   ###### # ####  #    #####     ###########
//     ###          #                               ####   ###### # ####  #    #####     ###########
//       #          #                               ####   ###### # ####  #    #####     ###########
//       #          #                               ####   ###### # ####  #    #####     ###########
//   ######         #                               ####   ###### # ####  #    #####     ###########
//   ######         #                               ####   ###### # ####  #    #####     ###########
//   ################                               ####   ###### # ####  #    #####     ###########
//   ######                                         ####       #  # ####  #    #####     ###########
//     #                                            ####       #  # ####  #    #####     ###########
//     ###############################              ####       #  # ####  #    #####     ###########
//                                   #              ####       #  # ####  #    #####     ###########
//                                   #              ####       #  # ####  #    #####     ###########
//                                   #              ####       #  # ####  #    #####     ###########
//           #################       #              ####       #  # ####  #    #####     ###########
//           #################       #              ####       #  # ####  #    #####     ###########
//           #################       #              ####       #  # ####  #    #####     ###########
//           #################       #                         #  # ####  #    #####     ###########
//           #################      ############               #  ######  #    #####     ###########
//           #################      ############               #    ####  #    #####     ###########
//           #################      ############               #    ####  #    #####     ###########
//           #################    ##############               #          #    #####     ###########
//           #################    # ############             ###          #    #####   #############
//           #################    # ############             #            #    #####   # ###########
//                     #          # ############            ############  #    #####   # ###########
//          ############          # ############            ############  #    #####   # ###########
//          #                     # ############            ############  #    #####   # ###########
//  ##########                    # ############            ############  #    #####   # ###########
//  ##########                    # ############            ###############    #####   # ###########
//  ##########                    # ############            ############       #####   # ###########
//  ############################### ############            ############       #####   # ###########
//  ##########                      ############            ############       #####   # ###########
//  ##########                                              ############       #####   # ###########
//  ##########                                              ############       #####   # ###########
//          #                                               ############       #####   # ###########
//          #                                               ############       #####   # ###########
//          #########################                              #                   # ###########
//                                  #                              ##                  # ###########
//                                  #                               #                  # ###########
//                              ##############                      #                  # ###########
//                              ##############                      #                  # ###########
//                              ##########################   ################          # ###########
//                              ##############           ############################### ###########
//                              ##############               ################            ###########
//                              ##############               ################            ###########
//
//
//