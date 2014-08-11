//
//  SKSelectWindow.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/08/08.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__SKSelectWindow__
#define __Karakuri2_Mac__SKSelectWindow__

#include "Karakuri.h"
#include <string>
#include <vector>

namespace selectWindow{
    class Window;
    class Element;
    
    // カーソルのデフォルトカラーは白。
    class Carsor{
        GMColor m_Color;
        Window* m_Window;
        Element* m_UnderElement;
    public:
        Carsor(Window* window);
        ~Carsor();
        Element* update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        void setColor(const GMColor& color);
        GMColor getColor() const;
    };
    
    // エレメントのデフォルトカラーは黒。
    class Element{
        GMRect2D m_rect;
        GMColor m_labelColor;
        std::string m_labelStr;
        Window* m_myWindow;
        Element* m_preElement;
        Element* m_nextElement;
        Carsor* m_OnCarsor;
    public:
        Element(Window* window);
        ~Element();
        void draw(GMSpriteBatch* s);
    public:
        GMRect2D getRect() const;
        void setRect(const GMRect2D& rect);
        GMColor getColor() const;
        void setColor(const GMColor& color);
        std::string getLabel() const;
        void setLabel(const std::string& label);
        Carsor* getCarsor() const;
        void setCarsor(Carsor* carsor);
        Element* getNext();
        Element* getPrev();
        void setNext(Element* next);
        void setPrev(Element* prev);
    };
    
    class Window{
        std::vector<Element*> m_elements;
        Carsor* m_carsor;
        GMRect2D m_rect;
        GMColor m_Color;
        void setRectAuto();
        double m_time;
    public:
        Window();
        ~Window();
        Element* update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
    public:
        std::vector<Element*>& getElements();
        GMRect2D getRect() const;
        GMColor getColor() const;
        void setColor(const GMColor& color);
        void addElement(Element* elem);
        void setCarsor(Carsor* carsor);
    };

}
    
#endif /* defined(__Karakuri2_Mac__SKSelectWindow__) */
