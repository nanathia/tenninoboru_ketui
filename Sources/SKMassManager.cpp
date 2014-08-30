//
//  SKMassManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/05/28.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SaKumas_includes.h"
#include "randam_dungeon.h"
#include "ItemCommandInfo.h"
#include "SKItemInclude.h"
#include "SKDungeonScene.h"
#include <fstream>
#include <vector>

// コンストラクタあ〜^q^♪
SKMassManager::SKMassManager(SKDungeonScene* parent, int width, int height, int drawAreaWidth, int drawAreaHeight):
m_parent(parent),
m_stageWidth(width),
m_stageHeight(height),
m_drawAreaWidth(drawAreaWidth),
m_drawAreaHeight(drawAreaHeight),
m_random_dungeonRenderer(0),
m_nextFlag(false),
m_kaisou(1)
{
    // プレイシーンにセット。
    parent->setMassMan(this);
    
    int size = width*height;
    m_masses = new SKMass*[size];
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            m_masses[y*width+x] = new SKMass(parent, x,y);
        }
    }
    
    // まずブロックを生成するにゃん。先に生成しないと他のアイテムとか色々置けないにゃん。
    // このゲームの物は壁を通れないからにゃん。
    m_random_dungeonRenderer = new randam_dungeon();
    m_random_dungeonRenderer->render(width, height);
    unsigned* flags = m_random_dungeonRenderer->getFlags();

    
    // 生成したステージ情報を、ブロックとして生成、
    // 部屋の入口マスを、部屋クラスに追加、
    for(int i = 0; i < size; i++){
        if(m_random_dungeonRenderer->getFlags()[i] & randam_dungeon::flag_isRoom_entrance){
            int size = (int)this->m_random_dungeonRenderer->getRoom()->size();
            vector<_room*>& rooms = *(this->m_random_dungeonRenderer->getRoom());
            for(int j = 0; j < size; j++){
                if(rooms[j]->isInRoom(m_masses[i])){
                    rooms[j]->addEntranceMasses(m_masses[i]);
                    break;
                }
                if(j == size-1){
                    throw "この「部屋の入口」が、どの部屋にもない";
                }
            }
        }
        else if(m_random_dungeonRenderer->getFlags()[i] & randam_dungeon::flag_on_block){
            SKBlock* block = new SKBlock(m_parent);
            parent->getBlockMan()->add(block);
            m_masses[i]->setBlock(block);
        }
    }
    
    // マス毎に、マスがある場所の部屋をセット
    for(int i = 0; i < size; i++){
        m_masses[i]->seachRoom();
    }
    
    // サクマを生成してから、各参照先へアドレスを渡すにゃん^q^♪
    SKPlayer* player = new SKPlayer(parent);
    parent->setPlayer(player);
    
    // サクマの位置はランダム配置にゃん🌟
    vector<SKMass*> noneBlock_masses;
    for(int i = 0; i < size; i++){
        if(!(flags[i] & randam_dungeon::flag_canTo_onTheObject)){
            continue;
        }
        noneBlock_masses.push_back(m_masses[i]);
    }
    int player_index = (int)randam_dungeon::rand(0, (int)noneBlock_masses.size()-1);
    noneBlock_masses[player_index]->setMovingObject(player);
    noneBlock_masses[player_index] = noneBlock_masses[noneBlock_masses.size()-1];
    // 敵ランダム配置
    int val = 0;
    for(; val < 10; val++){
        SKEnemy* enem = SKEnemy::createRandomEnemy(m_parent);
        parent->getEnemMan()->add(enem);
        int randNum = (int)randam_dungeon::rand(0, (int)noneBlock_masses.size()-val-2);
        noneBlock_masses[randNum]->setMovingObject(enem);
        noneBlock_masses[randNum] = noneBlock_masses[noneBlock_masses.size()-val-2];
    }
    // アイテムランダム配置
    for(; val < 30; val++){
        SKItem* enem = SKItem::createRandamItem(m_parent);
        parent->getItemMan()->add(enem);
        int randNum = (int)randam_dungeon::rand(0, (int)noneBlock_masses.size()-val-2);
        noneBlock_masses[randNum]->setItem(enem);
        noneBlock_masses[randNum] = noneBlock_masses[noneBlock_masses.size()-val-2];
    }
    int r_n = (int)randam_dungeon::rand(0, (int)noneBlock_masses.size()-22);
    SKItem* item = new KaidanItem(m_parent);
    noneBlock_masses[r_n]->setItem(item);
    noneBlock_masses[r_n] = noneBlock_masses[noneBlock_masses.size()-22];

    // デバッグ用コード。ランダムダンジョンをテキストで自動生成して書き出す。
    this->fileDraw_dungeonData();
}

SKMassManager::~SKMassManager(){
    int size = m_stageWidth*m_stageHeight;
    for(int i = 0; i < size; i++){
        delete m_masses[i];
    }
    delete [] m_masses;
    
}

void SKMassManager::nextFloor(){
    m_nextFlag = true;
}

