#include <QApplication>
#include <QtGui>
#include <QtWidgets>
#include "QUnitMargin.h"

class Edit : public QWidget
{
    Q_OBJECT

public:
    Edit( QWidget *parent = 0 )
    {
        resize(700,400);
        setWindowTitle("Margin Sample");
        gridLayout = new QGridLayout(this);
        Umargin = new QUnitMargin(250,this);
        gridLayout->addWidget(Umargin, 0, 0, 1, 1);
        textEdit = new QTextEdit(this);
        textEdit->setHtml("If the wrap mode is <b>FixedPixelWidth</b>, the value is the number of pixels from the left edge of the text edit at which text should be wrapped. If the wrap mode is FixedColumnWidth, the value is the column number (in character columns) from the left edge of the text edit at which text should be wrapped.");
        //CursorMargins(10.5,Umargin->width() - 10.5);
        gridLayout->addWidget(textEdit, 1, 0, 1, 1);
        connect(Umargin, SIGNAL(CursorMove(qreal,qreal)),this,SLOT(CursorMargins(qreal,qreal)));
    }
    QGridLayout *gridLayout;
    QUnitMargin *Umargin;
    QTextEdit *textEdit;

public slots:
    void CursorMargins( qreal left , qreal right )
    {
        //////qDebug() << "### on_Umargin_Cursor_Move " << left << "," << right;
        QTextFrame  *Tframe = textEdit->document()->rootFrame();
        QTextFrameFormat rootformats = Tframe->frameFormat();
        rootformats.setBorder(0);
        rootformats.setLeftMargin(left - 1);
        rootformats.setRightMargin(Umargin->width() - right + 1);
        Tframe->setFrameFormat(rootformats);

    }

};


int main(int argc, char ** argv)
{
    QApplication app( argc, argv );
    Edit win;
    win.show();
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}

#include "main.moc"









