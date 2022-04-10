#include "jsonmanger.h"

JsonManger::JsonManger()
{
}

void JsonManger::writeObjJson()
{
    QFile file(QDir::currentPath() + "./test.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Append)) {
        qDebug() << "can't open error!";
        return;
    }

    /*
    QIODevice::NotOpen 未打开
    QIODevice::ReadOnly 以只读方式打开
    QIODevice::WriteOnly 以只写方式打开
    QIODevice::ReadWrite 以读写方式打开
    QIODevice::Append 以追加的方式打开
    QIODevice::Truncate 以重写的方式
    QIODevice::Text 在读取时，将行结束符转换成 \n；在写入时，将行结束符转换成本地格式，例如 Win32 平台上是 \r\n
    QIODevice::Unbuffered 忽略缓存
    */
    // 清空文件中的原有内容
    file.resize(0);



    // 插入元素，对应键值对,// 生成JSON
    QJsonObject subArrayObj;
    QJsonObject subObjObj;

    interestObj.insert("name", QString::fromLocal8Bit("marco"));
    interestObj.insert("id", "11111111");
    interestObj.insert("vip", true);
    interestObj.insert("address", QJsonValue::Null);

    subObjObj.insert("basketball", QString::fromLocal8Bit("篮球"));
    subObjObj.insert("badminton", QString::fromLocal8Bit("羽毛球"));
    subObjObj.insert("name", QString("liyifeng"));
    subObjObj.insert("age", 22);
    subObjObj.insert("Time","Time:"+QDateTime::currentDateTime().toString());
    interestObj.insert("meimei",QJsonValue(subObjObj));


    subArrayObj.insert("id", "01");
    subArrayObj.insert("name","male");
    subArrayObj.insert("gender","2323");
    jsonArray.append(QJsonValue(subArrayObj));
    jsonDoc.setArray(jsonArray);
    interestObj.insert("Student",QJsonValue(jsonArray));

    // 定义[ ]数组对象
    QJsonArray colorArray;
    // 往数组中添加元素
    colorArray.append("black");
    colorArray.append("white");
    interestObj.insert("color",colorArray);


    // 定义{}json对象
    QJsonObject language1;
    language1.insert("language", QString::fromLocal8Bit("汉语"));
    language1.insert("grade", 10);
    QJsonObject language2;
    language2.insert("language", QString::fromLocal8Bit("英语"));
    language2.insert("grade", 6);
    // 将{ } 插入 { } 中
    QJsonObject languages;
    languages.insert("serialOne", language1);
    languages.insert("serialTwo", language2);
    interestObj.insert("gege",languages);


    jsonDoc.setObject(interestObj);


    //第一种写入方式
    QTextStream stream(&file);
    stream.setCodec("UTF-8");		// 设置写入编码是UTF8
    stream << jsonDoc.toJson();      // 写入文件


    /*第二种写入方式
    file.write(jsonDoc.toJson());
    //file.write(jsonDoc.toJson(QJsonDocument::Indented));
    */


    file.close();
    qDebug() << "Write to file";
}

void JsonManger::deleteObjJson()
{
    QFile file(QDir::currentPath() + "./test.json");
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        qDebug() << "can't open error!";
        return;
    }
    file.resize(0);

    // 获取根 { }
    QJsonObject rootObj = jsonDoc.object();

    //删除属性
    rootObj.remove("name");  // 删除vip

    //删除数组[]中的元素
    QJsonValue colorValue = rootObj.value("color");
    if (colorValue.type() == QJsonValue::Array) {
        QJsonArray colorArray = colorValue.toArray();
        // 删除数组中索引为1的值
        colorArray.removeAt(1);
        // 赋值覆盖原有数组属性
        rootObj["color"] = colorArray;
    }

    //删除 { } 中的值
    QJsonValue interestValue = rootObj.value("meimei");
    if (interestValue.type() == QJsonValue::Object) {
        QJsonObject interestObjectTest = interestValue.toObject();

        // 删除键为basketball的属性元素
        interestObjectTest.remove("basketball");

        rootObj["meimei"] = interestObjectTest;
    }

//    // 删除 [ ]
//    rootObj.remove("color");

//    // 删除 { }
//    rootObj.remove("gege");


    jsonDoc.setObject(rootObj);

    QTextStream stream(&file);
    stream.setCodec("UTF-8");		// 设置写入编码是UTF8
    stream << jsonDoc.toJson();      // 写入文件
    file.close();
}

