#ifndef TESTCLASS_H
#define TESTCLASS_H
#include "QString"
#include "QDomDocument"
#include "QDomNode"
#include "QDomElement"
#include "QDomText"

class testClass
{
    int testData;
    QString testString;
public:

    QString serialize(){
        QDomNode el = serializeToDom();
        QDomDocument doc = el.toDocument();
        QDomElement test = el.toElement();
        return doc.toString() ;

    }

    QDomNode serializeToDom(){
        QString temp;
        QDomDocument doc("");
        QDomElement head = doc.createElement("testClass");
        QDomElement node1 = doc.createElement("testData");
        node1.setNodeValue("testData");
        QDomNode node2 = doc.createElement("testString");
        node2.setNodeValue("testString");
        QDomText dstr= doc.createTextNode(temp.setNum(testData));
        QDomText tstr= doc.createTextNode(testString);
        node1.appendChild(dstr);
        node2.appendChild(tstr);
        head.appendChild(node1);
        head.appendChild(node2);
        doc.appendChild(head);
        return doc;
    }

    void deserialize(QString data){
        QDomDocument doc;
        doc.setContent(data);
        deserializeFromDom(doc);
    }

    void deserializeFromDom(QDomNode node){
        QDomNode head = node;
        QDomNode temp;
        if(head.nodeName() == "testClass"){
            temp = head.firstChild();
            if( temp.nodeName() == "testData"){
                QString text = temp.firstChild().toText().data();
                testData = text.toInt();
            }
            temp = temp.nextSibling();
            if( temp.nodeName() == "testString"){
               testString = temp.firstChild().toText().data();
            }
        }
    }

    testClass();
    testClass(QString str, int data = 0){
        testString = str;
        testData = data;
    }

    ~testClass();
};

#endif // TESTCLASS_H
