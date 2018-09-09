#include "filestatisticscontroller.h"
#include <QDebug>
#include <QModelIndex>

FileStatisticsController::FileStatisticsController(QObject *parent) : QObject(parent)
{

}

void FileStatisticsController::setModel(FileStatisticsModel *m)
{
    model = m;
    QObject::connect(&worker, &StatisticsWorker::ready,
                     m, &FileStatisticsModel::setModel);
}

void FileStatisticsController::updateStatistics(const QModelIndex& path)
{
    QString s = path.data().toString();
    if(worker.isRunning())
    {
        worker.terminate();
        qDebug()<<"Terminating worker...";
        worker.wait();
        qDebug()<<"Worker has been terminated";
    }
    worker.setPath(s);
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
