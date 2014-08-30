//
//  BaseAreaMap.cpp
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/20.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#include "BaseAreaSouces.h"
#include "tinyxml2.h"

namespace baseArea{
    
    BaseAreaMap::BaseAreaMap(SKBaseAreaScene* parent, const std::string& fileName, const std::string& extension):
    m_ObjectLayerMan(0),
    m_TileLayerMan(0),
    m_ImageLayerMan(0),
    m_parent(parent),
    m_SceneJumpLayerMan(0),
    m_SiraberuLayerMan(0),
    m_MurabitoMan(0),
    m_TileSetMan(0){
        
        NSURL *fileURL = [[NSBundle mainBundle] URLForResource:@(fileName.c_str()) withExtension:@(extension.c_str())];
        if (!fileURL) {
            NSLog(@"Error: Failed to locate .tmx file!!");
            exit(1);
        }
        tinyxml2::XMLDocument doc;
        doc.LoadFile(fileURL.path.UTF8String);
        tinyxml2::XMLElement* firstElem = doc.FirstChildElement();
        std::cout << firstElem->Name() << std::endl;
        tinyxml2::XMLElement* c = firstElem->FirstChildElement();
        
        m_ImageLayerMan = new ImageLayerManager(this);
        m_ObjectLayerMan = new ObjectLayerManager(this);
        m_TileLayerMan = new TileLayerManager(this);
        m_TileSetMan = new TileSetManager(this);
        m_SiraberuLayerMan = new SiraberuLayerManager(this);
        m_SceneJumpLayerMan = new SceneJumpLayerManager(this);
        
        while(c){
            std::string name = c->Name();
            if(name == "tileset"){
                m_TileSetMan->add(new TileSet(c, m_TileSetMan));
            }else if(name == "layer"){
                TileLayer* layer = new TileLayer(c, this);
                if(std::string(c->Attribute("name")).rfind("siraberu")!=std::string::npos){
                    m_SiraberuLayerMan->add(layer);
                }else if(std::string(c->Attribute("name")).rfind("murabito")!=std::string::npos){
                    delete layer; layer = 0;
                    m_MurabitoMan = new MurabitoManager(c, this);
                }else if(std::string(c->Attribute("name")).rfind("jumpscene")!=std::string::npos){
                    m_SceneJumpLayerMan->add(layer);
                }else{
                    m_TileLayerMan->add(layer);
                }
            }else if(name == "objectgroup"){
                m_ObjectLayerMan->add(new ObjectLayer(m_ObjectLayerMan, c));
            }else if(name == "imagelayer"){
                m_ImageLayerMan->add(new ImageLayer(c));
            }else{
                GMException("エレメントロード抜け。");
            }
            c = c->NextSiblingElement();
        }
    }
    BaseAreaMap::~BaseAreaMap(){
        delete m_ImageLayerMan;
        m_ImageLayerMan = 0;
        delete m_TileLayerMan;
        m_TileLayerMan = 0;
        delete m_ObjectLayerMan;
        m_ObjectLayerMan = 0;
        delete m_TileSetMan;
        m_TileSetMan = 0;
    }
    void BaseAreaMap::update(GMInput *input, double deltaTime){
        m_MurabitoMan->update(input, deltaTime);
    }
    void BaseAreaMap::draw(GMSpriteBatch *s){
        m_ImageLayerMan->draw(s);
        m_MurabitoMan->draw(s);
    }
    ImageLayerManager* BaseAreaMap::getImageLayerMan(){
        return m_ImageLayerMan;
    }
    ObjectLayerManager* BaseAreaMap::getObjectLayerMan(){
        return m_ObjectLayerMan;
    }
    TileLayerManager* BaseAreaMap::getTileLayerMan(){
        return m_TileLayerMan;
    }
    TileSetManager* BaseAreaMap::getTileSetMan(){
        return m_TileSetMan;
    }
    SKBaseAreaScene* BaseAreaMap::getBaseAreaScene(){
        return m_parent;
    }
    MurabitoManager* BaseAreaMap::getMurabitoMan(){
        return m_MurabitoMan;
    }
    SiraberuLayerManager* BaseAreaMap::getSiraberuLayerMan(){
        return m_SiraberuLayerMan;
    }
    SceneJumpLayerManager* BaseAreaMap::getSceneJumpLayerMan(){
        return m_SceneJumpLayerMan;
    }
    
}