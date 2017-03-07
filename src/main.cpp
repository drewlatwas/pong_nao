/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: james
 *
 * Created on September 13, 2016, 9:40 PM
 */

#include <QApplication>

#include "MasterGui.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MasterGui masterGui;
    masterGui.show();

    return app.exec();
}
