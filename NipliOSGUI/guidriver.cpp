#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QGroupBox>
#include <QObject>

int main(int argc, char **argv) {
    QApplication app (argc, argv);
    QWidget *window = new QWidget;
    QProcess nipliOS;

    const char *os = ".././NipliOS";

    //Buttons Farm
    QPushButton *start = new QPushButton("START");
    start->setEnabled(true);

    QPushButton *button1 = new QPushButton("PROC");
    button1->setEnabled(false);

    QPushButton *button2 = new QPushButton("MEM");
    button2->setEnabled(false);

    QPushButton *button3 = new QPushButton("LOAD");
    button3->setEnabled(false);

    QPushButton *button4 = new QPushButton("EXE");
    button4->setEnabled(false);

    QPushButton *button6 = new QPushButton("RESET");
    button6->setEnabled(false);

    QPushButton *button5 = new QPushButton("EXIT");
    button5->setEnabled(true);

    QVBoxLayout *layout = new QVBoxLayout;

    QLineEdit *textBox = new QLineEdit;

    QTextEdit *txtLog = new QTextEdit;

    QLabel *m_label = new QLabel();
    m_label->setText(QString::fromUtf8("Command Line Interpreter: "));

    QLabel *procInfoLabel = new QLabel();
    procInfoLabel->setText(QString::fromUtf8("Number of Processes: "));

    QLabel *procInfo = new QLabel();
    procInfo->setText(QString::fromUtf8("STATS"));
    procInfo->setAlignment(Qt::AlignCenter);

    QGroupBox *horizontalGroupBox = new QGroupBox;
    QHBoxLayout *layoutH = new QHBoxLayout;

    horizontalGroupBox->setLayout(layoutH);
    layoutH->addWidget(txtLog);

    QGroupBox *side = new QGroupBox;
    QVBoxLayout *sidebar = new QVBoxLayout;

    side->setLayout(sidebar);

    sidebar->addWidget(procInfoLabel);
    sidebar->addWidget(procInfo);
    sidebar->addWidget(start);
    sidebar->addWidget(button1);
    sidebar->addWidget(button2);
    sidebar->addWidget(button3);
    sidebar->addWidget(button4);
    sidebar->addWidget(button6);
    sidebar->addWidget(button5);
    layoutH->addWidget(side);
    layout->addWidget(m_label);
    layout->addWidget(textBox);
    layout->addWidget(horizontalGroupBox);


    QWidget::connect(textBox,SIGNAL(textChanged(QString)),txtLog,SLOT(setText(QString)));
    QWidget::connect(button5, SIGNAL(clicked(bool)), QApplication::instance(), SLOT(nipliOS.kill();));
    QWidget::connect(button5, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
    QWidget::connect(start, SIGNAL (clicked()), QApplication::instance(), SLOT(nipliOS.start(QString::fromLatin1(os));));
    QWidget:connect(nipliOS, &QProcess::started, QApplication::instance() ,
        SLOT(
          start.setEnabled(false);
          button1.setEnabled(true);
          button2.setEnabled(true);
          button3.setEnabled(true);
          button4.setEnabled(true);
          button6.setEnabled(true);));

    /*

QObject::connect(&qProcessChild, &QProcess::started,
    [&]() {
      qBtnStart.setEnabled(false);
      qBtnStop.setEnabled(true);
      qLblInput.setEnabled(true);
      qInput.setEnabled(true);
    });
    */


    window->setLayout(layout);
    window->show();

    return app.exec();
}
