/********************************************************************************
** Form generated from reading UI file 'wallpaper.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WALLPAPER_H
#define UI_WALLPAPER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wallpaper
{
public:
    QWidget *centralWidget;
    QPushButton *hoverButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *filePath;
    QPushButton *path_button;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *fillButton;
    QRadioButton *firstButton;
    QRadioButton *secondButton;
    QLabel *label_4;

    void setupUi(QMainWindow *Wallpaper)
    {
        if (Wallpaper->objectName().isEmpty())
            Wallpaper->setObjectName(QString::fromUtf8("Wallpaper"));
        Wallpaper->resize(350, 360);
        Wallpaper->setMinimumSize(QSize(350, 360));
        Wallpaper->setMaximumSize(QSize(350, 360));
        Wallpaper->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Wallpaper->setWindowIcon(icon);
        Wallpaper->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);padding:0px;margin:0px;border:none;"));
        Wallpaper->setInputMethodHints(Qt::ImhNone);
        centralWidget = new QWidget(Wallpaper);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        hoverButton = new QPushButton(centralWidget);
        hoverButton->setObjectName(QString::fromUtf8("hoverButton"));
        hoverButton->setGeometry(QRect(50, 290, 250, 40));
        hoverButton->setMinimumSize(QSize(250, 40));
        hoverButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 170, 0);color:white;border-radius:5px;border:none;font-size:14px;"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 110, 331, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        filePath = new QLineEdit(layoutWidget);
        filePath->setObjectName(QString::fromUtf8("filePath"));
        filePath->setMinimumSize(QSize(100, 30));
        filePath->setMaximumSize(QSize(250, 30));
        filePath->setStyleSheet(QString::fromUtf8("border:1px solid #ccc;"));

        horizontalLayout->addWidget(filePath);

        path_button = new QPushButton(layoutWidget);
        path_button->setObjectName(QString::fromUtf8("path_button"));
        path_button->setMinimumSize(QSize(0, 30));
        path_button->setMaximumSize(QSize(80, 30));
        path_button->setStyleSheet(QString::fromUtf8("background-color:rgb(83, 83, 83);border-radius:3px;color:white;font-size:12px;font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(path_button);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 350, 60));
        label->setMaximumSize(QSize(350, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("font-size:22px;font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 90, 20));
        QFont font1;
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("font-size:14px;"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 170, 91, 21));
        label_3->setStyleSheet(QString::fromUtf8("font-size:14px;"));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 200, 321, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        fillButton = new QRadioButton(layoutWidget1);
        fillButton->setObjectName(QString::fromUtf8("fillButton"));
        fillButton->setMaximumSize(QSize(60, 30));
        QFont font2;
        font2.setPointSize(10);
        fillButton->setFont(font2);
        fillButton->setToolTipDuration(1);

        horizontalLayout_3->addWidget(fillButton);

        firstButton = new QRadioButton(layoutWidget1);
        firstButton->setObjectName(QString::fromUtf8("firstButton"));
        firstButton->setEnabled(true);
        firstButton->setMaximumSize(QSize(60, 30));
        firstButton->setFont(font2);
        firstButton->setChecked(true);

        horizontalLayout_3->addWidget(firstButton);

        secondButton = new QRadioButton(layoutWidget1);
        secondButton->setObjectName(QString::fromUtf8("secondButton"));
        secondButton->setMaximumSize(QSize(60, 30));
        secondButton->setFont(font2);

        horizontalLayout_3->addWidget(secondButton);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 250, 161, 21));
        label_4->setStyleSheet(QString::fromUtf8("font-size:14px;"));
        Wallpaper->setCentralWidget(centralWidget);

        retranslateUi(Wallpaper);

        QMetaObject::connectSlotsByName(Wallpaper);
    } // setupUi

    void retranslateUi(QMainWindow *Wallpaper)
    {
        Wallpaper->setWindowTitle(QCoreApplication::translate("Wallpaper", "Wallpaper", nullptr));
        hoverButton->setText(QCoreApplication::translate("Wallpaper", "\345\205\263\351\227\255", nullptr));
        path_button->setText(QCoreApplication::translate("Wallpaper", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        label->setText(QCoreApplication::translate("Wallpaper", "Html5 Wallpaper Engine", nullptr));
        label_2->setText(QCoreApplication::translate("Wallpaper", "\346\226\207\344\273\266\350\267\257\345\276\204/URL:", nullptr));
        label_3->setText(QCoreApplication::translate("Wallpaper", "\345\270\203\345\261\200\346\226\271\345\274\217:", nullptr));
        fillButton->setText(QCoreApplication::translate("Wallpaper", "\345\241\253\345\205\205", nullptr));
        firstButton->setText(QCoreApplication::translate("Wallpaper", "\351\246\226\345\261\217", nullptr));
        secondButton->setText(QCoreApplication::translate("Wallpaper", "\346\254\241\345\261\217", nullptr));
        label_4->setText(QCoreApplication::translate("Wallpaper", "\345\274\200\345\220\257/\345\205\263\351\227\255 hover\344\272\244\344\272\222:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wallpaper: public Ui_Wallpaper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WALLPAPER_H
