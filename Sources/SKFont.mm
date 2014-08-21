#include "SKFont.h"
#include "GameMain.h"
#include <string>

namespace sizurus_fonts{
    namespace{
        enum size{
            texSizeW = 2048,
            texSizeH = 2048*3,
            charSize = 64,
            charNum = 32,
        };
        
        // 日本語以外もバグらんらん
        bool len(const char* _1, const char* _2){
            if(_1[0] == _2[0]){
                if(_1[1] == _2[1] && _1[2] == _2[2]){
                    return true;
                }
            }
            return false;
        }
    }
    
    SKFont::SKFont(){
        
    }
    
    SKFont::SKFont(const SKFont&){
        
    }
    
    SKFont::~SKFont(){
        
    }
    
    void SKFont::drawCharacter(const char* character, GMSpriteBatch* s, const GMRect2D& destRect, const GMColor& color, double rotation, const GMVector2D& origin){
        SizurusFontsName drawFont[3];
        convertChar2Name(drawFont, character);
        GMRect2D srcRect((drawFont[0]%charNum)*charSize, (drawFont[0]/charNum)*charSize, charSize, charSize);
        s->draw(gGameInst->getFontTex(), destRect, srcRect, color, rotation*M_PI, origin*charSize, GMSpriteFlipHorizontally);
    }
    
    void SKFont::drawString_toWindow(const SizurusFontsName drawFont, const GMRect2D& destRect, GMSpriteBatch* s, GMColor c){
        int tx = (drawFont%charNum)*charSize;
        int ty = (drawFont/charNum)*charSize;
        s->draw(gGameInst->getFontTex(), destRect, GMRect2D(tx, ty, charSize, charSize), c);
    }
    
