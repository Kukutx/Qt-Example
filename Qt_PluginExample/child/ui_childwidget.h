/********************************************************************************
** Form generated from reading UI file 'childwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILDWIDGET_H
#define UI_CHILDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChildWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ChildWidget)
    {
        if (ChildWidget->objectName().isEmpty())
            ChildWidget->setObjectName(QString::fromUtf8("ChildWidget"));
        ChildWidget->resize(397, 261);
        verticalLayout_2 = new QVBoxLayout(ChildWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(ChildWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_4 = new QPushButton(ChildWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(ChildWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_2 = new QPushButton(ChildWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(ChildWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ChildWidget);

        QMetaObject::connectSlotsByName(ChildWidget);
    } // setupUi

    void retranslateUi(QWidget *ChildWidget)
    {
        ChildWidget->setWindowTitle(QCoreApplication::translate("ChildWidget", "ChildWidget", nullptr));
        pushButton->setText(QCoreApplication::translate("ChildWidget", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ChildWidget", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("ChildWidget", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ChildWidget", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ChildWidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChildWidget: public Ui_ChildWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILDWIDGET_H
