#include "filestatisticscontroller.h"
#include <QDebug>
#include <QModelIndex>
#include <QFileSystemModel>
FileStatisticsController::FileStatisticsController(QObject *parent) : QObject(parent)
{
    QObject::connect(&worker, &StatisticsWorker::ready,
                     this, &FileStatisticsController::updated);
}

void FileStatisticsController::updateStatistics(const QModelIndex& index)
{
    QFileSystemModel* model = (QFileSystemModel*)index.model();
    QString path = model->filePath(index);
    qDebug()<<path;
    /*if(worker.isRunning())
    {
        worker.terminate();
        qDebug()<<"Terminating worker...";
        worker.wait();
        qDebug()<<"Worker has been terminated";
    }
    worker.setPath(s);
    worker.start();*/
}

FileStatisticsController::~FileStatisticsController()
{
    if(worker.isRunning())
    {
        worker.terminate();
        qDebug()<<"Terminating worker...";
        worker.wait();
        qDebug()<<"Worker has been terminated";
    }
}
