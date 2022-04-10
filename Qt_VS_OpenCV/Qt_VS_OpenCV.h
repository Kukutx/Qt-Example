#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_VS_OpenCV.h"

class Qt_VS_OpenCV : public QMainWindow
{
    Q_OBJECT

public:
    Qt_VS_OpenCV(QWidget *parent = Q_NULLPTR);

private:
    Ui::Qt_VS_OpenCVClass ui;
};
