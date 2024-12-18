#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QRect screen = QGuiApplication::primaryScreen()->geometry();
    int x = (screen.width() - w.width()) / 2;
    int y = (screen.height() - w.height()) / 2;

    w.move(x, y - 45);

    w.show();

    QString msg_style = R"(
        QMessageBox { background-color: #181b22; color: #d0d1d6; padding: 10px; }
        QMessageBox QLabel { color: #d0d1d6; font-size: 14px; }
        QMessageBox QPushButton { color: #d0d1d6; background-color: #313237; border: 1px solid #d0d1d6; border-radius: 5px; padding: 5px 10px; }
        QMessageBox QPushButton:hover { background-color: #e65100; color: #ffffff; border: 1px solid #e65100; }
        QMessageBox QPushButton:pressed { background-color: #d04f00; color: #ffffff; }
    )";

    a.setStyleSheet(msg_style);

    return a.exec();
}
