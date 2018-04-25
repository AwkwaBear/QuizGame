#include "quizwindow.hh"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Quiz");
    QuizWindow window;
    window.show();
    return app.exec();
}