void JsonManger::updateObjJson()
{
    QFile file(QDir::currentPath() + "./test.json");
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        qDebug() << "can't open error!";
        return;
    }

    // 获取根 { }
    QJsonObject rootObj = jsonDoc.object();

    //修改根元素
    //第一种方法
    rootObj["name"] = QString::fromLocal8Bit("老李"); // 修改name属性
    rootObj["vip"] = false;
    //第二种方法
    QJsonValueRef RefPage = rootObj.find("name").value();
    RefPage = QJsonValue("8888");

    //修改数组 [ ] 中的元素
    QJsonValue colorValue = rootObj.value("color");
    if (colorValue.type() == QJsonValue::Array) {
        QJsonArray colorArray = colorValue.toArray();
        // 修改数组中的值
        colorArray.replace(0, "blue");
        colorArray.replace(1, "green");
        // 赋值覆盖原有数组属性
        rootObj["color"] = colorArray;
    }

    //修改 { } 中的值
    QJsonValue interestValue = rootObj.value("meimei");
    if (interestValue.type() == QJsonValue::Object) {
        QJsonObject interestObjectTest = interestValue.toObject();

        interestObjectTest["badminton"] =QString::fromLocal8Bit("乒乓球");
        interestObjectTest["basketball"] = QString::fromLocal8Bit("足球");
        rootObj["meimei"] = interestObjectTest;
    }



    jsonDoc.setObject(rootObj);

    QTextStream stream(&file);
    stream.setCodec("UTF-8");		// 设置写入编码是UTF8
    stream << jsonDoc.toJson();      // 写入文件
    file.close();
}

void JsonManger::readObjJson()
{
    QFile file(QDir::currentPath() + "./test.json");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "can't open error!";
        return;
    }

    // 读取文件的全部内容
    QTextStream stream(&file);
    stream.setCodec("UTF-8");		// 设置读取编码是UTF8
    QString str = stream.readAll();
    //qDebug()<<str;


    // 将json解析为UTF-8编码的json文档，并从中创建一个QJsonDocument。
    // 如果解析成功，返回QJsonDocument对象，否则返回null
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
    // 判断是否解析失败
    if (jsonError.error != QJsonParseError::NoError && !doc.isNull()) {
        qDebug() << "Json格式错误！" << jsonError.error;
        return;
    }

    if (doc.isObject())    //判断是否Object对象
    {
        //解析根 { }对象成员
        QJsonObject rootObj = doc.object();
        QJsonValue nameValue = rootObj.value("name");     // 根据键获取值
        qDebug() << "name = " << nameValue.toString();
        QJsonValue ageValue = rootObj.value("id");
        qDebug() << "id = " << ageValue.toInt();
        QJsonValue vipValue = rootObj.value("vip");       // 解析 bool类型
        qDebug() << "vip = " << vipValue.toBool();
        QJsonValue addressValue = rootObj.value("address"); // 解析 null类型
        if (addressValue.type() == QJsonValue::Null) {
            qDebug() << "address = " << "null";
        }


        //解析对象 { } 对象内部成员
        QJsonValue interestValue = rootObj.value("meimei");
        // 判断是否是object类型
        if (interestValue.type() == QJsonValue::Object) {
            // 转换为QJsonObject类型
            QJsonObject interestObj = interestValue.toObject();
            QJsonValue basketballValue = interestObj.value("basketball");
            qDebug() << "basketball = " << basketballValue.toString();
            QJsonValue badmintonValue = interestObj.value("badminton");
            qDebug() << "badminton = " << badmintonValue.toString();
        }


        //解析数组 [ ] 对象内部成员
        QJsonValue colorValue = rootObj.value("color");
        // 判断是否是Array类型
        if (colorValue.type() == QJsonValue::Array) {
            // 转换为QJsonArray类型
            QJsonArray colorArray = colorValue.toArray();
            for (int i = 0; i < colorArray.size(); i++) {
                QJsonValue color = colorArray.at(i);
                qDebug() << "color = " << color.toString();
            }
        }



        QStringList keys = rootObj.keys();
        for(int i = 0; i < keys.size(); i++)
        {
            qDebug() << "key" << i << " is:" << keys.at(i);
        }

        //因为是预先定义好的JSON数据格式，所以这里可以这样读取
        if(rootObj.contains("meimei"))
        {
            QJsonObject subObj = rootObj.value("meimei").toObject();
            qDebug() << "basketball is:" << subObj["basketball"].toString();
            qDebug() << "badminton is:" << subObj["badminton"].toString();
            qDebug() << "name is:" << subObj["name"].toString();
        }

        if(rootObj.contains("color"))
        {
            QJsonArray subArray = rootObj.value("color").toArray();
            for(int i = 0; i< subArray.size(); i++)
            {
                qDebug() << i<<" value is:" << subArray.at(i).toString();
            }
        }
    }

    file.close();
}
