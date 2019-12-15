#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QtGui/QTextCharFormat>

namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();

private:
    Ui::Editor *ui;
    QString FileName;



    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);

private slots:

    //declaration of menu options
    void on_actionNew_File_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionOpen_Folder_triggered();
    void on_actionExit_triggered();

    //declaration of font style options
    void on_btnBold_clicked();
    void on_btnItalic_clicked();
    void on_btnUnderline_clicked();
    void on_btnStrikeout_clicked();



};

#endif // EDITOR_H
