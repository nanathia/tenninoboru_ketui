#include "SKFont.h"
#include "GameMain.h"
#include <string>

namespace sizurus_fonts{
    namespace{
        enum size{
            texSizeW = 2048,
            texSizeH = 2048,
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
        ten_flags flags[3];
        convertChar2Name(drawFont, flags, character);
        GMRect2D srcRect((drawFont[0]%charNum)*charSize, (drawFont[0]/charNum)*charSize, charSize, charSize);
        s->draw(gGameInst->getFontTex(), destRect, srcRect, color, rotation*M_PI, origin*charSize, GMSpriteFlipHorizontally);
        if(flags[0] == dakuten){
            srcRect.x = (濁点%charNum)*charSize;
            srcRect.y = (濁点/charNum)*charSize;
            s->draw(gGameInst->getFontTex(), destRect, srcRect, color, rotation, origin*charSize, GMSpriteFlipHorizontally);
        }
    }
    
    void SKFont::drawString_toWindow(const SizurusFontsName drawFont, const GMRect2D& destRect, GMSpriteBatch* s, GMColor c){
        int tx = (drawFont%charNum)*charSize;
        int ty = (drawFont/charNum)*charSize;
        s->draw(gGameInst->getFontTex(), destRect, GMRect2D(tx, ty, charSize, charSize), c);
    }
    
    void SKFont::convertChar2Name(SizurusFontsName* fontNames, ten_flags* daku, const std::string& str){
        int size = (int)str.size()/3;
        const char* s = str.c_str();
        
        for(int i = 0; i < size; i++){
            daku[i] = none;
            int ind = i*3;
            
            if(len(&(s[ind]), "が")){
                fontNames[i] = か;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ぎ")){
                fontNames[i] = き;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ぐ")){
                fontNames[i] = く;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "げ")){
                fontNames[i] = け;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ご")){
                fontNames[i] = こ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ざ")){
                fontNames[i] = さ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "じ")){
                fontNames[i] = し;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ず")){
                fontNames[i] = す;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ぜ")){
                fontNames[i] = せ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ぞ")){
                fontNames[i] = そ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "だ")){
                fontNames[i] = た;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ぢ")){
                fontNames[i] = ち;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "づ")){
                fontNames[i] = つ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "で")){
                fontNames[i] = て;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ど")){
                fontNames[i] = と;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ば")){
                fontNames[i] = は;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "び")){
                fontNames[i] = ひ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ぶ")){
                fontNames[i] = ふ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "べ")){
                fontNames[i] = へ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ぼ")){
                fontNames[i] = ほ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ガ")){
                fontNames[i] = カ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ギ")){
                fontNames[i] = キ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "グ")){
                fontNames[i] = ク;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ゲ")){
                fontNames[i] = ケ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ゴ")){
                fontNames[i] = コ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ザ")){
                fontNames[i] = サ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ジ")){
                fontNames[i] = シ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ズ")){
                fontNames[i] = ス;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ゼ")){
                fontNames[i] = セ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ゾ")){
                fontNames[i] = ソ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ダ")){
                fontNames[i] = タ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ヂ")){
                fontNames[i] = チ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ヅ")){
                fontNames[i] = ツ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "デ")){
                fontNames[i] = テ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ド")){
                fontNames[i] = ト;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "バ")){
                fontNames[i] = ハ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ビ")){
                fontNames[i] = ヒ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ブ")){
                fontNames[i] = フ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ベ")){
                fontNames[i] = ヘ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ボ")){
                fontNames[i] = ホ;
                daku[i] = dakuten;
            }
            else if(len(&(s[ind]), "ぱ")){
                fontNames[i] = は;
                daku[i] = handakuten;
            }
            else if(len(&(s[ind]), "ぴ")){
                fontNames[i] = ひ;
                daku[i] = handakuten;
            }
            else if(len(&(s[ind]), "ぷ")){
                fontNames[i] = ふ;
                daku[i] = handakuten;
            }
            else if(len(&(s[ind]), "ぺ")){
                fontNames[i] = へ;
                daku[i] = handakuten;
            }
            else if(len(&(s[ind]), "ぽ")){
                fontNames[i] = ほ;
                daku[i] = handakuten;
            }
            else if(len(&(s[ind]), "パ")){
                fontNames[i] = ハ;
                daku[i] = handakuten;
            }
            else if(len(&(s[ind]), "ピ")){
                fontNames[i] = ヒ;
                daku[i] = handakuten;
            }
            else if(len(&(s[ind]), "プ")){
                fontNames[i] = フ;
                daku[i] = handakuten;
            }
            else if(len(&(s[ind]), "ペ")){
                fontNames[i] = ヘ;
                daku[i] = handakuten;
            }
            else if(len(&(s[ind]), "ポ")){
                fontNames[i] = ホ;
                daku[i] = handakuten;
            }
            
            
            
            else if(len(&(s[ind]), "刊")){
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
            }else{
                fontNames[i] = 疑問;
            }

        }
        fontNames[size] = sizurusFonts_end;
    }
}