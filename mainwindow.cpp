#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::vector<float> vec(10);
    vec[0] = 10.8;
    vec[1] = 12.5;    //5
    vec[2] = 9.3;
    vec[3] = 1;
    vec[4] = 80;      //2
    vec[5] = 1000;    //1
    vec[6] = 2.7777;
    vec[7] = 1.11111;
    vec[8] = 33;      //4
    vec[9] = 80;      //3

    std::vector<int> pos;
    Max_N_Of_Vector::largest_N(vec, pos, 5);

    for(int i = 0; i < 5; i++)
    {
        qDebug() << pos[i] << "\n";
    }


}

// 将存放有ary_N个元素的数组value中最大的max_N数的位置找出来，下标存在pos数组中
void Max_N_Of_Vector::largest_N(std::vector<float>& value, std::vector<int>& pos, int max_N)
{
    int ary_N = value.size();
    pos.resize(max_N);
    // 对数组前max_N个元素排序
    struct sort_item sort_items[max_N];
    for (int i = 0; i < max_N; i++)
    {
        sort_items[i].value = value[i];
        sort_items[i].pos = i;
    }
    qsort(sort_items, max_N, sizeof(struct sort_item), comp_item);
    for (int i = 0; i < max_N; i++)
    {
        pos[i] = sort_items[i].pos;//max_N - 1 - sort_items[i].pos;
    }

    // 线性扫描数组剩余元素
    for (int i = max_N; i < ary_N; i++)
    {
        int j = 0;
        for (j = 0; j < max_N; j++)
            if (value[i] > value[pos[j]])
                break;
        if (j < max_N)
        {
            for (int k = max_N - 1; k > j; k--)
            {
                pos[k] = pos[k-1];
            }
            pos[j] = i;
        }
    }
    std::sort(pos.begin(), pos.end());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString path = "G:\\OMS\\0413\\build-OMS-Desktop_Qt_5_12_5_MinGW_32_bit-Release\\release\\tuningDir";
    QStringList res = getFileNames(path);
    int a = 0;
    a++;

}

QStringList MainWindow::getFileNames(const QString &path)
{
    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*.tuning";
    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    return files;
}
