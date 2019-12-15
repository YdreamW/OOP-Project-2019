#include "editor.h"
#include "ui_editor.h"
#include <QtWidgets/QFileSystemModel>
#include <QtWidgets/QFileDialog>
#include <QtGui/QTextCharFormat>

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);

//    //connect menu options
//    connect(ui->actionNew_File, SIGNAL(triggered()), this, SLOT(on_actionNew_File_triggered()));
//    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(on_actionSave_triggered()));
//    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(on_actionOpen_triggered()));
//    connect(ui->actionOpen_Folder, SIGNAL(triggered()), this, SLOT(on_actionOpen_Folder_triggered()));
//    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(on_actionExit_triggered()));

//    //connect font style options
//    connect(ui->btnBold, SIGNAL(clicked()), this, SLOT(on_btnBold_clicked()));

}

Editor::~Editor()
{
    delete ui;
}


//defination of handle menu options
void Editor::on_actionNew_File_triggered()
{
    ui->textEditor->clear();
}

void Editor::on_actionSave_triggered()
{

}

void Editor::on_actionOpen_triggered()
{

}

void Editor::on_actionOpen_Folder_triggered()
{

}

void Editor::on_actionExit_triggered()
{
    this->close();
}

//defination of handle font style options
void Editor::on_btnBold_clicked()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(ui->btnBold->isChecked() ? QFont::Bold : QFont::Normal);
    mergeFormatOnWordOrSelection(fmt);
}

void Editor::on_btnItalic_clicked()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(ui->btnItalic->isChecked());
    mergeFormatOnWordOrSelection(fmt);
}

void Editor::on_btnUnderline_clicked()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(ui->btnUnderline->isChecked());
    mergeFormatOnWordOrSelection(fmt);
}

void Editor::on_btnStrikeout_clicked()
{
    QTextCharFormat fmt;
    fmt.setFontStrikeOut(ui->btnStrikeout->isChecked());
    mergeFormatOnWordOrSelection(fmt);
}


void Editor::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
    QTextCursor cursor = ui->textEditor->textCursor();
    if (!cursor.hasSelection())
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(format);
    ui->textEditor->mergeCurrentCharFormat(format);
    ui->textEditor->setFocus(Qt::TabFocusReason);
}



