#include "mainwindow.h"
#include <QApplication>
#include <simplelogger.h>
#include <vector>
#include <stategraph.h>
#include <state.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Logger::write("Hello world");
    States::StateGraph<int> graph;
    States::State<int> s1(1);
    States::State<int> s2(2);
    States::State<int> s3(3);
    States::State<int> s4(4);
    States::State<int> s5(5);
    graph.addState(s1);
    graph.addState(s2);
    graph.addState(s3);
    graph.addState(s4);
    graph.addState(s5);
    graph.addConnection(1,2);
    graph.addConnection(2,3);
    graph.addConnection(2,4);
    graph.addConnection(3,5);
    graph.addConnection(4,5);
    std::vector<char> test;
    test.push_back('0');
    test.push_back('1');
    test.push_back('2');
    test.push_back('3');
    test.push_back('4');
    QString testOut;
    for(int i=0; i< test.size(); i++)
        testOut.append(":").append(test[i]).append(" ").append("\n");
    Logger::write(testOut);
    test.erase(test.begin() + 3);
    testOut.clear();
    for(int i=0; i< test.size(); i++)
        testOut.append(":").append(test[i]).append(" ").append("\n");
    Logger::write(testOut);

    w.show();

    return a.exec();
}
