//
//  SpeakStrManager.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/28.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SpeakStrManager__
#define __Karakuri2_Mac__SpeakStrManager__

#include "Karakuri.h"
#include <list>
#include <string>

namespace tinyxml2{
    class XMLElement;
}

namespace characterspeak{
    // その言葉が出て、次の言葉に行くときの行動
    enum speakKeys{
        key_TurnRight,
        key_TurnLeft,
        key_TurnTop,
        key_TurnBottom,
        key_TurnPlayer,
        
        key_None,
    };
    
    class SpeakStrManager;
    
    class SpeakAnswer{
        const std::string answerStr;
        SpeakStrManager* m_speaks;
    public:
        
    };
    
    class SpeakQuestion{
        
    public:
    };
    
    class SpeakStr{
        const std::string m_data;
        const speakKeys m_key;
        SpeakStr* m_next;
        SpeakStr* m_prev;
    public:
        SpeakStr(tinyxml2::XMLElement* data);
        ~SpeakStr();
        const std::string& getSpeak() const;
        speakKeys getKey() const;
        void setNext(SpeakStr* next);
        void setPrev(SpeakStr* prev);
        SpeakStr* getNext();
        SpeakStr* getPrev();
    };
    
    class SpeakStrManager{
        // 喋る言葉
        std::list<SpeakStr*> m_speaks;
        SpeakStr* m_currentStr;
        void add(SpeakStr* speak);
    public:
        SpeakStrManager(tinyxml2::XMLElement* data);
        ~SpeakStrManager();
        void goNext();
        void reset();
        bool isEnd() const;
        speakKeys getCurrentKey() const;
        const std::string& getSpeak() const;
    };
    
}

#endif /* defined(__Karakuri2_Mac__SpeakStrManager__) */
