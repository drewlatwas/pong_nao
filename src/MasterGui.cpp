/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * http://gamedev.stackexchange.com/questions/4253/in-pong-how-do-you-calculate-the-balls-direction-when-it-bounces-off-the-paddl
 */

#include "MasterGui.hpp"


MasterGui::MasterGui(QWidget* parent) : QWidget(parent), PADDLE_SIZE(100, 10)
{
    this->resize(750, 750);
    
    currDir = MasterGui::DOWN;
    paddle = new QRectF(0, this->size().width()-10, PADDLE_SIZE.width(), PADDLE_SIZE.height());
    ball = new QRectF(250, 250, 20, 20);
    x = 0.0;
    vel = 2.0;
    
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);
}


void MasterGui::keyPressEvent(QKeyEvent* event)
{

    int leftArrSize = 14;
    int rightArrSize = 12;
    int leftArr[] = {Qt::Key_A, Qt::Key_S, Qt::Key_Q, Qt::Key_W, Qt::Key_Z, Qt::Key_X, Qt::Key_E, Qt::Key_R, Qt::Key_C, Qt::Key_V, Qt::Key_D, Qt::Key_F, Qt::Key_T, Qt::Key_G};
    int rightArr[] = {Qt::Key_L, Qt::Key_K, Qt::Key_P, Qt::Key_O, Qt::Key_M, Qt::Key_N, Qt::Key_I, Qt::Key_U, Qt::Key_J, Qt::Key_H, Qt::Key_B, Qt::Key_Y};

    bool isLeftKey = false;

    for(int i = 0; i < leftArrSize; i++)
    {
        if(event->key() == leftArr[i]) //if we loop though all left keys and don't find a match, it must be a right key
        {    isLeftKey = true;
            break;
        }
    }

    if(isLeftKey == true)
    {
        if(paddle->x() > 0)
        {
            paddle->setX(paddle->x()-10);
            paddle->setWidth(paddle->width()-10);
        }
        cout << "<--" << paddle->x() << endl;
    }
    else
    {
        if(paddle->x() < this->size().width()-paddle->width() )
        {
            paddle->setX(paddle->x()+10);
            paddle->setWidth(paddle->width()+10);
        }
        cout << "-->" << paddle->x() << endl;
    }

    /*
    switch(event->key() )
    {
        case Qt::Key_Left:
            if(paddle->x() > 0)
            {
                paddle->setX(paddle->x()-10);
                paddle->setWidth(paddle->width()-10);
            }
            cout << "<--" << paddle->x() << endl;
            break;
        case Qt::Key_Right:
            if(paddle->x() < this->size().width()-paddle->width() )
            {
                paddle->setX(paddle->x()+10);
                paddle->setWidth(paddle->width()+10);
            }
            cout << "-->" << paddle->x() << endl;
            break;
        default:
            cout << "unknown key pressed" << endl;
    }
    
    //repaint();
    //OR update()
    */
}


void MasterGui::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    float rand = 0;
    
    if(ball->x() < 0)
    {
        rand = (qrand() % 10)/10.0;
        cout << "adding rand: " << rand << endl;
        x += rand;
        x = -x;
    }
    
    if(ball->x() > this->size().width() )
    {
        rand = (qrand() % 10)/10.0;
        cout << "adding rand: " << rand << endl;
        x += rand;
        x = -x;
    }
    
    if(currDir == MasterGui::DOWN)
    {
        ball->setY(ball->y()+vel);
        ball->setX(ball->x()+x);
        ball->setWidth(ball->width()+x);
        ball->setHeight(ball->height()+vel);
        if(ball->y() > this->size().width()-10)
        {
            currDir = MasterGui::UP;
        }
        
        if(ball->y() >= paddle->y()-20 && (paddle->x() < ball->x() && paddle->x()+paddle->width() > ball->x()) )
        {
            currDir = MasterGui::UP;
            x = ((paddle->x()+50) - ball->x())/10.0;
            rand = (qrand() % 10)/10.0;
            cout << "adding rand: " << rand << endl;
            x += rand;
            cout << "x=" << x << endl;
        }
    }
    else if(currDir == MasterGui::UP)
    {
        rand = (qrand() % 10)/10.0;
        cout << "adding rand: " << rand << endl;
        //x += rand;
        ball->setY(ball->y()-vel);
        ball->setX(ball->x()-x);
        ball->setWidth(ball->width()-x);
        ball->setHeight(ball->height()-vel);
        if(ball->y() < 0)
        {
            currDir = MasterGui::DOWN;
        }
    }
    
    painter.fillRect(*paddle, QColor(0,191,255));
    painter.fillRect(*ball, Qt::red);
}


MasterGui::~MasterGui()
{
    ;
}
