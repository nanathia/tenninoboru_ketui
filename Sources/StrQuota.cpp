//
//  StrQuota.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/12.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "JASpeakWindow.h"

namespace JASpeakWindow{

    StrQuotation::StrQuotation(const std::string& str, int quota):
    m_quota(quota){
        m_string = str;
    }
    StrQuotation::StrQuotation(const std::string& str):
    m_quota(-1),
    m_string(str){
    }
    int StrQuotation::getQuota() const{
        return m_quota;
    }
    const std::string& StrQuotation::getStr() const{
        return m_string;
    };

}