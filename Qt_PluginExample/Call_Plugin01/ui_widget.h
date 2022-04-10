/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QCheckBox *checkBox;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QVBoxLayout *childWidgetLayout;
    QPushButton *integrateWidgetBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(547, 448);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 80));
        pushButton->setMaximumSize(QSize(16777215, 80));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 80));
        pushButton_3->setMaximumSize(QSize(16777215, 80));

        horizontalLayout->addWidget(pushButton_3);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 80));
        pushButton_2->setMaximumSize(QSize(16777215, 80));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 80));
        pushButton_4->setMaximumSize(QSize(16777215, 80));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 80));
        pushButton_5->setMaximumSize(QSize(16777215, 80));

        horizontalLayout_2->addWidget(pushButton_5);


        verticalLayout->addWidget(widget_2);

        childWidgetLayout = new QVBoxLayout();
        childWidgetLayout->setObjectName(QString::fromUtf8("childWidgetLayout"));

        verticalLayout->addLayout(childWidgetLayout);

        integrateWidgetBtn = new QPushButton(Widget);
        integrateWidgetBtn->setObjectName(QString::fromUtf8("integrateWidgetBtn"));

        verticalLayout->addWidget(integrateWidgetBtn);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\212\240\350\275\275\346\211\200\346\234\211\346\217\222\344\273\266", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\345\215\270\350\275\275\346\211\200\346\234\211\346\217\222\344\273\266\344\275\240", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "\346\230\257\345\220\246\345\274\200\345\220\257\350\207\252\345\212\250\345\212\240\350\275\275\346\217\222\344\273\266", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\346\217\222\344\273\26601\345\217\221\346\266\210\346\201\257", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\346\217\222\344\273\26602\345\217\221\346\266\210\346\201\257", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\346\217\222\344\273\2663\347\252\227\345\217\243", nullptr));
        integrateWidgetBtn->setText(QCoreApplication::translate("Widget", "Integrate!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
