#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Max_N_Of_Vector{
    // 排序结构和比较函数
private:
    struct sort_item {
        float value;
        int pos;
    };

    static int comp_item(const void * a, const void * b)
    {
        float v1 = ((struct sort_item *)a)->value;
        float v2 = ((struct sort_item *)b)->value;
        return (v1<v2) ? 1 : (v1>v2) ? -1 : 0;
    }
public:
    // 将存放有ary_N个元素的数组value中最大的max_N数的位置找出来，下标存在pos数组中
    static void largest_N(std::vector<float> &value, std::vector<int> &pos, int max_N);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QStringList getFileNames(const QString &path);

};
#endif // MAINWINDOW_H
