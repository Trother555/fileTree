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
    if(worker.isRunning())
    {
        qDebug()<<"Stopping the worker...";
        worker.stop();
        worker.wait();
    }
    worker.setPath(path);
    qDebug()<<"Starting the worker...";
    worker.start();
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
