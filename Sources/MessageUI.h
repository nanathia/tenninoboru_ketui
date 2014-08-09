//
//  MessageUI.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/06/15.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__MessageUI__
#define __Karakuri2_Mac__MessageUI__

#include "UITemplate.h"
#include <string>
#include <list>

// メッセージ速度によって状態を変えるステイト
class UI_MessageSpeed;

// メッセージ速度設定についての列挙。通常、１を選択する形になると思う。
enum Message_speedName{
    // 容赦無い速度でブワーッとメッセージが流れる。
    speed_0,
    // ０よりは低い速度で、そこそこ見れる程度の速度でメッセージが流れる。
    speed_1,
    // ２までは自動メッセージ。そこそこゆっくりメッセージが流れる。
    speed_2,
    // ２と同じ速度で、メッセージが流れる毎に決定を入力しないと次のメッセージが流れない。
    speed_3,
    // 考えうる限りの鈍足メッセージで、しかも決定を押さないと次に飛ばない。
    speed_4,
};

class MessageUI: public UITemplate{
    // メッセージスピード
    Message_speedName m_messageSpeed;
    // メッセージ格納
    std::list<std::string> m_messages;
    
    // 今のメッセージ
    std::string m_message;
    // メッセージカウント
    double m_messageCount;
    
public:
    MessageUI();
    ~MessageUI();
    
    void update(GMInput* input, double deltaTime) override;
    void draw(GMSpriteBatch* s) const override;
    
    void textInput(const std::string& str);
};

#endif /* defined(__Karakuri2_Mac__MessageUI__) */
