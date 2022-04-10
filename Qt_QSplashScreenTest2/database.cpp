#include "database.h"
DataBase::DataBase(QObject *parent) : QObject(parent){
}
void DataBase::readData(){
    int max = 10000;
    emit startReadData(max, "is reading data");
    for (int i = 0; i < max; ++i)    {
        emit this->readingData(i);
        qDebug("reading data");
    }
}
