//
//  DungeonSceneState.h
//  Karakuri2 Mac
//
//  Created by 小林　伸 on 2014/09/01.
//  Copyright (c) 2014年 Satoshi Numata. All rights reserved.
//

#ifndef __Karakuri2_Mac__DungeonSceneState__
#define __Karakuri2_Mac__DungeonSceneState__

#include "Karakuri.h"
#include "JASpeakWindow.h"

class SKDungeonScene;

namespace JASpeakWindow{
    class Window;
}
namespace selectWindow{
    class Window;
}

namespace dungeonscenestate{
    
    class DungeonSceneState;
    // スーパー
    class DungeonSceneStateChild{
    protected:
        SKDungeonScene* m_user;
    public:
        DungeonSceneStateChild(SKDungeonScene* user);
        virtual ~DungeonSceneStateChild();
        virtual DungeonSceneStateChild* update(GMInput* input, double deltaTime) = 0;
        virtual void draw(GMSpriteBatch* s) = 0;
        SKDungeonScene* getScene();
        virtual void nextFloor();
    };
    
    // ---ダンジョンに入る---
    class DungeonSceneFloorInter: public DungeonSceneStateChild{
        double m_time;
    public:
        DungeonSceneFloorInter(SKDungeonScene* user);
        ~DungeonSceneFloorInter();
        DungeonSceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    // ---メインゲーム---
    class DungeonSceneFreeMove: public DungeonSceneStateChild{
        bool m_isGoNextFloorReady;
    public:
        DungeonSceneFreeMove(SKDungeonScene* user);
        ~DungeonSceneFreeMove();
        DungeonSceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
        void nextFloor() override;
    };
    
    // ---階層移動開始---
    class DungeonSceneFloorOuter: public DungeonSceneStateChild{
        double m_time;
    public:
        DungeonSceneFloorOuter(SKDungeonScene* user);
        ~DungeonSceneFloorOuter();
        DungeonSceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    // ---リザルト画面---
    class DungeonSceneResult: public DungeonSceneStateChild{
    public:
        DungeonSceneResult(SKDungeonScene* user);
        ~DungeonSceneResult();
        DungeonSceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    // ---イベント---
    class DungeonSceneEvent: public DungeonSceneStateChild{
    public:
        DungeonSceneEvent(SKDungeonScene* user);
        ~DungeonSceneEvent();
        DungeonSceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    // ---階層遷移の際にダンジョン名を表示する---
    class DungeonSceneFloorShowingDungeonName: public DungeonSceneStateChild{
        double m_time;
    public:
        DungeonSceneFloorShowingDungeonName(SKDungeonScene* user);
        ~DungeonSceneFloorShowingDungeonName();
        DungeonSceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    // ---階層移動するかどうか聞く
    class DungeonSceneIsGoNextFloor: public DungeonSceneStateChild{
    public:
        enum answerName{
            answer_iiyo,
            answer_mada,
            answer_imanankai,
            question_isEnable,
        };
    private:
        selectWindow::Window* m_questionWin;
        JASpeakWindow::Window* m_JaSpkWin;
    public:
        DungeonSceneIsGoNextFloor(SKDungeonScene* user);
        ~DungeonSceneIsGoNextFloor();
        DungeonSceneStateChild* update(GMInput* input, double deltaTime) override;
        void draw(GMSpriteBatch* s) override;
    };
    
    // 管理
    class DungeonSceneState{
        DungeonSceneStateChild* m_child;
    public:
        DungeonSceneState(SKDungeonScene* user);
        ~DungeonSceneState();
        void update(GMInput* input, double deltaTime);
        void draw(GMSpriteBatch* s);
        void nextFloor();
    };
    
    
}
#endif /* defined(__Karakuri2_Mac__DungeonSceneState__) */