    void SKFont::convertChar2Name(SizurusFontsName* fontNames, const std::string& str){
        int size = (int)str.size()/3;
        const char* s = str.c_str();
        
        for(int i = 0; i < size; i++){
            int ind = i*3;
            
            if(len(&(s[ind]), "刊")){
                fontNames[i] = 刊;
            }
            else if(len(&(s[ind]), "圧")){
                fontNames[i] = 圧;
            }
            else if(len(&(s[ind]), "掲")){
                fontNames[i] = 掲;
            }
            else if(len(&(s[ind]), "捨")){
                fontNames[i] = 捨;
            }
            else if(len(&(s[ind]), "秘")){
                fontNames[i] = 秘;
            }
            else if(len(&(s[ind]), "札")){
                fontNames[i] = 札;
            }
            else if(len(&(s[ind]), "導")){
                fontNames[i] = 導;
            }
            else if(len(&(s[ind]), "九")){
                fontNames[i] = 九;
            }
            else if(len(&(s[ind]), "麻")){
                fontNames[i] = 麻;
            }
            else if(len(&(s[ind]), "傷")){
                fontNames[i] = 傷;
            }
            else if(len(&(s[ind]), "歯")){
                fontNames[i] = 歯;
            }
            else if(len(&(s[ind]), "清")){
                fontNames[i] = 清;
            }
            else if(len(&(s[ind]), "七")){
                fontNames[i] = 七;
            }
            else if(len(&(s[ind]), "晴")){
                fontNames[i] = 晴;
            }
            else if(len(&(s[ind]), "晩")){
                fontNames[i] = 晩;
            }
            else if(len(&(s[ind]), "継")){
                fontNames[i] = 継;
            }
            else if(len(&(s[ind]), "犯")){
                fontNames[i] = 犯;
            }
            else if(len(&(s[ind]), "辞")){
                fontNames[i] = 辞;
            }
            else if(len(&(s[ind]), "環")){
                fontNames[i] = 環;
            }
            else if(len(&(s[ind]), "列")){
                fontNames[i] = 列;
            }
            else if(len(&(s[ind]), "含")){
                fontNames[i] = 含;
            }
            else if(len(&(s[ind]), "暗")){
                fontNames[i] = 暗;
            }
            else if(len(&(s[ind]), "剣")){
                fontNames[i] = 剣;
            }
            else if(len(&(s[ind]), "盾")){
                fontNames[i] = 盾;
            }
            else if(len(&(s[ind]), "腕")){
                fontNames[i] = 腕;
            }
            else if(len(&(s[ind]), "輪")){
                fontNames[i] = 輪;
            }
            else if(len(&(s[ind]), "貰")){
                fontNames[i] = 貰;
            }
            else if(len(&(s[ind]), "冬")){
                fontNames[i] = 冬;
            }
            else if(len(&(s[ind]), "州")){
                fontNames[i] = 州;
            }
            else if(len(&(s[ind]), "稼")){
                fontNames[i] = 稼;
            }
            else if(len(&(s[ind]), "酔")){
                fontNames[i] = 酔;
            }
            else if(len(&(s[ind]), "賀")){
                fontNames[i] = 賀;
            }
            else if(len(&(s[ind]), "恵")){
                fontNames[i] = 恵;
            }
            else if(len(&(s[ind]), "測")){
                fontNames[i] = 測;
            }
            else if(len(&(s[ind]), "乙")){
                fontNames[i] = 乙;
            }
            else if(len(&(s[ind]), "腐")){
                fontNames[i] = 腐;
            }
            else if(len(&(s[ind]), "牛")){
                fontNames[i] = 牛;
            }
            else if(len(&(s[ind]), "互")){
                fontNames[i] = 互;
            }
            else if(len(&(s[ind]), "療")){
                fontNames[i] = 療;
            }
            else if(len(&(s[ind]), "到")){
                fontNames[i] = 到;
            }
            else if(len(&(s[ind]), "里")){
                fontNames[i] = 里;
            }
            else if(len(&(s[ind]), "延")){
                fontNames[i] = 延;
            }
            else if(len(&(s[ind]), "払")){
                fontNames[i] = 払;
            }
            else if(len(&(s[ind]), "誘")){
                fontNames[i] = 誘;
            }
            else if(len(&(s[ind]), "旦")){
                fontNames[i] = 旦;
            }
            else if(len(&(s[ind]), "純")){
                fontNames[i] = 純;
            }
            else if(len(&(s[ind]), "富")){
                fontNames[i] = 富;
            }
            else if(len(&(s[ind]), "裕")){
                fontNames[i] = 裕;
            }
            else if(len(&(s[ind]), "綺")){
                fontNames[i] = 綺;
            }
            else if(len(&(s[ind]), "忙")){
                fontNames[i] = 忙;
            }
            else if(len(&(s[ind]), "箱")){
                fontNames[i] = 箱;
            }
            else if(len(&(s[ind]), "隠")){
                fontNames[i] = 隠;
            }
            else if(len(&(s[ind]), "嘘")){
                fontNames[i] = 嘘;
            }
            else if(len(&(s[ind]), "嫁")){
                fontNames[i] = 嫁;
            }
            else if(len(&(s[ind]), "蔵")){
                fontNames[i] = 蔵;
            }
            else if(len(&(s[ind]), "敗")){
                fontNames[i] = 敗;
            }
            else if(len(&(s[ind]), "菅")){
                fontNames[i] = 菅;
            }
            else if(len(&(s[ind]), "尾")){
                fontNames[i] = 尾;
            }
            else if(len(&(s[ind]), "湯")){
                fontNames[i] = 湯;
            }
            else if(len(&(s[ind]), "妙")){
                fontNames[i] = 妙;
            }
            else if(len(&(s[ind]), "角")){
                fontNames[i] = 角;
            }
            else if(len(&(s[ind]), "丁")){
                fontNames[i] = 丁;
            }
            else if(len(&(s[ind]), "監")){
                fontNames[i] = 監;
            }
            else if(len(&(s[ind]), "ン")){
                fontNames[i] = ン;
            }
            else if(len(&(s[ind]), "ー")){
                fontNames[i] = ー;
            }
            else if(len(&(s[ind]), "「")){
                fontNames[i] = 鍵括弧始;
            }
            else if(len(&(s[ind]), "」")){
                fontNames[i] = 鍵括弧閉;
            }
            else if(len(&(s[ind]), "（")){
                fontNames[i] = 括弧始;
            }
            else if(len(&(s[ind]), "）")){
                fontNames[i] = 括弧閉;
            }
            else if(len(&(s[ind]), "歓")){
                fontNames[i] = 歓;
            }
            else if(len(&(s[ind]), "購")){
                fontNames[i] = 購;
            }
            else if(len(&(s[ind]), "右")){
                fontNames[i] = 右;
            }
            else if(len(&(s[ind]), "左")){
                fontNames[i] = 左;
            }
            else if(len(&(s[ind]), "触")){
                fontNames[i] = 触;
            }
            else if(len(&(s[ind]), "乱")){
                fontNames[i] = 乱;
            }
            else if(len(&(s[ind]), "仮")){
                fontNames[i] = 仮;
            }
            else if(len(&(s[ind]), "慢")){
                fontNames[i] = 慢;
            }
            else if(len(&(s[ind]), "百")){
                fontNames[i] = 百;
            }
            else if(len(&(s[ind]), "推")){
                fontNames[i] = 推;
            }
            else if(len(&(s[ind]), "那")){
                fontNames[i] = 那;
            }
            else if(len(&(s[ind]), "堂")){
                fontNames[i] = 堂;
            }
            else if(len(&(s[ind]), "草")){
                fontNames[i] = 草;
            }
            else if(len(&(s[ind]), "華")){
                fontNames[i] = 華;
            }
            else if(len(&(s[ind]), "微")){
                fontNames[i] = 微;
            }
            else if(len(&(s[ind]), "疑")){
                fontNames[i] = 疑;
            }
            else if(len(&(s[ind]), "陽")){
                fontNames[i] = 陽;
            }
            else if(len(&(s[ind]), "揺")){
                fontNames[i] = 揺;
            }
            else if(len(&(s[ind]), "責")){
                fontNames[i] = 責;
            }
            else if(len(&(s[ind]), "快")){
                fontNames[i] = 快;
            }
            else if(len(&(s[ind]), "景")){
                fontNames[i] = 景;
            }
            else if(len(&(s[ind]), "劇")){
                fontNames[i] = 劇;
            }
            else if(len(&(s[ind]), "課")){
                fontNames[i] = 課;
            }
            else if(len(&(s[ind]), "礼")){
                fontNames[i] = 礼;
            }
            else if(len(&(s[ind]), "財")){
                fontNames[i] = 財;
            }
            else if(len(&(s[ind]), "耳")){
                fontNames[i] = 耳;
            }
            else if(len(&(s[ind]), "セ")){
                fontNames[i] = セ;
            }
            else if(len(&(s[ind]), "ソ")){
                fontNames[i] = ソ;
            }
            else if(len(&(s[ind]), "タ")){
                fontNames[i] = タ;
            }
            else if(len(&(s[ind]), "チ")){
                fontNames[i] = チ;
            }
            else if(len(&(s[ind]), "ツ")){
                fontNames[i] = ツ;
            }
            else if(len(&(s[ind]), "テ")){
                fontNames[i] = テ;
            }
            else if(len(&(s[ind]), "ト")){
                fontNames[i] = ト;
            }
            else if(len(&(s[ind]), "ナ")){
                fontNames[i] = ナ;
            }
            else if(len(&(s[ind]), "ニ")){
                fontNames[i] = ニ;
            }
            else if(len(&(s[ind]), "ヌ")){
                fontNames[i] = ヌ;
            }
            else if(len(&(s[ind]), "ネ")){
                fontNames[i] = ネ;
            }
            else if(len(&(s[ind]), "ノ")){
                fontNames[i] = ノ;
            }
            else if(len(&(s[ind]), "ハ")){
                fontNames[i] = ハ;
            }
            else if(len(&(s[ind]), "ヒ")){
                fontNames[i] = ヒ;
            }
            else if(len(&(s[ind]), "フ")){
                fontNames[i] = フ;
            }
            else if(len(&(s[ind]), "ヘ")){
                fontNames[i] = ヘ;
            }
            else if(len(&(s[ind]), "ホ")){
                fontNames[i] = ホ;
            }
            else if(len(&(s[ind]), "マ")){
                fontNames[i] = マ;
            }
            else if(len(&(s[ind]), "ミ")){
                fontNames[i] = ミ;
            }
            else if(len(&(s[ind]), "ム")){
                fontNames[i] = ム;
            }
            else if(len(&(s[ind]), "メ")){
                fontNames[i] = メ;
            }
            else if(len(&(s[ind]), "モ")){
                fontNames[i] = モ;
            }
            else if(len(&(s[ind]), "ヤ")){
                fontNames[i] = ヤ;
            }
            else if(len(&(s[ind]), "ユ")){
                fontNames[i] = ユ;
            }
            else if(len(&(s[ind]), "ヨ")){
                fontNames[i] = ヨ;
            }
            else if(len(&(s[ind]), "ラ")){
                fontNames[i] = ラ;
            }
            else if(len(&(s[ind]), "リ")){
                fontNames[i] = リ;
            }
            else if(len(&(s[ind]), "ル")){
                fontNames[i] = ル;
            }
            else if(len(&(s[ind]), "レ")){
                fontNames[i] = レ;
            }
            else if(len(&(s[ind]), "ロ")){
                fontNames[i] = ロ;
            }
            else if(len(&(s[ind]), "ワ")){
                fontNames[i] = ワ;
            }
            else if(len(&(s[ind]), "ヲ")){
                fontNames[i] = ヲ;
            }
            else if(len(&(s[ind]), "み")){
                fontNames[i] = み;
            }
            else if(len(&(s[ind]), "む")){
                fontNames[i] = む;
            }
            else if(len(&(s[ind]), "め")){
                fontNames[i] = め;
            }
            else if(len(&(s[ind]), "も")){
                fontNames[i] = も;
            }
            else if(len(&(s[ind]), "や")){
                fontNames[i] = や;
            }
            else if(len(&(s[ind]), "ゆ")){
                fontNames[i] = ゆ;
            }
            else if(len(&(s[ind]), "よ")){
                fontNames[i] = よ;
            }
            else if(len(&(s[ind]), "ら")){
                fontNames[i] = ら;
            }
            else if(len(&(s[ind]), "り")){
                fontNames[i] = り;
            }
            else if(len(&(s[ind]), "る")){
                fontNames[i] = る;
            }
            else if(len(&(s[ind]), "れ")){
                fontNames[i] = れ;
            }
            else if(len(&(s[ind]), "ろ")){
                fontNames[i] = ろ;
            }
            else if(len(&(s[ind]), "わ")){
                fontNames[i] = わ;
            }
            else if(len(&(s[ind]), "を")){
                fontNames[i] = を;
            }
            else if(len(&(s[ind]), "ん")){
                fontNames[i] = ん;
            }
            else if(len(&(s[ind]), "波")){
                fontNames[i] = 波;
            }
            else if(len(&(s[ind]), "線")){
                fontNames[i] = 線;
            }
            else if(len(&(s[ind]), "！")){
                fontNames[i] = 吃驚;
            }
            else if(len(&(s[ind]), "？")){
                fontNames[i] = 疑問;
            }
            else if(len(&(s[ind]), "。")){
                fontNames[i] = 句点;
            }
            else if(len(&(s[ind]), "ア")){
                fontNames[i] = ア;
            }
            else if(len(&(s[ind]), "イ")){
                fontNames[i] = イ;
            }
            else if(len(&(s[ind]), "ウ")){
                fontNames[i] = ウ;
            }
            else if(len(&(s[ind]), "エ")){
                fontNames[i] = エ;
            }
            else if(len(&(s[ind]), "オ")){
                fontNames[i] = オ;
            }
            else if(len(&(s[ind]), "カ")){
                fontNames[i] = カ;
            }
            else if(len(&(s[ind]), "キ")){
                fontNames[i] = キ;
            }
            else if(len(&(s[ind]), "ク")){
                fontNames[i] = ク;
            }
            else if(len(&(s[ind]), "ケ")){
                fontNames[i] = ケ;
            }
            else if(len(&(s[ind]), "コ")){
                fontNames[i] = コ;
            }
            else if(len(&(s[ind]), "サ")){
                fontNames[i] = サ;
            }
            else if(len(&(s[ind]), "シ")){
                fontNames[i] = シ;
            }
            else if(len(&(s[ind]), "ス")){
                fontNames[i] = ス;
            }
            else if(len(&(s[ind]), "歴")){
                fontNames[i] = 歴;
            }
            else if(len(&(s[ind]), "あ")){
                fontNames[i] = あ;
            }
            else if(len(&(s[ind]), "い")){
                fontNames[i] = い;
            }
            else if(len(&(s[ind]), "う")){
                fontNames[i] = う;
            }
            else if(len(&(s[ind]), "え")){
                fontNames[i] = え;
            }
            else if(len(&(s[ind]), "お")){
                fontNames[i] = お;
            }
            else if(len(&(s[ind]), "た")){
                fontNames[i] = た;
            }
            else if(len(&(s[ind]), "ち")){
                fontNames[i] = ち;
            }
            else if(len(&(s[ind]), "つ")){
                fontNames[i] = つ;
            }
            else if(len(&(s[ind]), "て")){
                fontNames[i] = て;
            }
            else if(len(&(s[ind]), "と")){
                fontNames[i] = と;
            }
            else if(len(&(s[ind]), "か")){
                fontNames[i] = か;
            }
            else if(len(&(s[ind]), "き")){
                fontNames[i] = き;
            }
            else if(len(&(s[ind]), "く")){
                fontNames[i] = く;
            }
            else if(len(&(s[ind]), "け")){
                fontNames[i] = け;
            }
            else if(len(&(s[ind]), "こ")){
                fontNames[i] = こ;
            }
            else if(len(&(s[ind]), "さ")){
                fontNames[i] = さ;
            }
            else if(len(&(s[ind]), "し")){
                fontNames[i] = し;
            }
            else if(len(&(s[ind]), "す")){
                fontNames[i] = す;
            }
            else if(len(&(s[ind]), "せ")){
                fontNames[i] = せ;
            }
            else if(len(&(s[ind]), "そ")){
                fontNames[i] = そ;
            }
            else if(len(&(s[ind]), "な")){
                fontNames[i] = な;
            }
            else if(len(&(s[ind]), "に")){
                fontNames[i] = に;
            }
            else if(len(&(s[ind]), "ぬ")){
                fontNames[i] = ぬ;
            }
            else if(len(&(s[ind]), "ね")){
                fontNames[i] = ね;
            }
            else if(len(&(s[ind]), "の")){
                fontNames[i] = の;
            }
            else if(len(&(s[ind]), "は")){
                fontNames[i] = は;
            }
            else if(len(&(s[ind]), "ひ")){
                fontNames[i] = ひ;
            }
            else if(len(&(s[ind]), "ふ")){
                fontNames[i] = ふ;
            }
            else if(len(&(s[ind]), "へ")){
                fontNames[i] = へ;
            }
            else if(len(&(s[ind]), "ほ")){
                fontNames[i] = ほ;
            }
            else if(len(&(s[ind]), "ま")){
                fontNames[i] = ま;
            }
            else if(len(&(s[ind]), "泉")){
                fontNames[i] = 泉;
            }
            else if(len(&(s[ind]), "隣")){
                fontNames[i] = 隣;
            }
            else if(len(&(s[ind]), "豆")){
                fontNames[i] = 豆;
            }
            else if(len(&(s[ind]), "条")){
                fontNames[i] = 条;
            }
            else if(len(&(s[ind]), "荷")){
                fontNames[i] = 荷;
            }
            else if(len(&(s[ind]), "級")){
                fontNames[i] = 級;
            }
            else if(len(&(s[ind]), "税")){
                fontNames[i] = 税;
            }
            else if(len(&(s[ind]), "否")){
                fontNames[i] = 否;
            }
            else if(len(&(s[ind]), "脳")){
                fontNames[i] = 脳;
            }
            else if(len(&(s[ind]), "統")){
                fontNames[i] = 統;
            }
            else if(len(&(s[ind]), "弟")){
                fontNames[i] = 弟;
            }
            else if(len(&(s[ind]), "億")){
                fontNames[i] = 億;
            }
            else if(len(&(s[ind]), "岩")){
                fontNames[i] = 岩;
            }
            else if(len(&(s[ind]), "康")){
                fontNames[i] = 康;
            }
            else if(len(&(s[ind]), "板")){
                fontNames[i] = 板;
            }
            else if(len(&(s[ind]), "模")){
                fontNames[i] = 模;
            }
            else if(len(&(s[ind]), "暖")){
                fontNames[i] = 暖;
            }
            else if(len(&(s[ind]), "背")){
                fontNames[i] = 背;
            }
            else if(len(&(s[ind]), "境")){
                fontNames[i] = 境;
            }
            else if(len(&(s[ind]), "街")){
                fontNames[i] = 街;
            }
            else if(len(&(s[ind]), "油")){
                fontNames[i] = 油;
            }
            else if(len(&(s[ind]), "建")){
                fontNames[i] = 建;
            }
            else if(len(&(s[ind]), "短")){
                fontNames[i] = 短;
            }
            else if(len(&(s[ind]), "罪")){
                fontNames[i] = 罪;
            }
            else if(len(&(s[ind]), "衛")){
                fontNames[i] = 衛;
            }
            else if(len(&(s[ind]), "階")){
                fontNames[i] = 階;
            }
            else if(len(&(s[ind]), "与")){
                fontNames[i] = 与;
            }
            else if(len(&(s[ind]), "誌")){
                fontNames[i] = 誌;
            }
            else if(len(&(s[ind]), "胸")){
                fontNames[i] = 胸;
            }
            else if(len(&(s[ind]), "汚")){
                fontNames[i] = 汚;
            }
            else if(len(&(s[ind]), "暴")){
                fontNames[i] = 暴;
            }
            else if(len(&(s[ind]), "株")){
                fontNames[i] = 株;
            }
            else if(len(&(s[ind]), "掛")){
                fontNames[i] = 掛;
            }
            else if(len(&(s[ind]), "労")){
                fontNames[i] = 労;
            }
            else if(len(&(s[ind]), "筋")){
                fontNames[i] = 筋;
            }
            else if(len(&(s[ind]), "納")){
                fontNames[i] = 納;
            }
            else if(len(&(s[ind]), "補")){
                fontNames[i] = 補;
            }
            else if(len(&(s[ind]), "簡")){
                fontNames[i] = 簡;
            }
            else if(len(&(s[ind]), "江")){
                fontNames[i] = 江;
            }
            else if(len(&(s[ind]), "造")){
                fontNames[i] = 造;
            }
            else if(len(&(s[ind]), "浮")){
                fontNames[i] = 浮;
            }
            else if(len(&(s[ind]), "麗")){
                fontNames[i] = 麗;
            }
            else if(len(&(s[ind]), "秋")){
                fontNames[i] = 秋;
            }
            else if(len(&(s[ind]), "鼻")){
                fontNames[i] = 鼻;
            }
            else if(len(&(s[ind]), "洋")){
                fontNames[i] = 洋;
            }
            else if(len(&(s[ind]), "就")){
                fontNames[i] = 就;
            }
            else if(len(&(s[ind]), "施")){
                fontNames[i] = 施;
            }
            else if(len(&(s[ind]), "弾")){
                fontNames[i] = 弾;
            }
            else if(len(&(s[ind]), "鬼")){
                fontNames[i] = 鬼;
            }
            else if(len(&(s[ind]), "各")){
                fontNames[i] = 各;
            }
            else if(len(&(s[ind]), "恥")){
                fontNames[i] = 恥;
            }
            else if(len(&(s[ind]), "抱")){
                fontNames[i] = 抱;
            }
            else if(len(&(s[ind]), "倍")){
                fontNames[i] = 倍;
            }
            else if(len(&(s[ind]), "渋")){
                fontNames[i] = 渋;
            }
            else if(len(&(s[ind]), "沖")){
                fontNames[i] = 沖;
            }
            else if(len(&(s[ind]), "五")){
                fontNames[i] = 五;
            }
            else if(len(&(s[ind]), "略")){
                fontNames[i] = 略;
            }
            else if(len(&(s[ind]), "算")){
                fontNames[i] = 算;
            }
            else if(len(&(s[ind]), "寺")){
                fontNames[i] = 寺;
            }
            else if(len(&(s[ind]), "姿")){
                fontNames[i] = 姿;
            }
            else if(len(&(s[ind]), "伊")){
                fontNames[i] = 伊;
            }
            else if(len(&(s[ind]), "惑")){
                fontNames[i] = 惑;
            }
            else if(len(&(s[ind]), "志")){
                fontNames[i] = 志;
            }
            else if(len(&(s[ind]), "票")){
                fontNames[i] = 票;
            }
            else if(len(&(s[ind]), "適")){
                fontNames[i] = 適;
            }
            else if(len(&(s[ind]), "森")){
                fontNames[i] = 森;
            }
            else if(len(&(s[ind]), "片")){
                fontNames[i] = 片;
            }
            else if(len(&(s[ind]), "独")){
                fontNames[i] = 独;
            }
            else if(len(&(s[ind]), "雅")){
                fontNames[i] = 雅;
            }
            else if(len(&(s[ind]), "萌")){
                fontNames[i] = 萌;
            }
            else if(len(&(s[ind]), "夕")){
                fontNames[i] = 夕;
            }
            else if(len(&(s[ind]), "弱")){
                fontNames[i] = 弱;
            }
            else if(len(&(s[ind]), "並")){
                fontNames[i] = 並;
            }
            else if(len(&(s[ind]), "混")){
                fontNames[i] = 混;
            }
            else if(len(&(s[ind]), "積")){
                fontNames[i] = 積;
            }
            else if(len(&(s[ind]), "囲")){
                fontNames[i] = 囲;
            }
            else if(len(&(s[ind]), "裏")){
                fontNames[i] = 裏;
            }
            else if(len(&(s[ind]), "講")){
                fontNames[i] = 講;
            }
            else if(len(&(s[ind]), "席")){
                fontNames[i] = 席;
            }
            else if(len(&(s[ind]), "退")){
                fontNames[i] = 退;
            }
            else if(len(&(s[ind]), "妹")){
                fontNames[i] = 妹;
            }
            else if(len(&(s[ind]), "端")){
                fontNames[i] = 端;
            }
            else if(len(&(s[ind]), "察")){
                fontNames[i] = 察;
            }
            else if(len(&(s[ind]), "菜")){
                fontNames[i] = 菜;
            }
            else if(len(&(s[ind]), "児")){
                fontNames[i] = 児;
            }
            else if(len(&(s[ind]), "史")){
                fontNames[i] = 史;
            }
            else if(len(&(s[ind]), "染")){
                fontNames[i] = 染;
            }
            else if(len(&(s[ind]), "賞")){
                fontNames[i] = 賞;
            }
            else if(len(&(s[ind]), "瞬")){
                fontNames[i] = 瞬;
            }
            else if(len(&(s[ind]), "芸")){
                fontNames[i] = 芸;
            }
            else if(len(&(s[ind]), "額")){
                fontNames[i] = 額;
            }
            else if(len(&(s[ind]), "究")){
                fontNames[i] = 究;
            }
            else if(len(&(s[ind]), "軍")){
                fontNames[i] = 軍;
            }
            else if(len(&(s[ind]), "刻")){
                fontNames[i] = 刻;
            }
            else if(len(&(s[ind]), "鳥")){
                fontNames[i] = 鳥;
            }
            else if(len(&(s[ind]), "舞")){
                fontNames[i] = 舞;
            }
            else if(len(&(s[ind]), "異")){
                fontNames[i] = 異;
            }
            else if(len(&(s[ind]), "祭")){
                fontNames[i] = 祭;
            }
            else if(len(&(s[ind]), "授")){
                fontNames[i] = 授;
            }
            else if(len(&(s[ind]), "仙")){
                fontNames[i] = 仙;
            }
            else if(len(&(s[ind]), "挙")){
                fontNames[i] = 挙;
            }
            else if(len(&(s[ind]), "印")){
                fontNames[i] = 印;
            }
            else if(len(&(s[ind]), "夏")){
                fontNames[i] = 夏;
            }
            else if(len(&(s[ind]), "破")){
                fontNames[i] = 破;
            }
            else if(len(&(s[ind]), "鉄")){
                fontNames[i] = 鉄;
            }
            else if(len(&(s[ind]), "盛")){
                fontNames[i] = 盛;
            }
            else if(len(&(s[ind]), "紹")){
                fontNames[i] = 紹;
            }
            else if(len(&(s[ind]), "攻")){
                fontNames[i] = 攻;
            }
            else if(len(&(s[ind]), "鹿")){
                fontNames[i] = 鹿;
            }
            else if(len(&(s[ind]), "極")){
                fontNames[i] = 極;
            }
            else if(len(&(s[ind]), "暇")){
                fontNames[i] = 暇;
            }
            else if(len(&(s[ind]), "大")){
                fontNames[i] = 大;
            }
            else if(len(&(s[ind]), "涙")){
                fontNames[i] = 涙;
            }
            else if(len(&(s[ind]), "押")){
                fontNames[i] = 押;
            }
            else if(len(&(s[ind]), "図")){
                fontNames[i] = 図;
            }
            else if(len(&(s[ind]), "源")){
                fontNames[i] = 源;
            }
            else if(len(&(s[ind]), "類")){
                fontNames[i] = 類;
            }
            else if(len(&(s[ind]), "漫")){
                fontNames[i] = 漫;
            }
            else if(len(&(s[ind]), "症")){
                fontNames[i] = 症;
            }
            else if(len(&(s[ind]), "悲")){
                fontNames[i] = 悲;
            }
            else if(len(&(s[ind]), "側")){
                fontNames[i] = 側;
            }
            else if(len(&(s[ind]), "整")){
                fontNames[i] = 整;
            }
            else if(len(&(s[ind]), "甘")){
                fontNames[i] = 甘;
            }
            else if(len(&(s[ind]), "粉")){
                fontNames[i] = 粉;
            }
            else if(len(&(s[ind]), "担")){
                fontNames[i] = 担;
            }
            else if(len(&(s[ind]), "索")){
                fontNames[i] = 索;
            }
            else if(len(&(s[ind]), "稿")){
                fontNames[i] = 稿;
            }
            else if(len(&(s[ind]), "司")){
                fontNames[i] = 司;
            }
            else if(len(&(s[ind]), "玉")){
                fontNames[i] = 玉;
            }
            else if(len(&(s[ind]), "星")){
                fontNames[i] = 星;
            }
            else if(len(&(s[ind]), "奴")){
                fontNames[i] = 奴;
            }
            else if(len(&(s[ind]), "香")){
                fontNames[i] = 香;
            }
            else if(len(&(s[ind]), "救")){
                fontNames[i] = 救;
            }
            else if(len(&(s[ind]), "脱")){
                fontNames[i] = 脱;
            }
            else if(len(&(s[ind]), "弁")){
                fontNames[i] = 弁;
            }
            else if(len(&(s[ind]), "警")){
                fontNames[i] = 警;
            }
            else if(len(&(s[ind]), "恐")){
                fontNames[i] = 恐;
            }
            else if(len(&(s[ind]), "両")){
                fontNames[i] = 両;
            }
            else if(len(&(s[ind]), "具")){
                fontNames[i] = 具;
            }
            else if(len(&(s[ind]), "辛")){
                fontNames[i] = 辛;
            }
            else if(len(&(s[ind]), "護")){
                fontNames[i] = 護;
            }
            else if(len(&(s[ind]), "桜")){
                fontNames[i] = 桜;
            }
            else if(len(&(s[ind]), "丸")){
                fontNames[i] = 丸;
            }
            else if(len(&(s[ind]), "猫")){
                fontNames[i] = 猫;
            }
            else if(len(&(s[ind]), "卒")){
                fontNames[i] = 卒;
            }
            else if(len(&(s[ind]), "途")){
                fontNames[i] = 途;
            }
            else if(len(&(s[ind]), "娘")){
                fontNames[i] = 娘;
            }
            else if(len(&(s[ind]), "池")){
                fontNames[i] = 池;
            }
            else if(len(&(s[ind]), "省")){
                fontNames[i] = 省;
            }
            else if(len(&(s[ind]), "製")){
                fontNames[i] = 製;
            }
            else if(len(&(s[ind]), "禁")){
                fontNames[i] = 禁;
            }
            else if(len(&(s[ind]), "専")){
                fontNames[i] = 専;
            }
            else if(len(&(s[ind]), "替")){
                fontNames[i] = 替;
            }
            else if(len(&(s[ind]), "渡")){
                fontNames[i] = 渡;
            }
            else if(len(&(s[ind]), "庫")){
                fontNames[i] = 庫;
            }
            else if(len(&(s[ind]), "奈")){
                fontNames[i] = 奈;
            }
            else if(len(&(s[ind]), "八")){
                fontNames[i] = 八;
            }
            else if(len(&(s[ind]), "袋")){
                fontNames[i] = 袋;
            }
            else if(len(&(s[ind]), "駄")){
                fontNames[i] = 駄;
            }
            else if(len(&(s[ind]), "険")){
                fontNames[i] = 険;
            }
            else if(len(&(s[ind]), "協")){
                fontNames[i] = 協;
            }
            else if(len(&(s[ind]), "案")){
                fontNames[i] = 案;
            }
            else if(len(&(s[ind]), "枝")){
                fontNames[i] = 枝;
            }
            else if(len(&(s[ind]), "乳")){
                fontNames[i] = 乳;
            }
            else if(len(&(s[ind]), "許")){
                fontNames[i] = 許;
            }
            else if(len(&(s[ind]), "象")){
                fontNames[i] = 象;
            }
            else if(len(&(s[ind]), "処")){
                fontNames[i] = 処;
            }
            else if(len(&(s[ind]), "迎")){
                fontNames[i] = 迎;
            }
            else if(len(&(s[ind]), "策")){
                fontNames[i] = 策;
            }
            else if(len(&(s[ind]), "錬")){
                fontNames[i] = 錬;
            }
            else if(len(&(s[ind]), "給")){
                fontNames[i] = 給;
            }
            else if(len(&(s[ind]), "働")){
                fontNames[i] = 働;
            }
            else if(len(&(s[ind]), "証")){
                fontNames[i] = 証;
            }
            else if(len(&(s[ind]), "枚")){
                fontNames[i] = 枚;
            }
            else if(len(&(s[ind]), "姉")){
                fontNames[i] = 姉;
            }
            else if(len(&(s[ind]), "管")){
                fontNames[i] = 管;
            }
            else if(len(&(s[ind]), "査")){
                fontNames[i] = 査;
            }
            else if(len(&(s[ind]), "血")){
                fontNames[i] = 血;
            }
            else if(len(&(s[ind]), "比")){
                fontNames[i] = 比;
            }
            else if(len(&(s[ind]), "官")){
                fontNames[i] = 官;
            }
            else if(len(&(s[ind]), "静")){
                fontNames[i] = 静;
            }
            else if(len(&(s[ind]), "喜")){
                fontNames[i] = 喜;
            }
            else if(len(&(s[ind]), "息")){
                fontNames[i] = 息;
            }
            else if(len(&(s[ind]), "精")){
                fontNames[i] = 精;
            }
            else if(len(&(s[ind]), "評")){
                fontNames[i] = 評;
            }
            else if(len(&(s[ind]), "是")){
                fontNames[i] = 是;
            }
            else if(len(&(s[ind]), "橋")){
                fontNames[i] = 橋;
            }
            else if(len(&(s[ind]), "緊")){
                fontNames[i] = 緊;
            }
            else if(len(&(s[ind]), "昔")){
                fontNames[i] = 昔;
            }
            else if(len(&(s[ind]), "辺")){
                fontNames[i] = 辺;
            }
            else if(len(&(s[ind]), "四")){
                fontNames[i] = 四;
            }
            else if(len(&(s[ind]), "根")){
                fontNames[i] = 根;
            }
            else if(len(&(s[ind]), "接")){
                fontNames[i] = 接;
            }
            else if(len(&(s[ind]), "旅")){
                fontNames[i] = 旅;
            }
            else if(len(&(s[ind]), "武")){
                fontNames[i] = 武;
            }
            else if(len(&(s[ind]), "迷")){
                fontNames[i] = 迷;
            }
            else if(len(&(s[ind]), "逆")){
                fontNames[i] = 逆;
            }
            else if(len(&(s[ind]), "門")){
                fontNames[i] = 門;
            }
            else if(len(&(s[ind]), "詳")){
                fontNames[i] = 詳;
            }
            else if(len(&(s[ind]), "振")){
                fontNames[i] = 振;
            }
            else if(len(&(s[ind]), "催")){
                fontNames[i] = 催;
            }
            else if(len(&(s[ind]), "勢")){
                fontNames[i] = 勢;
            }
            else if(len(&(s[ind]), "困")){
                fontNames[i] = 困;
            }
            else if(len(&(s[ind]), "吉")){
                fontNames[i] = 吉;
            }
            else if(len(&(s[ind]), "勤")){
                fontNames[i] = 勤;
            }
            else if(len(&(s[ind]), "守")){
                fontNames[i] = 守;
            }
            else if(len(&(s[ind]), "路")){
                fontNames[i] = 路;
            }
            else if(len(&(s[ind]), "怒")){
                fontNames[i] = 怒;
            }
            else if(len(&(s[ind]), "父")){
                fontNames[i] = 父;
            }
            else if(len(&(s[ind]), "展")){
                fontNames[i] = 展;
            }
            else if(len(&(s[ind]), "便")){
                fontNames[i] = 便;
            }
            else if(len(&(s[ind]), "貴")){
                fontNames[i] = 貴;
            }
            else if(len(&(s[ind]), "佐")){
                fontNames[i] = 佐;
            }
            else if(len(&(s[ind]), "津")){
                fontNames[i] = 津;
            }
            else if(len(&(s[ind]), "壊")){
                fontNames[i] = 壊;
            }
            else if(len(&(s[ind]), "韓")){
                fontNames[i] = 韓;
            }
            else if(len(&(s[ind]), "隊")){
                fontNames[i] = 隊;
            }
            else if(len(&(s[ind]), "答")){
                fontNames[i] = 答;
            }
            else if(len(&(s[ind]), "吹")){
                fontNames[i] = 吹;
            }
            else if(len(&(s[ind]), "洗")){
                fontNames[i] = 洗;
            }
            else if(len(&(s[ind]), "移")){
                fontNames[i] = 移;
            }
            else if(len(&(s[ind]), "研")){
                fontNames[i] = 研;
            }
            else if(len(&(s[ind]), "域")){
                fontNames[i] = 域;
            }
            else if(len(&(s[ind]), "輩")){
                fontNames[i] = 輩;
            }
            else if(len(&(s[ind]), "謝")){
                fontNames[i] = 謝;
            }
            else if(len(&(s[ind]), "客")){
                fontNames[i] = 客;
            }
            else if(len(&(s[ind]), "河")){
                fontNames[i] = 河;
            }
            else if(len(&(s[ind]), "倒")){
                fontNames[i] = 倒;
            }
            else if(len(&(s[ind]), "毛")){
                fontNames[i] = 毛;
            }
            else if(len(&(s[ind]), "充")){
                fontNames[i] = 充;
            }
            else if(len(&(s[ind]), "販")){
                fontNames[i] = 販;
            }
            else if(len(&(s[ind]), "改")){
                fontNames[i] = 改;
            }
            else if(len(&(s[ind]), "提")){
                fontNames[i] = 提;
            }
            else if(len(&(s[ind]), "師")){
                fontNames[i] = 師;
            }
            else if(len(&(s[ind]), "頼")){
                fontNames[i] = 頼;
            }
            else if(len(&(s[ind]), "危")){
                fontNames[i] = 危;
            }
            else if(len(&(s[ind]), "装")){
                fontNames[i] = 装;
            }
            else if(len(&(s[ind]), "換")){
                fontNames[i] = 換;
            }
            else if(len(&(s[ind]), "族")){
                fontNames[i] = 族;
            }
            else if(len(&(s[ind]), "激")){
                fontNames[i] = 激;
            }
            else if(len(&(s[ind]), "紙")){
                fontNames[i] = 紙;
            }
            else if(len(&(s[ind]), "銀")){
                fontNames[i] = 銀;
            }
            else if(len(&(s[ind]), "費")){
                fontNames[i] = 費;
            }
            else if(len(&(s[ind]), "編")){
                fontNames[i] = 編;
            }
            else if(len(&(s[ind]), "種")){
                fontNames[i] = 種;
            }
            else if(len(&(s[ind]), "効")){
                fontNames[i] = 効;
            }
            else if(len(&(s[ind]), "防")){
                fontNames[i] = 防;
            }
            else if(len(&(s[ind]), "軽")){
                fontNames[i] = 軽;
            }
            else if(len(&(s[ind]), "節")){
                fontNames[i] = 節;
            }
            else if(len(&(s[ind]), "修")){
                fontNames[i] = 修;
            }
            else if(len(&(s[ind]), "御")){
                fontNames[i] = 御;
            }
            else if(len(&(s[ind]), "医")){
                fontNames[i] = 医;
            }
            else if(len(&(s[ind]), "材")){
                fontNames[i] = 材;
            }
            else if(len(&(s[ind]), "逃")){
                fontNames[i] = 逃;
            }
            else if(len(&(s[ind]), "派")){
                fontNames[i] = 派;
            }
            else if(len(&(s[ind]), "薬")){
                fontNames[i] = 薬;
            }
            else if(len(&(s[ind]), "越")){
                fontNames[i] = 越;
            }
            else if(len(&(s[ind]), "遠")){
                fontNames[i] = 遠;
            }
            else if(len(&(s[ind]), "営")){
                fontNames[i] = 営;
            }
            else if(len(&(s[ind]), "党")){
                fontNames[i] = 党;
            }
            else if(len(&(s[ind]), "火")){
                fontNames[i] = 火;
            }
            else if(len(&(s[ind]), "載")){
                fontNames[i] = 載;
            }
            else if(len(&(s[ind]), "午")){
                fontNames[i] = 午;
            }
            else if(len(&(s[ind]), "求")){
                fontNames[i] = 求;
            }
            else if(len(&(s[ind]), "殺")){
                fontNames[i] = 殺;
            }
            else if(len(&(s[ind]), "徐")){
                fontNames[i] = 徐;
            }
            else if(len(&(s[ind]), "去")){
                fontNames[i] = 去;
            }
            else if(len(&(s[ind]), "等")){
                fontNames[i] = 等;
            }
            else if(len(&(s[ind]), "戸")){
                fontNames[i] = 戸;
            }
            else if(len(&(s[ind]), "健")){
                fontNames[i] = 健;
            }
            else if(len(&(s[ind]), "府")){
                fontNames[i] = 府;
            }
            else if(len(&(s[ind]), "況")){
                fontNames[i] = 況;
            }
            else if(len(&(s[ind]), "企")){
                fontNames[i] = 企;
            }
            else if(len(&(s[ind]), "撮")){
                fontNames[i] = 撮;
            }
            else if(len(&(s[ind]), "吸")){
                fontNames[i] = 吸;
            }
            else if(len(&(s[ind]), "率")){
                fontNames[i] = 率;
            }
            else if(len(&(s[ind]), "邪")){
                fontNames[i] = 邪;
            }
            else if(len(&(s[ind]), "崎")){
                fontNames[i] = 崎;
            }
            else if(len(&(s[ind]), "響")){
                fontNames[i] = 響;
            }
            else if(len(&(s[ind]), "差")){
                fontNames[i] = 差;
            }
            else if(len(&(s[ind]), "為")){
                fontNames[i] = 為;
            }
            else if(len(&(s[ind]), "誕")){
                fontNames[i] = 誕;
            }
            else if(len(&(s[ind]), "雑")){
                fontNames[i] = 雑;
            }
            else if(len(&(s[ind]), "凄")){
                fontNames[i] = 凄;
            }
            else if(len(&(s[ind]), "例")){
                fontNames[i] = 例;
            }
            else if(len(&(s[ind]), "低")){
                fontNames[i] = 低;
            }
            else if(len(&(s[ind]), "浜")){
                fontNames[i] = 浜;
            }
            else if(len(&(s[ind]), "撃")){
                fontNames[i] = 撃;
            }
            else if(len(&(s[ind]), "英")){
                fontNames[i] = 英;
            }
            else if(len(&(s[ind]), "届")){
                fontNames[i] = 届;
            }
            else if(len(&(s[ind]), "戻")){
                fontNames[i] = 戻;
            }
            else if(len(&(s[ind]), "松")){
                fontNames[i] = 松;
            }
            else if(len(&(s[ind]), "程")){
                fontNames[i] = 程;
            }
            else if(len(&(s[ind]), "形")){
                fontNames[i] = 形;
            }
            else if(len(&(s[ind]), "勉")){
                fontNames[i] = 勉;
            }
            else if(len(&(s[ind]), "規")){
                fontNames[i] = 規;
            }
            else if(len(&(s[ind]), "末")){
                fontNames[i] = 末;
            }
            else if(len(&(s[ind]), "南")){
                fontNames[i] = 南;
            }
            else if(len(&(s[ind]), "寄")){
                fontNames[i] = 寄;
            }
            else if(len(&(s[ind]), "申")){
                fontNames[i] = 申;
            }
            else if(len(&(s[ind]), "室")){
                fontNames[i] = 室;
            }
            else if(len(&(s[ind]), "冷")){
                fontNames[i] = 冷;
            }
            else if(len(&(s[ind]), "巻")){
                fontNames[i] = 巻;
            }
            else if(len(&(s[ind]), "共")){
                fontNames[i] = 共;
            }
            else if(len(&(s[ind]), "宿")){
                fontNames[i] = 宿;
            }
            else if(len(&(s[ind]), "走")){
                fontNames[i] = 走;
            }
            else if(len(&(s[ind]), "工")){
                fontNames[i] = 工;
            }
            else if(len(&(s[ind]), "王")){
                fontNames[i] = 王;
            }
            else if(len(&(s[ind]), "十")){
                fontNames[i] = 十;
            }
            else if(len(&(s[ind]), "商")){
                fontNames[i] = 商;
            }
            else if(len(&(s[ind]), "細")){
                fontNames[i] = 細;
            }
            else if(len(&(s[ind]), "首")){
                fontNames[i] = 首;
            }
            else if(len(&(s[ind]), "似")){
                fontNames[i] = 似;
            }
            else if(len(&(s[ind]), "仲")){
                fontNames[i] = 仲;
            }
            else if(len(&(s[ind]), "探")){
                fontNames[i] = 探;
            }
            else if(len(&(s[ind]), "任")){
                fontNames[i] = 任;
            }
            else if(len(&(s[ind]), "権")){
                fontNames[i] = 権;
            }
            else if(len(&(s[ind]), "識")){
                fontNames[i] = 識;
            }
            else if(len(&(s[ind]), "示")){
                fontNames[i] = 示;
            }
            else if(len(&(s[ind]), "突")){
                fontNames[i] = 突;
            }
            else if(len(&(s[ind]), "郎")){
                fontNames[i] = 郎;
            }
            else if(len(&(s[ind]), "熱")){
                fontNames[i] = 熱;
            }
            else if(len(&(s[ind]), "園")){
                fontNames[i] = 園;
            }
            else if(len(&(s[ind]), "髪")){
                fontNames[i] = 髪;
            }
            else if(len(&(s[ind]), "判")){
                fontNames[i] = 判;
            }
            else if(len(&(s[ind]), "収")){
                fontNames[i] = 収;
            }
            else if(len(&(s[ind]), "基")){
                fontNames[i] = 基;
            }
            else if(len(&(s[ind]), "肉")){
                fontNames[i] = 肉;
            }
            else if(len(&(s[ind]), "型")){
                fontNames[i] = 型;
            }
            else if(len(&(s[ind]), "談")){
                fontNames[i] = 談;
            }
            else if(len(&(s[ind]), "減")){
                fontNames[i] = 減;
            }
            else if(len(&(s[ind]), "光")){
                fontNames[i] = 光;
            }
            else if(len(&(s[ind]), "打")){
                fontNames[i] = 打;
            }
            else if(len(&(s[ind]), "兄")){
                fontNames[i] = 兄;
            }
            else if(len(&(s[ind]), "追")){
                fontNames[i] = 追;
            }
            else if(len(&(s[ind]), "若")){
                fontNames[i] = 若;
            }
            else if(len(&(s[ind]), "停")){
                fontNames[i] = 停;
            }
            else if(len(&(s[ind]), "負")){
                fontNames[i] = 負;
            }
            else if(len(&(s[ind]), "介")){
                fontNames[i] = 介;
            }
            else if(len(&(s[ind]), "存")){
                fontNames[i] = 存;
            }
            else if(len(&(s[ind]), "器")){
                fontNames[i] = 器;
            }
            else if(len(&(s[ind]), "周")){
                fontNames[i] = 周;
            }
            else if(len(&(s[ind]), "服")){
                fontNames[i] = 服;
            }
            else if(len(&(s[ind]), "雨")){
                fontNames[i] = 雨;
            }
            else if(len(&(s[ind]), "訳")){
                fontNames[i] = 訳;
            }
            else if(len(&(s[ind]), "術")){
                fontNames[i] = 術;
            }
            else if(len(&(s[ind]), "波")){
                fontNames[i] = 波;
            }
            else if(len(&(s[ind]), "深")){
                fontNames[i] = 深;
            }
            else if(len(&(s[ind]), "準")){
                fontNames[i] = 準;
            }
            else if(len(&(s[ind]), "余")){
                fontNames[i] = 余;
            }
            else if(len(&(s[ind]), "科")){
                fontNames[i] = 科;
            }
            else if(len(&(s[ind]), "抜")){
                fontNames[i] = 抜;
            }
            else if(len(&(s[ind]), "影")){
                fontNames[i] = 影;
            }
            else if(len(&(s[ind]), "赤")){
                fontNames[i] = 赤;
            }
            else if(len(&(s[ind]), "育")){
                fontNames[i] = 育;
            }
            else if(len(&(s[ind]), "頃")){
                fontNames[i] = 頃;
            }
            else if(len(&(s[ind]), "値")){
                fontNames[i] = 値;
            }
            else if(len(&(s[ind]), "焼")){
                fontNames[i] = 焼;
            }
            else if(len(&(s[ind]), "視")){
                fontNames[i] = 視;
            }
            else if(len(&(s[ind]), "職")){
                fontNames[i] = 職;
            }
            else if(len(&(s[ind]), "総")){
                fontNames[i] = 総;
            }
            else if(len(&(s[ind]), "済")){
                fontNames[i] = 済;
            }
            else if(len(&(s[ind]), "際")){
                fontNames[i] = 際;
            }
            else if(len(&(s[ind]), "段")){
                fontNames[i] = 段;
            }
            else if(len(&(s[ind]), "交")){
                fontNames[i] = 交;
            }
            else if(len(&(s[ind]), "横")){
                fontNames[i] = 横;
            }
            else if(len(&(s[ind]), "温")){
                fontNames[i] = 温;
            }
            else if(len(&(s[ind]), "頂")){
                fontNames[i] = 頂;
            }
            else if(len(&(s[ind]), "習")){
                fontNames[i] = 習;
            }
            else if(len(&(s[ind]), "助")){
                fontNames[i] = 助;
            }
            else if(len(&(s[ind]), "布")){
                fontNames[i] = 布;
            }
            else if(len(&(s[ind]), "絡")){
                fontNames[i] = 絡;
            }
            else if(len(&(s[ind]), "酒")){
                fontNames[i] = 酒;
            }
            else if(len(&(s[ind]), "係")){
                fontNames[i] = 係;
            }
            else if(len(&(s[ind]), "茶")){
                fontNames[i] = 茶;
            }
            else if(len(&(s[ind]), "士")){
                fontNames[i] = 士;
            }
            else if(len(&(s[ind]), "割")){
                fontNames[i] = 割;
            }
            else if(len(&(s[ind]), "藤")){
                fontNames[i] = 藤;
            }
            else if(len(&(s[ind]), "婚")){
                fontNames[i] = 婚;
            }
            else if(len(&(s[ind]), "役")){
                fontNames[i] = 役;
            }
            else if(len(&(s[ind]), "眼")){
                fontNames[i] = 眼;
            }
            else if(len(&(s[ind]), "離")){
                fontNames[i] = 離;
            }
            else if(len(&(s[ind]), "青")){
                fontNames[i] = 青;
            }
            else if(len(&(s[ind]), "呂")){
                fontNames[i] = 呂;
            }
            else if(len(&(s[ind]), "命")){
                fontNames[i] = 命;
            }
            else if(len(&(s[ind]), "降")){
                fontNames[i] = 降;
            }
            else if(len(&(s[ind]), "黒")){
                fontNames[i] = 黒;
            }
            else if(len(&(s[ind]), "絵")){
                fontNames[i] = 絵;
            }
            else if(len(&(s[ind]), "苦")){
                fontNames[i] = 苦;
            }
            else if(len(&(s[ind]), "阪")){
                fontNames[i] = 阪;
            }
            else if(len(&(s[ind]), "価")){
                fontNames[i] = 価;
            }
            else if(len(&(s[ind]), "飛")){
                fontNames[i] = 飛;
            }
            else if(len(&(s[ind]), "区")){
                fontNames[i] = 区;
            }
            else if(len(&(s[ind]), "系")){
                fontNames[i] = 系;
            }
            else if(len(&(s[ind]), "局")){
                fontNames[i] = 局;
            }
            else if(len(&(s[ind]), "村")){
                fontNames[i] = 村;
            }
            else if(len(&(s[ind]), "城")){
                fontNames[i] = 城;
            }
            else if(len(&(s[ind]), "務")){
                fontNames[i] = 務;
            }
            else if(len(&(s[ind]), "備")){
                fontNames[i] = 備;
            }
            else if(len(&(s[ind]), "井")){
                fontNames[i] = 井;
            }
            else if(len(&(s[ind]), "携")){
                fontNames[i] = 携;
            }
            else if(len(&(s[ind]), "昼")){
                fontNames[i] = 昼;
            }
            else if(len(&(s[ind]), "登")){
                fontNames[i] = 登;
            }
            else if(len(&(s[ind]), "恋")){
                fontNames[i] = 恋;
            }
            else if(len(&(s[ind]), "興")){
                fontNames[i] = 興;
            }
            else if(len(&(s[ind]), "満")){
                fontNames[i] = 満;
            }
            else if(len(&(s[ind]), "義")){
                fontNames[i] = 義;
            }
            else if(len(&(s[ind]), "避")){
                fontNames[i] = 避;
            }
            else if(len(&(s[ind]), "館")){
                fontNames[i] = 館;
            }
            else if(len(&(s[ind]), "版")){
                fontNames[i] = 版;
            }
            else if(len(&(s[ind]), "我")){
                fontNames[i] = 我;
            }
            else if(len(&(s[ind]), "千")){
                fontNames[i] = 千;
            }
            else if(len(&(s[ind]), "失")){
                fontNames[i] = 失;
            }
            else if(len(&(s[ind]), "沢")){
                fontNames[i] = 沢;
            }
            else if(len(&(s[ind]), "敵")){
                fontNames[i] = 敵;
            }
            else if(len(&(s[ind]), "居")){
                fontNames[i] = 居;
            }
            else if(len(&(s[ind]), "号")){
                fontNames[i] = 号;
            }
            else if(len(&(s[ind]), "設")){
                fontNames[i] = 設;
            }
            else if(len(&(s[ind]), "氏")){
                fontNames[i] = 氏;
            }
            else if(len(&(s[ind]), "単")){
                fontNames[i] = 単;
            }
            else if(len(&(s[ind]), "増")){
                fontNames[i] = 増;
            }
            else if(len(&(s[ind]), "射")){
                fontNames[i] = 射;
            }
            else if(len(&(s[ind]), "聴")){
                fontNames[i] = 聴;
            }
            else if(len(&(s[ind]), "幸")){
                fontNames[i] = 幸;
            }
            else if(len(&(s[ind]), "嬉")){
                fontNames[i] = 嬉;
            }
            else if(len(&(s[ind]), "古")){
                fontNames[i] = 古;
            }
            else if(len(&(s[ind]), "座")){
                fontNames[i] = 座;
            }
            else if(len(&(s[ind]), "量")){
                fontNames[i] = 量;
            }
            else if(len(&(s[ind]), "置")){
                fontNames[i] = 置;
            }
            else if(len(&(s[ind]), "断")){
                fontNames[i] = 断;
            }
            else if(len(&(s[ind]), "了")){
                fontNames[i] = 了;
            }
            else if(len(&(s[ind]), "容")){
                fontNames[i] = 容;
            }
            else if(len(&(s[ind]), "病")){
                fontNames[i] = 病;
            }
            else if(len(&(s[ind]), "論")){
                fontNames[i] = 論;
            }
            else if(len(&(s[ind]), "進")){
                fontNames[i] = 進;
            }
            else if(len(&(s[ind]), "由")){
                fontNames[i] = 由;
            }
            else if(len(&(s[ind]), "募")){
                fontNames[i] = 募;
            }
            else if(len(&(s[ind]), "谷")){
                fontNames[i] = 谷;
            }
            else if(len(&(s[ind]), "母")){
                fontNames[i] = 母;
            }
            else if(len(&(s[ind]), "岡")){
                fontNames[i] = 岡;
            }
            else if(len(&(s[ind]), "資")){
                fontNames[i] = 資;
            }
            else if(len(&(s[ind]), "団")){
                fontNames[i] = 団;
            }
            else if(len(&(s[ind]), "注")){
                fontNames[i] = 注;
            }
            else if(len(&(s[ind]), "歳")){
                fontNames[i] = 歳;
            }
            else if(len(&(s[ind]), "春")){
                fontNames[i] = 春;
            }
            else if(len(&(s[ind]), "住")){
                fontNames[i] = 住;
            }
            else if(len(&(s[ind]), "故")){
                fontNames[i] = 故;
            }
            else if(len(&(s[ind]), "米")){
                fontNames[i] = 米;
            }
            else if(len(&(s[ind]), "飯")){
                fontNames[i] = 飯;
            }
            else if(len(&(s[ind]), "魔")){
                fontNames[i] = 魔;
            }
            else if(len(&(s[ind]), "構")){
                fontNames[i] = 構;
            }
            else if(len(&(s[ind]), "拡")){
                fontNames[i] = 拡;
            }
            else if(len(&(s[ind]), "西")){
                fontNames[i] = 西;
            }
            else if(len(&(s[ind]), "念")){
                fontNames[i] = 念;
            }
            else if(len(&(s[ind]), "忘")){
                fontNames[i] = 忘;
            }
            else if(len(&(s[ind]), "非")){
                fontNames[i] = 非;
            }
            else if(len(&(s[ind]), "普")){
                fontNames[i] = 普;
            }
            else if(len(&(s[ind]), "説")){
                fontNames[i] = 説;
            }
            else if(len(&(s[ind]), "害")){
                fontNames[i] = 害;
            }
            else if(len(&(s[ind]), "個")){
                fontNames[i] = 個;
            }
            else if(len(&(s[ind]), "帯")){
                fontNames[i] = 帯;
            }
            else if(len(&(s[ind]), "宮")){
                fontNames[i] = 宮;
            }
            else if(len(&(s[ind]), "投")){
                fontNames[i] = 投;
            }
            else if(len(&(s[ind]), "怖")){
                fontNames[i] = 怖;
            }
            else if(len(&(s[ind]), "曜")){
                fontNames[i] = 曜;
            }
            else if(len(&(s[ind]), "馬")){
                fontNames[i] = 馬;
            }
            else if(len(&(s[ind]), "広")){
                fontNames[i] = 広;
            }
            else if(len(&(s[ind]), "果")){
                fontNames[i] = 果;
            }
            else if(len(&(s[ind]), "歩")){
                fontNames[i] = 歩;
            }
            else if(len(&(s[ind]), "駅")){
                fontNames[i] = 駅;
            }
            else if(len(&(s[ind]), "町")){
                fontNames[i] = 町;
            }
            else if(len(&(s[ind]), "質")){
                fontNames[i] = 質;
            }
            else if(len(&(s[ind]), "告")){
                fontNames[i] = 告;
            }
            else if(len(&(s[ind]), "腹")){
                fontNames[i] = 腹;
            }
            else if(len(&(s[ind]), "希")){
                fontNames[i] = 希;
            }
            else if(len(&(s[ind]), "院")){
                fontNames[i] = 院;
            }
            else if(len(&(s[ind]), "件")){
                fontNames[i] = 件;
            }
            else if(len(&(s[ind]), "遊")){
                fontNames[i] = 遊;
            }
            else if(len(&(s[ind]), "描")){
                fontNames[i] = 描;
            }
            else if(len(&(s[ind]), "宅")){
                fontNames[i] = 宅;
            }
            else if(len(&(s[ind]), "速")){
                fontNames[i] = 速;
            }
            else if(len(&(s[ind]), "字")){
                fontNames[i] = 字;
            }
            else if(len(&(s[ind]), "太")){
                fontNames[i] = 太;
            }
            else if(len(&(s[ind]), "像")){
                fontNames[i] = 像;
            }
            else if(len(&(s[ind]), "態")){
                fontNames[i] = 態;
            }
            else if(len(&(s[ind]), "他")){
                fontNames[i] = 他;
            }
            else if(len(&(s[ind]), "親")){
                fontNames[i] = 親;
            }
            else if(len(&(s[ind]), "得")){
                fontNames[i] = 得;
            }
            else if(len(&(s[ind]), "反")){
                fontNames[i] = 反;
            }
            else if(len(&(s[ind]), "超")){
                fontNames[i] = 超;
            }
            else if(len(&(s[ind]), "験")){
                fontNames[i] = 験;
            }
            else if(len(&(s[ind]), "演")){
                fontNames[i] = 演;
            }
            else if(len(&(s[ind]), "土")){
                fontNames[i] = 土;
            }
            else if(len(&(s[ind]), "消")){
                fontNames[i] = 消;
            }
            else if(len(&(s[ind]), "爆")){
                fontNames[i] = 爆;
            }
            else if(len(&(s[ind]), "慣")){
                fontNames[i] = 慣;
            }
            else if(len(&(s[ind]), "嫌")){
                fontNames[i] = 嫌;
            }
            else if(len(&(s[ind]), "雪")){
                fontNames[i] = 雪;
            }
            else if(len(&(s[ind]), "和")){
                fontNames[i] = 和;
            }
            else if(len(&(s[ind]), "録")){
                fontNames[i] = 録;
            }
            else if(len(&(s[ind]), "検")){
                fontNames[i] = 検;
            }
            else if(len(&(s[ind]), "認")){
                fontNames[i] = 認;
            }
            else if(len(&(s[ind]), "指")){
                fontNames[i] = 指;
            }
            else if(len(&(s[ind]), "供")){
                fontNames[i] = 供;
            }
            else if(len(&(s[ind]), "泣")){
                fontNames[i] = 泣;
            }
            else if(len(&(s[ind]), "石")){
                fontNames[i] = 石;
            }
            else if(len(&(s[ind]), "試")){
                fontNames[i] = 試;
            }
            else if(len(&(s[ind]), "彼")){
                fontNames[i] = 彼;
            }
            else if(len(&(s[ind]), "遅")){
                fontNames[i] = 遅;
            }
            else if(len(&(s[ind]), "治")){
                fontNames[i] = 治;
            }
            else if(len(&(s[ind]), "復")){
                fontNames[i] = 復;
            }
            else if(len(&(s[ind]), "呼")){
                fontNames[i] = 呼;
            }
            else if(len(&(s[ind]), "痛")){
                fontNames[i] = 痛;
            }
            else if(len(&(s[ind]), "有")){
                fontNames[i] = 有;
            }
            else if(len(&(s[ind]), "皆")){
                fontNames[i] = 皆;
            }
            else if(len(&(s[ind]), "保")){
                fontNames[i] = 保;
            }
            else if(len(&(s[ind]), "残")){
                fontNames[i] = 残;
            }
            else if(len(&(s[ind]), "約")){
                fontNames[i] = 約;
            }
            else if(len(&(s[ind]), "状")){
                fontNames[i] = 状;
            }
            else if(len(&(s[ind]), "毎")){
                fontNames[i] = 毎;
            }
            else if(len(&(s[ind]), "観")){
                fontNames[i] = 観;
            }
            else if(len(&(s[ind]), "伝")){
                fontNames[i] = 伝;
            }
            else if(len(&(s[ind]), "常")){
                fontNames[i] = 常;
            }
            else if(len(&(s[ind]), "優")){
                fontNames[i] = 優;
            }
            else if(len(&(s[ind]), "急")){
                fontNames[i] = 急;
            }
            else if(len(&(s[ind]), "転")){
                fontNames[i] = 転;
            }
            else if(len(&(s[ind]), "木")){
                fontNames[i] = 木;
            }
            else if(len(&(s[ind]), "映")){
                fontNames[i] = 映;
            }
            else if(len(&(s[ind]), "台")){
                fontNames[i] = 台;
            }
            else if(len(&(s[ind]), "緒")){
                fontNames[i] = 緒;
            }
            else if(len(&(s[ind]), "格")){
                fontNames[i] = 格;
            }
            else if(len(&(s[ind]), "乗")){
                fontNames[i] = 乗;
            }
            else if(len(&(s[ind]), "更")){
                fontNames[i] = 更;
            }
            else if(len(&(s[ind]), "利")){
                fontNames[i] = 利;
            }
            else if(len(&(s[ind]), "花")){
                fontNames[i] = 花;
            }
            else if(len(&(s[ind]), "寒")){
                fontNames[i] = 寒;
            }
            else if(len(&(s[ind]), "完")){
                fontNames[i] = 完;
            }
            else if(len(&(s[ind]), "議")){
                fontNames[i] = 議;
            }
            else if(len(&(s[ind]), "制")){
                fontNames[i] = 制;
            }
            else if(len(&(s[ind]), "計")){
                fontNames[i] = 計;
            }
            else if(len(&(s[ind]), "組")){
                fontNames[i] = 組;
            }
            else if(len(&(s[ind]), "曲")){
                fontNames[i] = 曲;
            }
            else if(len(&(s[ind]), "支")){
                fontNames[i] = 支;
            }
            else if(len(&(s[ind]), "君")){
                fontNames[i] = 君;
            }
            else if(len(&(s[ind]), "限")){
                fontNames[i] = 限;
            }
            else if(len(&(s[ind]), "止")){
                fontNames[i] = 止;
            }
            else if(len(&(s[ind]), "空")){
                fontNames[i] = 空;
            }
            else if(len(&(s[ind]), "写")){
                fontNames[i] = 写;
            }
            else if(len(&(s[ind]), "北")){
                fontNames[i] = 北;
            }
            else if(len(&(s[ind]), "別")){
                fontNames[i] = 別;
            }
            else if(len(&(s[ind]), "覚")){
                fontNames[i] = 覚;
            }
            else if(len(&(s[ind]), "散")){
                fontNames[i] = 散;
            }
            else if(len(&(s[ind]), "引")){
                fontNames[i] = 引;
            }
            else if(len(&(s[ind]), "万")){
                fontNames[i] = 万;
            }
            else if(len(&(s[ind]), "政")){
                fontNames[i] = 政;
            }
            else if(len(&(s[ind]), "丈")){
                fontNames[i] = 丈;
            }
            else if(len(&(s[ind]), "産")){
                fontNames[i] = 産;
            }
            else if(len(&(s[ind]), "口")){
                fontNames[i] = 口;
            }
            else if(len(&(s[ind]), "運")){
                fontNames[i] = 運;
            }
            else if(len(&(s[ind]), "援")){
                fontNames[i] = 援;
            }
            else if(len(&(s[ind]), "欲")){
                fontNames[i] = 欲;
            }
            else if(len(&(s[ind]), "半")){
                fontNames[i] = 半;
            }
            else if(len(&(s[ind]), "疲")){
                fontNames[i] = 疲;
            }
            else if(len(&(s[ind]), "重")){
                fontNames[i] = 重;
            }
            else if(len(&(s[ind]), "返")){
                fontNames[i] = 返;
            }
            else if(len(&(s[ind]), "平")){
                fontNames[i] = 平;
            }
            else if(len(&(s[ind]), "夢")){
                fontNames[i] = 夢;
            }
            else if(len(&(s[ind]), "望")){
                fontNames[i] = 望;
            }
            else if(len(&(s[ind]), "在")){
                fontNames[i] = 在;
            }
            else if(len(&(s[ind]), "久")){
                fontNames[i] = 久;
            }
            else if(len(&(s[ind]), "声")){
                fontNames[i] = 声;
            }
            else if(len(&(s[ind]), "絶")){
                fontNames[i] = 絶;
            }
            else if(len(&(s[ind]), "点")){
                fontNames[i] = 点;
            }
            else if(len(&(s[ind]), "頭")){
                fontNames[i] = 頭;
            }
            else if(len(&(s[ind]), "参")){
                fontNames[i] = 参;
            }
            else if(len(&(s[ind]), "勝")){
                fontNames[i] = 勝;
            }
            else if(len(&(s[ind]), "次")){
                fontNames[i] = 次;
            }
            else if(len(&(s[ind]), "色")){
                fontNames[i] = 色;
            }
            else if(len(&(s[ind]), "主")){
                fontNames[i] = 主;
            }
            else if(len(&(s[ind]), "飲")){
                fontNames[i] = 飲;
            }
            else if(len(&(s[ind]), "素")){
                fontNames[i] = 素;
            }
            else if(len(&(s[ind]), "加")){
                fontNames[i] = 加;
            }
            else if(len(&(s[ind]), "選")){
                fontNames[i] = 選;
            }
            else if(len(&(s[ind]), "音")){
                fontNames[i] = 音;
            }
            else if(len(&(s[ind]), "向")){
                fontNames[i] = 向;
            }
            else if(len(&(s[ind]), "流")){
                fontNames[i] = 流;
            }
            else if(len(&(s[ind]), "川")){
                fontNames[i] = 川;
            }
            else if(len(&(s[ind]), "直")){
                fontNames[i] = 直;
            }
            else if(len(&(s[ind]), "込")){
                fontNames[i] = 込;
            }
            else if(len(&(s[ind]), "落")){
                fontNames[i] = 落;
            }
            else if(len(&(s[ind]), "式")){
                fontNames[i] = 式;
            }
            else if(len(&(s[ind]), "眠")){
                fontNames[i] = 眠;
            }
            else if(len(&(s[ind]), "身")){
                fontNames[i] = 身;
            }
            else if(len(&(s[ind]), "界")){
                fontNames[i] = 界;
            }
            else if(len(&(s[ind]), "死")){
                fontNames[i] = 死;
            }
            else if(len(&(s[ind]), "特")){
                fontNames[i] = 特;
            }
            else if(len(&(s[ind]), "僕")){
                fontNames[i] = 僕;
            }
            else if(len(&(s[ind]), "海")){
                fontNames[i] = 海;
            }
            else if(len(&(s[ind]), "調")){
                fontNames[i] = 調;
            }
            else if(len(&(s[ind]), "難")){
                fontNames[i] = 難;
            }
            else if(len(&(s[ind]), "配")){
                fontNames[i] = 配;
            }
            else if(len(&(s[ind]), "足")){
                fontNames[i] = 足;
            }
            else if(len(&(s[ind]), "週")){
                fontNames[i] = 週;
            }
            else if(len(&(s[ind]), "必")){
                fontNames[i] = 必;
            }
            else if(len(&(s[ind]), "然")){
                fontNames[i] = 然;
            }
            else if(len(&(s[ind]), "歌")){
                fontNames[i] = 歌;
            }
            else if(len(&(s[ind]), "葉")){
                fontNames[i] = 葉;
            }
            else if(len(&(s[ind]), "都")){
                fontNames[i] = 都;
            }
            else if(len(&(s[ind]), "問")){
                fontNames[i] = 問;
            }
            else if(len(&(s[ind]), "位")){
                fontNames[i] = 位;
            }
            else if(len(&(s[ind]), "教")){
                fontNames[i] = 教;
            }
            else if(len(&(s[ind]), "休")){
                fontNames[i] = 休;
            }
            else if(len(&(s[ind]), "線")){
                fontNames[i] = 線;
            }
            else if(len(&(s[ind]), "題")){
                fontNames[i] = 題;
            }
            else if(len(&(s[ind]), "表")){
                fontNames[i] = 表;
            }
            else if(len(&(s[ind]), "法")){
                fontNames[i] = 法;
            }
            else if(len(&(s[ind]), "戦")){
                fontNames[i] = 戦;
            }
            else if(len(&(s[ind]), "語")){
                fontNames[i] = 語;
            }
            else if(len(&(s[ind]), "校")){
                fontNames[i] = 校;
            }
            else if(len(&(s[ind]), "過")){
                fontNames[i] = 過;
            }
            else if(len(&(s[ind]), "県")){
                fontNames[i] = 県;
            }
            else if(len(&(s[ind]), "受")){
                fontNames[i] = 受;
            }
            else if(len(&(s[ind]), "解")){
                fontNames[i] = 解;
            }
            else if(len(&(s[ind]), "員")){
                fontNames[i] = 員;
            }
            else if(len(&(s[ind]), "正")){
                fontNames[i] = 正;
            }
            else if(len(&(s[ind]), "続")){
                fontNames[i] = 続;
            }
            else if(len(&(s[ind]), "三")){
                fontNames[i] = 三;
            }
            else if(len(&(s[ind]), "夫")){
                fontNames[i] = 夫;
            }
            else if(len(&(s[ind]), "顔")){
                fontNames[i] = 顔;
            }
            else if(len(&(s[ind]), "友")){
                fontNames[i] = 友;
            }
            else if(len(&(s[ind]), "想")){
                fontNames[i] = 想;
            }
            else if(len(&(s[ind]), "記")){
                fontNames[i] = 記;
            }
            else if(len(&(s[ind]), "福")){
                fontNames[i] = 福;
            }
            else if(len(&(s[ind]), "第")){
                fontNames[i] = 第;
            }
            else if(len(&(s[ind]), "応")){
                fontNames[i] = 応;
            }
            else if(len(&(s[ind]), "民")){
                fontNames[i] = 民;
            }
            else if(len(&(s[ind]), "決")){
                fontNames[i] = 決;
            }
            else if(len(&(s[ind]), "経")){
                fontNames[i] = 経;
            }
            else if(len(&(s[ind]), "誰")){
                fontNames[i] = 誰;
            }
            else if(len(&(s[ind]), "被")){
                fontNames[i] = 被;
            }
            else if(len(&(s[ind]), "連")){
                fontNames[i] = 連;
            }
            else if(len(&(s[ind]), "天")){
                fontNames[i] = 天;
            }
            else if(len(&(s[ind]), "神")){
                fontNames[i] = 神;
            }
            else if(len(&(s[ind]), "島")){
                fontNames[i] = 島;
            }
            else if(len(&(s[ind]), "道")){
                fontNames[i] = 道;
            }
            else if(len(&(s[ind]), "二")){
                fontNames[i] = 二;
            }
            else if(len(&(s[ind]), "達")){
                fontNames[i] = 達;
            }
            else if(len(&(s[ind]), "立")){
                fontNames[i] = 立;
            }
            else if(len(&(s[ind]), "世")){
                fontNames[i] = 世;
            }
            else if(len(&(s[ind]), "切")){
                fontNames[i] = 切;
            }
            else if(len(&(s[ind]), "読")){
                fontNames[i] = 読;
            }
            else if(len(&(s[ind]), "始")){
                fontNames[i] = 始;
            }
            else if(len(&(s[ind]), "文")){
                fontNames[i] = 文;
            }
            else if(len(&(s[ind]), "頑")){
                fontNames[i] = 頑;
            }
            else if(len(&(s[ind]), "屋")){
                fontNames[i] = 屋;
            }
            else if(len(&(s[ind]), "数")){
                fontNames[i] = 数;
            }
            else if(len(&(s[ind]), "侍")){
                fontNames[i] = 侍;
            }
            else if(len(&(s[ind]), "悪")){
                fontNames[i] = 悪;
            }
            else if(len(&(s[ind]), "着")){
                fontNames[i] = 着;
            }
            else if(len(&(s[ind]), "信")){
                fontNames[i] = 信;
            }
            else if(len(&(s[ind]), "集")){
                fontNames[i] = 集;
            }
            else if(len(&(s[ind]), "男")){
                fontNames[i] = 男;
            }
            else if(len(&(s[ind]), "品")){
                fontNames[i] = 品;
            }
            else if(len(&(s[ind]), "昨")){
                fontNames[i] = 昨;
            }
            else if(len(&(s[ind]), "機")){
                fontNames[i] = 機;
            }
            else if(len(&(s[ind]), "成")){
                fontNames[i] = 成;
            }
            else if(len(&(s[ind]), "化")){
                fontNames[i] = 化;
            }
            else if(len(&(s[ind]), "要")){
                fontNames[i] = 要;
            }
            else if(len(&(s[ind]), "願")){
                fontNames[i] = 願;
            }
            else if(len(&(s[ind]), "能")){
                fontNames[i] = 能;
            }
            else if(len(&(s[ind]), "確")){
                fontNames[i] = 確;
            }
            else if(len(&(s[ind]), "活")){
                fontNames[i] = 活;
            }
            else if(len(&(s[ind]), "安")){
                fontNames[i] = 安;
            }
            else if(len(&(s[ind]), "震")){
                fontNames[i] = 震;
            }
            else if(len(&(s[ind]), "山")){
                fontNames[i] = 山;
            }
            else if(len(&(s[ind]), "美")){
                fontNames[i] = 美;
            }
            else if(len(&(s[ind]), "情")){
                fontNames[i] = 情;
            }
            else if(len(&(s[ind]), "可")){
                fontNames[i] = 可;
            }
            else if(len(&(s[ind]), "市")){
                fontNames[i] = 市;
            }
            else if(len(&(s[ind]), "違")){
                fontNames[i] = 違;
            }
            else if(len(&(s[ind]), "京")){
                fontNames[i] = 京;
            }
            else if(len(&(s[ind]), "水")){
                fontNames[i] = 水;
            }
            else if(len(&(s[ind]), "考")){
                fontNames[i] = 考;
            }
            else if(len(&(s[ind]), "風")){
                fontNames[i] = 風;
            }
            else if(len(&(s[ind]), "代")){
                fontNames[i] = 代;
            }
            else if(len(&(s[ind]), "予")){
                fontNames[i] = 予;
            }
            else if(len(&(s[ind]), "売")){
                fontNames[i] = 売;
            }
            else if(len(&(s[ind]), "野")){
                fontNames[i] = 野;
            }
            else if(len(&(s[ind]), "関")){
                fontNames[i] = 関;
            }
            else if(len(&(s[ind]), "以")){
                fontNames[i] = 以;
            }
            else if(len(&(s[ind]), "災")){
                fontNames[i] = 災;
            }
            else if(len(&(s[ind]), "少")){
                fontNames[i] = 少;
            }
            else if(len(&(s[ind]), "相")){
                fontNames[i] = 相;
            }
            else if(len(&(s[ind]), "取")){
                fontNames[i] = 取;
            }
            else if(len(&(s[ind]), "真")){
                fontNames[i] = 真;
            }
            else if(len(&(s[ind]), "元")){
                fontNames[i] = 元;
            }
            else if(len(&(s[ind]), "車")){
                fontNames[i] = 車;
            }
            else if(len(&(s[ind]), "白")){
                fontNames[i] = 白;
            }
            else if(len(&(s[ind]), "店")){
                fontNames[i] = 店;
            }
            else if(len(&(s[ind]), "夜")){
                fontNames[i] = 夜;
            }
            else if(len(&(s[ind]), "番")){
                fontNames[i] = 番;
            }
            else if(len(&(s[ind]), "公")){
                fontNames[i] = 公;
            }
            else if(len(&(s[ind]), "現")){
                fontNames[i] = 現;
            }
            else if(len(&(s[ind]), "強")){
                fontNames[i] = 強;
            }
            else if(len(&(s[ind]), "心")){
                fontNames[i] = 心;
            }
            else if(len(&(s[ind]), "先")){
                fontNames[i] = 先;
            }
            else if(len(&(s[ind]), "田")){
                fontNames[i] = 田;
            }
            else if(len(&(s[ind]), "使")){
                fontNames[i] = 使;
            }
            else if(len(&(s[ind]), "仕")){
                fontNames[i] = 仕;
            }
            else if(len(&(s[ind]), "付")){
                fontNames[i] = 付;
            }
            else if(len(&(s[ind]), "外")){
                fontNames[i] = 外;
            }
            else if(len(&(s[ind]), "社")){
                fontNames[i] = 社;
            }
            else if(len(&(s[ind]), "対")){
                fontNames[i] = 対;
            }
            else if(len(&(s[ind]), "帰")){
                fontNames[i] = 帰;
            }
            else if(len(&(s[ind]), "近")){
                fontNames[i] = 近;
            }
            else if(len(&(s[ind]), "放")){
                fontNames[i] = 放;
            }
            else if(len(&(s[ind]), "不")){
                fontNames[i] = 不;
            }
            else if(len(&(s[ind]), "送")){
                fontNames[i] = 送;
            }
            else if(len(&(s[ind]), "内")){
                fontNames[i] = 内;
            }
            else if(len(&(s[ind]), "書")){
                fontNames[i] = 書;
            }
            else if(len(&(s[ind]), "小")){
                fontNames[i] = 小;
            }
            else if(len(&(s[ind]), "張")){
                fontNames[i] = 張;
            }
            else if(len(&(s[ind]), "面")){
                fontNames[i] = 面;
            }
            else if(len(&(s[ind]), "同")){
                fontNames[i] = 同;
            }
            else if(len(&(s[ind]), "多")){
                fontNames[i] = 多;
            }
            else if(len(&(s[ind]), "料")){
                fontNames[i] = 料;
            }
            else if(len(&(s[ind]), "終")){
                fontNames[i] = 終;
            }
            else if(len(&(s[ind]), "早")){
                fontNames[i] = 早;
            }
            else if(len(&(s[ind]), "所")){
                fontNames[i] = 所;
            }
            else if(len(&(s[ind]), "初")){
                fontNames[i] = 初;
            }
            else if(len(&(s[ind]), "結")){
                fontNames[i] = 結;
            }
            else if(len(&(s[ind]), "円")){
                fontNames[i] = 円;
            }
            else if(len(&(s[ind]), "起")){
                fontNames[i] = 起;
            }
            else if(len(&(s[ind]), "朝")){
                fontNames[i] = 朝;
            }
            else if(len(&(s[ind]), "期")){
                fontNames[i] = 期;
            }
            else if(len(&(s[ind]), "雷")){
                fontNames[i] = 雷;
            }
            else if(len(&(s[ind]), "当")){
                fontNames[i] = 当;
            }
            else if(len(&(s[ind]), "力")){
                fontNames[i] = 力;
            }
            else if(len(&(s[ind]), "変")){
                fontNames[i] = 変;
            }
            else if(len(&(s[ind]), "理")){
                fontNames[i] = 理;
            }
            else if(len(&(s[ind]), "度")){
                fontNames[i] = 度;
            }
            else if(len(&(s[ind]), "的")){
                fontNames[i] = 的;
            }
            else if(len(&(s[ind]), "場")){
                fontNames[i] = 場;
            }
            else if(len(&(s[ind]), "良")){
                fontNames[i] = 良;
            }
            else if(len(&(s[ind]), "開")){
                fontNames[i] = 開;
            }
            else if(len(&(s[ind]), "部")){
                fontNames[i] = 部;
            }
            else if(len(&(s[ind]), "物")){
                fontNames[i] = 物;
            }
            else if(len(&(s[ind]), "原")){
                fontNames[i] = 原;
            }
            else if(len(&(s[ind]), "実")){
                fontNames[i] = 実;
            }
            else if(len(&(s[ind]), "様")){
                fontNames[i] = 様;
            }
            else if(len(&(s[ind]), "体")){
                fontNames[i] = 体;
            }
            else if(len(&(s[ind]), "通")){
                fontNames[i] = 通;
            }
            else if(len(&(s[ind]), "報")){
                fontNames[i] = 報;
            }
            else if(len(&(s[ind]), "金")){
                fontNames[i] = 金;
            }
            else if(len(&(s[ind]), "買")){
                fontNames[i] = 買;
            }
            else if(len(&(s[ind]), "家")){
                fontNames[i] = 家;
            }
            else if(len(&(s[ind]), "味")){
                fontNames[i] = 味;
            }
            else if(len(&(s[ind]), "長")){
                fontNames[i] = 長;
            }
            else if(len(&(s[ind]), "持")){
                fontNames[i] = 持;
            }
            else if(len(&(s[ind]), "性")){
                fontNames[i] = 性;
            }
            else if(len(&(s[ind]), "愛")){
                fontNames[i] = 愛;
            }
            else if(len(&(s[ind]), "用")){
                fontNames[i] = 用;
            }
            else if(len(&(s[ind]), "意")){
                fontNames[i] = 意;
            }
            else if(len(&(s[ind]), "々")){
                fontNames[i] = 繰り返し;
            }
            else if(len(&(s[ind]), "聞")){
                fontNames[i] = 聞;
            }
            else if(len(&(s[ind]), "俺")){
                fontNames[i] = 俺;
            }
            else if(len(&(s[ind]), "業")){
                fontNames[i] = 業;
            }
            else if(len(&(s[ind]), "名")){
                fontNames[i] = 名;
            }
            else if(len(&(s[ind]), "発")){
                fontNames[i] = 発;
            }
            else if(len(&(s[ind]), "無")){
                fontNames[i] = 無;
            }
            else if(len(&(s[ind]), "手")){
                fontNames[i] = 手;
            }
            else if(len(&(s[ind]), "来")){
                fontNames[i] = 来;
            }
            else if(len(&(s[ind]), "新")){
                fontNames[i] = 新;
            }
            else if(len(&(s[ind]), "月")){
                fontNames[i] = 月;
            }
            else if(len(&(s[ind]), "全")){
                fontNames[i] = 全;
            }
            else if(len(&(s[ind]), "地")){
                fontNames[i] = 地;
            }
            else if(len(&(s[ind]), "最")){
                fontNames[i] = 最;
            }
            else if(len(&(s[ind]), "電")){
                fontNames[i] = 電;
            }
            else if(len(&(s[ind]), "明")){
                fontNames[i] = 明;
            }
            else if(len(&(s[ind]), "楽")){
                fontNames[i] = 楽;
            }
            else if(len(&(s[ind]), "合")){
                fontNames[i] = 合;
            }
            else if(len(&(s[ind]), "感")){
                fontNames[i] = 感;
            }
            else if(len(&(s[ind]), "目")){
                fontNames[i] = 目;
            }
            else if(len(&(s[ind]), "食")){
                fontNames[i] = 食;
            }
            else if(len(&(s[ind]), "話")){
                fontNames[i] = 話;
            }
            else if(len(&(s[ind]), "作")){
                fontNames[i] = 作;
            }
            else if(len(&(s[ind]), "動")){
                fontNames[i] = 動;
            }
            else if(len(&(s[ind]), "寝")){
                fontNames[i] = 寝;
            }
            else if(len(&(s[ind]), "東")){
                fontNames[i] = 東;
            }
            else if(len(&(s[ind]), "定")){
                fontNames[i] = 定;
            }
            else if(len(&(s[ind]), "好")){
                fontNames[i] = 好;
            }
            else if(len(&(s[ind]), "後")){
                fontNames[i] = 後;
            }
            else if(len(&(s[ind]), "女")){
                fontNames[i] = 女;
            }
            else if(len(&(s[ind]), "知")){
                fontNames[i] = 知;
            }
            else if(len(&(s[ind]), "下")){
                fontNames[i] = 下;
            }
            else if(len(&(s[ind]), "回")){
                fontNames[i] = 回;
            }
            else if(len(&(s[ind]), "高")){
                fontNames[i] = 高;
            }
            else if(len(&(s[ind]), "者")){
                fontNames[i] = 者;
            }
            else if(len(&(s[ind]), "画")){
                fontNames[i] = 画;
            }
            else if(len(&(s[ind]), "薄")){
                fontNames[i] = 薄;
            }
            else if(len(&(s[ind]), "年")){
                fontNames[i] = 年;
            }
            else if(len(&(s[ind]), "思")){
                fontNames[i] = 思;
            }
            else if(len(&(s[ind]), "捕")){
                fontNames[i] = 捕;
            }
            else if(len(&(s[ind]), "行")){
                fontNames[i] = 行;
            }
            else if(len(&(s[ind]), "本")){
                fontNames[i] = 本;
            }
            else if(len(&(s[ind]), "学")){
                fontNames[i] = 学;
            }
            else if(len(&(s[ind]), "言")){
                fontNames[i] = 言;
            }
            else if(len(&(s[ind]), "国")){
                fontNames[i] = 国;
            }
            else if(len(&(s[ind]), "中")){
                fontNames[i] = 中;
            }
            else if(len(&(s[ind]), "分")){
                fontNames[i] = 分;
            }
            else if(len(&(s[ind]), "日")){
                fontNames[i] = 日;
            }
            else if(len(&(s[ind]), "人")){
                fontNames[i] = 人;
            }
            else if(len(&(s[ind]), "今")){
                fontNames[i] = 今;
            }
            else if(len(&(s[ind]), "折")){
                fontNames[i] = 折;
            }
            else if(len(&(s[ind]), "見")){
                fontNames[i] = 見;
            }
            else if(len(&(s[ind]), "気")){
                fontNames[i] = 気;
            }
            else if(len(&(s[ind]), "出")){
                fontNames[i] = 出;
            }
            else if(len(&(s[ind]), "一")){
                fontNames[i] = 一;
            }
            else if(len(&(s[ind]), "時")){
                fontNames[i] = 時;
            }
            else if(len(&(s[ind]), "燃")){
                fontNames[i] = 燃;
            }
            else if(len(&(s[ind]), "生")){
                fontNames[i] = 生;
            }
            else if(len(&(s[ind]), "間")){
                fontNames[i] = 間;
            }
            else if(len(&(s[ind]), "笑")){
                fontNames[i] = 笑;
            }
            else if(len(&(s[ind]), "子")){
                fontNames[i] = 子;
            }
            else if(len(&(s[ind]), "方")){
                fontNames[i] = 方;
            }
            else if(len(&(s[ind]), "自")){
                fontNames[i] = 自;
            }
            else if(len(&(s[ind]), "会")){
                fontNames[i] = 会;
            }
            else if(len(&(s[ind]), "前")){
                fontNames[i] = 前;
            }
            else if(len(&(s[ind]), "私")){
                fontNames[i] = 私;
            }
            else if(len(&(s[ind]), "何")){
                fontNames[i] = 何;
            }
            else if(len(&(s[ind]), "上")){
                fontNames[i] = 上;
            }
            else if(len(&(s[ind]), "入")){
                fontNames[i] = 入;
            }else if(len(&(s[i*3]), "、")){
                fontNames[i] = 句読点;
            }else if(len(&(s[i*3]), "・")){
                fontNames[i] = 一点;
            }else if(len(&(s[i*3]), "が")){
                fontNames[i] = が;
            }else if(len(&(s[i*3]), "ぎ")){
                fontNames[i] = ぎ;
            }else if(len(&(s[i*3]), "ぐ")){
                fontNames[i] = ぐ;
            }else if(len(&(s[i*3]), "げ")){
                fontNames[i] = げ;
            }else if(len(&(s[i*3]), "ご")){
                fontNames[i] = ご;
            }else if(len(&(s[i*3]), "ざ")){
                fontNames[i] = ざ;
            }else if(len(&(s[i*3]), "じ")){
                fontNames[i] = じ;
            }else if(len(&(s[i*3]), "ず")){
                fontNames[i] = ず;
            }else if(len(&(s[i*3]), "ぜ")){
                fontNames[i] = ぜ;
            }else if(len(&(s[i*3]), "ぞ")){
                fontNames[i] = ぞ;
            }else if(len(&(s[i*3]), "だ")){
                fontNames[i] = だ;
            }else if(len(&(s[i*3]), "ぢ")){
                fontNames[i] = ぢ;
            }else if(len(&(s[i*3]), "づ")){
                fontNames[i] = づ;
            }else if(len(&(s[i*3]), "で")){
                fontNames[i] = で;
            }else if(len(&(s[i*3]), "ど")){
                fontNames[i] = ど;
            }else if(len(&(s[i*3]), "ば")){
                fontNames[i] = ば;
            }else if(len(&(s[i*3]), "び")){
                fontNames[i] = び;
            }else if(len(&(s[i*3]), "ぶ")){
                fontNames[i] = ぶ;
            }else if(len(&(s[i*3]), "べ")){
                fontNames[i] = べ;
            }else if(len(&(s[i*3]), "ぼ")){
                fontNames[i] = ぼ;
            }else if(len(&(s[i*3]), "ぱ")){
                fontNames[i] = ぱ;
            }else if(len(&(s[i*3]), "ぴ")){
                fontNames[i] = ぴ;
            }else if(len(&(s[i*3]), "ぷ")){
                fontNames[i] = ぷ;
            }else if(len(&(s[i*3]), "ぺ")){
                fontNames[i] = ぺ;
            }else if(len(&(s[i*3]), "ぽ")){
                fontNames[i] = ぽ;
            }else if(len(&(s[i*3]), "ー")){
                fontNames[i] = ー;
            }else if(len(&(s[i*3]), "｜")){
                fontNames[i] = 縦棒;
            }else if(len(&(s[i*3]), "￥")){
                fontNames[i] = 円マーク;
            }else if(len(&(s[i*3]), "＝")){
                fontNames[i] = イコール;
            }else if(len(&(s[i*3]), "＆")){
                fontNames[i] = アンパサンド;
            }else if(len(&(s[i*3]), "陸")){
                fontNames[i] = 陸;
            }else if(len(&(s[i*3]), "汗")){
                fontNames[i] = 汗;
            }else if(len(&(s[i*3]), "詰")){
                fontNames[i] = 詰;
            }else if(len(&(s[i*3]), "懐")){
                fontNames[i] = 懐;
            }else if(len(&(s[i*3]), "委")){
                fontNames[i] = 委;
            }else if(len(&(s[i*3]), "羽")){
                fontNames[i] = 羽;
            }else if(len(&(s[i*3]), "港")){
                fontNames[i] = 港;
            }else if(len(&(s[i*3]), "癒")){
                fontNames[i] = 癒;
            }else if(len(&(s[i*3]), "厳")){
                fontNames[i] = 厳;
            }else if(len(&(s[i*3]), "怪")){
                fontNames[i] = 怪;
            }else if(len(&(s[i*3]), "券")){
                fontNames[i] = 券;
            }else if(len(&(s[i*3]), "宇")){
                fontNames[i] = 宇;
            }else if(len(&(s[i*3]), "照")){
                fontNames[i] = 照;
            }else if(len(&(s[i*3]), "縺")){
                fontNames[i] = 縺;
            }else if(len(&(s[i*3]), "繋")){
                fontNames[i] = 繋;
            }else if(len(&(s[i*3]), "永")){
                fontNames[i] = 永;
            }else if(len(&(s[i*3]), "燃")){
                fontNames[i] = 燃;
            }else if(len(&(s[i*3]), "寂")){
                fontNames[i] = 寂;
            }else if(len(&(s[i*3]), "泊")){
                fontNames[i] = 泊;
            }else if(len(&(s[i*3]), "杯")){
                fontNames[i] = 杯;
            }else if(len(&(s[i*3]), "幼")){
                fontNames[i] = 幼;
            }else if(len(&(s[i*3]), "肌")){
                fontNames[i] = 肌;
            }else if(len(&(s[i*3]), "閉")){
                fontNames[i] = 閉;
            }else if(len(&(s[i*3]), "荒")){
                fontNames[i] = 荒;
            }else if(len(&(s[i*3]), "争")){
                fontNames[i] = 争;
            }else if(len(&(s[i*3]), "悔")){
                fontNames[i] = 悔;
            }else if(len(&(s[i*3]), "婦")){
                fontNames[i] = 婦;
            }else if(len(&(s[i*3]), "才")){
                fontNames[i] = 才;
            }else if(len(&(s[i*3]), "己")){
                fontNames[i] = 己;
            }else if(len(&(s[i*3]), "刺")){
                fontNames[i] = 刺;
            }else if(len(&(s[i*3]), "借")){
                fontNames[i] = 借;
            }else if(len(&(s[i*3]), "闘")){
                fontNames[i] = 闘;
            }else if(len(&(s[i*3]), "祈")){
                fontNames[i] = 祈;
            }else if(len(&(s[i*3]), "魚")){
                fontNames[i] = 魚;
            }else if(len(&(s[i*3]), "標")){
                fontNames[i] = 標;
            }else if(len(&(s[i*3]), "林")){
                fontNames[i] = 林;
            }else if(len(&(s[i*3]), "博")){
                fontNames[i] = 博;
            }else if(len(&(s[i*3]), "留")){
                fontNames[i] = 留;
            }else if(len(&(s[i*3]), "憶")){
                fontNames[i] = 憶;
            }else if(len(&(s[i*3]), "干")){
                fontNames[i] = 干;
            }else if(len(&(s[i*3]), "齢")){
                fontNames[i] = 齢;
            }else if(len(&(s[i*3]), "兵")){
                fontNames[i] = 兵;
            }else if(len(&(s[i*3]), "章")){
                fontNames[i] = 章;
            }else if(len(&(s[i*3]), "央")){
                fontNames[i] = 央;
            }else if(len(&(s[i*3]), "障")){
                fontNames[i] = 障;
            }else if(len(&(s[i*3]), "典")){
                fontNames[i] = 典;
            }else if(len(&(s[i*3]), "呟")){
                fontNames[i] = 呟;
            }else if(len(&(s[i*3]), "診")){
                fontNames[i] = 診;
            }else if(len(&(s[i*3]), "伸")){
                fontNames[i] = 伸;
            }else if(len(&(s[i*3]), "農")){
                fontNames[i] = 農;
            }else if(len(&(s[i*3]), "順")){
                fontNames[i] = 順;
            }else if(len(&(s[i*3]), "枠")){
                fontNames[i] = 枠;
            }else if(len(&(s[i*3]), "詞")){
                fontNames[i] = 詞;
            }else if(len(&(s[i*3]), "船")){
                fontNames[i] = 船;
            }else if(len(&(s[i*3]), "旧")){
                fontNames[i] = 旧;
            }else if(len(&(s[i*3]), "即")){
                fontNames[i] = 即;
            }else if(len(&(s[i*3]), "豊")){
                fontNames[i] = 豊;
            }else if(len(&(s[i*3]), "寿")){
                fontNames[i] = 寿;
            }else if(len(&(s[i*3]), "也")){
                fontNames[i] = 也;
            }else if(len(&(s[i*3]), "宜")){
                fontNames[i] = 宜;
            }else if(len(&(s[i*3]), "樹")){
                fontNames[i] = 樹;
            }else if(len(&(s[i*3]), "到")){
                fontNames[i] = 到;
            }else if(len(&(s[i*3]), "六")){
                fontNames[i] = 六;
            }else if(len(&(s[i*3]), "徒")){
                fontNames[i] = 徒;
            }else if(len(&(s[i*3]), "’")){
                fontNames[i] = シングルクォーテーション;
            }else if(len(&(s[i*3]), "”")){
                fontNames[i] = ダブルクォーテーション;
            }else if(len(&(s[i*3]), "Ａ")){
                fontNames[i] = エー;
            }else if(len(&(s[i*3]), "Ｂ")){
                fontNames[i] = ビー;
            }else if(len(&(s[i*3]), "Ｃ")){
                fontNames[i] = シー;
            }else if(len(&(s[i*3]), "Ｄ")){
                fontNames[i] = ディー;
            }else if(len(&(s[i*3]), "Ｅ")){
                fontNames[i] = イー;
            }else if(len(&(s[i*3]), "Ｆ")){
                fontNames[i] = エフ;
            }else if(len(&(s[i*3]), "Ｇ")){
                fontNames[i] = ジー;
            }else if(len(&(s[i*3]), "Ｈ")){
                fontNames[i] = エイチ;
            }else if(len(&(s[i*3]), "Ｉ")){
                fontNames[i] = アイ;
            }else if(len(&(s[i*3]), "Ｊ")){
                fontNames[i] = ジェイ;
            }else if(len(&(s[i*3]), "Ｋ")){
                fontNames[i] = ケイ;
            }else if(len(&(s[i*3]), "Ｌ")){
                fontNames[i] = エル;
            }else if(len(&(s[i*3]), "Ｍ")){
                fontNames[i] = エム;
            }else if(len(&(s[i*3]), "Ｎ")){
                fontNames[i] = エヌ;
            }else if(len(&(s[i*3]), "Ｏ")){
                fontNames[i] = オー;
            }else if(len(&(s[i*3]), "Ｐ")){
                fontNames[i] = ピー;
            }else if(len(&(s[i*3]), "Ｑ")){
                fontNames[i] = キュー;
            }else if(len(&(s[i*3]), "Ｒ")){
                fontNames[i] = アール;
            }else if(len(&(s[i*3]), "Ｓ")){
                fontNames[i] = エス;
            }else if(len(&(s[i*3]), "Ｔ")){
                fontNames[i] = ティー;
            }else if(len(&(s[i*3]), "Ｕ")){
                fontNames[i] = ユー;
            }else if(len(&(s[i*3]), "Ｖ")){
                fontNames[i] = ブイ;
            }else if(len(&(s[i*3]), "Ｗ")){
                fontNames[i] = ダブリュー;
            }else if(len(&(s[i*3]), "Ｘ")){
                fontNames[i] = エクス;
            }else if(len(&(s[i*3]), "Ｙ")){
                fontNames[i] = ワイ;
            }else if(len(&(s[i*3]), "Ｚ")){
                fontNames[i] = ゼット;
            }else if(len(&(s[i*3]), "［")){
                fontNames[i] = 四角括弧初め;
            }else if(len(&(s[i*3]), "］")){
                fontNames[i] = 四角括弧閉じ;
            }else if(len(&(s[i*3]), "０")){
                fontNames[i] = ゼロ;
            }else if(len(&(s[i*3]), "１")){
                fontNames[i] = イチ;
            }else if(len(&(s[i*3]), "／")){
                fontNames[i] = スラッシュ;
            }else if(len(&(s[i*3]), "％")){
                fontNames[i] = パーセント;
            }else if(len(&(s[i*3]), "＄")){
                fontNames[i] = ドル;
            }else if(len(&(s[i*3]), "＃")){
                fontNames[i] = シャープ;
            }else if(len(&(s[i*3]), "＊")){
                fontNames[i] = アスタリスク;
            }else if(len(&(s[i*3]), "＋")){
                fontNames[i] = プラス;
            }else if(len(&(s[i*3]), "－")){
                fontNames[i] = マイナス;
            }else if(len(&(s[i*3]), "＠")){
                fontNames[i] = アットマーク;
            }else if(len(&(s[i*3]), "；")){
                fontNames[i] = セミコロン;
            }else if(len(&(s[i*3]), "：")){
                fontNames[i] = コロン;
            }else if(len(&(s[i*3]), "＜")){
                fontNames[i] = 角括弧初め;
            }else if(len(&(s[i*3]), "＞")){
                fontNames[i] = 角括弧終わり;
            }else if(len(&(s[i*3]), "２")){
                fontNames[i] = ニー;
            }else if(len(&(s[i*3]), "３")){
                fontNames[i] = サン;
            }else if(len(&(s[i*3]), "４")){
                fontNames[i] = シイ;
            }else if(len(&(s[i*3]), "５")){
                fontNames[i] = ゴオ;
            }else if(len(&(s[i*3]), "６")){
                fontNames[i] = ロク;
            }else if(len(&(s[i*3]), "７")){
                fontNames[i] = シチ;
            }else if(len(&(s[i*3]), "８")){
                fontNames[i] = ハチ;
            }else if(len(&(s[i*3]), "９")){
                fontNames[i] = キュウ;
            }else if(len(&(s[i*3]), "衣")){
                fontNames[i] = 衣;
            }else if(len(&(s[i*3]), "既")){
                fontNames[i] = 既;
            }else if(len(&(s[i*3]), "坊")){
                fontNames[i] = 坊;
            }else if(len(&(s[i*3]), "房")){
                fontNames[i] = 房;
            }else if(len(&(s[i*3]), "臭")){
                fontNames[i] = 臭;
            }else if(len(&(s[i*3]), "酷")){
                fontNames[i] = 酷;
            }else if(len(&(s[i*3]), "秒")){
                fontNames[i] = 秒;
            }else if(len(&(s[i*3]), "養")){
                fontNames[i] = 養;
            }else if(len(&(s[i*3]), "腰")){
                fontNames[i] = 腰;
            }else if(len(&(s[i*3]), "滅")){
                fontNames[i] = 滅;
            }else if(len(&(s[i*3]), "姫")){
                fontNames[i] = 姫;
            }else if(len(&(s[i*3]), "輪")){
                fontNames[i] = 輪;
            }else if(len(&(s[i*3]), "庭")){
                fontNames[i] = 庭;
            }else if(len(&(s[i*3]), "勘")){
                fontNames[i] = 勘;
            }else if(len(&(s[i*3]), "茨")){
                fontNames[i] = 茨;
            }else if(len(&(s[i*3]), "廃")){
                fontNames[i] = 廃;
            }else if(len(&(s[i*3]), "握")){
                fontNames[i] = 握;
            }else if(len(&(s[i*3]), "露")){
                fontNames[i] = 露;
            }else if(len(&(s[i*3]), "功")){
                fontNames[i] = 功;
            }else if(len(&(s[i*3]), "骨")){
                fontNames[i] = 骨;
            }else if(len(&(s[i*3]), "妻")){
                fontNames[i] = 妻;
            }else if(len(&(s[i*3]), "領")){
                fontNames[i] = 領;
            }else if(len(&(s[i*3]), "勇")){
                fontNames[i] = 勇;
            }else if(len(&(s[i*3]), "倉")){
                fontNames[i] = 倉;
            }else if(len(&(s[i*3]), "老")){
                fontNames[i] = 老;
            }else if(len(&(s[i*3]), "巨")){
                fontNames[i] = 巨;
            }else if(len(&(s[i*3]), "創")){
                fontNames[i] = 創;
            }else if(len(&(s[i*3]), "壁")){
                fontNames[i] = 壁;
            }else if(len(&(s[i*3]), "掃")){
                fontNames[i] = 掃;
            }else if(len(&(s[i*3]), "奇")){
                fontNames[i] = 奇;
            }else if(len(&(s[i*3]), "咲")){
                fontNames[i] = 咲;
            }else if(len(&(s[i*3]), "跡")){
                fontNames[i] = 跡;
            }else if(len(&(s[i*3]), "剣")){
                fontNames[i] = 剣;
            }else if(len(&(s[i*3]), "誤")){
                fontNames[i] = 誤;
            }else if(len(&(s[i*3]), "濃")){
                fontNames[i] = 濃;
            }else if(len(&(s[i*3]), "鏡")){
                fontNames[i] = 鏡;
            }else if(len(&(s[i*3]), "漢")){
                fontNames[i] = 漢;
            }else if(len(&(s[i*3]), "採")){
                fontNames[i] = 採;
            }else if(len(&(s[i*3]), "抗")){
                fontNames[i] = 抗;
            }else if(len(&(s[i*3]), "遣")){
                fontNames[i] = 遣;
            }else if(len(&(s[i*3]), "彡")){
                fontNames[i] = 彡;
            }else if(len(&(s[i*3]), "崩")){
                fontNames[i] = 崩;
            }else if(len(&(s[i*3]), "扱")){
                fontNames[i] = 扱;
            }else if(len(&(s[i*3]), "菓")){
                fontNames[i] = 菓;
            }else if(len(&(s[i*3]), "騒")){
                fontNames[i] = 騒;
            }else if(len(&(s[i*3]), "属")){
                fontNames[i] = 属;
            }else if(len(&(s[i*3]), "腕")){
                fontNames[i] = 腕;
            }else if(len(&(s[i*3]), "築")){
                fontNames[i] = 築;
            }else if(len(&(s[i*3]), "賛")){
                fontNames[i] = 賛;
            }else if(len(&(s[i*3]), "裁")){
                fontNames[i] = 裁;
            }else if(len(&(s[i*3]), "固")){
                fontNames[i] = 固;
            }else if(len(&(s[i*3]), "狂")){
                fontNames[i] = 狂;
            }else if(len(&(s[i*3]), "杉")){
                fontNames[i] = 杉;
            }else if(len(&(s[i*3]), "削")){
                fontNames[i] = 削;
            }else if(len(&(s[i*3]), "紅")){
                fontNames[i] = 紅;
            }else if(len(&(s[i*3]), "梅")){
                fontNames[i] = 梅;
            }else if(len(&(s[i*3]), "縄")){
                fontNames[i] = 縄;
            }else if(len(&(s[i*3]), "幕")){
                fontNames[i] = 幕;
            }else if(len(&(s[i*3]), "候")){
                fontNames[i] = 候;
            }else if(len(&(s[i*3]), "底")){
                fontNames[i] = 底;
            }else if(len(&(s[i*3]), "瀬")){
                fontNames[i] = 瀬;
            }else if(len(&(s[i*3]), "束")){
                fontNames[i] = 束;
            }else if(len(&(s[i*3]), "欠")){
                fontNames[i] = 欠;
            }else if(len(&(s[i*3]), "競")){
                fontNames[i] = 競;
            }else if(len(&(s[i*3]), "叫")){
                fontNames[i] = 叫;
            }else if(len(&(s[i*3]), "益")){
                fontNames[i] = 益;
            }else if(len(&(s[i*3]), "裸")){
                fontNames[i] = 裸;
            }else if(len(&(s[i*3]), "液")){
                fontNames[i] = 液;
            }else if(len(&(s[i*3]), "黄")){
                fontNames[i] = 黄;
            }else if(len(&(s[i*3]), "紀")){
                fontNames[i] = 紀;
            }else if(len(&(s[i*3]), "踏")){
                fontNames[i] = 踏;
            }else if(len(&(s[i*3]), "討")){
                fontNames[i] = 討;
            }else if(len(&(s[i*3]), "鮮")){
                fontNames[i] = 鮮;
            }else if(len(&(s[i*3]), "厚")){
                fontNames[i] = 厚;
            }else if(len(&(s[i*3]), "暮")){
                fontNames[i] = 暮;
            }else if(len(&(s[i*3]), "督")){
                fontNames[i] = 督;
            }else if(len(&(s[i*3]), "貸")){
                fontNames[i] = 貸;
            }else if(len(&(s[i*3]), "吐")){
                fontNames[i] = 吐;
            }else if(len(&(s[i*3]), "耐")){
                fontNames[i] = 耐;
            }else if(len(&(s[i*3]), "締")){
                fontNames[i] = 締;
            }else if(len(&(s[i*3]), "窓")){
                fontNames[i] = 窓;
            }else if(len(&(s[i*3]), "七")){
                fontNames[i] = 七;
            }else if(len(&(s[i*3]), "及")){
                fontNames[i] = 及;
            }else if(len(&(s[i*3]), "季")){
                fontNames[i] = 季;
            }else if(len(&(s[i*3]), "徹")){
                fontNames[i] = 徹;
            }else if(len(&(s[i*3]), "閣")){
                fontNames[i] = 閣;
            }else if(len(&(s[i*3]), "柄")){
                fontNames[i] = 柄;
            }else if(len(&(s[i*3]), "雄")){
                fontNames[i] = 雄;
            }else if(len(&(s[i*3]), "群")){
                fontNames[i] = 群;
            }else if(len(&(s[i*3]), "竹")){
                fontNames[i] = 竹;
            }else if(len(&(s[i*3]), "盤")){
                fontNames[i] = 盤;
            }else if(len(&(s[i*3]), "批")){
                fontNames[i] = 批;
            }else if(len(&(s[i*3]), "豪")){
                fontNames[i] = 豪;
            }else if(len(&(s[i*3]), "損")){
                fontNames[i] = 損;
            }else if(len(&(s[i*3]), "臨")){
                fontNames[i] = 臨;
            }else if(len(&(s[i*3]), "黙")){
                fontNames[i] = 黙;
            }else if(len(&(s[i*3]), "棒")){
                fontNames[i] = 棒;
            }else if(len(&(s[i*3]), "踊")){
                fontNames[i] = 踊;
            }else if(len(&(s[i*3]), "敬")){
                fontNames[i] = 敬;
            }else if(len(&(s[i*3]), "圏")){
                fontNames[i] = 圏;
            }else if(len(&(s[i*3]), "句")){
                fontNames[i] = 句;
            }else if(len(&(s[i*3]), "庁")){
                fontNames[i] = 庁;
            }else if(len(&(s[i*3]), "縁")){
                fontNames[i] = 縁;
            }else if(len(&(s[i*3]), "龍")){
                fontNames[i] = 龍;
            }else if(len(&(s[i*3]), "毒")){
                fontNames[i] = 毒;
            }else if(len(&(s[i*3]), "尻")){
                fontNames[i] = 尻;
            }else if(len(&(s[i*3]), "択")){
                fontNames[i] = 択;
            }else if(len(&(s[i*3]), "乾")){
                fontNames[i] = 乾;
            }else if(len(&(s[i*3]), "履")){
                fontNames[i] = 履;
            }else if(len(&(s[i*3]), "革")){
                fontNames[i] = 革;
            }else if(len(&(s[i*3]), "織")){
                fontNames[i] = 織;
            }else if(len(&(s[i*3]), "浦")){
                fontNames[i] = 浦;
            }else if(len(&(s[i*3]), "至")){
                fontNames[i] = 至;
            }else if(len(&(s[i*3]), "契")){
                fontNames[i] = 契;
            }else if(len(&(s[i*3]), "徳")){
                fontNames[i] = 徳;
            }else if(len(&(s[i*3]), "塗")){
                fontNames[i] = 塗;
            }else if(len(&(s[i*3]), "訴")){
                fontNames[i] = 訴;
            }else if(len(&(s[i*3]), "炎")){
                fontNames[i] = 炎;
            }else if(len(&(s[i*3]), "称")){
                fontNames[i] = 称;
            }else if(len(&(s[i*3]), "塩")){
                fontNames[i] = 塩;
            }else if(len(&(s[i*3]), "某")){
                fontNames[i] = 某;
            }else if(len(&(s[i*3]), "肩")){
                fontNames[i] = 肩;
            }else if(len(&(s[i*3]), "挨")){
                fontNames[i] = 挨;
            }else if(len(&(s[i*3]), "拶")){
                fontNames[i] = 拶;
            }else if(len(&(s[i*3]), "栄")){
                fontNames[i] = 栄;
            }else if(len(&(s[i*3]), "魂")){
                fontNames[i] = 魂;
            }else if(len(&(s[i*3]), "浴")){
                fontNames[i] = 浴;
            }else if(len(&(s[i*3]), "床")){
                fontNames[i] = 床;
            }else if(len(&(s[i*3]), "操")){
                fontNames[i] = 操;
            }else if(len(&(s[i*3]), "趣")){
                fontNames[i] = 趣;
            }else if(len(&(s[i*3]), "盗")){
                fontNames[i] = 盗;
            }else if(len(&(s[i*3]), "衝")){
                fontNames[i] = 衝;
            }else if(len(&(s[i*3]), "訪")){
                fontNames[i] = 訪;
            }else if(len(&(s[i*3]), "童")){
                fontNames[i] = 童;
            }else if(len(&(s[i*3]), "焦")){
                fontNames[i] = 焦;
            }else if(len(&(s[i*3]), "則")){
                fontNames[i] = 則;
            }else if(len(&(s[i*3]), "聖")){
                fontNames[i] = 聖;
            }else if(len(&(s[i*3]), "垢")){
                fontNames[i] = 垢;
            }else if(len(&(s[i*3]), "複")){
                fontNames[i] = 複;
            }else if(len(&(s[i*3]), "艸")){
                fontNames[i] = 艸;
            }else if(len(&(s[i*3]), "籍")){
                fontNames[i] = 籍;
            }else if(len(&(s[i*3]), "緑")){
                fontNames[i] = 緑;
            }else if(len(&(s[i*3]), "秀")){
                fontNames[i] = 秀;
            }else if(len(&(s[i*3]), "魅")){
                fontNames[i] = 魅;
            }else if(len(&(s[i*3]), "審")){
                fontNames[i] = 審;
            }else if(len(&(s[i*3]), "穴")){
                fontNames[i] = 穴;
            }else if(len(&(s[i*3]), "漏")){
                fontNames[i] = 漏;
            }else if(len(&(s[i*3]), "副")){
                fontNames[i] = 副;
            }else if(len(&(s[i*3]), "奏")){
                fontNames[i] = 奏;
            }else if(len(&(s[i*3]), "甲")){
                fontNames[i] = 甲;
            }else if(len(&(s[i*3]), "砂")){
                fontNames[i] = 砂;
            }else if(len(&(s[i*3]), "鍋")){
                fontNames[i] = 鍋;
            }else if(len(&(s[i*3]), "雲")){
                fontNames[i] = 雲;
            }else if(len(&(s[i*3]), "宝")){
                fontNames[i] = 宝;
            }else if(len(&(s[i*3]), "矢")){
                fontNames[i] = 矢;
            }else if(len(&(s[i*3]), "宙")){
                fontNames[i] = 宙;
            }else if(len(&(s[i*3]), "慎")){
                fontNames[i] = 慎;
            }else if(len(&(s[i*3]), "献")){
                fontNames[i] = 献;
            }else if(len(&(s[i*3]), "貼")){
                fontNames[i] = 貼;
            }else if(len(&(s[i*3]), "狙")){
                fontNames[i] = 狙;
            }else if(len(&(s[i*3]), "汁")){
                fontNames[i] = 汁;
            }else if(len(&(s[i*3]), "勧")){
                fontNames[i] = 勧;
            }else if(len(&(s[i*3]), "双")){
                fontNames[i] = 双;
            }else if(len(&(s[i*3]), "殿")){
                fontNames[i] = 殿;
            }else if(len(&(s[i*3]), "努")){
                fontNames[i] = 努;
            }else if(len(&(s[i*3]), "鈴")){
                fontNames[i] = 鈴;
            }else if(len(&(s[i*3]), "湾")){
                fontNames[i] = 湾;
            }else if(len(&(s[i*3]), "枝")){
                fontNames[i] = 枝;
            }else if(len(&(s[i*3]), "諦")){
                fontNames[i] = 諦;
            }else if(len(&(s[i*3]), "遺")){
                fontNames[i] = 遺;
            }else if(len(&(s[i*3]), "奮")){
                fontNames[i] = 奮;
            }else if(len(&(s[i*3]), "濯")){
                fontNames[i] = 濯;
            }else if(len(&(s[i*3]), "包")){
                fontNames[i] = 包;
            }else if(len(&(s[i*3]), "凍")){
                fontNames[i] = 凍;
            }else if(len(&(s[i*3]), "靴")){
                fontNames[i] = 靴;
            }else if(len(&(s[i*3]), "鑑")){
                fontNames[i] = 鑑;
            }else if(len(&(s[i*3]), "嵐")){
                fontNames[i] = 嵐;
            }else if(len(&(s[i*3]), "謎")){
                fontNames[i] = 謎;
            }else if(len(&(s[i*3]), "著")){
                fontNames[i] = 著;
            }else if(len(&(s[i*3]), "雰")){
                fontNames[i] = 雰;
            }else if(len(&(s[i*3]), "埋")){
                fontNames[i] = 埋;
            }else if(len(&(s[i*3]), "霊")){
                fontNames[i] = 霊;
            }else if(len(&(s[i*3]), "幅")){
                fontNames[i] = 幅;
            }else if(len(&(s[i*3]), "依")){
                fontNames[i] = 依;
            }else if(len(&(s[i*3]), "岸")){
                fontNames[i] = 岸;
            }else if(len(&(s[i*3]), "昇")){
                fontNames[i] = 昇;
            }else if(len(&(s[i*3]), "叩")){
                fontNames[i] = 叩;
            }else if(len(&(s[i*3]), "拠")){
                fontNames[i] = 拠;
            }else if(len(&(s[i*3]), "舎")){
                fontNames[i] = 舎;
            }else if(len(&(s[i*3]), "徴")){
                fontNames[i] = 徴;
            }else if(len(&(s[i*3]), "輝")){
                fontNames[i] = 輝;
            }else if(len(&(s[i*3]), "剤")){
                fontNames[i] = 剤;
            }else if(len(&(s[i*3]), "免")){
                fontNames[i] = 免;
            }else if(len(&(s[i*3]), "繰")){
                fontNames[i] = 繰;
            }else if(len(&(s[i*3]), "熊")){
                fontNames[i] = 熊;
            }else if(len(&(s[i*3]), "煙")){
                fontNames[i] = 煙;
            }else if(len(&(s[i*3]), "償")){
                fontNames[i] = 償;
            }else if(len(&(s[i*3]), "巳")){
                fontNames[i] = 巳;
            }else if(len(&(s[i*3]), "憩")){
                fontNames[i] = 憩;
            }else if(len(&(s[i*3]), "均")){
                fontNames[i] = 均;
            }else if(len(&(s[i*3]), "煮")){
                fontNames[i] = 煮;
            }else if(len(&(s[i*3]), "挑")){
                fontNames[i] = 挑;
            }else if(len(&(s[i*3]), "陰")){
                fontNames[i] = 陰;
            }else if(len(&(s[i*3]), "虫")){
                fontNames[i] = 虫;
            }else if(len(&(s[i*3]), "胃")){
                fontNames[i] = 胃;
            }else if(len(&(s[i*3]), "塚")){
                fontNames[i] = 塚;
            }else if(len(&(s[i*3]), "埼")){
                fontNames[i] = 埼;
            }else if(len(&(s[i*3]), "痴")){
                fontNames[i] = 痴;
            }else if(len(&(s[i*3]), "皮")){
                fontNames[i] = 皮;
            }else if(len(&(s[i*3]), "潟")){
                fontNames[i] = 潟;
            }else if(len(&(s[i*3]), "悟")){
                fontNames[i] = 悟;
            }else if(len(&(s[i*3]), "喋")){
                fontNames[i] = 喋;
            }else if(len(&(s[i*3]), "飼")){
                fontNames[i] = 飼;
            }else if(len(&(s[i*3]), "浅")){
                fontNames[i] = 浅;
            }else if(len(&(s[i*3]), "従")){
                fontNames[i] = 従;
            }else if(len(&(s[i*3]), "須")){
                fontNames[i] = 須;
            }else if(len(&(s[i*3]), "灯")){
                fontNames[i] = 灯;
            }else if(len(&(s[i*3]), "阿")){
                fontNames[i] = 阿;
            }else if(len(&(s[i*3]), "釣")){
                fontNames[i] = 釣;
            }else if(len(&(s[i*3]), "易")){
                fontNames[i] = 易;
            }else if(len(&(s[i*3]), "癖")){
                fontNames[i] = 癖;
            }else if(len(&(s[i*3]), "距")){
                fontNames[i] = 距;
            }else if(len(&(s[i*3]), "筆")){
                fontNames[i] = 筆;
            }else if(len(&(s[i*3]), "之")){
                fontNames[i] = 之;
            }else if(len(&(s[i*3]), "融")){
                fontNames[i] = 融;
            }else if(len(&(s[i*3]), "智")){
                fontNames[i] = 智;
            }else if(len(&(s[i*3]), "慮")){
                fontNames[i] = 慮;
            }else if(len(&(s[i*3]), "縮")){
                fontNames[i] = 縮;
            }else if(len(&(s[i*3]), "沼")){
                fontNames[i] = 沼;
            }else if(len(&(s[i*3]), "粛")){
                fontNames[i] = 粛;
            }else if(len(&(s[i*3]), "植")){
                fontNames[i] = 植;
            }else if(len(&(s[i*3]), "拝")){
                fontNames[i] = 拝;
            }else if(len(&(s[i*3]), "輸")){
                fontNames[i] = 輸;
            }else if(len(&(s[i*3]), "襲")){
                fontNames[i] = 襲;
            }else if(len(&(s[i*3]), "熟")){
                fontNames[i] = 熟;
            }else if(len(&(s[i*3]), "迫")){
                fontNames[i] = 迫;
            }else if(len(&(s[i*3]), "豚")){
                fontNames[i] = 豚;
            }else if(len(&(s[i*3]), "孫")){
                fontNames[i] = 孫;
            }else if(len(&(s[i*3]), "仏")){
                fontNames[i] = 仏;
            }else if(len(&(s[i*3]), "冊")){
                fontNames[i] = 冊;
            }else if(len(&(s[i*3]), "績")){
                fontNames[i] = 績;
            }else if(len(&(s[i*3]), "奪")){
                fontNames[i] = 奪;
            }else if(len(&(s[i*3]), "看")){
                fontNames[i] = 看;
            }else if(len(&(s[i*3]), "舗")){
                fontNames[i] = 舗;
            }else if(len(&(s[i*3]), "尽")){
                fontNames[i] = 尽;
            }else if(len(&(s[i*3]), "羨")){
                fontNames[i] = 羨;
            }else if(len(&(s[i*3]), "揃")){
                fontNames[i] = 揃;
            }else if(len(&(s[i*3]), "炉")){
                fontNames[i] = 炉;
            }else if(len(&(s[i*3]), "炊")){
                fontNames[i] = 炊;
            }else if(len(&(s[i*3]), "衆")){
                fontNames[i] = 衆;
            }else if(len(&(s[i*3]), "珍")){
                fontNames[i] = 珍;
            }else if(len(&(s[i*3]), "躍")){
                fontNames[i] = 躍;
            }else if(len(&(s[i*3]), "尊")){
                fontNames[i] = 尊;
            }else if(len(&(s[i*3]), "律")){
                fontNames[i] = 律;
            }else if(len(&(s[i*3]), "酸")){
                fontNames[i] = 酸;
            }else if(len(&(s[i*3]), "郷")){
                fontNames[i] = 郷;
            }else if(len(&(s[i*3]), "臣")){
                fontNames[i] = 臣;
            }else if(len(&(s[i*3]), "逮")){
                fontNames[i] = 逮;
            }else if(len(&(s[i*3]), "承")){
                fontNames[i] = 承;
            }else if(len(&(s[i*3]), "喉")){
                fontNames[i] = 喉;
            }else if(len(&(s[i*3]), "潰")){
                fontNames[i] = 潰;
            }else if(len(&(s[i*3]), "闇")){
                fontNames[i] = 闇;
            }else if(len(&(s[i*3]), "褒")){
                fontNames[i] = 褒;
            }else if(len(&(s[i*3]), "卵")){
                fontNames[i] = 卵;
            }else if(len(&(s[i*3]), "晒")){
                fontNames[i] = 晒;
            }else if(len(&(s[i*3]), "幌")){
                fontNames[i] = 幌;
            }else if(len(&(s[i*3]), "懸")){
                fontNames[i] = 懸;
            }else if(len(&(s[i*3]), "宗")){
                fontNames[i] = 宗;
            }else if(len(&(s[i*3]), "鬱")){
                fontNames[i] = 鬱;
            }else if(len(&(s[i*3]), "厨")){
                fontNames[i] = 厨;
            }else if(len(&(s[i*3]), "範")){
                fontNames[i] = 範;
            }else if(len(&(s[i*3]), "令")){
                fontNames[i] = 令;
            }else if(len(&(s[i*3]), "帳")){
                fontNames[i] = 帳;
            }else if(len(&(s[i*3]), "粧")){
                fontNames[i] = 粧;
            }else if(len(&(s[i*3]), "添")){
                fontNames[i] = 添;
            }else if(len(&(s[i*3]), "層")){
                fontNames[i] = 層;
            }else if(len(&(s[i*3]), "愚")){
                fontNames[i] = 愚;
            }else if(len(&(s[i*3]), "獲")){
                fontNames[i] = 獲;
            }else if(len(&(s[i*3]), "喫")){
                fontNames[i] = 喫;
            }else if(len(&(s[i*3]), "偉")){
                fontNames[i] = 偉;
            }else if(len(&(s[i*3]), "妖")){
                fontNames[i] = 妖;
            }else if(len(&(s[i*3]), "麺")){
                fontNames[i] = 麺;
            }else if(len(&(s[i*3]), "脚")){
                fontNames[i] = 脚;
            }else if(len(&(s[i*3]), "帝")){
                fontNames[i] = 帝;
            }else if(len(&(s[i*3]), "却")){
                fontNames[i] = 却;
            }else if(len(&(s[i*3]), "飽")){
                fontNames[i] = 飽;
            }else if(len(&(s[i*3]), "諸")){
                fontNames[i] = 諸;
            }else if(len(&(s[i*3]), "刑")){
                fontNames[i] = 刑;
            }else if(len(&(s[i*3]), "滞")){
                fontNames[i] = 滞;
            }else if(len(&(s[i*3]), "唯")){
                fontNames[i] = 唯;
            }else if(len(&(s[i*3]), "譲")){
                fontNames[i] = 譲;
            }else if(len(&(s[i*3]), "暑")){
                fontNames[i] = 暑;
            }else if(len(&(s[i*3]), "駆")){
                fontNames[i] = 駆;
            }else if(len(&(s[i*3]), "狩")){
                fontNames[i] = 狩;
            }else if(len(&(s[i*3]), "署")){
                fontNames[i] = 署;
            }else if(len(&(s[i*3]), "貧")){
                fontNames[i] = 貧;
            }else if(len(&(s[i*3]), "呑")){
                fontNames[i] = 呑;
            }else if(len(&(s[i*3]), "陣")){
                fontNames[i] = 陣;
            }else if(len(&(s[i*3]), "透")){
                fontNames[i] = 透;
            }else if(len(&(s[i*3]), "稲")){
                fontNames[i] = 稲;
            }else if(len(&(s[i*3]), "亀")){
                fontNames[i] = 亀;
            }else if(len(&(s[i*3]), "噂")){
                fontNames[i] = 噂;
            }else if(len(&(s[i*3]), "幻")){
                fontNames[i] = 幻;
            }else if(len(&(s[i*3]), "忍")){
                fontNames[i] = 忍;
            }else if(len(&(s[i*3]), "彦")){
                fontNames[i] = 彦;
            }else if(len(&(s[i*3]), "皇")){
                fontNames[i] = 皇;
            }else if(len(&(s[i*3]), "嬢")){
                fontNames[i] = 嬢;
            }else if(len(&(s[i*3]), "氷")){
                fontNames[i] = 氷;
            }else if(len(&(s[i*3]), "桃")){
                fontNames[i] = 桃;
            }else if(len(&(s[i*3]), "揚")){
                fontNames[i] = 揚;
            }else if(len(&(s[i*3]), "昭")){
                fontNames[i] = 昭;
            }else if(len(&(s[i*3]), "溜")){
                fontNames[i] = 溜;
            }else if(len(&(s[i*3]), "仁")){
                fontNames[i] = 仁;
            }else if(len(&(s[i*3]), "彩")){
                fontNames[i] = 彩;
            }else if(len(&(s[i*3]), "封")){
                fontNames[i] = 封;
            }else if(len(&(s[i*3]), "磨")){
                fontNames[i] = 磨;
            }else if(len(&(s[i*3]), "析")){
                fontNames[i] = 析;
            }else if(len(&(s[i*3]), "殴")){
                fontNames[i] = 殴;
            }else if(len(&(s[i*3]), "巡")){
                fontNames[i] = 巡;
            }else if(len(&(s[i*3]), "執")){
                fontNames[i] = 執;
            }else if(len(&(s[i*3]), "棚")){
                fontNames[i] = 棚;
            }else if(len(&(s[i*3]), "痩")){
                fontNames[i] = 痩;
            }else if(len(&(s[i*3]), "偽")){
                fontNames[i] = 偽;
            }else if(len(&(s[i*3]), "妊")){
                fontNames[i] = 妊;
            }else if(len(&(s[i*3]), "竜")){
                fontNames[i] = 竜;
            }else if(len(&(s[i*3]), "核")){
                fontNames[i] = 核;
            }else if(len(&(s[i*3]), "還")){
                fontNames[i] = 還;
            }else if(len(&(s[i*3]), "敷")){
                fontNames[i] = 敷;
            }else if(len(&(s[i*3]), "航")){
                fontNames[i] = 航;
            }else if(len(&(s[i*3]), "如")){
                fontNames[i] = 如;
            }else if(len(&(s[i*3]), "獄")){
                fontNames[i] = 獄;
            }else if(len(&(s[i*3]), "飾")){
                fontNames[i] = 飾;
            }else if(len(&(s[i*3]), "哀")){
                fontNames[i] = 哀;
            }else if(len(&(s[i*3]), "貯")){
                fontNames[i] = 貯;
            }else if(len(&(s[i*3]), "控")){
                fontNames[i] = 控;
            }else if(len(&(s[i*3]), "滑")){
                fontNames[i] = 滑;
            }else if(len(&(s[i*3]), "維")){
                fontNames[i] = 維;
            }else if(len(&(s[i*3]), "誠")){
                fontNames[i] = 誠;
            }else if(len(&(s[i*3]), "皿")){
                fontNames[i] = 皿;
            }else if(len(&(s[i*3]), "丼")){
                fontNames[i] = 丼;
            }else if(len(&(s[i*3]), "針")){
                fontNames[i] = 針;
            }else if(len(&(s[i*3]), "拾")){
                fontNames[i] = 拾;
            }else if(len(&(s[i*3]), "孤")){
                fontNames[i] = 孤;
            }else if(len(&(s[i*3]), "沈")){
                fontNames[i] = 沈;
            }else if(len(&(s[i*3]), "噌")){
                fontNames[i] = 噌;
            }else if(len(&(s[i*3]), "僚")){
                fontNames[i] = 僚;
            }else if(len(&(s[i*3]), "梨")){
                fontNames[i] = 梨;
            }else if(len(&(s[i*3]), "較")){
                fontNames[i] = 較;
            }else if(len(&(s[i*3]), "糖")){
                fontNames[i] = 糖;
            }else if(len(&(s[i*3]), "沙")){
                fontNames[i] = 沙;
            }else if(len(&(s[i*3]), "拒")){
                fontNames[i] = 拒;
            }else if(len(&(s[i*3]), "遇")){
                fontNames[i] = 遇;
            }else if(len(&(s[i*3]), "臓")){
                fontNames[i] = 臓;
            }else if(len(&(s[i*3]), "摘")){
                fontNames[i] = 摘;
            }else if(len(&(s[i*3]), "塾")){
                fontNames[i] = 塾;
            }else if(len(&(s[i*3]), "郡")){
                fontNames[i] = 郡;
            }else if(len(&(s[i*3]), "堀")){
                fontNames[i] = 堀;
            }else if(len(&(s[i*3]), "祖")){
                fontNames[i] = 祖;
            }else if(len(&(s[i*3]), "貨")){
                fontNames[i] = 貨;
            }else if(len(&(s[i*3]), "羅")){
                fontNames[i] = 羅;
            }else if(len(&(s[i*3]), "枕")){
                fontNames[i] = 枕;
            }else if(len(&(s[i*3]), "励")){
                fontNames[i] = 励;
            }else if(len(&(s[i*3]), "刷")){
                fontNames[i] = 刷;
            }else if(len(&(s[i*3]), "璧")){
                fontNames[i] = 璧;
            }else if(len(&(s[i*3]), "偏")){
                fontNames[i] = 偏;
            }else if(len(&(s[i*3]), "沿")){
                fontNames[i] = 沿;
            }else if(len(&(s[i*3]), "隆")){
                fontNames[i] = 隆;
            }else if(len(&(s[i*3]), "兆")){
                fontNames[i] = 兆;
            }else if(len(&(s[i*3]), "匂")){
                fontNames[i] = 匂;
            }else if(len(&(s[i*3]), "雷")){
                fontNames[i] = 雷;
            }else if(len(&(s[i*3]), "噛")){
                fontNames[i] = 噛;
            }else if(len(&(s[i*3]), "患")){
                fontNames[i] = 患;
            }else if(len(&(s[i*3]), "澤")){
                fontNames[i] = 澤;
            }else if(len(&(s[i*3]), "柔")){
                fontNames[i] = 柔;
            }else if(len(&(s[i*3]), "紫")){
                fontNames[i] = 紫;
            }else if(len(&(s[i*3]), "唱")){
                fontNames[i] = 唱;
            }else if(len(&(s[i*3]), "匹")){
                fontNames[i] = 匹;
            }else if(len(&(s[i*3]), "鍵")){
                fontNames[i] = 鍵;
            }else if(len(&(s[i*3]), "惚")){
                fontNames[i] = 惚;
            }else if(len(&(s[i*3]), "概")){
                fontNames[i] = 概;
            }else if(len(&(s[i*3]), "雅")){
                fontNames[i] = 雅;
            }else if(len(&(s[i*3]), "亜")){
                fontNames[i] = 亜;
            }else if(len(&(s[i*3]), "棄")){
                fontNames[i] = 棄;
            }else if(len(&(s[i*3]), "屈")){
                fontNames[i] = 屈;
            }else if(len(&(s[i*3]), "寸")){
                fontNames[i] = 寸;
            }else if(len(&(s[i*3]), "溶")){
                fontNames[i] = 溶;
            }else if(len(&(s[i*3]), "只")){
                fontNames[i] = 只;
            }else if(len(&(s[i*3]), "缶")){
                fontNames[i] = 缶;
            }else if(len(&(s[i*3]), "狭")){
                fontNames[i] = 狭;
            }else if(len(&(s[i*3]), "浪")){
                fontNames[i] = 浪;
            }else if(len(&(s[i*3]), "漁")){
                fontNames[i] = 漁;
            }else if(len(&(s[i*3]), "賢")){
                fontNames[i] = 賢;
            }else if(len(&(s[i*3]), "芝")){
                fontNames[i] = 芝;
            }else if(len(&(s[i*3]), "潮")){
                fontNames[i] = 潮;
            }else if(len(&(s[i*3]), "侵")){
                fontNames[i] = 侵;
            }else if(len(&(s[i*3]), "浄")){
                fontNames[i] = 浄;
            }else if(len(&(s[i*3]), "匠")){
                fontNames[i] = 匠;
            }else if(len(&(s[i*3]), "駐")){
                fontNames[i] = 駐;
            }else if(len(&(s[i*3]), "掘")){
                fontNames[i] = 掘;
            }else if(len(&(s[i*3]), "玄")){
                fontNames[i] = 玄;
            }else if(len(&(s[i*3]), "詐")){
                fontNames[i] = 詐;
            }else if(len(&(s[i*3]), "曇")){
                fontNames[i] = 曇;
            }else if(len(&(s[i*3]), "妬")){
                fontNames[i] = 妬;
            }else if(len(&(s[i*3]), "抑")){
                fontNames[i] = 抑;
            }else if(len(&(s[i*3]), "需")){
                fontNames[i] = 需;
            }else if(len(&(s[i*3]), "浩")){
                fontNames[i] = 浩;
            }else if(len(&(s[i*3]), "綾")){
                fontNames[i] = 綾;
            }else if(len(&(s[i*3]), "獣")){
                fontNames[i] = 獣;
            }else if(len(&(s[i*3]), "湿")){
                fontNames[i] = 湿;
            }else if(len(&(s[i*3]), "郵")){
                fontNames[i] = 郵;
            }else if(len(&(s[i*3]), "畜")){
                fontNames[i] = 畜;
            }else if(len(&(s[i*3]), "欺")){
                fontNames[i] = 欺;
            }else if(len(&(s[i*3]), "雇")){
                fontNames[i] = 雇;
            }else if(len(&(s[i*3]), "翔")){
                fontNames[i] = 翔;
            }else if(len(&(s[i*3]), "抵")){
                fontNames[i] = 抵;
            }else if(len(&(s[i*3]), "餅")){
                fontNames[i] = 餅;
            }else if(len(&(s[i*3]), "債")){
                fontNames[i] = 債;
            }else if(len(&(s[i*3]), "曝")){
                fontNames[i] = 曝;
            }else if(len(&(s[i*3]), "粋")){
                fontNames[i] = 粋;
            }else if(len(&(s[i*3]), "鎖")){
                fontNames[i] = 鎖;
            }else if(len(&(s[i*3]), "緩")){
                fontNames[i] = 緩;
            }else if(len(&(s[i*3]), "把")){
                fontNames[i] = 把;
            }else if(len(&(s[i*3]), "虚")){
                fontNames[i] = 虚;
            }else if(len(&(s[i*3]), "銭")){
                fontNames[i] = 銭;
            }else if(len(&(s[i*3]), "訓")){
                fontNames[i] = 訓;
            }else if(len(&(s[i*3]), "遭")){
                fontNames[i] = 遭;
            }else if(len(&(s[i*3]), "縛")){
                fontNames[i] = 縛;
            }else if(len(&(s[i*3]), "威")){
                fontNames[i] = 威;
            }else if(len(&(s[i*3]), "冗")){
                fontNames[i] = 冗;
            }else if(len(&(s[i*3]), "繧")){
                fontNames[i] = 繧;
            }else if(len(&(s[i*3]), "戯")){
                fontNames[i] = 戯;
            }else if(len(&(s[i*3]), "憧")){
                fontNames[i] = 憧;
            }else if(len(&(s[i*3]), "招")){
                fontNames[i] = 招;
            }else if(len(&(s[i*3]), "随")){
                fontNames[i] = 随;
            }else if(len(&(s[i*3]), "麦")){
                fontNames[i] = 麦;
            }else if(len(&(s[i*3]), "旬")){
                fontNames[i] = 旬;
            }else if(len(&(s[i*3]), "旨")){
                fontNames[i] = 旨;
            }else if(len(&(s[i*3]), "柳")){
                fontNames[i] = 柳;
            }else if(len(&(s[i*3]), "岐")){
                fontNames[i] = 岐;
            }else if(len(&(s[i*3]), "鶴")){
                fontNames[i] = 鶴;
            }else if(len(&(s[i*3]), "傾")){
                fontNames[i] = 傾;
            }else if(len(&(s[i*3]), "勿")){
                fontNames[i] = 勿;
            }else if(len(&(s[i*3]), "呪")){
                fontNames[i] = 呪;
            }else if(len(&(s[i*3]), "舌")){
                fontNames[i] = 舌;
            }else if(len(&(s[i*3]), "脂")){
                fontNames[i] = 脂;
            }else if(len(&(s[i*3]), "賃")){
                fontNames[i] = 賃;
            }else if(len(&(s[i*3]), "撤")){
                fontNames[i] = 撤;
            }else if(len(&(s[i*3]), "撲")){
                fontNames[i] = 撲;
            }else if(len(&(s[i*3]), "捜")){
                fontNames[i] = 捜;
            }else if(len(&(s[i*3]), "戒")){
                fontNames[i] = 戒;
            }else if(len(&(s[i*3]), "預")){
                fontNames[i] = 預;
            }else if(len(&(s[i*3]), "贈")){
                fontNames[i] = 贈;
            }else if(len(&(s[i*3]), "寧")){
                fontNames[i] = 寧;
            }else if(len(&(s[i*3]), "欧")){
                fontNames[i] = 欧;
            }else if(len(&(s[i*3]), "騙")){
                fontNames[i] = 騙;
            }else if(len(&(s[i*3]), "蓮")){
                fontNames[i] = 蓮;
            }else if(len(&(s[i*3]), "裂")){
                fontNames[i] = 裂;
            }else if(len(&(s[i*3]), "覗")){
                fontNames[i] = 覗;
            }else if(len(&(s[i*3]), "糸")){
                fontNames[i] = 糸;
            }else if(len(&(s[i*3]), "偶")){
                fontNames[i] = 偶;
            }else if(len(&(s[i*3]), "哲")){
                fontNames[i] = 哲;
            }else if(len(&(s[i*3]), "項")){
                fontNames[i] = 項;
            }else if(len(&(s[i*3]), "摩")){
                fontNames[i] = 摩;
            }else if(len(&(s[i*3]), "逢")){
                fontNames[i] = 逢;
            }else if(len(&(s[i*3]), "浸")){
                fontNames[i] = 浸;
            }else if(len(&(s[i*3]), "乃")){
                fontNames[i] = 乃;
            }else if(len(&(s[i*3]), "排")){
                fontNames[i] = 排;
            }else if(len(&(s[i*3]), "没")){
                fontNames[i] = 没;
            }else if(len(&(s[i*3]), "謹")){
                fontNames[i] = 謹;
            }else if(len(&(s[i*3]), "潤")){
                fontNames[i] = 潤;
            }else if(len(&(s[i*3]), "糞")){
                fontNames[i] = 糞;
            }else if(len(&(s[i*3]), "翼")){
                fontNames[i] = 翼;
            }else if(len(&(s[i*3]), "菌")){
                fontNames[i] = 菌;
            }else if(len(&(s[i*3]), "刀")){
                fontNames[i] = 刀;
            }else if(len(&(s[i*3]), "云")){
                fontNames[i] = 云;
            }else if(len(&(s[i*3]), "泥")){
                fontNames[i] = 泥;
            }else if(len(&(s[i*3]), "傘")){
                fontNames[i] = 傘;
            }else if(len(&(s[i*3]), "稚")){
                fontNames[i] = 稚;
            }else if(len(&(s[i*3]), "唐")){
                fontNames[i] = 唐;
            }else if(len(&(s[i*3]), "罰")){
                fontNames[i] = 罰;
            }else if(len(&(s[i*3]), "儀")){
                fontNames[i] = 儀;
            }else if(len(&(s[i*3]), "憲")){
                fontNames[i] = 憲;
            }else if(len(&(s[i*3]), "凸")){
                fontNames[i] = 凸;
            }else if(len(&(s[i*3]), "爽")){
                fontNames[i] = 爽;
            }else if(len(&(s[i*3]), "卑")){
                fontNames[i] = 卑;
            }else if(len(&(s[i*3]), "噴")){
                fontNames[i] = 噴;
            }else if(len(&(s[i*3]), "喰")){
                fontNames[i] = 喰;
            }else if(len(&(s[i*3]), "祥")){
                fontNames[i] = 祥;
            }else if(len(&(s[i*3]), "釈")){
                fontNames[i] = 釈;
            }else if(len(&(s[i*3]), "喧")){
                fontNames[i] = 喧;
            }else if(len(&(s[i*3]), "俗")){
                fontNames[i] = 俗;
            }else if(len(&(s[i*3]), "雀")){
                fontNames[i] = 雀;
            }else if(len(&(s[i*3]), "蹴")){
                fontNames[i] = 蹴;
            }else if(len(&(s[i*3]), "誇")){
                fontNames[i] = 誇;
            }else if(len(&(s[i*3]), "揮")){
                fontNames[i] = 揮;
            }else if(len(&(s[i*3]), "輔")){
                fontNames[i] = 輔;
            }else if(len(&(s[i*3]), "膝")){
                fontNames[i] = 膝;
            }else if(len(&(s[i*3]), "堪")){
                fontNames[i] = 堪;
            }else if(len(&(s[i*3]), "眺")){
                fontNames[i] = 眺;
            }else if(len(&(s[i*3]), "嫉")){
                fontNames[i] = 嫉;
            }else if(len(&(s[i*3]), "虎")){
                fontNames[i] = 虎;
            }else if(len(&(s[i*3]), "炭")){
                fontNames[i] = 炭;
            }else if(len(&(s[i*3]), "潜")){
                fontNames[i] = 潜;
            }else if(len(&(s[i*3]), "斎")){
                fontNames[i] = 斎;
            }else if(len(&(s[i*3]), "兼")){
                fontNames[i] = 兼;
            }else if(len(&(s[i*3]), "貞")){
                fontNames[i] = 貞;
            }else if(len(&(s[i*3]), "羊")){
                fontNames[i] = 羊;
            }else if(len(&(s[i*3]), "慶")){
                fontNames[i] = 慶;
            }else if(len(&(s[i*3]), "敏")){
                fontNames[i] = 敏;
            }else if(len(&(s[i*3]), "繁")){
                fontNames[i] = 繁;
            }else if(len(&(s[i*3]), "垣")){
                fontNames[i] = 垣;
            }else if(len(&(s[i*3]), "苗")){
                fontNames[i] = 苗;
            }else if(len(&(s[i*3]), "栃")){
                fontNames[i] = 栃;
            }else if(len(&(s[i*3]), "涼")){
                fontNames[i] = 涼;
            }else if(len(&(s[i*3]), "晶")){
                fontNames[i] = 晶;
            }else if(len(&(s[i*3]), "騎")){
                fontNames[i] = 騎;
            }else if(len(&(s[i*3]), "伴")){
                fontNames[i] = 伴;
            }else if(len(&(s[i*3]), "抽")){
                fontNames[i] = 抽;
            }else if(len(&(s[i*3]), "烈")){
                fontNames[i] = 烈;
            }else if(len(&(s[i*3]), "尋")){
                fontNames[i] = 尋;
            }else if(len(&(s[i*3]), "凹")){
                fontNames[i] = 凹;
            }else if(len(&(s[i*3]), "遂")){
                fontNames[i] = 遂;
            }else if(len(&(s[i*3]), "沸")){
                fontNames[i] = 沸;
            }else if(len(&(s[i*3]), "摂")){
                fontNames[i] = 摂;
            }else if(len(&(s[i*3]), "爪")){
                fontNames[i] = 爪;
            }else if(len(&(s[i*3]), "燥")){
                fontNames[i] = 燥;
            }else if(len(&(s[i*3]), "朗")){
                fontNames[i] = 朗;
            }else if(len(&(s[i*3]), "猛")){
                fontNames[i] = 猛;
            }else if(len(&(s[i*3]), "憂")){
                fontNames[i] = 憂;
            }else if(len(&(s[i*3]), "栗")){
                fontNames[i] = 栗;
            }else if(len(&(s[i*3]), "往")){
                fontNames[i] = 往;
            }else if(len(&(s[i*3]), "奨")){
                fontNames[i] = 奨;
            }else if(len(&(s[i*3]), "帽")){
                fontNames[i] = 帽;
            }else if(len(&(s[i*3]), "惨")){
                fontNames[i] = 惨;
            }else if(len(&(s[i*3]), "翻")){
                fontNames[i] = 翻;
            }else if(len(&(s[i*3]), "机")){
                fontNames[i] = 机;
            }else if(len(&(s[i*3]), "嶋")){
                fontNames[i] = 嶋;
            }else if(len(&(s[i*3]), "嘩")){
                fontNames[i] = 嘩;
            }else if(len(&(s[i*3]), "肝")){
                fontNames[i] = 肝;
            }else if(len(&(s[i*3]), "畑")){
                fontNames[i] = 畑;
            }else if(len(&(s[i*3]), "淡")){
                fontNames[i] = 淡;
            }else if(len(&(s[i*3]), "馴")){
                fontNames[i] = 馴;
            }else if(len(&(s[i*3]), "丘")){
                fontNames[i] = 丘;
            }else if(len(&(s[i*3]), "漬")){
                fontNames[i] = 漬;
            }else if(len(&(s[i*3]), "湖")){
                fontNames[i] = 湖;
            }else if(len(&(s[i*3]), "繝")){
                fontNames[i] = 繝;
            }else if(len(&(s[i*3]), "杏")){
                fontNames[i] = 杏;
            }else if(len(&(s[i*3]), "粒")){
                fontNames[i] = 粒;
            }else if(len(&(s[i*3]), "鶏")){
                fontNames[i] = 鶏;
            }else if(len(&(s[i*3]), "柏")){
                fontNames[i] = 柏;
            }else if(len(&(s[i*3]), "菊")){
                fontNames[i] = 菊;
            }else if(len(&(s[i*3]), "餃")){
                fontNames[i] = 餃;
            }else if(len(&(s[i*3]), "斉")){
                fontNames[i] = 斉;
            }else if(len(&(s[i*3]), "忠")){
                fontNames[i] = 忠;
            }else if(len(&(s[i*3]), "濡")){
                fontNames[i] = 濡;
            }else if(len(&(s[i*3]), "股")){
                fontNames[i] = 股;
            }else if(len(&(s[i*3]), "舐")){
                fontNames[i] = 舐;
            }else if(len(&(s[i*3]), "冒")){
                fontNames[i] = 冒;
            }else if(len(&(s[i*3]), "溢")){
                fontNames[i] = 溢;
            }else if(len(&(s[i*3]), "卓")){
                fontNames[i] = 卓;
            }else if(len(&(s[i*3]), "袖")){
                fontNames[i] = 袖;
            }else if(len(&(s[i*3]), "叶")){
                fontNames[i] = 叶;
            }else if(len(&(s[i*3]), "慰")){
                fontNames[i] = 慰;
            }else if(len(&(s[i*3]), "紛")){
                fontNames[i] = 紛;
            }else if(len(&(s[i*3]), "淫")){
                fontNames[i] = 淫;
            }else if(len(&(s[i*3]), "揉")){
                fontNames[i] = 揉;
            }else if(len(&(s[i*3]), "垂")){
                fontNames[i] = 垂;
            }else if(len(&(s[i*3]), "翌")){
                fontNames[i] = 翌;
            }else if(len(&(s[i*3]), "伏")){
                fontNames[i] = 伏;
            }else if(len(&(s[i*3]), "牧")){
                fontNames[i] = 牧;
            }else if(len(&(s[i*3]), "邦")){
                fontNames[i] = 邦;
            }else if(len(&(s[i*3]), "剛")){
                fontNames[i] = 剛;
            }else if(len(&(s[i*3]), "斬")){
                fontNames[i] = 斬;
            }else if(len(&(s[i*3]), "吾")){
                fontNames[i] = 吾;
            }else if(len(&(s[i*3]), "頻")){
                fontNames[i] = 頻;
            }else if(len(&(s[i*3]), "召")){
                fontNames[i] = 召;
            }else if(len(&(s[i*3]), "詩")){
                fontNames[i] = 詩;
            }else if(len(&(s[i*3]), "殊")){
                fontNames[i] = 殊;
            }else if(len(&(s[i*3]), "硬")){
                fontNames[i] = 硬;
            }else if(len(&(s[i*3]), "覇")){
                fontNames[i] = 覇;
            }else if(len(&(s[i*3]), "芋")){
                fontNames[i] = 芋;
            }else if(len(&(s[i*3]), "械")){
                fontNames[i] = 械;
            }else if(len(&(s[i*3]), "鳩")){
                fontNames[i] = 鳩;
            }else if(len(&(s[i*3]), "疎")){
                fontNames[i] = 疎;
            }else if(len(&(s[i*3]), "俊")){
                fontNames[i] = 俊;
            }else if(len(&(s[i*3]), "仰")){
                fontNames[i] = 仰;
            }else if(len(&(s[i*3]), "佳")){
                fontNames[i] = 佳;
            }else if(len(&(s[i*3]), "渉")){
                fontNames[i] = 渉;
            }else if(len(&(s[i*3]), "述")){
                fontNames[i] = 述;
            }else if(len(&(s[i*3]), "縦")){
                fontNames[i] = 縦;
            }else if(len(&(s[i*3]), "銃")){
                fontNames[i] = 銃;
            }else if(len(&(s[i*3]), "虐")){
                fontNames[i] = 虐;
            }else if(len(&(s[i*3]), "譜")){
                fontNames[i] = 譜;
            }else if(len(&(s[i*3]), "尿")){
                fontNames[i] = 尿;
            }else if(len(&(s[i*3]), "阻")){
                fontNames[i] = 阻;
            }else if(len(&(s[i*3]), "倫")){
                fontNames[i] = 倫;
            }else if(len(&(s[i*3]), "斗")){
                fontNames[i] = 斗;
            }else if(len(&(s[i*3]), "貫")){
                fontNames[i] = 貫;
            }else if(len(&(s[i*3]), "腸")){
                fontNames[i] = 腸;
            }else if(len(&(s[i*3]), "尚")){
                fontNames[i] = 尚;
            }else if(len(&(s[i*3]), "怠")){
                fontNames[i] = 怠;
            }else if(len(&(s[i*3]), "蒼")){
                fontNames[i] = 蒼;
            }else if(len(&(s[i*3]), "弘")){
                fontNames[i] = 弘;
            }else if(len(&(s[i*3]), "贅")){
                fontNames[i] = 贅;
            }else if(len(&(s[i*3]), "咳")){
                fontNames[i] = 咳;
            }else if(len(&(s[i*3]), "蒸")){
                fontNames[i] = 蒸;
            }else if(len(&(s[i*3]), "又")){
                fontNames[i] = 又;
            }else if(len(&(s[i*3]), "滝")){
                fontNames[i] = 滝;
            }else if(len(&(s[i*3]), "煽")){
                fontNames[i] = 煽;
            }else if(len(&(s[i*3]), "孝")){
                fontNames[i] = 孝;
            }else if(len(&(s[i*3]), "拓")){
                fontNames[i] = 拓;
            }else if(len(&(s[i*3]), "促")){
                fontNames[i] = 促;
            }else if(len(&(s[i*3]), "軒")){
                fontNames[i] = 軒;
            }else if(len(&(s[i*3]), "柴")){
                fontNames[i] = 柴;
            }else if(len(&(s[i*3]), "薦")){
                fontNames[i] = 薦;
            }else if(len(&(s[i*3]), "暫")){
                fontNames[i] = 暫;
            }else if(len(&(s[i*3]), "祉")){
                fontNames[i] = 祉;
            }else if(len(&(s[i*3]), "丹")){
                fontNames[i] = 丹;
            }else if(len(&(s[i*3]), "克")){
                fontNames[i] = 克;
            }else if(len(&(s[i*3]), "鎌")){
                fontNames[i] = 鎌;
            }else if(len(&(s[i*3]), "悶")){
                fontNames[i] = 悶;
            }else if(len(&(s[i*3]), "霧")){
                fontNames[i] = 霧;
            }else if(len(&(s[i*3]), "訂")){
                fontNames[i] = 訂;
            }else if(len(&(s[i*3]), "戚")){
                fontNames[i] = 戚;
            }else if(len(&(s[i*3]), "脇")){
                fontNames[i] = 脇;
            }else if(len(&(s[i*3]), "偵")){
                fontNames[i] = 偵;
            }else if(len(&(s[i*3]), "径")){
                fontNames[i] = 径;
            }else if(len(&(s[i*3]), "儲")){
                fontNames[i] = 儲;
            }else if(len(&(s[i*3]), "蛇")){
                fontNames[i] = 蛇;
            }else if(len(&(s[i*3]), "銘")){
                fontNames[i] = 銘;
            }else if(len(&(s[i*3]), "酬")){
                fontNames[i] = 酬;
            }else if(len(&(s[i*3]), "釜")){
                fontNames[i] = 釜;
            }else if(len(&(s[i*3]), "撫")){
                fontNames[i] = 撫;
            }else if(len(&(s[i*3]), "拍")){
                fontNames[i] = 拍;
            }else if(len(&(s[i*3]), "礎")){
                fontNames[i] = 礎;
            }else if(len(&(s[i*3]), "搭")){
                fontNames[i] = 搭;
            }else if(len(&(s[i*3]), "灰")){
                fontNames[i] = 灰;
            }else if(len(&(s[i*3]), "阜")){
                fontNames[i] = 阜;
            }else if(len(&(s[i*3]), "簿")){
                fontNames[i] = 簿;
            }else if(len(&(s[i*3]), "敢")){
                fontNames[i] = 敢;
            }else if(len(&(s[i*3]), "括")){
                fontNames[i] = 括;
            }else if(len(&(s[i*3]), "艦")){
                fontNames[i] = 艦;
            }else if(len(&(s[i*3]), "疫")){
                fontNames[i] = 疫;
            }else if(len(&(s[i*3]), "悠")){
                fontNames[i] = 悠;
            }else if(len(&(s[i*3]), "砲")){
                fontNames[i] = 砲;
            }else if(len(&(s[i*3]), "紳")){
                fontNames[i] = 紳;
            }else if(len(&(s[i*3]), "挟")){
                fontNames[i] = 挟;
            }else if(len(&(s[i*3]), "邸")){
                fontNames[i] = 邸;
            }else if(len(&(s[i*3]), "旗")){
                fontNames[i] = 旗;
            }else if(len(&(s[i*3]), "寛")){
                fontNames[i] = 寛;
            }else if(len(&(s[i*3]), "宏")){
                fontNames[i] = 宏;
            }else if(len(&(s[i*3]), "宴")){
                fontNames[i] = 宴;
            }else if(len(&(s[i*3]), "掴")){
                fontNames[i] = 掴;
            }else if(len(&(s[i*3]), "恩")){
                fontNames[i] = 恩;
            }else if(len(&(s[i*3]), "憎")){
                fontNames[i] = 憎;
            }else if(len(&(s[i*3]), "践")){
                fontNames[i] = 践;
            }else if(len(&(s[i*3]), "託")){
                fontNames[i] = 託;
            }else if(len(&(s[i*3]), "穏")){
                fontNames[i] = 穏;
            }else if(len(&(s[i*3]), "貢")){
                fontNames[i] = 貢;
            }else if(len(&(s[i*3]), "穂")){
                fontNames[i] = 穂;
            }else if(len(&(s[i*3]), "婆")){
                fontNames[i] = 婆;
            }else if(len(&(s[i*3]), "幽")){
                fontNames[i] = 幽;
            }else if(len(&(s[i*3]), "剥")){
                fontNames[i] = 剥;
            }else if(len(&(s[i*3]), "墓")){
                fontNames[i] = 墓;
            }else if(len(&(s[i*3]), "椅")){
                fontNames[i] = 椅;
            }else if(len(&(s[i*3]), "網")){
                fontNames[i] = 網;
            }else if(len(&(s[i*3]), "犠")){
                fontNames[i] = 犠;
            }else if(len(&(s[i*3]), "倶")){
                fontNames[i] = 倶;
            }else if(len(&(s[i*3]), "凶")){
                fontNames[i] = 凶;
            }else if(len(&(s[i*3]), "弥")){
                fontNames[i] = 弥;
            }else if(len(&(s[i*3]), "併")){
                fontNames[i] = 併;
            }else if(len(&(s[i*3]), "慌")){
                fontNames[i] = 慌;
            }else if(len(&(s[i*3]), "昧")){
                fontNames[i] = 昧;
            }else if(len(&(s[i*3]), "軟")){
                fontNames[i] = 軟;
            }else if(len(&(s[i*3]), "盟")){
                fontNames[i] = 盟;
            }else if(len(&(s[i*3]), "蘭")){
                fontNames[i] = 蘭;
            }else if(len(&(s[i*3]), "惜")){
                fontNames[i] = 惜;
            }else if(len(&(s[i*3]), "唄")){
                fontNames[i] = 唄;
            }else if(len(&(s[i*3]), "劣")){
                fontNames[i] = 劣;
            }else if(len(&(s[i*3]), "酢")){
                fontNames[i] = 酢;
            }else if(len(&(s[i*3]), "脅")){
                fontNames[i] = 脅;
            }else if(len(&(s[i*3]), "拳")){
                fontNames[i] = 拳;
            }else if(len(&(s[i*3]), "醤")){
                fontNames[i] = 醤;
            }else if(len(&(s[i*3]), "欄")){
                fontNames[i] = 欄;
            }else if(len(&(s[i*3]), "泳")){
                fontNames[i] = 泳;
            }else if(len(&(s[i*3]), "牲")){
                fontNames[i] = 牲;
            }else if(len(&(s[i*3]), "膨")){
                fontNames[i] = 膨;
            }else if(len(&(s[i*3]), "征")){
                fontNames[i] = 征;
            }else if(len(&(s[i*3]), "娠")){
                fontNames[i] = 娠;
            }else if(len(&(s[i*3]), "蓄")){
                fontNames[i] = 蓄;
            }else if(len(&(s[i*3]), "披")){
                fontNames[i] = 披;
            }else if(len(&(s[i*3]), "鍛")){
                fontNames[i] = 鍛;
            }else if(len(&(s[i*3]), "葛")){
                fontNames[i] = 葛;
            }else if(len(&(s[i*3]), "謙")){
                fontNames[i] = 謙;
            }else if(len(&(s[i*3]), "俳")){
                fontNames[i] = 俳;
            }else if(len(&(s[i*3]), "顧")){
                fontNames[i] = 顧;
            }else if(len(&(s[i*3]), "眉")){
                fontNames[i] = 眉;
            }else if(len(&(s[i*3]), "伺")){
                fontNames[i] = 伺;
            }else if(len(&(s[i*3]), "賠")){
                fontNames[i] = 賠;
            }else if(len(&(s[i*3]), "誉")){
                fontNames[i] = 誉;
            }else if(len(&(s[i*3]), "雛")){
                fontNames[i] = 雛;
            }else if(len(&(s[i*3]), "飴")){
                fontNames[i] = 飴;
            }else if(len(&(s[i*3]), "逸")){
                fontNames[i] = 逸;
            }else if(len(&(s[i*3]), "抹")){
                fontNames[i] = 抹;
            }else if(len(&(s[i*3]), "肥")){
                fontNames[i] = 肥;
            }else if(len(&(s[i*3]), "瓶")){
                fontNames[i] = 瓶;
            }else if(len(&(s[i*3]), "兎")){
                fontNames[i] = 兎;
            }else if(len(&(s[i*3]), "乏")){
                fontNames[i] = 乏;
            }else if(len(&(s[i*3]), "肢")){
                fontNames[i] = 肢;
            }else if(len(&(s[i*3]), "祐")){
                fontNames[i] = 祐;
            }else if(len(&(s[i*3]), "絞")){
                fontNames[i] = 絞;
            }else if(len(&(s[i*3]), "殆")){
                fontNames[i] = 殆;
            }else if(len(&(s[i*3]), "椎")){
                fontNames[i] = 椎;
            }else if(len(&(s[i*3]), "呆")){
                fontNames[i] = 呆;
            }else if(len(&(s[i*3]), "淳")){
                fontNames[i] = 淳;
            }else if(len(&(s[i*3]), "滋")){
                fontNames[i] = 滋;
            }else if(len(&(s[i*3]), "宛")){
                fontNames[i] = 宛;
            }else if(len(&(s[i*3]), "駒")){
                fontNames[i] = 駒;
            }else if(len(&(s[i*3]), "隔")){
                fontNames[i] = 隔;
            }else if(len(&(s[i*3]), "茂")){
                fontNames[i] = 茂;
            }else if(len(&(s[i*3]), "鋼")){
                fontNames[i] = 鋼;
            }else if(len(&(s[i*3]), "陥")){
                fontNames[i] = 陥;
            }else if(len(&(s[i*3]), "鷹")){
                fontNames[i] = 鷹;
            }else if(len(&(s[i*3]), "牡")){
                fontNames[i] = 牡;
            }else if(len(&(s[i*3]), "敦")){
                fontNames[i] = 敦;
            }else if(len(&(s[i*3]), "笠")){
                fontNames[i] = 笠;
            }else if(len(&(s[i*3]), "堅")){
                fontNames[i] = 堅;
            }else if(len(&(s[i*3]), "盾")){
                fontNames[i] = 盾;
            }else if(len(&(s[i*3]), "挿")){
                fontNames[i] = 挿;
            }else if(len(&(s[i*3]), "肪")){
                fontNames[i] = 肪;
            }else if(len(&(s[i*3]), "彰")){
                fontNames[i] = 彰;
            }else if(len(&(s[i*3]), "愉")){
                fontNames[i] = 愉;
            }else if(len(&(s[i*3]), "賊")){
                fontNames[i] = 賊;
            }else if(len(&(s[i*3]), "厄")){
                fontNames[i] = 厄;
            }else if(len(&(s[i*3]), "萎")){
                fontNames[i] = 萎;
            }else if(len(&(s[i*3]), "亮")){
                fontNames[i] = 亮;
            }else if(len(&(s[i*3]), "罠")){
                fontNames[i] = 罠;
            }else if(len(&(s[i*3]), "恒")){
                fontNames[i] = 恒;
            }else if(len(&(s[i*3]), "零")){
                fontNames[i] = 零;
            }else if(len(&(s[i*3]), "桐")){
                fontNames[i] = 桐;
            }else if(len(&(s[i*3]), "詣")){
                fontNames[i] = 詣;
            }else if(len(&(s[i*3]), "亭")){
                fontNames[i] = 亭;
            }else if(len(&(s[i*3]), "唇")){
                fontNames[i] = 唇;
            }else if(len(&(s[i*3]), "哉")){
                fontNames[i] = 哉;
            }else if(len(&(s[i*3]), "刃")){
                fontNames[i] = 刃;
            }else if(len(&(s[i*3]), "擬")){
                fontNames[i] = 擬;
            }else if(len(&(s[i*3]), "岳")){
                fontNames[i] = 岳;
            }else if(len(&(s[i*3]), "拭")){
                fontNames[i] = 拭;
            }else if(len(&(s[i*3]), "嘆")){
                fontNames[i] = 嘆;
            }else if(len(&(s[i*3]), "醒")){
                fontNames[i] = 醒;
            }else if(len(&(s[i*3]), "脈")){
                fontNames[i] = 脈;
            }else if(len(&(s[i*3]), "寮")){
                fontNames[i] = 寮;
            }else if(len(&(s[i*3]), "閲")){
                fontNames[i] = 閲;
            }else if(len(&(s[i*3]), "巣")){
                fontNames[i] = 巣;
            }else if(len(&(s[i*3]), "隙")){
                fontNames[i] = 隙;
            }else if(len(&(s[i*3]), "潔")){
                fontNames[i] = 潔;
            }else if(len(&(s[i*3]), "剰")){
                fontNames[i] = 剰;
            }else if(len(&(s[i*3]), "殻")){
                fontNames[i] = 殻;
            }else if(len(&(s[i*3]), "櫻")){
                fontNames[i] = 櫻;
            }else if(len(&(s[i*3]), "狼")){
                fontNames[i] = 狼;
            }else if(len(&(s[i*3]), "葬")){
                fontNames[i] = 葬;
            }else if(len(&(s[i*3]), "胞")){
                fontNames[i] = 胞;
            }else if(len(&(s[i*3]), "勃")){
                fontNames[i] = 勃;
            }else if(len(&(s[i*3]), "逝")){
                fontNames[i] = 逝;
            }else if(len(&(s[i*3]), "猿")){
                fontNames[i] = 猿;
            }else if(len(&(s[i*3]), "柱")){
                fontNames[i] = 柱;
            }else if(len(&(s[i*3]), "喚")){
                fontNames[i] = 喚;
            }else if(len(&(s[i*3]), "胡")){
                fontNames[i] = 胡;
            }else if(len(&(s[i*3]), "〆")){
                fontNames[i] = シメ;
            }else if(len(&(s[i*3]), "猥")){
                fontNames[i] = 猥;
            }else if(len(&(s[i*3]), "篠")){
                fontNames[i] = 篠;
            }else if(len(&(s[i*3]), "粘")){
                fontNames[i] = 粘;
            }else if(len(&(s[i*3]), "汰")){
                fontNames[i] = 汰;
            }else if(len(&(s[i*3]), "班")){
                fontNames[i] = 班;
            }else if(len(&(s[i*3]), "禿")){
                fontNames[i] = 禿;
            }else if(len(&(s[i*3]), "洒")){
                fontNames[i] = 洒;
            }else if(len(&(s[i*3]), "彫")){
                fontNames[i] = 彫;
            }else if(len(&(s[i*3]), "軸")){
                fontNames[i] = 軸;
            }else if(len(&(s[i*3]), "凝")){
                fontNames[i] = 凝;
            }else if(len(&(s[i*3]), "磁")){
                fontNames[i] = 磁;
            }else if(len(&(s[i*3]), "謀")){
                fontNames[i] = 謀;
            }else if(len(&(s[i*3]), "磯")){
                fontNames[i] = 磯;
            }else if(len(&(s[i*3]), "鯖")){
                fontNames[i] = 鯖;
            }else if(len(&(s[i*3]), "腫")){
                fontNames[i] = 腫;
            }else if(len(&(s[i*3]), "酎")){
                fontNames[i] = 酎;
            }else if(len(&(s[i*3]), "弊")){
                fontNames[i] = 弊;
            }else if(len(&(s[i*3]), "塔")){
                fontNames[i] = 塔;
            }else if(len(&(s[i*3]), "姦")){
                fontNames[i] = 姦;
            }else if(len(&(s[i*3]), "傍")){
                fontNames[i] = 傍;
            }else if(len(&(s[i*3]), "序")){
                fontNames[i] = 序;
            }else if(len(&(s[i*3]), "泡")){
                fontNames[i] = 泡;
            }else if(len(&(s[i*3]), "弄")){
                fontNames[i] = 弄;
            }else if(len(&(s[i*3]), "磐")){
                fontNames[i] = 磐;
            }else if(len(&(s[i*3]), "峰")){
                fontNames[i] = 峰;
            }else if(len(&(s[i*3]), "徐")){
                fontNames[i] = 徐;
            }else if(len(&(s[i*3]), "稽")){
                fontNames[i] = 稽;
            }else if(len(&(s[i*3]), "湧")){
                fontNames[i] = 湧;
            }else if(len(&(s[i*3]), "愕")){
                fontNames[i] = 愕;
            }else if(len(&(s[i*3]), "芽")){
                fontNames[i] = 芽;
            }else if(len(&(s[i*3]), "瞳")){
                fontNames[i] = 瞳;
            }else if(len(&(s[i*3]), "猪")){
                fontNames[i] = 猪;
            }else if(len(&(s[i*3]), "覆")){
                fontNames[i] = 覆;
            }else if(len(&(s[i*3]), "綱")){
                fontNames[i] = 綱;
            }else if(len(&(s[i*3]), "辻")){
                fontNames[i] = 辻;
            }else if(len(&(s[i*3]), "炒")){
                fontNames[i] = 炒;
            }else if(len(&(s[i*3]), "幾")){
                fontNames[i] = 幾;
            }else if(len(&(s[i*3]), "弓")){
                fontNames[i] = 弓;
            }else if(len(&(s[i*3]), "斐")){
                fontNames[i] = 斐;
            }else if(len(&(s[i*3]), "扉")){
                fontNames[i] = 扉;
            }else if(len(&(s[i*3]), "鈍")){
                fontNames[i] = 鈍;
            }else if(len(&(s[i*3]), "砕")){
                fontNames[i] = 砕;
            }else if(len(&(s[i*3]), "堕")){
                fontNames[i] = 堕;
            }else if(len(&(s[i*3]), "拘")){
                fontNames[i] = 拘;
            }else if(len(&(s[i*3]), "凡")){
                fontNames[i] = 凡;
            }else if(len(&(s[i*3]), "斜")){
                fontNames[i] = 斜;
            }else if(len(&(s[i*3]), "錦")){
                fontNames[i] = 錦;
            }else if(len(&(s[i*3]), "喪")){
                fontNames[i] = 喪;
            }else if(len(&(s[i*3]), "琴")){
                fontNames[i] = 琴;
            }else if(len(&(s[i*3]), "歪")){
                fontNames[i] = 歪;
            }else if(len(&(s[i*3]), "罵")){
                fontNames[i] = 罵;
            }else if(len(&(s[i*3]), "珈")){
                fontNames[i] = 珈;
            }else if(len(&(s[i*3]), "宵")){
                fontNames[i] = 宵;
            }else if(len(&(s[i*3]), "跳")){
                fontNames[i] = 跳;
            }else if(len(&(s[i*3]), "腺")){
                fontNames[i] = 腺;
            }else if(len(&(s[i*3]), "琲")){
                fontNames[i] = 琲;
            }else if(len(&(s[i*3]), "筒")){
                fontNames[i] = 筒;
            }else if(len(&(s[i*3]), "尖")){
                fontNames[i] = 尖;
            }else if(len(&(s[i*3]), "迄")){
                fontNames[i] = 迄;
            }else if(len(&(s[i*3]), "錯")){
                fontNames[i] = 錯;
            }else if(len(&(s[i*3]), "畳")){
                fontNames[i] = 畳;
            }else if(len(&(s[i*3]), "啓")){
                fontNames[i] = 啓;
            }else if(len(&(s[i*3]), "捉")){
                fontNames[i] = 捉;
            }else if(len(&(s[i*3]), "粗")){
                fontNames[i] = 粗;
            }else if(len(&(s[i*3]), "符")){
                fontNames[i] = 符;
            }else if(len(&(s[i*3]), "絆")){
                fontNames[i] = 絆;
            }else if(len(&(s[i*3]), "遥")){
                fontNames[i] = 遥;
            }else if(len(&(s[i*3]), "湘")){
                fontNames[i] = 湘;
            }else if(len(&(s[i*3]), "怯")){
                fontNames[i] = 怯;
            }else if(len(&(s[i*3]), "漂")){
                fontNames[i] = 漂;
            }else if(len(&(s[i*3]), "爺")){
                fontNames[i] = 爺;
            }else if(len(&(s[i*3]), "叱")){
                fontNames[i] = 叱;
            }else if(len(&(s[i*3]), "惹")){
                fontNames[i] = 惹;
            }else if(len(&(s[i*3]), "冥")){
                fontNames[i] = 冥;
            }else if(len(&(s[i*3]), "恨")){
                fontNames[i] = 恨;
            }else if(len(&(s[i*3]), "箇")){
                fontNames[i] = 箇;
            }else if(len(&(s[i*3]), "壮")){
                fontNames[i] = 壮;
            }else if(len(&(s[i*3]), "旭")){
                fontNames[i] = 旭;
            }else if(len(&(s[i*3]), "扇")){
                fontNames[i] = 扇;
            }else if(len(&(s[i*3]), "架")){
                fontNames[i] = 架;
            }else if(len(&(s[i*3]), "頬")){
                fontNames[i] = 頬;
            }else if(len(&(s[i*3]), "挫")){
                fontNames[i] = 挫;
            }else if(len(&(s[i*3]), "繊")){
                fontNames[i] = 繊;
            }else if(len(&(s[i*3]), "蘇")){
                fontNames[i] = 蘇;
            }else if(len(&(s[i*3]), "鼓")){
                fontNames[i] = 鼓;
            }else if(len(&(s[i*3]), "妥")){
                fontNames[i] = 妥;
            }else if(len(&(s[i*3]), "掌")){
                fontNames[i] = 掌;
            }else if(len(&(s[i*3]), "紗")){
                fontNames[i] = 紗;
            }else if(len(&(s[i*3]), "虹")){
                fontNames[i] = 虹;
            }else if(len(&(s[i*3]), "珠")){
                fontNames[i] = 珠;
            }else if(len(&(s[i*3]), "騰")){
                fontNames[i] = 騰;
            }else if(len(&(s[i*3]), "殖")){
                fontNames[i] = 殖;
            }else if(len(&(s[i*3]), "矛")){
                fontNames[i] = 矛;
            }else if(len(&(s[i*3]), "糧")){
                fontNames[i] = 糧;
            }else if(len(&(s[i*3]), "搬")){
                fontNames[i] = 搬;
            }else if(len(&(s[i*3]), "刈")){
                fontNames[i] = 刈;
            }else if(len(&(s[i*3]), "圭")){
                fontNames[i] = 圭;
            }else if(len(&(s[i*3]), "莉")){
                fontNames[i] = 莉;
            }else if(len(&(s[i*3]), "暦")){
                fontNames[i] = 暦;
            }else if(len(&(s[i*3]), "隅")){
                fontNames[i] = 隅;
            }else if(len(&(s[i*3]), "菱")){
                fontNames[i] = 菱;
            }else if(len(&(s[i*3]), "陶")){
                fontNames[i] = 陶;
            }else if(len(&(s[i*3]), "荘")){
                fontNames[i] = 荘;
            }else if(len(&(s[i*3]), "誓")){
                fontNames[i] = 誓;
            }else if(len(&(s[i*3]), "桑")){
                fontNames[i] = 桑;
            }else if(len(&(s[i*3]), "舘")){
                fontNames[i] = 舘;
            }else if(len(&(s[i*3]), "蕎")){
                fontNames[i] = 蕎;
            }else if(len(&(s[i*3]), "綿")){
                fontNames[i] = 綿;
            }else if(len(&(s[i*3]), "蛍")){
                fontNames[i] = 蛍;
            }else if(len(&(s[i*3]), "國")){
                fontNames[i] = 國;
            }else if(len(&(s[i*3]), "鉛")){
                fontNames[i] = 鉛;
            }else if(len(&(s[i*3]), "憤")){
                fontNames[i] = 憤;
            }else if(len(&(s[i*3]), "萩")){
                fontNames[i] = 萩;
            }else if(len(&(s[i*3]), "篇")){
                fontNames[i] = 篇;
            }else if(len(&(s[i*3]), "馳")){
                fontNames[i] = 馳;
            }else if(len(&(s[i*3]), "鎮")){
                fontNames[i] = 鎮;
            }else if(len(&(s[i*3]), "陛")){
                fontNames[i] = 陛;
            }else if(len(&(s[i*3]), "澄")){
                fontNames[i] = 澄;
            }else if(len(&(s[i*3]), "枯")){
                fontNames[i] = 枯;
            }else if(len(&(s[i*3]), "僧")){
                fontNames[i] = 僧;
            }else if(len(&(s[i*3]), "桁")){
                fontNames[i] = 桁;
            }else if(len(&(s[i*3]), "伯")){
                fontNames[i] = 伯;
            }else if(len(&(s[i*3]), "痒")){
                fontNames[i] = 痒;
            }else if(len(&(s[i*3]), "蜜")){
                fontNames[i] = 蜜;
            }else if(len(&(s[i*3]), "遽")){
                fontNames[i] = 遽;
            }else if(len(&(s[i*3]), "烏")){
                fontNames[i] = 烏;
            }else if(len(&(s[i*3]), "塁")){
                fontNames[i] = 塁;
            }else if(len(&(s[i*3]), "餌")){
                fontNames[i] = 餌;
            }else if(len(&(s[i*3]), "妨")){
                fontNames[i] = 妨;
            }else if(len(&(s[i*3]), "奉")){
                fontNames[i] = 奉;
            }else if(len(&(s[i*3]), "幡")){
                fontNames[i] = 幡;
            }else if(len(&(s[i*3]), "弦")){
                fontNames[i] = 弦;
            }else if(len(&(s[i*3]), "餓")){
                fontNames[i] = 餓;
            }else if(len(&(s[i*3]), "塊")){
                fontNames[i] = 塊;
            }else if(len(&(s[i*3]), "鯛")){
                fontNames[i] = 鯛;
            }else if(len(&(s[i*3]), "曰")){
                fontNames[i] = 曰;
            }else if(len(&(s[i*3]), "貝")){
                fontNames[i] = 貝;
            }else if(len(&(s[i*3]), "蟹")){
                fontNames[i] = 蟹;
            }else if(len(&(s[i*3]), "泰")){
                fontNames[i] = 泰;
            }else if(len(&(s[i*3]), "辱")){
                fontNames[i] = 辱;
            }else if(len(&(s[i*3]), "凛")){
                fontNames[i] = 凛;
            }else if(len(&(s[i*3]), "李")){
                fontNames[i] = 李;
            }else if(len(&(s[i*3]), "疾")){
                fontNames[i] = 疾;
            }else if(len(&(s[i*3]), "胆")){
                fontNames[i] = 胆;
            }else if(len(&(s[i*3]), "鋭")){
                fontNames[i] = 鋭;
            }else if(len(&(s[i*3]), "桂")){
                fontNames[i] = 桂;
            }else if(len(&(s[i*3]), "戴")){
                fontNames[i] = 戴;
            }else if(len(&(s[i*3]), "衰")){
                fontNames[i] = 衰;
            }else if(len(&(s[i*3]), "隷")){
                fontNames[i] = 隷;
            }else if(len(&(s[i*3]), "牙")){
                fontNames[i] = 牙;
            }else if(len(&(s[i*3]), "媛")){
                fontNames[i] = 媛;
            }else if(len(&(s[i*3]), "吊")){
                fontNames[i] = 吊;
            }else if(len(&(s[i*3]), "佑")){
                fontNames[i] = 佑;
            }else if(len(&(s[i*3]), "冠")){
                fontNames[i] = 冠;
            }else if(len(&(s[i*3]), "鴨")){
                fontNames[i] = 鴨;
            }else if(len(&(s[i*3]), "洲")){
                fontNames[i] = 洲;
            }else if(len(&(s[i*3]), "紋")){
                fontNames[i] = 紋;
            }else if(len(&(s[i*3]), "笛")){
                fontNames[i] = 笛;
            }else if(len(&(s[i*3]), "廊")){
                fontNames[i] = 廊;
            }else if(len(&(s[i*3]), "膚")){
                fontNames[i] = 膚;
            }else if(len(&(s[i*3]), "薇")){
                fontNames[i] = 薇;
            }else if(len(&(s[i*3]), "痺")){
                fontNames[i] = 痺;
            }else if(len(&(s[i*3]), "薔")){
                fontNames[i] = 薔;
            }else if(len(&(s[i*3]), "淹")){
                fontNames[i] = 淹;
            }else if(len(&(s[i*3]), "辿")){
                fontNames[i] = 辿;
            }else if(len(&(s[i*3]), "塞")){
                fontNames[i] = 塞;
            }else if(len(&(s[i*3]), "姐")){
                fontNames[i] = 姐;
            }else if(len(&(s[i*3]), "喘")){
                fontNames[i] = 喘;
            }else if(len(&(s[i*3]), "懲")){
                fontNames[i] = 懲;
            }else if(len(&(s[i*3]), "葵")){
                fontNames[i] = 葵;
            }else if(len(&(s[i*3]), "澪")){
                fontNames[i] = 澪;
            }else if(len(&(s[i*3]), "函")){
                fontNames[i] = 函;
            }else if(len(&(s[i*3]), "蓋")){
                fontNames[i] = 蓋;
            }else if(len(&(s[i*3]), "蝶")){
                fontNames[i] = 蝶;
            }else if(len(&(s[i*3]), "賭")){
                fontNames[i] = 賭;
            }else if(len(&(s[i*3]), "昆")){
                fontNames[i] = 昆;
            }else if(len(&(s[i*3]), "苛")){
                fontNames[i] = 苛;
            }else if(len(&(s[i*3]), "檎")){
                fontNames[i] = 檎;
            }else if(len(&(s[i*3]), "玲")){
                fontNames[i] = 玲;
            }else if(len(&(s[i*3]), "眩")){
                fontNames[i] = 眩;
            }else if(len(&(s[i*3]), "梶")){
                fontNames[i] = 梶;
            }else if(len(&(s[i*3]), "擦")){
                fontNames[i] = 擦;
            }else if(len(&(s[i*3]), "芳")){
                fontNames[i] = 芳;
            }else if(len(&(s[i*3]), "拙")){
                fontNames[i] = 拙;
            }else if(len(&(s[i*3]), "霞")){
                fontNames[i] = 霞;
            }else if(len(&(s[i*3]), "該")){
                fontNames[i] = 該;
            }else if(len(&(s[i*3]), "涯")){
                fontNames[i] = 涯;
            }else if(len(&(s[i*3]), "苺")){
                fontNames[i] = 苺;
            }else if(len(&(s[i*3]), "鉢")){
                fontNames[i] = 鉢;
            }else if(len(&(s[i*3]), "暁")){
                fontNames[i] = 暁;
            }else if(len(&(s[i*3]), "昌")){
                fontNames[i] = 昌;
            }else if(len(&(s[i*3]), "筑")){
                fontNames[i] = 筑;
            }else if(len(&(s[i*3]), "芯")){
                fontNames[i] = 芯;
            }else if(len(&(s[i*3]), "訟")){
                fontNames[i] = 訟;
            }else if(len(&(s[i*3]), "柿")){
                fontNames[i] = 柿;
            }else if(len(&(s[i*3]), "姜")){
                fontNames[i] = 姜;
            }else if(len(&(s[i*3]), "慈")){
                fontNames[i] = 慈;
            }else if(len(&(s[i*3]), "措")){
                fontNames[i] = 措;
            }else if(len(&(s[i*3]), "詮")){
                fontNames[i] = 詮;
            }else if(len(&(s[i*3]), "筈")){
                fontNames[i] = 筈;
            }else if(len(&(s[i*3]), "此")){
                fontNames[i] = 此;
            }else if(len(&(s[i*3]), "曖")){
                fontNames[i] = 曖;
            }else if(len(&(s[i*3]), "滴")){
                fontNames[i] = 滴;
            }else if(len(&(s[i*3]), "縫")){
                fontNames[i] = 縫;
            }else if(len(&(s[i*3]), "棟")){
                fontNames[i] = 棟;
            }else if(len(&(s[i*3]), "屍")){
                fontNames[i] = 屍;
            }else if(len(&(s[i*3]), "詫")){
                fontNames[i] = 詫;
            }else if(len(&(s[i*3]), "丿")){
                fontNames[i] = 丿;
            }else if(len(&(s[i*3]), "藍")){
                fontNames[i] = 藍;
            }else if(len(&(s[i*3]), "懇")){
                fontNames[i] = 懇;
            }else if(len(&(s[i*3]), "椿")){
                fontNames[i] = 椿;
            }else if(len(&(s[i*3]), "箸")){
                fontNames[i] = 箸;
            }else if(len(&(s[i*3]), "苑")){
                fontNames[i] = 苑;
            }else if(len(&(s[i*3]), "陳")){
                fontNames[i] = 陳;
            }else if(len(&(s[i*3]), "溝")){
                fontNames[i] = 溝;
            }else if(len(&(s[i*3]), "蔽")){
                fontNames[i] = 蔽;
            }else if(len(&(s[i*3]), "柚")){
                fontNames[i] = 柚;
            }else if(len(&(s[i*3]), "蒲")){
                fontNames[i] = 蒲;
            }else if(len(&(s[i*3]), "盲")){
                fontNames[i] = 盲;
            }else if(len(&(s[i*3]), "伎")){
                fontNames[i] = 伎;
            }else if(len(&(s[i*3]), "崇")){
                fontNames[i] = 崇;
            }else if(len(&(s[i*3]), "棋")){
                fontNames[i] = 棋;
            }else if(len(&(s[i*3]), "撒")){
                fontNames[i] = 撒;
            }else if(len(&(s[i*3]), "肺")){
                fontNames[i] = 肺;
            }else if(len(&(s[i*3]), "狐")){
                fontNames[i] = 狐;
            }else if(len(&(s[i*3]), "壇")){
                fontNames[i] = 壇;
            }else if(len(&(s[i*3]), "惰")){
                fontNames[i] = 惰;
            }else if(len(&(s[i*3]), "培")){
                fontNames[i] = 培;
            }else if(len(&(s[i*3]), "瓦")){
                fontNames[i] = 瓦;
            }else if(len(&(s[i*3]), "嘉")){
                fontNames[i] = 嘉;
            }else if(len(&(s[i*3]), "堺")){
                fontNames[i] = 堺;
            }else if(len(&(s[i*3]), "遮")){
                fontNames[i] = 遮;
            }else if(len(&(s[i*3]), "舫")){
                fontNames[i] = 舫;
            }else if(len(&(s[i*3]), "俣")){
                fontNames[i] = 俣;
            }else if(len(&(s[i*3]), "膜")){
                fontNames[i] = 膜;
            }else if(len(&(s[i*3]), "朱")){
                fontNames[i] = 朱;
            }else if(len(&(s[i*3]), "壱")){
                fontNames[i] = 壱;
            }else if(len(&(s[i*3]), "赦")){
                fontNames[i] = 赦;
            }else if(len(&(s[i*3]), "忌")){
                fontNames[i] = 忌;
            }else if(len(&(s[i*3]), "曹")){
                fontNames[i] = 曹;
            }else if(len(&(s[i*3]), "剃")){
                fontNames[i] = 剃;
            }else if(len(&(s[i*3]), "旋")){
                fontNames[i] = 旋;
            }else if(len(&(s[i*3]), "聡")){
                fontNames[i] = 聡;
            }else if(len(&(s[i*3]), "諭")){
                fontNames[i] = 諭;
            }else if(len(&(s[i*3]), "擁")){
                fontNames[i] = 擁;
            }else if(len(&(s[i*3]), "痔")){
                fontNames[i] = 痔;
            }else if(len(&(s[i*3]), "蜂")){
                fontNames[i] = 蜂;
            }else if(len(&(s[i*3]), "軌")){
                fontNames[i] = 軌;
            }else if(len(&(s[i*3]), "傑")){
                fontNames[i] = 傑;
            }else if(len(&(s[i*3]), "笹")){
                fontNames[i] = 笹;
            }else if(len(&(s[i*3]), "癌")){
                fontNames[i] = 癌;
            }else if(len(&(s[i*3]), "梓")){
                fontNames[i] = 梓;
            }else if(len(&(s[i*3]), "這")){
                fontNames[i] = 這;
            }else if(len(&(s[i*3]), "獅")){
                fontNames[i] = 獅;
            }else if(len(&(s[i*3]), "掻")){
                fontNames[i] = 掻;
            }else if(len(&(s[i*3]), "緯")){
                fontNames[i] = 緯;
            }else if(len(&(s[i*3]), "捧")){
                fontNames[i] = 捧;
            }else if(len(&(s[i*3]), "屁")){
                fontNames[i] = 屁;
            }else if(len(&(s[i*3]), "隈")){
                fontNames[i] = 隈;
            }else if(len(&(s[i*3]), "濁")){
                fontNames[i] = 濁;
            }else if(len(&(s[i*3]), "串")){
                fontNames[i] = 串;
            }else if(len(&(s[i*3]), "諏")){
                fontNames[i] = 諏;
            }else if(len(&(s[i*3]), "籠")){
                fontNames[i] = 籠;
            }else if(len(&(s[i*3]), "巧")){
                fontNames[i] = 巧;
            }else if(len(&(s[i*3]), "淵")){
                fontNames[i] = 淵;
            }else if(len(&(s[i*3]), "髭")){
                fontNames[i] = 髭;
            }else if(len(&(s[i*3]), "栽")){
                fontNames[i] = 栽;
            }else if(len(&(s[i*3]), "庄")){
                fontNames[i] = 庄;
            }else if(len(&(s[i*3]), "朴")){
                fontNames[i] = 朴;
            }else if(len(&(s[i*3]), "鞄")){
                fontNames[i] = 鞄;
            }else if(len(&(s[i*3]), "淋")){
                fontNames[i] = 淋;
            }else if(len(&(s[i*3]), "穫")){
                fontNames[i] = 穫;
            }else if(len(&(s[i*3]), "訊")){
                fontNames[i] = 訊;
            }else if(len(&(s[i*3]), "槽")){
                fontNames[i] = 槽;
            }else if(len(&(s[i*3]), "釘")){
                fontNames[i] = 釘;
            }else if(len(&(s[i*3]), "姓")){
                fontNames[i] = 姓;
            }else if(len(&(s[i*3]), "茅")){
                fontNames[i] = 茅;
            }else if(len(&(s[i*3]), "冴")){
                fontNames[i] = 冴;
            }else if(len(&(s[i*3]), "傲")){
                fontNames[i] = 傲;
            }else if(len(&(s[i*3]), "錠")){
                fontNames[i] = 錠;
            }else if(len(&(s[i*3]), "錬")){
                fontNames[i] = 錬;
            }else if(len(&(s[i*3]), "玩")){
                fontNames[i] = 玩;
            }else if(len(&(s[i*3]), "巾")){
                fontNames[i] = 巾;
            }else if(len(&(s[i*3]), "其")){
                fontNames[i] = 其;
            }else if(len(&(s[i*3]), "琉")){
                fontNames[i] = 琉;
            }else if(len(&(s[i*3]), "紺")){
                fontNames[i] = 紺;
            }else if(len(&(s[i*3]), "賑")){
                fontNames[i] = 賑;
            }else if(len(&(s[i*3]), "洞")){
                fontNames[i] = 洞;
            }else if(len(&(s[i*3]), "遡")){
                fontNames[i] = 遡;
            }else if(len(&(s[i*3]), "遼")){
                fontNames[i] = 遼;
            }else if(len(&(s[i*3]), "瑞")){
                fontNames[i] = 瑞;
            }else if(len(&(s[i*3]), "廻")){
                fontNames[i] = 廻;
            }else if(len(&(s[i*3]), "耕")){
                fontNames[i] = 耕;
            }else if(len(&(s[i*3]), "酵")){
                fontNames[i] = 酵;
            }else if(len(&(s[i*3]), "堤")){
                fontNames[i] = 堤;
            }else if(len(&(s[i*3]), "瑠")){
                fontNames[i] = 瑠;
            }else if(len(&(s[i*3]), "茎")){
                fontNames[i] = 茎;
            }else if(len(&(s[i*3]), "煎")){
                fontNames[i] = 煎;
            }else if(len(&(s[i*3]), "墨")){
                fontNames[i] = 墨;
            }else if(len(&(s[i*3]), "壌")){
                fontNames[i] = 壌;
            }else if(len(&(s[i*3]), "顎")){
                fontNames[i] = 顎;
            }else if(len(&(s[i*3]), "稀")){
                fontNames[i] = 稀;
            }else if(len(&(s[i*3]), "匿")){
                fontNames[i] = 匿;
            }else if(len(&(s[i*3]), "漠")){
                fontNames[i] = 漠;
            }else if(len(&(s[i*3]), "醸")){
                fontNames[i] = 醸;
            }else if(len(&(s[i*3]), "呈")){
                fontNames[i] = 呈;
            }else if(len(&(s[i*3]), "鉱")){
                fontNames[i] = 鉱;
            }else if(len(&(s[i*3]), "曽")){
                fontNames[i] = 曽;
            }else if(len(&(s[i*3]), "苔")){
                fontNames[i] = 苔;
            }else if(len(&(s[i*3]), "渇")){
                fontNames[i] = 渇;
            }else if(len(&(s[i*3]), "溺")){
                fontNames[i] = 溺;
            }else if(len(&(s[i*3]), "纏")){
                fontNames[i] = 纏;
            }else if(len(&(s[i*3]), "躊")){
                fontNames[i] = 躊;
            }else if(len(&(s[i*3]), "叔")){
                fontNames[i] = 叔;
            }else if(len(&(s[i*3]), "躇")){
                fontNames[i] = 躇;
            }else if(len(&(s[i*3]), "薙")){
                fontNames[i] = 薙;
            }else if(len(&(s[i*3]), "梱")){
                fontNames[i] = 梱;
            }else if(len(&(s[i*3]), "紐")){
                fontNames[i] = 紐;
            }else if(len(&(s[i*3]), "薫")){
                fontNames[i] = 薫;
            }else if(len(&(s[i*3]), "奢")){
                fontNames[i] = 奢;
            }else if(len(&(s[i*3]), "朋")){
                fontNames[i] = 朋;
            }else if(len(&(s[i*3]), "骸")){
                fontNames[i] = 骸;
            }else if(len(&(s[i*3]), "伐")){
                fontNames[i] = 伐;
            }else if(len(&(s[i*3]), "粥")){
                fontNames[i] = 粥;
            }else if(len(&(s[i*3]), "蠣")){
                fontNames[i] = 蠣;
            }else if(len(&(s[i*3]), "綻")){
                fontNames[i] = 綻;
            }else if(len(&(s[i*3]), "姪")){
                fontNames[i] = 姪;
            }else if(len(&(s[i*3]), "甥")){
                fontNames[i] = 甥;
            }else if(len(&(s[i*3]), "荻")){
                fontNames[i] = 荻;
            }else if(len(&(s[i*3]), "栓")){
                fontNames[i] = 栓;
            }else if(len(&(s[i*3]), "嗚")){
                fontNames[i] = 嗚;
            }else if(len(&(s[i*3]), "駿")){
                fontNames[i] = 駿;
            }else if(len(&(s[i*3]), "碧")){
                fontNames[i] = 碧;
            }else if(len(&(s[i*3]), "孔")){
                fontNames[i] = 孔;
            }else if(len(&(s[i*3]), "塵")){
                fontNames[i] = 塵;
            }else if(len(&(s[i*3]), "頓")){
                fontNames[i] = 頓;
            }else if(len(&(s[i*3]), "艶")){
                fontNames[i] = 艶;
            }else if(len(&(s[i*3]), "飢")){
                fontNames[i] = 飢;
            }else if(len(&(s[i*3]), "晃")){
                fontNames[i] = 晃;
            }else if(len(&(s[i*3]), "恭")){
                fontNames[i] = 恭;
            }else if(len(&(s[i*3]), "乞")){
                fontNames[i] = 乞;
            }else if(len(&(s[i*3]), "尺")){
                fontNames[i] = 尺;
            }else if(len(&(s[i*3]), "煩")){
                fontNames[i] = 煩;
            }else if(len(&(s[i*3]), "循")){
                fontNames[i] = 循;
            }else if(len(&(s[i*3]), "囁")){
                fontNames[i] = 囁;
            }else if(len(&(s[i*3]), "憑")){
                fontNames[i] = 憑;
            }else if(len(&(s[i*3]), "累")){
                fontNames[i] = 累;
            }else if(len(&(s[i*3]), "鳳")){
                fontNames[i] = 鳳;
            }else if(len(&(s[i*3]), "庵")){
                fontNames[i] = 庵;
            }else if(len(&(s[i*3]), "樽")){
                fontNames[i] = 樽;
            }else if(len(&(s[i*3]), "弐")){
                fontNames[i] = 弐;
            }else if(len(&(s[i*3]), "鷲")){
                fontNames[i] = 鷲;
            }else if(len(&(s[i*3]), "蹄")){
                fontNames[i] = 蹄;
            }else if(len(&(s[i*3]), "据")){
                fontNames[i] = 据;
            }else if(len(&(s[i*3]), "凌")){
                fontNames[i] = 凌;
            }else if(len(&(s[i*3]), "顕")){
                fontNames[i] = 顕;
            }else if(len(&(s[i*3]), "巫")){
                fontNames[i] = 巫;
            }else if(len(&(s[i*3]), "盆")){
                fontNames[i] = 盆;
            }else if(len(&(s[i*3]), "媒")){
                fontNames[i] = 媒;
            }else if(len(&(s[i*3]), "肯")){
                fontNames[i] = 肯;
            }else if(len(&(s[i*3]), "搾")){
                fontNames[i] = 搾;
            }else if(len(&(s[i*3]), "悦")){
                fontNames[i] = 悦;
            }else if(len(&(s[i*3]), "迅")){
                fontNames[i] = 迅;
            }else if(len(&(s[i*3]), "栖")){
                fontNames[i] = 栖;
            }else if(len(&(s[i*3]), "箒")){
                fontNames[i] = 箒;
            }else if(len(&(s[i*3]), "拉")){
                fontNames[i] = 拉;
            }else if(len(&(s[i*3]), "槌")){
                fontNames[i] = 槌;
            }else if(len(&(s[i*3]), "眞")){
                fontNames[i] = 眞;
            }else if(len(&(s[i*3]), "緋")){
                fontNames[i] = 緋;
            }else if(len(&(s[i*3]), "槍")){
                fontNames[i] = 槍;
            }else if(len(&(s[i*3]), "郊")){
                fontNames[i] = 郊;
            }else if(len(&(s[i*3]), "醜")){
                fontNames[i] = 醜;
            }else if(len(&(s[i*3]), "篤")){
                fontNames[i] = 篤;
            }else if(len(&(s[i*3]), "卸")){
                fontNames[i] = 卸;
            }else if(len(&(s[i*3]), "亘")){
                fontNames[i] = 亘;
            }else if(len(&(s[i*3]), "捻")){
                fontNames[i] = 捻;
            }else if(len(&(s[i*3]), "辰")){
                fontNames[i] = 辰;
            }else if(len(&(s[i*3]), "鮭")){
                fontNames[i] = 鮭;
            }else if(len(&(s[i*3]), "詠")){
                fontNames[i] = 詠;
            }else if(len(&(s[i*3]), "碁")){
                fontNames[i] = 碁;
            }else if(len(&(s[i*3]), "侍")){
                fontNames[i] = 侍;
            }else if(len(&(s[i*3]), "尼")){
                fontNames[i] = 尼;
            }else if(len(&(s[i*3]), "杖")){
                fontNames[i] = 杖;
            }else if(len(&(s[i*3]), "鮎")){
                fontNames[i] = 鮎;
            }else if(len(&(s[i*3]), "來")){
                fontNames[i] = 來;
            }else if(len(&(s[i*3]), "吟")){
                fontNames[i] = 吟;
            }else if(len(&(s[i*3]), "狗")){
                fontNames[i] = 狗;
            }else if(len(&(s[i*3]), "僅")){
                fontNames[i] = 僅;
            }else if(len(&(s[i*3]), "橘")){
                fontNames[i] = 橘;
            }else if(len(&(s[i*3]), "貿")){
                fontNames[i] = 貿;
            }else if(len(&(s[i*3]), "舟")){
                fontNames[i] = 舟;
            }else if(len(&(s[i*3]), "喝")){
                fontNames[i] = 喝;
            }else if(len(&(s[i*3]), "捏")){
                fontNames[i] = 捏;
            }else if(len(&(s[i*3]), "侮")){
                fontNames[i] = 侮;
            }else if(len(&(s[i*3]), "甚")){
                fontNames[i] = 甚;
            }else if(len(&(s[i*3]), "秩")){
                fontNames[i] = 秩;
            }else if(len(&(s[i*3]), "礫")){
                fontNames[i] = 礫;
            }else if(len(&(s[i*3]), "芦")){
                fontNames[i] = 芦;
            }else if(len(&(s[i*3]), "帆")){
                fontNames[i] = 帆;
            }else if(len(&(s[i*3]), "謡")){
                fontNames[i] = 謡;
            }else if(len(&(s[i*3]), "茹")){
                fontNames[i] = 茹;
            }else if(len(&(s[i*3]), "吠")){
                fontNames[i] = 吠;
            }else if(len(&(s[i*3]), "縲")){
                fontNames[i] = 縲;
            }else if(len(&(s[i*3]), "槻")){
                fontNames[i] = 槻;
            }else if(len(&(s[i*3]), "韻")){
                fontNames[i] = 韻;
            }else if(len(&(s[i*3]), "刹")){
                fontNames[i] = 刹;
            }else if(len(&(s[i*3]), "晋")){
                fontNames[i] = 晋;
            }else if(len(&(s[i*3]), "些")){
                fontNames[i] = 些;
            }else if(len(&(s[i*3]), "睨")){
                fontNames[i] = 睨;
            }else if(len(&(s[i*3]), "閃")){
                fontNames[i] = 閃;
            }else if(len(&(s[i*3]), "但")){
                fontNames[i] = 但;
            }else if(len(&(s[i*3]), "猟")){
                fontNames[i] = 猟;
            }else if(len(&(s[i*3]), "媚")){
                fontNames[i] = 媚;
            }else if(len(&(s[i*3]), "鐘")){
                fontNames[i] = 鐘;
            }else if(len(&(s[i*3]), "瞑")){
                fontNames[i] = 瞑;
            }else if(len(&(s[i*3]), "庶")){
                fontNames[i] = 庶;
            }else if(len(&(s[i*3]), "矯")){
                fontNames[i] = 矯;
            }else if(len(&(s[i*3]), "耶")){
                fontNames[i] = 耶;
            }else if(len(&(s[i*3]), "銅")){
                fontNames[i] = 銅;
            }else if(len(&(s[i*3]), "畿")){
                fontNames[i] = 畿;
            }else if(len(&(s[i*3]), "讃")){
                fontNames[i] = 讃;
            }else if(len(&(s[i*3]), "貌")){
                fontNames[i] = 貌;
            }else if(len(&(s[i*3]), "蚊")){
                fontNames[i] = 蚊;
            }else if(len(&(s[i*3]), "嗅")){
                fontNames[i] = 嗅;
            }else if(len(&(s[i*3]), "痢")){
                fontNames[i] = 痢;
            }else if(len(&(s[i*3]), "棲")){
                fontNames[i] = 棲;
            }else if(len(&(s[i*3]), "卯")){
                fontNames[i] = 卯;
            }else if(len(&(s[i*3]), "呉")){
                fontNames[i] = 呉;
            }else if(len(&(s[i*3]), "蔑")){
                fontNames[i] = 蔑;
            }else if(len(&(s[i*3]), "壼")){
                fontNames[i] = 壼;
            }else if(len(&(s[i*3]), "璃")){
                fontNames[i] = 璃;
            }else if(len(&(s[i*3]), "鹸")){
                fontNames[i] = 鹸;
            }else if(len(&(s[i*3]), "愁")){
                fontNames[i] = 愁;
            }else if(len(&(s[i*3]), "饅")){
                fontNames[i] = 饅;
            }else if(len(&(s[i*3]), "耗")){
                fontNames[i] = 耗;
            }else if(len(&(s[i*3]), "郁")){
                fontNames[i] = 郁;
            }else if(len(&(s[i*3]), "遍")){
                fontNames[i] = 遍;
            }else if(len(&(s[i*3]), "祷")){
                fontNames[i] = 祷;
            }else if(len(&(s[i*3]), "窪")){
                fontNames[i] = 窪;
            }else if(len(&(s[i*3]), "綴")){
                fontNames[i] = 綴;
            }else if(len(&(s[i*3]), "遙")){
                fontNames[i] = 遙;
            }else if(len(&(s[i*3]), "杜")){
                fontNames[i] = 杜;
            }else if(len(&(s[i*3]), "慨")){
                fontNames[i] = 慨;
            }else if(len(&(s[i*3]), "仔")){
                fontNames[i] = 仔;
            }else if(len(&(s[i*3]), "薩")){
                fontNames[i] = 薩;
            }else if(len(&(s[i*3]), "炸")){
                fontNames[i] = 炸;
            }else if(len(&(s[i*3]), "裾")){
                fontNames[i] = 裾;
            }else if(len(&(s[i*3]), "坪")){
                fontNames[i] = 坪;
            }else if(len(&(s[i*3]), "溘")){
                fontNames[i] = 溘;
            }else if(len(&(s[i*3]), "鯉")){
                fontNames[i] = 鯉;
            }else if(len(&(s[i*3]), "燐")){
                fontNames[i] = 燐;
            }else if(len(&(s[i*3]), "娯")){
                fontNames[i] = 娯;
            }else if(len(&(s[i*3]), "膳")){
                fontNames[i] = 膳;
            }else if(len(&(s[i*3]), "鯨")){
                fontNames[i] = 鯨;
            }else if(len(&(s[i*3]), "翠")){
                fontNames[i] = 翠;
            }else if(len(&(s[i*3]), "梁")){
                fontNames[i] = 梁;
            }else if(len(&(s[i*3]), "附")){
                fontNames[i] = 附;
            }else if(len(&(s[i*3]), "袴")){
                fontNames[i] = 袴;
            }else if(len(&(s[i*3]), "囚")){
                fontNames[i] = 囚;
            }else if(len(&(s[i*3]), "窮")){
                fontNames[i] = 窮;
            }else if(len(&(s[i*3]), "拗")){
                fontNames[i] = 拗;
            }else if(len(&(s[i*3]), "胴")){
                fontNames[i] = 胴;
            }else if(len(&(s[i*3]), "宰")){
                fontNames[i] = 宰;
            }else if(len(&(s[i*3]), "准")){
                fontNames[i] = 准;
            }else if(len(&(s[i*3]), "嗜")){
                fontNames[i] = 嗜;
            }else if(len(&(s[i*3]), "欝")){
                fontNames[i] = 欝;
            }else if(len(&(s[i*3]), "訣")){
                fontNames[i] = 訣;
            }else if(len(&(s[i*3]), "蛮")){
                fontNames[i] = 蛮;
            }else if(len(&(s[i*3]), "拷")){
                fontNames[i] = 拷;
            }else if(len(&(s[i*3]), "慕")){
                fontNames[i] = 慕;
            }else if(len(&(s[i*3]), "赴")){
                fontNames[i] = 赴;
            }else if(len(&(s[i*3]), "濱")){
                fontNames[i] = 濱;
            }else if(len(&(s[i*3]), "靖")){
                fontNames[i] = 靖;
            }else if(len(&(s[i*3]), "楼")){
                fontNames[i] = 楼;
            }else if(len(&(s[i*3]), "臆")){
                fontNames[i] = 臆;
            }else if(len(&(s[i*3]), "禅")){
                fontNames[i] = 禅;
            }else if(len(&(s[i*3]), "胎")){
                fontNames[i] = 胎;
            }else if(len(&(s[i*3]), "颯")){
                fontNames[i] = 颯;
            }else if(len(&(s[i*3]), "爵")){
                fontNames[i] = 爵;
            }else if(len(&(s[i*3]), "楚")){
                fontNames[i] = 楚;
            }else if(len(&(s[i*3]), "髄")){
                fontNames[i] = 髄;
            }else if(len(&(s[i*3]), "椒")){
                fontNames[i] = 椒;
            }else if(len(&(s[i*3]), "陵")){
                fontNames[i] = 陵;
            }else if(len(&(s[i*3]), "悼")){
                fontNames[i] = 悼;
            }else if(len(&(s[i*3]), "窃")){
                fontNames[i] = 窃;
            }else if(len(&(s[i*3]), "霜")){
                fontNames[i] = 霜;
            }else if(len(&(s[i*3]), "卍")){
                fontNames[i] = 卍;
            }else if(len(&(s[i*3]), "屑")){
                fontNames[i] = 屑;
            }else if(len(&(s[i*3]), "羞")){
                fontNames[i] = 羞;
            }else if(len(&(s[i*3]), "穀")){
                fontNames[i] = 穀;
            }else if(len(&(s[i*3]), "挽")){
                fontNames[i] = 挽;
            }else if(len(&(s[i*3]), "應")){
                fontNames[i] = 應;
            }else if(len(&(s[i*3]), "鱗")){
                fontNames[i] = 鱗;
            }else if(len(&(s[i*3]), "彷")){
                fontNames[i] = 彷;
            }else if(len(&(s[i*3]), "茸")){
                fontNames[i] = 茸;
            }else if(len(&(s[i*3]), "崖")){
                fontNames[i] = 崖;
            }else if(len(&(s[i*3]), "肘")){
                fontNames[i] = 肘;
            }else if(len(&(s[i*3]), "漆")){
                fontNames[i] = 漆;
            }else if(len(&(s[i*3]), "涛")){
                fontNames[i] = 涛;
            }else if(len(&(s[i*3]), "麿")){
                fontNames[i] = 麿;
            }else if(len(&(s[i*3]), "柑")){
                fontNames[i] = 柑;
            }else if(len(&(s[i*3]), "篭")){
                fontNames[i] = 篭;
            }else if(len(&(s[i*3]), "鵜")){
                fontNames[i] = 鵜;
            }else if(len(&(s[i*3]), "寅")){
                fontNames[i] = 寅;
            }else if(len(&(s[i*3]), "窒")){
                fontNames[i] = 窒;
            }else if(len(&(s[i*3]), "賄")){
                fontNames[i] = 賄;
            }else if(len(&(s[i*3]), "怨")){
                fontNames[i] = 怨;
            }else if(len(&(s[i*3]), "閑")){
                fontNames[i] = 閑;
            }else if(len(&(s[i*3]), "憫")){
                fontNames[i] = 憫;
            }else if(len(&(s[i*3]), "鎧")){
                fontNames[i] = 鎧;
            }else if(len(&(s[i*3]), "从")){
                fontNames[i] = 从;
            }else if(len(&(s[i*3]), "或")){
                fontNames[i] = 或;
            }else if(len(&(s[i*3]), "曾")){
                fontNames[i] = 曾;
            }else if(len(&(s[i*3]), "墜")){
                fontNames[i] = 墜;
            }else if(len(&(s[i*3]), "洩")){
                fontNames[i] = 洩;
            }else if(len(&(s[i*3]), "朔")){
                fontNames[i] = 朔;
            }else if(len(&(s[i*3]), "嶺")){
                fontNames[i] = 嶺;
            }else if(len(&(s[i*3]), "廿")){
                fontNames[i] = 廿;
            }else if(len(&(s[i*3]), "茄")){
                fontNames[i] = 茄;
            }else if(len(&(s[i*3]), "唾")){
                fontNames[i] = 唾;
            }else if(len(&(s[i*3]), "藻")){
                fontNames[i] = 藻;
            }else if(len(&(s[i*3]), "貪")){
                fontNames[i] = 貪;
            }else if(len(&(s[i*3]), "渦")){
                fontNames[i] = 渦;
            }else if(len(&(s[i*3]), "秤")){
                fontNames[i] = 秤;
            }else if(len(&(s[i*3]), "尉")){
                fontNames[i] = 尉;
            }else if(len(&(s[i*3]), "湊")){
                fontNames[i] = 湊;
            }else if(len(&(s[i*3]), "朽")){
                fontNames[i] = 朽;
            }else if(len(&(s[i*3]), "憐")){
                fontNames[i] = 憐;
            }else if(len(&(s[i*3]), "雫")){
                fontNames[i] = 雫;
            }else if(len(&(s[i*3]), "讐")){
                fontNames[i] = 讐;
            }else if(len(&(s[i*3]), "諾")){
                fontNames[i] = 諾;
            }else if(len(&(s[i*3]), "廉")){
                fontNames[i] = 廉;
            }else if(len(&(s[i*3]), "頁")){
                fontNames[i] = 頁;
            }else if(len(&(s[i*3]), "脆")){
                fontNames[i] = 脆;
            }else if(len(&(s[i*3]), "碗")){
                fontNames[i] = 碗;
            }else if(len(&(s[i*3]), "峠")){
                fontNames[i] = 峠;
            }else if(len(&(s[i*3]), "穿")){
                fontNames[i] = 穿;
            }else if(len(&(s[i*3]), "廣")){
                fontNames[i] = 廣;
            }else if(len(&(s[i*3]), "條")){
                fontNames[i] = 條;
            }else if(len(&(s[i*3]), "襟")){
                fontNames[i] = 襟;
            }else if(len(&(s[i*3]), "肛")){
                fontNames[i] = 肛;
            }else if(len(&(s[i*3]), "渕")){
                fontNames[i] = 渕;
            }else if(len(&(s[i*3]), "慧")){
                fontNames[i] = 慧;
            }else if(len(&(s[i*3]), "凪")){
                fontNames[i] = 凪;
            }else if(len(&(s[i*3]), "郭")){
                fontNames[i] = 郭;
            }else if(len(&(s[i*3]), "妃")){
                fontNames[i] = 妃;
            }else if(len(&(s[i*3]), "且")){
                fontNames[i] = 且;
            }else if(len(&(s[i*3]), "兜")){
                fontNames[i] = 兜;
            }else if(len(&(s[i*3]), "气")){
                fontNames[i] = 气;
            }else if(len(&(s[i*3]), "疹")){
                fontNames[i] = 疹;
            }else if(len(&(s[i*3]), "謳")){
                fontNames[i] = 謳;
            }else if(len(&(s[i*3]), "虜")){
                fontNames[i] = 虜;
            }else if(len(&(s[i*3]), "酌")){
                fontNames[i] = 酌;
            }else if(len(&(s[i*3]), "琶")){
                fontNames[i] = 琶;
            }else if(len(&(s[i*3]), "痕")){
                fontNames[i] = 痕;
            }else if(len(&(s[i*3]), "琵")){
                fontNames[i] = 琵;
            }else if(len(&(s[i*3]), "淀")){
                fontNames[i] = 淀;
            }else if(len(&(s[i*3]), "瞼")){
                fontNames[i] = 瞼;
            }else if(len(&(s[i*3]), "隼")){
                fontNames[i] = 隼;
            }else if(len(&(s[i*3]), "迂")){
                fontNames[i] = 迂;
            }else if(len(&(s[i*3]), "絢")){
                fontNames[i] = 絢;
            }else if(len(&(s[i*3]), "屮")){
                fontNames[i] = 屮;
            }else if(len(&(s[i*3]), "拐")){
                fontNames[i] = 拐;
            }else if(len(&(s[i*3]), "汐")){
                fontNames[i] = 汐;
            }else if(len(&(s[i*3]), "楠")){
                fontNames[i] = 楠;
            }else if(len(&(s[i*3]), "瀧")){
                fontNames[i] = 瀧;
            }else if(len(&(s[i*3]), "唆")){
                fontNames[i] = 唆;
            }else if(len(&(s[i*3]), "劉")){
                fontNames[i] = 劉;
            }else if(len(&(s[i*3]), "鞭")){
                fontNames[i] = 鞭;
            }else if(len(&(s[i*3]), "汲")){
                fontNames[i] = 汲;
            }else if(len(&(s[i*3]), "焉")){
                fontNames[i] = 焉;
            }else if(len(&(s[i*3]), "惣")){
                fontNames[i] = 惣;
            }else if(len(&(s[i*3]), "滾")){
                fontNames[i] = 滾;
            }else if(len(&(s[i*3]), "捐")){
                fontNames[i] = 捐;
            }else if(len(&(s[i*3]), "劫")){
                fontNames[i] = 劫;
            }else if(len(&(s[i*3]), "琥")){
                fontNames[i] = 琥;
            }else if(len(&(s[i*3]), "冨")){
                fontNames[i] = 冨;
            }else if(len(&(s[i*3]), "晦")){
                fontNames[i] = 晦;
            }else if(len(&(s[i*3]), "棺")){
                fontNames[i] = 棺;
            }else if(len(&(s[i*3]), "蝉")){
                fontNames[i] = 蝉;
            }else if(len(&(s[i*3]), "窟")){
                fontNames[i] = 窟;
            }else if(len(&(s[i*3]), "勲")){
                fontNames[i] = 勲;
            }else if(len(&(s[i*3]), "紘")){
                fontNames[i] = 紘;
            }else if(len(&(s[i*3]), "紬")){
                fontNames[i] = 紬;
            }else if(len(&(s[i*3]), "膏")){
                fontNames[i] = 膏;
            }else if(len(&(s[i*3]), "捗")){
                fontNames[i] = 捗;
            }else if(len(&(s[i*3]), "洪")){
                fontNames[i] = 洪;
            }else if(len(&(s[i*3]), "徊")){
                fontNames[i] = 徊;
            }else if(len(&(s[i*3]), "徘")){
                fontNames[i] = 徘;
            }else if(len(&(s[i*3]), "攣")){
                fontNames[i] = 攣;
            }else if(len(&(s[i*3]), "肴")){
                fontNames[i] = 肴;
            }else if(len(&(s[i*3]), "婿")){
                fontNames[i] = 婿;
            }else if(len(&(s[i*3]), "廷")){
                fontNames[i] = 廷;
            }else if(len(&(s[i*3]), "嘔")){
                fontNames[i] = 嘔;
            }else if(len(&(s[i*3]), "莫")){
                fontNames[i] = 莫;
            }else if(len(&(s[i*3]), "焚")){
                fontNames[i] = 焚;
            }else if(len(&(s[i*3]), "芥")){
                fontNames[i] = 芥;
            }else if(len(&(s[i*3]), "桶")){
                fontNames[i] = 桶;
            }else if(len(&(s[i*3]), "樋")){
                fontNames[i] = 樋;
            }else if(len(&(s[i*3]), "於")){
                fontNames[i] = 於;
            }else if(len(&(s[i*3]), "幣")){
                fontNames[i] = 幣;
            }else if(len(&(s[i*3]), "秦")){
                fontNames[i] = 秦;
            }else if(len(&(s[i*3]), "楓")){
                fontNames[i] = 楓;
            }else if(len(&(s[i*3]), "冤")){
                fontNames[i] = 冤;
            }else if(len(&(s[i*3]), "逐")){
                fontNames[i] = 逐;
            }else if(len(&(s[i*3]), "箋")){
                fontNames[i] = 箋;
            }else if(len(&(s[i*3]), "瑛")){
                fontNames[i] = 瑛;
            }else if(len(&(s[i*3]), "侑")){
                fontNames[i] = 侑;
            }else if(len(&(s[i*3]), "埃")){
                fontNames[i] = 埃;
            }else if(len(&(s[i*3]), "撰")){
                fontNames[i] = 撰;
            }else if(len(&(s[i*3]), "祓")){
                fontNames[i] = 祓;
            }else if(len(&(s[i*3]), "葱")){
                fontNames[i] = 葱;
            }else if(len(&(s[i*3]), "享")){
                fontNames[i] = 享;
            }else if(len(&(s[i*3]), "譚")){
                fontNames[i] = 譚;
            }else if(len(&(s[i*3]), "巴")){
                fontNames[i] = 巴;
            }else if(len(&(s[i*3]), "猶")){
                fontNames[i] = 猶;
            }else if(len(&(s[i*3]), "賽")){
                fontNames[i] = 賽;
            }else if(len(&(s[i*3]), "氣")){
                fontNames[i] = 氣;
            }else if(len(&(s[i*3]), "吃")){
                fontNames[i] = 吃;
            }else if(len(&(s[i*3]), "嬲")){
                fontNames[i] = 嬲;
            }else if(len(&(s[i*3]), "姑")){
                fontNames[i] = 姑;
            }else if(len(&(s[i*3]), "峨")){
                fontNames[i] = 峨;
            }else if(len(&(s[i*3]), "燕")){
                fontNames[i] = 燕;
            }else if(len(&(s[i*3]), "瓜")){
                fontNames[i] = 瓜;
            }else if(len(&(s[i*3]), "畠")){
                fontNames[i] = 畠;
            }else if(len(&(s[i*3]), "灘")){
                fontNames[i] = 灘;
            }else if(len(&(s[i*3]), "壺")){
                fontNames[i] = 壺;
            }else if(len(&(s[i*3]), "橙")){
                fontNames[i] = 橙;
            }else if(len(&(s[i*3]), "牌")){
                fontNames[i] = 牌;
            }else if(len(&(s[i*3]), "咥")){
                fontNames[i] = 咥;
            }else if(len(&(s[i*3]), "升")){
                fontNames[i] = 升;
            }else if(len(&(s[i*3]), "醍")){
                fontNames[i] = 醍;
            }else if(len(&(s[i*3]), "鼠")){
                fontNames[i] = 鼠;
            }else if(len(&(s[i*3]), "謂")){
                fontNames[i] = 謂;
            }else if(len(&(s[i*3]), "凜")){
                fontNames[i] = 凜;
            }else if(len(&(s[i*3]), "毅")){
                fontNames[i] = 毅;
            }else if(len(&(s[i*3]), "聯")){
                fontNames[i] = 聯;
            }else if(len(&(s[i*3]), "摯")){
                fontNames[i] = 摯;
            }else if(len(&(s[i*3]), "醐")){
                fontNames[i] = 醐;
            }else if(len(&(s[i*3]), "孕")){
                fontNames[i] = 孕;
            }else if(len(&(s[i*3]), "萬")){
                fontNames[i] = 萬;
            }else if(len(&(s[i*3]), "叙")){
                fontNames[i] = 叙;
            }else if(len(&(s[i*3]), "儚")){
                fontNames[i] = 儚;
            }else if(len(&(s[i*3]), "灸")){
                fontNames[i] = 灸;
            }else if(len(&(s[i*3]), "后")){
                fontNames[i] = 后;
            }else if(len(&(s[i*3]), "泌")){
                fontNames[i] = 泌;
            }else if(len(&(s[i*3]), "遷")){
                fontNames[i] = 遷;
            }else if(len(&(s[i*3]), "煌")){
                fontNames[i] = 煌;
            }else if(len(&(s[i*3]), "遜")){
                fontNames[i] = 遜;
            }else if(len(&(s[i*3]), "屓")){
                fontNames[i] = 屓;
            }else if(len(&(s[i*3]), "叉")){
                fontNames[i] = 叉;
            }else if(len(&(s[i*3]), "茉")){
                fontNames[i] = 茉;
            }else if(len(&(s[i*3]), "貶")){
                fontNames[i] = 貶;
            }else if(len(&(s[i*3]), "峡")){
                fontNames[i] = 峡;
            }else if(len(&(s[i*3]), "贔")){
                fontNames[i] = 贔;
            }else if(len(&(s[i*3]), "臼")){
                fontNames[i] = 臼;
            }else if(len(&(s[i*3]), "睦")){
                fontNames[i] = 睦;
            }else if(len(&(s[i*3]), "鍼")){
                fontNames[i] = 鍼;
            }else if(len(&(s[i*3]), "榊")){
                fontNames[i] = 榊;
            }else if(len(&(s[i*3]), "雌")){
                fontNames[i] = 雌;
            }else if(len(&(s[i*3]), "渚")){
                fontNames[i] = 渚;
            }else if(len(&(s[i*3]), "漕")){
                fontNames[i] = 漕;
            }else if(len(&(s[i*3]), "邉")){
                fontNames[i] = 邉;
            }else if(len(&(s[i*3]), "俄")){
                fontNames[i] = 俄;
            }else if(len(&(s[i*3]), "頷")){
                fontNames[i] = 頷;
            }else if(len(&(s[i*3]), "坐")){
                fontNames[i] = 坐;
            }else if(len(&(s[i*3]), "嘲")){
                fontNames[i] = 嘲;
            }else if(len(&(s[i*3]), "轢")){
                fontNames[i] = 轢;
            }else if(len(&(s[i*3]), "縞")){
                fontNames[i] = 縞;
            }else if(len(&(s[i*3]), "闊")){
                fontNames[i] = 闊;
            }else if(len(&(s[i*3]), "蒙")){
                fontNames[i] = 蒙;
            }else if(len(&(s[i*3]), "隕")){
                fontNames[i] = 隕;
            }else if(len(&(s[i*3]), "惧")){
                fontNames[i] = 惧;
            }else if(len(&(s[i*3]), "涌")){
                fontNames[i] = 涌;
            }else if(len(&(s[i*3]), "嗣")){
                fontNames[i] = 嗣;
            }else if(len(&(s[i*3]), "隻")){
                fontNames[i] = 隻;
            }else if(len(&(s[i*3]), "玖")){
                fontNames[i] = 玖;
            }else if(len(&(s[i*3]), "倖")){
                fontNames[i] = 倖;
            }else if(len(&(s[i*3]), "彙")){
                fontNames[i] = 彙;
            }else if(len(&(s[i*3]), "蛛")){
                fontNames[i] = 蛛;
            }else if(len(&(s[i*3]), "蛙")){
                fontNames[i] = 蛙;
            }else if(len(&(s[i*3]), "樺")){
                fontNames[i] = 樺;
            }else if(len(&(s[i*3]), "陀")){
                fontNames[i] = 陀;
            }else if(len(&(s[i*3]), "絹")){
                fontNames[i] = 絹;
            }else if(len(&(s[i*3]), "鞘")){
                fontNames[i] = 鞘;
            }else if(len(&(s[i*3]), "蒟")){
                fontNames[i] = 蒟;
            }else if(len(&(s[i*3]), "帖")){
                fontNames[i] = 帖;
            }else if(len(&(s[i*3]), "蒻")){
                fontNames[i] = 蒻;
            }else if(len(&(s[i*3]), "慄")){
                fontNames[i] = 慄;
            }else if(len(&(s[i*3]), "蜘")){
                fontNames[i] = 蜘;
            }else if(len(&(s[i*3]), "釧")){
                fontNames[i] = 釧;
            }else if(len(&(s[i*3]), "藝")){
                fontNames[i] = 藝;
            }else if(len(&(s[i*3]), "蔓")){
                fontNames[i] = 蔓;
            }else if(len(&(s[i*3]), "渓")){
                fontNames[i] = 渓;
            }else if(len(&(s[i*3]), "翫")){
                fontNames[i] = 翫;
            }else if(len(&(s[i*3]), "沌")){
                fontNames[i] = 沌;
            }else if(len(&(s[i*3]), "艇")){
                fontNames[i] = 艇;
            }else if(len(&(s[i*3]), "俵")){
                fontNames[i] = 俵;
            }else if(len(&(s[i*3]), "唖")){
                fontNames[i] = 唖;
            }else if(len(&(s[i*3]), "腑")){
                fontNames[i] = 腑;
            }else if(len(&(s[i*3]), "蔭")){
                fontNames[i] = 蔭;
            }else if(len(&(s[i*3]), "枢")){
                fontNames[i] = 枢;
            }else if(len(&(s[i*3]), "賜")){
                fontNames[i] = 賜;
            }else if(len(&(s[i*3]), "竿")){
                fontNames[i] = 竿;
            }else if(len(&(s[i*3]), "壷")){
                fontNames[i] = 壷;
            }else if(len(&(s[i*3]), "峯")){
                fontNames[i] = 峯;
            }else if(len(&(s[i*3]), "腿")){
                fontNames[i] = 腿;
            }else if(len(&(s[i*3]), "扶")){
                fontNames[i] = 扶;
            }else if(len(&(s[i*3]), "衡")){
                fontNames[i] = 衡;
            }else if(len(&(s[i*3]), "鉾")){
                fontNames[i] = 鉾;
            }else if(len(&(s[i*3]), "孵")){
                fontNames[i] = 孵;
            }else if(len(&(s[i*3]), "瘍")){
                fontNames[i] = 瘍;
            }else if(len(&(s[i*3]), "轄")){
                fontNames[i] = 轄;
            }else if(len(&(s[i*3]), "瀕")){
                fontNames[i] = 瀕;
            }else if(len(&(s[i*3]), "嵌")){
                fontNames[i] = 嵌;
            }else if(len(&(s[i*3]), "奔")){
                fontNames[i] = 奔;
            }else if(len(&(s[i*3]), "腎")){
                fontNames[i] = 腎;
            }else if(len(&(s[i*3]), "閥")){
                fontNames[i] = 閥;
            }else if(len(&(s[i*3]), "藩")){
                fontNames[i] = 藩;
            }else if(len(&(s[i*3]), "繕")){
                fontNames[i] = 繕;
            }else if(len(&(s[i*3]), "魁")){
                fontNames[i] = 魁;
            }else if(len(&(s[i*3]), "梗")){
                fontNames[i] = 梗;
            }else if(len(&(s[i*3]), "播")){
                fontNames[i] = 播;
            }else if(len(&(s[i*3]), "豹")){
                fontNames[i] = 豹;
            }else if(len(&(s[i*3]), "妓")){
                fontNames[i] = 妓;
            }else if(len(&(s[i*3]), "轟")){
                fontNames[i] = 轟;
            }else if(len(&(s[i*3]), "蟲")){
                fontNames[i] = 蟲;
            }else if(len(&(s[i*3]), "蒔")){
                fontNames[i] = 蒔;
            }else if(len(&(s[i*3]), "汎")){
                fontNames[i] = 汎;
            }else if(len(&(s[i*3]), "燗")){
                fontNames[i] = 燗;
            }else if(len(&(s[i*3]), "侶")){
                fontNames[i] = 侶;
            }else if(len(&(s[i*3]), "滲")){
                fontNames[i] = 滲;
            }else if(len(&(s[i*3]), "狸")){
                fontNames[i] = 狸;
            }else if(len(&(s[i*3]), "紡")){
                fontNames[i] = 紡;
            }else if(len(&(s[i*3]), "蓬")){
                fontNames[i] = 蓬;
            }else if(len(&(s[i*3]), "渾")){
                fontNames[i] = 渾;
            }else if(len(&(s[i*3]), "昏")){
                fontNames[i] = 昏;
            }else if(len(&(s[i*3]), "蟻")){
                fontNames[i] = 蟻;
            }else if(len(&(s[i*3]), "錆")){
                fontNames[i] = 錆;
            }else if(len(&(s[i*3]), "旺")){
                fontNames[i] = 旺;
            }else if(len(&(s[i*3]), "斑")){
                fontNames[i] = 斑;
            }else if(len(&(s[i*3]), "喩")){
                fontNames[i] = 喩;
            }else if(len(&(s[i*3]), "樫")){
                fontNames[i] = 樫;
            }else if(len(&(s[i*3]), "苫")){
                fontNames[i] = 苫;
            }else if(len(&(s[i*3]), "裟")){
                fontNames[i] = 裟;
            }else if(len(&(s[i*3]), "繍")){
                fontNames[i] = 繍;
            }else if(len(&(s[i*3]), "淑")){
                fontNames[i] = 淑;
            }else if(len(&(s[i*3]), "牽")){
                fontNames[i] = 牽;
            }else if(len(&(s[i*3]), "鰻")){
                fontNames[i] = 鰻;
            }else if(len(&(s[i*3]), "齋")){
                fontNames[i] = 齋;
            }else if(len(&(s[i*3]), "鷺")){
                fontNames[i] = 鷺;
            }else if(len(&(s[i*3]), "昴")){
                fontNames[i] = 昴;
            }else if(len(&(s[i*3]), "迦")){
                fontNames[i] = 迦;
            }else if(len(&(s[i*3]), "葎")){
                fontNames[i] = 葎;
            }else if(len(&(s[i*3]), "訛")){
                fontNames[i] = 訛;
            }else if(len(&(s[i*3]), "肖")){
                fontNames[i] = 肖;
            }else if(len(&(s[i*3]), "儘")){
                fontNames[i] = 儘;
            }else if(len(&(s[i*3]), "銚")){
                fontNames[i] = 銚;
            }else if(len(&(s[i*3]), "祇")){
                fontNames[i] = 祇;
            }else if(len(&(s[i*3]), "餡")){
                fontNames[i] = 餡;
            }else if(len(&(s[i*3]), "蠍")){
                fontNames[i] = 蠍;
            }else if(len(&(s[i*3]), "填")){
                fontNames[i] = 填;
            }else if(len(&(s[i*3]), "彿")){
                fontNames[i] = 彿;
            }else if(len(&(s[i*3]), "浣")){
                fontNames[i] = 浣;
            }else if(len(&(s[i*3]), "夷")){
                fontNames[i] = 夷;
            }else if(len(&(s[i*3]), "麟")){
                fontNames[i] = 麟;
            }else if(len(&(s[i*3]), "茜")){
                fontNames[i] = 茜;
            }else if(len(&(s[i*3]), "痙")){
                fontNames[i] = 痙;
            }else if(len(&(s[i*3]), "鮫")){
                fontNames[i] = 鮫;
            }else if(len(&(s[i*3]), "訃")){
                fontNames[i] = 訃;
            }else if(len(&(s[i*3]), "栞")){
                fontNames[i] = 栞;
            }else if(len(&(s[i*3]), "糾")){
                fontNames[i] = 糾;
            }else if(len(&(s[i*3]), "巷")){
                fontNames[i] = 巷;
            }else if(len(&(s[i*3]), "斧")){
                fontNames[i] = 斧;
            }else if(len(&(s[i*3]), "碑")){
                fontNames[i] = 碑;
            }else if(len(&(s[i*3]), "朧")){
                fontNames[i] = 朧;
            }else if(len(&(s[i*3]), "凱")){
                fontNames[i] = 凱;
            }else if(len(&(s[i*3]), "珀")){
                fontNames[i] = 珀;
            }else if(len(&(s[i*3]), "仇")){
                fontNames[i] = 仇;
            }else if(len(&(s[i*3]), "禄")){
                fontNames[i] = 禄;
            }else if(len(&(s[i*3]), "榎")){
                fontNames[i] = 榎;
            }else if(len(&(s[i*3]), "粕")){
                fontNames[i] = 粕;
            }else if(len(&(s[i*3]), "躾")){
                fontNames[i] = 躾;
            }else if(len(&(s[i*3]), "踪")){
                fontNames[i] = 踪;
            }else if(len(&(s[i*3]), "咎")){
                fontNames[i] = 咎;
            }else if(len(&(s[i*3]), "穢")){
                fontNames[i] = 穢;
            }else if(len(&(s[i*3]), "柊")){
                fontNames[i] = 柊;
            }else if(len(&(s[i*3]), "癶")){
                fontNames[i] = 癶;
            }else if(len(&(s[i*3]), "輿")){
                fontNames[i] = 輿;
            }else if(len(&(s[i*3]), "汝")){
                fontNames[i] = 汝;
            }else if(len(&(s[i*3]), "抄")){
                fontNames[i] = 抄;
            }else if(len(&(s[i*3]), "逗")){
                fontNames[i] = 逗;
            }else if(len(&(s[i*3]), "怜")){
                fontNames[i] = 怜;
            }else if(len(&(s[i*3]), "爛")){
                fontNames[i] = 爛;
            }else if(len(&(s[i*3]), "菩")){
                fontNames[i] = 菩;
            }else if(len(&(s[i*3]), "儂")){
                fontNames[i] = 儂;
            }else if(len(&(s[i*3]), "罹")){
                fontNames[i] = 罹;
            }else if(len(&(s[i*3]), "膣")){
                fontNames[i] = 膣;
            }else if(len(&(s[i*3]), "唸")){
                fontNames[i] = 唸;
            }else if(len(&(s[i*3]), "灼")){
                fontNames[i] = 灼;
            }else if(len(&(s[i*3]), "帥")){
                fontNames[i] = 帥;
            }else if(len(&(s[i*3]), "燈")){
                fontNames[i] = 燈;
            }else if(len(&(s[i*3]), "柘")){
                fontNames[i] = 柘;
            }else if(len(&(s[i*3]), "剖")){
                fontNames[i] = 剖;
            }else if(len(&(s[i*3]), "咽")){
                fontNames[i] = 咽;
            }else if(len(&(s[i*3]), "牢")){
                fontNames[i] = 牢;
            }else if(len(&(s[i*3]), "姻")){
                fontNames[i] = 姻;
            }else if(len(&(s[i*3]), "嬌")){
                fontNames[i] = 嬌;
            }else if(len(&(s[i*3]), "亞")){
                fontNames[i] = 亞;
            }else if(len(&(s[i*3]), "膿")){
                fontNames[i] = 膿;
            }else if(len(&(s[i*3]), "岬")){
                fontNames[i] = 岬;
            }else if(len(&(s[i*3]), "墟")){
                fontNames[i] = 墟;
            }else if(len(&(s[i*3]), "袈")){
                fontNames[i] = 袈;
            }else if(len(&(s[i*3]), "坦")){
                fontNames[i] = 坦;
            }else if(len(&(s[i*3]), "鶯")){
                fontNames[i] = 鶯;
            }else if(len(&(s[i*3]), "伽")){
                fontNames[i] = 伽;
            }else if(len(&(s[i*3]), "悸")){
                fontNames[i] = 悸;
            }else if(len(&(s[i*3]), "槙")){
                fontNames[i] = 槙;
            }else if(len(&(s[i*3]), "贄")){
                fontNames[i] = 贄;
            }else if(len(&(s[i*3]), "腱")){
                fontNames[i] = 腱;
            }else if(len(&(s[i*3]), "捌")){
                fontNames[i] = 捌;
            }else if(len(&(s[i*3]), "學")){
                fontNames[i] = 學;
            }else if(len(&(s[i*3]), "俯")){
                fontNames[i] = 俯;
            }else if(len(&(s[i*3]), "螺")){
                fontNames[i] = 螺;
            }else if(len(&(s[i*3]), "焔")){
                fontNames[i] = 焔;
            }else if(len(&(s[i*3]), "鰹")){
                fontNames[i] = 鰹;
            }else if(len(&(s[i*3]), "炙")){
                fontNames[i] = 炙;
            }else if(len(&(s[i*3]), "硝")){
                fontNames[i] = 硝;
            }else if(len(&(s[i*3]), "凰")){
                fontNames[i] = 凰;
            }else if(len(&(s[i*3]), "禍")){
                fontNames[i] = 禍;
            }else if(len(&(s[i*3]), "靭")){
                fontNames[i] = 靭;
            }else if(len(&(s[i*3]), "珂")){
                fontNames[i] = 珂;
            }else if(len(&(s[i*3]), "憾")){
                fontNames[i] = 憾;
            }else if(len(&(s[i*3]), "采")){
                fontNames[i] = 采;
            }else if(len(&(s[i*3]), "麹")){
                fontNames[i] = 麹;
            }else if(len(&(s[i*3]), "丑")){
                fontNames[i] = 丑;
            }else if(len(&(s[i*3]), "騨")){
                fontNames[i] = 騨;
            }else if(len(&(s[i*3]), "汽")){
                fontNames[i] = 汽;
            }else if(len(&(s[i*3]), "乂")){
                fontNames[i] = 乂;
            }else if(len(&(s[i*3]), "黎")){
                fontNames[i] = 黎;
            }else if(len(&(s[i*3]), "宍")){
                fontNames[i] = 宍;
            }else if(len(&(s[i*3]), "吶")){
                fontNames[i] = 吶;
            }else if(len(&(s[i*3]), "鰤")){
                fontNames[i] = 鰤;
            }else if(len(&(s[i*3]), "瞭")){
                fontNames[i] = 瞭;
            }else if(len(&(s[i*3]), "漱")){
                fontNames[i] = 漱;
            }else if(len(&(s[i*3]), "硫")){
                fontNames[i] = 硫;
            }else if(len(&(s[i*3]), "鴉")){
                fontNames[i] = 鴉;
            }else if(len(&(s[i*3]), "雁")){
                fontNames[i] = 雁;
            }else if(len(&(s[i*3]), "窯")){
                fontNames[i] = 窯;
            }else if(len(&(s[i*3]), "稔")){
                fontNames[i] = 稔;
            }else if(len(&(s[i*3]), "芹")){
                fontNames[i] = 芹;
            }else if(len(&(s[i*3]), "脊")){
                fontNames[i] = 脊;
            }else if(len(&(s[i*3]), "涎")){
                fontNames[i] = 涎;
            }else if(len(&(s[i*3]), "莱")){
                fontNames[i] = 莱;
            }else if(len(&(s[i*3]), "卿")){
                fontNames[i] = 卿;
            }else if(len(&(s[i*3]), "酪")){
                fontNames[i] = 酪;
            }else if(len(&(s[i*3]), "鵬")){
                fontNames[i] = 鵬;
            }else if(len(&(s[i*3]), "泄")){
                fontNames[i] = 泄;
            }else if(len(&(s[i*3]), "頸")){
                fontNames[i] = 頸;
            }else if(len(&(s[i*3]), "麒")){
                fontNames[i] = 麒;
            }else if(len(&(s[i*3]), "錫")){
                fontNames[i] = 錫;
            }else if(len(&(s[i*3]), "楢")){
                fontNames[i] = 楢;
            }else if(len(&(s[i*3]), "團")){
                fontNames[i] = 團;
            }else if(len(&(s[i*3]), "會")){
                fontNames[i] = 會;
            }else if(len(&(s[i*3]), "塀")){
                fontNames[i] = 塀;
            }else if(len(&(s[i*3]), "畏")){
                fontNames[i] = 畏;
            }else if(len(&(s[i*3]), "巌")){
                fontNames[i] = 巌;
            }else if(len(&(s[i*3]), "蝋")){
                fontNames[i] = 蝋;
            }else if(len(&(s[i*3]), "琢")){
                fontNames[i] = 琢;
            }else if(len(&(s[i*3]), "祟")){
                fontNames[i] = 祟;
            }else if(len(&(s[i*3]), "倣")){
                fontNames[i] = 倣;
            }else if(len(&(s[i*3]), "肋")){
                fontNames[i] = 肋;
            }else if(len(&(s[i*3]), "蝕")){
                fontNames[i] = 蝕;
            }else if(len(&(s[i*3]), "藁")){
                fontNames[i] = 藁;
            }else if(len(&(s[i*3]), "几")){
                fontNames[i] = 几;
            }else if(len(&(s[i*3]), "腔")){
                fontNames[i] = 腔;
            }else if(len(&(s[i*3]), "叢")){
                fontNames[i] = 叢;
            }else if(len(&(s[i*3]), "檻")){
                fontNames[i] = 檻;
            }else if(len(&(s[i*3]), "邊")){
                fontNames[i] = 邊;
            }else if(len(&(s[i*3]), "皐")){
                fontNames[i] = 皐;
            }else if(len(&(s[i*3]), "箕")){
                fontNames[i] = 箕;
            }else if(len(&(s[i*3]), "傭")){
                fontNames[i] = 傭;
            }else if(len(&(s[i*3]), "駕")){
                fontNames[i] = 駕;
            }else if(len(&(s[i*3]), "薪")){
                fontNames[i] = 薪;
            }else if(len(&(s[i*3]), "褌")){
                fontNames[i] = 褌;
            }else if(len(&(s[i*3]), "已")){
                fontNames[i] = 已;
            }else if(len(&(s[i*3]), "屯")){
                fontNames[i] = 屯;
            }else if(len(&(s[i*3]), "鍾")){
                fontNames[i] = 鍾;
            }else if(len(&(s[i*3]), "檜")){
                fontNames[i] = 檜;
            }else if(len(&(s[i*3]), "懺")){
                fontNames[i] = 懺;
            }else if(len(&(s[i*3]), "濤")){
                fontNames[i] = 濤;
            }else if(len(&(s[i*3]), "筐")){
                fontNames[i] = 筐;
            }else if(len(&(s[i*3]), "昂")){
                fontNames[i] = 昂;
            }else if(len(&(s[i*3]), "楊")){
                fontNames[i] = 楊;
            }else if(len(&(s[i*3]), "蕾")){
                fontNames[i] = 蕾;
            }else if(len(&(s[i*3]), "閻")){
                fontNames[i] = 閻;
            }else if(len(&(s[i*3]), "砥")){
                fontNames[i] = 砥;
            }else if(len(&(s[i*3]), "膀")){
                fontNames[i] = 膀;
            }else if(len(&(s[i*3]), "掟")){
                fontNames[i] = 掟;
            }else if(len(&(s[i*3]), "櫂")){
                fontNames[i] = 櫂;
            }else if(len(&(s[i*3]), "胱")){
                fontNames[i] = 胱;
            }else if(len(&(s[i*3]), "檀")){
                fontNames[i] = 檀;
            }else if(len(&(s[i*3]), "堵")){
                fontNames[i] = 堵;
            }else if(len(&(s[i*3]), "奄")){
                fontNames[i] = 奄;
            }else if(len(&(s[i*3]), "漸")){
                fontNames[i] = 漸;
            }else if(len(&(s[i*3]), "睫")){
                fontNames[i] = 睫;
            }else if(len(&(s[i*3]), "窶")){
                fontNames[i] = 窶;
            }else if(len(&(s[i*3]), "迭")){
                fontNames[i] = 迭;
            }else if(len(&(s[i*3]), "榴")){
                fontNames[i] = 榴;
            }else if(len(&(s[i*3]), "柵")){
                fontNames[i] = 柵;
            }else if(len(&(s[i*3]), "扁")){
                fontNames[i] = 扁;
            }else if(len(&(s[i*3]), "滸")){
                fontNames[i] = 滸;
            }else if(len(&(s[i*3]), "鞍")){
                fontNames[i] = 鞍;
            }else if(len(&(s[i*3]), "徨")){
                fontNames[i] = 徨;
            }else if(len(&(s[i*3]), "逞")){
                fontNames[i] = 逞;
            }else if(len(&(s[i*3]), "殲")){
                fontNames[i] = 殲;
            }else if(len(&(s[i*3]), "鱈")){
                fontNames[i] = 鱈;
            }else if(len(&(s[i*3]), "厭")){
                fontNames[i] = 厭;
            }else if(len(&(s[i*3]), "蝿")){
                fontNames[i] = 蝿;
            }else if(len(&(s[i*3]), "梯")){
                fontNames[i] = 梯;
            }else if(len(&(s[i*3]), "繚")){
                fontNames[i] = 繚;
            }else if(len(&(s[i*3]), "祀")){
                fontNames[i] = 祀;
            }else if(len(&(s[i*3]), "謗")){
                fontNames[i] = 謗;
            }else if(len(&(s[i*3]), "綜")){
                fontNames[i] = 綜;
            }else if(len(&(s[i*3]), "哺")){
                fontNames[i] = 哺;
            }else if(len(&(s[i*3]), "侯")){
                fontNames[i] = 侯;
            }else if(len(&(s[i*3]), "冫")){
                fontNames[i] = 冫;
            }else if(len(&(s[i*3]), "个")){
                fontNames[i] = 个;
            }else if(len(&(s[i*3]), "馨")){
                fontNames[i] = 馨;
            }else if(len(&(s[i*3]), "恰")){
                fontNames[i] = 恰;
            }else if(len(&(s[i*3]), "琳")){
                fontNames[i] = 琳;
            }else if(len(&(s[i*3]), "燻")){
                fontNames[i] = 燻;
            }else if(len(&(s[i*3]), "佃")){
                fontNames[i] = 佃;
            }else if(len(&(s[i*3]), "箔")){
                fontNames[i] = 箔;
            }else if(len(&(s[i*3]), "疼")){
                fontNames[i] = 疼;
            }else if(len(&(s[i*3]), "梵")){
                fontNames[i] = 梵;
            }else if(len(&(s[i*3]), "捲")){
                fontNames[i] = 捲;
            }else if(len(&(s[i*3]), "跨")){
                fontNames[i] = 跨;
            }else if(len(&(s[i*3]), "沁")){
                fontNames[i] = 沁;
            }else if(len(&(s[i*3]), "賓")){
                fontNames[i] = 賓;
            }else if(len(&(s[i*3]), "杭")){
                fontNames[i] = 杭;
            }else if(len(&(s[i*3]), "椛")){
                fontNames[i] = 椛;
            }else if(len(&(s[i*3]), "檄")){
                fontNames[i] = 檄;
            }else if(len(&(s[i*3]), "鴻")){
                fontNames[i] = 鴻;
            }else if(len(&(s[i*3]), "脛")){
                fontNames[i] = 脛;
            }else if(len(&(s[i*3]), "麓")){
                fontNames[i] = 麓;
            }else if(len(&(s[i*3]), "頒")){
                fontNames[i] = 頒;
            }else if(len(&(s[i*3]), "淘")){
                fontNames[i] = 淘;
            }else if(len(&(s[i*3]), "董")){
                fontNames[i] = 董;
            }else if(len(&(s[i*3]), "魏")){
                fontNames[i] = 魏;
            }else if(len(&(s[i*3]), "邑")){
                fontNames[i] = 邑;
            }else if(len(&(s[i*3]), "砦")){
                fontNames[i] = 砦;
            }else if(len(&(s[i*3]), "恣")){
                fontNames[i] = 恣;
            }else if(len(&(s[i*3]), "誹")){
                fontNames[i] = 誹;
            }else if(len(&(s[i*3]), "耽")){
                fontNames[i] = 耽;
            }else if(len(&(s[i*3]), "峙")){
                fontNames[i] = 峙;
            }else if(len(&(s[i*3]), "俸")){
                fontNames[i] = 俸;
            }else if(len(&(s[i*3]), "趙")){
                fontNames[i] = 趙;
            }else if(len(&(s[i*3]), "佇")){
                fontNames[i] = 佇;
            }else if(len(&(s[i*3]), "倦")){
                fontNames[i] = 倦;
            }else if(len(&(s[i*3]), "勾")){
                fontNames[i] = 勾;
            }else if(len(&(s[i*3]), "粟")){
                fontNames[i] = 粟;
            }else if(len(&(s[i*3]), "筍")){
                fontNames[i] = 筍;
            }else if(len(&(s[i*3]), "暢")){
                fontNames[i] = 暢;
            }else if(len(&(s[i*3]), "牟")){
                fontNames[i] = 牟;
            }else if(len(&(s[i*3]), "恫")){
                fontNames[i] = 恫;
            }else if(len(&(s[i*3]), "萃")){
                fontNames[i] = 萃;
            }else if(len(&(s[i*3]), "伍")){
                fontNames[i] = 伍;
            }else if(len(&(s[i*3]), "揶")){
                fontNames[i] = 揶;
            }else if(len(&(s[i*3]), "鰐")){
                fontNames[i] = 鰐;
            }else if(len(&(s[i*3]), "顏")){
                fontNames[i] = 顏;
            }else if(len(&(s[i*3]), "很")){
                fontNames[i] = 很;
            }else if(len(&(s[i*3]), "嚇")){
                fontNames[i] = 嚇;
            }else if(len(&(s[i*3]), "揄")){
                fontNames[i] = 揄;
            }else if(len(&(s[i*3]), "燵")){
                fontNames[i] = 燵;
            }else if(len(&(s[i*3]), "彗")){
                fontNames[i] = 彗;
            }else if(len(&(s[i*3]), "濫")){
                fontNames[i] = 濫;
            }else if(len(&(s[i*3]), "摺")){
                fontNames[i] = 摺;
            }else if(len(&(s[i*3]), "炬")){
                fontNames[i] = 炬;
            }else if(len(&(s[i*3]), "蜷")){
                fontNames[i] = 蜷;
            }else if(len(&(s[i*3]), "羹")){
                fontNames[i] = 羹;
            }else if(len(&(s[i*3]), "乖")){
                fontNames[i] = 乖;
            }else if(len(&(s[i*3]), "寡")){
                fontNames[i] = 寡;
            }else if(len(&(s[i*3]), "薮")){
                fontNames[i] = 薮;
            }else if(len(&(s[i*3]), "匚")){
                fontNames[i] = 匚;
            }else if(len(&(s[i*3]), "庇")){
                fontNames[i] = 庇;
            }else if(len(&(s[i*3]), "屏")){
                fontNames[i] = 屏;
            }else if(len(&(s[i*3]), "冲")){
                fontNames[i] = 冲;
            }else if(len(&(s[i*3]), "狛")){
                fontNames[i] = 狛;
            }else if(len(&(s[i*3]), "侠")){
                fontNames[i] = 侠;
            }else if(len(&(s[i*3]), "褻")){
                fontNames[i] = 褻;
            }else if(len(&(s[i*3]), "麩")){
                fontNames[i] = 麩;
            }else if(len(&(s[i*3]), "叡")){
                fontNames[i] = 叡;
            }else if(len(&(s[i*3]), "褐")){
                fontNames[i] = 褐;
            }else if(len(&(s[i*3]), "穹")){
                fontNames[i] = 穹;
            }else if(len(&(s[i*3]), "瑚")){
                fontNames[i] = 瑚;
            }else if(len(&(s[i*3]), "翁")){
                fontNames[i] = 翁;
            }else if(len(&(s[i*3]), "囃")){
                fontNames[i] = 囃;
            }else if(len(&(s[i*3]), "靡")){
                fontNames[i] = 靡;
            }else if(len(&(s[i*3]), "冑")){
                fontNames[i] = 冑;
            }else if(len(&(s[i*3]), "葡")){
                fontNames[i] = 葡;
            }else if(len(&(s[i*3]), "甦")){
                fontNames[i] = 甦;
            }else if(len(&(s[i*3]), "庸")){
                fontNames[i] = 庸;
            }else if(len(&(s[i*3]), "毀")){
                fontNames[i] = 毀;
            }else if(len(&(s[i*3]), "蕁")){
                fontNames[i] = 蕁;
            }else if(len(&(s[i*3]), "冶")){
                fontNames[i] = 冶;
            }else if(len(&(s[i*3]), "磔")){
                fontNames[i] = 磔;
            }else if(len(&(s[i*3]), "揆")){
                fontNames[i] = 揆;
            }else if(len(&(s[i*3]), "躁")){
                fontNames[i] = 躁;
            }else if(len(&(s[i*3]), "喬")){
                fontNames[i] = 喬;
            }else if(len(&(s[i*3]), "憬")){
                fontNames[i] = 憬;
            }else if(len(&(s[i*3]), "芭")){
                fontNames[i] = 芭;
            }else if(len(&(s[i*3]), "卦")){
                fontNames[i] = 卦;
            }else if(len(&(s[i*3]), "諜")){
                fontNames[i] = 諜;
            }else if(len(&(s[i*3]), "孟")){
                fontNames[i] = 孟;
            }else if(len(&(s[i*3]), "弔")){
                fontNames[i] = 弔;
            }else if(len(&(s[i*3]), "焙")){
                fontNames[i] = 焙;
            }else if(len(&(s[i*3]), "墳")){
                fontNames[i] = 墳;
            }else if(len(&(s[i*3]), "瞰")){
                fontNames[i] = 瞰;
            }else if(len(&(s[i*3]), "殉")){
                fontNames[i] = 殉;
            }else if(len(&(s[i*3]), "諫")){
                fontNames[i] = 諫;
            }else if(len(&(s[i*3]), "辟")){
                fontNames[i] = 辟;
            }else if(len(&(s[i*3]), "爬")){
                fontNames[i] = 爬;
            }else if(len(&(s[i*3]), "蜀")){
                fontNames[i] = 蜀;
            }else if(len(&(s[i*3]), "樂")){
                fontNames[i] = 樂;
            }else if(len(&(s[i*3]), "餐")){
                fontNames[i] = 餐;
            }else if(len(&(s[i*3]), "辣")){
                fontNames[i] = 辣;
            }else if(len(&(s[i*3]), "牝")){
                fontNames[i] = 牝;
            }else if(len(&(s[i*3]), "酉")){
                fontNames[i] = 酉;
            }else if(len(&(s[i*3]), "煉")){
                fontNames[i] = 煉;
            }else if(len(&(s[i*3]), "蟄")){
                fontNames[i] = 蟄;
            }else if(len(&(s[i*3]), "朦")){
                fontNames[i] = 朦;
            }else if(len(&(s[i*3]), "而")){
                fontNames[i] = 而;
            }else if(len(&(s[i*3]), "竈")){
                fontNames[i] = 竈;
            }else if(len(&(s[i*3]), "萄")){
                fontNames[i] = 萄;
            }else if(len(&(s[i*3]), "蛾")){
                fontNames[i] = 蛾;
            }else if(len(&(s[i*3]), "撼")){
                fontNames[i] = 撼;
            }else if(len(&(s[i*3]), "藪")){
                fontNames[i] = 藪;
            }else if(len(&(s[i*3]), "桔")){
                fontNames[i] = 桔;
            }else if(len(&(s[i*3]), "軋")){
                fontNames[i] = 軋;
            }else if(len(&(s[i*3]), "吻")){
                fontNames[i] = 吻;
            }else if(len(&(s[i*3]), "鮨")){
                fontNames[i] = 鮨;
            }else if(len(&(s[i*3]), "荳")){
                fontNames[i] = 荳;
            }else if(len(&(s[i*3]), "菖")){
                fontNames[i] = 菖;
            }else if(len(&(s[i*3]), "緻")){
                fontNames[i] = 緻;
            }else if(len(&(s[i*3]), "燭")){
                fontNames[i] = 燭;
            }else if(len(&(s[i*3]), "噺")){
                fontNames[i] = 噺;
            }else if(len(&(s[i*3]), "舶")){
                fontNames[i] = 舶;
            }else if(len(&(s[i*3]), "穣")){
                fontNames[i] = 穣;
            }else if(len(&(s[i*3]), "欽")){
                fontNames[i] = 欽;
            }else if(len(&(s[i*3]), "舵")){
                fontNames[i] = 舵;
            }else if(len(&(s[i*3]), "裳")){
                fontNames[i] = 裳;
            }else if(len(&(s[i*3]), "惇")){
                fontNames[i] = 惇;
            }else if(len(&(s[i*3]), "榛")){
                fontNames[i] = 榛;
            }else if(len(&(s[i*3]), "仝")){
                fontNames[i] = 仝;
            }else if(len(&(s[i*3]), "鞠")){
                fontNames[i] = 鞠;
            }else if(len(&(s[i*3]), "曙")){
                fontNames[i] = 曙;
            }else if(len(&(s[i*3]), "僻")){
                fontNames[i] = 僻;
            }else if(len(&(s[i*3]), "餉")){
                fontNames[i] = 餉;
            }else if(len(&(s[i*3]), "腋")){
                fontNames[i] = 腋;
            }else if(len(&(s[i*3]), "丞")){
                fontNames[i] = 丞;
            }else if(len(&(s[i*3]), "惟")){
                fontNames[i] = 惟;
            }else if(len(&(s[i*3]), "敲")){
                fontNames[i] = 敲;
            }else if(len(&(s[i*3]), "厩")){
                fontNames[i] = 厩;
            }else if(len(&(s[i*3]), "咄")){
                fontNames[i] = 咄;
            }else if(len(&(s[i*3]), "嗟")){
                fontNames[i] = 嗟;
            }else if(len(&(s[i*3]), "哭")){
                fontNames[i] = 哭;
            }else if(len(&(s[i*3]), "譁")){
                fontNames[i] = 譁;
            }else if(len(&(s[i*3]), "廟")){
                fontNames[i] = 廟;
            }else if(len(&(s[i*3]), "皺")){
                fontNames[i] = 皺;
            }else if(len(&(s[i*3]), "棘")){
                fontNames[i] = 棘;
            }else if(len(&(s[i*3]), "逹")){
                fontNames[i] = 逹;
            }else if(len(&(s[i*3]), "霖")){
                fontNames[i] = 霖;
            }else if(len(&(s[i*3]), "翡")){
                fontNames[i] = 翡;
            }else if(len(&(s[i*3]), "蛸")){
                fontNames[i] = 蛸;
            }else if(len(&(s[i*3]), "臥")){
                fontNames[i] = 臥;
            }else if(len(&(s[i*3]), "嘗")){
                fontNames[i] = 嘗;
            }else if(len(&(s[i*3]), "戮")){
                fontNames[i] = 戮;
            }else if(len(&(s[i*3]), "凧")){
                fontNames[i] = 凧;
            }else if(len(&(s[i*3]), "漣")){
                fontNames[i] = 漣;
            }else if(len(&(s[i*3]), "絨")){
                fontNames[i] = 絨;
            }else if(len(&(s[i*3]), "枷")){
                fontNames[i] = 枷;
            }else if(len(&(s[i*3]), "瞞")){
                fontNames[i] = 瞞;
            }else if(len(&(s[i*3]), "鋳")){
                fontNames[i] = 鋳;
            }else if(len(&(s[i*3]), "爾")){
                fontNames[i] = 爾;
            }else if(len(&(s[i*3]), "哈")){
                fontNames[i] = 哈;
            }else if(len(&(s[i*3]), "涜")){
                fontNames[i] = 涜;
            }else if(len(&(s[i*3]), "憚")){
                fontNames[i] = 憚;
            }else if(len(&(s[i*3]), "疇")){
                fontNames[i] = 疇;
            }else if(len(&(s[i*3]), "洛")){
                fontNames[i] = 洛;
            }else if(len(&(s[i*3]), "撥")){
                fontNames[i] = 撥;
            }else if(len(&(s[i*3]), "發")){
                fontNames[i] = 發;
            }else if(len(&(s[i*3]), "斤")){
                fontNames[i] = 斤;
            }else if(len(&(s[i*3]), "與")){
                fontNames[i] = 與;
            }else if(len(&(s[i*3]), "蹊")){
                fontNames[i] = 蹊;
            }else if(len(&(s[i*3]), "糊")){
                fontNames[i] = 糊;
            }else if(len(&(s[i*3]), "壹")){
                fontNames[i] = 壹;
            }else if(len(&(s[i*3]), "裔")){
                fontNames[i] = 裔;
            }else if(len(&(s[i*3]), "什")){
                fontNames[i] = 什;
            }else if(len(&(s[i*3]), "蕩")){
                fontNames[i] = 蕩;
            }else if(len(&(s[i*3]), "套")){
                fontNames[i] = 套;
            }else if(len(&(s[i*3]), "褪")){
                fontNames[i] = 褪;
            }else if(len(&(s[i*3]), "蝦")){
                fontNames[i] = 蝦;
            }else if(len(&(s[i*3]), "灣")){
                fontNames[i] = 灣;
            }else if(len(&(s[i*3]), "櫛")){
                fontNames[i] = 櫛;
            }else if(len(&(s[i*3]), "弛")){
                fontNames[i] = 弛;
            }else if(len(&(s[i*3]), "珊")){
                fontNames[i] = 珊;
            }else if(len(&(s[i*3]), "驕")){
                fontNames[i] = 驕;
            }else if(len(&(s[i*3]), "毯")){
                fontNames[i] = 毯;
            }else if(len(&(s[i*3]), "沫")){
                fontNames[i] = 沫;
            }else if(len(&(s[i*3]), "嶽")){
                fontNames[i] = 嶽;
            }else if(len(&(s[i*3]), "擢")){
                fontNames[i] = 擢;
            }else if(len(&(s[i*3]), "稜")){
                fontNames[i] = 稜;
            }else if(len(&(s[i*3]), "轍")){
                fontNames[i] = 轍;
            }else if(len(&(s[i*3]), "咬")){
                fontNames[i] = 咬;
            }else if(len(&(s[i*3]), "碇")){
                fontNames[i] = 碇;
            }else if(len(&(s[i*3]), "蕉")){
                fontNames[i] = 蕉;
            }else if(len(&(s[i*3]), "繭")){
                fontNames[i] = 繭;
            }else if(len(&(s[i*3]), "娼")){
                fontNames[i] = 娼;
            }else if(len(&(s[i*3]), "妾")){
                fontNames[i] = 妾;
            }else if(len(&(s[i*3]), "弧")){
                fontNames[i] = 弧;
            }else if(len(&(s[i*3]), "鸞")){
                fontNames[i] = 鸞;
            }else if(len(&(s[i*3]), "涅")){
                fontNames[i] = 涅;
            }else if(len(&(s[i*3]), "詭")){
                fontNames[i] = 詭;
            }else if(len(&(s[i*3]), "杵")){
                fontNames[i] = 杵;
            }else if(len(&(s[i*3]), "侘")){
                fontNames[i] = 侘;
            }else if(len(&(s[i*3]), "癪")){
                fontNames[i] = 癪;
            }else if(len(&(s[i*3]), "礁")){
                fontNames[i] = 礁;
            }else if(len(&(s[i*3]), "款")){
                fontNames[i] = 款;
            }else if(len(&(s[i*3]), "坑")){
                fontNames[i] = 坑;
            }else if(len(&(s[i*3]), "遵")){
                fontNames[i] = 遵;
            }else if(len(&(s[i*3]), "鼎")){
                fontNames[i] = 鼎;
            }else if(len(&(s[i*3]), "濾")){
                fontNames[i] = 濾;
            }else if(len(&(s[i*3]), "毘")){
                fontNames[i] = 毘;
            }else if(len(&(s[i*3]), "屠")){
                fontNames[i] = 屠;
            }else if(len(&(s[i*3]), "槭")){
                fontNames[i] = 槭;
            }else if(len(&(s[i*3]), "攫")){
                fontNames[i] = 攫;
            }else if(len(&(s[i*3]), "魄")){
                fontNames[i] = 魄;
            }else if(len(&(s[i*3]), "鵠")){
                fontNames[i] = 鵠;
            }else if(len(&(s[i*3]), "鰯")){
                fontNames[i] = 鰯;
            }else if(len(&(s[i*3]), "躙")){
                fontNames[i] = 躙;
            }else if(len(&(s[i*3]), "螟")){
                fontNames[i] = 螟;
            }else if(len(&(s[i*3]), "箪")){
                fontNames[i] = 箪;
            }else if(len(&(s[i*3]), "槇")){
                fontNames[i] = 槇;
            }else if(len(&(s[i*3]), "蜃")){
                fontNames[i] = 蜃;
            }else if(len(&(s[i*3]), "壬")){
                fontNames[i] = 壬;
            }else if(len(&(s[i*3]), "宋")){
                fontNames[i] = 宋;
            }else if(len(&(s[i*3]), "莠")){
                fontNames[i] = 莠;
            }else if(len(&(s[i*3]), "帙")){
                fontNames[i] = 帙;
            }else if(len(&(s[i*3]), "狡")){
                fontNames[i] = 狡;
            }else if(len(&(s[i*3]), "賂")){
                fontNames[i] = 賂;
            }else if(len(&(s[i*3]), "斯")){
                fontNames[i] = 斯;
            }else if(len(&(s[i*3]), "輌")){
                fontNames[i] = 輌;
            }else if(len(&(s[i*3]), "邁")){
                fontNames[i] = 邁;
            }else if(len(&(s[i*3]), "匡")){
                fontNames[i] = 匡;
            }else if(len(&(s[i*3]), "釉")){
                fontNames[i] = 釉;
            }else if(len(&(s[i*3]), "曳")){
                fontNames[i] = 曳;
            }else if(len(&(s[i*3]), "魎")){
                fontNames[i] = 魎;
            }else if(len(&(s[i*3]), "咀")){
                fontNames[i] = 咀;
            }else if(len(&(s[i*3]), "啼")){
                fontNames[i] = 啼;
            }else if(len(&(s[i*3]), "丶")){
                fontNames[i] = 丶;
            }else if(len(&(s[i*3]), "逼")){
                fontNames[i] = 逼;
            }else if(len(&(s[i*3]), "圓")){
                fontNames[i] = 圓;
            }else if(len(&(s[i*3]), "攘")){
                fontNames[i] = 攘;
            }else if(len(&(s[i*3]), "椀")){
                fontNames[i] = 椀;
            }else if(len(&(s[i*3]), "畔")){
                fontNames[i] = 畔;
            }else if(len(&(s[i*3]), "痣")){
                fontNames[i] = 痣;
            }else if(len(&(s[i*3]), "鮪")){
                fontNames[i] = 鮪;
            }else if(len(&(s[i*3]), "倥")){
                fontNames[i] = 倥;
            }else if(len(&(s[i*3]), "亨")){
                fontNames[i] = 亨;
            }else if(len(&(s[i*3]), "痰")){
                fontNames[i] = 痰;
            }else if(len(&(s[i*3]), "壽")){
                fontNames[i] = 壽;
            }else if(len(&(s[i*3]), "蹂")){
                fontNames[i] = 蹂;
            }else if(len(&(s[i*3]), "齧")){
                fontNames[i] = 齧;
            }else if(len(&(s[i*3]), "抉")){
                fontNames[i] = 抉;
            }else if(len(&(s[i*3]), "蕨")){
                fontNames[i] = 蕨;
            }else if(len(&(s[i*3]), "饒")){
                fontNames[i] = 饒;
            }else if(len(&(s[i*3]), "暈")){
                fontNames[i] = 暈;
            }else if(len(&(s[i*3]), "棗")){
                fontNames[i] = 棗;
            }else if(len(&(s[i*3]), "衿")){
                fontNames[i] = 衿;
            }else if(len(&(s[i*3]), "杞")){
                fontNames[i] = 杞;
            }else if(len(&(s[i*3]), "烹")){
                fontNames[i] = 烹;
            }else if(len(&(s[i*3]), "氾")){
                fontNames[i] = 氾;
            }else if(len(&(s[i*3]), "戎")){
                fontNames[i] = 戎;
            }else if(len(&(s[i*3]), "嚼")){
                fontNames[i] = 嚼;
            }else if(len(&(s[i*3]), "甜")){
                fontNames[i] = 甜;
            }else if(len(&(s[i*3]), "槃")){
                fontNames[i] = 槃;
            }else if(len(&(s[i*3]), "鵺")){
                fontNames[i] = 鵺;
            }else if(len(&(s[i*3]), "娩")){
                fontNames[i] = 娩;
            }else if(len(&(s[i*3]), "燦")){
                fontNames[i] = 燦;
            }else if(len(&(s[i*3]), "閖")){
                fontNames[i] = 閖;
            }else if(len(&(s[i*3]), "勅")){
                fontNames[i] = 勅;
            }else if(len(&(s[i*3]), "躓")){
                fontNames[i] = 躓;
            }else if(len(&(s[i*3]), "恍")){
                fontNames[i] = 恍;
            }else if(len(&(s[i*3]), "賦")){
                fontNames[i] = 賦;
            }else if(len(&(s[i*3]), "捺")){
                fontNames[i] = 捺;
            }else if(len(&(s[i*3]), "岱")){
                fontNames[i] = 岱;
            }else if(len(&(s[i*3]), "晰")){
                fontNames[i] = 晰;
            }else if(len(&(s[i*3]), "瑜")){
                fontNames[i] = 瑜;
            }else if(len(&(s[i*3]), "實")){
                fontNames[i] = 實;
            }else if(len(&(s[i*3]), "簾")){
                fontNames[i] = 簾;
            }else if(len(&(s[i*3]), "戌")){
                fontNames[i] = 戌;
            }else if(len(&(s[i*3]), "蹟")){
                fontNames[i] = 蹟;
            }else if(len(&(s[i*3]), "霙")){
                fontNames[i] = 霙;
            }else if(len(&(s[i*3]), "亥")){
                fontNames[i] = 亥;
            }else if(len(&(s[i*3]), "罫")){
                fontNames[i] = 罫;
            }else if(len(&(s[i*3]), "踵")){
                fontNames[i] = 踵;
            }else if(len(&(s[i*3]), "誅")){
                fontNames[i] = 誅;
            }else if(len(&(s[i*3]), "傀")){
                fontNames[i] = 傀;
            }else if(len(&(s[i*3]), "咆")){
                fontNames[i] = 咆;
            }else if(len(&(s[i*3]), "鯵")){
                fontNames[i] = 鯵;
            }else if(len(&(s[i*3]), "蠅")){
                fontNames[i] = 蠅;
            }else if(len(&(s[i*3]), "疱")){
                fontNames[i] = 疱;
            }else if(len(&(s[i*3]), "榮")){
                fontNames[i] = 榮;
            }else if(len(&(s[i*3]), "鋏")){
                fontNames[i] = 鋏;
            }else if(len(&(s[i*3]), "堆")){
                fontNames[i] = 堆;
            }else if(len(&(s[i*3]), "魍")){
                fontNames[i] = 魍;
            }else if(len(&(s[i*3]), "ガ")){
                fontNames[i] = ガ;
            }else if(len(&(s[i*3]), "ギ")){
                fontNames[i] = ギ;
            }else if(len(&(s[i*3]), "グ")){
                fontNames[i] = グ;
            }else if(len(&(s[i*3]), "ゲ")){
                fontNames[i] = ゲ;
            }else if(len(&(s[i*3]), "ゴ")){
                fontNames[i] = ゴ;
            }else if(len(&(s[i*3]), "ザ")){
                fontNames[i] = ザ;
            }else if(len(&(s[i*3]), "ジ")){
                fontNames[i] = ジ;
            }else if(len(&(s[i*3]), "ズ")){
                fontNames[i] = ズ;
            }else if(len(&(s[i*3]), "ゼ")){
                fontNames[i] = ゼ;
            }else if(len(&(s[i*3]), "ゾ")){
                fontNames[i] = ゾ;
            }else if(len(&(s[i*3]), "ダ")){
                fontNames[i] = ダ;
            }else if(len(&(s[i*3]), "ヂ")){
                fontNames[i] = ヂ;
            }else if(len(&(s[i*3]), "ヅ")){
                fontNames[i] = ヅ;
            }else if(len(&(s[i*3]), "デ")){
                fontNames[i] = デ;
            }else if(len(&(s[i*3]), "ド")){
                fontNames[i] = ド;
            }else if(len(&(s[i*3]), "バ")){
                fontNames[i] = バ;
            }else if(len(&(s[i*3]), "ビ")){
                fontNames[i] = ビ;
            }else if(len(&(s[i*3]), "ブ")){
                fontNames[i] = ブ;
            }else if(len(&(s[i*3]), "ベ")){
                fontNames[i] = ベ;
            }else if(len(&(s[i*3]), "ボ")){
                fontNames[i] = ボ;
            }else if(len(&(s[i*3]), "パ")){
                fontNames[i] = パ;
            }else if(len(&(s[i*3]), "ピ")){
                fontNames[i] = ピ;
            }else if(len(&(s[i*3]), "プ")){
                fontNames[i] = プ;
            }else if(len(&(s[i*3]), "ペ")){
                fontNames[i] = ペ;
            }else if(len(&(s[i*3]), "ポ")){
                fontNames[i] = ポ;
            }else{
                fontNames[i] = 疑問;
            }

        }
        fontNames[size] = sizurusFonts_end;
    }
}