void SKMassManager::_nextFloor(){
    m_kaisou++;
    int size = m_stageWidth*m_stageHeight;
    for(int i = 0; i < size; i++){
        m_masses[i]->clean();
    }
    m_parent->getEnemMan()->clean();
    m_parent->getItemMan()->clean();
    m_parent->getBlockMan()->clean();
    m_parent->getPlayer()->setMass(0);
    
    // まずブロックを生成するにゃん。先に生成しないと他のアイテムとか色々置けないにゃん。
    // このゲームの物は壁を通れないからにゃん。
    m_random_dungeonRenderer = new randam_dungeon();
    m_random_dungeonRenderer->render(m_stageWidth, m_stageHeight);
    unsigned* flags = m_random_dungeonRenderer->getFlags();
    
    
    // 生成したステージ情報を、ブロックとして生成、
    // 部屋の入口マスを、部屋クラスに追加、
    for(int i = 0; i < size; i++){
        if(m_random_dungeonRenderer->getFlags()[i] & randam_dungeon::flag_isRoom_entrance){
            int size = (int)this->m_random_dungeonRenderer->getRoom()->size();
            vector<_room*>& rooms = *(this->m_random_dungeonRenderer->getRoom());
            for(int j = 0; j < size; j++){
                if(rooms[j]->isInRoom(m_masses[i])){
                    rooms[j]->addEntranceMasses(m_masses[i]);
                    break;
                }
                if(j == size-1){
                    throw "この「部屋の入口」が、どの部屋にもない";
                }
            }
        }
        else if(m_random_dungeonRenderer->getFlags()[i] & randam_dungeon::flag_on_block){
            SKBlock* block = new SKBlock(m_parent);
            m_parent->getBlockMan()->add(block);
            block->objectInit(GMGraphics::CurrentGraphics);
            m_masses[i]->setBlock(block);
        }
    }
    
    // マス毎に、マスがある場所の部屋をセット
    for(int i = 0; i < size; i++){
        m_masses[i]->seachRoom();
    }
    vector<SKMass*> noneBlock_masses;
    for(int i = 0; i < size; i++){
        if(!(flags[i] & randam_dungeon::flag_canTo_onTheObject)){
            continue;
        }
        noneBlock_masses.push_back(m_masses[i]);
    }
    // サクマを配置
    int player_index = (int)randam_dungeon::rand(0, (int)noneBlock_masses.size()-1);
    noneBlock_masses[player_index]->setMovingObject(m_parent->getPlayer());
    noneBlock_masses[player_index] = noneBlock_masses[noneBlock_masses.size()-1];
    // 敵ランダム配置
    for(int i = 0; i < 10; i++){
        SKEnemy* enem = SKEnemy::createRandomEnemy(m_parent);
        m_parent->getEnemMan()->add(enem);
        int randNum = (int)randam_dungeon::rand(0, (int)noneBlock_masses.size()-i-2);
        noneBlock_masses[randNum]->setMovingObject(enem);
        enem->objectInit(GMGraphics::CurrentGraphics);
        enem->setEnt("食虫植物");
        noneBlock_masses[randNum] = noneBlock_masses[noneBlock_masses.size()-i-2];
    }
    // アイテムランダム配置
    for(int i = 10; i < 20; i++){
        SKItem* enem = SKItem::createRandamItem(m_parent);
        m_parent->getItemMan()->add(enem);
        int randNum = (int)randam_dungeon::rand(0, (int)noneBlock_masses.size()-i-2);
        noneBlock_masses[randNum]->setItem(enem);
        enem->objectInit(GMGraphics::CurrentGraphics);
        noneBlock_masses[randNum] = noneBlock_masses[noneBlock_masses.size()-i-2];
    }
    int r_n = (int)randam_dungeon::rand(0, (int)noneBlock_masses.size()-22);
    SKItem* item = new KaidanItem(m_parent);
    item->objectInit(GMGraphics::CurrentGraphics);
    noneBlock_masses[r_n]->setItem(item);
    noneBlock_masses[r_n] = noneBlock_masses[noneBlock_masses.size()-22];
    
    // デバッグ用コード。ランダムダンジョンをテキストで自動生成して書き出す。
    this->fileDraw_dungeonData();
}

