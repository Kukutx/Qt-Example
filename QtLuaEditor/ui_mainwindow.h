// ui_mainwindow.h
 
 
#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H
 
#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMainWindow>
#include <QPushButton>
#include <QSpacerItem>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <codeeditor.h>
 
QT_BEGIN_NAMESPACE
 
class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *openpushButton;
    QPushButton *savepushButton;
    QPushButton *pushButton;
    CodeEditor *plainTextEdit;
    QTextEdit *textEdit;
 
    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(551, 337);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
 
        horizontalLayout->addItem(horizontalSpacer);
 
        openpushButton = new QPushButton(centralWidget);
        openpushButton->setObjectName(QString::fromUtf8("openpushButton"));
 
        horizontalLayout->addWidget(openpushButton);
 
        savepushButton = new QPushButton(centralWidget);
        savepushButton->setObjectName(QString::fromUtf8("savepushButton"));
 
        horizontalLayout->addWidget(savepushButton);
 
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
 
        horizontalLayout->addWidget(pushButton);
 
 
        verticalLayout->addLayout(horizontalLayout);
 
        plainTextEdit = new CodeEditor(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
 
        verticalLayout->addWidget(plainTextEdit);
 
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
 
        verticalLayout->addWidget(textEdit);
 
        MainWindow->setCentralWidget(centralWidget);
 
        retranslateUi(MainWindow);
 
        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi
 
    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        openpushButton->setText(QApplication::translate("MainWindow", "Open", 0));
        savepushButton->setText(QApplication::translate("MainWindow", "Save", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Compile", 0));
    } // retranslateUi
 
};
 
namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui
 
QT_END_NAMESPACE
 
#endif // UI_MAINWINDOW_H
