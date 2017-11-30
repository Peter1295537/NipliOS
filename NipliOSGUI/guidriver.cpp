#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QGroupBox>

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

     QLabel *m_label = new QLabel();
     m_label->setText(QString::fromUtf8("Number of Process: "));

     QGroupBox *horizontalGroupBox = new QGroupBox;
     QHBoxLayout *layoutH = new QHBoxLayout;

     horizontalGroupBox->setLayout(layoutH);
     layoutH->addWidget(txtLog);

     QGroupBox *side = new QGroupBox;
     QVBoxLayout *sidebar = new QVBoxLayout;

     side->setLayout(sidebar);

     sidebar->addWidget(button1);
     sidebar->addWidget(button2);
     sidebar->addWidget(button3);
     sidebar->addWidget(button4);
     sidebar->addWidget(button5);
     layoutH->addWidget(side);
     layout->addWidget(m_label);
     layout->addWidget(textBox);
     layout->addWidget(horizontalGroupBox);




     QWidget::connect(textBox,SIGNAL(textChanged(QString)),txtLog,SLOT(setText(QString)));
     QWidget::connect(button5, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));

     window->setLayout(layout);
     window->show();

 return app.exec();
}