void SKMassManager::allDraw_currentGameGraph(){
    // 描画を開始するマスの x y インデクスを取得。
    int startIndex_x, startIndex_y;
    // まずプレイヤー位置を取得し
    m_parent->getPlayer()->getMass()->getPos(startIndex_x, startIndex_y);
    // 画面に入りきる幅と高さの、それぞれのマス数の半分を格納。
    int harfWidht = m_drawAreaWidth/2;
    int harfHeight = m_drawAreaHeight/2;
    // プレイヤーから上記のものを引いたら、描画開始マス。
    startIndex_x -= harfWidht;
    startIndex_y -= harfHeight;
    // そこに、描画可能のマス最大個数を足してやると、描画終了マス
    int endIndex_x = startIndex_x + m_drawAreaWidth+1;
    int endIndex_y = startIndex_y + m_drawAreaHeight+1;
    // 描画範囲マスに、一つ一つ描画位置を渡して、描画。
    for(int y = startIndex_y; y < endIndex_y; y++){
        for(int x = startIndex_x; x < endIndex_x; x++){
            // ステージ範囲外の場合には、このまま描画するとアクセス違反になるので、
            // 代わりに「何をしても壊れない壁」を描画する。
            if(x<0 || x>=m_stageWidth || y<0 || y>=m_stageHeight){
                SKMass::draw_outOfStageBlock(x-startIndex_x,y-startIndex_y);
            }else{
                m_masses[y*m_stageWidth+x]->drawAllObject_atTheThisMass(x-startIndex_x,y-startIndex_y);
            }
        }
    }
    
    // デバッグ用。薄く配置禁止領域を描画する。部屋の入口を薄い赤で描画する。
    /*if(1){
        unsigned *flags = m_random_dungeonRenderer->getFlags();
        for(int y = startIndex_y; y < endIndex_y; y++){
            for(int x = startIndex_x; x < endIndex_x; x++){
                if(!(flags[y*m_stageWidth+x] & randam_dungeon::flag_canTo_onTheObject)){
                    SKMass::draw_debugRect(x-startIndex_x,y-startIndex_y,s);
                }
                if(flags[y*m_stageWidth+x] & randam_dungeon::flag_isRoom_entrance){
                    SKMass::draw_debugRect(x-startIndex_x,y-startIndex_y,s,GMColor::Crimson);
                }
            }
        }
        
    }*/
    
}

//void SKMassManager::updateForAllObject_inTheCurrentStage(GMInput* input, double deltaTime){
//    int size = m_stageHeight*m_stageWidth;
//    
//}

void SKMassManager::update(){
    if(m_nextFlag){
        _nextFloor();
        m_nextFlag = false;
    }
}


void SKMassManager::load(GMVector2D size /*, ロードするファイル*/ ){
    
}

void SKMassManager::move(SKObject* moveObj, int ofs_x, int ofs_y){
    // 今は使わない
    int sx, sy;
    moveObj->getMass()->getPos(sx, sy);
    SKMass* preMass = m_masses[sy*m_stageWidth+sx];
    preMass->setMovingObject(0);
    moveObj->setMass(0);
    
    sx += ofs_x;
    sy += ofs_y;
    
    SKMass* nextMass = m_masses[sy*m_stageWidth+sx];
    
    nextMass->setMovingObject(moveObj);
    moveObj->setMass(nextMass);
}

SKMass* SKMassManager::get(int x, int y){
    if(x >= m_stageWidth || y >= m_stageHeight || x < 0 || y < 0){
        return 0;
    }
    return m_masses[y*m_stageWidth+x];
}

void SKMassManager::getStageSize(int& x, int& y) const{
    x = m_stageWidth;
    y = m_stageHeight;
}

// 部屋std::vectorを取得。
std::vector<_room*>& SKMassManager::getRooms(){
    return *(m_random_dungeonRenderer->getRoom());
}


// 描画インデクスに変換
void SKMassManager::convertDrawIndex(const SKMass* mass, int& ix, int& iy) const{
    // 描画を開始するマスの x y インデクスを取得。
    int startIndex_x, startIndex_y;
    // まずプレイヤー位置を取得し
    m_parent->getPlayer()->getMass()->getPos(startIndex_x, startIndex_y);
    // 画面に入りきる幅と高さの、それぞれのマス数の半分を格納。
    int harfWidht = m_drawAreaWidth/2;
    int harfHeight = m_drawAreaHeight/2;
    // プレイヤーから上記のものを引いたら、描画開始マス。
    startIndex_x -= harfWidht;
    startIndex_y -= harfHeight;
    mass->getPos(ix, iy);
    ix -= startIndex_x;
    iy -= startIndex_y;
}

// デバッグ用。ダンジョンデータを書き出す。
void SKMassManager::fileDraw_dungeonData(){
    // デバッグ用コード。ランダムダンジョンをテキストで自動生成して書き出す。
    std::ofstream ofs("/Users/nanathia/Desktop/randomText.txt", ios::binary);
    for(int y = 0; y < m_stageHeight; y++){
        if(y < 10) ofs << ' ';
        ofs << y << " //";
        for(int x = 0; x < m_stageWidth; x++){
            int index = (m_stageHeight-1-y)*m_stageWidth+x;
            if(m_masses[index]->getMovingObject()){
                if(dynamic_cast<SKPlayer*>(m_masses[index]->getMovingObject())){
                    ofs << 'P';
                }else{
                    ofs << 'E';
                }
            }else if(m_masses[index]->getItem()){
                ofs << 'I';
            }else if(m_masses[index]->getBlock()){
                ofs << '#';
            }else{
                if(m_masses[index]->getRoom()){
                    ofs << m_masses[index]->getRoom()->getRoomNumber()%10;
                }else{
                    ofs << ' ';
                }
            }
        }
        ofs << endl;
    }
    ofs << '\0';
    ofs.close();
}

int SKMassManager::getKaisou(){
    return m_kaisou;
}

void SKMassManager::ClearSearhFlag(){
    int size = this->m_stageHeight*this->m_stageWidth;
    for(int i = 0; i < size; i++){
        m_masses[i]->seachClear();
    }
}
