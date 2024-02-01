#include "mainwindow.h"
#include "systemc.h"

#include <QApplication>
#include <QPlainTextEdit>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPlainTextEdit *plainTextEdit = new QPlainTextEdit();
    plainTextEdit->setPlainText("hello qt\t");
    plainTextEdit->show();
    return a.exec();
}

int sc_main(int argc, char *argv[]) {
    return 0;
}
