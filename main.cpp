#include "mainwindow.h"
#include <QApplication>
#include <simplelogger.h>
#include <vector>
#include <stategraph.h>
#include <state.h>
#include <superstate.h>
#include <testclass.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Logger::write("Hello world");
    States::StateGraph<int> graph;
    States::StateGraph<testClass> graph2;
    States::State<int>* s1 = new States::SuperState<int>(1);
    States::State<int> s2(2);
    States::State<int> s3(3);
    States::State<int> s4(4);
    States::State<int> s5(5);
    States::State<int> *st;
    States::SuperState<int> *sst;
    graph.addState(s1);
    graph.addState(&s2);
    graph.addState(&s3);
    graph.addState(&s4);
    graph.addState(&s5);
    graph.addConnection(0,1);
    graph.addConnection(1,2);
    graph.addConnection(1,3);

    graph.addConnection(3,4);
    graph.setInitialState(s1);
    graph.setFinalState(&s5);
    graph.findPath(s1,&s5);
    States::StateIterator<int> iter= graph.begin();
    st = *iter;
    Logger::write(st->toString());
    sst = dynamic_cast< States::SuperState<int>* >(st);
    iter++;
    st = *iter;
    Logger::write(st->toString());
    sst = dynamic_cast< States::SuperState<int>* >(st);


    w.show();

    return a.exec();
}
