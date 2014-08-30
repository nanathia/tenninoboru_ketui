//
//  SpeakStrManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/28.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "SpeakStrManager.h"
#include "tinyxml2.h"
#include <string>

namespace characterspeak{
    
    SpeakStrManager::SpeakStrManager(tinyxml2::XMLElement* data){
        tinyxml2::XMLElement* c = data->FirstChildElement();
        bool isfirst = true;
        while(c){
            SpeakStr* str = 0;
            if(c->Name()==std::string("speak")) str = (new SpeakStr(c));
            if(!isfirst && str){
                m_speaks.back()->setNext(str);
                str->setPrev(m_speaks.back());
            }
            isfirst = false;
            if(str) add(str);
            c = c->NextSiblingElement();
        }
        m_currentStr = m_speaks.front();
    }
    SpeakStrManager::~SpeakStrManager(){
        auto it = m_speaks.begin();
        while(it != m_speaks.end()){
            delete *it;
            *it = 0;
            it++;
        }
        m_speaks.clear();
    }
    void SpeakStrManager::add(characterspeak::SpeakStr *speak){
        m_speaks.push_back(speak);
    }
    void SpeakStrManager::goNext(){
        m_currentStr = m_currentStr->getNext();
    }
    bool SpeakStrManager::isEnd() const{
        return m_currentStr ? false: true;
    }
    speakKeys SpeakStrManager::getCurrentKey() const{
        return key_None;
    }
    const std::string& SpeakStrManager::getSpeak() const{
        return m_currentStr->getSpeak();
    }
    void SpeakStrManager::reset(){
        m_currentStr = m_speaks.front();
    }
    
#pragma mark ---SpeakStr---
    namespace{
        speakKeys convertData2Key(const char* data){
            if(!data) return key_None;
            std::string str = data;
            speakKeys ret = key_None;
            if(str == "turnLeft"){
                ret = key_TurnLeft;
            }else if(str == "turnRight"){
                ret = key_TurnRight;
            }else if(str == "turnTop"){
                ret = key_TurnTop;
            }else if(str == "turnBottom"){
                ret = key_TurnBottom;
            }else if(str == "turnPlayer"){
                ret = key_TurnPlayer;
            }
            return ret;
        }
    }
    SpeakStr::SpeakStr(tinyxml2::XMLElement* data):
    m_key(convertData2Key(data->Attribute("key"))),
    m_next(0),
    m_prev(0),
    m_data(data->Attribute("value")){
        
    }
    SpeakStr::~SpeakStr(){
        
    }
    const std::string& SpeakStr::getSpeak() const{
        return m_data;
    }
    speakKeys SpeakStr::getKey() const{
        return m_key;
    }
    void SpeakStr::setNext(SpeakStr* next){
        m_next = next;
    }
    void SpeakStr::setPrev(SpeakStr* prev){
        m_prev = prev;
    }
    SpeakStr* SpeakStr::getNext(){
        return m_next;
    }
    SpeakStr* SpeakStr::getPrev(){
        return m_prev;
    }
    
}