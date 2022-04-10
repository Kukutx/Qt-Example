#ifndef JSONMANGER_H
#define JSONMANGER_H
#include <QJsonObject>          // 封装JSON对象 { }
#include <QJsonArray>           // 封装JSON数组 [ ]
#include <QJsonDocument>        // 读写解析JSON文档
#include <QJsonValue>           // 封装JSON值 int，float，double，bool，{ }，[ ]等
#include <QJsonParseError>      // 报告JSON处理过程中出现的错误
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QDateTime>
#pragma execution_character_set("utf-8") // qt支持显示中文

class JsonManger
{
public:
    JsonManger();
    void writeObjJson();
    void deleteObjJson();
    void updateObjJson();
    void readObjJson();

    // 使用QJsonArray添加值，并写入文件
    QJsonArray jsonArray;
    QJsonDocument jsonDoc;
    QJsonObject interestObj;    // 定义Json对象
    QJsonParseError jsonError;  // QJsonParseError类用于在JSON解析期间报告错误。
};

#endif // JSONMANGER_H
