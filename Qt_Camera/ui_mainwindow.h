/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *ImageCapture;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *ImageView;
    QPushButton *buttonCapture;
    QPushButton *buttonSave;
    QPushButton *buttonQuit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(624, 429);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ImageCapture = new QLabel(centralwidget);
        ImageCapture->setObjectName(QString::fromUtf8("ImageCapture"));
        ImageCapture->setGeometry(QRect(30, 100, 161, 161));
        ImageCapture->setLayoutDirection(Qt::LeftToRight);
        ImageCapture->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(250, 30, 351, 311));
        ImageView = new QHBoxLayout(horizontalLayoutWidget);
        ImageView->setObjectName(QString::fromUtf8("ImageView"));
        ImageView->setContentsMargins(0, 0, 0, 0);
        buttonCapture = new QPushButton(centralwidget);
        buttonCapture->setObjectName(QString::fromUtf8("buttonCapture"));
        buttonCapture->setGeometry(QRect(60, 350, 75, 23));
        buttonSave = new QPushButton(centralwidget);
        buttonSave->setObjectName(QString::fromUtf8("buttonSave"));
        buttonSave->setGeometry(QRect(290, 350, 75, 23));
        buttonQuit = new QPushButton(centralwidget);
        buttonQuit->setObjectName(QString::fromUtf8("buttonQuit"));
        buttonQuit->setGeometry(QRect(520, 350, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 624, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ImageCapture->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\344\277\235\345\255\230", nullptr));
        buttonCapture->setText(QCoreApplication::translate("MainWindow", "\346\213\215\347\205\247", nullptr));
        buttonSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        buttonQuit->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
