/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MasterGui.hpp
 * Author: james
 *
 * Created on September 13, 2016, 9:40 PM
 */

#ifndef MASTERGUI_HPP
#define MASTERGUI_HPP

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QTime>

#include <iostream>

using std::cout;
using std::endl;

class MasterGui : public QWidget
{
    Q_OBJECT
            
    public:
        enum Direction
        {
            UP,
            DOWN
        };
        
        Direction currDir;
        
        explicit MasterGui(QWidget* parent = 0);
        virtual ~MasterGui();
        
    protected:
        void keyPressEvent(QKeyEvent* event);
        void paintEvent(QPaintEvent* event);
        
    private:
        const QSize PADDLE_SIZE;
        QRectF* paddle;
        QRectF* ball;
        float x;
        float vel;
        
};

#endif /* MASTERGUI_HPP */