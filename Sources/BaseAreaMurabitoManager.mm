//
//  MurabitoManager.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/26.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaSouces.h"
#include "tinyxml2.h"
#include <sstream>

namespace baseArea{
    
    MurabitoManager::MurabitoManager(tinyxml2::XMLElement* layer, BaseAreaMap* parent):
    m_parent(parent){
        std::string fileName = layer->Attribute("name");
        NSURL *fileURL = [[NSBundle mainBundle] URLForResource:@(fileName.c_str()) withExtension:@(".xml")];
        if (!fileURL) {
            NSLog(@"Error: Failed to locate .xml file!!");
            exit(1);
        }
        tinyxml2::XMLDocument doc;
        doc.LoadFile(fileURL.path.UTF8String);
        tinyxml2::XMLElement* MurabitoData = doc.FirstChildElement();
        tinyxml2::XMLElement* c = MurabitoData->FirstChildElement();
        while(c){
            if(!c->Attribute("type")) break;
            this->add(new Murabito(c, parent));
            c = c->NextSiblingElement();
        }
        c = layer->FirstChildElement();
        while(c->Name() != std::string("data")){
            c = c->NextSiblingElement();
        }
        c = c->FirstChildElement();
        int count = 0;
        while(c){
            std::string name = c->Name();
            if(name == "tile"){
                if(c->IntAttribute("gid")){
                    std::ostringstream oss;
                    oss << "obj_" << parent->getTileSetMan()->getLocalGid(c->IntAttribute("gid"));
                    auto it = m_Murabitos.begin();
                    while(it != m_Murabitos.end()){
                        if((*it)->Name()==oss.str().c_str()){
                            (*it)->setPos(GMVector2D(count%layer->IntAttribute("width"), count/layer->IntAttribute("width")));
                            break;
                        }
                        it++;
                    }
                }
            }
            c = c->NextSiblingElement();
            count++;
        }
    }
    MurabitoManager::~MurabitoManager(){
        if(m_Murabitos.empty()) return;
        auto it = m_Murabitos.begin();
        while(it != m_Murabitos.end()){
            delete *it;
            *it = 0;
            it++;
        }
        m_Murabitos.clear();
    }
    void MurabitoManager::update(GMInput* input, double deltaTime){
        auto it = m_Murabitos.begin();
        while(it != m_Murabitos.end()){
            (*it)->update(input, deltaTime);
            it++;
        }
    }
    void MurabitoManager::draw(GMSpriteBatch* s){
        auto it = m_Murabitos.begin();
        while(it != m_Murabitos.end()){
            (*it)->draw(s);
            it++;
        }
    }
    BaseAreaMap* MurabitoManager::getBaseAreaMap(){
        return m_parent;
    }
    std::list<Murabito*>& MurabitoManager::getMurabitos(){
        return m_Murabitos;
    }
    void MurabitoManager::add(Murabito* murabito){
        m_Murabitos.push_back(murabito);
    }
    Murabito* MurabitoManager::isCollision(const GMRect2D &rect) const{
        if(m_Murabitos.empty()) return 0;
        std::list<Murabito*>::const_iterator it = m_Murabitos.begin();
        while(it != m_Murabitos.end()){
            bool isCol = (*it)->isCollision(rect);
            if(isCol) return *it;
            it++;
        }
        return 0;
    }
}