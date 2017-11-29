#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);
 QWidget *window = new QWidget;
     QPushButton *button1 = new QPushButton("PROC");
     QPushButton *button2 = new QPushButton("MEM");
     QPushButton *button3 = new QPushButton("LOAD");
     QPushButton *button4 = new QPushButton("EXE");
     QPushButton *button5 = new QPushButton("EXIT");

     QVBoxLayout *layout = new QVBoxLayout;

     QLineEdit *textBox = new QLineEdit;

     QTextEdit *txtLog = new QTextEdit;

     layout->addWidget(button1);
     layout->addWidget(button2);
     layout->addWidget(button3);
     layout->addWidget(button4);
     layout->addWidget(button5);
     layout->addWidget(textBox);
     layout->addWidget(txtLog);


     QWidget::connect(textBox,SIGNAL(textChanged(QString)),txtLog,SLOT(setText(QString)));
     QWidget::connect(button5, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));


     window->setLayout(layout);
     window->show();

 return app.exec();
}
